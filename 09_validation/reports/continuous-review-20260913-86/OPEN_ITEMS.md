# 남은 OPENSTEP 원본 분석

86차는 disk 제출과 uio/copy/PTE 이동의 지역 계약 및 selector 후보를 연결했다.
전체 원본 분석 완료는 아직 증명되지 않았다.

1. **다음 우선: disk class와 실제 비동기 완료**. 원본 `__inst_meth` 후보
   blockSize `0x1a5724`, readAsync `0x1a5e9c`/`0x1a6e64`/`0x1ac7fc`,
   writeAsync `0x1a5f74`/`0x1a6f34`/`0x1ac85c`, errnoFromReturn
   `0x1a4a20`/`0x1a5d60`/`0x1a9568`의 소유 class·superclass와 실제 객체 생성/등록을 연결한다.
   disk lookup table `0x1e7324`/control `0x1e7564` writer, pending B의 수명,
   client map과 data 주소 변환, 완료 callback/error WORD/residual/biodone 도달을 확인한다.
   objc lookup/cache helper `0x1cd868` 및 category/동적 등록 때문에 정적 후보만으로
   실제 dispatch를 확정하지 않는다.
2. **copy fault 및 native 주소 공간**. uiomove 값 1의 copywithin 오류 미검사와 필드 진척,
   invalid space와 iovec 개수/remaining 조건, 짧은 copy의 recovery slot 잔존,
   fragment에서 부모 epilogue로 이어지는 native trap/frame/EBP/DF/FS 계약을 확인한다.
   stack breadDirect의 physical 주소가 kernel map·copywithin·RPC/bzero에서 유효한 선형 주소인지
   별도 mapping 근거가 필요하다. 부분 복사 후 오류와 상위 UFS write 제출도 함께 검증한다.
3. **pagemove와 buffer allocator 전제**. fixed `0x1000` 이동, page_size 초기화,
   PDE/PTE present와 NULL pointer 배제, src/dst 비중첩·정렬·빈 destination,
   kernel_pmap/CR3 활성 상태·다른 CPU TLB 및 PV/dirty/ref 회계를 확인한다.
   allocbuf donor/reuse와 brealloc bucket 한정 overlap에 필요한 geometry/크기 invariant,
   release 뒤 필드/next 접근, stack hash 게시 배타성도 미완료다.
4. **NFS wire와 daemon 도달성**. RFScall `0x12eef4`, XDR read/write와 count bounds,
   mount chunk writer, set_label `0x186f88` 비지역 복귀 및 `0x1e59ec`/`0x1e59e8` writer,
   queue 배타성을 분석한다. daemon의 flag-only 오류 분기는 존재하지만 native 도달성과
   당시 error WORD/residual은 미확인이다. worker -98 예외와 sticky 오류 소비도 남아 있다.
5. **NFS/UFS·상위 VM·등록 종료**. bmap, cache invalidation/uncache, credential 및
   rlock/runlock, UFS size 선증가·부분 성공·uerror, vm_fault/pageout/mfs 전체 정책,
   object/page event 수명, pager ID capacity/sentinel/bitmap/게시와 shutdown 참조 균형을 유지한다.
6. **전역 원본 분석 요건**. vnode hash/reuse/inactive, COW/shadow/cache/device pager,
   pmap/PV/PT/PD·managed region, scheduler/IRQ/context/fault/FPU/CR3/TLB/MMIO,
   함수 밖 code/data/undefined와 누락 entry·경계·ABI/타입, Ghidra 경고/IDA 실패 독립 대조,
   전역 함수·경로 ledger, loader/__common/__bss 및 IPC/MIG/BSD/VFS/network/
   DriverKit/kernserv/Objective-C 잔여 범위를 축소하지 않는다.

다른 코드는 참고하지 않는다. 구현·복원·빌드·포팅 및 동적 실행은 이번 원본 분석 범위 밖이다.
계산은 Python만, 변경은 apply_patch만 사용한다. 독립 계획 교차검토 미수신을 통과로
바꾸거나 실패 요청을 재시도·우회하지 않는다. 의미 있는 분석이 가능하므로 전체 목표는
완료도 차단도 아니다.
