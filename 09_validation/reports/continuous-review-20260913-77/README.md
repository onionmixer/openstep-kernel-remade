# 77차 — VM 삭제·객체 참조·pmap 정리의 원본 분석

## 범위와 판정

OPENSTEP 원본 커널과 그 보존 Ghidra asm/C/메타데이터만 사용했다. 다른 프로젝트의
코드, `01_resources`, 복원 코드 `07_kernel`은 참고하지 않았다. 기존 외부 소스 비교를
현재 결론의 근거로 승계하지 않았다. Ghidra 스킬은 기존 export 읽기와 원본 대조에만
적용했다. 구현·빌드·포팅·DB 수정·동적 실행·새 독립 계획 검토는 수행하지 않았다.

선택 본문 8개, 명령어 817개, 본문 2,199바이트의 원본 file mapping과 재디코딩을
Python으로 확인했다. 직접 분기 109곳의 목적지가 해당 보존 본문 명령어 시작점인지,
직접 CALL 36곳의 목적지가 export와 일치하는지 확인했다. 간접 제어 이전은 없다.
이는 선택한 본문에 대한 점검이지 전역 함수 경계·도달성·하위 함수 의미의 완료가 아니다.
명시적인 Ghidra WARNING 주석은 5개이며, 아래 의미 차이는 경고 유무와 별개다.

증거는 [vm-delete-evidence.json](vm-delete-evidence.json), 이전 산출물 보존 해시는
[preservation.json](preservation.json), 후속 항목은 [OPEN_ITEMS.md](OPEN_ITEMS.md)에 있다.
주소·폭·분기·산술 예시는 모두 Python으로 검산했다. 재디코딩은 실행이나 에뮬레이션이 아니다.

## 중요한 디컴파일 차이

| 위치 | 원본에서 확인한 사실 | C 출력의 한계 |
| --- | --- | --- |
| pmap_remove `0x18fa8d`, `0x18fa90` | EAX로 CR3를 읽고 같은 값을 CR3에 기록 | 큰 구간 분기에서 이 명령들이 생략됨 |
| vm_object_deallocate `0x178cfd`, `0x178d0b` | 캐시 목록 tail 저장이 cache lock 해제보다 먼저 | C에서는 tail 저장이 lock 해제 뒤로 이동 |
| 객체 참조/제거 함수들 | object 인자는 stack에서 읽음. reference/deallocate는 하나, page_remove/pmap_remove는 세 stack 인자를 사용 | 불필요한 EAX 인자를 포함한 `__regparm1` 형식으로 표현 |
| spin 14곳 | 메모리 load 다음 TEST로 되돌아가는 `75fc` 내부 분기 | C의 반복 메모리 읽기를 원본과 동일한 진행성으로 간주할 수 없음 |

EAX가 NULL 경로에서 그대로 남거나 unlock XCHG의 이전 값을 받는 것을 의미 있는
추가 입력·성공 코드·해제 수로 해석하지 않는다. CALL 측 push와 stack 정리도 대조했다.
spin은 실제 재로드 위치와 원자적 XCHG 경로를 보존했으며 native 진행성을 검증하지 않았다.

## vm_map_delete — entry 분할과 삭제 순서

`0x176164`는 map/start/end stack 인자를 사용한다. 부모 map 전체의 write lock을
이 본문에서 새로 잡지 않는다. 76차의 vm_map_remove가 이를 잡는 호출 경계와 구분한다.
map+0x3c는 +0x38 탐색 hint를 보호하는 별도 spin이다. sentinel은 map+0xc다.
entry에서 관찰한 prev/next/start/end는 +0/+4/+8/+0xc, 대상 포인터와 offset은
+0x10/+0x14, 분기에 사용하는 flags byte는 +0x18, wire word는 +0x28이다.
외부 헤더의 구조체명·bit 이름을 가져와 확정하지 않았다.

