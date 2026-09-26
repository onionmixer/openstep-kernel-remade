# 남은 원본 분석

98차는 task LDT setter·LLDT 소비자와 task/thread hold-wait-release의 지역 의미를 확인했다.
기존 ASM에서 발견한 LLDT 본문 검토는 진전했지만 전체 원본 분석 완료가 아니다.

## 다음에 연결할 원본 경로

1. **Task machine state 생성과 I/O bitmap writer**.
   K=[task+0x40]의 초기화·수명·복제/종료, PCB 초기화 `0x18d520/0x18d5c4`,
   `0x18d610` 및 task_map_io_ports `0x18d7d4`와 bootstrap의 K+8/+0xc 소비를 연결한다.
   TSS resize의 할당 오류/덧셈 wrap, TSS+0x66 offset·길이·sentinel, 이전 allocation 해제와
   LTR/bitmap 접근을 확인한다. 선택 본문 전체 raw decode를 callee 계약 완료로 바꾸지 않는다.
2. **LDT 지역 검사의 실제 전제와 동시성**.
   PCldt의 권한/suser/object_copyin, 실제 map bounds/허용 size·정렬,
   base/size가 같을 때 내용 변경, bootstrap base-only 비교의 writer 불변식,
   _gdt/_ldt/selector/GDTR runtime writer, alias/bulk/함수 밖 LLDT를 확인한다.
   wrapped 주소·0 size·limit truncation의 산식 반례는 아직 native 재현/도달성 증거가 아니다.
3. **Hold/wait/release와 reader lock 계약**.
   lock_write/read/done(K+0x10), task list mutation/reference/PCB 수명,
   현재 thread가 제외되는 hold/wait와 전체 release의 상위 균형,
   task/thread inactive 변화, rem_runq/thread_sleep/wakeup/scheduler/IRQ를 확인한다.
   caller와 상위 hold count를 확인하지 않고 underflow/안전성을 단정하지 않는다.
4. **PC shared-state writer**.
   M(PC shared state)는 이번 K(task machine state)와 다르다.
   M+0x30/0x34, M+0x38/0x3c, M+0x84와 R active/enable/bitmap writer,
   shared mapping 변경·index 안정성과 descriptor 읽기의 full-byte bounds가 계속 남는다.

## 97차 및 이전의 미완료 항목 유지

- **Callout 수명**: delayed→ready 승격, gate 0x1dfcbc 초기화/변경,
  worker 생성·종료, 예약 중복·해제/재예약·IRQ/SMP, PCdestroy 상위 파괴 계약.
  queued remove를 in-flight 완료 대기로 해석하지 않는다.
- **PC 생성/오류**: kmem_alloc_wired 0x173d1c, pmap_enter_shared_range 0x190afc,
  caller-map/target-thread, allocator 초기화/실패, copyout 이후 cleanup,
  port/thread ref와 PCB+0xec publish/해제, 짧은 copy recovery slot.
- **Exception/return**: exception_with_continuation 0x1568d8의 실제 인자 소비·실행/취소,
  active T/S/M/R 동일성, R+0x54/+0x58 writer, AST/segment fault/TSS/IRETD/VM tail,
  CR0/FPU·stack reuse·중첩 trap.
- **전체 의미 누락 목록**: [이번 추가 목록](DECOMPILER_ISSUES.md)과 앞선 frame 초기화/
  stack gap/ABI/hardware effect 관찰을 전체 Ghidra 경고/IDA 실패와 연결한다.
- **Recovery 및 앞선 I/O**: alias/절대주소/bulk/겹친 폭/함수 밖 writer,
  stale slot·EBP/ESP/DF/FS/ES, pathname/exec non-NUL·fault count/cleanup,
  uio high-bit BYTE/segment, IPC size/할당/caller/put capacity/cache/부분 write,
  raw I/O vector/residual/DMA/정확히 한 번 완료/오류 전파.
- **전체 kernel**: 모든 함수/함수 밖 code/data/undefined, 누락 entry/경계/ABI/타입/
  loader/common/bss, scheduler/VM COW/shadow/pager/wait/wiring/PV/TLB/CR3,
  VFS/UFS/NFS/RPC/XDR/IPC/MIG/BSD/network/DriverKit/kernserv/Objective-C를
  이번 한정된 검증으로 대체하지 않는다.

원본 정적 분석을 계속 진행할 수 있다. 외부 코드 참조·소스 복원·구현·빌드·포팅은 하지 않는다.
원본과 DB/export를 보존하며 계산은 모두 Python으로 한다.
