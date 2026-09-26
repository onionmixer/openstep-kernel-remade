# 남은 OPENSTEP 원본 분석

88차는 SCSI 요청 queue/dequeue/완료 후보와 NXConditionLock의 지역 명령을 연결했다.
전체 분석은 계속 미완료다.

1. **다음 우선: doSdBuf `0x1ad8b0` 실제 전송·완료**. R.status `+0x28`과
   actualLength `+0x24` writer, controller 호출·client map/buffer 변환·부분 전송,
   retry/sense/error와 sdIoComplete 호출이 정확히 연결되는지 확인한다.
   관련 후보 setupScsiReq `0x1ae510`, genRwCdb `0x1ae488`, reqSense `0x1ae600`,
   logOpInfo `0x1ae348` 및 명령 writer를 검토한다. 현재 완료 helper에 biodone이 있다고
   모든 요청의 정확히 한 번 완료가 입증된 것은 아니다.
2. **게시·해제·조건 잠금의 native 전제**. enqueue의 queue unlock 뒤 R.pending 읽기와
   worker의 빠른 완료/free 순서를 확인한다. NXConditionLock 내부의 LOAD 밖 TEST-loop
   `75fc` 진입 조건, thread_sleep `0x163320`/wakeup `0x1631a0`/lock_write/lock_done,
   condition waiter 선택·등록/해제·소유/수명과 quiescence가 필요하다.
   IOForkThread `0x1a90ec`/IOExitThread `0x1a9220`, 생성 후 count 게시 및 종료 정책,
   active count·eject BYTE writer와 ready 상태도 미해결이다.
3. **실제 객체/메서드 등록**. disk table `0x1e7324`/control `0x1e7564` writer,
   self `+0x184` 연결, superclass 문자열→class pointer fixup, category/selector 등록·
   override·cache·forwarding을 확인한다. NXConditionLock/SCSIDisk/IODisk의 정적 후보를
   실제 receiver identity나 모든 override의 errno 반환으로 일반화하지 않는다.
4. **geometry·원본 buffer 계약**. blockSize/diskSize/partition 값·label/ready writer,
   DIV divisor·비율/overflow/zero length와 actualLength<=B.request 보장,
   잔여 길이·flag-only 오류·중복 완료·B 수명, physical 주소/client map의 유효성을 확인한다.
   IOMalloc/kalloc 실패·bzero/memset 전체 동작은 이번에 확정하지 않았다.
5. **이전 원본 미완료 범위**. uiomove/copywithin 오류와 recovery/frame/DF/FS,
   pagemove/PTE/CR3/PV/TLB와 allocator/release 뒤 접근,
   NFS rfscall/XDR count·daemon 비지역 복귀/queue/sticky 오류,
   UFS bmap/size/uerror/부분 성공·credential와 상위 VM/pager/event/bitmap/shutdown을 유지한다.
6. **전역 요건**. 함수 밖 code/data/undefined·누락 entry·경계·ABI/타입,
   Ghidra 경고/IDA 실패 독립 대조와 전역 함수·경로 ledger,
   loader/__common/__bss·scheduler/IRQ/context/fault/FPU/CR3/TLB/MMIO,
   pmap/PV/PT/PD·COW/shadow/cache/device pager·vnode hash/reuse/inactive,
   IPC/MIG/BSD/VFS/network/DriverKit/kernserv/Objective-C 범위를 축소하지 않는다.

다른 코드는 참고하지 않는다. 구현·복원·빌드·포팅·동적 실행은 범위 밖이다.
계산은 Python만, 파일 변경은 apply_patch만 사용한다. 독립 계획 교차검토 미수신을
통과로 바꾸거나 실패 요청을 재시도·우회하지 않는다. 안전한 정적 분석이 가능하므로
전체 목표는 완료도 차단도 아니다.