탐색은 hint부터 시작하되 start가 hint.start보다 작으면 첫 entry에서 제한된 재탐색을
한다. 포함 entry를 못 찾으면 predecessor를 hint로 저장하고 그 next부터 삭제를 시도한다.
포함 entry를 찾고 entry.start < start이면 end를 검사하기 전에 앞쪽을 분할한다.

- zalloc이 NULL이면 `0x176286`에서 원본 문자열 `vm_map_entry_create`로 panic을 호출한다.
- `0x17629b` CLD, ECX=0xb, `0x1762a1` REP MOVSD는 44바이트를 복사한다.
- 복제본은 앞 구간이 되고 원래 entry.start와 offset을 올린다. map+0x1c 수를 증가시키고
  복제본을 원래 entry 앞에 연결한다.
- flags & 5이면 NULL이 아닌 대상 map의 DWORD +0x30을 +0x34 lock 아래 증가시킨다.
  아니면 복제본 대상에 vm_object_reference를 호출한다.
- hint를 원래 entry.prev로 바꾸며 map+0x40 보조 포인터도 시작 주소 비교에 따라 바꾼다.

삭제 loop의 entry.start < end 검사는 `0x17635f` 이후다. 따라서 빈 범위를 항상
무변경으로 처리한다고 결론 내릴 수 없다. 예를 들어 정상적으로 찾은
`[0x400000,0x406000)`, offset `0x10000` entry에서 start=end=`0x402000`이면,
할당·참조 증가가 정상 완료되는 조건 아래 `[0x400000,0x402000)`과
`[0x402000,0x406000)`으로 나뉜다. 뒤 entry offset은 `0x12000`, entry 수는 +1,
삭제 바이트는 0이다. 이는 정적 분기와 유한 산술의 결과이며 native 재현 결과가 아니다.

entry.end > end인 실제 삭제에서는 뒤쪽 분할을 별도로 수행한다. `0x1763c9`의
44바이트 복사 뒤 원래 entry.end를 줄이고, 복제본 start/offset을 조정해 뒤에 연결하며
참조를 증가시킨다. 두 경계가 내부인 삭제의 참조 증감·남는 구간은 증거 JSON에 있다.
분할 할당 실패를 복구하는 일반 오류 반환은 이 본문에서 보이지 않는다.

실제 제거 순서는 다음과 같다.

1. `0x176437/0x17643a`에서 next를 지역 stack에 먼저 저장한다. start/end/대상도 저장한다.
2. wire word가 0이 아니면 vm_fault_unwire를 호출하고, 반환 뒤 `0x17645d`에서 word를 0으로 쓴다.
3. 대상이 원본 심볼 kernel_object와 같으면 vm_object_page_remove(target, offset, offset+길이)를 호출한다.
4. map+0x2c가 0이면 vm_object_pmap_remove를 같은 객체 offset 범위로 호출한다.
   이 직접 호출 앞에 entry flags & 5 검사를 임의로 추가하면 원본과 달라진다.
5. pmap_remove(map+0x24, 저장한 start, 저장한 end)를 호출한다.
6. wire word를 다시 검사해 필요하면 다시 unwire하고 0으로 쓴다. 중간 callee의 writer를
   모두 검증하지 않았으므로 두 번째 검사를 불필요하다고 제거하지 않는다.
7. map entry 수를 감소시키고 prev/next를 unlink한 뒤 map+0x28에서 entry 길이를 뺀다.
8. flags & 5 경로는 대상 map 참조를 줄인다. 감소 후 DWORD를 signed로 검사해
   양수일 때만 파괴를 건너뛴다. 그 외에는 child write lock, timestamp 증가,
   재귀 vm_map_delete, pmap_destroy, map zone zfree 순서다. 별도 child unlock은 이 본문에 없다.
   flags & 5가 0이면 vm_object_deallocate를 호출한다.
9. map+0x20으로 선택한 entry zone에 zfree하고 저장해 둔 next를 복원한다.

보통 반환 경로는 `0x1765a0`의 EAX=0으로 합류한다. 하위 호출의 오류를 모두 확인한
성공 보증이나 물리 페이지 반환 완료를 의미하지 않는다. panic·대기·fault·참조 수명은
별도 경계이며, 잘못된 입력이 실제로 도달하는지도 추가 입증이 필요하다.

