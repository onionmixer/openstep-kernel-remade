# 259차 정적 검토 — infinite-loop warning category의 원본-byte 검토 범위 감사

원본-derived decompiler warning export에서 Do nothing block with infinite loop category를
Python으로 다시 집계했다. 이 category는 warning record 8개와 warning instance 10개이며,
그중 analysis fragment record는 1개다.

각 record는 235·253–258차의 원본-byte evidence에 연결된다. 해당 checkpoint는 모두 원본
mach_kernel SHA-256과 추적 파일 hash를 재검증해 pass 상태임을 확인했다. 10개 warning
instance를 6개의 실제 raw direct self-loop 관찰로 축소하거나 warning correctness로
판정하지 않는다. 0x00105afc와 0x00105d58은 하나의 local loop evidence를 공유한다.

원시 loop 관찰은 HLT self-loop 5개와 HLT가 아닌 direct self-loop 1개다. 나머지 warning
instance 3개는 해당 검토 범위의 원시 HLT 인접 바이트에서 direct self-branch가 관찰되지
않았다. 이 category의 runtime 의미와 decompiler warning의 정확성은 여전히 별도 검증 대상이다.

완전한 mapping과 checkpoint audit은
[infinite-loop-warning-byte-audit.json](infinite-loop-warning-byte-audit.json)에,
재검증 입력 해시는 [SCOPE.md](SCOPE.md)와 [checkpoint.json](checkpoint.json)에 보존한다.
