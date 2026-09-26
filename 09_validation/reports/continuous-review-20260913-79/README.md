# 79차 — object 종료·cache trim·pager 수명 경계

## 범위와 판정

OPENSTEP 원본 바이너리와 그 보존 Ghidra asm/C/메타데이터만 사용했다. 다른 프로젝트
코드, `01_resources`, `07_kernel`은 참고하지 않았다. Ghidra 스킬은 기존 export 읽기와
원본 대조에 한정했으며 원본·DB·기존 export·이전 보고서는 변경하지 않았다.
구현·빌드·포팅·새 실행 검증 프로그램·동적 실행·새 독립 계획 검토는 수행하지 않았다.

Python으로 본문 13개, 명령어 1,281개, 3,636바이트의 원본 mapping과 재디코딩을 확인했다.
직접 분기 201곳의 목적지가 해당 본문 명령어 시작점인지, 직접 CALL 46곳의 목적지가
export와 일치하는지 확인했다. 간접 CALL은 vnode_dealloc의 `0x17e0a6` 한 곳이며,
실제 target 집합은 아직 확정하지 않았다. 선택 본문의 전부를 읽은 것과 전역 의미·도달성·
모든 callee가 검증된 것은 다르다.

명령어·원본 nlist·문자열·계산은 [object-lifetime-evidence.json](object-lifetime-evidence.json),
이전 범위 내 보존 해시는 [preservation.json](preservation.json), 후속 경계는
[OPEN_ITEMS.md](OPEN_ITEMS.md)에 기록했다. Ghidra WARNING 주석은 11개이며,
경고가 없는 함수도 원본과 다른 lock 표현·인자 추정·갱신 순서를 포함한다.

## 핵심 연결

| 경계 | 원본에서 확인한 계약 |
| --- | --- |
| vm_object_terminate 진입 | 자신의 object lock을 이미 보유한 호출을 전제로 하며, 연결 object lock은 별도로 획득 |
| thread_sleep | wait를 등록한 뒤 전달받은 lock을 해제하고 block 호출. 전달 lock을 직접 재획득하지 않음 |
| terminate의 pager 호출 전 | 자신의 object lock을 실제 해제. pager 반환 후에도 재획득 없이 잔여 목록을 처리 |
| cache_trim → lookup | 저장한 cached head의 pager로 조회하고 WORD 참조를 얻음. 조회 결과가 저장한 head와 같은지 검사 |
| cache_object(object,0) | cache 허용 mask를 변경할 뿐 아니라 참조를 소비하며, 마지막 참조이면 종료 경로로 이어짐 |
| device pager 종료 | page를 object/hash에서 detach한 뒤 metadata allocation을 kfree. VM free queue 반환과 다름 |
| vnode pager 종료 | packed 기록·bitmap·보조 집계와 조건부 VFS 간접 호출을 거친 뒤 vstruct zone에 반환 |

## vm_object_terminate — lock 소비와 단계별 페이지 처리

`0x178d60`은 object stack 인자 하나를 읽고 자체 NULL 검사는 하지 않는다.
77차 vm_object_deallocate와 이번 cache_object의 종료 호출은 object lock을 보유한 채
이 함수에 들어온다. 진입부터 자신의 lock을 새로 획득한다고 해석하면 안 된다.

object+0x20이 가리키는 연결 object가 있으면 그 +0x10 lock을 획득한다. 연결 object+0x1c가
자신이면 0으로 만들고, 0이면 그대로 두며, 그 외 포인터이면 `0x178dad` panic이다.
원본 문자열은 `vm_object_terminate: copy/shadow inconsistency`다. 외부 구조체 정의로
이 관계의 모든 생성·수명 규칙을 채우지는 않았다. 연결 object lock은 `0x178db7`에서 해제한다.

자신의 +0x44 WORD가 0이 아니면 thread_sleep(object, object+0x10, 0)을 호출한다.
반환 뒤 `0x178dd0`에서 자신의 lock을 다시 잡고 WORD를 재검사한다. 음수처럼 보이는
WORD도 0이 아니면 이 검사에 해당하며, signed 양수 검사로 바꾸지 않는다.

