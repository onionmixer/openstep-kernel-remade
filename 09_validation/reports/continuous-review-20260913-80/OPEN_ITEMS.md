# 남은 OPENSTEP 원본 분석

80차는 vattr_null 초기화 범위, 이름 있는 표의 속성/마지막 참조 대상 본문과 pager
생성·선택·초기화를 연결했다. 기존 79차의 전체 미해결 목록을 없애지 않으며 다음을 잇는다.

1. **실제 vnodeops 설치와 내부 vnode 포인터 관계**: 0x12f5ee, 0x139512, 0x13969d,
   0x1397e3, 0x140626, 0x1408f2의 저장 base+0x20/+0x28과 caller가 읽는 vnode+0x1c의
   연결을 생성 함수 전체에서 검증한다. spec_setattr 재위임 대상, descriptor 등록·제거,
   표의 다른 writer·이름 없는 표를 확인한다. 17개 export 참조로 전역 writer 집합을 닫지 않는다.
2. **pager packed 기록 writer와 child 배열**: count 변경/확장, 2단 child 할당과
   마지막 블록 padding의 BYTE ID 초기화, ID/bitmap/집계 table 범위 및 직렬화,
   모든 reader의 ID=0 gate와 중복 해제 방지. vnode_alloc의 pointer-array 초기화만으로
   자식 슬롯 초기화는 증명되지 않는다. 79차 high-water 검색 실패 도달성도 남아 있다.
3. **UFS/NFS/SPEC 실제 정리·변경 하위 계약**: iinactive(0x140da0), itrunc(0x141014),
   iupdat(0x140eb4), iaccess(0x141f44), suser(0x108310), spec_fsync(0x13a384),
   sunsave(0x139894), mfs_trunc(0x15e534), mfs_fsync(0x15f638), sync_vp(0x1337d0),
   rfree(0x12f844), rfscall(0x12eef4)의 원본 wait·오류·객체 수명·context 계약.
   NFS의 RPC 전 크기 기록과 후속 회복, SPEC의 proc bit clear에 필요한 호출 전제를 확인한다.
4. **pager 생성 호출자와 수명**: vnode_pager_setup 후단 zalloc/zfree의 allocator 계약,
   이미 pager가 있을 때 cache 인자 생략의 호출자 전제, 실패 전 vnode flag 변경,
   WORD 참조 overflow 도달성·모든 참조 writer와 외부 lock. device pager 생성과
   metadata allocation/page-list 반환 대상의 일치도 79차에서 이어 남아 있다.
5. **VM object/page/pmap**: object+0x44 증감/wakeup, +0x20/+0x1c shadow/copy/COW,
   cache snapshot-unlock-lookup 수명, hash insert/중복, 종료 배타성, PTE/PV 생성·변경,
   PT/PD backing 재사용·반환, managed span/region/descriptor 일치와 page flag writer.
   pmap_clear_reference/is_modified 및 unwire 하위 직접 함수도 남아 있다.
6. **lock·대기·native 경계**: lock_done/owner/재귀/wait flag writer,
   thread_block_with_continuation/wakeup/IRQ/scheduler/context, 관측한 register spin과
   실제 진행성·fault 복구. 정적 읽기로 native 동시성의 완전성을 주장하지 않는다.
7. **전역 완료 요건**: loader/초기 entry/__common clearing, 함수 밖 코드/data/undefined,
   함수 경계·ABI/타입, Ghidra 경고 및 IDA 실패의 독립 대조, 전역 함수·경로 ledger와
   IPC/MIG/BSD/VFS/UFS/network/DriverKit/kernserv/Objective-C, MMIO/FPU/fault의 잔여 경로.

원본 분석이 계속 가능하다. 전체 목표는 완료도 차단도 아니다.
다른 코드 참고·커널 구현·소스 복원·빌드·아키텍처 이식은 수행하지 않는다.
