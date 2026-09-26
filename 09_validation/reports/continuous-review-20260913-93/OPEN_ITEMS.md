# 남은 원본 분석 — 범위 축소 없음

93차는 복구 슬롯의 실제 소비자와 일반 trap 저장/복귀 프레임, JMP/CALL 참조 분류 차이,
VM fault의 반환 경로 부분을 확인했다. 전체 원본 분석은 미완료다.

1. **다음 우선: recovery slot의 전체 writer·수명과 진입 계약**.
   thread +0x74의 초기화·소멸·문맥 전환·중첩 copy·다른 writer를 원본에서 추적한다.
   짧은 copy 뒤 슬롯 잔존에서 실제 후속 fault/복구 조각의 EBP/ESP 전제까지 연결한다.
   각 trap stub의 push/error 계약, IDT/TSS/descriptor 초기화와 실제 kernel/user 경계,
   scheduler/IRQ 및 active_threads/empty_stacks 안정성, DF/FS/ES/RF와 debug 처리,
   dbf_handler caller·loop·state 및 thread_exception_return의 native 계약이 남는다.
2. **일반 VM fault 전체 의미**.
   COW/shadow/pager와 page/object/map의 busy/paging/ref/queue/lock 수명 전이를 계속 분석한다.
   반환0의 대기 종료가 실제로 가능한 wait_result writer와 wirechange별 조건,
   relookup/restart/할당 실패/부분 wiring·rollback, 경고 0x1731e5의 전체 CFG/alias 조건,
   pmap_enter 및 helper 0x19108c/0x1910e4, PV/TLB/PTE/CR3/PA/region 전제를 확인한다.
3. **기존 wiring·raw I/O 미완료**.
   빈 구간 split/hole·entry/page WORD count 상한·kernel_map unlocked 순회·recursive/read exclusion,
   실제 file/vnode/cdev 연결, zero/multi-vector·segment·B residual 초기화/재사용,
   DMA 임시 버퍼 수명과 부분 복사, sleep/spl/wakeup/완료 exactly-once,
   fspause writer/retry 및 buffered writeback의 오류 전파를 유지한다.
4. **디스크/controller 실제 동작**.
   ID table/partition/unit/major/maxTransfer writer와 등록, worker/init 순서,
   directDevice/class/category/fixup, geometry/ready/inquiry/name,
   executeRequest/DMA/status/actual/sense writer와 CDB count 전제가 남는다.
5. **kernel 전체 분석 요구**.
   모든 함수와 함수 밖 code/data/undefined·누락 entry·경계·ABI/타입,
   Ghidra 경고/IDA 실패 독립 대조, 전역 함수·경로 ledger,
   loader/common/bss·scheduler/IRQ/context/FPU·VM·VFS/UFS/NFS/RPC/XDR·IPC/MIG/BSD/network·
   DriverKit/kernserv/Objective-C의 미검토 범위를 완료 기준에서 제거하지 않는다.

외부 코드로 공백을 채우거나 구현 단계로 넘어가지 않는다. 원본 정적 분석을 계속할 수 있다.
계산은 Python, 편집은 apply_patch만 사용한다. 새 교차검토 미수신을 통과로 취급하지 않는다.
