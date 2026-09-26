# kalloc·zone 할당 정책과 callout allocation 전제

72차의 calloutEntryAllocate가 NULL 검사 없이 반환 포인터를 사용하는 전제를 좁혔다. **초기화·table·zone 설정이 유지되면 32바이트 요청은 nonpageable·non-exhaustible·expandable zone의 blocking 할당 경로다.** 이 조건에서 backing 확보 실패는 해당 공통 본문에서 panic으로 이어진다. 그러나 일반 kalloc/zalloc 전체를 항상 성공하거나 항상 non-NULL인 함수로 선언할 수는 없다.

Ghidra 스킬로 전체 보존 ASM/C/metadata를 읽고 Python으로 원본 Mach-O 매핑·명령어·직접 분기/호출·table·해시·정수식을 검증했다. [증거](allocator-evidence.json), [보존 목록](preservation.json), [남은 분석](OPEN_ITEMS.md)을 분리했다. 직전 체크포인트와 입력을 재검증했고 원본·참고 소스·DB·export·기존 확정 보고서·07_kernel을 보존했다. 신규 독립 계획 교차검토·구현·새 실행 검증 프로그램·동적 실행·GCC 2.7 빌드는 수행하지 않았으며 이전 실패 검토를 재요청·우회하지 않았다.

## 검증 본문

Python 집계는 본문 12개, 명령어 813개, 2277바이트, 직접 분기 130개, 직접 호출 60개, 간접 제어 이전 0개다. 명시적 Ghidra WARNING 9개, register-only busy loop 8곳, 원본 데이터 창 3개를 기록했다. 입력 43개와 이전 보존 파일 750개를 해시 검증했다. backing VM/zone 전체나 native 실행의 완료율이 아니다.

| 함수 | 주소 | 명령어 | 본문 바이트 |
|---|---|---:|---:|
| kalloc_init | 0x15a67c | 40 | 111 |
| kalloc | 0x15a75c | 38 | 108 |
| kget | 0x15a7cc | 29 | 84 |
| kfree | 0x15a824 | 35 | 91 |
| zinit | 0x16a490 | 103 | 323 |
| FUN_0016af6c: free-space selector | 0x16af6c | 39 | 88 |
| FUN_0016b364: canblock 공통 경로 | 0x16b364 | 346 | 1023 |
| zalloc | 0x16b790 | 9 | 18 |
| zalloc_noblock | 0x16b7a4 | 9 | 18 |
| zget | 0x16b7b8 | 55 | 141 |
| zfree | 0x16b84c | 74 | 178 |
| zchange | 0x16b90c | 36 | 94 |

## 크기 table와 선택 규칙

원본 0x1ded18의 DWORD table은 Python으로 다음과 같이 해독했다.

`16, 32, 48, 64, 80, 128, 256, 384, 512, 1024, 2048, 3072, 4096, 8192, 12288, 16384`

크기는 단순한 다음 2의 거듭제곱으로 올리는 규칙이 아니다. kalloc_init은 kalloc_map에 kernel_map을 저장하고 table을 순회하되 class>=page_size가 되는 첫 항목에서 멈춘다. 각 class에 zinit(class,0x100000,page_size,0,name)을 호출하고 k_zone[index]와 k_zone_maxsize를 저장한다. name buffer stride는 0x10이고 원본 sprintf 형식은 별도 데이터 참조다. 초기화 재호출·동시 실행·zinit 반환값의 별도 오류 검사는 이 본문에 없다.

조건부 Python 계산에서 page_size=4096이면 최대 zone class는 3072, page_size=8192이면 4096이다. 실제 boot의 page_size/초기화 순서 검증을 이 예로 대체하지 않는다.

kalloc/kfree는 unsigned 요청 크기가 k_zone_maxsize 이하일 때 table에서 요청 이상인 첫 class를 찾고, 그 class도 max 이하이면 zone을 선택한다. 그렇지 않으면 VM 경로다. 선택 loop에는 별도의 table index 상한 검사가 없으므로 정렬된 table·초기화된 max/zone 배열이 전제다. size=0도 별도 거부 없이 첫 class를 선택할 수 있다.

