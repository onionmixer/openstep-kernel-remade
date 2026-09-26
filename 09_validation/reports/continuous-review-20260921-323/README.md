# 323차 정적 검토 — Unknown calling convention 경고 바이트 검토 완결 감사

원본에서 파생된 full-pass5 decompiler warning export의 Unknown calling convention을 Python으로 재감사했다. 59개 warning record와 61개 warning string instance가 있고, 59개 모든 entry가 원본 바이트 검토 및 pass checkpoint에 대응한다. 미검토 entry는 0개다.

이는 경고의 정확성이나 ABI·parameter storage·return convention·runtime 의미를 판정하지 않는다. 원본 바이트 검토 범위의 완결성만 확정한다.
