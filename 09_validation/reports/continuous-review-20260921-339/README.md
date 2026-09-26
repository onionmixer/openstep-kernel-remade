# 339차 정적 검토 — Subroutine does not return CFG 외부 분기 경계 대조

338차의 함수 export instruction set 밖 직접 분기 9개를 원본 바이트의 상대변위로 다시 계산하고, full-pass5 전체 함수 body 구간과 대조했다. 9개 모두 다른 함수로 이탈하지 않고 더 큰 소유 함수의 body 안으로 향했다.

따라서 338차의 9개 CFG 중단점은 경고 대상 함수 내보내기 분할의 경계다. 이는 대상 함수가 실제로 반환하지 않는다는 근거나 외부 제어 전송의 근거가 아니다.

대상은 _ttwrite, _m_copy, _sbflush, _iget, _ipc_mqueue_receive, FUN_00171cb4, _clock_timer_init, _mmrw, _NXDefaultExceptionRaiser의 내부 body 구간이다. 모든 VA와 상대 JMP 대상 계산은 Python으로 수행했다.
