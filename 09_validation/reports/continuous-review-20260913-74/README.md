# 74차 — OPENSTEP 원본 zone backing·초기화 분석

## 범위와 판정

원본의 free-space 조회·분할·영역 확보, bootstrap descriptor 생성, 직접 하위 VM 페이지
확보 경로를 연결했다. 선택한 함수 본문의 정적 검토이며 allocator 전체, 실제 부팅,
동시 실행 또는 모든 caller의 입력 조건을 검증한 결과는 아니다.

사용자 정정에 따라 다른 프로젝트의 코드를 근거에서 제외한다. 중단 전 외부 소스를
열었던 이력은 있으나, 아래 결론은 원본 바이트·원본 심볼·해당 바이너리의 보존 export로
다시 확인했다. 외부 코드의 함수 이름·구조체 선언·오류 상수 의미를 가져오지 않는다.
`FUN_0016a360`과 `FUN_00173ebc`에는 이번 원본 nlist 검사에서 이름이 없으므로 각각
“free-block 조회 helper”, “페이지 확보 helper”라는 분석용 설명만 사용한다.

Ghidra 스킬의 함수 본문·역어셈블·디컴파일 대조 절차를 보존 출력에 적용했다.
원본·DB·기존 export·복원 소스는 수정하지 않았고, 구현·빌드·포팅·동적 실행은 하지 않았다.

근거: [범위](SCOPE.md), [원본 바이트 및 산술 근거](zone-backing-evidence.json),
[보존 해시](preservation.json), [후속 분석](OPEN_ITEMS.md).

## 원본 바이트 검증

대상 `03_original/x86/binaries/mach_kernel`의 SHA-256:
`33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`.
Python으로 Mach-O load command/segment/section/nlist를 읽고, file-backed 주소를 매핑하여
Capstone 4.0.2의 x86 32-bit 디코더로 각 명령을 재디코딩했다. 커널을 실행하지 않았다.

| 원본 entry | 심볼 또는 분석용 가칭 | 본문 바이트 | 명령 |
|---|---|---:|---:|
| 0x16ada4 | `_zget_space` | 450 | 160 |
| 0x16a360 | free-block 조회 helper | 292 | 134 |
| 0x16a694 | `_zone_free_space_add` | 347 | 145 |
| 0x16afc8 | `_zone_bootstrap` | 871 | 236 |
| 0x16b338 | `_zone_init` | 43 | 14 |
| 0x174170 | `_kmem_alloc_zone` | 299 | 115 |
| 0x173ebc | 페이지 확보 helper | 248 | 90 |

합계 7개 본문, 894개 명령, 2550바이트다. 보존 metadata의 inclusive body range와
명령 바이트의 합집합이 일치하며, 본문 사이의 gap을 임의로 명령으로 채우지 않았다.
직접 분기 110개와 직접 CALL 35개의 목적지를 대조했다. 직접 분기 목적지는 모두 해당
본문의 명령 시작점이다. 선택 범위의 간접 transfer는 0개다. 하위 함수의 완전 검증을
뜻하지 않으며, 전체 바이너리 coverage의 수치도 아니다.

Ghidra 경고는 2개로, `zget_space`의 겹치는 global 심볼과 `zone_bootstrap`의 non-return
호출 표현이다. 경고가 없는 함수도 원본 대조를 생략하지 않았다.
입력 27개를 기록했다. 이전 범위 중 735개 파일을 재해시하고 직전 보고서 입력 40개를
재확인했다. 범위 밖 보존 경로 21개와 직전 입력의 외부 소스 3개는 다시 열지 않았다.
제외 경로와 이전 해시는 evidence에 명시했으며, 이전 전체 보존 집합을 재검증했다고
주장하지 않는다. 수정한 작업 지침은 이번 입력의 현재 해시로 별도 기록했다.

## 1. free-space 자료 배치와 조회

다음은 명령의 load/store에서 확인한 배치다. C 구조체 선언을 복원한 것은 아니다.