kalloc의 zone 경로는 zalloc 결과를 그대로 반환한다. VM 경로는 kmem_alloc_wired(kalloc_map,&local,선택 크기)를 호출하고 오류이면 local=0으로 만든다. 첫 max 검사에서 넘어간 요청은 원래 크기를, table 선택 후 max를 넘긴 경우는 선택된 class 크기를 넘긴다. wrapper 자체가 모든 경우를 page 단위로 반올림하거나 memory를 zero-fill하지 않는다.

kfree는 caller가 준 size로 같은 class 결정을 다시 하고 zfree(zone,pointer) 또는 kmem_free(map,pointer,선택 크기)를 호출한다. 객체 header에서 원래 할당 크기를 복구하거나 pointer/size의 일치를 검증하지 않는다. NULL·double-free·잘못된 allocator 출처를 일반적으로 무해하게 처리하는 wrapper가 아니다.

## Zone 초기화와 free-space 선택

zinit은 zone_zone이 있으면 zalloc(zone_zone), 없으면 zget_space(default_space,0x44,0)으로 zone 구조를 얻고 NULL이면 panic한다. 원본 bootstrap 요청은 68바이트라는 type 추정 대신 증거에 0x44와 Python 계산값을 보존했다. 할당 단위 인자가 0이면 page_size, element size가 0이면 먼저 4로 바꾼다. 그 뒤 `(size+15) & 0xfffffff0`으로 DWORD 정렬한다. 큰 값의 wrap을 거부하는 분기는 없다. 예를 들어 0xfffffff1은 Python 계산상 0으로 wrap되므로 임의 크기까지 안전한 초기화라고 주장하지 않는다.

max와 alloc size는 전역 page_mask로 반올림하고 max가 alloc보다 작으면 alloc으로 올린다. free_head·last_insert·cur_size·count·doing_alloc은 0으로 설정한다. flags low nibble은 pageable 인자의 low bit를 유지하고 sleepable/exhaustible을 끄며 expandable을 켠다. 높은 bits까지 모두 0으로 덮는 코드는 아니다. Python 계산으로 pageable=0이면 low nibble 8, pageable=1이면 9다.

nonpageable은 zone+0 spinlock을 0으로 초기화하고 pageable은 zone+0x30에 lock_init(...,1)을 호출한다. free-space selector 이후 next_zone=0으로 만들고 all_zones_lock 아래 전체 zone list에 붙여 num_zones를 증가시킨다. saved_spl 같은 모든 바이트를 일괄 초기화하는 함수는 아니다.

FUN_0016af6c는 cur_size가 0일 때 descriptor 배열의 index 1부터 검사한다. 각 descriptor의 첫 DWORD를 alignment, 다음 DWORD를 상한으로 사용하여 `((elem_size-1+alignment) mod 2^32) & (-alignment mod 2^32)`를 구하고 상한 이하인 첫 descriptor를 선택한다. 성공하면 elem_size와 zone+0x3c free_space를 저장한다. 아무 descriptor도 맞지 않으면 +0x3c에 default를 새로 저장하지 않고 반환한다. 실제 descriptor 초기화·유효한 alignment·fallback 생존 조건은 후속 backing/boot 검증 대상이다.

## zalloc, zalloc_noblock, zget은 같은 함수가 아니다

zalloc은 공통 helper(zone,1), zalloc_noblock은 helper(zone,0)를 호출하며 둘 다 EAX의 결과를 그대로 반환한다. Ghidra의 void wrapper 표기를 포인터 반환 ABI로 채택하지 않는다.

| 진입 | free list가 비었을 때 |
|---|---|
| zget / kget의 zone 경로 | 기존 free_head만 확인하고 없으면 0; backing 확장 없음 |
| zalloc_noblock | helper의 canblock=0 분기 적용; 조건에 따라 backing 확보를 시도함 |
| zalloc | helper의 canblock=1 분기 적용; doing_alloc 대기나 실패 panic 가능 |

kget은 zone 크기 범위 밖이면 panic하며 wired VM fallback을 하지 않는다. zget도 zone NULL이면 panic한다. `noblock`이라는 이름만으로 모든 lock/VM callee까지 절대 sleep하지 않는다고 보장하지 않는다. pageable zone의 complex lock 획득과 신규 pageable VM 확보는 이 공통 본문에서 별도의 canblock=0 우회로 막지 않는다.

