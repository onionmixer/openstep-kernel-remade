# 남은 원본 분석

97차는 PC monitor/state/marker와 timer queue/worker, create/destroy의 지역 계약을 대조했다.
96차의 우선 소비자 본문 검토는 진전했지만 PC subsystem 전체나 원본 kernel 전체가
완료된 것은 아니다. 다음 항목을 구현으로 바꾸지 말고 원본에서 계속 분석한다.

## 다음 우선순위

1. **PC LDT/descriptor와 shared-state writer**.
   PCldt의 실제 callee task_locate_ldt `0x18d930`, task_default_ldt `0x18dac8`의
   원본 descriptor 변경·base/bound 단위·정렬·권한·실패 경로를 확인한다.
   M+0x30/0x34, M+0x38/0x3c, M+0x84 index 및 R active/enable/bitmap writer를 추적한다.
   shared mapping을 통해 사용자 측에서 바뀔 수 있는 상태의 안정성은 별도 전제다.
   다른 프로그램 소스/바이너리를 참조하지 않고 kernel 내부 증거의 한계를 기록한다.
2. **콜백 생존성과 초기화/승격 경로**.
   delayed→ready queue 이동, gate `0x1dfcbc` writer, worker 등록/생성/종료,
   예약 중복·timer callback 해제/재예약·IRQ/SMP·상위 caller 직렬화를 확인한다.
   Remove가 in-flight 종료를 기다리지 않는 지역 사실을 실제 use-after-free/안전 증명으로
   확대하지 않는다. PCdestroy 상위 PCB 파괴 경로와의 연결이 필요하다.
3. **PC allocation/mapping·error cleanup**.
   kmem_alloc_wired `0x173d1c`, pmap_enter_shared_range `0x190afc`, suser `0x108310`,
   map/copyout 실패 및 thread/port reference 계약을 확인한다.
   caller-map/target-thread 관계, allocator 초기화/실패 보장, PCB+0xec publish/해제와
   짧은 copy helper recovery slot의 수명을 전체 caller와 연결한다.
4. **예외 continuation 및 실제 state return**.
   exception_with_continuation `0x1568d8`의 stack 인자 소비·continuation 실행/취소,
   active T/S/M/R 동일성, R+0x54/0x58 변경자를 확인한다.
   AST/segment fault/TSS/IRETD/VM segment tail, CR0/FPU·stack reuse·중첩 trap이 남는다.

## 앞선 미완료 항목 유지

- **전체 C 의미 누락 ledger**: 이번 [한정된 누락 목록](DECOMPILER_ISSUES.md)은 출발점이다.
  96차 frame 초기화 누락/stack gap, 다른 배열·stack alias, 비표준 ABI, hardware effect,
  Ghidra 경고/IDA 실패를 커널 전체 범위에서 대조해야 한다.
- **recovery writer 완전성**: exact-literal 후보 검토와 alias-derived/절대주소/bulk/겹친 폭/
  함수 밖 writer 검토는 다르다. 이전 slot 중첩, 등록/해제 사이 trap, stale slot,
  EBP/ESP/DF/FS/ES 전제와 return 연결을 유지한다.
- **95차 문자열/uio/IPC 후속**: pathname/exec non-NUL 성공·fault count·cleanup,
  high-bit BYTE/segment 불변식, IPC high-bit size/할당·전체 caller·put capacity/cache/부분 write.
- **thread/IRQ/trap/VM 및 기존 I/O**: thread template/global 전환·scheduler/continuation,
  IDT/TSS/GDT/LDT/FS/ES/DF/RF/FPU/AST/signal/sigreturn, VM COW/shadow/pager/wait/wiring/
  rollback/PV/TLB/CR3, raw I/O vector/residual/DMA/정확히 한 번 완료/오류 전파와
  controller/Objective-C 조건은 미완료다.
- **전체 kernel 완료 기준**: 모든 함수와 함수 밖 code/data/undefined,
  누락 entry/경계/ABI/타입/loader/common/bss, scheduler·VM·VFS/UFS/NFS/RPC/XDR·
  IPC/MIG/BSD/network·DriverKit/kernserv/Objective-C를 일부 helper의 검증으로 대체하지 않는다.

안전한 원본 정적 분석은 계속 가능하다. 원본·DB·기존 export를 보존하고,
외부 코드를 사용하지 않으며 모든 계산은 Python으로 진행한다.
