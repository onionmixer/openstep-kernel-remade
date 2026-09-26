# 357차 정적 검토 — full-pass5 symbol·function 인벤토리 대조

symbols.tsv의 41,793개 심볼을 memory-blocks.json과 functions.json에 Python으로 대조했다. Function 심볼 행과 고유 주소는 모두 5,253개이며, functions.json의 분석 단위 주소 집합과 정확히 일치한다. 함수 심볼 누락과 초과는 각각 0개다.

전체 심볼 중 35개 주소는 현재 memory block 밖이지만 모두 Function이 아닌 Label이다. 심볼 유형은 Label 36,540개와 Function 5,253개다.

이 인벤토리 검증은 심볼 주소·종류·분석 단위 대응만 다룬다. 심볼 이름, 함수 의미, 원래 소스 선언 또는 ABI를 확정하지 않는다.
