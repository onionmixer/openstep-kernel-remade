# 85차 계획 — 원본 strategy와 buffer 재사용

[84차 잔여](../continuous-review-20260913-84/OPEN_ITEMS.md)에 따라 원본 vnodeops의
strategy target 및 getnewbuf/brealloc/bfree를 읽고, 직접 연결되는 NFS I/O worker,
allocbuf와 UFS 하위 I/O 본문까지 이어서 오류/residual·메모리 사용 계약을 확인한다.

1. 원본/이전 checkpoint/export 해시를 재확인한다.
2. 선택한 전체 본문의 원본 byte mapping, 경계, 직접 분기 및 중요 operand를 대조한다.
3. 정적 strategy 및 block-size slot을 원본에서 읽고 실제 dispatch 전제와 구분한다.
4. 요청 준비·완료·오류 WORD·residual 기록, async queue 게시, allocator retry와 reuse,
   크기/offset/범위 식을 연결한다. 모든 계산은 인라인 Python만 사용한다.
5. 해시와 정적 명령/정수 증거 및 미해결 계약을 남기며 전체 목표는 별도로 판단한다.

Ghidra 스킬의 전체 본문·디컴파일·참조 대조를 기존 원본 export에 적용한다.
다른 프로젝트 코드, `01_resources`, `07_kernel`은 참고하지 않는다. 원본 및 DB와
확정된 이전 보고서는 변경하지 않는다. 새 verifier 파일·에뮬레이터·구현·동적 실행은 추가하지 않는다.
파일 변경은 apply_patch로만 한다. 별도의 독립 계획 교차검토는 수신하지 않았으며
실패한 검토 요청을 재시도·우회하거나 Python 계산을 독립 에이전트 검토로 표현하지 않는다.

원본 register/stack 폭과 순서를 우선한다. 특히 TEST의 Capstone access annotation은
84차에서 오류가 확인되었으므로 단독으로 메모리 write 판정 근거로 사용하지 않는다.
단일 함수의 성공 반환을 native I/O 영속성, 전역 잠금/수명 또는 전체 분석 완료로 확대하지 않는다.
