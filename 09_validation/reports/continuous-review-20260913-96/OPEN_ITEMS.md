# 남은 원본 분석

96차는 남은 literal recovery store 36개의 지역 계약과 PC dispatcher/fragment 연결을 대조했다.
이는 원본 kernel 전체 분석 완료가 아니다. 다음 항목을 그대로 유지한다.

1. **다음 우선: PC monitor와 state 전이의 실제 소비자**.
   PCcallMonitor 0x1a1750, marker 인자 소비자 0x1a18c8/0x1a1918/0x1a1968,
   timers 0x1a1abc/0x1a1ad4, continuation 0x1a1514의 frame/return/수명/중첩 계약을 확인한다.
   PCexception이 page fault/monitor/exception return을 연결하는 전체 전제,
   descriptor base/bound와 M/R index/active/bitmap writer 및 dispatch table runtime 변경도 남는다.
2. **새로 확인한 C 누락과 원본 stack gap**.
   0x1a3160 C export의 frame 초기화 누락을 전체 decompiler 의미 누락 ledger에 연결한다.
   유사 frame/간접 stack alias에서 추가 누락이 있는지 원본으로 확인한다.
   CS WORD 위의 미초기화 gap은 실제 stack 초기값/간접 writer/도달성까지 증명된 것이 아니다.
   원본에 없는 초기화나 타입을 보충하거나 새 소스 구현으로 이동하지 않는다.
3. **recovery writer의 완전성**.
   94차 exact-literal 목록의 후보 검토와 별개로 alias-derived/절대주소/bulk/겹친 폭/
   함수 밖 writer, 이전 slot 중첩·등록/해제 사이 trap, stale slot과 EBP/ESP 보존을 추적한다.
   후보 0을 전체 writer 발견 완료로 세지 않는다.
4. **95차 문자열/uio/IPC 소비자 후속**.
   pathname/exec의 non-NUL 성공·fault count·cleanup, high-bit BYTE/segment 불변식,
   IPC get high-bit size/할당·전체 caller/간접 호출과 put length/capacity/cache/부분 write가 남는다.
5. **thread/IRQ/trap/VM 및 기존 I/O**.
   template·Unix/machine global 전환·continuation·stack reuse·IDT/TSS/GDT/LDT/FS/ES/DF/RF,
   allocator/PCB/FPU/AST/signal/sigreturn, COW/shadow/pager/wait/wiring/rollback/PV/TLB/CR3,
   raw I/O vector/residual/DMA/정확히 한 번 완료/오류 전파·controller/Objective-C 조건을 유지한다.
6. **전체 kernel 완료 기준**.
   모든 함수와 함수 밖 code/data/undefined, 누락 entry/경계/ABI/타입,
   Ghidra 경고/IDA 실패 독립 대조·전체 ledger·loader/common/bss,
   scheduler·VM·VFS/UFS/NFS/RPC/XDR·IPC/MIG/BSD/network·DriverKit/kernserv/Objective-C를
   특정 helper 검증으로 대체하지 않는다.

원본 정적 분석은 계속 가능하다. 외부 코드 참조 없이 신중하게 진행하며 계산은 Python으로 한다.
