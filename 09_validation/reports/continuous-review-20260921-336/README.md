# 336차 정적 검토 — global-symbol overlap warning 범위 감사

정확히 /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */인 경고를 원본 파생 full-analysis 경고 목록에서 다시 집계했다. 378개 레코드·378개 인스턴스 중 analysis fragment는 95개다.

각 경고 진입 VA는 함수 C·JSON 내보내기와 symbols.tsv의 대표 함수 심볼 하나에 대응했다. 대표 심볼은 IMPORTED 232개, USER_DEFINED 95개, DEFAULT 51개이며 이름은 밑줄 시작 327개와 기타 51개다. 그러나 symbols.tsv에는 작은 겹침 심볼이 보존되지 않아 실제 겹침의 크기·우선순위·해결 여부는 이 감사로 결론내리지 않는다.
