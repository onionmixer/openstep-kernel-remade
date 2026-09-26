# Timer adapter·wait 해제·스케줄러 진입 연결

보고서 69의 후속이다. set/reset timeout, timer 초기화와 service adapter, thread timeout/setup/set_timeout, clear_wait, ticks→ns/deadline 변환, thread_go_and_switch와 thread_block_with_continuation의 전체 원본 본문을 대조한다. 간접 switch 표는 원본 데이터에서 별도로 해독한다. timer callback 연결은 등록 필드와 service adapter까지 검증하며 callout scheduler 내부의 실제 실행/취소 경쟁은 제외한다.

Ghidra 스킬을 보존 export의 읽기 전용 대조에 적용한다. 계산은 모두 Python이다. 정적 증거·문서만 추가하고 원본·참고 소스·DB·export·기존 확정 보고서·07_kernel은 변경하지 않는다. 새 독립 계획 검토 미확보 상태에서 구현·새 실행 검증 프로그램·동적 실행으로 전환하지 않으며 이전 실패 검토의 우회·재요청도 하지 않는다.

thread_select/invoke/run, call_continuation과 context/stack 전환, callout dispatch/remove·실제 clock/interrupt·native 경합, 모든 timer와 wait 생성자의 생존 조건, GCC 2.7 빌드/boot는 이번 완료 범위 밖이다. 전체 분석 목표는 계속 미완료다.
