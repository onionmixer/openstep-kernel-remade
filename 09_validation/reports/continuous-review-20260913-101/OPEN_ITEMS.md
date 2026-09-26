# 101차 이후 남은 원본 분석

이번 검토로 PCB/K 생성·종료와 thread 사용자 상태 복제, 최종 해제 후보 재검사 및
reaper 연결을 좁혔다. 원본 전체 분석과 객체 수명의 완전한 증명은 아직 끝나지 않았다.

## 직접 후속 항목

1. **K/bitmap/TSS 전체 writer와 소유자**: K+8/+0xc, P+0/+4/+8/+0xc,
   P+0xf0 소유 flag, I/O offset과 추가 바이트의 alias/bulk writer 및 해제를 연결한다.
   common destructor에 bitmap free가 없다는 사실만으로 실제 누수를 확정하지 않는다.
   99차 조건부 첫 kfree(0,0)와 100차 allocator 재사용 전제도 유지한다.
2. **종료 완료 계약**: thread_halt, AST 생성·소비, ipc_thread/task 종료와 scheduler 경로를 읽어
   자기 자신 종료, 강제 종료, reaper enqueue/dequeue와 실제 최종 해제의 관계를 닫는다.
   task_terminate의 inactive→task_hold 실패 가능 경로를 성공한 hold로 간주하지 않는다.
3. **참조·목록·카운터 균형**: task_create의 초기 참조, kernel_task_create의 감소,
   thread_create 실패 정리와 nthreads 증감, self task 종료의 목록 임시 제거/재삽입,
   reaper 임시 참조와 동시 reference 획득을 모든 관련 caller에 연결한다.
   thread_deallocate의 stack_free 구간 splsched 반환 보존/splx 값도 별도 확인한다.
4. **PCB 사용자 상태와 FP**: U 앞 132바이트의 전체 writer/reader, U 할당 실패 도달성,
   child task+0x3c 객체+0x30 WORD의 실제 타입·소유자를 확인한다.
   FP_synch/pcb_synch, context 전환 및 CR0/FP owner writer와 하드웨어 소비를 연결한다.
   user-state 복사는 전체 FP/PCB 복제가 아니다.
5. **TSS/PC 소비자의 종료**: PCB 포인터를 지우기 전후 current-thread/TSS/LTR 소비,
   W+4 map 참조, PCdestroy와 callback in-flight 수명을 확인한다.
   task 참조를 먼저 내려놓는 순서나 queued timer 제거만으로 안전/위험을 확정하지 않는다.
6. **생성 ABI의 나머지 caller**: 이번 25개 직접 hit 중 선택 본문 밖 caller,
   간접 호출·함수 밖 entry·alias 경로를 확인한다. pmap_create의 하위 초기화와
   vm_map_create 이후 map/object의 전체 수명도 미완료다.

## 이전 미완료 유지

- Zone free-space 반환·coalescing·GC, metadata 재사용, hint/크기/정렬 불변식,
  busy wait/wakeup 및 VM backing 할당·초기값·오류 처리는
  [100차 목록](../continuous-review-20260913-100/OPEN_ITEMS.md)을 유지한다.
- I/O Ports Objective-C binding/권한/범위 ABI, bitmap 전파와 current-thread hold/release,
  LDT/GDT/IDT/IRETD/DF/FS/CR3/TLB, trap/copy recovery, PC exception continuation은 미완료다.
- 모든 함수와 함수 밖 code/data/undefined, 누락 entry/경계/ABI/타입,
  Ghidra 경고/IDA 실패, VM COW/shadow/pager/PV, VFS/UFS/NFS/RPC/XDR,
  IPC/MIG/BSD/network/DriverKit/kernserv/Objective-C 및 MMIO/DMA 전체 의미도 남아 있다.

다음 작업도 원본 OPENSTEP 분석으로만 제한한다. 외부 소스 참조, 복원·구현·빌드·포팅은
하지 않는다. 새 독립 계획 검토를 받지 않았다는 제한을 유지하며 이를 통과로 간주하지 않는다.

[이번 결과](README.md) · [검증 범위](SCOPE.md)