첫 페이지 순회는 자신의 object lock을 유지한 채 page마다 queue lock을 잡는다.

- page+0x1e & 2이면 active 목록에서 제거하고 수를 감소시킨 뒤 mask를 지운다.
- 이어 & 1이면 inactive 목록도 독립적으로 제거한다. else-if가 아니다.
- page+8의 next를 `0x178e8c`에서 먼저 저장한다.
- page+0x1e & 8이 설정된 경우에만 `0x178e96`에서 vm_page_free를 호출한다.
  78차에서 이 mask는 addfree 재삽입을 건너뛰게 하는 직접 조건임을 확인했다.
- queue lock을 풀고 저장한 next로 진행한다.

따라서 첫 순회에서 모든 page를 free하는 것은 아니다. active/inactive 제거와
이미 free 상태인 page의 object/hash detach를 구분한다. next 저장도 free 전에 있다.

`0x178eb2`는 자신의 object+0x10 lock을 실제로 0으로 교환한다. 그 뒤 +0x28이
non-NULL일 때 vm_pager_deallocate를 호출한다. pager 반환 뒤 +0x44 WORD가 nonzero이면
`0x178ed1`에서 `vm_object_deallocate: pageout in progress` panic이다.
이 검사에서 다시 sleep하거나 자신의 lock을 재획득하는 명령은 없다.

다음 순회는 매번 현재 object 목록 head를 읽고 queue lock 아래 vm_page_free를 호출하여
목록이 sentinel이 될 때까지 진행한다. 자신의 object lock을 다시 잡지 않으므로, 종료 중
배타적 수명·pager의 정리·다른 writer의 정지 조건을 입증해야 한다. 조건 없이 안전하거나
곧바로 race라고 단정하지 않는다.

마지막에는 vm_object_list_lock을 획득하고 object+8/+0xc의 next/prev와 sentinel을
연결 해제하며 vm_object_count를 감소시킨다. sentinel.next 쓰기는 `0x178d98`의
앞쪽 별도 코드 조각으로 분기한다. 이 조각을 함수 초기 처리라고 잘못 배치하지 않는다.
list lock 해제 뒤 vm_object_zone에 zfree한다. 연결 object+0x20의 다음 참조 소비는
이 본문이 아니라 호출자가 미리 저장한 포인터를 사용해 이어간다.

## thread_sleep — 전달 lock 해제의 원본 확인

`0x163320`의 인자는 event, 해제할 lock 포인터, 제어값이다. active_threads에서 읽은
포인터의 +0x3c가 이미 nonzero이면 printf와 panic을 호출한다. 정상 흐름은 splsched를
저장하고 event가 nonzero인 경우 wait bucket과 thread+0x20 lock을 잡아 queue를 연결한다.

event의 signed 값이 음수이면 절댓값이 아니라 **DWORD 보수**를 사용해 59로 나눈 나머지를
bucket으로 삼는다. Python 검산에서 event 0xffffffff는 bucket 0, 0xfffffffe는 bucket 1이다.
event 0은 bucket 등록 없이 thread 상태만 갱신한다.

thread+0x3c에 event를 기록하고 제어값이 0이면 thread+0x4c에 OR 9, 아니면 OR 1을 한다.
내부 thread/bucket lock을 해제하고 splx한 다음, `0x16343a`에서 **인자로 받은 lock**을
0으로 교환한다. 그 후 thread_block_with_continuation(0)을 호출한다. 자체 재획득은 없다.
이로써 terminate와 lock_write의 재획득 loop가 필요한 이유를 원본에서 연결했다.
실제 wakeup·scheduler·interrupt 실행과 event writer 전체 검증은 아직 별도다.

## cache_trim·lookup·cache_object — 단순 삭제가 아닌 참조 소비

