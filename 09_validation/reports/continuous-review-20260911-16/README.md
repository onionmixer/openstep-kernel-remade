# 연속 추가검토 — 미확정 호출의 AF 비트와 I/O 순서

대상: OPENSTEP 4.2 mk-183.34.4 / x86. 검토일: 2026-09-11.
원본 SHA-256: `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`.
출발점: [PUSHFD 도달·저장값 사용 검토](../continuous-review-20260911-15/README.md).

## 결론

이전 검토의 `_intr_unregister_irq` 호출 경계 미확정을 **저장된 AF 비트의 직접 호출
경로에 한정해** 좁혔다. POP EAX로 꺼낸 AF 비트는 `_intr_change_mode`, `_eisa_present`,
`_strncmp`의 원본 명령을 추적하면 읽히기 전에 덮어써진다.
일반적인 ABI 가정으로 EAX를 무시한 것이 아니라 AL 부분 쓰기까지 확인했다.

별도로 `_intr_change_mode`의 정본 디컴파일 C가 원본의 모드 저장과 I/O·카운터 순서를
보존하지 않음을 확인했다. 모드가 바뀌는 원본 실행 48건에서는 최종 값과 포트 출력값이
표시된 C의 순서 모형과 같아도 중간 관찰 상태가 달랐다.
최종 상태 일치만으로 해당 C 표현을 복원 근거로 확정하면 안 된다.

원본 실행은 240쌍, 총 480건이며 정의한 assertion과 AF 반전 쌍 비교에서 불일치는 없었다.
이는 함수 일부와 실제 중첩 호출을 합성 하드웨어 상태에서 실행한 결과다.
전체 AF 영향, 전체 IRQ 해제 동작, 실제 하드웨어 또는 GCC 2.7 생성 코드의 증명은 아니다.

## 직접 호출을 따라간 비트 수준 검토

[분석·실행 코드](call_review.py), [경로·원본 문맥·실행 결과](call-review.json).

추적은 `_intr_unregister_irq`의 POP EAX 직후 `0018c581`에서 시작한다.
원본 직접 호출은 다음으로 연결된다.

```text
_intr_unregister_irq
  → _intr_change_mode
      → _eisa_present
          → _strncmp  (아직 EISA 유무를 검사하지 않은 경로)
```

추적 대상은 EAX의 bit 4, 즉 저장된 AF 하나다. EAX/AX/AL의 순수 쓰기는 해당 비트를
덮어쓰며 AH 쓰기는 그렇지 않다. `XOR EAX,EAX`는 이전 값과 무관한 0으로 처리한다.
다른 읽기가 발견되면 미확정으로 중단하도록 했고, 읽은 뒤의 일반적 taint 전파를
구현했다고 주장하지 않는다. 이 경로에서는 그런 읽기 없이 덮어쓰기에 도달했다.

| 최초 덮어쓰기 후보 | 원본 명령 | 해석 |
|---|---|---|
| `00194715` | `MOV EAX,[001e2c50]` | 캐시된 EISA 상태로 전체 EAX 교체 |
| `00101f10` | `MOV AL,[EBX]` | 비교 문자열 byte가 AF 비트 자리를 교체 |
| `00101fb3` | `MOVSX EAX,byte [EBX]` | 문자열 비교 결과 계산 전에 전체 EAX 교체 |
| `00101fa9` | `XOR EAX,EAX` | 0 반환 경로에서 전체 EAX 교체 |

호출 문맥을 포함한 상태 42개를 탐색했고, 종료 전 순환이나 미해결 호출은 없었다.
정적 CFG는 조건의 실현 가능성을 모두 계산하지 않으므로 위 후보에는 이 호출의
인자 조건에서 최초 덮어쓰기가 될 수 없는 경로도 포함된다.
특히 `_eisa_present`는 비교 길이 4를 넘기므로, 처음부터 길이가 0 이하라는
`00101fa9` 도달 경로는 이번 실제 호출 조건을 대표하지 않는다.
480건의 실행에서 최초 덮어쓰기로 관찰된 것은 `00194715` 192건,
`00101f10` 192건, `00101fb3` 96건이다.

이 결과로 이전 보고서의 마지막 호출 경계를 AF 비트에 대해서만 보완한다.
저장 flags 전체, 당시 CPU EFLAGS, 스택의 잔류 기록 또는 interrupt에 의한 관찰까지
폐기됐다고 주장하지 않는다. 간접 진입·예외·비동기 경로는 이 그래프에 없다.

## 원본 실행 쌍 비교

`0018c578`의 마지막 LOCK INC부터 실행하여 PUSHFD/POP EAX가 실제로 AF를 저장하는지
확인한 뒤, 한쪽 실행에서만 EAX에 저장된 AF 비트를 반전했다.
중첩 호출을 모두 원본대로 실행하고, 외부 함수의 `MOV EAX,1` 뒤 `0018c596`에서 멈췄다.
호출을 mock으로 대체하지 않았다. `_strncmp` 원본도 해당 경로의 288건에서 실행했다.

