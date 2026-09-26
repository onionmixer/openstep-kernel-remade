# 남은 원본 분석

94차는 thread template 초기화/복사, 문맥 전환의 +0x74 기준 객체 구분,
실제 stack switch/IRETD, AST/sendsig의 지역 계약을 확인했다. 전체 목표는 미완료다.

1. **다음 우선: 나머지 recovery 주소 writer의 의미 검토**.
   이번 exact-offset survey의 code-pointer store 후보를 copyinmsg/copywithin/copyoutmsg,
   copystr/instr/outstr, fu/su, PC emulation 계열로 나누고 각 base를 원본으로 확인한다.
   정상·실패·길이0·부분 전송·중첩·이전 slot 저장/복원 및 recovery fragment의 프레임,
   alias-derived/절대주소/bulk/겹친 폭/함수 밖 writer 누락 여부를 추적한다.
   50개 후보를 전체 writer 또는 검토 완료 수치로 사용하지 않는다.
2. **thread/IRQ/복귀의 runtime 전제**.
   thread_init 실행 순서·template 간접 writer, context caller의 spl/IRQ exclusion,
   Unix/machine global 전환 일치성, continuation/call_continuation/stack_attach의 frame 폐기,
   saved PC/ESP/EBP writer, stack reuse·active/empty stack 상태와 중첩 trap을 확인한다.
   IDT/TSS/GDT/LDT/FS/ES/DF/RF·dbf·allocator/PCB 수명·AST/signal/sigreturn 전체가 남는다.
3. **VM fault와 wiring 전체 의미**.
   93차의 반환 계약을 넘어 COW/shadow/pager·busy/paging/ref/queue/lock 수명,
   nonzero wait_result writer·wirechange별 실제 도달성·retry·부분 wiring/rollback,
   relookup 경고와 alias, pmap/PV/TLB/PTE/CR3/PA/region 계약을 확인한다.
4. **기존 raw I/O·disk/controller 범위**.
   file/vnode/cdev 실제 연결, zero/multi-vector·segment·B residual/재사용,
   DMA 임시 버퍼와 부분 copy/완료 exactly-once·sleep/spl/wakeup/fspause,
   buffered writeback 오류 전파, ID/major/unit/maxTransfer writer/등록/worker/init,
   Objective-C fixup·geometry/inquiry·executeRequest/status/actual/sense/CDB 조건을 유지한다.
5. **원본 kernel 전체 완료 기준**.
   모든 함수/함수 밖 code/data/undefined·누락 entry/경계/ABI/타입,
   Ghidra 경고/IDA 실패 독립 대조·전체 ledger·loader/common/bss·scheduler/IRQ/context/FPU,
   VM·VFS/UFS/NFS/RPC/XDR·IPC/MIG/BSD/network·DriverKit/kernserv/Objective-C를 축소하지 않는다.

원본 정적 분석은 계속 가능하다. 외부 코드로 공백을 메우거나 구현 단계로 이동하지 않는다.
계산은 Python, 편집은 apply_patch만 사용한다. 새 교차검토 미수신은 통과가 아니다.
