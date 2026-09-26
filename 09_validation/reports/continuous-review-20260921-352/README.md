# 352차 정적 검토 — FULL_ANALYSIS 필수 자료 산출물 현재 상태 감사

FULL_ANALYSIS의 정적 자료 확보 요구를 current full-pass5와 full-analysis audit로 대조했다. 분석 설정·매니페스트, memory block·code-unit·coverage 자료, 함수 JSON·ASM·C, symbols·references·data-types·Objective-C inventory, whole-program assembly와 failure 자료가 존재한다.

현재 audit는 export failures 빈 배열, unrepresented bytes 0, nonpadding unclassified ranges 빈 배열, orphan instruction ranges 빈 배열, missing symbol·ObjC entries 빈 배열을 기록한다. 5,253개 분석 단위의 JSON·ASM·C 존재와 기준 바이너리 SHA 일치는 350차에서 독립 확인했다.

이 자료 확보 감사는 semantic reconstruction verified와 GCC 2.7 build verified가 false임을 그대로 보존한다. 따라서 정적 자료 확보의 completeness와 코드 의미·ABI·빌드 검증을 혼동하지 않는다.
