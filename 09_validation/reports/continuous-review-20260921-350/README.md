# 350차 정적 검토 — full-pass5 분석 corpus 무결성 재검증

full-pass5의 functions.json 5,253개 분석 단위를 Python으로 전수 검사했다. 일반 함수는 4,761개, 인위적 analysis fragment는 492개다.

각 단위의 주소별 JSON·ASM·C 파일이 모두 존재하고 비어 있지 않으며, JSON의 원본 바이너리 SHA-256은 기준 mach_kernel SHA-256과 모두 일치한다. 누락 파일과 SHA 불일치는 각각 0개다.

이 결과는 분석 자료 corpus의 존재·대상 일치성만 재검증한다. 함수 경계·decompiler 의미·ABI·런타임 동작의 정확성을 확정하지 않는다.
