# 연속 추가검토 — PC 에뮬레이션의 fault landing 문맥

대상: OPENSTEP 4.2 mk-183.34.4 / x86. 검토일: 2026-09-11.
원본 SHA-256: `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`.
선행 결과: [포인터 출처](../continuous-review-20260911-01/README.md),
[copy/accessor 실행 검토](../continuous-review-20260911-02/README.md).

## 결과와 판정 범위

PC 에뮬레이션의 복구 목적지 36곳 모두에 대해, 실제 소유 함수 진입부터
복구 주소 설정·FS 접근 직전 fault 주입·원본 복구 helper·landing·호출자 복귀까지 실행했다.
부분 접근 뒤의 fault도 포함한 **119개 bounded fixture**에서 호출자 스택과 보존 레지스터가 일치했다.

이전 copy/accessor 결과와 합치면 기존에 식별한 복구 목적지 50곳 모두에
제한된 fault 실행 근거가 생겼다. 이는 “모든 fault 경로·입력·인터럽트 동작을 검증했다”는 뜻은 아니다.
레지스터 기반 복구 주소 저장이나 계산된 별칭을 포함한 전역 완전성은 아직 미확정이다.

Ghidra·IDA 스킬의 원본 사실과 도구 해석 분리 원칙을 적용했다.
이번 실행 증거는 원본 바이트이며, 기존 DB·export를 수정하거나 커널 구현을 시작하지 않았다.
주소·descriptor·집계·에뮬레이터 제어 등 모든 계산은 Python으로 수행했다.

## P04 — 함수 진입부터 실행한 복구 문맥 검사

함수 중간에서 임의로 레지스터를 맞추어 성공한 것으로 처리하지 않았다.
원본 함수 진입점에 합성 thread/state 인자를 전달하고 그 함수의 prologue부터 실행했다.
fixture의 주요 자료는 다음과 같다.

- thread → PCB → PC task → PC common/context 포인터 연결.
- REAL용 CS:IP·SS:SP 및 IVT 데이터.
- PROT용 소프트웨어 IDT/LDT descriptor와 사용자 코드·스택 버퍼.
- BOP opcode, interrupt/trap 번호, gate 종류 및 stack descriptor 폭.

합성 descriptor는 커널의 PC 에뮬레이션 코드가 소프트웨어로 읽는 데이터다.
이를 실제 CPU GDT/IDT로 설치한 것은 아니다.

목표 복구 주소가 `thread + 0x74`에 설정된 뒤 FS 명령이 실행되기 직전에 fault를 주입했다.
원본 `FUN_001924a0`을 별도 합성 프레임/스택에서 실행하여 recover 해제와 복귀 EIP/EFLAGS를 확인한 뒤,
fault 당시 범용 레지스터를 복원하고 해당 landing으로 이동했다.
인터럽트 진입과 IRETD 자체는 여전히 harness의 모델이다.

최종적으로 확인한 조건:

- 원래 호출자의 복귀 주소 도착.
- 호출자 ESP와 EBX/ESI/EDI/EBP 보존.
- recover 해제 및 원본 helper가 갱신한 프레임의 일치.
- 지정하지 않은 메모리 fault나 임의의 외부 함수 성공 대체가 없음.

| 검사 항목 | 결과 |
|---|---:|
| 후보 복구 목적지 | 36 |
| 각 목적지의 첫 접근 fault fixture 확보 | 36 |
| 이를 찾기 위해 실행한 fixture 탐색 | 57 |
| 같은 입력에서 후속 접근에 주입한 추가 fault | 83 |
| 복구·호출자 복귀 검사 통과 | 119 |
| 해당 소유 함수 | 14 |
| 해당 함수의 FS instruction 시작점 | 47 |
| 실제 fault를 주입한 고유 FS 시작점 | 47 |
| 이 함수군에서 미검사 FS 시작점 | 0 |

57은 탐색 시도 수이지 57개 모두 성공했다는 뜻이 아니다.
탐색 중 외부 `_PCcallMonitor` 등으로 향하는 경우에는 성공 stub을 넣지 않고 경계를 기록했다.
목표 접근 횟수가 끝나는지 확인한 별도 probe 36개도 있으며,
이 중 24개는 정상 반환, 12개는 외부 호출 경계에서 중단됐다. 이 probe들은 119개 통과 수에 넣지 않았다.

모든 시행 기록은 [실행 결과](pc-fault-execution.json)에 있다.
`verified`, `later_access_verified`, `attempts`, `end_of_sequence_probes`를 구분해 보존했다.

## P05 — 복구 후 반환값이 항상 0인 것은 아님

목적지별 첫 fault fixture에서는 35곳이 0을 반환했으나,
`_PCemulateREAL`의 `0x001a2614`는 후속 예외 처리 경로를 거쳐 1을 반환했다.

해당 fixture의 실행 흐름:

