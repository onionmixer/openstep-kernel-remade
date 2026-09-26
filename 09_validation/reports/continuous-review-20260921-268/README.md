# 268차 정적 검토 — Unknown calling convention warning의 byte-review coverage 감사

원본-derived full-pass5 warning export에서 Unknown calling convention category를 Python으로
재집계했다. warning record와 instance는 각각 59개이며 analysis fragment record는 없다.

그중 8개 entry는 260·262–267차의 원본-byte evidence와 연결된다. 관련 checkpoint는 모두
원본 mach_kernel SHA-256 및 추적 파일 hash 검증을 통과했다. 나머지 51개 entry는 아직
개별 원본-byte review 대상이다.

이 감사는 warning category의 검토 coverage만 기록한다. calling convention·parameter
storage·return ABI·decompiler warning의 정확성은 판정하지 않는다. 전체 mapping과 남은
entry는 [unknown-calling-convention-byte-review-audit.json](unknown-calling-convention-byte-review-audit.json)에,
재검증 입력 해시는 [SCOPE.md](SCOPE.md)와 [checkpoint.json](checkpoint.json)에 보존한다.
