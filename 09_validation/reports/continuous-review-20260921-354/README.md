# 354차 정적 검토 — __text code-unit 연속 coverage 독립 검증

full-pass5 code-units.tsv의 __text 단위 308,204개를 Python으로 정렬·검사했다. 0x001012d0부터 0x001d10bb까지 각 unit의 시작·끝·length가 연속하며 공백, 겹침, length 불일치는 없다.

총 851,436바이트는 instruction 824,512, undefined 20,556, data 6,368바이트로 분류된다. 합계와 범위는 원본 __text 크기 및 full-analysis audit와 일치한다.

undefined 분류는 공백이 아니라 analysis-export의 코드 unit 종류다. 이 coverage 검증은 undefined 영역의 의미나 실행 가능성을 확정하지 않는다.
