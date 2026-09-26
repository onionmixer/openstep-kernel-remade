# 신중한 추가 검토24 — 높은 CS의 원본 trap 복구 연결

## 판정

실제 CPU 모델 paging fault 관찰과 명시적 same-CPL 예외 프레임 주입을 연결한 뒤,
원본 예외 처리·VM lookup 실패·복구·IRETD·복사 실패 반환을 실행했다.
호출 반환값 mock이나 원본 명령 patch는 사용하지 않았다.

**native IDT 자동 전달은 확인하지 못했다.** no-INTR-hook 시험은 fault 명령에서
`UC_ERR_EXCEPTION`으로 끝났다. 아래 성공은 CPU가 자동으로 프레임을 만들었다는
증거가 아니라, 관찰한 fault 상태를 입력으로 연결한 원본 handler 실행의 증거다.

| 검증 범위 | 결과 |
|---|---:|
| 높은 CS의 정상 copyout/copyoutmsg 대조 | 32 |
| 실제 #PF 관찰 후 합성 frame으로 연결한 원본 복구 경로 | 80 |
| 그중 fault 전 부분 쓰기가 있는 사례 | 64 |
| DF 설정 입력에서 원본 복구가 DF를 해제한 사례 | 40 |
| 원본 IRETD 실행 | 80 |
| handler 구간의 원본 instruction 방문 | 25,520 |
| handler 구간의 서로 다른 instruction head | 329 |

집계는 Python 결과이며 서로 겹치는 항목이다. 전체 커널 coverage로 사용하지 않는다.

## 높은 CS·IDT 주소 게이트

report23의 CS=0x48 혼합 fixture에서 원본 최종 far jump를 실행하여 CS=8로 전환했다.
CS base는 높은 커널 base이며 DS/ES/SS=0x10, FS/GS=0x50에서 시험을 시작했다.

- 이 backend의 `emu_start`에는 EIP **offset**을 전달해야 한다.
- code hook은 높은 **선형 주소**를 보고한다. 각 code page를 Python walker로
  원본 offset의 물리 backing과 연결하고, 실행 명령 바이트를 원본과 대조했다.
- 시작 주소에 높은 base까지 더한 대조는 명령 방문 없이 CPU 예외로 끝났다.
  이 도구 주소 계약 위반을 원본 커널 결함으로 해석하지 않는다.
- 원본 `idt_init`과 IDTR relocation 구간을 실행했다. vector14는 selector8,
  type0xf의 trap gate이며 handler offset은 `0x001861cc`이다. IDT slot도 높은
  선형 주소에서 실제 fixture backing으로 page walk했다.

전체 부팅 순서를 실행한 것은 아니다. 초기화 구간과 합성 fixture를 조합한 시험이다.
page walk와 hook/readback의 일치는 실제 하드웨어 instruction fetch·TLB의 독립
검증이 아니다.

## 실제 fault와 주입 경계

원본 `_copyout`/`_copyoutmsg`를 A/B 사용자 root에서 실행했다. 정상 대조는 길이1/19,
fault 조건은 첫 페이지 RO 길이1, 두 번째 페이지 RO/NP 길이32/19이다.
IF와 DF 입력을 독립적으로 바꾸고 CR0.WP는 설정 상태로 유지했다.
첫 페이지 NP는 root 선택의 선행 FS scalar 읽기부터 fault하므로 포함하지 않았다.

각 fault의 vector14/EIP/CR2/GPR/ESP/세그먼트/flags/recover와 실제 backing 버퍼를
보존했다. 실패 store 직전까지의 원본 operand 기록과 별도 예상 버퍼를 대조했다.
선택한 pending store와 완료된 store는 단일 페이지 안에 있다. 단일 명령의 page
crossing fault 원자성은 이 범위가 아니다.

native 시도와 fresh INTR-hook 관찰 대조의 전체 레지스터 snapshot·recover·버퍼
해시가 같았다. 따라서 이번 native 실패가 다른 초기화 위치의 예외와 혼동되지
않음을 확인했다. native 시도에서는 IDT handler에 도달하지 않았다.

그 다음 **명시적으로 주입한 부분**은 error/EIP/CS/EFLAGS의 same-CPL CPU frame과
ESP 변경이다. error는 RO에3, NP에2를 입력했다. 저장 flags는 관찰한 fault flags를
입력했으며 실제 CPU의 saved RF 처리나 hardware error-code 생성은 검증하지 않았다.
old ESP/SS는 추가하지 않았고, trap number는 원본 stub이 push했다.

## 호출 mock 없는 원본 경로

