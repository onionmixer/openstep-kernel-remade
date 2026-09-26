# OPENSTEP 4.2J m68k·SPARC 30회 연속 정적 감사 — 2026-09-22

## 결과

`10_tools/audit_multiarch_rounds_20260922.py`를 한 번 실행해 30개 round record를 순차
생성했다. Python으로 검증한 결과는 통과 28개와 비확정 관측 2개다. 모든 record의 번호는
1부터 30까지 연속이며, 원본 m68k·SPARC kernel bytes, 해당 아키텍처 IDA export, 원본에서
생성한 검증 JSON만 읽었다.

| 항목 | 값 |
|---|---:|
| round record | 30 |
| 통과 | 28 |
| 비확정 관측 | 2 |

집계와 개별 기록은 [aggregate.json](aggregate.json)에 있다. 이 감사는 함수·symbol·xref의
동작 의미, ABI, source 복원, 빌드 또는 실행을 확정하지 않는다.

## 범위와 핵심 불변식

- m68k·SPARC 원본 SHA-256, Fat container slice, `FEEDFACE`, raw CPU type을 explicit
  big-endian Python parsing으로 확인했다.
- canonical IDA processor와 big-endian 설정, 전체 `__text` byte coverage, xref source·
  destination partition, SPARC loader 거부 DB의 보존을 확인했다.
- m68k unknown 6바이트는 원본 bytes 및 단일 xref 관측과 대조했지만, 근거 부족으로 unknown
  상태와 DB를 유지했다.
- SPARC raw `__OBJC` word layout, NUL-section TSV 재조합, raw record xref endpoint 경계를
  원본 hash와 함께 확인했다. word 값·NUL record·IDA xref type은 runtime 의미가 아니다.
- explicit m68k·SPARC 경로가 x86 경로와 분리됐음을 확인했다. field명 `x86_path_absent`는
  기존 검증 JSON의 field명이며 경로 참조가 아니다.

두 관측 record는 `m68k-unknown-retention`과 `sparc-nul-xref-record-start-observation`이다.
관측값을 함수 경계·code/data·pointer·호출 의미로 승격하지 않는다.

## Preflight 기록

최종 실행 전, validation JSON field mapping을 엄격하게 맞추는 과정에서 세 개의 incomplete
preflight run이 발생했다. 해당 6·24·29개 partial record는 각각
`multiarch-continuous-20260922-preflight-failure*` 경로에 원인 설명과 함께 보존했다. 원본
binary, IDA DB, 기존 확정 보고서는 수정되지 않았고, 이 partial 기록은 위 30회차 집계에
포함하지 않는다.

## 근거

- [다중 아키텍처 입력·무결성 보고서](../multiarch-input-20260921/README.md)
- [입력 무결성 집계](../multiarch-input-20260921/separation-and-integrity-validation.json)
- [m68k unknown 보류 근거](../multiarch-input-20260921/m68k-unknown-text-unit-review.json)
- [SPARC NUL-section xref endpoint 감사](../multiarch-input-20260921/sparc-objc-nul-xref-endpoint-audit.json)
