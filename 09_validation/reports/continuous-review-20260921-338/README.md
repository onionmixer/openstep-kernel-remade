# 338차 정적 검토 — Subroutine does not return의 보수적 CFG RET 도달성

337차의 544개 경고 함수를 대상으로, 함수 진입점에서 직접 상대 JMP·Jcc와 fall-through만 따라가는 보수적 CFG 도달성 분석을 Python으로 수행했다. CALL은 fall-through를 유지하고, 간접 전송의 대상이나 호출의 반환 여부는 추정하지 않았다.

291개 함수는 진입점에서 도달 가능한 RET를 가졌고 253개는 이 제한된 모델에서 RET에 도달하지 않았다. RET 총수별 분류는 reachable RET 1개/전체 RET 1개 286개, reachable RET 1개/전체 2개 3개, reachable RET 14개/전체 14개 1개, reachable RET 3개/전체 3개 1개다. no reachable RET는 전체 RET 0개 249개, 1개 3개, 4개 1개다.

직접 분기 대상 9개는 함수의 export instruction set 밖에 있어 모델에서 더 이상 확장하지 않았다. 이 분석은 실행·호출 반환·간접 분기 의미를 검증하지 않으며, 실제 런타임 반환 여부를 결론내리지 않는다.
