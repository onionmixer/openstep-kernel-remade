# 252차 정적 검토 — decompiler warning inventory와 indirect-transfer 4-entry 경계 audit

원본-derived `full-pass5` warning export를 Python으로 집계했다. 이는 원본 바이트 분석을 대체하지
않으며, warning 자체를 해소 또는 오류로 판정하지 않는다.

warning record는 884개, warning instance는 2,206개다. 가장 큰 종류는 `Subroutine does not return`
1,185건, `Removing unreachable block` 538건, overlapping global-symbol 378건이다.

`Treating indirect jump as call`은 11건이지만 실제 entry는 네 개다. `__switch_tss`,
`__call_with_stack`, `_objc_msgSend`, `_objc_msgSendSuper`의 원시 indirect transfer는 각각
238·249·250·251차에서 검토했다. 이는 경고가 완전히 해소됐다는 뜻이 아니며, ABI·target·runtime
meaning은 여전히 별도 근거가 필요하다.

집계와 검토 상태는 [warning-indirect-transfer-audit.json](warning-indirect-transfer-audit.json)에,
재검증 해시는 [checkpoint.json](checkpoint.json)에 보존했다.
