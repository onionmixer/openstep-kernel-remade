# PD 참조 수명·재사용의 정적 추가검토

이번 단계는 **정적 분석 완료, 신규 동적 검증 미착수** 상태다. 독립 계획 검토 에이전트가 오류로 종료되어 새 실행·검증 코드 작성은 보류했다. [교차검토 상태](CROSS_REVIEW.md)에 실패와 한계를 명시했다.

## 확인한 진전

- 원본 create/reference/destroy 직접 호출 13곳을 바이트에서 계산하여 Ghidra 참조 목록과 대조했다: create 7, reference 2, destroy 4.
- 선택 함수 본문 7개의 instruction 경계·길이와 원본 해독 결과를 기록하고 근거 입력 63개를 식별했다.
- 이전 실제 생성 prefix 8개에서 양쪽 슬롯의 사용자 PDE가 0이고 refcount가 1인 사전조건을 확인했다.
- size가 0이 아닌 create는 NULL을 반환하며, 비최종 destroy는 슬롯을 반환하지 않는 분기를 확인했다.
- 반환 슬롯 재사용은 pmap 구조체 초기화와 kernel PDE 복사를 수행하지만 PD 전체를 zero하지 않는다는 차이를 확인했다.
- 공유 pmap 참조를 사용하는 호출자와 map 삭제 후 pmap 해제 순서를 식별했다. caller 전체 수명·오류 경로는 아직 검증하지 않았다.

[정적 상세 검토](STATIC_REVIEW.md) · [원본·호출자 근거](static-evidence.json) · [이전 자료 보존](preservation.json) · [계획](PLAN.md) · [남은 전체 분석](OPEN_ITEMS.md)

Ghidra 스킬을 사용하여 보존 listing/디컴파일/참조 자료를 읽기 전용으로 대조했다. 모든 주소·크기·집계·해시는 Python으로 계산했다. 원본 binary/DB/export와 이전 보고서는 변경하지 않았다. 이번 경로의 새 emulator 실행·negative control·재현성 결과는 없으며 이전 성공 지표를 전용하지 않았다. `07_kernel` 구현과 GCC 2.7 실컴파일도 수행하지 않았다.
