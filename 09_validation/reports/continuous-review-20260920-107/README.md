# 107차 연속 검토 — VM COW, fault 오류 반환, map fork 수명

## 판정

원본 x86 `mach_kernel`의 명령어를 정적으로 다시 디코드하여, VM COW의 object-chain 변경,
`vm_fault`의 반환값, map-copy/fork의 분기, 그리고 map deallocate의 마지막 참조 정리를
확인했다. 이 보고서는 디컴파일 출력만으로 정한 동작을 확정하지 않는다.

`vm_fault`에는 공통 복귀부 `0x00173580`가 있다. `vm_map_lookup`의 비영 값은
`0x0017207a`에서 그대로 그 복귀부에 전달된다. 세 정리 경로는 `EAX=10`
(`0x001721de`, `0x00172572`, `0x00172922`)으로, 두 thread 중단·재검사 경로는
`EAX=0` (`0x00172376`, `0x00172d13`)으로 복귀한다. 정상 경로는 `0x0017357e`에서
`EAX=0`을 만든 뒤 같은 epilogue로 떨어진다.

직접 caller 다섯 곳 중 `_vm_fault_wire`는 반환 레지스터를 검사하지 않는다.
`_user_trap`, `_kernel_trap`, `_PCexception`은 반환값을 저장하여 비영 값에 분기하고,
`FUN_001923e0`은 이를 자신의 반환값으로 보존한다. 따라서 `vm_fault`의 오류 전파는
호출자마다 동일하지 않으며, wire helper의 무시를 일반 caller의 계약으로 확대할 수 없다.

`_vm_object_copy`는 object lock `+0x10` 아래에서 `+0x28`과 byte `+0x46` bit `0x10`을
검사한다. 빠른 경로는 `+0x18`을 증가시키고 output flag에 1을 기록한다. 다른 경로는
backing object의 `+0x1a`, `+0x28` 조건을 검사해 재사용하거나, 새 object를 할당해
`+0x20/+0x24` chain과 참조 count `+0x18`을 갱신하고 output flag에 0을 기록한다.
field의 의미와 count의 자료형 범위는 이 명령만으로 확정하지 않았다.

`_vm_object_shadow`는 새 object를 할당해 input object pointer가 가리키던 값을 새 object
`+0x20`으로, input offset pointer가 가리키던 값을 `+0x24`로 옮긴 뒤 offset을 0으로,
object pointer를 새 object로 바꾼다. 이 함수 본문에는 참조 count를 직접 증가시키는
명령이 없다.

`_vm_fault_copy_entry`는 새 object를 만든 뒤 page 단위로 진행한다. page 할당이 0이면
object lock을 풀고 `thread_wakeup_prim` 및 `thread_sleep`을 거쳐 다시 시도한다. source
page lookup이 0이면 panic call로 간다. 성공한 page는 `vm_page_copy`, `pmap_enter`,
queue lock 아래 `vm_page_activate` 순으로 처리한다.

`_vm_map_copy_entry`와 `_vm_map_fork`는 `vm_object_copy`의 output flag를 검사한다.
flag가 설정되면 양쪽 entry flag에 bit `0x40` 및 bit `0x08`을 설정하고, 기존 object를
deallocate한 뒤 `pmap_copy`를 호출한다. map entry WORD `+0x28`이 0이 아닌 경로는
`vm_fault_copy_entry`로 분기한다. `_vm_map_fork`는 parent write lock 후 `+0x4c`을
증가시키며 시작하고, 끝에서 parent에 `lock_done`을 호출한 후 새 map pointer를 EAX로
반환한다.

`_vm_map_deallocate`는 map `+0x34` interlock 아래 `+0x30`을 감소시킨다. 감소 전 값이
양수인 경우에만 바로 반환하며, 0 또는 음수에 이르면 write lock, 전체 범위
`vm_map_delete`, `pmap_destroy`, `zfree`를 차례로 수행한다.

## 검증 범위

- 원본: `03_original/x86/binaries/mach_kernel`
- 원본 SHA-256: `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`
- export: `04_ghidra/exports/x86/full-pass5`
- 독립 명령 디코드: Python `capstone`, Mach-O `__text` file offset `4816`, VM address
  `0x001012d0`을 사용한 원본 바이트 대조

세부 call/return/명령 evidence와 Python 집계값은
[`vm-cow-fault-evidence.json`](vm-cow-fault-evidence.json)에, 입력 보존 검사는
[`preservation.json`](preservation.json)에 있다.

## 아직 남은 범위

이번 확인은 COW·fault·copy/fork/deallocate의 직접 경로만 다룬다. page/object/map/pmap
간접 call, 주소 table, alias writer, runtime initializer, pager와 PV의 간접 dispatch,
object `+0x30`과 entry WORD `+0x28`의 전 수명, 그리고 모든 caller의 rollback/lock order는
계속 조사 대상이다. 이 보고서만으로 106차 `OPEN_ITEMS.md`의 1번 또는 2번을 완료로
바꾸지 않는다.
