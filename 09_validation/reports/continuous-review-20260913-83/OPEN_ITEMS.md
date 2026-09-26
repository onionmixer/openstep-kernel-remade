# 남은 OPENSTEP 원본 분석

83차는 상위 pager EAX 반환 소비, vmp_push의 page 상태와 object I/O 카운터,
원본 NFS/UFS I/O 및 NFS mapping을 검토했다. 원본 분석 전체 완료는 아직 증명되지 않았다.

1. **우선: buffer I/O 하위 계약**. breadDirect(0x119e00), bread(0x119b8c),
   breada(0x119c10), vnReadAhead(0x119d88), getblk(0x11a3e8), incore(0x11a394),
   brelse(0x11a288), bawrite(0x11a208), bdwrite(0x11a1e0)를 연결한다.
   size/residual/error WORD·flag의 일관성, direct byte count와 out-error, 0-progress,
   부분 copy·비동기/지연 write와 완료 오류 전파를 확인한다. filesystem callback의 반환 0을
   저장소 영속성으로 간주하지 않는다. NFS buffered 경로의 무 residual-clamp와
   error flag+error WORD 0 조합은 하위 invariant가 확인되기 전까지 조건부 분석이다.
2. **NFS/UFS 하위 상태**. rlock(0x12fc80), rlock_timeout(0x12fd1c), runlock(0x12fccc),
   nfs_validate_caches(0x12c204), bmap(0x13d830), mount block-size writer/검증,
   node+0x62 오류 writer/소비, credential reference 및 copy_to_phys/from_phys 계약.
   NFS read divisor masking·write divisor와 mapping signed stride가 어떤 허용 값에서
   일치하는지 검증한다. UFS 선증가 inode size와 NFS copy 후 크기 증가의 후속 오류도 남아 있다.
3. **상위 fault/pageout 전체 정책**. vm_fault(0x172038), vm_pageout_scan(0x179d44),
   FUN_0017bacc 및 mfs caller의 전체 잠금·오류·재시도 경로를 연결한다. 이번 caller window는
   EAX 소비만 증명하며 전체 ABI·경계/상태 검증이 아니다. object+0x44 WORD 증가/감소,
   object-event wait/wakeup, page 활성화·busy·mask 0x8과 object list next의 수명도 필요하다.
4. **sentinel·packed 기록·등록 종료**. 등록 개수·ID table capacity와 모든 writer,
   __bss 초기화, findpage sentinel lock/table 겹침의 실제 도달성, 기존 bitmap 선해제 후
   교체 실패와 array/child 게시 배타성은 미완료다. shutdown 선행 함수가 사용자를 모두
   중지시키는지와 descriptor/이름/credential 수명, file_init 오류의 참조 균형도 확인한다.
5. **기존 vnode/VM/pmap/native 잔여**. NFS/SPEC/UFS 생성·hash·free/reuse·inactive,
   inode truncation/속성/권한·disk geometry, COW/shadow/cache와 device pager,
   PTE/PV·PT/PD 재사용, managed region, lock/wait/scheduler/IRQ/context/fault/FPU,
   CR3/TLB/MMIO 분석은 이전 범위를 유지한다. register TEST와 C 메모리 재읽기 차이도 남는다.
6. **전역 완료 요건**. 함수 밖 code/data/undefined, 누락 entry·잘못된 경계·ABI/타입,
   Ghidra 경고와 IDA 실패 독립 대조, 전역 함수·경로 ledger, loader와 __common/__bss,
   IPC/MIG/BSD/VFS/network/DriverKit/kernserv/Objective-C 잔여를 계속 분석한다.

안전한 원본 분석이 가능하므로 전체 목표는 완료도 차단도 아니다.
외부 코드 참고, 구현·복원·빌드·포팅은 현재 범위 밖이다. 계산은 Python만 사용한다.
독립 계획 교차검토 미수신을 통과로 바꾸거나 실패한 요청을 재시도/우회하지 않는다.