vm_object_cache_trim `0x1790dc`는 cache lock 아래 signed cached > cache_max일 때만
작업한다. 원본은 그때 cached head를 EBX에 저장하고 lock을 해제한 뒤 **EBX+0x28**을
lookup 인자로 읽는다. C는 저장한 포인터 대신 해제 뒤 global cached head를 다시 읽는
표현을 포함한다. 동시성 분석에서는 이 둘을 같은 메모리 접근으로 취급하지 않는다.

lookup 반환 포인터가 저장한 EBX와 다르면 panic이며, 같으면 cache_object(EBX,0)를 호출하고
cache lock을 다시 잡아 한도를 재검사한다. snapshot을 참조로 고정하기 전에 lock을 푸는
구간의 객체 수명·재진입 조건은 추가 검토 대상이다. 한도가 음수이면 cached=0에서도
signed 비교가 참일 수 있으며, 이 함수 자체에 별도 빈 목록 guard는 없다. 실제 설정이
그런 상태인지 입증하지 않았으므로 정상 실행 결함으로 발표하지 않는다.

vm_object_lookup `0x179630`는 `(pager & 0x7f) * 8 + vm_object_hashtable`의 bucket을
cache lock 아래 검색한다. hash entry+8이 object이고 object+0x28이 key다.
발견하면 object lock도 잡는다. **기존 참조 WORD +0x18이 0인 경우에만** cached 목록에서
object를 제거하고 cached 수를 감소시킨 뒤, WORD 참조를 증가시킨다. object lock,
cache lock을 해제한 뒤 EAX=object를 명시적으로 반환한다. 미발견은 EAX=0이다.
WORD 0xffff의 증가 wrap, 잘못된 cached 연결·hash membership은 직접 방어하지 않는다.

vm_object_cache_object `0x179170`는 object가 NULL이면 EAX=4를 반환한다. 그 외에는
cache→object lock 아래 두 번째 인자 **최하위 bit만** object+0x46의 mask 0x08에 옮긴다.
따라서 일반적인 nonzero 판정과 다르다. Python 예시에서 인자 2는 mask를 지우며 3은 설정한다.
이후 두 lock을 해제하고, 다시 cache→object lock을 잡아 WORD 참조를 소비한다.

감소 전 WORD가 1이 아니면 unlock하고 종료한다. 1이면 다음과 같다.

- mask 0x08이 설정되고 signed WORD +0x1a > 0이면 cached tail에 연결하고 수를 증가시킨다.
  tail 저장 `0x179275`는 cache unlock `0x179283`보다 먼저다. C에서는 뒤로 옮겨져 있다.
  object lock을 유지한 채 deactivate_pages, object unlock, cache_trim 순서다.
- 그 외에는 필요 시 mask를 지우고, 두 lock 아래 vm_object_remove(object+0x28)를 호출한다.
  cache lock을 해제하고 object+0x20을 저장한 뒤 terminate를 호출한다.
  저장한 연결 object로 이어서 참조를 소비한다.

초기 인자로 지정한 cache mask는 첫 object에만 적용한다. 모든 연결 object의 cache를
일괄 비활성화하는 함수가 아니므로, 후속 object가 다시 cached 경로로 들어가거나 trim을
호출할 수 있다. ordinary non-NULL 반환은 EAX=0이지만 모든 하위 처리의 성공·즉시 파괴를
보장하는 별도 결과 코드는 아니다.

vm_object_remove `0x179764`는 같은 bucket에서 pager key가 맞는 첫 hash entry만 unlink하고
object_hash_zone에 zfree한다. 자체 cache/object lock 획득은 없으며 object 자체를 free하거나
+0x28을 0으로 쓰지 않는다. key 0도 자체 조기 반환으로 거르지 않는다. bucket 생성·중복·수명
규칙은 계속 원본 writer에서 확인해야 한다.

## 페이지 비활성화와 page_remove

