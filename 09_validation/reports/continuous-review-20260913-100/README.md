# 100차 — Zone 할당·초기화와 최초/재사용 메모리의 구분

## 결과

99차에서 남긴 allocator 전제를 원본 zone 본체·초기화·backing-space 공급 및
부팅 호출 경로와 연결했다. 최초 zone 공급 메모리에 명시적인 zero-fill 호출이 있으나,
free-list에서 재사용하는 항목에는 다시 zero-fill하지 않는다는 차이를 확인했다.
page-size 설정과 kalloc class 초기화도 확인하여 첫 NULL free 경로의 조건을 좁혔다.
이는 지역 원본 분석의 진전이며 실제 오류·안전성·전체 kernel 완료를 주장하지 않는다.

원본 SHA-256: `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`.
Ghidra 스킬의 본문/호출/제어 흐름 대조를 기존 export와 원본 bytes에 적용했다.
외부 코드는 참고하지 않았으며 계산·해시·재디코드는 Python이다.
새 독립 계획 교차검토는 받지 않았고 검토 통과로 표시하지 않는다.
원본·DB·export·기존 완료 보고서는 변경하지 않는다.

Python 집계: 일반 본문 25개와 fragment 9개, 총 34개 본문의 2,213개 명령/6,719바이트.
직접 분기 275개, 직접 CALL 155개, 간접 JMP 3개, 핵심 명령 202개,
register-only spin 패턴 11개, memset static footprint 경로 46개를 확인했다.
입력 108개와 기존 보존 경로 894개를 검사했다.
C 경고 33행은 fragment의 겹친 문맥도 포함하며 독립 원본 결함 수가 아니다.

자료: [범위·계획](SCOPE.md), [원본·산식 증거](object-lifetime-evidence.json),
[C 표현 차이](DECOMPILER_ISSUES.md), [보존 해시](preservation.json),
[체크포인트](checkpoint.json), [미완료 항목](OPEN_ITEMS.md),
[99차 결과](../continuous-review-20260913-99/README.md).

## 1. Page size와 초기화 호출 경로

start 0x1860dc에는 CLD와 segment 설정/far JMP를 거쳐 i386_init을 호출하고,
다시 segment를 설정한 뒤 startup_early와 setup_main을 호출하는 원본 경로가 있다.
setup_main은 vm_mem_init 0x173a68을 호출한다.
이 호출 연결을 확인했지만 모든 선행 callee·loader·descriptor·native 부팅 성공을 증명하지 않는다.

i386_init의 **0x18ab2b는 page_size에 0x2000을 쓴다**.
이어 0x18ab35에서 vm_set_page_size를 호출한다.
이 값이 유지되고 해당 경로가 정상 복귀하면 Python 산식으로 page size=8192,
page mask=8191, page shift=13이다. 파일의 page_size initializer는 0이므로
그 파일 값 자체를 runtime page size로 해석하면 안 된다.
page_mask 및 여러 zone 전역은 Mach-O common/zerofill 영역이며 file-backed 값으로 읽지 않는다.

vm_mem_init의 관련 순서는 다음과 같다.

1. vm_page_startup → zone_bootstrap.
2. vm_object_init → vm_map_init → kmem_init → pmap_init.
3. zone_init → kalloc_init → 이후 VM 초기화.

VM subsystem이 모두 완료 분석되었다는 뜻은 아니다. 이번에는 zone 공급/초기화의
지역 호출 순서와 해당 함수의 원본 명령을 확인했다.

기존 full-pass5 ASM 5,253개를 manifest와 대조하여 지정 global displacement write와
초기화 직접 CALL을 조사했고 17개 hit 모두를 선택 본문에서 재디코드했다.
그 범위에서 page_size literal write는 0x18ab2b다. alias, bulk, 함수 밖 명령과
runtime 변경 가능성까지 제거한 writer closure는 아니다.

## 2. 최초 zone 공급 pool에는 zero-fill 호출이 있다

