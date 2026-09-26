# 106차 이후 남은 원본 분석

이번 106차에서 기존 우선순위 1의 선택 VM 계약과 우선순위 2의 지정 recursive-lock 직접
caller는 원본 명령 기준으로 확인했다. 아래 항목은 그 완료 판정을 확장하지 않는다.

1. page/object/map/pmap의 간접 호출·주소 table·alias writer와 runtime initializer를
   추적한다. 특히 page size/shift, template, object `+0x30`, map entry WORD `+0x28`의
   runtime 값·경계와 실제 수명을 별도로 검토한다.
2. VM COW/shadow/pager/PV, `vm_fault` 전체의 오류 전파, copy/map fork와 deallocate의
   caller-wide rollback·잠금 순서를 원본으로 확대한다.
3. IRQ/pending callback writer, SPL level/mask/재진입과 lock register-spin의 실제
   진행성을 검토한다.
4. stack cache/waiter/reserve, scheduler priority/runq/processor/idle/binding, AST/IPC/
   thread/task 종료와 callback/map 수명을 분석한다.
5. 최초 context, GDT/LDT/TSS/CR3/TLB/CR0/FPU/continuation, VFS/UFS/NFS/RPC/XDR,
   IPC/MIG/BSD/network, DriverKit/kernserv/ObjC/MMIO/DMA 및 전체 함수 경계·ABI·경고·
   decompiler 실패 항목은 여전히 미완료다.

다음 단계도 원본 OPENSTEP x86만 사용하고, 모든 계산은 Python으로 하며, 구현·복원·빌드·
포팅으로 확대하지 않는다.
