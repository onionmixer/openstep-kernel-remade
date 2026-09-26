# IPC 요청 취소·최종 해제·알림 소유권의 정적 검토

보고서 59의 하위 계약 중 dead-name request 취소, space/object release, notify 권한 획득/복제, message-accepted request 생성·취소·파괴 및 알림 생성/할당 실패 시 권한 해제를 원본 본문으로 연결한다. kmsg clean/receive의 호출과 알림 template 초기화는 관련 window를 별도로 대조한다.

Ghidra 스킬을 보존 export의 읽기 전용 비교에 적용하며 모든 계산은 Python으로 수행한다. 새 독립 계획 검토 미확보 상태를 유지한다. 새 검증 프로그램·동적 실행·DB/원본/07_kernel 수정·GCC 2.7 실빌드는 하지 않는다. 과거 실패한 독립 검토를 재요청하거나 우회하지 않는다.

queue send/최종 전달, allocator 전체, no-senders 연쇄, request rename 및 전체 caller의 직렬화·경합은 이 단계로 완결되지 않는다. 공개 소스와 원본의 차이를 기록하고 일치하지 않는 참고 구현을 채택하지 않는다.