vm_page_startup은 0x17abf5에서 zdata_size를 page_size*8로 바꾸고,
vm_alloc_from_regions(size,page_size)의 EAX를 0x17ac02에서 zdata pointer로 저장한다.
0x17ac0f에서 bzero(pointer,size)를 호출한다.
위 page-size 전제 아래 요청 크기는 Python 계산으로 65,536바이트다.
파일의 zdata_size initializer 430,080과 이 runtime 초기화 값을 구분한다.

bzero 0x101600은 memset(destination,0,length)를 호출한다.
memset의 원본 table/MOV 목적지 구간과 길이 0..65536, destination alignment의 산식
524,296개를 확인했다. 이는 정상적인 유효 buffer에서의 정적 fill 범위 근거이지
해당 memory mapping의 실제 성공·fault 부재를 관찰한 결과가 아니다.

vm_alloc_from_regions 0x178964는 region cursor를 alignment로 올림한 시작 주소를 EAX,
size를 더한 끝을 EDX에 둔다. end가 region upper bound 이하면 cursor=end로 게시하고
**EAX=시작 주소를 유지해 반환**한다. C의 void 반환은 이 연결을 누락한다.
이 본문에는 alignment의 nonzero/power-of-two 검사나 DWORD 덧셈 carry 검사 자체가 없다.
선택 초기화 인자는 확인했지만 모든 caller 입력·region 수명·실제 memory는 미완료다.

초기 pool의 zero-fill 호출은 zone metadata가 처음 공급되는 경로의 중요한 전제다.
그러나 이후 extent header 쓰기·사용자 쓰기·free-list 재사용을 거친 객체가 계속 0이라는
보장은 아니다. 이를 99차 TSS 추가 바이트의 값 확정으로 확대하지 않는다.

## 3. Kalloc size class와 NULL free의 조건

kalloc_init 0x15a67c는 원본 table 0x1ded18을 순서대로 읽는다.
page_size<=class이면 중단하므로 생성 대상은 **page size보다 엄격히 작은 class**다.
각 class는 zinit(class,0x100000,page_size,0,name)으로 만들고 zone pointer 및 maxsize를 게시한다.
이 함수에는 zinit 반환 NULL에 대한 별도 gate가 없다. zinit의 자체 실패는 panic 경로다.

원본 table과 위 page-size 전제에 따른 선택은 다음과 같다.

| 초기화되는 class | 그 뒤 table에 남는 class |
|---|---|
| 16, 32, 48, 64, 80, 128, 256, 384, 512, 1024, 2048, 3072, 4096 | 8192, 12288, 16384 |

따라서 조건부 active class는 13개, maxsize는 4096이다.
kalloc/kfree는 요청 이하/이상의 unsigned 비교로 첫 충분한 class를 고르고,
maxsize를 넘으면 wired allocation/free 경로로 간다.

| 요청 바이트 | 선택 경로·class |
|---|---|
| 0, 1, 16 | zone 16 |
| 28 | zone 32 |
| 68 | zone 80 |
| 104, 105 | zone 128 |
| 244 | zone 256 |
| 4096 | zone 4096 |
| 4097, 8192 | wired, 위 page-size 전제의 요청 round는 8192 |
| 8297 | wired, 위 page-size 전제의 요청 round는 16384 |

99차 bitmap N에 대한 TSS 요청은 N+105다. 위 allocator 설정이 유지되면
N<=3991은 zone 요청 범위이고 N=3992부터 wired 범위다.
이는 TSS 요청의 분류이며 표의 일반 요청 바이트와 혼동하지 않는다.

99차 K 초기 pointer/size=0에서 첫 bitmap 확장은 kfree(0,0)를 호출한다.
이번 초기화는 첫 zone=16, maxsize>=16이라는 조건의 원본 근거를 추가한다.
zfree의 0x16b8d0은 element 인자를 목적지로 하는 DWORD store이고 자체 NULL gate가 없다.
하지만 실제 그 첫 확장의 도달, zone/list/lock 상태, 주소 0 mapping과 이후 실행은
확인하지 않았으므로 native crash/정보 노출/안전성을 단정하지 않는다.

## 4. zinit은 모든 metadata 바이트를 지우지 않는다