vm_object_deactivate_pages `0x179084`는 object stack 인자 하나를 사용한다. Ghidra의
추가 EAX `__regparm1` 인자를 의미 있는 입력으로 보지 않는다. page next를 queue lock보다
먼저 저장하고, lock 아래 page+0x1e & 1이 0일 때 vm_page_deactivate를 호출한다.
이 함수는 object lock을 직접 잡거나 해제하지 않으며 caller가 보유하는 경계와 구분한다.

vm_page_deactivate `0x17b810` 자체는 page+0x1e & 2가 설정된 경우에만 작업한다.
pmap_clear_reference(page+0x24), active 목록 제거, inactive tail 연결,
mask 2 제거·mask 1 설정과 카운터 갱신 순서다. 이후 mask 0x20이 설정된 경우에만
pmap_is_modified를 호출하여 반환 nonzero이면 그 mask를 지운다. 마지막에는 현재 byte의
mask 0x20에 반대되는 값을 mask 4에 기록한다. 자체 queue lock은 없다.

Python byte 예시의 0x22 → 0x21 또는 0x05 차이는 제시한 pmap 반환과 다른 flag가
변하지 않는 조건에서의 산술이다. 아직 읽지 않은 pmap helper의 모든 부수 효과를
실행한 결과가 아니며, invalid active/inactive 동시 flag를 유효 목록 상태로 가정하지 않는다.

vm_page_remove `0x17aeac`는 78차 vm_page_free의 hash/object detach와 같은 형태의
직접 처리를 한다. membership byte mask 4를 검사하고 bucket lock·splimp 아래 hash
연결을 제거한다. bucket unlock/splx 뒤 object 목록을 unlink하고 object+0x1a WORD를
감소시킨 뒤 membership mask를 지운다. hash chain에서 미발견 NULL 탈출은 직접 없다.
**vm_page_addfree 호출은 전혀 없다.** 따라서 device metadata 목록의 detach를 VM page의
free queue 반환과 동일시하지 않는다.

## pager dispatch와 device 해제

vm_pager_deallocate `0x17a2c0`는 NULL이면 panic, pager 첫 DWORD가 nonzero이면
device_dealloc, 0이면 vnode_dealloc을 호출한다. 이 wrapper의 분기만으로 모든 pager
형식·입력 수명을 확인했다고 할 수 없다.

device_dealloc `0x17c28c`는 pager+4가 가리키는 목록이 sentinel이 될 때까지 현재 head에
vm_page_remove를 호출한다. 그 뒤 pager+8의 포인터와 pager+0xc의 크기로 kfree한다.
목록에서 실제로 제거되는 page와 pager+4 목록의 일치가 진행성 전제다. 직접 page queue
free나 별도 pager-zone zfree는 없다. pager가 metadata allocation에 포함되는지 등 생성
경로를 보지 않고 누수·이중 해제 여부를 단정하지 않는다.

## vnode_dealloc — 저장 기록, bitmap, 간접 VFS 호출

`0x17dc74`의 전체 보존 본문을 읽고 재디코딩했다. 진입은 vstruct_lock 아래 인자+0xe
WORD를 증가시키고 lock을 푼다. 이 WORD의 증가를 외부 구조체의 참조 수로 확정하지 않았다.
나머지 전체 처리를 vstruct_lock으로 감싸는 형태가 아니다. global `0x1e0e58` 집계 수를
0으로 만들고 인자+0xc의 mask 1로 경로를 나눈다.

### 저장 기록 경로

mask 1이 설정되면 인자+4를 보존하고 +0x10의 count, +8의 저장소를 사용한다.
`(count * 4) mod 2^32 <= 0x40`이면 flat 배열이며 signed 양수 count만큼 순회한다.
그 외에는 `((count - 1) mod 2^32 >> 4) + 1`개의 포인터를 순회하며, NULL이 아닌 각
하위 블록의 16개 기록을 전부 처리하고 해당 블록을 64바이트로 kfree한다.
마지막 블록을 실제 count 나머지로 제한하지 않으므로 생성 시 나머지 기록의 초기화·유효성이 필요하다.
count=17의 조건부 산술은 하위 블록 2개, 각 16개 슬롯, 상위 포인터 배열 8바이트다.
count 곱셈 wrap을 거르는 별도 검사는 없으므로 정상 count 범위는 writer에서 입증해야 한다.

