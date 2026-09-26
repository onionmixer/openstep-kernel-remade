# IPC entry 생산자: 할당·확장·tree 삽입과 reverse lookup

## 결과와 범위

entry get/alloc/alloc_name/grow_table, splay insert 및 reverse hash lookup의 원본 본문을 대조했다. 성공 시 namespace lock을 유지하는 할당 계약, lock을 놓은 뒤 이름을 다시 검사하는 경로, table 확장 중 hash 재구축·tree 이동 순서를 확인했다. 참고 Darwin의 grow_table에는 원본에서 사용하지 않는 target_size 인자가 있으므로 그대로 가져올 수 없다. 또한 global hash lookup도 연결 순서를 변경한다.

원본은 OPENSTEP x86 mk-183.34.4, SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`이다. Ghidra 스킬을 보존 export 읽기 전용 대조에 적용했다. 모든 산술·주소/범위 매핑·해시·집계는 Python으로 수행했다. [정적 증거](entry-producer-evidence.json)에 원본 바이트와 file offset, Ghidra listing, 독립 decoding, 분기/call 목적지, register-only wait 및 직접 stack-slot 검사를 보존했다.

| 함수 | 주소 | instruction heads | body bytes |
| --- | --- | ---: | ---: |
| entry_get | `0x145f04` | 36 | 86 |
| entry_alloc | `0x145f5c` | 56 | 136 |
| entry_alloc_name | `0x145fe8` | 232 | 648 |
| entry_grow_table | `0x1464ac` | 406 | 1099 |
| hash_lookup | `0x146908` | 38 | 78 |
| hash_global_lookup | `0x1469e8` | 71 | 171 |
| hash_local_lookup | `0x146b54` | 49 | 113 |
| splay_tree_insert | `0x150bac` | 157 | 448 |

Python 집계는 8개 본문, 1045개 명령어, 2779 bytes, 직접 branch 125개, CALL 37개이다. 현재 선정 C 출력의 WARNING 줄은 0개지만 이것은 의미 검증이나 ABI가 자동으로 올바르다는 뜻이 아니다. 입력 fingerprint 35개와 이전 파일 690개의 해시를 확인했다. 별도 Mach-O load-command 해석과 보존 디코더의 주소 매핑을 비교하고 body byte 중복/누락 및 직접 branch의 instruction head를 검사했다.

참조는 보존 Darwin의 `ipc_entry.c/.h`, `ipc_space.h`, `ipc_splay.c`, `ipc_hash.c`, `mach/kern_return.h`이다. offset 대응과 계약 비교용이며 원본 동일 빌드 소스라는 증거는 아니다. tree traverse, table allocator, space 수명, wait/wakeup 및 모든 caller까지 전이적으로 완료한 범위는 아니다.

## 공통 lock와 entry 상태

namespace lock은 space `+0x8`, active는 `+0xc`, growing은 `+0x10`, table은 `+0x14`, size는 `+0x18`, next-size descriptor는 `+0x1c`이다. tree는 `+0x20`, tree_total/small/hash는 각각 `+0x38/+0x3c/+0x40`이다. ref lock `+0x0`와 혼동하지 않는다.

table entry는 16 bytes이며 bits/object/next-or-request/hash-index가 각각 `+0/+4/+8/+0xc`이다. `+8`은 free-list next와 live request가 공유한다. `+0xc`의 hash slot은 해당 entry의 권한 사용 상태와 독립적으로 다른 index를 담을 수 있다. 할당/해제에서 구조체 전체를 지우면 안 된다는 앞선 분석을 생산자에서도 확인했다.

현재 본문에서 register-only spin 8개를 확인했다. load 주소는 `0x145f6c`, `0x14600c`, `0x14625c`, `0x1464ec`, `0x1465a0`, `0x146610`, `0x1468ac`, `0x146a10`이다. 각각 `MOV EAX,[lock]` 다음 `TEST EAX,EAX; JNZ TEST`이며 분기 bytes는 `75fc`다. 안쪽 반복에는 메모리 재읽기가 없다. 바깥 XCHG 재시도는 MOV로 되돌아간다. Ghidra의 `while (*lock != 0)`처럼 계속 메모리를 다시 읽는 것으로 해석하면 진행성 판단이 달라진다.

이하 lock 이후의 상태 계약은 정상적으로 lock 획득을 통과하고 필요한 helper가 반환한다는 조건부 정적 결과다. 원본 실행에서 실제 hang을 관찰한 것은 아니며 runtime patch/CPU/context/경합 검증도 남아 있다.

## entry_get와 entry_alloc

entry_get은 자체 lock/active 검사나 메모리 할당 없이 free list에서 entry를 하나 꺼낸다. 호출자가 active namespace를 write-lock하고 있어야 한다. `table[0]+8`의 head가 0이면 EAX=3을 반환하고 출력 포인터에는 쓰지 않는다. 이 3은 참조 헤더의 KERN_NO_SPACE와 대응한다.

head가 비어 있지 않으면 `table + index*16`을 구하고 head를 그 entry의 next로 바꾼다. bits 전체 DWORD에 `0x01000000`을 더하여 저장하고 request를 0으로 만든다. 이름은 `(index << 8) | (new_bits >> 24)`로 출력한다. object와 hash slot은 지우지 않는다. free bits에 generation 외의 값이 없고 object=NULL이라는 참조 소스 assert는 원본에 없다. index 범위 및 free-list 무결성도 본문에서 검증하지 않는다.

덧셈은 DWORD wrap이다. Python 계산상 old bits `0xff000000`은 new bits 0이 되며 index 1의 이름은 `0x100`이다. 세대 최댓값에서 할당을 거부하거나 saturation하지 않는다. 이 산술 결과 자체가 실제 커널에서 해당 재사용 횟수나 잘못된 free entry에 도달했다는 증거는 아니다.

entry_alloc은 namespace lock을 잡고 active를 검사한다. dead이면 `0x145f88`에서 unlock하고 16(KERN_INVALID_TASK)을 반환한다. free head가 있으면 get과 같은 inline 변경을 수행하고 EAX=0으로 반환하며 lock을 유지한다. 빈 free list이면 `0x145fd1`에서 grow_table(space)를 호출하고, 0이면 `0x145f80`으로 돌아가 active/free head를 재검사한다. grow 오류는 그대로 반환한다. 성공 출력은 이름과 entry 포인터이며 새 권한 type/object를 완성하는 것은 caller의 다음 작업이다.

## entry_alloc_name: 기존 이름 탐색과 할당 사이의 재검사

인자는 `(space, name, entryp)`이다. index=`name >> 8`, gen=`name << 24`를 DWORD로 취한다. 먼저 lock을 잡는다. 원본에는 MACH_PORT_VALID(name) 검사가 없으며 참조 소스에서는 assert이다. index 0을 table의 일반 권한 slot으로 쓰지 않는 분기는 있지만, invalid 이름 전체를 에러 처리하는 검증은 아니다. 실제 syscall의 입력 인정 여부는 caller를 추가 확인해야 한다.

active 상태에서는 다음 순서로 진행한다.

1. `0 < index < size`이면 table을 먼저 검사한다. type bits가 있고 generation이 같으면 기존 entry를 반환한다. type가 0이면 free-list에서 해당 index의 선행 링크를 찾아 제거하고 bits를 요청 gen으로 바꾸며 request를 0으로 만든다. object/hash는 그대로다. free-list 순회 `0x1460a8`에는 못 찾았을 때 NULL 종료나 방문 수 제한이 없다. type=0이면 그 index가 free-list에 있다는 불변조건이 필요하다.
2. table에서 해결되지 않고 tree_total이 0이 아니면 `0x1460f0`에서 splay lookup을 수행한다. 정확한 이름이 있으면 기존 node를 반환한다. 이미 별도 준비 node를 확보했다면 성공 경로에서도 그 미사용 node만 zfree한다.
3. index가 `[size,next_size)`이고 table 추가 비용보다 `(tree_small+1)` node 비용이 크면 grow_table을 호출한다. `0x146131` 이후 실제 비교는 DWORD shift와 unsigned 비교다. grow가 0이면 active/table/tree를 다시 검사한다. 오류이면 준비 node가 있을 때 해제하고 오류를 보존해 반환한다.
4. tree node가 필요하지만 아직 없으면 `0x146236`에서 namespace unlock, `0x146240`에서 zalloc을 수행한다. 실패하면 6(KERN_RESOURCE_SHORTAGE), 출력 없이 unlocked 상태로 반환한다. 성공하면 lock을 다시 잡고 `0x146020`으로 돌아가 active 및 기존 이름을 처음부터 재검사한다. unlocked 구간의 오래된 miss 결과를 그대로 삽입에 사용하지 않는다.
5. 준비 node가 있고 여전히 새 이름이면 tree_total을 먼저 증가시킨다. index가 현재 table 안이면 해당 bits에 COLLISION을 추가한다. 다음 크기 안이면 bounds로 인접 key의 index를 확인하고 같은 index가 없을 때만 tree_small을 증가시킨다. 그 뒤 insert를 호출한다.

`0x1461fe`의 insert 호출 후 `0x146203`, `0x146209`, `0x146210`에서 bits/object/request를 0으로 만들고 `0x14621a`에서 node.space를 저장한다. hash next `+0xc`는 초기화하지 않는다. 반환은 lock 유지 상태의 아직 권한 type가 없는 entry다. active와 tree_total의 정확성, caller가 잠금을 놓기 전에 type/object를 완성한다는 조건, 모든 producer의 고유 key 보장까지는 별도 검증이 필요하다.

dead 상태는 unlock 후 준비 node만 해제하고 16을 반환한다. 기존 entry 반환/새 table entry/새 tree entry의 성공은 namespace lock 유지다. 성공 경로에서 zfree가 호출되더라도 namespace unlock을 추정해서는 안 된다.

## splay insert의 직접 계약

인자는 `(tree, name, supplied_node)`이다. 직접 CALL/allocator/free/lock 획득은 없다. 빈 root이면 새 node의 left/right를 NULL로 만든다. 비어 있지 않고 cached name이 요청과 다르면 assemble/lookup primitive를 inline으로 실행한다.

`0x150cfa`는 root key와 요청을 unsigned 비교한다. 요청이 root key보다 작으면 left tail에 NULL, right tail에 root를 저장하고, 그렇지 않으면 left tail에 root, right tail에 NULL을 저장한다. 이어 tree의 ltree/rtree를 새 node의 children으로 가져온다. 공통부에서 node.name, tree.root, tree.name 및 self-tail들을 저장한다. node bits/object/request/space/hash는 이 helper가 설정하지 않는다.

원본에는 duplicate key나 supplied_node NULL 검사가 없다. 참조 소스의 `root->ite_name != name` 및 빈 child assert도 실행되지 않는다. 동일 key는 원본 비교상 else 방향으로 간다. 이것을 중복 삽입 지원으로 해석해서는 안 된다. 원래 계약은 caller가 별도의 새 node와 아직 존재하지 않는 이름을 제공하는 것이다. alloc_name은 위의 locked 재검색으로 이 계약을 뒷받침하지만 다른 caller까지 증명하지 않았다.

## grow_table: ABI, lock 반환과 교체 단계

원본 `0x1464ac`은 space 인자만 사용한다. 현재 확인한 caller `0x145fd1`, `0x146144`도 인자를 하나 push한다. 전체 본문에서 직접 `[EBP+0xc]` operand가 없는 것을 Python으로 확인했고, 수동 본문 검토에서도 target_size 탐색은 없다. 반면 Darwin 함수는 `(space, target_size)`이며 지정 크기 검색과 별도의 성공 반환 분기를 갖는다. 원본 ABI/제어 흐름에 그 기능을 근거 없이 추가하지 않는다. 직접 stack-slot 부재 검사만으로 일반적인 alias를 통한 인자 읽기를 증명한 것은 아니다.

| 조건 | 원본 작업과 반환 |
| --- | --- |
| 다른 grow 진행 중 | assert_wait(space,0), unlock, block(NULL), relock 후 0 |
| 이전 size와 다음 size가 같음 | unlock 후 3 |
| 새 table 확보 실패 | relock, growing=0, unlock, wakeup 후 6 |
| 확보 중 space가 죽음 | unlock, wakeup, 새 table free, relock 후 0 |
| 교체 완료 | unlock, wakeup, 옛 table free, relock 후 후속 상태 확인 |

0 반환은 이 호출이 table을 실제 확장했다는 뜻만이 아니다. 기다린 경우나 space가 죽은 경우도 0이다. 그래서 alloc/alloc_name의 재검사가 필요하다. 원본의 위 0 반환들은 lock 유지이며 3/6은 unlock이다. wait/wakeup의 실행·스케줄링 안전성은 callee와 space 수명을 더 확인해야 한다.

크기는 `space.next`가 가리키는 descriptor의 앞/현재/다음 DWORD에서 각각 osize/size/nsize로 읽는다. 저장된 space.size와 osize가 같고 `osize < size <= nsize`라는 소스 assert는 원본에 없다. old_bytes=`osize << 4`가 page_size보다 작으면 table_alloc(new_bytes), 아니면 table_realloc(old_bytes, old_table, new_bytes)를 호출한다. 할당 전에 growing=1 및 unlock, 돌아오면 relock 후 growing=0이다. allocator가 기존 table을 보존·매핑하는 실제 방식은 이번 범위에서 확인하지 않았다.

성공·active이면 `0x146632/0x146638/0x14663e`에서 table/size/next를 먼저 갱신한다. 새 할당 경로는 그 뒤 old bytes를 bcopy한다. old 영역의 hash-index slot을 모두 0으로 만들고, 새 영역은 bzero한 뒤, old 영역 중 정확히 pure SEND type만 local reverse hash에 다시 넣는다. 전체 초기화는 namespace lock 안에서 수행되지만 잠금 없는 reader가 없다는 전역 증거는 아직 없다.

## grow_table의 tree 이동과 free-list 재구축

tree_total이 0이 아니면 split의 엄격한 경계를 이용해 아래 영역을 만든다. 아래 명칭은 참고 소스와 원본 stack object를 대응시킨 것이다. 이름 경계는 각 size를 왼쪽으로 8 bit 이동한 DWORD다. 크기와 shift가 유효한 범위라는 전제가 필요하다.

| index 영역 | 임시 tree | 작업 |
| --- | --- | --- |
| `[0, osize)` | ignore | 이번 확장에서 이동하지 않음 |
| `[osize, size)` | move | 새 table 영역으로 이동 시도 |
| `[size, nsize)` | small | 다음 확장에서 이동 가능한 서로 다른 index 수 계산 |
| `[nsize, …)` | space.tree | 이번 확장에서 이동하지 않음 |

split 호출은 `0x1466fe`, `0x14670f`, `0x146720`이다. move traversal에서 대상 table bits 전체 DWORD가 0인지 검사한다(`0x14675d`). nonzero이면 COLLISION을 더하고 traverse_next(move,0)를 호출한다. 0이면 tree bits에 name의 generation을 OR하고 object/request를 복사한다. pure SEND만 global hash delete 후 local hash insert로 옮긴다(`0x14679e` 다음 `0x1467ad`). tree_total을 감소시키고 traverse_next(move,1)를 호출한다. 원본에는 type!=NONE, 세대 차이, node.space 같은 assert 검사가 없다.

여기서 delete=1을 전달한다는 사실과 실제 node 해제 구현 검증은 구분한다. traverse_next 본문은 다음 범위이며 이번 보고서에서는 정확한 해제 시점/전수 방문을 확정하지 않는다. small traversal은 연속으로 보이는 index가 바뀔 때만 count를 증가시킨다. 정렬 순회가 보장될 때 서로 다른 index 수가 되며 초기 직전 index=0이 유효하려면 이 영역이 index 0을 포함하지 않아야 한다. count를 tree_small에 저장한 뒤 join은 small, 남은 move, ignore 순서로 수행된다.

새 table 영역은 큰 index부터 내려오며 bits가 0인 entry에 `0xff000000`을 넣고 next를 기존 free head로 연결한다. 마지막 head를 table[0].next에 저장한다. generation을 이렇게 시작하므로 첫 get에서 wrap하여 gen=0 이름이 나온다. 이 작업은 새 영역의 hash-index를 다시 지우지 않는다. 이미 hash 재구축에 쓰였을 수 있기 때문이다. 역순 순회가 unsigned index 0에서 언더플로하지 않으려면 osize>0 등 table 크기 조건이 필요하다.

unlock/wakeup/old table free/relock 후 space가 죽었거나 next descriptor가 다른 값이면 0으로 끝낸다. 동일 descriptor이고 tree_small이 있으며 다음 table 증가 비용이 tree node 비용보다 작으면 다시 grow를 시도한다(`0x1468f1`). DWORD 산술 wrap의 도달성, size descriptor 생성과 최대 크기, allocator 보존 조건 및 space 파괴와의 협력은 아직 미완료다.

## reverse lookup: 포인터 수명과 조회의 변경 효과

hash_lookup은 `(space, object, namep, entryp)`로 local lookup을 먼저 호출한다. 실패하면서 space.tree_hash가 0이 아닐 때만 global lookup을 호출하고 결과를 0/1로 정규화한다. own namespace lock/active 검사나 object ref 획득은 없다. source 계약은 namespace lock을 호출 전후 유지하는 것이다. tree_hash count가 실제 membership과 어긋나면 global 조회 생략 여부에도 영향을 주므로 앞선 delete의 count 계약이 중요하다.

local lookup의 `0x146b6e DIV`는 unsigned `(object >> 6) % size`이다. hash slot이 0이면 miss로 반환하며 출력에는 쓰지 않는다. nonzero index이면 해당 table entry의 object 포인터와 비교한다. 일치하면 `0x146b8b`에서 bits의 상위 byte를 읽어 `(index << 8)`과 OR한 이름, entry 포인터를 출력한다. 실패하면 한 slot 진행하고 size에서 0으로 wrap한다. type/active/인덱스 상한이나 중복 index를 검사하지 않는다. size=0 방어, full hash-table의 miss 순회 제한도 없다. 반환 전에 ref를 추가하지 않으므로 caller의 namespace lock 수명 계약이 필요하다.

global lookup은 `((space >> 4) + (object >> 6)) & mask`의 8-byte bucket을 잠근다. node.object와 node.space가 모두 같은지 비교한다. head에서 찾으면 출력만 쓰고, 뒤에서 찾으면 `0x146a4b`, `0x146a50`, `0x146a53`에서 기존 링크에서 빼내 head로 옮긴 후 출력한다. 따라서 성공한 조회가 연결을 변경할 수 있다. 실패에는 출력 저장이 없으며 모든 정상 경로는 bucket unlock 후 node!=NULL을 EAX의 0/1로 반환한다. count/ref/type/request 변경이나 node free는 없다. bucket lock 해제 뒤 반환 포인터가 살아 있다는 근거는 namespace/producer 수명까지 연결해야 한다.

## 남은 검증

이번 결과는 [보고서 61](../continuous-review-20260912-61/README.md)의 dealloc/hash 제거와 [보고서 62](../continuous-review-20260912-62/README.md)의 splay 계약을 생산자 측에서 보완한다. 아직 모든 입력 불변조건이 닫힌 것은 아니다. 다음 정적 범위는 traverse start/next/finish, table alloc/realloc/free와 size descriptor 생성, 이어 space 생성/파괴다. 전체 [OPEN_ITEMS](OPEN_ITEMS.md)를 유지한다.

신규 독립 계획 검토는 확보되지 않았다. 문서와 정적 증거만 추가했으며 새 실행 검증 프로그램·동적 실행·DB/원본/07_kernel 수정·GCC 2.7 실컴파일·링크·부팅은 수행하지 않았다. 전체 의미 분석과 복원 목표는 미완료이다.
