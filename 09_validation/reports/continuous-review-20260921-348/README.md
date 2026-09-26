# 348차 정적 검토 — Could not recover jumptable warning 원본 FF /4 대조

Could not recover jumptable at ... Too many branches 경고는 11개 레코드이며 모두 analysis fragment가 아닌 함수에 있다. 각 경고 VA의 원본 두 바이트를 Python으로 읽으면 모두 FF /4 간접 JMP다.

0x00186f55·0x00186f72은 FFE2, 0x00186f86과 Objective-C message-send 계열의 나머지 여덟 주소는 FFE0이다. 이 결과는 간접 JMP 명령의 존재만 보장한다. jump table 대상 집합, 호출 의미, ABI 또는 런타임 분기는 결론내리지 않는다.