| 대상 | offset | 원본에서 관찰한 용도 |
|---|---|---|
| free block | +0 / +4 / +8 | 다음 블록 / 길이 / 이 블록을 가리키는 링크 word의 주소 |
| descriptor | +0 / +4 | bootstrap이 넣는 정렬 단위 / 큰 크기 bucket의 기준 |
| descriptor | +8 / +0xc | free-list head / entry count |
| descriptor | +0x10 / +0x14 / +0x18 | 크기 우측 shift 값 / hint 배열 / hint 수 |
| hint | stride 0x10, +0 | 해당 크기에서 먼저 사용할 블록 주소 |

특히 block+8은 이전 블록의 식별 포인터가 아니라 **수정해야 하는 링크 word의 주소**다.
첫 블록이면 descriptor+8을 가리킬 수 있다. free block의 시작 주소 자체가 반환되므로
항상 별도 header를 건너뛰는 allocator로 해석하면 안 된다.

`FUN_0016a360(space, size)`는 자체 lock이 없고 목록에서 블록을 unlink하지도 않는다.
그러나 hint를 변경하므로 읽기 전용 검색 함수는 아니다.

- head가 0이면 0을 반환한다. head 길이가 충분하면 바로 head를 고르고 해당 hint만
  필요에 따라 갱신한다. 최소 크기의 블록을 전수 검색하는 best-fit 동작이 아니다.
- head가 작으면 `size >> (shift의 하위 5비트)`를 구하고 signed 비교로 hint 수에
  상한을 맞춘다. slot 주소는 `hints + hash * 0x10 - 0x10`이다.
- 마지막 전 bucket에서 nonzero hint를 만나면 그 블록을 선택하고, 이후 같은 길이의
  블록을 찾아 hint를 옮긴다. 이 분기에는 선택 블록 길이와 요청 크기의 직접 비교가 없다.
  크기 정렬과 hint의 유효성이 caller·producer 계약에 포함되어야 한다.
- 마지막 bucket의 hint가 너무 작으면 다음 블록 중 요청을 충족하는 것을 찾되 기존
  hint는 그대로 둔다(`0x16a44f` 이후). hint 자체를 사용하는 경우에만 다음
  `descriptor+4` 이상 블록으로 갱신한다(`0x16a468` 이후).

크기·hash의 정상 범위, 정렬·길이·link/hint 일관성을 전체 writer에 대해 증명하지 않았다.
원본의 logical shift와 signed 상한 비교를 임의의 unsigned min 연산으로 바꾸면 안 된다.

## 2. zget_space의 확보·반환·소유권

ABI는 `(space, size, canblock)`이고 space가 0이면 원본 심볼
`__zone_default_space`(0x1f6db0)를 사용한다. 요청이 unsigned 0x10 이하이면 0x10,
그 외에는 DWORD 덧셈 후 하위 정렬 비트를 지운다. 예를 들어 0→0x10,
0x1c→0x20, 0x44→0x50이며 0xfffffff1→0으로 wrap된다. 모두 Python 계산이며
그런 큰 값이 정상 caller에서 도달한다는 증명은 아니다. 별도 overflow 검사는 없다.

`_zget_space_lock`(0x1f6df4)을 확보하고 조회 helper를 호출한다(0x16ae29).
블록 길이에서 요청을 뺀 DWORD 결과가 0xf 이하이면 전체 블록을 unlink하고 count를
감소시킨다(0x16ae55). 그보다 크면 요청 뒤에 나머지 header를 만들고 이웃 링크와
hint를 갱신하며 count는 유지한다. 반환 대상은 기존 블록 시작 주소다.
반환 영역의 첫 word를 지우거나 전체를 zero-fill하는 코드는 이 함수에 없다.

조회 실패 이후의 소유권 분기는 다음과 같다.

| 상태 | 다음 원본 동작 | 반환 및 임시 영역 처리 |
|---|---|---|
| 예약 `zdata_size`가 page-round 크기 이상 | lock 상태에서 예약 잔량을 줄이고 `zdata + 잔량`을 add에 전달 | 예약 영역의 위쪽부터 소비; add 결과 반환 |
| 예약 부족, 아직 새 VM 영역 없음 | lock 해제 → `kmem_alloc_zone` | 오류면 0 반환; 성공이면 lock 재확보 후 조회부터 재시도 |
| 재조회에서 기존 블록 발견 | 기존 블록을 분할 또는 unlink | lock 해제 후 사용하지 않은 새 VM 영역을 `kmem_free`에 전달 |
| 재조회도 실패, 새 VM 영역 있음 | `zone_free_space_add` 호출 | 임시 영역 포인터를 0으로 지워 소비 처리한 뒤 lock 해제·반환 |

