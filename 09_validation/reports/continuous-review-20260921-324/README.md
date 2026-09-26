# 324차 정적 검토 — Treating indirect jump as call 경고 완결 감사

원본에서 파생된 full-pass5 warning export를 Python으로 재감사했다. Treating indirect jump as call은 4개 entry·11개 warning instance이며, 네 원본-byte 보고서에 기록된 raw indirect JMP 11개와 대응한다. 모든 참조 checkpoint는 pass 상태다.

이는 indirect target, 호출 convention, ABI 또는 런타임 제어흐름을 확정하지 않는다. 경고 entry와 원시 indirect JMP 바이트 검토의 대응 범위만 확정한다.
