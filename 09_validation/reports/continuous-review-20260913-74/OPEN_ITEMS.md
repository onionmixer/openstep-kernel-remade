# 남은 분석 — OPENSTEP 원본에 한정

이번에 검토한 본문의 바이트 일치·직접 분기·지역적 소유권은 근거가 확보됐지만,
하위 동작·모든 입력·동시 실행까지 닫힌 것은 아니다. 다른 프로젝트 코드를 사용하지 않는다.

## 가장 가까운 다음 작업

1. 보존 원본 listing의 0x17aa08 본문에서 발견한 zdata_size store(0x17abf5),
   zdata store(0x17ac02)의 전후 할당·정렬·clearing·실패 경로와 실제 bootstrap 호출 순서를
   검토한다. 현재는 writer 위치만 찾았으며 해당 함수 전체를 완료 처리하지 않았다.
   page_size/page_mask의 producer 및 loader 초기 상태도 원본에서 연결한다.
2. `zone_free_space_reclaim`(0x16ab34)과 GC 쪽 producer를 검토한다. descriptor별 정렬,
   hint 갱신·unlink·count·페이지 경계 분할 및 실제 VM 반환을 추적한다. add에 기존
   head보다 낮은 새 영역이 들어올 수 있는지 주소 선택·재사용과 함께 확인한다.
3. `kmem_suballoc`(0x173fbc), map find/insert/delete/pageable, object reference/deallocate,
   page sequential allocation/zero-fill의 원본 계약을 필요한 경로까지 연결한다.
   무시하는 반환 상태, 출력 word 변경 시점, 부분 페이지 할당 실패의 rollback 범위를
   실제 하위 명령으로 검증하기 전에는 leak-free·항상 성공·무대기라고 단정하지 않는다.
4. `thread_sleep`(0x163320)이 전달 lock을 소비하는 순서, wakeup/재시도와 scheduler 전환,
   object/page byte 상태의 writer/reader를 검토한다. register-only 대기 루프의 바이트
   확인과 native 진행성 입증을 별도 판정으로 유지한다.

## 계속 열려 있는 원본 분석 범위

- default descriptor 및 새 zone 저장소의 초기 내용과 전체 writer. 이전 보고서의 selector·
  callout 할당 결론도 현재 범위에서 사용할 때 원본 근거만 재검증하고 외부 소스 해석을
  그대로 계승하지 않는다.
- callout lifetime, clock/IRQ·scheduler/continuation/context, IPC/권리/notification/OOL VM,
  pager/COW/shadow·페이지 상태/alias/PV·오류 및 대기, PD/GC/reuse/CR3,
  fault/RF/IDT/IRETD/FPU, 장치/MMIO/TLB/cache 경로의 미검증 의미와 상호작용.
- BSD/VFS/UFS/network/DriverKit/kernserv/Objective-C 등 원본 subsystem의 미검토 경로.
  함수별·경로별 완료 근거를 전역 ledger와 맞춰, 일부 성공을 전체 완료로 확대하지 않는다.
- 함수 밖 코드·fragment·data 분류, ABI/타입/호출 규약, Ghidra 경고와 IDA 실패 및
  디컴파일 해석의 독립 대조. export 파일의 존재만으로 의미 검증 완료로 처리하지 않는다.

소스 복원·구현·GCC 2.7 빌드·다른 architecture 포팅은 최신 사용자 지시에 따라 현재
작업에서 제외한다. 그 작업이 남았다는 이유로 현재 원본 분석의 완료 조건을 넓히지 않는다.
반대로 원본 의미·미식별 코드·ABI 등의 미검증 항목이 남아 있으므로 원본 분석 목표는
아직 완료가 아니다. 의미 있는 정적 분석이 가능하므로 목표를 차단으로 표시하지 않는다.