원본의 핵심 순서는 `0x16aedb` unlock → `0x16aef4` VM CALL → 성공 시
`0x16af12` 재확보 → `0x16af1f`에서 조회 지점으로 복귀다. 새 영역의 무조건 삽입이 아니다.
소비 표시인 local 포인터 0 store는 add 뒤의 `0x16af35`이며,
미사용 영역의 free CALL(0x16af5a)은 unlock(0x16af41) 뒤다.

하위 VM 오류는 `0x16aefe`에서 0 반환 경로로 분기한다. 이 함수의 직접 CALL 목록에
panic은 없고, 오류 시 lock을 다시 확보하지 않는다. add의 반환값을 따로 검사하지도
않는다. `canblock`은 하위 VM으로 그대로 전달되지만, 자체 spin이나 VM map lock의
대기까지 없어진다는 의미는 아니다.

## 3. zone_free_space_add는 일반적인 free 함수가 아니다

ABI는 `(space, allocation_size, new_extent, extent_size)`다. 자체 lock·VM 할당이 없고
호출자 쪽 직렬화에 의존한다. 반환할 원소를 새 영역에서 떼어내면서 나머지를 관리하는
함수이며 단순히 영역 전체를 반납하는 free로 해석할 수 없다.

검색은 기존 블록 시작이 새 영역보다 작고 기존 끝이 새 영역 시작과 같지 않을 동안
진행한다. 멈춘 후보가 인접하면 기존 hint를 필요에 따라 제거한 뒤, **반환 시작 주소를
기존 free block으로 바꾼다**(0x16a790). 나머지는 `기존 시작 + 요청 크기`에 만들고
길이는 `기존 길이 + 새 영역 길이 - 요청`의 DWORD 결과다. count는 유지한다.
이 인접 분기 자체에는 최소 나머지 크기 검사가 없다.

비인접 삽입 분기에서는 `새 영역 길이 - 요청`이 unsigned 0xf보다 클 때 나머지를
목록에 넣고 count를 증가시킨다(0x16a714). 작거나 같으면 나머지를 등록하지 않고
입력 시작 주소를 반환한다. 뺄셈 underflow를 따로 거부하지 않는다.

주의할 다른 분기는 `0x16a71c/0x16a71e`다. 검색이 멈춘 후보 끝이 새 영역 시작보다
크고 같지는 않으면 입력 주소를 그대로 반환하면서 새 나머지를 등록하지 않는다.
이는 “중첩을 모두 검사해 오류로 반환”하는 코드가 아니다. 새 영역이 기존 head보다
낮은 비중첩 범위인 경우에도 이 비교 조건을 만족할 수 있다. 반대로 앞쪽 블록 내부의
중첩은 검색 조건만으로 전부 잡히지 않는다. 실제 VM 주소 선택·재사용·GC가 이러한
순서를 만드는지는 아직 검증하지 않았으므로 정상 실행상의 결함으로 단정하지 않는다.
양쪽 이웃을 포괄적으로 병합하는 일반 free-list 삽입으로 확대 해석하지 않는다.

## 4. bootstrap과 초기 전역 상태

`zone_bootstrap`은 all-zones lock·head·count와 zget-space lock을 초기화한다.
default descriptor에는 hint 주소(0x1f6dc4→0x1f6dd0), hint 수(0x1f6dc8→1)를 쓰고,
space 배열 첫 slot과 count를 설정한다. 그러나 default descriptor의 나머지 필드와
hint 내용 전체를 이 본문에서 명시적으로 0으로 만드는 것은 아니다.

원본 section 기록에서 default descriptor·hint·zdata 포인터·page_mask는 `__DATA`,
`__common`, type 1 범위에 있으며 해당 VA의 file-backed bytes가 없다.
이를 가상 메모리의 관측된 0 값처럼 기록하지 않았다. 실제 loader/초기 부팅의 clearing과
후속 writer를 검증해야 한다. `_page_size`의 파일 word도 0이어서 파일값만으로 실행 시
페이지 크기를 정할 수 없다.

