# 범위·증거 강도

원본 OPENSTEP mach_kernel과 원본-derived full-pass5 자료 및 원본-only 이전 보고서를
사용했다. 01_resources/07_kernel/외부 코드/구현/빌드/포팅/동적 실행은 범위 밖이다.
Ghidra/IDA DB와 기존 export·확정 보고서는 변경하지 않는다.

선택 본문: thread_init/create/deallocate/invoke, switch_unix_context,
switch_context/stack_handoff, pcb_init/terminate, thread_exception_return,
__switch_tss/__return_with_state, check_for_ast/catch_interrupt/sendsig.
전체 선택 ASM/C를 읽고 원본 본문 byte 합집합·head·직접 target·중요 operand를 대조했다.
이 사실은 모든 하위 callee, native scheduler/descriptor/allocator/signal 계약까지
완료했다는 뜻이 아니다. 특정 local 수명/기준/순서/ABI 결과로 한정한다.

offset survey는 manifest에 있는 full-pass5 함수 ASM 전체 파일 집합과 일치함을 확인하고,
각 파일 해시와 크기를 대조한 후 양의 literal +0x74 operand를 고른 것이다.
각 후보 명령은 raw bytes와 폭·displacement를 확인했다. corpus 경로/크기/SHA 목록의
정렬된 JSON 해시도 보존한다. 음의 stack local, 절대주소, alias-derived/split offset,
함수 밖/미export 명령은 이 검색에 포함되지 않는다. 정확한 검색과 전체 writer 증명은 다르다.
code-pointer 후보를 독립적으로 증명된 thread recovery writer로 집계하지 않는다.

__common/__bss에서 runtime 값을 읽지 않는다. template 초기화는 명령 증거로,
파일-backed PCB/state template와 selector는 초기 파일 값으로 구분한다.
모든 비분기 export 문자열의 자동 의미 동등성을 검사했다고 주장하지 않는다.
계산과 즉석 원본 대조는 Python, 보고서 편집은 apply_patch만 사용한다.
새 .py verifier/구현 파일·에뮬레이터·독립 agent·live DB 변경은 없다.
새 교차검토 미수신은 통과가 아니며 실패한 요청을 재시도·우회하지 않는다.
전체 목표는 완료도 차단도 아니다.