Z=zone metadata로 표기한다. zinit은 zone_zone이 없으면 기본 backing space에서
0x44바이트를 요청하고, 있으면 zone_zone의 zalloc을 호출한다. NULL은 panic 경로다.
element=0이면 먼저 4로 바꾸고 DWORD에서 (element+15)&~15로 정렬한다.
max/chunk는 page mask로 올림하고 max가 chunk보다 작으면 chunk로 높인다.

| Z offset | 선택 초기화/소비 의미 |
|---|---|
| +0 / +4 | spin 관련 storage / 저장 IPL; 모드에 따라 +0x30 lock 사용 |
| +8 | 사용 중 항목 count, 초기 0 |
| +0xc / +0x10 | 삽입 hint / free-list head, 초기 0 |
| +0x14 | 공급된 바이트 accounting, 초기 0 |
| +0x18 | max bytes |
| +0x1c | 정렬된 element 크기; backing-space 선택이 다시 조정 가능 |
| +0x20 | chunk allocation 크기 |
| +0x24 | pageable refill 관련 busy 값, 초기 0 |
| +0x28 | name pointer |
| +0x2c BYTE | flag 갱신, 전체 BYTE zero가 아님 |
| +0x3c | backing-space selector가 조건부로 쓰는 pointer |
| +0x40 | 전체 zone 목록 next, 초기 0 |

flags는 Python에서 이전 BYTE 전 범위와 mode 0/1을 대조한 결과
**(old&0xf0)|8|(mode&1)**이다. high nibble을 보존하며 mask 2/4는 지우고 mask 8을 세운다.
이 본문에는 metadata 전체 bzero와 +0x3c의 무조건 초기화가 없다.

FUN_0x16af6c는 Z+0x14=0이고 backing-space 후보가 있을 때만 검색한다.
후보 alignment a에 대해 (element-1+a)&(-a)를 계산하여 그 후보 maximum 이하이면
element와 Z+0x3c를 갱신한다. 후보가 없거나 모두 실패하면 +0x3c를 쓰지 않는다.
이 값이 잘못되었다고 단정하려면 실제 초기 공급·재사용·writer를 더 확인해야 한다.

zone_bootstrap의 첫 zone은 추가 backing space를 생성하기 전에 만들어진다.
요청 metadata 68바이트는 element 80바이트로 정렬된다.
이후 생성하는 backing-space 설정은 다음과 같다.

| alignment | maximum | shift | hint count | hint bytes |
|---|---|---|---|---|
| 16 | 96 | 4 | 6 | 96 |
| 128 | 768 | 7 | 6 | 96 |
| 1024 | 8192 조건부 | 10 | 8 조건부 | 128 조건부 |

hint storage에는 bzero 호출이 있다. 각 작은 metadata allocation에 자체 NULL gate가
모두 있는 것은 아니므로 하위 성공 전제와 구분한다.
형식적인 DWORD 정렬 산식은 상단 값에서 wrap할 수 있다. 예를 들어 0xfffffff1은
16바이트 올림 결과가 0이다. 실제 zinit caller가 그 입력을 전달한다는 주장은 아니다.

## 5. zalloc 본체의 반환·대기·재사용

0x16b364의 첫 인자는 Z, 두 번째 인자는 wrapper가 선택하는 wait 값이다.
zalloc은 1, zalloc_noblock은 0을 전달하고 둘 다 callee EAX를 보존해 반환한다.

free-list head가 있으면 Z+8 증가, head의 첫 DWORD를 새 head로 게시,
필요 시 insertion hint를 0으로 바꾼 뒤 기존 head를 반환한다.
**반환 항목의 첫 DWORD를 포함해 payload를 지우는 store가 없다**.
Z+0x10에서 떼어낸 항목의 이전 next 값은 자체 경로에서 그대로 남는다.
zget 0x16b7b8도 이 head-pop만 수행하며 비어 있으면 NULL, refill 호출은 하지 않는다.

빈 경우의 지역 분기는 다음과 같이 구분된다.

- Z+0x24 busy nonzero: wait=0은 unlock 후 0. wait!=0은 assert_wait, unlock,
  thread_block_with_continuation(0), relock 경로를 탄다.
- 공급량+요청이 max를 넘고 flag mask 4가 있으면 local pointer 0을 반환하는 경로다.
  따라서 wait=1이라는 이유만으로 항상 non-NULL이라고 할 수 없다.
