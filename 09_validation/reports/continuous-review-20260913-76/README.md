# 76차 — 원본 zone collect/reclaim·GC의 소유권과 lock

## 결과

원본의 zone 원소 수집, free-space 병합, 페이지 경계별 회수, GC 진입과 직접 VM 반환
wrapper를 연결했다. 특히 `zone_free_space_reclaim`은 회수 목록을 외부로 반환하는
함수가 아니다. 호출자가 보유한 zget-space lock을 스스로 해제한 뒤 해당 영역들을
`kmem_free`에 전달한다. 실제 VM/page 반환 성공과 이후 주소 재사용까지 입증하지는 않았다.

다른 프로젝트 소스·복원 코드는 사용하지 않았다. Ghidra 스킬을 보존 asm/C에 적용하고
Python으로 원본 Mach-O mapping·nlist·명령·분기·유한 산술·해시를 검증했다.
원본·DB·기존 export·이전 보고서는 변경하지 않았다. 구현·빌드·포팅·동적 실행은 없다.

근거: [범위](SCOPE.md), [원본 명령 및 산술](zone-gc-evidence.json),
[보존 해시](preservation.json), [후속 분석](OPEN_ITEMS.md).

## 원본 검증 범위

바이너리 SHA-256은 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`다.
Capstone 4.0.2 x86 32-bit로 file-backed 원본을 다시 디코딩했다. 보존 metadata의
inclusive body range와 명령 바이트 집합, 직접 분기의 명령 시작점 및 CALL 목적지를
대조했다. 보존 본문 밖 gap을 임의로 명령으로 채우지 않았다.

| entry | 원본 심볼 | 본문 바이트 | 명령 |
|---|---|---:|---:|
| 0x16a7f4 | `_zone_collect` | 822 | 320 |
| 0x16ab34 | `_zone_free_space_reclaim` | 611 | 227 |
| 0x16b970 | `_zone_gc` | 274 | 100 |
| 0x16bad0 | `_zone_reclaim` | 40 | 15 |
| 0x16ba88 | `_consider_zone_gc` | 69 | 18 |
| 0x17c428 | `_gc_control` | 184 | 52 |
| 0x173e90 | `_kmem_free` | 44 | 20 |
| 0x1765ac | `_vm_map_remove` | 79 | 38 |

8개 본문, 790개 명령, 2123바이트다. 직접 분기 132개, CALL 21개, 간접 transfer 0개다.
Ghidra WARNING 주석은 0개지만 아래와 같이 반환·메모리 읽기·lock store의 해석 차이가
있다. 경고가 없음을 디컴파일 의미의 정확성으로 취급하지 않는다.
현재 입력 30개, 이전 보존·보고서 파일 747개와 직전 입력 36개를 재검증했다.

## 1. zone_collect — free 원소의 이전과 accounting

ABI는 zone 포인터 하나다. zone+0x1c를 원소 크기로 저장하고 +0x3c descriptor가
0 또는 default 주소 0x1f6db0이면 종료한다. 함수 자체에는 lock 확보·해제나 VM CALL이
없다. 호출자 `zone_gc`의 backend 및 zone lock 계약과 함께 해석해야 한다.

각 zone free 원소에 대해 **zone+0x14를 원소 크기만큼 먼저 감소**시키고(0x16a842),
그 원소의 다음 포인터를 local에 저장한다(0x16a845/0x16a847). 그 뒤 첫 word들을
descriptor free-block header로 재사용할 수 있다. 마지막에는 저장한 next를 zone+0x10에
기록하고 다음 원소로 간다(0x16ab13). 순회를 마치면 insertion cache인 +0xc도 0으로
만든다. 사용 중 개수인 zone+8을 변경하는 store는 이 본문에 없다.

즉 free 원소가 descriptor 쪽으로 넘어가면 zone의 저장소 용량은 감소한다. 그러나 그
공간이 아직 descriptor에 남아 있고 VM으로 반환되지 않았을 수도 있다. zone 용량 감소와
실제 페이지 해제를 같은 사건으로 세지 않는다.

descriptor 목록 검색은 이전 링크 위치를 재사용하며 주소 순서·비중첩·올바른 원소 크기를
전제로 한다. 각 원소와 후보 free block의 관계에 따른 원본 변화는 다음과 같다.

| 관계 | 주요 처리 | descriptor entry 수 변화 |
|---|---|---:|
| 후보가 없거나 원소 끝 뒤에 떨어져 있음 | 원소 자체에 header를 만들어 삽입 | +1 |
| 원소 끝이 후보 시작과 같음 | 원소 앞으로 header를 옮겨 후보와 병합 | 0 |
| 후보 끝이 원소 시작과 같음 | 후보 길이를 늘림 | 0 |
| 위 append 후 다음 블록 시작까지 이어짐 | 다음 블록도 병합·unlink | -1 |

header의 +8은 이전 객체 포인터가 아니라 해당 블록을 가리키는 **링크 word의 주소**다.
삽입·header 이동·다음 블록 unlink에 따라 그 주소와 이웃 링크가 수정된다.

hint는 길이를 descriptor+0x10으로 logical shift하고 signed 비교로 hint 수에 맞춘다.
slot은 `hints + hash*0x10 - 0x10`이다. prepend에서 hash가 그대로이면 old header를
가리키던 hint만 new header로 바꾼다. hash가 달라지면 old hint를 필요에 따라 같은 크기
또는 마지막 bucket 기준 이상인 다음 블록으로 옮기고, new bucket의 가장 앞 주소 후보를
갱신한다. append에서는 시작 주소가 같으므로 hash가 같을 때의 새 위치 등록은 없다.
bridge에서는 제거할 다음 블록의 hint를 먼저 처리하고 candidate의 길이/hint를 갱신한다.

중첩이나 잘못된 순서를 모두 검증하는 코드는 아니다. `0x16a9d2/0x16a9d4`의
비인접 경로는 descriptor에 원소를 게시하지 않고도 공통 detach 지점으로 갈 수 있다.
그 경우에도 앞서 용량을 감소시켰고 zone head는 저장한 next로 진행한다. 이를 정상 실행의
메모리 손실로 단정하지 않는다. 실제 producer가 그런 목록·입력을 만들 수 있는지 남아 있다.
반대로 임의의 중첩을 안전하게 거부하는 함수로 설명해서도 안 된다.

## 2. zone_free_space_reclaim — 선택·분할·lock 소비

이 함수는 자체적으로 zget-space lock을 확보하지 않는다. 원본은 descriptor 배열의
index 1부터 signed count 비교로 순회하여 index 0을 건너뛴다. 각 descriptor나 block
포인터의 NULL·범위·형식 검사를 포괄적으로 수행하는 API는 아니다.

block 시작을 A, 길이를 L이라 할 때 우선 L이 현재 page_size 이상이어야 한다.
`lo = round_page(A)`, `hi = trunc_page(A+L)`을 DWORD 연산으로 구하고 다음을 요구한다.

- lo < hi
- zone_min <= lo
- hi <= zone_max

정렬된 중간 구간이 zone 범위를 벗어나면 해당 후보를 건너뛴다. zone 범위와의 교집합으로
줄여서 일부를 회수하는 코드가 아니다. 원래 블록의 비정렬 fringe와 회수 구간의 범위도
구분해야 한다. page_size/page_mask/zone 경계가 일관되고 유지된다는 전제가 필요하다.

회수하기로 하면 원래 block의 hint를 먼저 필요에 따라 다음 후보로 옮긴다. 그 뒤
회수 구간의 앞·뒤에 남는 조각에 따라 다음과 같이 목록을 만든다.

| 앞 조각 | 뒤 조각 | 원본 처리 | entry 수 변화 |
|---|---|---|---:|
| 없음 | 없음 | 원래 블록을 unlink, 다음 블록의 pred 수정 | -1 |
| 있음 | 없음 | 원래 header를 유지하고 길이를 줄임 | 0 |
| 없음 | 있음 | hi에 새 header를 만들고 기존 링크가 이를 가리키게 함 | 0 |
| 있음 | 있음 | 앞 header 뒤에 hi의 새 header를 연결 | +1 |

앞·뒤에 남긴 조각은 길이에 맞춰 hint에 다시 등록한다. 재시도는 현재 predecessor-link
word에서 시작하므로, 남은 조각을 다시 검사한 뒤 진행할 수 있다. 정상 페이지 경계에서는
각 fringe가 한 페이지보다 작다. 잔여 조각이 header를 담기에 충분한 크기인지 별도로
검사하지는 않으므로 기존 정렬·길이 불변식이 필요하다.

Python으로 page_size=8192, zone 범위 [0x400000,0x500000)의 유한 예시를 계산했다.
시작 0x400010, 길이 0x4000이면 [0x402000,0x404000)의 8192바이트가 회수 대상이며,
앞 8176바이트·뒤 16바이트를 남겨 entry 수가 1 늘어난다. 같은 시작에서 길이 0x2000이면
L은 page_size 이상이지만 완전한 페이지가 없어 회수 조건을 통과하지 않는다.
정렬되지 않은 가정 입력에서는 1바이트 suffix도 산술상 생기므로, 이 계산을 임의 입력의
안전성 검증으로 취급하지 않았다. 실제 allocator를 실행하거나 emulation한 것은 아니다.

회수 구간의 lo에는 길이 `hi-lo`를 +4에, 이전 회수 목록 head를 +0에 저장하여 local
목록 앞으로 연결한다(0x16ad3c/0x16ad42/0x16ad44). 별도의 malloc 없이 회수할 영역 자체를
임시 목록 저장소로 사용하는 방식이며, 이 목록은 바깥으로 반환되지 않는다.

모든 descriptor 순회 뒤 `0x16ad70`의 XCHG가 **호출자의 zget-space lock을 0으로 만든다**.
회수 대상이 없어도 이 unlock은 수행된다. 이후 목록의 다음 포인터를 먼저 local로 보존
(0x16ad78/0x16ad7a)하고, 길이를 읽고, `kmem_free(zone_map,span,length)`를 호출한다
(0x16ad89). 해제한 span에서 next를 뒤늦게 읽지 않는다. 목록 앞에 붙인 역순으로 영역을
전달하며, 한 항목은 여러 페이지를 포함할 수 있다.

각 VM 반환 상태를 확인하거나 실패 시 descriptor/hint를 복원하는 분기는 없다.
Ghidra의 `undefined4` 반환은 회수 목록·회수 개수 계약의 근거가 아니다. 원본 EAX에는
free가 없을 때 unlock의 이전 lock 값, free가 있을 때 마지막 하위 CALL 결과가 남을 수
있지만 caller는 이를 검사하지 않는다. 의미 있는 반환 타입·성공 코드로 확정하지 않는다.

## 3. zone_gc와 zone_reclaim의 lock 경계

`zone_gc`는 먼저 all-zones lock을 확보한 뒤 num_zones와 first_zone을 EDI/EBX에
저장하고(0x16b993/0x16b999), all-zones lock을 해제한 뒤 zget-space lock을 확보한다.
Ghidra C에 나타난 lock 이전 count 읽기나 늦은 first_zone 읽기를 그대로 채택하지 않는다.

저장한 count만큼 각 zone을 처리한다. flags bit 0이 켜졌으면 zone+0x30의 write-lock,
꺼졌으면 splhigh 뒤 zone 첫 word의 spin lock을 잡고 +4에 saved spl을 기록한다.
그 상태에서 bit 0이 꺼지고 +0x3c가 0/default가 아닐 때만 `zone_collect`를 호출한다.
즉 pageable로 표시된 zone은 이 경로에서 collect하지 않지만 lock을 거치는 동작은 있다.

nonpageable unlock에서는 saved spl을 **먼저 EAX에 읽고**(0x16ba34), lock 해제
(0x16ba39), splx(0x16ba3c) 순서다. Ghidra C의 해제 후 field 읽기와 원본 순서를 구분한다.
그 뒤 backend lock을 계속 보유한 채 all-zones lock을 재확보하고 next(+0x40)를 읽은 뒤
all-zones lock을 해제한다. snapshot count 기반 순회에는 잘못된 목록 길이에 대한
NULL 복구가 없으며, zone 목록의 생존·추가·제거 계약은 전체 producer 검증이 필요하다.

마지막에 backend lock을 가진 상태로 reclaim을 호출하며, 그 callee가 이를 소비한다.
`zone_gc` epilogue에서 backend를 다시 unlock하지 않는다. `zone_reclaim`은 더 짧게
backend lock을 확보한 뒤 같은 reclaim을 호출한다. zone free 원소를 먼저 collect하는
단계가 없으므로 이미 descriptor free list에 있는 영역만 회수 대상으로 삼는다.

현재 정적으로 확인한 lock 순서가 native deadlock 부재의 증명은 아니다. 모든 zalloc/
zfree/zchange/zone writer, scheduler·인터럽트 진입과 하위 complex lock을 함께 확인해야 한다.

## 4. GC 진입 gate와 반환 표현

`consider_zone_gc`는 max_rate가 0이면 먼저 hz를 복사한다. 이는 allowed 검사보다 앞이다.
allowed가 nonzero이고 `sched_tick > (last_tick + max_rate)의 DWORD 결과`일 때만
last_tick에 관측 tick을 **먼저 기록**하고 zone_gc를 호출한다. 비교는 unsigned이고
경계에서 엄격한 초과다. 원본 파일의 allowed/last/max는 1/0/0, hz는 100이다.

값이 그 조건으로 유지된다면 last=0, rate=100일 때 tick=100은 호출하지 않고 101은
호출한다. wrap 예시는 evidence에 따로 기록했다. 이 코드는 signed 차이를 이용한
wrap-safe 시간 비교가 아니며, tick 생산자를 검증하지 않고 wall-clock 주기로 환산하지
않는다. gate 자체의 lock이나 진행 중 표시도 없다.

`gc_control`은 global을 통해 얻은 argument 포인터를 저장한 뒤 `_suser`를 호출하고,
그 결과가 0이면 본문을 건너뛴다. `_suser` 내부의 권한·오류 계약은 이번에 검증하지 않았다.
nonzero 경로는 gc_lock 아래에서 gc_active를 검사한다. 이미 active이면 unlock하고
대기·큐 등록 없이 끝난다. 아니면 active=1을 게시하고 lock을 풀어 실제 작업을 수행한다.

- mask bit 0x1 검사: 원본에 있는 cache-clear CALL들을 순서대로 수행한다.
- mask bit 0x2 검사: zone_gc를 호출한다.
- mask bit 0x4 검사: zone_reclaim을 호출한다.

이들은 각각의 위치에서 pointer의 byte를 다시 읽는 독립 검사다. 처음의 mask를 한 번
저장한 switch가 아니며, 0x2/0x4는 else-if 관계도 아니다. mask가 유지되고 둘 다 켜져
있으면 full GC 뒤 reclaim-only 호출도 진행한다. 하위 결과에 따른 rollback은 없다.
끝에 gc_lock을 다시 확보하고 active=0을 쓴 뒤 unlock한다.

원본 EAX는 early skip에서 `_suser`의 0, lock 경로에서는 마지막 XCHG의 이전 lock 값일
수 있다. 이를 회수량이나 모든 callee 성공의 요약 상태로 해석하지 않는다. 또 gc_active는
이 진입점의 gate이며, consider_zone_gc나 zone_gc 자체가 같은 flag를 검사하지 않는다.

## 5. kmem_free와 vm_map_remove — 해제 성공은 아직 하위 경계

`kmem_free(map,start,size)`는 start를 page-truncate하고, `start+size+page_mask`를
DWORD로 계산한 뒤 page-truncate한 값을 end로 하여 vm_map_remove를 호출한다.
size=0을 별도로 건너뛰는 검사는 없다. 예를 들어 page_size=8192, start=0x400003,
size=0의 산술 결과도 [0x400000,0x402000)이다. reclaim이 넘기는 정상 span은 양의
page-aligned 구간이므로 이 특수 예가 실제 해당 caller에서 발생한다는 의미는 아니다.

원본 epilogue는 하위 CALL 뒤 EAX를 변경하지 않는다. 따라서 C의 void 표현과 별개로
하위 반환 word가 레지스터에 남는다. caller reclaim은 이를 검사하지 않는다.

`vm_map_remove(map,start,end)`는 write-lock을 잡고 map+0x4c를 먼저 증가시킨다.
start를 map+0x14 이상, end를 map+0x18 이하로 맞춘 뒤, start>end이면 start=end로
만든다. 빈 구간이어도 이 wrapper에서 미리 반환하지 않고 vm_map_delete를 호출한다.
end가 map 하한보다 아래이면 마지막 빈 구간도 그 아래 값으로 만들어질 수 있으므로
“두 끝을 항상 map 안으로 clamp한다”는 표현은 정확하지 않다.

delete 결과를 EBX에 저장하고 map unlock 뒤 EAX로 되돌린다. 그 결과가 실제 페이지,
object reference, pmap mapping을 어떻게 정리했는지는 vm_map_delete 및 하위 callee를
검증해야 한다. reclaim의 zone_min/max와 실제 map 경계가 일치하는지도 필요하다.
bookkeeping이 먼저 바뀌고 반환 상태는 무시되므로 지금 단계에서 leak-free·rollback 완료를
선언하지 않는다.

## 6. 경고 없이도 달라지는 spin과 메모리 순서

register-only spin의 load는 0x16b978, 0x16b9a8, 0x16b9ec, 0x16ba44, 0x16bad4,
0x17c444, 0x17c4ac이다. 각 `75fc` 분기는 load가 아니라 TEST로 돌아가므로 내부 반복이
메모리를 다시 읽는 형태가 아니다. 0x16ba44의 load와 TEST 사이에는 NOP가 있어
단순히 인접한 명령 세 개만 찾으면 누락된다. 이번에는 NOP 및 분기 operand를 추가 대조했다.

Ghidra의 lock store 재배치, count/head 읽기 위치, saved spl 읽기 위치 및 반환 word
해석을 원본으로 구분했다. 선택 범위에 WARNING이 없더라도 이런 검토가 필요하다.
바이트와 지역적 순서가 확인됐을 뿐 실제 CPU 진행성·멀티스레드 안전성은 미완료다.

## 다음 단계

가장 가까운 하위 경계는 vm_map_delete(0x176164)의 실제 객체·페이지·mapping 정리다.
이를 map의 재할당 주소 선택과 연결하기 전에는 74차 add의 낮은 새 주소 경로가 정상
GC/reuse에서 도달하는지 확정하지 않는다. 원본 전체의 나머지 항목은
[후속 분석](OPEN_ITEMS.md)에 유지하며 목표는 미완료로 둔다.
