# 원본과 C 표현의 차이 — 97차의 한정된 목록

이 문서는 선택 본문에서 확인한 의미 누락과 96차의 관련 누락을 연결한다.
커널 전체의 경고·실패·ABI·의미 누락 ledger가 완성되었다는 뜻은 아니다.
원본 ASM/C와 DB는 수정하지 않았다. C가 보기 좋다는 이유로 원본보다 우선하지 않는다.
원본 명령과 byte mapping은 [증거 JSON](object-lifetime-evidence.json),
96차의 상세 frame 근거는 [이전 보고서](../continuous-review-20260913-96/README.md)에 있다.

## CR0 상태 변경이 C에 없음

- PCresume: `0x1a1675 MOV EAX,CR0`, `0x1a1678 OR AL,8`, `0x1a167a MOV CR0,EAX`.
- PCcallMonitor: `0x1a186b MOV EAX,CR0`, `0x1a186e OR AL,8`, `0x1a1870 MOV CR0,EAX`.

[PCresume C](../../../04_ghidra/exports/x86/full-pass5/functions/001a15c4.c)와
[PCcallMonitor C](../../../04_ghidra/exports/x86/full-pass5/functions/001a1750.c)의 전체 본문은
해당 하드웨어 상태 변경을 표현하지 않는다. 첫 함수에서는 active 저장 뒤 일반 state 복사,
두 번째에서는 inactive 저장 뒤 deliverTimers로 바로 연결되어 보인다.
이 출력으로 hardware contract가 보존된 구현을 얻었다고 할 수 없다.
CR0 변경의 모든 FPU/예외 효과는 이 지역 대조의 완료 범위가 아니다.

## return_with_state의 제어 이전과 stack ABI

[0x186f04 C](../../../04_ghidra/exports/x86/full-pass5/functions/00186f04.c)는
empty_stacks 저장 뒤 `CONCAT44` 반환으로 표현한다.
[원본 ASM](../../../04_ghidra/exports/x86/full-pass5/functions/00186f04.asm)은
CALL return address 제거, S를 ESP로 전환, CLI/STI, segment/general register 복원,
trap/error 슬롯 건너뛰기와 IRETD이다. 단순한 64비트 함수 반환이 아니다.

이번에 caller thread_exception_return의 실제 PUSH/CALL과 함께 재확인했다.
PC monitor/resume/marker의 C에 보이는 일반 반환도 이 비표준 경로를 그대로 설명하지 못한다.
원본 caller의 남은 epilogue가 존재한다는 사실과 정상 IRETD 경로의 비복귀는 구분한다.
AST/segment fault 등 미확인 경로를 이유 없이 noreturn 처리하지 않는다.

## exception continuation call-site 인자 누락

[PCexception C](../../../04_ghidra/exports/x86/full-pass5/functions/001a13a0.c)의 47행은
`_exception_with_continuation(1,iVar4)`이다.
원본 `0x1a1468`부터는 continuation 주소, CR2, status, 1의 DWORD PUSH가 있고
`0x1a1471` CALL 뒤 `0x1a1476`에서 ESP에 0x10을 더한다.
호출 직전 stack에서 전달하는 continuation과 CR2가 C 호출에 드러나지 않는다.
callee의 full formal signature·continuation 실행 의미는 여기서 임의 보충하지 않는다.

## Queue lock의 memory polling/저장 위치 표현

원본에서 다음 MOV→TEST→JNZ TEST backedge를 재확인했다.

| 본문 | load | TEST | JNZ target |
|---|---|---|---|
| dispatch delayed | 0x16940c | 0x169412 | 0x169412 |
| remove | 0x169590 | 0x169595 | 0x169595 |
| worker 진입 | 0x169cc8 | 0x169ccd | 0x169ccd |
| worker callback 후 | 0x169d7c | 0x169d81 | 0x169d81 |

branch bytes는 `75fc`이며, 같은 TEST로 반복하는 동안 load를 다시 실행하지 않는다.
C는 `while (DAT_001e7244 != 0)`로 표현한다. 캡처된 register가 nonzero이고
외부 예외적 register 변경이 없다면 원본의 반복은 memory polling이 아니다.
또한 원본의 XCHG 1/old-value 검사/retry 관계를 C의 LOCK/UNLOCK 표식만으로 대체할 수 없다.

[remove C](../../../04_ghidra/exports/x86/full-pass5/functions/0016957c.c)의 진입 LOCK/UNLOCK
사이에는 lock=1 저장이 보이지 않는다. [worker C](../../../04_ghidra/exports/x86/full-pass5/functions/00169cb0.c)는
진입/재진입에서는 LOCK/UNLOCK만 보이고 loop 뒤 53행에 DAT=1을 표현한다.
원본은 `0x169cd1/0x169cd6`, `0x169d85/0x169d8a`에서 각각 1을 XCHG한다.
C의 표현 위치를 원본 동기화 순서로 채택하지 않는다. 실제 contention/hang은 미검증이다.

## Synthetic panic fallthrough의 불완전한 C ABI

`0x16943e`는 parent의 panic CALL 다음 바이트부터 시작하는 synthetic fragment다.
원본 body는 enclosing EBP/레지스터를 사용하고 `0x169454/0x16946b`로 분기한다.
그 C는 parent의 후속 영역까지 따라가면서 clock_value 인자,
set_timer의 DWORD 인자, splx 인자를 불완전하게 표현한다.
독립 호출 가능한 void 함수로 해석하거나 fragment C만으로 parent를 대체하지 않는다.
실제로 panic이 반환한다는 증명은 없으며, fragment 존재를 그 증명으로 사용하지 않는다.

## 96차에서 이어받은 frame 초기화 누락

96차는 원본 `0x1a3160`에서 다음 초기화 명령을 raw bytes로 확인했다.

- `0x1a33b6/0x1a33c0/0x1a33ca`: 넓은 frame의 EIP DWORD/CS WORD/flags DWORD.
- `0x1a3517/0x1a3522/0x1a352d`: 좁은 frame의 EIP/CS/flags WORD.
- `0x1a3677/0x1a3680/0x1a368a/0x1a3694`: error DWORD와 EIP DWORD/CS WORD/flags DWORD.

해당 C의 local_20/local_38은 전달용 배열 주소로 사용되지만 위 초기화 저장은 빠져 있었다.
이는 C 의미 누락이다. 이와 별개로 넓은 frame의 CS WORD 위 gap에 명시적 own
EBP-relative MOV 초기화가 없다는 원본 관찰도 있었다. 둘을 혼동하지 않는다.
stack 초기값·alias writer·실제 노출/도달성은 96차에서도 미확인이다.

이번에는 96차 보고서/증거/해시를 재검증하고 이 목록에 연결했다.
0x1a3160의 전체 본문을 97차 선택 본문 집계에 다시 포함한 것은 아니다.
커널 전체의 유사 배열/stack alias/간접 호출/하드웨어 효과/제어 이전 누락은 계속 추적해야 한다.
