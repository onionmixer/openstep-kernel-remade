# 복원 증거와 대응표

도구 출력(04/05)과 복원 구현(07)을 연결하는 검토 계층이다.

- `functions.tsv`: 기준 바이너리 함수 ↔ 참고 소스 ↔ 복원 구현 대응.
- `types.tsv`: 구조체·필드 offset, 크기, alignment, 호출 ABI의 증거.
- `subsystems.tsv`: 큰 단위의 범위와 진행 상태.
- `evidence/`: 판단 근거. `templates/function.md`를 복사하여 시작한다.

상태는 `unmapped → candidate → compared → implemented → static_verified → runtime_verified`.
근거 없는 항목은 `unknown`, 상충하면 `conflicting`으로 기록한다.
신뢰도는 `low/medium/high`이며 검증 상태와 독립적이다.
심볼명 일치나 디컴파일 유사성만으로 `verified`로 올리지 않는다.
각 행의 원본 SHA-256과 VA를 함께 유지하며 architecture별로 분리한다.
후보 소스에는 정확한 commit/아카이브 해시와 파일/함수 위치가 필요하다.

함수 대응표는 의도적으로 header만 생성한다. 원시 nlist 심볼은 함수 경계가 아니므로
정적 인벤토리의 전체 심볼을 복원 함수로 일괄 등록하지 않는다.

`compared` + `high`: 후보 소스를 기록된 옵션으로 빌드한 목적 파일에서 그 함수가 L1 MATCH(바이트와 모든 참조를 재현, 참조하는 데이터 섹션도 검증)이고, 목적 파일이 등급 A·A\*(`objects_confirmed.tsv`) 또는 P(`objects_partial.tsv`)인 경우. 함수 단위 결과이며 목적 파일 전체 배치의 증명이 아니다.
`compared` + `medium`: 함수 바이트와 참조가 모두 같으나(L1 MATCH_UNVERIFIED) 미검증 의존이 `zerofill_check.py` 결론이 `reference-inferred` 또는 `reference-inferred-single`(D019: 참조가 하나뿐이라 음성 검사만 구조상 미검출, 그 참조는 scattered·pc-relative 아님, 다른 검사 모두 통과)인 zero-fill 섹션뿐인 경우(결론이 `fail` 이면 이 분류를 쓰지 않는다).
역사적 원 소스의 동일성과 실행 동작은 이것으로 확정되지 않는다.
`objects_confirmed.tsv` 의 등급 A 는 L1 OBJECT_MATCH 와 앞뒤 경계 증명서(최소 정렬 채움, 값 00)가 모두 성립한 경우, A\* 는 OBJECT_MATCH 이지만 경계 증명서 일부가 성립하지 않은 경우(사유는 gap 열·근거 파일).
`objects_partial.tsv` 의 등급 P(부분 검증, 계획 46.1–46.2)는 OBJECT_MATCH 가 아니다: 목록(`unverified_sections`)에 적은 섹션을 뺀 모든 파일 기반 섹션의 바이트·참조가 일치하고(바이트 차이·참조 차이·미지원 참조·모호 배치 없음), 목록의 섹션은 참조가 전혀 없어 배치할 수 없는 것(unreferenced)이거나 참조로만 위치를 추정한 zero-fill(`zerofill_check.py` 결론 reference-inferred 또는 reference-inferred-single — 후자는 D019 에 따라 행에 "단일 참조" 를 적고, 이웃 확정으로 위치가 독립 고정되면 재판정)이며, 경계 증명서가 성립한 경우.
참조 소스에 없는 코드를 원본 바이트에 맞춰 새로 쓴 함수(D016, 계획 48 W1–W6)는 `source_id` 를 `darwin01+authored` 처럼 표시하고 비고에 작성 범위·근거 주소·diff 를 적는다(역사적 원문이라는 주장이 아님).
후보 소스를 원본에 맞게 고친 경우("복원 수정", D014)는 `source_revision` 에 `+ restoration edit` 를 붙이고 `07_kernel/MODIFICATIONS.md` 에 기록한다. 바이트로 확정된 목적 파일 범위는 `objects_confirmed.tsv`,
자동 생성 후보는 `objects.tsv`(S2-A)·`function_candidates.tsv`(S2-B, 신뢰도 최대 medium).