각 기록은 low byte가 0이면 건너뛴다. 아니면 그 byte로 `0x1e7294`의 포인터 table을
색인하고, 나머지 상위 bit는 logical SHR 8로 기록 번호를 얻는다. descriptor+0x34에
lock_write를 호출하고 descriptor+0x14의 signed 값이 번호보다 커야 한다. 아니면 panic이다.
descriptor+0x24를 더 작은 번호로 갱신하고, +0x10 bitmap의 번호/8 byte에서 번호%8 bit를
ROL32(0xfffffffe,bit)의 AL로 지운다. descriptor+0x18 DWORD를 증가시키고 lock_done한다.
low-byte ID의 table 상한이나 이미 비어 있는 bit를 직접 검사하지 않으므로 이 불변식은 미완료다.

Python 범위 계산에서 logical SHR 8 결과는 0부터 16,777,215다. 호출된 lock_write의
EBX 보존도 원본에서 확인했으므로, 정상 반환·stack 보존을 전제로 `0x17dd64`와
`0x17deb6`의 음수 나눗셈 보정 분기는 이 데이터 흐름에서 실행되지 않는다.
이 두 블록은 Ghidra가 제거했다고 경고한 위치와 일치한다. 임의 중간 진입까지 제외한
전역 도달성 증명은 아니다.

각 기록은 bitmap 해제 뒤 저장소에서 다시 읽어 별도 집계에 사용한다. `0x1e72d4`에 같은
low-byte ID가 있으면 상위 번호의 최대값을 남기고, 없으면 append해 `0x1e0e58`을 증가시킨다.
집계가 중복 ID를 합쳐도 앞선 bitmap 해제 자체의 중복을 방지하는 것은 아니다.
집계 table의 capacity 검사·전체 구간 lock은 이 본문에서 직접 보이지 않는다.

하위 블록과 상위 배열 또는 flat 배열을 kfree한 뒤, 보존한 인자+4 대상의 +0xc DWORD를
감소시킨다. 저장소 포인터들을 임의로 0으로 초기화하는 코드를 분석 결과에 추가하지 않았다.

### 다른 분기와 후속 크기 조정

mask 1이 0이면 인자+0x14 대상의 +4 byte에 AND 0xfd, 그 대상 첫 포인터가 가리키는
DWORD에 0을 쓴 뒤 vn_rele를 호출한다. 이 포인터 관계의 완전한 타입은 아직 확정하지 않았다.

집계된 각 ID에 대해 descriptor+8 포인터를 먼저 저장한다. signed descriptor+0x20이
집계 최대 번호 이하이고 swapfs_enabled가 0일 때만 descriptor+0x34 write lock을 잡는다.
최대 해제 번호 **바로 아래**부터 bitmap을 내려가며 남아 있는 set bit를 찾는다.
찾으면 그 번호를 +0x20에 저장한다. 찾지 못하면 +0x20을 0이나 -1로 바꾸지 않고
기존 값을 유지한다. 이 동작을 일반적인 high-water 갱신 관례로 대체하지 않았다.

그 뒤 (+0x20 + 1)의 DWORD 값을 계산한다. +0x1c가 nonzero이고 signed 비교상 후보가
그 값보다 크며, 후보 << page_shift의 DWORD 결과가 저장 대상의 크기 field 이하일 때
후속 호출을 준비한다. Python 가상 예시에서 검색 실패 시 기존 +0x20=10은 그대로 남아
후보 11이 된다. 이것이 실제 파일 상태에 맞는지는 저장소 생성·bitmap writer를 더 봐야 한다.

