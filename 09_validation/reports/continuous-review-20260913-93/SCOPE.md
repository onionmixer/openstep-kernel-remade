# 범위와 증거 강도

OPENSTEP 원본 mach_kernel과 그에서 추출된 full-pass5 ASM/C/본문/참조 및 원본 nlist만
사용한다. 원본-only 92차 copy/wiring 증거는 해시와 관련 copy 명령을 다시 대조했다.
01_resources, 07_kernel, 외부 Mach4/NeXTMach/Darwin 코드는 열거나 의미 근거로 쓰지 않았다.

선택 본문은 vm_fault, kernel_trap, mach_kernel_trap_ 진입부, catch_trap,
0x186d20 일반 trap entry, dbf_handler, helper 0x1923e0/0x192438/0x1924a0/0x1924e0,
stub 0x186138/0x1861c4/0x1861cc다.
vm_fault는 전체 body-byte/명령 경계를 대조했지만 의미 검토는 반환 및 선택 경로 부분이다.
나머지 선택 본문은 전체 ASM/C를 읽었으나 모든 하위 callee와 native 환경이 증명된 것은 아니다.

원본 Mach-O file-backed mapping, body 합집합, 명령 길이·직접 target·중요 operand,
table 경계/target, 이전 copy 명령, 전역 zero-fill 구분을 Python으로 검증한다.
모든 비분기 export 문자열의 자동 의미 동등성을 검사한 것은 아니다.
다른 본문으로 나가는 선택 stub JMP는 선택된 대상 entry와 원본 목적지를 확인하고
외부 body 경계 간선으로 기록한다. 참조의 CALL 라벨을 명령 종류로 신뢰하지 않는다.
64개 참조 명령 검증은 그 predecessor stub/IDT 전체의 분석 완료가 아니다.

임의 byte 위치의 탐색 디코드는 의미 증거로 쓰지 않으며, 산출물의 명령 검증은 확인된
export head/selected body 또는 직접 참조가 지시하는 JMP head에 한정한다.
__common/__bss를 파일 offset으로 오독하지 않는다. 초기 또는 runtime 값을 추정하지 않는다.

분석 보고서/증거만 apply_patch로 추가한다. 새 .py 구현·verifier 파일, 에뮬레이터,
소스 복원, 빌드, 포팅, 동적 실행, live Ghidra/IDA DB 변경은 하지 않는다.
계산은 Python만 사용하며 기존 확정 보고서·원본·DB/export를 보존한다.
새 독립 계획 교차검토 미수신은 통과가 아니고, 실패 요청을 재시도·우회하지 않는다.
전체 목표는 완료도 차단도 아니다.