```text
_PCemulateREAL 진입
  → 0x001a2603의 명령 byte 읽기 직전에 fault
  → 원본 복구 helper
  → 0x001a2614 landing
  → 0x001a2683에서 FUN_001a2384 호출
  → 예외 전달용 사용자 스택/IVT 처리
  → 0x001a26c7의 RET, EAX = 1
```

합성 입력에서 saved IP는 `0x100`에서 `0x200`으로, saved SP는 `0x800`에서 `0x7fa`로 바뀌었다.
이 변화는 fixture에 준비한 예외 전달 경로의 처리 결과다.
“모든 recovery fragment를 `return 0`으로 복원한다”는 규칙은 원본과 맞지 않는다.
그렇다고 해당 landing이 모든 입력에서 항상 1을 반환한다는 뜻도 아니다.

목적지별 원래 소유 함수, 관찰된 반환값, 실제 RET 위치, 복구 후 호출 목록과 sample trace는
[복구 문맥 명세](recovery-contracts.json)에 기록했다.
이들은 독립 ABI callback 함수가 아니라 원래 함수의 스택을 사용하는 비지역 landing이다.

## P06 — 실패 반환과 사용자 메모리의 원상 복구는 다름

descriptor의 첫 word를 읽은 뒤 두 번째 접근에서 fault를 발생시키거나,
사용자 스택의 일부 word를 쓴 뒤 후속 접근에서 fault를 발생시키는 경우를 포함했다.

0을 반환했지만 사용자 스택 버퍼의 일부 변경이 남은 fixture는 23개다.
반면 이번 0 반환 fixture들의 saved-state 버퍼는 진입 시 값과 일치했다.
이를 모든 입력에 대한 트랜잭션적 원상 복구 보장으로 확대 해석해서는 안 된다.

예: `FUN_001a20d4`에서 복구 목적지 `0x001a230c`가 설정된 후
`0x001a22f8`의 IVT 읽기 직전에 fault를 주입했다.
함수는 실패 0을 반환하고 saved IP/SP를 원래 값으로 되돌렸지만,
앞서 사용자 스택에 기록한 `0x7fa`부터 `0x7ff` 위치의 바이트는 남았다.
해당 범위·차이는 Python으로 계산한 buffer 비교 결과다.

따라서 복원 구현에 “실패면 모든 사용자 메모리 변경 취소”를 임의로 추가하면 안 된다.
이 관찰만으로 보안 취약점이나 악용 가능성을 주장하지 않는다.

## 기존 복구 후보의 통합 상태

[통합 검증 색인](recovery-validation-index.json):

- copy/accessor 복구 목적지: 14곳에 제한된 실행 근거 있음.
- PC 에뮬레이션 복구 목적지: 36곳에 제한된 실행 근거 있음.
- 기존 후보 50곳 중 실행 fixture가 전혀 없는 목적지: 없음.

이는 기존 후보 집합에 대한 결과다. 코드 주소 즉시값 패턴 밖의 추가 복구 경로가 없다는 증명은 아니다.
원본 함수의 C 출력에 recovery 문맥이 올바로 결합됐다는 판정도 아니다.
원래 함수와 fragment의 연결을 명세했지만 기존 분석 DB와 C export는 그대로 남아 있다.

## 재현과 제한

```sh
python3 -B 09_validation/reports/continuous-review-20260911-03/pc_fault_execution.py
```

Python/Unicorn의 별도 메모리에서 원본 명령을 실행한다. 호스트 커널이나 실제 장치에 접근하지 않는다.
이전 단계의 입력 로더와 Python helper를 읽어 재사용하며, 새 결과는 이 디렉터리에만 기록한다.
의도적으로 범위 밖 호출을 성공 처리하지 않고 중단·기록한다.

남은 한계:

- synthetic-before-instruction fault이므로 실제 CPU의 모든 fault 시점·부분 store 특성을 증명하지 않는다.
- 실제 trap entry/IRETD, segment selector의 권한·limit, 인터럽트 교차 실행은 별도 검토 대상이다.
- 입력 fixture는 유한하다. 모든 descriptor 조합, wraparound, thread 수명 또는 잘못된 인자를 검증하지 않았다.
- 후속 외부 호출로 넘기는 경로 전체는 이번 통과 수에 포함하지 않았다.
- GCC 2.7 컴파일이나 부팅 시험이 아니다.

## 다음 우선 검토

복구 목적지 집합의 실행 근거가 보강됐으므로 다음은 기존 확정 분석 오류의 교정 조건을 점검한다.
R01의 이웃 함수 혼입과 R02의 padding 오인을 제거할 제어 흐름 계약을
별도 분석 실험으로 검증하고, 원본/기존 export와 분리한 결과를 비교할 필요가 있다.
기존 IDA 세그먼트 표현 불일치, 실제 trap 프레임, recover 수명 및 전역 별칭 검토도 계속 남긴다.

전체 목표는 미완료다. 이번 단계의 진전은 복구 문맥의 실행 증거와 구체적 복원 제약을 추가한 것이다.
