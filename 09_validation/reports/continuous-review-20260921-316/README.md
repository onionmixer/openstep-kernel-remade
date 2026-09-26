# 316차 정적 검토 — Unknown calling convention 경고 범위 재감사

원본에서 파생된 full-pass5 decompiler warning export를 Python으로 다시 집계했다. Unknown calling convention은 59개 warning record와 61개 warning string instance다. 원본 바이트 검토와 pass checkpoint가 있는 entry는 53개이며, 미검토 entry는 6개다.

281차 범위표의 instance 수 59는 record 수를 중복 집계한 값이었다. 이 보고서는 경고의 정확성이나 ABI·parameter storage·return convention·runtime 의미를 판정하지 않는다.
