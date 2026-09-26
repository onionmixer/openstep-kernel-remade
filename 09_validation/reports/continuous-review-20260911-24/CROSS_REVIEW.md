# 코딩 전 독립 교차검토

검토자 `/root/trap_plan_review`는 읽기 전용으로 원본 명령·SDK와 계획을 검토했다.
새 시험 코드나 에뮬레이션을 수행하지 않았으며, 다음 조건하에 순서가 타당하다는
의견을 냈다. root는 관련 원본 assembly와 SDK를 직접 읽어 대조했다.

- CS=8의 높은 base에서 EIP offset과 hook 선형 주소/API 좌표를 먼저 확인.
- vector14 초기 table은 0x001e1a74, handler 0x001861cc, selector8/type0xf.
  **Trap gate**이므로 interrupt gate처럼 IF를 자동으로 지우면 안 됨.
- stub은 trap number만 push. error code를 중복 삽입하지 않음.
- same-CPL frame에는 old ESP/SS를 무조건 추가하지 않음. segment push 슬롯의
  상위 비트를 selector 의미로 확정하지 않고 low word를 검사.
- 실제 fault의 CR2/EIP/recover/GPR 스냅샷과 프레임 주입 경계를 기록.
  error-code와 CPU saved RF 등 미관찰 항목은 명시적 입력 계약.
- 빈 map의 sentinel/next/prev/hint와 start 조건, lock owner/read count/flags/
  interlock/hint lock을 초기화하고 원본 획득·해제 및 복원 검사.
- vm_fault counter 증가는 원본의 허용된 효과. uthread+0x68 저장·초기화·복원 검사.
- recovery는 EIP, CS low word, DF, thread recover를 바꿈. 다른 flags를 임의
  정규화하지 않음. IRETD 이후 실패 epilogue와 실제 caller 반환까지 검증.

독립 의견만으로 통과를 선언하지 않는다. 주소·프레임 크기·실행 후 상태는
Python으로 다시 계산하고 원본 바이트와 실행 결과를 증거로 남긴다.

## 첫 실행 이후 읽기 전용 재검토

같은 독립 검토자는 첫 코드·JSON에서 명백한 frame offset 오류를 발견하지 못했으나,
다음 보강을 권고했다. root는 의견을 그대로 통과 판정에 쓰지 않고 검사를 추가했다.

- 높은 code hook 주소와 IDT slot의 물리 backing: Python page walker로 대조.
- native 실패가 다른 초기화 예외인지 구분: fresh INTR-hook fault 대조와 전체
  스냅샷, recover, 사용자/커널 버퍼 해시를 비교.
- IF/DF 외 flags: IRETD landing에서 합성 saved flags 전체의 DF-clear 결과를 대조.
- frame 변경 범위: 원본 PUSH가 만든 selector 슬롯 상위 비트도 보존했는지,
  실제 frame 전체를 읽어 EIP/CS low word/DF 이외의 변경이 없는지 검사.
- 쓰기 범위 과장 금지: 버퍼·map·uthread 필드·counter·caller 구간 및 스택 guard를
  명시. 이 검사로 전체 RAM·실제 bus write를 검증했다고 주장하지 않는다.
- 첫 페이지 NP는 선행 root-switch scalar gate부터 fault하므로 이번 NP 조건은
  두 번째 페이지에 한정하고, 짧은 첫 페이지 fault는 RO로 시험.

별도 `audit_results.py`는 fixture 코드를 import하지 않는다. 원본 Mach-O mapping을
직접 파싱하고 instruction trace의 direct branch/call/return/IRETD 연결, 별도
frame 계산과 버퍼 예상 해시를 대조한다. 같은 CPU 관찰 자료의 독립 산술 검토이며
다른 CPU backend 또는 실제 하드웨어의 독립 실행 증거는 아니다.
