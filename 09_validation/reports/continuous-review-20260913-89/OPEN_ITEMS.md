# 남은 OPENSTEP 원본 분석

89차는 doSdBuf/setup/CDB/sense/상태 변환의 지역 경로를 연결했다.
기본 IOSCSIController executeRequest는 전송 없는 상수 반환이므로 실제 하드웨어 계약은
아직 증명되지 않았다. 전체 원본 분석 목표는 계속 미완료다.

1. **다음 우선: 실제 controller 연결과 명령 생성 전제**. 원본 SCSIDisk 초기화 후보
   `0x1acbc8`의 controller 전달·self `+0x184` writer, probe/등록 및 class/category/fixup,
   IOSCSIController/IODirectDevice의 실제 subclass·메서드 선택을 추적한다.
   외부 driver 코드를 가져와 공백을 메우지 않는다. 명령 2–4의 T 생성/target-lun/길이,
   read/write blockCount 상한·maxTransfer·WORD CDB count와 DWORD 길이의 일치를 확인한다.
2. **실제 execute·DMA·sense**. executeRequest의 runtime override, buffer/client map 변환,
   실제 길이/상태/embedded sense writer, 짧은 전송·실패 시 reqSense의 고정 26바이트 복사,
   aligned allocation의 NULL·mask 정렬·power-of-two·overflow와 원시 할당 해제의 계약이 필요하다.
   IOVmTaskSelf의 `_IOTask_kern` 생성과 `+0xc`, getDMAAlignment override/출력 초기화도 남는다.
3. **완료·게시·조건 잠금 native 전제**. 88차 enqueue의 unlock 뒤 R.pending 재읽기와
   빠른 완료/free, 실제 exactly-once 완료·B 수명·residual 범위·errno override를 확인한다.
   선택한 setup 실패 IMP는 완료 후 비영 반환하지만 모든 동적 override로 일반화하지 않는다.
   NXConditionLock register TEST-loop `75fc`, thread_sleep/wakeup/lock primitive,
   waiter/owner/quiescence, IOForkThread/IOExitThread와 count·eject·ready 정책은 미완료다.
4. **geometry·diagnostics·할당**. logical/physical block geometry writer·DIV/overflow/zero length,
   label/ready와 retry counter 외부 writer·stats IMP, 초기화 global unit 증가/rollback,
   공유 fallback 진단 buffer의 동시 접근과 sprintf/strcpy, bzero/memset/kalloc의 전체 계약을 유지한다.
5. **이전 원본 범위**. uiomove/copywithin 오류와 recovery/frame/DF/FS,
   pagemove/PTE/CR3/PV/TLB·buffer allocator/release 뒤 접근,
   NFS rfscall/XDR/daemon/queue/sticky 오류,
   UFS bmap/size/uerror/부분 성공/credential 및 상위 VM/pager/event/bitmap/shutdown을 유지한다.
6. **전역 요건**. 함수 밖 code/data/undefined·누락 entry·경계·ABI/타입,
   Ghidra 경고/IDA 실패 독립 대조 및 전역 함수·경로 ledger,
   loader/__common/__bss·scheduler/IRQ/context/fault/FPU/CR3/TLB/MMIO,
   pmap/PV/PT/PD·COW/shadow/cache/device pager·vnode hash/reuse/inactive,
   IPC/MIG/BSD/VFS/network/DriverKit/kernserv/Objective-C 잔여 범위를 축소하지 않는다.

다른 코드는 참고하지 않는다. 구현·복원·빌드·포팅·동적 실행은 현재 범위 밖이다.
계산은 Python만, 파일 변경은 apply_patch만 사용한다. 독립 계획 교차검토 미수신을
통과로 간주하거나 실패 요청을 재시도·우회하지 않는다. 원본 정적 분석이 계속 가능하므로
전체 목표는 완료도 차단도 아니다.
