# 남은 OPENSTEP 원본 분석

85차는 strategy/worker/daemon 및 buffer 재사용의 지역 계약을 확정했다.
전체 원본 분석 완료는 여전히 증명되지 않았다.

1. **다음 우선: 실제 장치와 데이터 이동**. 정적 bdevsw의 sdstrategy `0x183920`,
   pagemove `0x193e58`, uiomove `0x10a384`를 연결한다. 장치 등록과 table writer,
   허용 major 및 nodev 진입 배제, biodone/callback 도달, error/residual bounds를 확인한다.
   stack breadDirect가 넘기는 physical 주소와 NFS RPC/bzero 및 UFS local U의 `+0xc=1`을
   사용하는 주소 공간 계약도 닫아야 한다. 필요한 경우 원본 xdr_readargs `0x1344b0`,
   xdr_rdresult `0x134518`, xdr_writeargs `0x134154`, xdr_attrstat `0x13454c`,
   rfscall `0x12eef4`와 mount chunk 크기 writer를 잇는다.
2. **NFS 오류 writer와 queue/native 도달성**. async_daemon `0x1331cc`의 set_label
   `0x186f88` 비지역 복귀, globals `0x1e59ec`/`0x1e59e8`의 모든 writer,
   queue `0x1ef174`의 배타성을 확인한다. counter-zero 종료는 flag만 설정하고 WORD/residual을
   쓰지 않는 실제 분기지만 native 진입과 당시 0 WORD 여부는 아직 증명하지 않았다.
   NFS worker 성공 short-read의 bzero 및 -98 합성 상태, WORD 절삭과 상태 -98 예외,
   async write의 node `+0x62` 게시/clear가 모든 상위 소비자와 일치하는지도 필요하다.
3. **buffer geometry·재사용·수명**. brealloc의 시작 bucket 한정 overlap 검사에 필요한
   정렬/최대 크기, geometry D의 0/음수와 writer, allocbuf의 page_size/요청 상한,
   donor list/진척과 pagemove, release 뒤 hash next 및 error/residual 재읽기를 확인한다.
   stack header가 hash에 게시되는 동안 동일 key getblk 진입 배제, 미초기화 필드 소비,
   busy/async/callback flags 변환과 post-strategy age 저장의 수명은 미완료다.
4. **NFS/UFS 추가 계약**. rlock `0x12fc80`, rlock_timeout `0x12fd1c`, runlock `0x12fccc`,
   nfs_validate_caches `0x12c204`, bmap `0x13d830`, credential 참조, vnode_uncache,
   btrash와 캐시 무효화, UFS size 선증가와 오류·부분 성공·uerror의 정리가 남아 있다.
   85차 rwip의 negative mapping+uerror 0, residual clamp와 copy 실패 후 write 제출의
   실제 도달성은 하위 함수/입력 invariant와 함께 검증해야 한다.
5. **상위 fault/pageout 및 등록 종료**. vm_fault `0x172038`, vm_pageout_scan `0x179d44`,
   FUN_0017bacc/mfs caller의 전체 잠금·오류·재시도, object `+0x44`/page 상태/event 수명,
   pager 등록 capacity와 ID table writer, sentinel 겹침·bitmap 선해제와 실패,
   array/child 게시, shutdown quiescence와 참조 균형은 유지한다.
6. **기존 vnode/VM/pmap/native 잔여**. vnode 생성·hash·reuse·inactive,
   inode truncation/속성/권한·disk geometry, COW/shadow/cache/device pager,
   PTE/PV·PT/PD reuse, managed region, lock/wait/scheduler/IRQ/context/fault/FPU,
   CR3/TLB/MMIO 및 메모리 재읽기와 register TEST 차이를 계속 검증한다.
7. **전역 완료 요건**. 함수 밖 code/data/undefined, 누락 entry·함수 경계·ABI/타입,
   Ghidra 경고와 IDA 실패 독립 대조, 전역 함수·경로 ledger, loader와 __common/__bss,
   IPC/MIG/BSD/VFS/network/DriverKit/kernserv/Objective-C 잔여는 축소하지 않는다.

원본 및 원본에서 나온 자료만 사용한다. 다른 코드 참고, 구현·복원·빌드·포팅은 범위 밖이다.
계산은 Python만 사용하고 DB/원본 및 기존 확정 보고서를 변경하지 않는다.
독립 계획 교차검토 미수신을 통과로 바꾸거나 실패한 요청을 재시도·우회하지 않는다.
의미 있는 원본 분석이 가능하므로 전체 목표는 완료도 차단도 아니다.
