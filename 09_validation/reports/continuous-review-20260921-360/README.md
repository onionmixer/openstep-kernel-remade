# 360차 정적 검토 — FULL_ANALYSIS 정적 자료 확보 완료 감사

현재 사용자 범위의 FULL_ANALYSIS 필수 산출물 여섯 항목을 current full-pass5와 독립 검증 기록에 대조했다.

1. 기준 바이너리 SHA-256, 언어·compiler spec·image base·분석 옵션 manifest는 359차에서 확인했다.
2. 모든 로드 영역 자료와 __text code-unit 연속 coverage는 354차에서 확인했다.
3. 5,253개 함수·analysis fragment의 JSON·ASM·C 존재, body/ASM 주소·길이 일치, pseudocode status는 350·355·356차에서 확인했다.
4. 심볼·참조·타입 파일 존재, 함수 심볼 주소 대응, references endpoint 범위, 원본 추출 Objective-C IMP 대응은 352·353·357·358차에서 확인했다.
5. 함수 밖 instruction, 미식별 executable 영역, 디컴파일 실패의 current audit 상태는 352차의 export failures 빈 배열·unrepresented bytes 0·orphan instruction ranges 빈 배열과 354·356차 검증으로 확인했다.
6. 원본 __text를 분모로 한 coverage는 354차에서 851,436바이트 전부가 공백·겹침 없이 분류됨을 확인했다.

full-analysis warning 인벤토리 2,206개는 349차에서 전수 범주화했고, 경고를 원본 의미의 해결로 해석하지 않았다. 현재 단계의 정적 자료 확보는 완료됐지만, semantic reconstruction, 원래 ABI/소스 선언 확정, GCC 2.7 빌드와 런타임 검증은 범위 밖이며 완료로 주장하지 않는다.
