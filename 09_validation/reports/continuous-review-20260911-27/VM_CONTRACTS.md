# VM 반환·재시도 및 공개 소스 대응 — 원본 정적 근거

아래는 mk-183.34.4 i386 원본 명령에서 조사한 계약이다. 실행하지 않은 경로의
실현 가능성·동시성까지 증명한 것이 아니다. 주소가 있는 분기 자체와 공개 소스의
이름·해석을 구분한다. 수치 검산과 상대 분기 목적지 계산은 Python이다.

## vm_fault의 서로 다른 결과

| 조건/지점 | 원본 제어 흐름 | 후속 검증 의무 |
|---|---|---|
| 최초 map lookup 실패 | `0x17206b` 호출, `0x172078`에서 실패 분리, `0x17207a`의 결과를 반환 | 주소 없음/권한 거절 외 share/submap/upgrade 상태 |
| 조회된 page의 error bit | `0x1720e6`의 bit `0x40`; busy/wanted 정리, 필요 wakeup, page free 및 참조 정리, `0x1721de`에서 EAX=10 | 실제 page free의 hash·memq·queue·참조/PV 영향 |
| 조회된 page가 busy | `0x1721e8`의 bit 1; wanted 설정, assert_wait, map unlock, thread_block 뒤 wait_result 확인 | scheduler/실제 wakeup; 합성 return mock으로 대체하지 않기 |
| busy 대기 결과 4 | `0x172254` 비교; 정리 후 `0x173401 → 0x172047` | 최초 map lookup부터 다시 수행하는 재시도 |
| busy 대기 결과 0 | `0x1722c8/0x1722ca → 0x1720cc` | 현재 object의 page lookup부터 반복; 최초 map lookup 재시도와 다름 |
| busy 대기의 그 외 결과 | 정리 후 `0x172376`의 XOR EAX,EAX와 epilogue | **매핑 생성 없이 0 반환**. 성공 매핑과 구분해야 함 |
| page absent bit | `0x172380`의 bit `0x20`; shadow 검사 및 필요 zero-fill/free/다음 object 진행 | absent와 lookup miss·pager error의 구별 |
| page_lock와 요청 접근 충돌 | `0x1724c3`의 AND 성격 TEST, `0x1724c6` 비영 fallthrough → 정리 → `0x172572` EAX=10 | 이 원본은 여기서 pager unlock을 요청하지 않음 |
| page lookup miss | `0x1720dd → 0x172678`; pager/배선/최초 object 조건으로 alloc 여부 결정 | alloc을 무조건 호출한다고 가정하지 않기 |
| page alloc 실패 | `0x17269a` 이후 NULL; 잠금·참조 정리 후 `0x172e63` 공통 대기, `0x172e85 → 0x172047` | free queue, pageout wakeup, thread_sleep, 자원 가용성 전환 |
| pager 요청 | `0x1727c3`의 vm_pager_get 호출 | object unlock 및 map unlock 이후 실제 device/vnode 경로 |
| pager 반환 0 | `0x1727cd` fallthrough, 재잠금·page lookup·`0x1914dc` 호출 뒤 resident 처리로 합류 | `0x1727fa`는 lookup 결과의 phys 필드를 역참조; mock 성공만으로 안전하지 않음 |
| pager 반환 2 | `0x17280c` 비교, page/참조 정리 후 `0x172922` EAX=10 | 실제 I/O 오류와 error 포인터 기록 |
| pager의 나머지 결과 | `0x17292c` 이후 shadow 탐색/zero-fill | 공개 헤더의 PAGER_ABSENT=1은 대응 근거지만 원본 분기는 정확히 1만 검사하지 않음 |
| shadow에서 얻은 page | `0x172a51` 최초 object와 비교; 요청 write bit에 따라 copy 또는 write 제거 | 원본 page copy·object collapse·paging 수와 복사 중 정합 |
| copy object의 busy 대기 | `0x172bef` assert_wait 후 정리, `0x172ced` thread_block | `0x172d0d` wait_result=0이면 최초 lookup 재시도, 그 외 `0x172d13`에서 0 반환 |
| copy object의 alloc 실패 | `0x172d30` 이후 NULL, 정리 후 공통 free-page 대기 | copy object ref·원래 page queue·최초 object 수명 |
| map을 놓은 뒤 재검사 | `0x1730de` lookup; 오류 반환, object/offset 변경, wired protection 변경을 분리 | map 잠금을 놓는 경로에 대한 변경·재시도 시험 |
| 최종 매핑 | `0x17344c` pmap_enter 이후 배선/activate·busy 해제·참조 정리, `0x17357e`에서 0 | report26은 이 중 resident/same-physical/비경합 사례만 실행 |

