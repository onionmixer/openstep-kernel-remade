# 281차 정적 검토 — Unknown calling convention 경고 원본 바이트 검토 범위 갱신

원본에서 파생된 full-pass5 decompiler warning export의 Unknown calling convention
59개 record·instance를 다시 대조했다. 원본 바이트 검토가 완료된 entry는 19개이며,
미검토 entry는 40개다.

이번 갱신은 278차 _xdr_diropargs, 279차 _xdr_diropres, 280차 _xdr_linkargs의
검증 통과 checkpoint를 범위표에 추가한다. 이 표는 warning의 정확성이나 ABI·parameter
storage·return convention·runtime 의미를 판정하지 않는다.

목록과 각 checkpoint 상태는
[unknown-calling-convention-byte-review-audit.json](unknown-calling-convention-byte-review-audit.json)에,
입력 및 추적 파일 해시는 [SCOPE.md](SCOPE.md)와 [checkpoint.json](checkpoint.json)에
보존한다.
