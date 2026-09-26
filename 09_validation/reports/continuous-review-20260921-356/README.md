# 356차 정적 검토 — full-pass5 pseudocode 상태와 비어 있지 않은 C 출력 전수 검증

5,253개 full-pass5 분석 단위의 JSON status·message와 주소별 C 출력을 Python으로 전수 검사했다. 모든 status는 decompiled이며, 비어 있는 C 파일은 없고 nonempty message와 non-decompiled 상태도 없다.

이 결과는 디컴파일 출력 자료가 존재한다는 검증이다. decompiler가 추론한 타입·제어 흐름·의미가 원본 동작과 일치한다는 뜻은 아니다.