입력 조합:

- EISA 캐시가 absent/present인 조건, 초기 검사 ROM이 일치/불일치/빈 문자열인 조건.
- IRQ 0, 1, 15; IRQ 테이블 항목의 유무; 초기 모드 0 또는 `0xffff`.
- 저장 IF의 두 상태와 counter `0xe` 또는 `0xffffffff`.
- 같은 조건에서 저장된 AF 비트 유지/반전.

모든 쌍에서 실행 주소 순서, 스택 밖 쓰기, 포트 출력 이벤트, 최종 EAX·IF·모드·counter·
EISA 상태가 같았다. 서로 다를 수 있는 스택 기록과 제한하지 않은 caller-clobbered
레지스터 전체를 동일성 검사에 포함했다고 주장하지 않는다.
원본 counter 증가 및 wrap, IF 선택, EISA 캐시 결과와 mode 변경도 Python 예상값과 비교했다.
실행한 명령 바이트가 원본과 같은지 각 주소에서 검사했다.

ROM은 합성 페이지이며 포트 OUT은 Unicorn hook으로 관찰했다.
실제 ROM·EISA/PIC 장치 동작, fault, SMP, 비동기 interrupt는 시험하지 않았다.
바깥 함수 진입부터 IRQ 테이블 해제·mask 갱신을 모두 수행한 실행도 아니다.

## 디컴파일 표현에서 확인한 I/O 순서 손실

[순서 비교 코드](order_review.py), [원본 이벤트와 C 순서 모형](order-review.json).

모드 변경 경로의 원본은 다음 순서를 가진다.

| 순서 | 원본 주소 | 동작 |
|---|---|---|
| 1 | `0018c817` | 새 모드 word를 `001e7720`에 저장 |
| 2 | `0018c827` | 낮은 byte를 포트 `0x4d0`에 출력 |
| 3 | `0018c828` | `001e7618` counter에 LOCK INC |
| 4 | `0018c83a` | 높은 byte를 포트 `0x4d1`에 출력 |
| 5 | `0018c83b` | 같은 counter에 LOCK INC |

반면 정본 C는 낮은 byte 출력, 높은 byte 출력, counter에 2 더하기,
새 모드 저장 순서로 표시된다. 원본의 두 counter 갱신은 한 식으로 합쳐지고,
모드 저장은 출력 뒤에 놓인다. `call-review.json`에 정본 C 전체와 재디코딩 문맥을 보존했다.

모드 변경 실행 48건에서, 첫 포트 출력 때 원본의 모드는 이미 새 값이다.
두 번째 포트 출력 때 counter는 첫 INC를 반영한다.
표시된 C 문장 순서를 직접 옮긴 Python 이벤트 모형은 이 두 관찰을 보존하지 않는다.
최종 모드·counter와 실제 출력 byte 값은 같지만 이벤트 순서는 모두 다르다.

이 모형은 **C 컴파일·실행 결과가 아니다.** 정본 출력의 `out`, `LOCK`, `UNLOCK`은
실제 구현이 정의되지 않은 분석 표기이며, 이번 모형은 LOCK/UNLOCK을 표지로만 취급한다.
특정 C 컴파일러의 순서 보장이나 실행 바이너리 오류를 입증한 것으로 해석하면 안 된다.
원본에서 필요한 저장 시점·독립 RMW·I/O 순서를 명시적으로 보존해야 한다는 증거다.
단순 volatile 적용이나 기존 Ghidra 언어 정의 변경은 이번에 하지 않았다.

## 보존·재현과 남은 작업

```sh
python3 -B 09_validation/reports/continuous-review-20260911-16/call_review.py
python3 -B 09_validation/reports/continuous-review-20260911-16/order_review.py
python3 -B 09_validation/reports/continuous-review-20260911-16/verify_artifacts.py
```

[검증 코드](verify_artifacts.py), [검증 결과](verification.json),
[입력 해시](input-hashes.json), [산출물 해시](artifact-hashes.json).
이전 manifest 전체, 정본 Ghidra 프로젝트와 기존 실험 사본을 재검증한다.
입력 해시는 이번 종료 시 기록하며, 불변 여부는 이전 manifest와 대조한다.

Ghidra 스킬에 따라 디컴파일 표현을 사실로 확정하지 않고 원본 명령·제어흐름·실행 이벤트와
분리해 검토했다. 새 Ghidra/IDA 재분석이나 정본 수정은 없으며 원본·기존 보고서·`07_kernel`도
변경하지 않았다. 주소, 비트, 길이, 경계값, 계수, 차이 및 해시 계산은 모두 Python이다.

남은 사항은 분석 IR의 flags·원자적 RMW·I/O 순서 보존, 비동기 상태 저장·복원,
같은 입력의 IDA 대조, fault/SMP 조건, GCC 2.7 실컴파일·링크·부팅이다.
이번 저장 AF 비트 경로를 좁힌 것으로 전체 분석 완료를 선언하지 않는다.
