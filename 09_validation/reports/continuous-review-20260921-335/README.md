# 335차 정적 검토 — Type propagation warning 범주 완료 감사

full-analysis 경고 목록에서 정확히 /* WARNING: Type propagation algorithm not settling */인 9개 레코드와 9개 인스턴스를 다시 집계했다. analysis fragment는 0개이며, 9개 모두 325·326·328–334차의 원본 바이트 검증 체크포인트에 연결되고 미검토 레코드는 없다.

각 연결 보고서의 원본 바이너리 SHA-256, status: pass, 보고서 식별자를 Python으로 다시 대조했다. 이 완료 감사는 decompiler 경고의 적용 범위만 다루며 타입 또는 실행 의미를 확정하지 않는다.
