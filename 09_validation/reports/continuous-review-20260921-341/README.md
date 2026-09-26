# 341차 정적 검토 — _ipc_object_copyin_type jump table 원본 바이트 대조

0x0014bb40의 _ipc_object_copyin_type는 0x0014bb46에서 EAX를 0x15와 비교한 뒤, 0x0014bb58의 22개 32비트 jump-table 엔트리를 사용한다. 원본 mach_kernel 바이트에서 이 테이블을 Python으로 해독했다.

22개 엔트리 중 9개는 0x0014bbb0, 0x0014bbb8, 0x0014bbc4, 0x0014bbd0의 RET 블록으로 향한다. 나머지 13개와 범위 초과 Jcc 경로는 0x0014bbdc의 _panic 호출로 향한다. 따라서 이 함수의 Subroutine does not return 경고는 전체 함수가 반환하지 않는다는 근거가 아니다.