- over-limit에서 mask 8이면 max에 max>>1을 DWORD로 더한다.
  그 flag가 없고 zone_ignore_overflow가 0이면 wait=0은 0, wait!=0은 printf/panic 경로다.
  파일의 zone_ignore_overflow 값은 1이지만 모든 runtime writer 부재는 미확인이다.
- pageable 모드에서는 busy를 세우고 lock을 풀어 kmem_alloc_pageable을 호출한다.
  실패 또는 zero address는 각각 panic 경로다. 공간을 element별 free-list로 넣은 뒤
  busy를 지우고 깨우며 head를 다시 읽어 pop한다. payload 전체 zero-fill은 하지 않는다.
- nonpageable 모드에서는 zget_space(Z+0x3c,element,wait)를 호출한다.
  반환 0이면 wait=0은 NULL 반환, wait!=0은 panic 경로다.
  성공이면 다시 lock을 얻어 count와 공급량을 증가시킨 뒤 pointer를 반환한다.

일부 busy-wait 복귀 edge는 local pointer만 검사하며 그 edge에서 free-list head를 새로
읽지 않는다. 별도의 pageable refill 성공 경로에는 head reload가 있다.
이를 일반적인 retry-pop 알고리즘으로 바꾸어 해석하지 않는다.
wait=0도 일부 공급 경로를 수행하고 pageable allocation call 자체는 남으므로
이름 noblock만으로 하위 callee까지 절대 sleep하지 않는다고 판단하지 않는다.

## 6. Backing space의 기존 extent·초기 pool·새 VM 공급

zget_space 0x16ada4는 NULL space를 기본 space로 바꾸고 요청을 최소 16/16바이트 정렬한다.
global space lock 아래 FUN_0x16a360으로 extent를 찾는다.
선택 extent의 잔여가 16 미만이면 list에서 제거하고, 그 밖에는 extent+request에
새 header를 만들며 next/previous-link/hint를 갱신한다. 반환 영역을 지우지는 않는다.

extent가 없으면 page-rounded 요청을 계산한다. 초기 zdata 잔여가 충분하면 잔여를 줄이고
pool의 그 위치를 zone_free_space_add에 넘긴다.
부족하면 lock을 풀고 kmem_alloc_zone(map,&new,size,wait)를 호출한다.
실패는 0 반환, 성공은 relock 후 기존 extent 검색을 다시 수행한다.
다른 extent가 선택되면 새 mapping을 나중에 kmem_free하고,
여전히 부족하면 새 mapping을 extent 공급에 사용해 local 소유 표시를 지운다.

FUN_0x16a360과 zone_free_space_add 0x16a694의 원본은 extent header와 hint를 갱신한다.
추가 공간이 이전 extent 끝과 정확히 붙는 경로에서는 반환 base가 이전 extent base로 바뀔 수 있다.
일부 범위/잔여 분기는 바로 인자 base를 반환한다. 전체 sorted-list/크기/정렬 불변식,
겹치는 입력과 wrap, 모든 free/coalescing/GC caller의 의미까지 완료했다고 하지 않는다.

kmem_alloc_zone 0x174170은 map-find 실패를 EAX=1로 정규화하고,
backing helper 0x173ebc 실패는 map 삭제 후 EAX=6을 반환한다.
success 때 vm_map_pageable을 호출하고 output pointer를 쓴 뒤 EAX=0이다.
wait 인자는 backing helper로 전달된다. output은 성공 때만 쓰며,
vm_map_pageable의 결과를 검사하는 자체 분기는 없다.
하위 page/object/wire/참조/zero-fill 계약은 후속 항목이다.

## 결론의 경계

99차 TSS의 추가 요청 바이트에 대해 이번에 확인한 것은 **초기 공급과 재사용 경로의 차이**다.
실제 TSS allocation이 어느 경로에서 어떤 값을 받았는지, 다른 writer가 값을 바꾸는지,
그 바이트를 CPU가 어떤 상태에서 소비하는지는 아직 확인하지 않았다.
원본 정적 분석을 계속하되 외부 코드 참조나 구현으로 범위를 확장하지 않는다.