zone 자체 저장소는 `zget_space(default, 0x44, 0)`으로 확보하며 NULL이면 panic CALL로
간다(0x16b05d). 원소 크기는 0x50으로 정렬되고, 최대량은 0x2200의 page-round,
증설량은 0x44의 page-round이며 전자가 후자보다 작으면 올려 맞춘다. 사용량·free head·
insertion cache·doing-allocation 값은 0을 쓰며 flags의 하위 nibble은 8이 된다.
selector CALL(0x16b0ef) 뒤 all-zones 목록에 연결하고 `_zone_zone`을 기록한다.
이 본문에는 새 zone의 +0x3c 필드에 대한 직접 store가 없으므로 올바른 값이 된다고
주장하려면 allocator 반환 저장소의 이전 내용과 selector 계약을 추가로 연결해야 한다.

이후 descriptor 생성이 본문에 반복되어 있다.

| 정렬 단위 | 기준 최대 크기 | shift | hint 수·요청 바이트 |
|---:|---:|---:|---|
| 16 | 96 | 4 | 6개, 96바이트 |
| 128 | 768 | 7 | 6개, 96바이트 |
| 1024 | 실행 시 page_size | 10 | page_size >> 10개, 그 결과 << 4바이트 |

각 생성은 count를 먼저 증가시키고, `zget_space(default,0x1c,0)` 결과에 필드를 쓴다.
hint 확보 결과에 `bzero`를 호출한 **뒤** 배열 slot에 descriptor를 게시한다.
descriptor와 hint의 NULL 검사는 해당 반복 본문에 없고 count rollback도 없다.
따라서 부트스트랩 자원이 충분하고 직렬 초기화라는 전제를 별도로 확인해야 한다.
정상 직렬 완료를 가정할 때 slot은 0x1f6e04/0x1f6e08/0x1f6e0c이고 count는 4다.

Python의 조건부 계산에서 page_size=4096이면 마지막 hint는 4개/64바이트,
page_size=8192이면 8개/128바이트다. 이는 실제 페이지 크기 판정이 아니다.
32바이트 요청은 첫 descriptor의 16 정렬과 96 기준에 맞지만, 이 산술만으로 실제
callout zone의 descriptor 포인터가 그 값이라고 확정하지 않는다.

`zone_init`(0x16b338)은 현재 `_zone_map_size`를 읽어
`kmem_suballoc(kernel_map, &zone_min, &zone_max, size, 0)`에 전달하고 EAX를
`_zone_map`에 쓴다. 이 짧은 본문에는 RAM 크기 기반 재산정이나 결과 검사 코드가 없다.
원본 파일의 `_zone_map`, `_zone_map_size`, `_zdata_size`는 각각 0, 12582912,
430080이다. 실행 중 writer나 `zdata`의 실제 확보 범위를 증명하는 값은 아니다.

## 5. kmem_alloc_zone의 오류·출력 계약

원본 ABI는 `(map, output_pointer, size, canblock)`이다. `_kernel_object`를 local에
저장하고 offset local을 0으로 둔다. 크기는 page_mask로 round하며 시작 후보는 map+0x14다.
`vm_map_find(map,0,0,&start,rounded_size,1)`를 호출한다(0x1741af).

실패 값은 원래 코드를 그대로 돌려주는 것이 아니라 TEST/SETNZ/AND에 의해 **1**로
정규화된다. 현재 kernel_object가 저장한 포인터와 달라졌을 때만 저장 객체를 deallocate한
뒤 반환한다. 출력 포인터가 가리키는 word에는 쓰지 않는다.

find 성공 후 현재 kernel_object가 저장 포인터와 같으면 offset=start로 설정하고
객체 reference CALL, map write-lock, map+0x4c 증가, 기존 범위 delete,
같은 범위에 객체 insert, map unlock을 수행한다. insert의 반환 상태는 검사하지 않는다.
객체 포인터가 달라진 분기는 이 재삽입 경로를 건너뛰며 offset=0을 유지한다.
이 global 비교가 항상 같다는 boot/수명 보장은 아직 없다.

그 뒤 `FUN_00173ebc(object,offset,rounded_size,canblock)`을 호출한다(0x174247).
0이면 map lock을 잡고 timestamp 증가·범위 delete·unlock 후 **6**을 반환한다.
이는 부분적으로 확보된 페이지까지 wrapper가 map 삭제 경로에 넘긴다는 근거이지,
하위 delete/object reference 정리가 완전히 맞다는 증명은 아니다.

