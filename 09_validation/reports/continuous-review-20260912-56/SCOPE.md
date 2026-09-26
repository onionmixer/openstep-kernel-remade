# compat copyout의 정상 반환과 내부 실패 처리

report55의 조건부 미확정 항목을 실제 callee로 좁힌다. `ipc_kmsg_copyout_compat`, `ipc_object_copyout_type_compat`, `copyoutmap`의 본문을 검토한다. 원본 정상 제어 흐름에서의 반환값과 내부 실패 시 메시지 변경·자원 처리 호출을 구분한다.

보존 Ghidra 출력과 원본 바이트, 공개 소스의 대응을 읽기 전용으로 확인한다. 계산·집계·해시·정적 제어 흐름 처리는 Python만 사용한다. callee가 정상 반환한다고 모델링한 정적 그래프는 실제 실행·경쟁·fault·비복귀의 증명이 아니다.

새 독립 계획 검토는 확보되지 않았다. 신규 실행/검증 프로그램, 동적 실행, 커널 구현 및 GCC 2.7 완료 판정은 하지 않는다. 하위 port/VM 서비스의 전체 소유권은 미완료다.
