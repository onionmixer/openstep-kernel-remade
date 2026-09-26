# OS42J m68k·SPARC 30회 연속 정적 감사

## 결과

원본 OPENSTEP 4.2J m68k·SPARC 커널에 대해 30개의 서로 다른 정적 감사를 순차 실행했다.
각 회차 결과는 `001-*.json`부터 `030-*.json`까지 별도 보존하며, 집계는
[aggregate.json](aggregate.json)에 있다.

| 상태 | 회차 수 | 의미 |
|---|---:|---|
| `pass` | 25 | 원본 바이트·구조·경로 불변식을 통과함 |
| `observed` | 5 | 관측값을 기록했으며 의미·함수 경계·분류를 확정하지 않음 |

## 확인 범위

- Fat container와 두 원본 slice의 SHA-256·offset·size·CPU type·big-endian magic
- Mach-O load command, segment, section 및 `__text` 원본 범위
- raw symbol row 수, IDA `__text` item 연속성, 함수 assembly 파일 존재와 후보 범위
- canonical big-endian IDA DB의 xref source endpoint mapping
- big-endian Capstone의 code item 첫 명령 관측
- m68k unknown 6바이트의 보류 상태와 m68k·SPARC·x86 경로 격리

`observed`는 실패를 숨기거나 성공으로 집계한 상태가 아니다. 함수 후보 시작점과 raw
symbol value의 교집합, Capstone decoder 결과, m68k unknown 6바이트는 원본 동작·함수
경계·code/data 의미를 단정할 근거가 아니므로 관측으로만 남겼다.

이 감사는 실행, 재부팅, QEMU, 소스 복원, 구현 또는 빌드를 수행하지 않았다. 계산과
집계는 Python으로 수행했고, x86와 m68k·SPARC의 원본·DB·export를 병합하지 않았다.
