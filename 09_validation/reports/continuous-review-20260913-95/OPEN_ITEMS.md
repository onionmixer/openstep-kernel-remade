# 남은 원본 분석

95차는 비-PC copy/string/fu/su helper와 복구 fragment, pathname/byte-uio/message
직접 소비자의 지역 반환 계약을 확인했다. 원본 전체 분석은 미완료다.

1. **다음 우선: PC emulation recovery writer 후보 36개**.
   94차 exact-literal 목록에서 남은 각 base가 thread인지 원본으로 추적하고,
   recovery target/정상 clear/이전 값 복원/부분 변경/재시도/호출 중첩과 fragment frame을 확인한다.
   후보 수를 전체 writer 또는 함수 수로 바꾸어 보고하지 않는다.
   별도로 alias-derived/절대주소/bulk/겹친 폭/함수 밖 writer의 누락 가능성을 유지한다.
2. **이번 소비자에서 이어지는 호출 계약**.
   pn_get/pn_set의 non-NUL 성공 후 pathname/exec 소비, copy fault의 count/객체 cleanup,
   uwritec high-bit BYTE와 ureadc invalid-segment의 실제 caller 허용 조건을 검토한다.
   ipc_kmsg_get high-bit size/할당 산술, get caller의 전체 CFG/간접 참조,
   ipc_kmsg_put length/capacity/부분 복사/cache 소유권 및 IPC/MIG 오류 경로가 남는다.
   지역적으로 가능한 인자를 native 도달 인자로 간주하지 않는다.
3. **thread/IRQ/trap/복귀의 runtime 전제**.
   template 초기화 실행 순서·간접 writer, Unix/machine globals의 전환 일치성,
   continuation/call_continuation/stack_attach의 프레임 폐기, saved PC/ESP/EBP writer,
   stack reuse·active/empty stack·중첩 trap, IDT/TSS/GDT/LDT/FS/ES/DF/RF,
   dbf/allocator/PCB 수명·AST/signal/sigreturn 전체를 확인해야 한다.
4. **VM fault와 wiring 전체 의미**.
   COW/shadow/pager·busy/paging/ref/queue/lock 수명, nonzero wait_result writer,
   wirechange별 실제 도달성·retry·부분 wiring/rollback, relookup 경고와 alias,
   pmap/PV/TLB/PTE/CR3/PA/region 계약을 유지한다.
5. **기존 raw I/O·disk/controller 범위**.
   file/vnode/cdev 연결, zero/multi-vector·segment·residual/재사용,
   DMA 임시 버퍼·부분 copy·완료 exactly-once·sleep/spl/wakeup/fspause,
   buffered writeback 오류, ID/major/unit/maxTransfer writer/등록/worker/init,
   Objective-C fixup·geometry/inquiry·executeRequest/status/actual/sense/CDB 조건이 남는다.
6. **원본 kernel 전체 완료 기준**.
   모든 함수/함수 밖 code/data/undefined·누락 entry/경계/ABI/타입,
   Ghidra 경고/IDA 실패 독립 대조·전체 ledger·loader/common/bss·scheduler/IRQ/context/FPU,
   VM·VFS/UFS/NFS/RPC/XDR·IPC/MIG/BSD/network·DriverKit/kernserv/Objective-C를 축소하지 않는다.

정적 분석은 계속 가능하다. 외부 코드 참조·복원·구현·빌드로 넘어가지 않는다.
계산은 Python, 편집은 apply_patch만 사용한다. 교차검토 미수신을 성공으로 처리하지 않는다.
