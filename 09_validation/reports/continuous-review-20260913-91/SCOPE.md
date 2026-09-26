# 범위와 방법

OPENSTEP 원본 바이너리와 원본에서 얻은 ASM/C·본문 범위·심볼·참조만 사용한다.
다른 코드와 `01_resources`, 복원 코드 `07_kernel`은 열거나 참고하지 않는다.
소스 복원·구현·빌드·포팅·동적 실행은 범위 밖이다. 과거 외부 소스 비교는 현재 의미 증거가 아니다.

선택: physstrat `0x11ed10`, useracc/vslock/vsunlock `0x17bd28/0x17bd68/0x17bd9c`,
read/readv/write/writev `0x10cd54/0x10cd8c/0x10ce00/0x10ce38`, rwuio `0x10ceac`,
vno_rw `0x11b984`, spec 본문 `0x139e18`, fspause `0x13ba10`,
vm_map_check_protection `0x1765fc`, vm_phys_to_vm_page `0x178894`,
기존 synthetic fall-through fragment `0x139e3e`.
fragment의 본문 byte와 확대된 C 출력 영역은 다른 개념이며 독립 함수로 중복 집계하지 않는다.

원본 Mach-O 파일과 기존 full-pass5 mapping/본문 byte 집합, 명령 경계/길이, 직접 branch/CALL target,
선택 중요 operand·폭·signedness·스택 인자·원본 표·문자열을 확인했다.
모든 비분기 operand의 export 문자열을 자동 동등성 검사한 것은 아니다.
중요 의미는 별도 명시 operand/순서 검사와 원본 본문 읽기로 한정한다.

기존 90차 결과도 시작 시 원본 매핑·저장 evidence·현재 파일 해시로 재검사했다.
표는 초기 파일 상태이지 runtime dispatch 확인이 아니다. __common/__bss 내용은 runtime 메모리로
읽지 않는다. 함수명과 추정 타입은 외부 API 정의로 확정하지 않는다.

모든 산술·offset/크기/개수·해시는 Python만 사용했다. 편집은 apply_patch만 사용했다.
새 verifier 파일·구현·에뮬레이터나 live 분석 DB 변경은 없다. 이전 실패한 독립 검토 요청을
재시도·우회하지 않았으며 이번 독립 계획 교차검토 미수신을 통과로 취급하지 않는다.
선택한 지역 분석 완료와 전체 kernel 의미/경계/ABI 검증 완료를 구분한다.
