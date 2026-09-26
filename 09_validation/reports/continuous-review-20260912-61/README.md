# IPC entry 제거·reverse hash 갱신·tree node 해제

## 결과와 검증 범위

entry dealloc, local/global hash 삽입·삭제, splay pick/delete의 본문을 연결했다. **권한 해제, hash 제거, entry 저장소 반환은 서로 다른 작업**이다. table entry는 free list로 돌려주거나 충돌 tree entry로 대체하고, tree node의 실제 zfree는 splay delete 안에 있다. 반복 삭제가 무해하다는 계약은 확인되지 않았다.

[증거](entry-hash-evidence.json)는 본문 9개, 명령어 734개, 본문 1878바이트를 포함한다. 원본 Mach-O VA/file mapping과 decoder의 바이트·명령 길이, 보존 Ghidra 범위·직접 분기 목적지를 Python으로 대조했다. 입력 fingerprint 35개, 이전 산출물 678개의 해시를 확인했다. 원본 SHA-256은 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`이다.

Ghidra 스킬을 보존 ASM/C의 읽기 전용 비교에 적용했다. 모든 계산은 Python으로 수행했다. 새 독립 계획 검토 미확보 상태이며 새 검증 프로그램·동적 실행·DB/원본/`07_kernel` 수정·GCC 2.7 실빌드는 하지 않았다. 아래는 정적 본문 계약으로, split/join/bounds, table grow, allocator 및 tree/hash 모든 상태의 검증은 아니다.

## entry dealloc의 전제와 분기

`_ipc_entry_dealloc` (`0x146284`)는 `(space,name,entry)`를 받는다. 자체 lock이나 active/object/request/generation 검사는 없다. Darwin 대응 소스의 전제는 space write-locked/active, entry object=0, request=0이다. 원본 caller가 권한과 요청을 먼저 정리하는 [보고서 59](../continuous-review-20260912-59/README.md)·[보고서 60](../continuous-review-20260912-60/README.md)와 연결된다. 이 helper가 누락된 권한 정리를 자동으로 해주지는 않는다.

index는 `name >> 8`, table은 space+0x14, size는 space+0x18이다. index<size이고 entry가 정확히 table+index*16이어야 table 경로이며, 아니면 tree 경로다. 이름의 숫자 범위만으로 판단하지 않는다.

| 경로 | 원본 처리 |
| --- | --- |
| table, collision 없음 | bits에 generation mask `0xff000000`만 남긴다. entry+8에 기존 table free-list head를 저장하고 table+8에 index를 넣는다. |
| table, collision 있음 | tree split/pick으로 대체 node를 고르고 bits/object/request를 table로 옮긴다. pure SEND이면 global hash 제거→local 삽입. 고른 node 삭제, tree_total 감소, 잔여 충돌 확인과 join. |
| tree entry | splay delete로 node를 제거·해제하고 tree_total 감소. 인접 이름의 index로 table collision bit 또는 tree_small count를 보정한다. |

collision 없는 table 반환은 object와 entry+0xc를 지우지 않는다. 특히 entry+0xc는 독립적인 reverse hash slot 저장소이므로 구조체 전체를 zeroing하면 다른 동작이 된다. object/request의 선행 정리 계약을 확인해야 한다.

## 충돌 node의 table 이동

원본은 space+0x20 tree를 `(index+1)<<8`로 split하고 그 결과를 `index<<8`로 다시 split한다. 같은 index의 세대별 이름을 분리하려는 참고 소스와 대응하지만 split 전체 구현은 다음 검토 범위다.

첫 pick(`0x146312`)은 EAX를 검사하지 않고 출력 name/node를 사용한다. collision bit가 해당 집합의 비어 있지 않음을 보장해야 한다. `_ipc_splay_tree_pick` (`0x150a1c`)는 root=0이면 출력 포인터를 쓰지 않고 0, 아니면 root의 name/node를 쓰고 정규화한 EAX=1을 반환한다. 난수 선택이 아니라 현재 root 선택이다.

고른 node의 bits에 `(picked_name << 24)`를 OR하고 object/request를 table entry로 복사한다. pure SEND이면 `0x146352` global hash delete와 `0x146361` local hash insert를 **node free 전에** 호출한다. 이는 객체 권한/ref 복제가 아니라 entry 표현 이동이다. generation/flag 불변조건 없이 OR를 독립적인 정규화로 해석하지 않는다.

`0x146375` tree delete 후 space+0x38 tree_total을 감소시킨다. 두 번째 pick(`0x14638c`)은 EAX를 검사하며, 남은 충돌이 있으면 collision bit 설정과 join을 한다. 이어 작은 이름 tree를 join한다. 첫 pick과 두 번째 pick의 검사 차이를 보존해야 한다.

tree entry를 직접 제거하면 bounds의 lower가 `0xffffffff`가 아니면서 같은 index인지, 또는 upper가 0이 아니면서 같은 index인지 확인한다. index가 현재 table 안이고 둘 다 아니면 대응 slot의 collision bit를 지운다. 현재 table 밖이지만 다음 table size 안이면 같은 조건에서 space+0x3c tree_small을 감소시킨다. tree_total/tree_small 양수 검사는 원본에 따로 없다.

## reverse hash dispatch와 미사용 ABI 인자

`_ipc_hash_insert` (`0x146958`), `_ipc_hash_delete` (`0x1469a0`)는 위와 같은 index+포인터 조건으로 local/global을 선택한다. local에는 `(space,object,index,entry)`, global에는 `(space,object,name,entry)`를 전달한다.

Ghidra C는 local insert/delete를 인자 3개로 표시하지만 caller는 entry까지 전달한다. 본문은 그 인자를 읽지 않으며 참고 선언에는 인자 4개가 있다. global의 name도 본문에서 읽지 않지만 caller/선언에 존재한다. **미사용 stack slot은 ABI에서 인자를 삭제할 근거가 아니다.**

global 함수의 Ghidra int 반환은 unlock XCHG의 incidental EAX이다. 참고 선언은 void이고 검토한 wrapper는 이를 상태로 검사하지 않는다. 반환형과 실제 의미를 분리해야 한다.

## global hash

`_ipc_hash_global_insert` (`0x146a98`)는 space+0x40 tree_hash count 증가 후 `((space>>4)+(object>>6)) & mask` bucket을 lock한다. stride는 8바이트이며 entry+0xc next=head, head=entry로 삽입한다. object/name/entry 일치나 중복 검사는 없다.

`_ipc_hash_global_delete` (`0x146ae8`)는 **탐색 전에** count를 감소시킨다. bucket lock 아래 pointer equality로 entry를 찾아 앞 link를 해당 next로 바꾼다. 못 찾으면 unlock하고 반환하지만 count 감소를 되돌리지 않는다. null 탐색 종료는 처리하나 유효한 not-found 성공 API는 아니다. 반복 delete의 무해성을 가정하면 안 된다.

어느 함수도 entry/object를 free하거나 object ref를 변경하지 않고, 삭제된 entry의 next도 지우지 않는다. 이 함수들에도 register-only lock wait가 있다. 보고서 59의 경합 진행성 제한을 유지한다.

## local hash의 probe와 삭제 후 보정

`_ipc_hash_local_insert` (`0x146bc8`), delete (`0x146c0c`)는 caller의 space lock에 의존한다. `(object >> 6) % size`를 unsigned DIV로 계산하며 size=0이나 객체/entry의 runtime 유효성 검사는 없다.

insert는 각 table entry+0xc `ie_index`를 선형 탐색하고 size 끝에서 0으로 돌아가 빈 slot에 index를 저장한다. 중복·한 바퀴 제한은 없다. delete는 목적 index를 찾을 때 중간 빈 slot이라고 중단하지 않는다. size>0, 목적 index 존재, 예약 index 0 및 여유 slot 전제는 alloc/lookup/grow 전체에서 확인해야 한다. 참고 소스의 여유 slot 설명은 실행 검증을 대신하지 않는다.

삭제 뒤 hole을 h, 후보 위치를 d, 후보 object의 원래 hash 위치를 home이라 할 때 이동 조건은 원본 unsigned 분기와 다음처럼 대응한다.

```text
d < h  :  d < home && home <= h
d >= h :  d < home || home <= h
```

실제로 옮기는 것은 node/object가 아니라 table[h].ie_index 값이다. 후보 index를 저장하고 hole을 후보 위치로 옮겨 반복하며, 빈 index를 만나면 마지막 hole에 0을 쓴다. slot 하나만 0으로 지우면 뒤쪽 충돌 원소의 탐색이 끊길 수 있어 원본과 다르다. 조건/예시는 Python 산술로 기록했지만 모든 hash 상태의 실행·불변조건 증명은 아니다.

## splay delete의 node free와 남은 구조

`_ipc_splay_tree_delete` (`0x150d74`)의 caller는 `(tree,name,entry)`를 전달하지만 본문은 tree/name만 읽는다. 참고 소스도 entry의 실질적 미사용을 설명하며 assert로 root/name/entry 동일성을 요구한다. 원본에는 해당 runtime 비교가 없다. Ghidra의 인자 2개 표현만으로 ABI를 줄이지 않는다.

tree는 cached name/root와 left/right tree·link pointer를 보유한다. cached name이 요청 name과 다르면 assemble 후 name 기준으로 splay한다. 탐색은 이름 불일치의 마지막 node에서 끝날 수도 있지만 삭제 직전에 일치 여부를 검사하지 않는다. 따라서 membership과 nonnull root가 필수 전제다. “없는 이름이면 아무 일도 하지 않는 삭제”가 아니다.

선택 root의 left/right child를 분리 tree link에 연결한 뒤 `0x150ec4`에서 **ipc_tree_entry_zone으로 zfree(root)** 한다. entry dealloc에 직접 zfree가 없는 이유가 이 callee에 있다. 여기서 해제하는 것은 tree node storage이며 port 객체의 권한/ref release 호출은 없다.

남은 left가 없으면 right를, right가 없으면 left를 root로 둔다. 둘 다 있으면 left에서 최대 key 방향으로 splay/assemble하고 saved right를 붙인다. 끝에서 root를 저장하고 nonnull일 때만 cached name과 link pointer를 갱신한다. 빈 tree의 모든 필드를 초기화하는 함수가 아니다. 모든 tree 형태의 연결·수명은 추가 검증 대상이다.

## unreachable 경고의 범위

splay delete의 Ghidra unreachable 제거 경고 9개를 evidence에 그대로 남겼으며 원본 명령어도 전부 보존했다. 후반 최대 key 탐색의 `0x150f33`, `0x150fc3`은 `0xffffffff`와 DWORD key의 unsigned CMP/JNC이다. 왼쪽 값이 unsigned 도메인의 상한이므로 borrow가 생기지 않아 해당 fall-through 가지를 C에서 제거한 현상과 대응한다.

이것은 operand와 도메인을 함께 본 제한된 정적 근거다. 전체 warning을 무시하거나 모든 splay 경로의 안전성을 증명한 것은 아니다. 원본 bytes와 signed/unsigned 의미를 이후 CFG·GCC 2.7 코드 생성 검토에도 유지한다.

## 다음 범위

[미완료 항목](OPEN_ITEMS.md)의 split/join/bounds 및 table/hash 불변조건을 연결한다. pset/mqueue와 전체 IPC·다른 서브시스템 검증도 남는다. 이번 대조를 전체 분석·복원·GCC 2.7 실컴파일·부팅 완료로 판정하지 않는다.
