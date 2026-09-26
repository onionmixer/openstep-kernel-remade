# 277차 정적 검토 — Unknown calling convention warning의 갱신된 byte-review coverage 감사

원본-derived full-pass5 warning export에서 Unknown calling convention category를 Python으로
재집계했다. warning record와 instance는 각각 59개이며 analysis fragment record는 없다.

현재 16개 entry는 260–276차 원본-byte evidence와 연결되고, 각 checkpoint의 원본 binary
SHA-256 및 추적 파일 hash를 다시 검증해 pass 상태임을 확인했다. 나머지 43개 entry는
개별 원본-byte review 대상이다.

이 감사는 warning category의 검토 coverage만 기록한다. calling convention·parameter
storage·return ABI·decompiler warning의 정확성은 판정하지 않는다. 전체 mapping과 남은
entry는 [unknown-calling-convention-byte-review-audit.json](unknown-calling-convention-byte-review-audit.json)에,
재검증 입력 해시는 [SCOPE.md](SCOPE.md)와 [checkpoint.json](checkpoint.json)에 보존한다.
