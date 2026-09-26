# 잔여 분석 — 보고서26 이후

[보고서25의 잔여 목록](../continuous-review-20260911-25/OPEN_ITEMS.md) 및 그 목록이
계승한 전체 의무를 유지한다. 이번에 성공한 범위는 아래와 같이 한정한다.

- 합성 기존 object/page/pmap 위에서 원본 resident lookup 및 같은 물리 매핑의
  RO→RW 교정, 원본 vm_fault=0, IRETD와 실제 fault 명령 재실행.
- 원본 page_insert 및 active 초기 queue 대조, 기존 통계의 미접근·불변,
  다른 root의 대상 mapping과 버퍼 보존.

아직 끝나지 않은 주요 분석:

- native IDT 진입·CPU error/frame 생성, CPL 전환·대체 스택·다른 예외.
- pager I/O, 부재 페이지 할당, page-table/PV 신규 할당, 다른 물리 매핑 대체,
  COW/shadow/shared map, busy/absent/error·wait/wakeup·실패/재시도.
- 완전한 object/map/pmap 생성과 전체 root의 소유권·통계·PV 정합.
- 비연속 물리 페이지와 실제 VM 페이지 경계 부분 복사, 전체 문맥 전환 및
  FS/descriptor 권한·limit·비동기 조건, 모든 recover 수명.
- 부팅 잔여 경로, ABI/타입/함수 경계, CPU 부작용 표현 통합·전체 소비자 회귀,
  동시성/장치·TLB/cache 하드웨어 효과, 같은 원본 IDA 대조 및 교정안 재추출,
  공개 소스 계보와 추적 가능한 복원 명세.

resident 권한 교정은 pager에서 새 데이터를 읽어 오는 page-in이 아니다. 이번
success를 이 구별 없이 전체 fault 성공 검증으로 확대하지 않는다. 후속 작업은
남은 할당/대체/재시도 경로의 조건을 원본에서 조사하고 코딩 전에 교차검토한다.

GCC 2.7 구현·빌드·부팅과 후속 아키텍처도 별도 미완료 의무다.
