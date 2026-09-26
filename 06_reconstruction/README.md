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
