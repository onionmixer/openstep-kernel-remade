# 보고서28 코딩 전 계획 — 원본 page alloc/free 및 cached 재할당

전체 잔여 의무를 유지한다. 원본 vm_page_alloc_sequential(0x17b200), vm_page_free,
vm_page_addfree의 queue/hash/memq 계약을 실제 원본 명령으로 시험한다. kernel 구현,
전체 VM 생성·pager I/O·pageout/PV teardown 검증으로 대체하지 않는다.

## 코딩 전 독립 검토와 root 원본 확인

`/root/vm_contract_review27`에 두 차례 읽기 전용 설계 검토를 요청하고 코드 작성
전에 결과를 받았다. root도 alloc/free/addfree/init/startup 및 pageout 연결 원본을
읽고 다음 조건을 대조했다.

- reserve 거절은 signed free_count<reserved 및 비특권 thread 조건. equality
  허용, empty 조기 거절, below/above 및 vm_privilege를 구별한다.
- tabled page의 hash/memq 멤버십은 반드시 정합해야 한다. 제거 탐색에는 NULL
  종료 검사가 없다. 정상 free는 tabled를 지우므로 cached/tabled-free와 분리한다.
- template는 zero-BSS에서 시작하여 원본 startup prefix 0x17aa08을 실행하고
  0x17aade 직전에 멈춰 얻는다. 전체 startup이 아니라 prefix임을 기록한다.
  전체 template/queue/lock 결과를 검사하고 이후 caller register/stack을 다시 준비한다.
- 원본 vm_page_init으로 서로 hash 충돌하는 페이지들을 한 object memq에 넣는다.
  정상 seed는 원본 free로, cached seed는 busy 해제 준비 경계 후 원본 addfree로
  구성한다. addfree의 중복 free/fictitious 금지, wanted=0을 사전 검사한다.
- 원본 pageout은 매핑 제거 뒤 busy 해제·필요 wakeup 후 addfree를 호출한다.
  이번 cached seed는 그 전체 경로가 아니다. 별도 합성 물리 backing을 두고
  fixture의 주소 공간에서 매핑이 없음을 확인한다. 전체 PV 소유권은 미검증이다.
- object 및 global queue caller lock은 startup prefix 종료 후 준비·보존한다.
  원본 free는 해당 lock을 자체 획득하지 않는다. 내부 free/hash lock과 구분한다.
- pageout 임계값은 감소 후 free_count에 적용된다. min/target/inactive-target=0,
  object policy=0이라는 제한을 명시하고 wakeup/policy 호출의 비실행을 검사한다.
  sequential 인자 0/1을 대조하되 policy=0 시험을 sequential policy 실행으로 부르지 않는다.
  last_alloc는 sequential 인자와 무관하게 성공 때 갱신된다.

## 실행·검산·보존

fresh 단일 사례에서 original init/free/alloc/lookup를 먼저 실행한다. 성공 후
정상 및 cached FIFO/collision/reuse, empty/reserve 경계/privilege/인자 대조를 확장한다.
반환·원본 trace·CPU/callee-saved·stack guards·전체 descriptor/object/queue/hash 상태와
물리 backing 불변을 기록한다. 독립 모델은 실행 fixture를 import하지 않고 상태
전이를 계산하며 원본 trace를 대조한다. 실패 시 진단을 새 보고서에 보존한다.

모든 계산은 Python. 원본·정본 Ghidra/IDA DB·참조 소스·기존 보고서·07_kernel은
변경하지 않는다. Ghidra 스킬에 따라 원본/해석/합성 준비/관찰/한계를 분리한다.
정본 export 읽기와 별도 CPU 모델 시험이며 DB를 교정하지 않는다.
