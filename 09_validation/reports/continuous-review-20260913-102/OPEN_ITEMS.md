# 102차 이후 남은 원본 분석

halt의 자체 성공/실패 조건, self 종료 등록, AST 소비와 scheduler의 정지 대기자 처리까지
연결했다. 실제 CPU 정지·IRQ·목록·참조 수명의 완전한 증명이나 전체 분석 완료는 아니다.

## 직접 후속 작업

1. **scheduler 선택·게시**: thread_select, thread_setrun, run queue enqueue/dequeue,
   processor 상태·우선순위·idle, swapin/stack allocation 재시도와 공정성 전제를 연결한다.
   같은 thread를 선택하는 경로와 종료 continuation walking_zombie의 도달 조건도 확인한다.
2. **machine 문맥과 continuation**: stack_handoff, switch_context, stack_free/alloc,
   stack_pointers/active_stacks/active_threads writer와 continuation entry의 실제 stack 준비,
   IRQ/segment/CR0/CR3/TSS를 연결한다. JMP helper의 C return을 근거로 완료하지 않는다.
3. **AST 진입과 IF 계약**: 0x187057/0x18df4d/0x18e01a caller의 진입 프레임,
   snapshot 전후 IRQ·spl 변환, FP AST와 signal 하위 호출을 분석한다.
   need_ast literal write 30개는 alias/bulk/함수 밖 전체 writer closure가 아니다.
4. **정지·wait 목록 동시성**: T+0/+4가 run/wait/reaper에서 재사용되는 시점,
   clear_wait의 event 재검사, timeout/callout in-flight, wait bucket 잠금과 wakeup,
   halt의 해제 후 상태 읽기 및 hold/release 균형을 모든 관련 경로에 연결한다.
   must_halt=1 정상 반환값 0과 반드시 유한 시간에 정지함은 다른 명제다.
5. **IPC와 thread/task 참조**: self-port gate 초기화·재게시, release_send,
   dealloc_special, right_reverse/destroy, space_destroy와 thread/task reference 변화를 확인한다.
   포인터를 먼저 0으로 만드는 것은 다른 호출의 cleanup 완료 대기가 아니다.
6. **PCB/K bitmap/TSS 수명**: 101차의 K+8/+0xc, PCB TSS pointer/size/ownership,
   I/O offset/추가 바이트 writer와 최종 해제는 여전히 별도 추적이 필요하다.
   현재 종료 연결만으로 bitmap 누수, TSS 초기값 또는 메모리 사용 종료를 확정하지 않는다.

## 기존 미완료 유지

[101차 목록](../continuous-review-20260913-101/OPEN_ITEMS.md)의 사용자 저장 상태 prefix,
FP 동기화, 참조·목록·nthreads 균형, PCB/PC callback·map 수명과 생성 ABI caller는 유지한다.
Zone GC/backing VM/boot, I/O Ports ObjC binding, LDT/GDT/IDT/IRETD/DF/FS/TLB,
trap/copy recovery, VM COW/shadow/pager/PV, VFS/UFS/NFS/RPC/XDR, IPC/MIG/BSD/network,
DriverKit/kernserv/ObjC/MMIO/DMA의 나머지 분석과 전체 영역/entry/ABI/경고/실패 검토도 미완료다.

후속 작업은 원본 OPENSTEP 분석에만 제한한다. 외부 코드 참조, 복원·구현·빌드·포팅은 하지 않는다.
새 독립 계획 검토를 받지 않았다는 제한을 유지한다.

[이번 결과](README.md) · [범위](SCOPE.md)