`vm_fault=0`은 원본 제어 흐름의 반환 규약이다. 그것만으로 pager I/O나 PTE 변경이
발생했다고 판정할 수 없다. 완료 판정에는 경로별 원인과 실제 매핑, 예외 복귀 후
명령의 진행 여부가 필요하다. 반대로 정적 중단 경로가 존재한다는 사실을 사용자
복사의 정상 호출에서 그 경로가 실제 발생했다는 증거로 쓰지 않는다.

## 공개 소스에서 그대로 가져오면 안 되는 차이

NeXTMach `mk-108.1/vm/vm_fault.c`의 page_lock 충돌 처리는 pager_data_unlock 요청,
wait와 재시도를 포함한다. Darwin-0.1 `kernel/vm/vm_fault.c`는 그 위치에서 정리 후
KERN_MEMORY_ERROR를 반환한다. 조사한 원본 `0x1724c3 → 0x172572`는 후자와
대응한다. 따라서 오래된 공개 소스의 해당 동작을 그대로 채택하면 원본과 달라진다.
이 국소 일치가 Darwin 파일 전체의 동일성이나 그대로 컴파일 가능한 ABI를 뜻하지 않는다.

busy 대기의 THREAD_AWAKENED/THREAD_RESTART 이름도 공개 소스로 해석하되 원본
비교 상수와 분기를 함께 보존한다. 현재 명세는 원본의 0/4/그 외 분리를 기준으로 한다.

## 다섯 번째 인자와 pager error 포인터

원본 vm_fault는 `0x1727ba`에서 `[EBP+0x18]`을 읽고 vm_pager_get의 마지막
인자로 전달한다. Darwin 소스의 NeXT 조건부 `int *error` 인자와 대응한다.
mk-108.1의 네 인자 선언만 채택해서는 안 된다.

정본 whole-program listing의 직접 CALL을 모두 검색하고 원본 상대 분기 바이트를
대조했다. `0x1735d5`, `0x192000`, `0x1921e7`, `0x19242d`, `0x1a143c`의
인자 준비 구간은 모두 PUSH 다섯 개이고 맨 먼저 error=0을 넣는다. protection 선택
분기가 PUSH를 건너뛰지 않는지도 검사했다. 이는 현재 listing에서 확인한 직접
호출 계약이며 간접 호출이나 다른 바이너리의 호출자를 배제하지 않는다.

원본 vm_pager_get의 dispatch는 다음과 같다.

- pager가 NULL이면 page zero-fill helper를 호출하고 0 반환.
- pager 첫 dword가 비영이면 `_device_pagein(0x17c264)`으로 page 전달.
- 그 외에는 error 인자를 `_vnode_pagein(0x17d2d0)`에 전달.

`_vnode_pagein`의 `0x17d373`은 vnode operation을 통한 간접 CALL이다. 그 뒤
`0x17d377`에서 error 포인터의 NULL 여부를 검사하고 비영일 때만 `0x17d385`에서
오류 값을 저장한다. 이 부분은 원본 ASM을 읽은 정적 근거이며 이번 함수 본문
전체 census/실행 대상에는 포함하지 않았다. 실제 pager 성공/실패 검증에는 vnode,
operation table, 파일/장치 및 I/O 완료 상태를 연결해야 한다.

