# OPENSTEP 4.2J m68k·SPARC 30단계 연속 정적 감사 — steps3

검증된 30-step audit를 새 전용 경로에서 한 번 실행해 record 30개를 순차 생성했다. Python
검증 결과는 통과 28개, 비확정 관측 2개이며 번호는 1부터 30까지 연속이다.

각 단계는 원본 SHA-256, big-endian Mach-O field, canonical IDA 조건, `__text` byte coverage,
xref endpoint partition, m68k unknown 보류, SPARC raw `__OBJC` NUL-section evidence 및 경로
격리를 대조한다. 함수·pointer·xref의 runtime 의미, ABI, source 복원, 빌드와 실행은 판정하지
않는다.

집계와 개별 기록은 [aggregate.json](aggregate.json)에 있다. 두 비확정 관측은 m68k unknown
상태 유지와 SPARC NUL record 시작 주소 xref 관측이며, 의미 결론으로 사용하지 않는다.

기준 자료는 [다중 아키텍처 무결성 집계](../multiarch-input-20260921/separation-and-integrity-validation.json)와
[continuation 2 30회 감사](../multiarch-continuous-20260922-continuation2/README.md)에 있다.