## 공통 helper의 lock·빠른 할당·대기

helper는 zone NULL이면 panic한다. pageable bit가 켜져 있으면 complex lock을 얻고, 그렇지 않으면 splhigh 후 zone spinlock을 얻어 saved_spl을 zone+4에 기록한다.

free_head가 있으면 count 증가, head=*entry로 교체, last_insert가 그 entry이면 0으로 만들고 unlock 후 반환한다. 반환 entry의 첫 DWORD나 나머지 저장소를 새로 0으로 만들지 않는다. 원본 freelist 내용이 남을 수 있으므로 새 객체 필드 초기화는 caller 책임이다.

free_head가 없고 doing_alloc이 비영이면 canblock=0은 unlock 후 0이다. canblock!=0은 assert_wait(&doing_alloc,1) → unlock → block(NULL) → relock 순서다. 이 wake 경로는 저장된 local 반환 포인터가 여전히 0인지 검사하고 doing_alloc 검사로 돌아간다. **잠에서 깼다는 이유만으로 즉시 free_head를 다시 pop하는 명령은 이 분기 사이에 없다.** 다른 thread가 만든 free list가 있어도 subsequent allocation 분기로 진행할 수 있는 정적 형태다. 실제 경합의 발생·낭비·안전성까지 실행한 결과는 아니다.

## 용량 초과와 실패 정책

free list가 비고 doing_alloc이 0이면 `cur_size + (pageable ? alloc_size : elem_size)`를 DWORD로 더해 unsigned max_size와 비교한다. 덧셈 overflow를 별도 검사하지 않는다.

- 초과하며 exhaustible bit가 켜져 있으면 canblock 값과 무관하게 현재 0인 local 포인터를 unlock 후 반환한다.
- expandable이면 `max_size += max_size >> 1`을 한 번 수행하고 계속 확보한다. 이번 요청이 새 max에 들어오는지 다시 검사하는 loop가 아니다. 기본 0x100000의 한 번 증가 결과는 Python으로 1572864다.
- expandable이 아니고 zone_ignore_overflow가 0이면 unlock 후 canblock=0은 0, canblock!=0은 printf와 panic이다.
- ignore_overflow가 비영이면 초과해도 진행한다. 원본 파일의 초기 값은 1이며 runtime 불변성은 이번에 전수 증명하지 않았다.

nonpageable은 zone lock을 풀고 zget_space(zone->free_space,elem_size,canblock)를 호출한다. 결과 0이면 canblock=0은 0, canblock!=0은 panic한다. 비NULL이면 다시 zone lock을 얻어 count와 cur_size를 늘린 뒤 반환한다. 하위 zget_space가 언제 성공·대기·실패하는지는 이번 직접 caller 분석과 별개다.

pageable은 doing_alloc=1을 쓴 뒤 unlock하고 kmem_alloc_pageable(zone_map,&local,alloc_size)를 호출한다. 오류나 주소 0이면 panic한다. 확보 영역을 elem_size 단위로 free list에 넣어 cur_size를 증가시키는 zcram 형태가 inline되어 있다. 이때 count를 읽고 같은 값으로 다시 쓰는 raw store도 존재한다. 새 영역 끝의 나머지를 별도 element로 반환하지 않는다.

그 후 unlock/relock을 거쳐 doing_alloc=0을 기록하고 **zone lock을 유지한 채** thread_wakeup_prim(&doing_alloc,0,0)을 호출한다. 이어 free_head를 pop하고 count를 증가시켜 반환한다. 고수준 C의 불필요해 보이는 lock 왕복이나 count self-store를 원본 명령어 누락으로 처리하지 않았다. 실제 pageable lock·wakeup·VM 계약은 후속 범위다.

## calloutEntryAllocate에 적용되는 조건부 결론

[72차](../continuous-review-20260913-72/README.md)의 요청은 0x20이다. 원본 table을 유지하고 kalloc_init이 해당 class를 생성했다면 Python으로 선택되는 index는 1, zone pointer slot은 0x1f6364다. zinit 인자가 pageable=0이고 기본 flags가 유지되면 nonpageable·non-exhaustible·expandable이다.