## 객체 페이지 제거와 unwire

vm_object_page_remove `0x179bbc`는 NULL 대상이면 종료한다. object 목록에서 page+0x18이
unsigned [lo,hi)에 들면 page+0x24를 pmap_remove_all에 넘기고, page queue lock
`0x1f64e8`을 잡아 vm_page_free를 호출한다. page+8의 next는 두 CALL 전에 저장한다.
자체 object lock, busy/absent/wired 검사나 명시적 wait는 이 본문에 없다. 따라서
상위 직렬화와 하위 함수 계약을 아직 해결된 것으로 보지 않는다.

vm_object_pmap_remove `0x179350`는 object+0x10 lock을 잡은 채 목록을 순회한다.
같은 offset 구간의 page+0x24로 pmap_remove_all을 호출하지만 page free는 직접 호출하지
않는다. next=page+8을 CALL 뒤에 읽는 점이 page_remove와 다르다. 하위 함수가 object
목록을 보존하는지 추가 확인해야 한다.

vm_fault_unwire `0x1735f4`는 entry.end와 map의 pmap을 먼저 snapshot하고 page queue lock을
잡은 뒤 entry.start를 읽는다. 각 주소마다 pmap_extract → 결과 0이면 panic →
pmap_change_wiring(...,0) → vm_phys_to_vm_page → vm_page_unwire 순서다.
물리 페이지 변환 결과의 NULL 검사는 직접 없다. 주소는 global page_size만큼 증가하며
자체 정렬·0 step·overflow 검사는 없다. queue unlock 뒤 entry.start를 다시 읽어
pmap_pageable(pmap,start,저장한 end,1)을 호출한다. entry wire word를 0으로 쓰는 주체는
이 함수가 아니라 앞서 본 caller다. 추출 결과 0의 전체 의미와 하위 helper 안전성은 미완료다.

## 객체 참조 폭·캐시 경로

vm_object_reference `0x178c30`의 갱신은 object+0x18의 WORD 증가다. vm_object_deallocate
`0x178c64`도 같은 WORD를 감소시키며, 마지막 참조 경로는 **감소 전 WORD == 1**이다.
child map의 signed 감소 결과 검사, pmap_destroy의 감소 결과 == 0 검사와 혼동하면 안 된다.
Python 산술에서 object의 0 감소는 0xffff로 돌아가지만 마지막 참조 경로는 타지 않고,
0xffff 증가는 0이 된다. 이는 폭의 성질이며 정상 실행에서 underflow가 발생했다는 뜻은 아니다.

deallocate는 cache lock 후 object lock을 잡는다. 마지막 참조이며 object+0x46의 mask 0x08이
설정되어 있고 **signed WORD +0x1a > 0**이면 캐시 목록에 연결한다. 이 WORD의 더 구체적인
의미는 외부 구조체 정의로 채우지 않았다. tail `0x1f6f3c` 저장과 cached 수 증가는
cache unlock보다 먼저다. 이후 object lock을 보유한 채 vm_object_deactivate_pages,
object unlock, vm_object_cache_trim 순서다. cache trim까지 읽지 않고 계속 보존된다고 단정하지 않는다.

mask 0x08이 설정됐으나 +0x1a 조건이 맞지 않으면 해당 bit를 지운다. 파괴 경로에서는
두 lock 아래 vm_object_remove(object+0x28)를 호출하고 cache lock을 푼다.
object+0x20을 EBX에 저장한 뒤 vm_object_terminate를 호출하고 저장한 포인터로 반복한다.
terminate 전 자체 object unlock은 없으며, callee의 lock 소비 여부는 아직 미확인이다.
이를 곧바로 lock 누수나 deadlock으로 확정하지 않는다.

## pmap_remove — 생략된 CR3와 구간 처리

