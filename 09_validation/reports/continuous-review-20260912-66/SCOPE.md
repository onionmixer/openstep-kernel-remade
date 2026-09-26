# Port 파괴·순환 검사·대기 해제와 지연 메시지 정리

보고서 65의 후속 정적 분석이다. ipc_port_destroy/check_circularity, ipc_mqueue_changed, ipc_thread_dequeue, ipc_kmsg_dequeue/destroy, thread_go, port-destroyed 일반·compat 알림, send-once 알림, ipc_kobject_destroy의 보존된 전체 본문을 원본 Mach-O 명령어와 대조한다. thread_go의 간접 분기 표는 함수 본문과 별도로 원본 데이터에서 해독한다.

Ghidra 스킬을 보존 export의 읽기 전용 분석에 적용한다. 주소·크기·비트·집계·해시 계산은 모두 Python으로 수행한다. 문서 및 정적 증거만 추가하며 원본·참고 소스·DB·export·기존 확정 보고서·07_kernel은 변경하지 않는다. 신규 독립 계획 검토는 확보되지 않았으며 기존 실패 검토의 우회·재요청, 새 실행 검증 프로그램, 동적 실행 및 구현은 하지 않는다.

호출 대상 전체의 의미 검증, 알림 template 초기화, 메시지 clean/free/send 내부, 스케줄러 전체, 동시성·실기 부팅·GCC 2.7 검증은 이번 범위 밖이다. 분석 자료 확보나 본문 바이트 일치를 전체 원본 의미 복원 완료로 간주하지 않는다.
