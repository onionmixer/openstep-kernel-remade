# IPC space 생성·파괴와 권한 정리 ABI

보고서 64의 후속으로 space_create/create_special/destroy, right_clean, pset_destroy, release_receive 및 ipc_bootstrap/init을 원본 전체 본문과 참고 소스에 대조한다. active/growing/ref의 수명, 정상 table/free-list 초기화와 특수 space의 불완전 필드, 권한 정리와 tree node free의 순서, Ghidra의 가짜 ABI 인자를 구분한다.

계산은 모두 Python이다. Ghidra 스킬은 보존 export 읽기 전용 분석에 적용하며 문서·정적 증거만 추가한다. 원본·참고 소스·DB·export·기존 확정 보고서·07_kernel을 보존한다. 신규 독립 계획 검토 미확보 상태에서 새 실행 검증 프로그램·동적 실행·구현·GCC 2.7 빌드 또는 이전 실패 검토의 우회/재요청은 하지 않는다.

port_destroy, mqueue/wait/wakeup, task_create와 allocator의 전이적 완결, native 경합·부팅 순서 및 전체 caller의 수명은 이번 완료 판정에서 제외한다. 전체 원본 분석 목표를 유지한다.
