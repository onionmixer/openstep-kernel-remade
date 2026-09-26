# 103차 이후 남은 원본 분석

runq 선택·등록·제거, idle 전달, stack/swapin과 context helper의 실제 인자·이동을 연결했다.
전체 queue/allocator/IRQ/CPU 수명 및 커널 의미 분석은 미완료다.

## 직접 후속 항목

1. **스택 공급·회수와 최초 문맥**: allocStack/freeStack, cache/header/count 초기화·회수,
   reserve stack 생성·소유권, initial load_context 0x18e0e4와 하위 helper,
   active_stacks/stack_pointers/active_threads의 전체 writer를 연결한다.
   stack+0xff4만으로 실제 할당 크기·정렬·guard/초기값을 확정하지 않는다.
2. **priority·runq 불변식**: update_priority, 초기 runq head/hint/count, processor/pset 초기화,
   모든 T+0x58/+8 writer와 enqueue caller의 state/lock/IRQ 전제를 확인한다.
   hint 상한과 post-removal 하향 탐색 하한, count와 실제 목록 일치가 핵심이다.
   지정 literal count writer 0x164e35는 해당 scheduler 본문 전체와 다시 연결해야 한다.
3. **idle·binding과 동시성**: processor state와 pending-slot 전체 writer,
   idle 직접 전달이 binding 검사에 앞서는 전제, PMSetCpuState 및 spl/IRQ,
   T+0/+4의 run/wait/reaper/swapin 재사용 시점과 동시 종료·우선순위 변경을 확인한다.
4. **machine 소비와 반환**: saved TSS field 전체 writer/reader, GDTR/GDT/LDT/TSS,
   CR3/TLB/CR0/FP/IRQ와 continuation별 새 stack 진입 및 복귀 조건을 확인한다.
   handoff의 global-stack 재게시 생략과 EBX 초기값 0을 전체 실행 수명과 연결한다.
5. **102차 이전 종료 계약**: AST 진입 frame/IF, IPC port/space 해제와 thread/task 참조,
   bitmap/TSS/PC callback/map의 최종 수명은 계속 미완료다.

[102차 목록](../continuous-review-20260913-102/OPEN_ITEMS.md)의 나머지 유보를 유지한다.
Zone GC/backing VM/boot, I/O Ports ObjC binding, trap/copy recovery,
VM COW/shadow/pager/PV, VFS/UFS/NFS/RPC/XDR, IPC/MIG/BSD/network,
DriverKit/kernserv/ObjC/MMIO/DMA, 모든 영역·entry·경계·ABI·경고·실패의 전체 검토도 남아 있다.

다음 작업도 원본 OPENSTEP 분석으로만 제한한다. 다른 코드 참조, 구현·복원·빌드·포팅은 하지 않는다.
신규 독립 계획 검토를 받지 않았다는 제한을 유지한다.

[이번 결과](README.md) · [범위](SCOPE.md)
