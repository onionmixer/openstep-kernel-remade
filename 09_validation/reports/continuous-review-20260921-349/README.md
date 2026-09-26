# 349차 정적 검토 — full-analysis decompiler warning 범위 인벤토리 감사

원본 파생 full-analysis warning export의 884개 경고 레코드와 2,206개 인스턴스를 Python으로 열 가지 범주에 전수 분류했다. 미분류 인스턴스는 없다.

이 감사는 경고가 모두 해결됐다는 선언이 아니다. 일부는 원본 바이트 대조와 범주 완료 감사를 가졌고, 일부는 decompiler 분석 한계 또는 함수 분할 범위만 정적으로 확인했다. 각 범주의 근거 보고서는 evidence JSON에 연결한다.
