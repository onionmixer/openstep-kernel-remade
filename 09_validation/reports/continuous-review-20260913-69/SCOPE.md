# IPC message queue 송수신·대기 상태 연결

보고서 68의 후속 정적 분석이다. ipc_mqueue_send/receive, thread_will_wait/with_timeout, ipc_thread_enqueue/rmqueue, ipc_kmsg_enqueue와 exception_raise_continue의 전체 보존 본문을 원본 Mach-O에 대조한다. 오류 시 kmsg 소유권, queue/port lock의 전환, timeout 재검사, 수신 size/pointer union, resume ABI와 참고 소스 차이를 기록한다.

Ghidra 스킬은 보존 export 읽기 전용 분석에 적용한다. 모든 계산은 Python이다. 문서·정적 증거만 추가하고 원본·참고 소스·DB·export·기존 확정 보고서·07_kernel은 보존한다. 새 독립 계획 검토 미확보 상태에서 구현·새 실행 검증 프로그램·동적 실행을 하지 않으며 이전 실패 검토의 우회·재요청도 하지 않는다.

thread_block/go_and_switch·timer 및 kobject_server의 내부 전체, 모든 caller의 reference/queue 생존 조건·native 경합, 후대 scatter/trailer 기능, GCC 2.7 빌드/boot는 이번 완료 범위 밖이다. 전체 목표는 계속 유지한다.
