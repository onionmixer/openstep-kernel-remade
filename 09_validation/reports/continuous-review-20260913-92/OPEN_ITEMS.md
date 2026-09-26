# 남은 OPENSTEP 원본 분석

92차는 map count의 선행 변경, fast wiring의 지역 undo와 일반 fault 반환 무시,
copy 짧은 경로의 복구 슬롯 잔존 및 복구 조각을 확인했다. 전체 목표는 미완료다.

1. **다음 우선: 일반 VM fault와 copy 복구의 실제 연결**.
   vm_fault `0x172038`의 실패/재시도/잠금·busy·paging 상태·wiring 변화를 추적하고,
   vm_fault_wire의 반환 무시 뒤 부분 성공/rollback이 어떤 원본 경로로 이어지는지 확인한다.
   thread +0x74의 실제 trap consumer·saved EBP/ESP·복귀·RF/DF/FS/ES 전제,
   짧은 copy 정상 반환 뒤 슬롯 잔존·중첩 copy·문맥 전환, 부분 복사와 sd 오류 전달을 대조한다.
2. **map/page/object 수명과 물리 매핑**.
   map 범위 clamp·빈 구간 split·구간 hole, entry/page WORD count 상한,
   kernel_map unlocked 순회와 비-kernel recursive/read lock의 실제 exclusion,
   object allocate/reference/shadow/deallocate, vm_page_lookup/wire/queue,
   pmap_enter `0x19065c`와 helper `0x19108c/0x1910e4`, region/PA coverage,
   PTE·TLB·PV·CR3·page-size 안정성·page flag writer를 확인한다.
3. **raw I/O·벡터·완료와 장치 상태**.
   실제 file/vnode/cdev/major 연결, count 0/선두 길이 0·여러 vector의 segment 변경,
   단위별 B 생성/재사용과 residual, DMA alignment·임시 버퍼 lifetime,
   sleep/spl/wakeup·exactly-once 완료·비동기 flag, fspause 문맥 writer·재호출,
   buffered spec copy 실패 뒤 writeback·오류·부분 갱신을 유지한다.
4. **디스크/controller 등록과 실제 전송**.
   ID 표/partition/행 WORD와 전역 unit/major/maxTransfer writer, super 등록·volCheckRegister,
   초기 worker와 늦은 IODisk init, directDevice/class/category/fixup,
   inquiry/geometry/ready/name, executeRequest/DMA/status/actual/sense writer와 CDB count 전제가 남는다.
5. **전체 원본 분석 요건**.
   함수 밖 code/data/undefined·누락 entry·경계·ABI/타입, Ghidra 경고/IDA 실패 독립 대조,
   전역 함수·경로 ledger, loader/__common/__bss·scheduler/IRQ/context/fault/FPU,
   VM COW/shadow/pager·VFS/UFS/NFS/RPC/XDR·IPC/MIG/BSD/network/DriverKit/kernserv/Objective-C
   잔여 범위를 축소하지 않는다.

원본 정적 분석이 계속 가능하다. 외부 코드로 공백을 메우거나 구현 단계로 넘어가지 않는다.
계산은 Python만, 편집은 apply_patch만 사용한다. 교차검토 미수신은 통과가 아니며
실패 요청을 재시도·우회하지 않는다. 현재 전체 목표는 완료도 차단도 아니다.
