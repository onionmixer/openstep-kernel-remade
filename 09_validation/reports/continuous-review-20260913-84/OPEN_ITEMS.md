# 남은 OPENSTEP 원본 분석

84차는 buffer read/write 제출, 완료·대기·오류 변환과 반환 목록, stack header 및 vnode
결합의 지역 계약을 검토했다. 원본 분석 전체 완료는 아직 증명되지 않았다.

1. **우선: 실제 strategy와 buffer 재사용**. 원본 vnodeops `+0x54`의 NFS `0x133130`,
   UFS `0x1455ec`, SPEC `0x13a568`, FIFO `0x139444`를 연결한다. getnewbuf `0x11a924`,
   brealloc `0x11a5e4`, bfree `0x1934d8`의 초기화·크기·NULL/재시도 및 free-list 소유권을
   확인한다. 모든 error flag/WORD·residual writer, done/callback/async mask 변경,
   실제 biodone 도달과 callback `B+0x30` 책임, 동기 완료 뒤 post-strategy `0x80` 저장,
   release 뒤 error/residual 재읽기의 수명을 검증한다.
2. **direct stack header와 원본 실행 배타성**. `EBP-0x44`의 부분 초기화 header가 hash에
   게시되는 동안 동일 vnode/block의 incore/getblk 진입, busy `0x8`이 없는 초기 상태,
   free-list 미초기화 필드 소비, `0x2000001` flags의 하위 의미 및 page_size 요청을 확인한다.
   size/copyLength/residual의 허용 관계와 0-progress·signed 음수 결과 도달성을 검증한다.
   brelse 메모리 TEST와 biodone AL snapshot TEST의 실제 동등 조건 및 IRQ/wakeup을 확인한다.
3. **NFS/UFS 하위 상태**. rlock `0x12fc80`, rlock_timeout `0x12fd1c`, runlock `0x12fccc`,
   nfs_validate_caches `0x12c204`, bmap `0x13d830`, mount block-size writer/검증,
   node `+0x62` 오류 writer/소비, credential reference와 copy_to_phys/from_phys 계약이 남아 있다.
   geterror는 buffer error WORD를 보정하지 않으므로 NFS buffered read의 error flag+WORD 0
   조건은 아직 해소되지 않았다. UFS size 선증가와 NFS copy 후 size 증가의 후속 오류도 남는다.
4. **상위 fault/pageout 전체 정책**. vm_fault `0x172038`, vm_pageout_scan `0x179d44`,
   FUN_0017bacc와 mfs caller의 전체 잠금·오류·재시도 경로를 잇는다. 이전 caller window는
   반환 소비만 증명했다. object `+0x44` WORD와 object-event wait/wakeup, page 활성화·busy·
   mask `0x8`, I/O 뒤 object list next 수명도 미완료다.
5. **sentinel·packed 기록·등록 종료**. 등록 개수·ID table capacity/모든 writer,
   __bss 초기화, findpage sentinel lock/table 겹침의 실제 도달성, bitmap 선해제 후 교체 실패,
   array/child 게시 배타성, shutdown 선행 quiescence, descriptor/이름/credential 수명,
   file_init 오류 참조 균형을 계속 확인한다.
6. **기존 vnode/VM/pmap/native 잔여**. NFS/SPEC/UFS 생성·hash·free/reuse·inactive,
   inode truncation/속성/권한·disk geometry, COW/shadow/cache 및 device pager,
   PTE/PV·PT/PD 재사용, managed region, lock/wait/scheduler/IRQ/context/fault/FPU,
   CR3/TLB/MMIO 범위를 유지한다. register TEST와 C의 재읽기 차이도 미완료 항목이다.
7. **전역 완료 요건**. 함수 밖 code/data/undefined, 누락 entry·잘못된 경계·ABI/타입,
   Ghidra 경고와 IDA 실패 독립 대조, 전역 함수·경로 ledger, loader와 __common/__bss,
   IPC/MIG/BSD/VFS/network/DriverKit/kernserv/Objective-C 잔여를 계속 분석한다.

다른 프로젝트 코드·로컬 참고 소스는 열지 않는다. 구현·복원·빌드·포팅은 현재 범위 밖이다.
모든 계산은 Python만 사용한다. 독립 계획 교차검토 미수신을 통과로 바꾸거나 실패한 요청을
재시도·우회하지 않는다. 안전한 원본 분석이 가능하므로 전체 목표는 완료도 차단도 아니다.