vattr_null에 지역 buffer를 넘기고, 그 buffer 시작으로부터 24바이트 위치에 크기 DWORD를
기록한다. active_u+0x1c의 기존 값을 보존하고 대상에서 읽은 +0x30 값으로 잠시 바꾼다.
이후 저장한 포인터의 +0x1c에서 얻은 ops 포인터의 **+0x18 함수 포인터**를
`0x17e0a6`에서 세 stack 인자로 호출한다. 원본 문자열과 준비한 크기/속성 데이터는
파일 크기 조정 계열임을 시사하지만, 실제 target 함수는 아직 확정하지 않았다.

간접 반환이 nonzero이면 오류를 printf하고, active_u를 다시 읽어 보존한 값을 복원한 뒤
lock_done한다. 오류 시 앞선 bitmap/배열 해제를 rollback하거나 이 함수에서 재시도하는
명령은 없다. 마지막에는 vstruct_zone에 zfree한다. 원본 간접 호출의 존재를 발견한 것과
모든 VFS 구현·권한/오류·wait 수명을 분석한 것은 다르다.

## lock_write — 레지스터 보존과 대기 의미의 추가 확인

`0x15b5d0`은 EBX를 저장하고 유일한 ordinary epilogue에서 복원한다. 이를 통해 vnode
경로의 logical SHR로 얻은 번호가 이 직접 callee의 정상 반환 뒤에도 보존됨을 연결했다.

자체 lock+8의 spin을 잡고 *lock이 active_threads에서 읽은 포인터와 같으면 +6 WORD의
낮은 nibble을 보존하면서 나머지 부분에 0x10을 더한다. Python의 0xfff2 예시는
0x0002로 wrap한다. 자체 overflow guard를 추가로 추정하지 않는다.

다른 경우 +6 byte의 mask 2가 없어질 때까지 기다리고 이를 설정한 뒤, +4 DWORD의
mask 0x1ffff가 0이 될 때까지 기다린다. lock_wait_time이 signed 양수이면 spin을 잠시
풀고 제한된 반복 후 재획득한다. 첫 제한 반복은 byte를, 다음 반복은 DWORD mask 값을
한 번 읽은 레지스터를 반복 검사한다. C의 매 반복 메모리 읽기와 같은 관찰 시점이 아니다.

설정된 mask 조건에 따라 wait 표시 mask 4를 쓰고 thread_sleep(lock,lock+8,0)을 호출하며,
반환 뒤 spin을 다시 잡아 조건을 재검사한다. 마지막에는 spin+8을 0으로 해제한다.
복합 lock의 논리 상태와 내부 spin 보유를 혼동하지 않는다. lock_done의 모든 writer·
wakeup·재귀·native 진행성은 아직 이 추가 본문만으로 완료된 것이 아니다.

## 디컴파일 차이와 보존 한계

- object list lock, cache trim/lookup/cache-object 진입, vnode vstruct lock에는 원본의
  EAX=1/XCHG 획득 쓰기가 C에서 생략된 예가 있다. LOCK/UNLOCK 표시만으로 대체하지 않는다.
- cache_object의 cached tail 저장은 cache unlock 전이며, cache_trim의 pager 인자는
  unlock 후 바뀔 수 있는 global head가 아니라 저장한 EBX에서 읽는다.
- deactivate_pages의 EAX 추가 인자는 원본 stack ABI로 뒷받침되지 않는다.
- cache_trim의 원본 반환 EAX는 마지막 unlock XCHG의 이전 word다. C의 상수 1은 정상
  lock 값 불변식 아래의 해석이며, 독립적인 성공 코드로 확정하지 않는다.
- register-only `75fc` spin은 24곳이며, object-list lock 한 곳에는 load/TEST 사이 NOP가 있다.
  원본의 재로드 위치를 보존했으며 native 실행이나 동시성 성공을 검증하지 않았다.

원본 SHA-256은 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`이다.
입력 45개, 이전 범위 내 보존 파일 765개의 해시와 원본 문자열 8곳을 확인했다.
모든 산술은 Python으로 수행했으며, 유한 예시는 명시한 조건의 산술이지 kernel·pager·
filesystem emulator가 아니다. 전체 원본 분석 목표는 아직 완료되지 않았다.