## pmap_enter: 원본 흐름과 다음 fixture의 위험

| 경로 | 원본 근거 | 필요한 선행조건/판정 |
|---|---|---|
| pmap NULL | `0x190665/0x190669 → 0x190af0` | 매핑을 만든 것으로 판정하지 않음 |
| protection=0 | `0x19066f` 이후 제거 경로; `0x190727` helper 호출 | 기존 매핑/PV/통계 및 invalidation; 일반 새 매핑과 분리 |
| PDE 부재 | `0x190788/0x19078b`; SPL 복원 후 `0x1907ac` expand, 다시 `0x190780` | 원본 PT 할당/목록/소유권을 준비하고 루프의 전진을 관찰 |
| 같은 물리 주소 | `0x1907d0/0x1907d3` fallthrough | report26 검증 범위. wired 변화에 따른 통계 helper는 별도 |
| 다른 물리 주소 | `0x1907d3 → 0x190914`; invalidation 후 `0x190990` 제거 helper | 이전 PV/dirty/통계와 새 매핑 모두 정합; report26의 합성 pmap만으로 충분하지 않음 |
| 새 매핑/PV | `0x190998` 물리 범위 검사; managed 영역이면 descriptor/PV 탐색 | managed 경계를 조작하여 PV 경로를 우회한 시험을 전체 교체 검증으로 삼지 않음 |
| PV head 비어 있음 | `0x1909d5/0x1909d9` 후 head에 pmap/VA 기록 | 정확한 descriptor 크기/인덱스·해당 물리 페이지 소유권 |
| PV 추가 노드 필요 | `0x190a06` zalloc 후 `0x190a11 → 0x19075c` | 할당 동안 상태 변화 가능. 반환 뒤 같은 분기로 곧장 이어 붙이지 않음 |
| 여분 PV 노드 불필요 | `0x190ada` 후 `0x190aeb` zfree | 재검사 뒤 여분 노드가 소비/해제되는 두 경우 |
| 새 매핑 통계/PTE | `0x190a40` 통계 helper, `0x190aa7` PTE store | 원래 제거/추가와 PT extension 통계까지 검증 |

`0x190cfc`는 정본 이름이 **FUN_00190cfc**이다. 이 문서의 pmap_expand는 공개
소스/동작 대조에 따른 해석 이름이며 원본 심볼로 승격하거나 DB를 변경하지 않았다.
제거 helper `0x18f7f8`, 통계 helper `0x190f24`도 정본에서 DEFAULT 이름이다.

expand helper는 free PT 목록이 있으면 가져오고, 없으면 `0x190d76`에서
kmem_alloc_wired를 호출한다. 실패하면 `0x190d80 → 0x190f1a`로 돌아간다.
호출자 pmap_enter는 이 반환값을 오류로 검사하지 않고 PDE를 다시 확인한다.
따라서 여기서 vm_fault로 직접 ENOMEM이 반환된다고 모델링하면 안 된다. 반복
실패의 종료/대기 특성은 allocator와 자원 상태까지 조사해야 하며 현재 무한 루프의
실제 발생을 주장하지 않는다.

expand가 메모리를 얻은 뒤에는 `0x190e35`에서 다른 실행 주체가 먼저 확장했는지
다시 검사한다. 이미 생겼다면 extension 및 메모리를 정리하고, 없으면 active PT
목록에 연결하고 `0x190ef4`에서 PDE를 쓴다. 이 경쟁 경로는 단일 backend 비경합
시험으로 완료 처리할 수 없다.

Darwin pmap.c는 관련 알고리즘의 대응 자료지만 cache 관련 wrapper/인자가 있는
다른 버전이다. helper 이름이 비슷하다는 이유로 구조체/함수 원형 전체를 복사하지 않는다.
