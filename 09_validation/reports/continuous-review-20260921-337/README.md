# 337차 정적 검토 — Subroutine does not return 경고의 전수 종단 분류

정확히 /* WARNING: Subroutine does not return */인 544개 경고 레코드와 1,185개 인스턴스를 원본 파생 full-pass5 함수 내보내기와 원본 __text 바이트로 전수 대조했다. analysis fragment는 228개다.

544개 모두 함수 JSON·ASM 내보내기를 가지며, 291개는 적어도 하나의 RET를 포함한다. 나머지와 함께 마지막 내보내기 명령 분류는 RET 291개, ADD 206개, CALL 22개, JMP 12개, MOV 13개다. 이는 함수의 전체 제어 흐름을 판정한 결과가 아니며, 경고 문구만으로 반환 여부를 단정할 수 없음을 보인다.

모든 주소·구간 끝 VA·원시 마지막 바이트·RET 수 계산은 Python으로 수행했다.
