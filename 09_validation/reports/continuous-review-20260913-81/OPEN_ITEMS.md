# 남은 OPENSTEP 원본 분석

81차는 내부 vnode offset과 선택 생성/검색 경로를 확인하고, child 전체 ID BYTE 초기화를
직접 writer에서 연결했다. 아래 항목은 미완료이며 전체 목표를 계속 유지한다.

1. **우선: findpage sentinel 경로의 실제 전제**. 0x17cc14→0x17cc19→0x17cb00은 다음
   노드가 sentinel이어도 시작 노드가 아니면 descriptor lock/free 검사로 들어간다.
   sentinel+0x18/+0x34가 ID table[3]/[10]과 겹친다. 등록 caller/상한, ID table capacity,
   vnode_pager_shutdown·descriptor 제거, __bss 초기화, lock_write/lock_done 동작을 연결해
   실제 도달성·상태를 검증한다. 원본 제어 흐름을 확인했을 뿐 native 오류로 판정하지 않았다.
2. **packed 기록 교체의 실패·배타성**. FUN_0017cd58은 기존 bitmap을 먼저 해제하고
   findpage 성공 후 packed 기록을 덮는다. mode caller, 실패 후 caller 정리, 동시 할당자,
   child pointer 게시→ID 초기화 사이 배타성을 확인한다. vnode_pager_truncate와 다른
   count/packed/bitmap/high-water writer, ID 범위·index 폭·중복 해제 방지도 남아 있다.
3. **등록 오류의 참조/context 정리**. vnode_pager_file_init의 getter 결과 무검사,
   vnode/credential 증가 후 mount callback 오류 경로를 실제 target/caller와 대조한다.
   최대/최소 크기, bitmap padding·hint 불변식, page_size 상태와 등록 수 제한도 필요하다.
4. **vnode 전체 설치·재사용·참조 수명**. 원본 B→V 관계는 선택 경로에서 확인했지만
   NFS hash 삽입/제거·rfree/rinactive, SPEC hash 삽입/제거·ops+0x6c 동등성/장치 callback,
   makespecvp sleep 재시도의 참조 균형, UFS inode free/reuse 및 모든 callback이 내부
   필드를 보존하는지는 남아 있다. 80차 속성/마지막 참조 하위 함수도 이어 검토한다.
5. **UFS 저장소·I/O 계약**. iget의 bread divisor/geometry·buffer bounds, byte_swap 원본
   layout 전체, iinactive/itrunc/iupdat/iaccess/suser와 vm_info_init/lock_init 및 allocator
   실패 계약. 직접 copy destination 범위 확인을 모든 callee의 보존 증명으로 확대하지 않는다.
6. **VM/page/pmap/lock/native 잔여**. 이전 80차의 device pager, object+0x44 writer/wakeup,
   COW/shadow/cache 수명, PTE/PV 생성과 PT/PD 재사용, managed region/descriptor,
   queue/lock/wakeup/scheduler/IRQ/context/fault/FPU/MMIO 항목은 계속 미완료다.
7. **전역 완료 요건**. 함수 밖 code/data/undefined 및 함수 경계·ABI/타입, Ghidra 경고와
   IDA 실패 독립 대조, 전역 함수·경로 ledger, loader와 __common/__bss clearing,
   IPC/MIG/BSD/VFS/network/DriverKit/kernserv/Objective-C 잔여 분석을 누락하지 않는다.

원본 분석의 안전한 다음 단계가 있으므로 전체 목표는 완료도 차단도 아니다.
외부 코드 참고·소스 복원·커널 구현·빌드·아키텍처 이식은 하지 않는다.