이 조건의 canblock=1 경로에서는 freelist에서 가져오거나 backing을 확보하여 반환하고, backing이 0이면 panic한다. 일반적인 exhaustible NULL 반환 분기를 해당 기본 zone에 무조건 적용해서도 안 된다. 따라서 callout caller의 NULL 검사 부재를 원본 allocator 정책과 연결할 수 있다.

하지만 이것은 모든 실제 호출이 성공함을 증명한 것이 아니다. zone 초기화/descriptor 선택의 성공, runtime zone pointer/flags/크기 변경, backing 정책, panic 비복귀와 native lock 진행성은 별도 전제다. kalloc의 VM 실패 반환과 임의 zone의 exhaustible NULL 가능성을 없애는 전역적인 non-NULL 선언도 하지 않는다.

## zfree: 크기 검증이 아니라 정렬된 freelist 삽입

zfree는 선택한 zone의 lock을 얻고 zone_check 전역이 비영일 때만 free list를 순회하여 동일 pointer가 이미 있는지 검사한다. 원본 파일 초기 zone_check는 0이다. 켜져 있어도 element alignment·zone 소속·원래 할당 크기·다른 zone의 free 상태를 전부 검사하는 장치는 아니다.

last_insert가 있고 반환 pointer가 unsigned 더 크면 그 hint에서, 아니면 free_head의 주소에서 탐색을 시작한다. 주소순 삽입 위치를 찾아 `*element=successor`, `*link=element`, last_insert=element를 쓰고 count를 감소시킨다. object pointer가 NULL인지 검사하지 않으며 count underflow를 막는 분기도 없다. cur_size/max_size를 감소시키거나 즉시 backing page를 반환하지 않는다. 실제 page 회수는 별도 경로다.

nonpageable unlock은 0x16b8ec에서 saved_spl을 **먼저 register로 읽고**, 0x16b8f1에서 spinlock을 푼 뒤 그 값으로 splx한다. Ghidra C의 unlock 뒤 zone+4를 읽는 표현은 raw 순서와 다르다. 다른 thread가 같은 saved_spl field를 다시 쓸 수 있는 조건의 분석에서 이 순서를 보존해야 한다.

## zchange와 runtime 설정 전제

zchange는 pageable/sleepable/exhaustible 인자의 각각 low bit를 flags의 low bits에 반영하고 expandable 등 나머지 bits는 유지한다. collectable 인자가 0이면 free_space를 default 공간으로 바꾼다. 비영이라고 원래 descriptor를 재선택하는 분기는 없다.

마지막으로 pageable이면 complex lock을 초기화하고 아니면 spinlock을 0으로 만든다. 현재 zone lock을 획득하거나 사용 중 여부를 확인하는 함수가 아니므로 임의 concurrent runtime 변경이 안전한 API로 해석하지 않는다. 기본 flags가 유지된다는 callout 결론에는 이와 다른 writer의 호출 시점·소유권 검토가 필요하다.

## 참고 소스와 미완료 경계

Darwin kalloc.c의 실제 table와 zalloc.c/h의 선택·flags·canblock 구조는 이번 원본과 대응된다. 그러나 kalloc.c 상단의 거듭제곱 반올림 설명만 따라 실제 table를 생략해서는 안 되며, DIAGNOSTIC/ZALLOC0 같은 참고 소스 조건부 zero-fill을 이 원본에 추가된 사실로 취급하지 않는다. 원본 helper의 모든 하위 callee 또는 GCC 2.7 구조체/bitfield ABI가 참고 선언만으로 검증된 것도 아니다.

명시적 WARNING은 panic 비복귀 표기 9개다. register-only busy loop 8곳은 각 JNZ 75fc가 memory load가 아닌 register TEST로 되돌아감을 확인했다. 이 추가 본문 검토는 과거 PD 경로의 제한된 검증을 전체 allocator/native 실행 완료로 확대하지 않는다. backing·VM·lock·scheduler 전수 의미와 실제 GCC 2.7 빌드/boot는 계속 남는다.
