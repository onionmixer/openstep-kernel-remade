# 95차 범위와 증거 수준

현재 목표는 OPENSTEP 원본 커널 분석이다. 01_resources/07_kernel 및 다른 코드의
내용은 열람하거나 근거로 사용하지 않았다. 원본 바이너리/DB/export/이전 보고서는 변경하지 않는다.
이번 신규 파일은 이 보고서 디렉터리의 문서·증거·보존 해시·체크포인트뿐이다.
모든 주소/폭/개수/마스크/반올림/해시는 Python으로 계산했다. 새 구현·emulator·verifier
소스 파일을 만들지 않았고 커널 실행이나 live Ghidra/IDA 조작도 하지 않았다.

## 선택한 본문

- 일반 helper: 0x189b34, 0x189c1c, 0x189e8c, 0x18a034, 0x18a0a4, 0x18a114,
  0x18a184, 0x18a1c4, 0x18a204, 0x18a244, 0x18a288, 0x18a2cc.
- recovery fragment: 0x189c00, 0x189cd0, 0x18a018, 0x18a088, 0x18a0f8, 0x18a168,
  0x18a1ac, 0x18a1ec, 0x18a22c, 0x18a270, 0x18a2b4, 0x18a2f8.
- 직접 소비자: pn_get 0x11c9a0, pn_set 0x11ca34, uwritec 0x10a4d8,
  ureadc 0x10a448, ipc_kmsg_get 0x14758c, ipc_kmsg_put 0x1476ec.

선택 본문은 full-pass5 ASM/C/metadata를 사용했다. export 명령의 크기/원본 mapping,
본문 byte union/직접 분기 목적지 및 핵심 operand를 별도 원본 디코드로 확인했다.
부가 IPC 인자 창은 mach_msg_send 0x1525c8..0x1525db,
mach_msg_trap 0x1535a9..0x1535bc / 0x1539ca..0x1539dd / 0x153bd0..0x153be3,
msg_send_trap 0x1542b0..0x154303, msg_rpc_trap 0x154594..0x1545e7이다.
이 caller들은 해당 창만 재디코드했고 전체 본문 의미 검토로 세지 않는다.

## 판정 한계

명령/주소/폭/분기는 원본 사실, 레지스터 산식은 해당 경로 전제하의 도출이다.
allocator 성공, caller 인자 정당성, segment/DF/IRQ/thread 동일성 및 실제 trap 도달은
지역 명령 확인과 구분한다. Python 유한 산식은 native 실행 검증이 아니다.
Ghidra의 fragment 이름/void 반환형/panic 경고를 실제 ABI 증명으로 삼지 않는다.
참조 export에 없는 간접 경로가 없다고 단정하지 않는다.

94차 후보 목록과 체크포인트를 다시 해시 검증했지만 95차에서 전체 ASM offset survey를
새로 실행했다고 보고하지 않는다. 후보 진전은 기존 exact-literal 범위로 제한한다.
기존 보존 목록에서도 현재 원본 증거 범위 밖 항목은 재열람하지 않았고 제외 이유를 기록한다.
독립 계획 교차검토 미수신, native 미검증, 전체 목표 미완료 상태를 그대로 유지한다.
