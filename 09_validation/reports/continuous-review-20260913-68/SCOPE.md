# IPC right destroy와 namespace caller·알림

보고서 67 후속으로 ipc_right_destroy 전체와 mach_port_destroy, ipc_hash_delete, ipc_notify_port_deleted/no_senders를 원본 본문에 대조한다. active/dead port, compat 반환 상태, namespace entry/hash와 port reference 정리 순서, 선행·후행 알림 ownership을 구분한다.

Ghidra 스킬은 보존 export 읽기 전용 대조에 적용한다. 계산은 모두 Python으로 하며 정적 증거·문서만 추가한다. 원본·참고 소스·DB·export·기존 확정 보고서·07_kernel은 변경하지 않는다. 새 독립 계획 검토가 확보되지 않아 구현·새 실행 검증 프로그램·동적 실행을 하지 않으며 이전 실패 검토를 우회·재요청하지 않는다.

전체 caller 및 native 경합, message queue 송수신·알림 template 초기화, 모든 allocator·권한 생성자와의 전이적 수명 증명은 제외한다. 전체 분석·실제 GCC 2.7 복원/빌드/부팅 목표는 계속 미완료다.
