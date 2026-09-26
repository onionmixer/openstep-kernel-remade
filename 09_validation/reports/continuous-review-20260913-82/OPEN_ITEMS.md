# 남은 OPENSTEP 원본 분석

82차는 등록·종료 caller, mode별 실패 반환, transient WORD와 lock_done, backing
high-water truncate의 원본 본문을 연결했다. 아래 항목을 완료로 간주하지 않는다.

1. **우선: I/O 오류의 상위 소비자와 callback**. vm_pager_get(0x17a248),
   vm_pager_put(0x17a284), vm_pager_has_page(0x17a308), vmp_push(0x15fc58),
   vmp_push_all(0x15fe70)의 잠금·참조·오류 반환 후 정책을 확인한다.
   원본 vnodeops +0x74/+0x78 targets NFS 0x1338c0/0x133de4,
   UFS 0x145848/0x145bbc, FIFO 0x139444, SPEC 0x139b14의 실제 본문도 이어 검토한다.
   callback 오류 때 packed/bitmap/vm_info가 복구되는지, page 플래그·busy·absent·dirty와
   저장소 I/O가 어떤 관계인지 상위·하위 모두 연결한다.
2. **findpage sentinel 실제 도달성**. 등록 caller 본문에도 개수 상한은 없고,
   sentinel의 lock은 ID table[10..12]와 겹친다. 전역 등록 수 제한, table capacity,
   __bss 초기화와 실제 포인터 값, allocator hint·padding, 모든 ID writer 및 진입 조건은
   미완료다. 원본 분기와 주소 겹침을 실제 오류 발생으로 단정하지 않는다.
3. **종료·등록 오류의 수명**. unmount_all의 proc_shutdown/kill_tasks/cache clear/
   fd_shutdown/vm_object_shutdown을 연결해 실제 pager 사용 중지·잔여 참조를 확인한다.
   shutdown 본문은 ID table·descriptor·이름을 직접 지우거나 free하지 않지만 callee 효과와
   종료 전제는 아직 확인되지 않았다. file_init mount callback 오류 전 vnode/credential
   증가분과 mach_swapon의 한 번 vn_rele, lookup/credential context의 균형도 남아 있다.
4. **packed 기록 배타성·잠금**. 기존 bitmap 선해제 후 findpage 실패와 배열 확장 실패를
   구별하며, child pointer 게시→ID BYTE 초기화 간 배타성 및 기록 수명 보장을 검증한다.
   vget/vput의 WORD 증감과 pagein/pageout의 임시 참조만으로 전체 조회/I/O가 잠기는 것은
   아니다. has_page는 자체 임시 참조가 없다. lock_done의 wakeup은 내부 spin 해제 전에
   호출되므로 thread_wakeup_prim, sleep, wait queue·scheduler와 owner/recursive 계약을
   연결한다. register TEST 반복과 C 재읽기 차이도 native 분석 미해결로 유지한다.
5. **vnode/UFS 계약**. NFS hash/rfree/rinactive, SPEC hash·동등성 callback·재귀 생성,
   makespecvp sleep 재시도의 참조, UFS inode free/reuse·iinactive/itrunc/iupdat/iaccess,
   bread geometry/buffer·byte_swap layout, pn_get/lookuppn/suser/allocator 실패 계약은
   전체가 검증되지 않았다. 직접 store 범위 확인을 모든 callee 보존 증명으로 확대하지 않는다.
6. **VM/page/pmap/lock/native 잔여**. object+0x44 writer/wakeup, COW/shadow/cache 수명,
   device pager, PTE/PV 생성과 PT/PD 재사용, managed region/descriptor,
   queue/IRQ/context/fault/FPU/CR3/TLB/MMIO 항목은 이전 미완료 범위를 유지한다.
7. **전역 완료 요건**. 함수 밖 code/data/undefined, 잘못된 경계·누락 entry·ABI/타입,
   Ghidra 경고와 IDA 실패 독립 대조, 전역 함수·경로 ledger, loader와 __common/__bss,
   IPC/MIG/BSD/VFS/network/DriverKit/kernserv/Objective-C 잔여 분석을 계속한다.

안전한 원본 분석의 다음 단계가 있으므로 전체 목표는 완료도 차단도 아니다.
외부 코드 참고, 소스 복원·구현·빌드·다른 아키텍처 이식은 현재 범위 밖이다.
모든 계산은 Python으로 수행하고, 독립 교차검토 미수신을 검토 통과로 바꾸지 않는다.
