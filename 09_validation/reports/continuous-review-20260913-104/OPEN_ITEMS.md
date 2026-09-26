# 104차 이후 남은 원본 분석

스택 슬롯의 공급·cache 반환·pageable 전환·해제 wrapper와 최초 context의 실제 명령을
연결했다. 전체 원본 커널 분석은 여전히 미완료다. 함수 내부 사실과 전체 실행 전제를 구분한다.

## 직접 후속 우선순위

1. **cache lock/IRQ와 waiter 계약**: freeStack의 unlock 후 scan/removal,
   doSwapout의 자체 무잠금, swapoutStack의 lock 유지 VM 호출,
   swapinStack의 VM 호출 후 lock 순서에 필요한 caller 직렬화를 확인한다.
   lock_write/read/done, spl/IRQ, wakeup/assert_wait/event의 전체 전제를 연결한다.
   count/head/state 불일치와 waiter flag 변경이 실제로 가능한지는 아직 판정하지 않는다.
2. **통계·reserve caller**: 0x168bb8 stack_statistics caller의 출력 초기값과 사용량 lock,
   stack_check_usage와 max 통계의 alias/runtime writer를 확인한다.
   stack_privilege 직접 caller, T+0x30 전체 writer, detach/handoff/termination의 reserve
   최종 해제와 active stack 일치를 닫는다. NOP 사이의 레지스터-only TEST loop는
   debug 조건·호출 경로까지 확인해야 실제 진행성 문제를 판단할 수 있다.
3. **VM wire/unwire/remove**: kmem_alloc_wired 하위 0x173ebc,
   vm_map_pageable 0x175b2c, vm_map_remove 0x1765ac와 map/object/page/pmap 수명을
   연결한다. 반환 상태 미검사의 실제 영향, 실패 rollback, fault/page alignment,
   페이지/슬롯 설정 불변성, guard/protection 및 재사용 내용은 아직 미완료다.
4. **새 문맥의 전제**: 최초 thread/PCB/TSS/continuation 준비 전체와 start_initial_context의
   호출을 연결한다. GDTR/GDT/LDT/TSS base·limit·selector runtime writer,
   CR3/TLB/CR0/FPU/IRQ와 saved EIP/EBX/ESP의 전체 수명·귀환을 확인한다.
5. **도달성**: 이번 direct CALL 조사에서 검출되지 않은 newStack/swapoutStack/
   swapinStack/stack_collect를 미사용으로 단정하지 않는다. 원본 주소 테이블·간접 호출·
   함수 밖 영역과 loader/fixup 영향을 조사해야 한다.

## 이전 미완료 항목 유지

[103차 목록](../continuous-review-20260913-103/OPEN_ITEMS.md)의 priority/runq 초기화·hint/count,
processor/pset·idle/binding·pending-slot writer, AST/IPC/thread/task 종료 및 callback/map 수명은
이번 스택 검토로 완료되지 않았다. Zone GC/backing VM/boot, trap/copy recovery,
VM COW/shadow/pager/PV, VFS/UFS/NFS/RPC/XDR, IPC/MIG/BSD/network,
DriverKit/kernserv/ObjC/MMIO/DMA 및 모든 영역·entry·경계·ABI·경고·실패 검토도 남아 있다.

신규 독립 계획 검토 미수신 제한을 유지한다. 다음도 원본 OPENSTEP 분석만 진행하며
다른 코드 참조·구현·복원·빌드·포팅으로 확대하지 않는다. 모든 계산은 Python으로 한다.

[이번 결과](README.md) · [범위](SCOPE.md)