`#PF stub → alltraps → catch_trap → kernel_trap → vm_fault → vm_map_lookup →
lock_done → recovery → POP/POPAD/IRETD → copy 실패 epilogue → caller`

active thread/task/map 및 uthread pointer는 합성 데이터다. 빈 VM map의 sentinel,
next/prev/hint/start와 lock 상태를 구성했다. `_vm_fault`는 원본 `_vm_map_lookup`의
miss 결과를 받아 조기 반환하고, trap은 원본 recovery로 이동한다.
실제 mapped entry의 RO 보호 거절이나 정상 page-in을 실행한 것이 아니다.
`empty_stacks=0`으로 대체 스택 전환 분기는 제외했다.

검증한 계약:

- Python으로 계산한 same-CPL saved state 크기68과 필드 offset을 원본 PUSH·SDK와 대조.
- PUSH segment의 selector는 low word로 확인. 실제 저장된 frame 전체를 별도로
  비교하여 recovery의 EIP/CS low word/DF 이외의 변경이 없음을 검사.
- trap gate의 IF를 임의로 지우지 않음. CLD, CLI/STI, IRETD 이후 상태를 분리해 관찰.
- 원본 read-lock count 증가·해제 및 map 복원, VM fault counter 증가,
  uthread 필드 저장·초기화·복원, recover 초기화.
- IRETD 직전 GPR·FS/GS 등의 복원과 frame, landing에서 saved flags의 DF-clear
  결과 전체 및 fault 시점 ESP/caller 구간 보존.
- 원본 실패 epilogue 뒤 EAX=14, caller ESP/callee-saved, IF 보존·DF 해제,
  root·CR2 유지, fault 전에 완료한 사용자 부분 쓰기와 다른 지정 버퍼의 보존.
- 지정한 아래/위 스택 guard와 실행 중 ESP 범위.

검사 영역은 지정 버퍼·map·uthread 필드·counter·frame·caller 구간·stack guard다.
전체 RAM의 쓰기 전수 검사, 실제 동시성·interrupt 또는 bus 효과 검증이 아니다.

## 디컴파일 표현과 복원 제약

canonical C의 `FUN_00186d20`은 `return CONCAT44(param_2,param_1)`로 보인다.
그러나 원본 종료는 `IRETD`이고, 이번 실행에서도 저장된 frame에서 제어 흐름·flags·
세그먼트·스택을 복구했다. **해당 C의 일반 함수 반환을 그대로 복원 구현으로
사용할 근거는 없다.** 정확한 assembly 경계와 예외 frame 계약을 유지해야 한다.
반면 recovery의 EIP/CS/DF/recover 변경은 canonical C에도 이미 표현되어 있다.
이를 모두 새로운 디컴파일 누락으로 집계하지 않는다.

Ghidra 스킬을 사용해 원본 assembly, decompiler 해석, Python 모델, 실행 관찰을
분리했다. 기존 정본 DB는 수정하지 않았다. GCC 2.7용 assembly 경계의 구현·빌드
호환성은 아직 검증하지 않았다.

## 재현·보존·잔여 작업

[코딩 전 계획](PLAN.md), [독립 Codex 검토와 보강](CROSS_REVIEW.md),
[잔여 분석 목록](OPEN_ITEMS.md)을 분리했다. Codex 의견은 그대로 신뢰하지 않고
원본 명령·Python 계산·실행 관찰로 대조했다.

```sh
python3 -B 09_validation/reports/continuous-review-20260911-24/trap_review.py
python3 -B 09_validation/reports/continuous-review-20260911-24/audit_results.py
python3 -B 09_validation/reports/continuous-review-20260911-24/verify_artifacts.py
```

[실행 코드](trap_review.py), [독립 검산 코드](audit_results.py),
[주소 게이트](coordinate-gate.json), [native 시도](native-delivery.json),
[정상 대조](normal-high-cs.json), [fault·원본 handler 원시 결과](trap-cases.json),
[집계](trap-review.json), [독립 검산 결과](independent-audit.json),
[재실행 해시 대조](reproducibility.json), [재현 검사 코드](reproduce_results.py),
[입력 해시](input-hashes.json), [실행 전 보존 검사](preservation-before.json),
[실행 후 보존 검사](preservation-after.json), [최종 보존 검사](verification.json),
[산출물 해시](artifact-hashes.json).

원본 바이너리·기존 Ghidra/IDA DB·이전 보고서·07_kernel은 보존했다.
native 예외 전달, page-in 성공·재시작, 다른 예외·권한·대체 스택 및 전체 문맥 전환은
미완료다. 이번 통과를 전체 분석·복원 구현·GCC 2.7 빌드·부팅 완료로 판정하지 않는다.