`0x18fa44`는 NULL pmap을 제외하고 splvm을 호출한다. kernel_pmap이거나 pmap+0x18이
0이 아닌 경우에 먼저 통계 갱신과 무효화 명령 경로를 실행한다. unsigned DWORD
end-start > page_size이면 CR3 읽기/재기록이고, 그렇지 않으면 start < end 동안
0x1000 간격의 INVLPG다. kernel_pmap은 기본 segment, 다른 pmap은 FS override를 쓴다.
이후 작은 구간 통계를 증가시키므로 빈 구간도 통계상 무변경이라고 할 수 없다.

Python 조건부 예시 page_size=8192에서 길이 8192의 INVLPG 주소는 0x400000, 0x401000이다.
명령의 step 4096과 VM page_size 8192는 다르다. 큰 구간의 CR3 명령은 보존 C 출력에
빠져 있으므로 C만으로 원본 동작을 기술하면 누락된다. 역전 구간의 DWORD 차도 무효화
분기 전에 별도 거부하지 않는다. 실제 입력 불변식과 native CR3/TLB 효과는 미검증이다.

무효화 명령은 lower helper 호출보다 **먼저**다. 이후 start < end 동안
`(start + page_size + section_size - 1) & -section_size`의 DWORD 결과를 end로 제한하고,
FUN_0018f7f8(pmap,start,chunk_end,1)을 호출해 start를 이동한다. 마지막에 splx다.
section_size의 올바른 값·alignment·증가 진행성은 별도 전제다. helper의 PTE/PV 처리와
오류 경계를 확인하기 전 전체 매핑 제거 완료로 승격하지 않는다.

## pmap_destroy — 참조 감소와 backing 관리

`0x18f69c`는 splvm, pmap+0xc lock 아래 DWORD +8 감소, unlock, splx를 먼저 수행한다.
감소 결과가 0일 때만 남은 정리를 한다. 이후 PD queue/bitmap을 조작하는 동안 이 본문에서
다시 lock이나 spl을 올리지는 않는다. 호출자 직렬화와 참조 수명 검증이 필요하다.

*pmap의 주소를 kernel_pmap의 directory와 page-table word로 변환하며 present bit를 검사한다.
PDE/PTE 누락 또는 계산한 PTE 포인터 0이면 EAX=0으로 합류하지만, 거기서 반환하지 않고
pg_first_phys 차, 우측 shift, pg_desc_tbl 색인 계산을 계속한다. 유효 변환이라는 전제를
입증해야 하며 이것만으로 실제 NULL 접근 사고를 주장하지 않는다.

관찰된 descriptor stride는 20바이트다. descriptor+0xc의 backing 포인터를 읽고 그 +0x18
WORD를 감소시키며, **감소 전 WORD == ptes_per_vm_page**일 때 pd_free_queue에 넣고 수를
증가시킨다. 그 뒤 (*pmap - descriptor+8)의 DWORD 차를 12비트 오른쪽으로 민 slot으로
`ROL32(0xfffffffe, slot & 31)`을 만들고, 결과 AL만 backing+0x1c BYTE에 AND한다.
Python 검산에서 slot 0/1/7의 low mask는 0xfe/0xfd/0x7f, slot 8/31은 0xff다.
가능한 slot 범위를 확인하지 않고 모든 slot에서 bit를 지운다고 일반화하지 않는다.

마지막 직접 호출은 zfree(pmap_zone,pmap)이다. queue/bitmap 재사용 bookkeeping을
backing 물리 메모리 전체 free와 동일시하지 않는다. 하위 물리 페이지·PV·object 종료와
주소 재사용은 [남은 항목](OPEN_ITEMS.md)으로 이어진다.

## 보존과 한계

원본 SHA-256은 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`이다.
현재 입력 30개와 이전 범위 내 보존 파일 753개의 해시를 확인했다. 원본 문자열 두 곳도
file-backed bytes에서 확인했다. 해시 보존은 과거 보고서의 모든 의미 해석을 승인하는 일이 아니다.
원본의 함수별 직접 경계가 더 구체화됐으나 전체 원본 분석은 아직 완료되지 않았다.