helper가 nonzero이면 `vm_map_pageable(map,start,end,0)`을 호출한다(0x174287).
그 반환 상태도 검사하지 않고 출력 주소를 기록(0x174292), EAX=0으로 성공 반환한다.
따라서 자체 분기의 반환값은 0/1/6이고 출력 store는 성공 경로에만 있다.
Ghidra가 표현한 `undefined1` 반환형을 원본 ABI의 확정된 1-byte 타입으로 채택하지 않는다.
또한 `canblock=0`이 map 찾기·lock·pageable 작업까지 무대기임을 뜻하지 않는다.

## 6. 페이지 확보 helper와 대기 경계

`FUN_00173ebc(object,offset,size,canblock)`은 size=0이면 바로 1을 반환한다.
그 외에는 object+0x10의 lock을 확보하고
`vm_page_alloc_sequential(object,offset,1)`을 호출한다(0x173eff).

페이지를 얻지 못하면 object lock을 먼저 해제한다. canblock=0이면 0을 반환하며,
이 helper 자체는 앞서 성공한 페이지들을 free하지 않는다. canblock이 nonzero이면
`vm_pages_needed_lock`을 확보하고 `thread_wakeup_prim(&vm_pages_needed,0,0)` 다음
`thread_sleep(&vm_page_free_count,&vm_pages_needed_lock,0)`을 호출한다.
이후 object lock을 다시 확보하고 **같은 offset·남은 size**로 페이지 할당을 재시도한다.
sleep 전에 free-count를 직접 비교하는 분기는 이 본문에 없다. 전달 lock을 sleep이
어떻게 소비하며 어떤 상태로 복귀하는지는 해당 callee와 scheduler 분석이 필요하다.

페이지 확보 성공 시 object lock을 해제(0x173f89)한 뒤 zero-fill CALL(0x173f8d),
page+0x20 byte의 bit 0 clear(0x173f92)를 수행한다. 외부 구조체 정의를 사용하지 않으므로
이 bit의 의미를 이름으로 확정하지 않는다. 이 구간 자체에 별도 wakeup CALL은 없다.
마지막으로 현재 page_size를 읽어 남은 size에서 빼고 offset에 더한다. 남은 값이 0이
될 때까지 반복하며, 정렬·정확한 배수·page_size nonzero를 검사하는 본문은 아니다.
페이지 단위 zero-fill이 나중의 zone 원소 재할당까지 zero-filled임을 뜻하지 않는다.

## 7. 디컴파일과 원본 lock 명령의 구분

반복 대기 load 위치는 0x16ae08, 0x16af04, 0x16b100, 0x173edf, 0x173f24,
0x173f68이다. 각 경우 원본 바이트 `75fc`의 JNZ 목적지는 메모리 load가 아니라
그 뒤 TEST 명령이다. 즉 해당 내부 반복은 EAX를 재검사하며 메모리를 다시 읽지 않는다.
이를 “volatile lock word를 계속 읽는다”는 C 표현으로 덮어쓰면 원본 의미를 잃는다.
실제 CPU 상태·인터럽트·진입값에 따른 진행성은 이번 정적 대조만으로 완료하지 않는다.

`zget_space`의 Ghidra C는 lock store를 바깥 do-loop 안으로 재배치한 형태로 보인다.
본 보고서는 0x16ae16/0x16af12의 XCHG 확보와 0x16aedb/0x16af41의 XCHG 해제를
실제 순서의 근거로 사용했다. bootstrap all-zones 연결에서도 C의 LOCK/UNLOCK 표식만
보고 lock 값 store가 없다고 판단하지 않고 0x16b10e의 원본 XCHG를 확인했다.

## 남은 경계

이번 결과는 원본의 직접 경로를 좁혔지만, boot 예약 영역·페이지 크기 writer,
free-space reclaim/GC와 주소 재사용 순서, VM map/object/page의 실제 정리·대기 계약은
남는다. [후속 목록](OPEN_ITEMS.md)에 원본 기반 다음 entry와 판단 기준을 기록했다.
전체 원본 분석 목표는 계속 미완료다. 복원 코드나 빌드를 현재 분석 완료 조건에 추가하지 않는다.
