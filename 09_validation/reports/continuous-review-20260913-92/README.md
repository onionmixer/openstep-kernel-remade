# 92차 — VM wiring 상태 전이와 copy 복구 경로

OPENSTEP 원본에서 entry count 변경과 실제 페이지 wiring, copyin/copyout 복구 경로를 연결했다.
**vm_map_pageable의 반환 0만으로 모든 페이지 wiring 성공을 증명할 수 없다.**
또 짧은 copy의 정상 반환은 복구 주소를 지우는 긴 경로를 건너뛴다.
이는 원본 지역 제어 흐름의 확인이며 native 장애·취약점 재현이나 전체 kernel 분석 완료가 아니다.
다른 코드·외부 소스는 참고하지 않았고 구현·복원·빌드·동적 실행은 하지 않았다.

## 검증 근거

원본 SHA-256은 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`이다.
일반 본문 13개와 synthetic fragment 7개, 명령어 1,229개/3,326바이트를 원본에서 decode했다.
직접 분기 172개, 직접 호출 48개, 중요 operand 146개, register-only TEST 반복 15개를 확인했다.
명시적 C WARNING 주석 13개는 fragment의 확대된 C 경고도 포함하므로 서로 독립된 결함 수가 아니다.
주소·개수·크기·비트·해시 계산은 Python만 사용했다.

[원본 기계 판독 근거](object-lifetime-evidence.json), [체크포인트](checkpoint.json),
[보존 해시](preservation.json), [검토 범위](SCOPE.md), [미해결 항목](OPEN_ITEMS.md),
[91차 호출자 연결](../continuous-review-20260913-91/README.md)을 보존한다.

## 1. vm_map_pageable: clamp와 split도 상태 변경이다

`0x175b2c`는 map write lock을 얻고 map `+0x4c`를 증가시킨다.
start는 map `+0x14` 이상으로, end는 `+0x18` 이하로 unsigned clamp한다.
그 뒤 start>end이면 start=end로 만든다. 자체 page 정렬이나 역전 구간 오류 반환은 없다.

hint/연결 목록에서 시작 entry를 찾고 start가 entry 내부이면 먼저 entry를 분할한다.
zalloc의 반환을 검사해 NULL이면 panic한다. 원본 copy는 CLD 뒤 REP DWORD 11개,
즉 44바이트다. 새 왼쪽 entry의 end를 start로, 기존 오른쪽 entry의 start와 offset을 변경하고,
map entry count `+0x1c`와 양방향 링크를 갱신한다.
entry flags BYTE `+0x18`의 마스크 5에 따라 참조 대상을 다르게 처리한다.
비영 마스크 쪽은 대상 `+0x34` 잠금 아래 DWORD `+0x30`을 증가시키며,
반대쪽은 vm_object_reference를 호출한다. 외부 구조체 타입을 가져와 해석하지 않았다.

**이 시작점 분할은 pageable 인자의 방향 분기와 unwire 사전 검사보다 앞선다.**
뒤에서 오류 4를 반환해도 timestamp/hint/이미 수행한 시작 분할을 복원하는 자체 경로는 없다.
따라서 오류 반환을 “아무 상태도 바뀌지 않았다”로 해석하면 안 된다.
예를 들어 clamp 결과 start=end여도 그 위치가 기존 entry 내부라면 분할을 수행할 수 있다.
entry를 찾지 못하면 다음 entry로 진행한다. 전체 구간의 빈틈 없는 매핑을 검사하는 루프는 아니다.

## 2. pageable 비영: 사전 검사 뒤 WORD 감소

인자가 비영이면 대상 entry들을 먼저 훑으며 WORD `+0x28`이 0인지 확인한다.
하나라도 0이면 lock_done 후 EAX 4로 반환한다. 이 검사 중에는 count를 감소시키지 않는다.
그러나 위의 시작점 분할과 map 상태 변경은 이미 일어날 수 있다.

사전 검사가 통과하면 end를 가로지르는 마지막 entry를 같은 44바이트 방식으로 분할하고,
각 대상 entry WORD `+0x28`을 감소시킨다. **감소 전 값이 1일 때만** vm_fault_unwire를 호출한다.
끝에서 map lock을 해제하고 0을 반환한다. 호출 결과에 따른 원상 복구는 이 본문에 없다.
숫자 마스크와 인자만 확인했으며 native unwire가 항상 정상 복귀한다고 가정하지 않는다.

## 3. pageable 0: count를 먼저 올리고 뒤에서 wiring

인자 0은 먼저 대상 entry들을 분할하고 WORD `+0x28`을 증가시킨다.
증가 전 값이 0이고 flags 마스크 1이 꺼져 있으면 object 준비를 수행한다.
flags `0x40`과 protection BYTE `+0x1c`의 마스크 2가 모두 켜졌으면 vm_object_shadow를
호출한 뒤 `0x40`을 지운다. 그렇지 않고 object 포인터 `+0x10`이 NULL이면
entry 길이로 vm_object_allocate를 호출해 결과와 offset 0을 저장한다.
이 본문에는 object 할당 결과의 추가 NULL 검사가 없다.

모든 entry 준비 뒤 map이 `_kernel_map`이면 lock_done으로 map lock을 놓는다.
다른 map이면 lock_set_recursive, lock_write_to_read 순서로 바꾼다.
그 뒤 다시 entry들을 순회하며 **현재 WORD count가 1인 entry만** vm_fault_wire에 넘긴다.
비-kernel map은 마지막에 lock_clear_recursive와 lock_done을 수행한다.
kernel-map 경로의 unlocked 순회가 안전한지는 별도의 lifetime/동시 변경 전제다.

count는 DWORD가 아니라 WORD다. `0xffff → 0`처럼 wrap해도 자체 오류 분기가 없다.
그 경우 증가 전 0 조건과 증가 후 1 조건이 모두 거짓이다. 이는 폭 계산의 결과이며
실제로 그 count에 도달하는지와 상위 제한은 아직 확인되지 않았다.

vm_fault_wire 반환을 검사하지 않고 최종 EAX는 0으로 덮는다.
이에 따라 91차 vslock/physio의 반환값 처리만 보완한다고 모든 wiring 실패를 감지할 수 있다는
결론도 성립하지 않는다. 하위 fault 경로의 반환·panic·잠금·재시도를 계속 확인해야 한다.

## 4. wire/fast path의 부분 처리

`vm_fault_wire` (`0x17358c`)는 entry의 start/end를 받아 먼저
`pmap_pageable(map.pmap,start,end,0)`을 호출한다. 원본 `pmap_pageable` (`0x1914c8`)은
prologue/epilogue/RET만 있는 본문이며 이 호출 자체가 페이지를 고정하지 않는다.

각 page 주소에서 `vm_fault_wire_fast(map,va,entry)`를 호출하고, 비영이면
`vm_fault(map,va,0,1,0)`을 호출한다. **일반 vm_fault의 반환값을 검사하지 않고**
page_size를 더해 다음 주소로 진행한다. 이 wrapper에는 앞선 페이지의 rollback도 없다.
page_size 0, 산술 wrap, map/entry lifetime은 별도의 전제다.

`vm_fault_wire_fast` (`0x173898`)는 flags 마스크 5를 허용하지 않으며 그런 경우 5를 반환한다.
그 밖에는 entry object와 `va-entry.start+entry.offset`, protection을 사용한다.
object 잠금 아래 WORD `+0x18/+0x44`를 증가시키고 vm_page_lookup을 호출한다.
NULL page, page BYTE `+0x20`의 `0x21`, page DWORD `+0x28`과 protection의 교집합이 있으면
object `+0x44` 감소·unlock·vm_object_deallocate를 거쳐 5를 반환한다.

허용 page는 vm_page_queue_lock 아래 vm_page_wire를 호출한다.
그 뒤 object `+0x1c`가 비영이고 protection 마스크 2가 켜져 있으면 page 상태를 되돌리는
BYTE 갱신/필요한 wakeup 후 **vm_page_unwire를 호출하는 지역 undo 경로**가 있다.
object 사용 상태를 정리하고 5를 반환한다. 따라서 “어떤 rollback도 없다”로 일반화하면 안 된다.
확인하지 못한 것은 vm_map_pageable 전체 요청 및 일반 vm_fault 실패의 rollback이다.

성공 후보는 page 상태를 표시하고 object lock을 놓은 채
`pmap_enter(map.pmap,va,page[+0x24],protection,1)`을 호출한다.
다시 object lock을 얻어 page BYTE의 마스크 1과 필요한 마스크 2를 지우고 wakeup,
object `+0x44` 감소·unlock·deallocate 뒤 EAX 0을 반환한다.
pmap_enter의 반환값은 검사하지 않는다. 실제 PTE 작성·page/object 수명·상태 마스크의
전체 의미는 하위 원본 writer와 계속 대조해야 한다.

## 5. unwire, pmap 조회와 페이지 count

`vm_fault_unwire` (`0x1735f4`)는 vm_page_queue_lock을 잡고 각 va의 pmap_extract를 수행한다.
반환 0이면 `unwire: page not in pmap` 진단으로 panic한다.
비영이면 pmap_change_wiring(...,0), vm_phys_to_vm_page, vm_page_unwire 순서다.
페이지 객체 변환 결과에는 자체 NULL 검사가 없다. 마지막에 queue lock을 해제하고
빈 본문 pmap_pageable(...,1)을 호출한다.

`pmap_extract` (`0x190c24`)는 splvm과 pmap `+0xc` 잠금을 사용한다.
`va >> 22`로 첫 DWORD 주소를, 그 값의 `0xfffff000`과 `(va >> 10) & 0xffc`로
다음 DWORD 주소를 계산한다. 각각 마스크 1과 중간 포인터 0 여부를 검사한다.
성공은 마지막 frame과 `va & 0xfff`의 합, 실패는 0이다. 마지막에는 unlock/splx 후 결과를 반환한다.
유효한 주소의 계산 결과도 0일 수 있는 수치적 경우와 실패 sentinel을 구분하는 별도 tag는 없다.
마스킹한 주소를 실제로 역참조하는 데 필요한 page-table 주소 공간 전제는 미확정이다.

`pmap_change_wiring` (`0x190b5c`)는 splvm 후 첫 단계 마스크 1과 계산된 PTE 포인터를 검사하지만,
pmap_extract와 같은 두 번째 present 검사는 하지 않는다. PTE BYTE `+1`의 마스크 2와
인자의 비영 여부에 따라 helper `0x19108c/0x1910e4`를 호출한다.
그 뒤 ptes_per_vm_page가 양수이면 각 PTE BYTE `+1`의 마스크 2를 인자의 low bit에 맞춰 갱신한다.
DWORD 마스크로는 `0x200`이다. 비영 판단과 low bit 판단이 다르므로 일반 인자가 0/1이라는
전제가 필요하지만 선택 unwire 호출자는 0을 넘긴다. 자체 pmap lock·TLB invalidation 호출은
이 본문에 없으며 helper와 외부 동기화 계약은 아직 열려 있다.

`vm_page_unwire` (`0x17b7bc`)는 page WORD `+0x1c`를 감소시키며, 이전 값 1일 때만
원본 active queue 끝에 연결하고 active count 증가, BYTE `+0x1e` 마스크 2 설정,
전역 wire count 감소를 수행한다. 자체 NULL/0 count 검사나 자체 lock은 없다.
선택한 호출자는 queue lock을 잡고 호출하지만 다른 호출자와 그 잠금의 native 유효성은 별도다.
entry WORD `+0x28`과 page WORD `+0x1c`를 같은 count로 취급하지 않는다.

## 6. 잠금 전이와 register-only loop

lock_set_recursive (`0x15bb9c`)는 내부 `+8` 잠금 아래 lock BYTE `+6`의 마스크 2를 요구한다.
없으면 panic하며, 정상 경로는 첫 DWORD에 active_threads 값을 저장한다.
lock_write_to_read (`0x15b9b0`)는 WORD `+4`를 증가시킨 뒤 WORD `+6`의 상위 `0xfff0` 부분이
비영이면 그 부분을 `0x10` 감소시킨다. 아니면 low BYTE의 마스크 1 또는 2를 지운다.
대기 마스크 4가 있으면 지우고 thread_wakeup_prim(lock,0,0) 후 내부 잠금을 놓는다.
lock_clear_recursive (`0x15bbe0`)는 현재 owner를 검사하고, 상위 `0xfff0`이 0이면 owner를
`0xffffffff`로 바꾼다. 각 호출의 EAX는 독립 성공 코드가 아니라 마지막 XCHG의 이전 값일 수 있다.

선택 본문에서 15개의 `LOAD → TEST → JNZ TEST`를 확인했다. raw 분기는 모두 `75fc`다.
비영 EAX를 읽은 뒤에는 해당 TEST loop 안에서 메모리를 다시 읽지 않는다.
Ghidra의 메모리 재조회 while과 같지 않으며, 별도 XCHG 재시도는 LOAD로 돌아간다.
주소 목록은 JSON에 보존했다. 반복문 수는 native 교착 발생 수나 전체 kernel의 총 loop 수가 아니다.

## 7. copyin/copyout와 복구 슬롯

copyin `0x189a5c`는 현재 thread `+0x74`에 `0x189b18`, copyout `0x189cec`는 `0x189e70`을 저장한다.
이전 복구 슬롯 값을 저장하거나 나중에 복원하지 않는다.
두 함수는 길이를 **signed 비교로 15 이하인지** 판단한다. 상위 rwuio의 음수 길이 거부와 별개로,
다른 호출자까지 원시 인자의 비음수 조건이 증명된 것은 아니다.

copyin의 짧은 경로는 `REP MOVSB ES:[EDI],FS:[ESI]` 후 바로 반환 0으로 간다.
긴 경로는 source를 DWORD 경계에 맞춘 prefix, FS source의 REP DWORD, 나머지 BYTE를 복사한다.
자체 CLD가 없으므로 REP 방향과 FS/ES 상태에 대한 진입 전제가 필요하다.
Ghidra C의 일부 루프는 FS 의미를 생략하고 증가 방향을 고정하므로 그대로 정확한 C 의미가 아니다.

copyout은 일반 source에서 읽어 FS destination에 BYTE/WORD/DWORD를 쓰는 scalar 명령을 사용한다.
짧은 경로는 low bit/WORD 부분과 DWORD loop, 긴 경로는 정렬 prefix와 풀어 쓴 DWORD 묶음,
마지막 BYTE를 처리한다. 이 본문은 copyin의 REP/DF 전제와 동일하지 않다.
긴 복사 후 나머지 BYTE는 offset 2,1,0처럼 역순으로 기록될 수 있으므로 fault 전의 결과를
항상 단순한 연속 prefix로 가정하지 않는다.

두 함수 모두 **짧은 정상 경로는 복구 슬롯 clear를 건너뛰고** 원래 epilogue로 간다.
길이 0도 여기에 포함된다. 긴 정상 경로는 슬롯을 0으로 지운다.
따라서 91차 readv/writev의 count 0 또는 1에 대한 vector 배열 copyin도
각각 길이 0/8의 짧은 경로에 해당한다. 이후 코드의 슬롯 갱신/복귀/예외 진입을 추가로 확인해야 한다.

복구 조각 `0x189b18/0x189e70`은 슬롯을 0으로 지우고 EAX `0xe`를 설정한 뒤
원래 함수 epilogue로 fall-through한다. 각 조각 자체는 독립 스택 프레임이나 RET가 없다.
실제 trap handler가 이 주소로 어떻게 이동하고 EBP/ESP·DF/FS를 보존하는지는 아직 이번 범위에서
입증하지 않았다. 부분 복사의 rollback·실제 완료 바이트 수를 반환하는 자체 경로도 없다.

이 원본 계약은 90차 sdwrite의 데이터 copyin 반환 무시와 sdread의 전체 길이 copyback을
추가로 검토해야 하는 이유다. 단지 복구 슬롯이 있다는 사실만으로 복사가 안전하거나
항상 완전하다고 볼 수 없다. 동시에 복구 주소 잔존만으로 실제 native 장애를 확정하지 않는다.

## 판정과 후속

원본·기존 자료·이전 보고서 보존 항목 843개 및 현재 입력 67개를 재해시했다.
Ghidra 스킬의 본문·참조 대조 절차로 C의 count 폭·복구 인자·fragment/REP/loop 해석을 검증했다.
새 독립 교차검토는 미수신이며 통과로 간주하지 않는다. 실패 요청의 재시도·우회,
새 verifier/에뮬레이터 파일, DB 변경은 없었다.
일반 vm_fault의 실패·재시도·수명과 trap 복구 슬롯의 실제 소비 경로를 다음 우선으로 남긴다.
전체 원본 분석 목표는 계속 미완료다.
