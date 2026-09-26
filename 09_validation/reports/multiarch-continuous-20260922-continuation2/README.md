# OPENSTEP 4.2J m68k·SPARC 30회 연속 정적 감사 — continuation 2

검증된 `audit_multiarch_rounds_20260922.py`를 새 전용 경로에서 한 번 실행해 30개 round
record를 순차 생성했다. Python 검증 결과는 통과 28개, 비확정 관측 2개이며, 번호는 1부터
30까지 연속이다.

이 감사는 원본 m68k·SPARC SHA-256, explicit big-endian Mach-O fields, canonical IDA 설정,
`__text` byte coverage, xref endpoint partition, m68k unknown 보류, SPARC raw `__OBJC`
NUL-section evidence 및 아키텍처 경로 격리를 다시 대조한다. 함수·pointer·xref의 runtime
의미, ABI, source 복원, 빌드와 실행은 판정하지 않는다.

두 비확정 관측은 m68k unknown 상태의 유지와 SPARC NUL record 시작 주소 xref 관측이다.
이 결과는 code/data·함수 경계·pointer·호출 의미로 승격하지 않는다.

집계와 개별 기록은 [aggregate.json](aggregate.json)에 있다. 기준 자료는
[2026-09-22 첫 30회 감사](../multiarch-continuous-20260922/README.md)와
[다중 아키텍처 무결성 집계](../multiarch-input-20260921/separation-and-integrity-validation.json)에
있다.
