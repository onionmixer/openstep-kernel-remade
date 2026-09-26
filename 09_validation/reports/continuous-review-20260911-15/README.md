# 연속 추가검토 — AF 도달 경로와 저장된 EFLAGS의 사용

대상: OPENSTEP 4.2 mk-183.34.4 / x86. 검토일: 2026-09-11.
원본 SHA-256: `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`.
출발점: [INC/DEC의 단일 읽기 계약 및 Ghidra AF 차이](../continuous-review-20260911-14/README.md).

## 결론

이전 검토에서 발견한 AF 차이의 영향 범위를 좁혔다. 현재 export에서 발견된 PUSHFD
22곳을 원본 바이트로 재확인하고, 함수 내부 제어흐름을 거슬러 올라가 AF의 마지막
정의 지점을 조사했다. 이 중 6곳에는 LOCK INC의 AF가 도달 가능한 로컬 경로가 있다.

그 6곳 중 5곳은 PUSHFD/POP EAX로 꺼낸 값을 읽지 않고 `MOV EAX,1`로 덮어쓴다.
다른 1곳은 값을 덮어쓰기 전에 함수 호출에 도달하므로, 이번 로컬 검사에서는 미확정이다.
**모든 AF 차이가 무해하다는 결론은 아니다.** 비동기 interrupt/exception, 호출 경계,
BIOS 반환 상태와 전체 flags 복원은 별도 검증이 필요하다.

원본 명령 실행 416건은 정의한 관찰값에서 불일치가 없었다. 이 수치는 서로 다른
범위의 함수·접두부·접미부 검사를 합한 것이며, 전체 커널 경로 수나 전체 입력 공간이 아니다.
Ghidra 표현의 AF 누락 자체를 수정하거나, 해당 C 출력을 실행한 시험도 아니다.

## AF 도달 분석의 방법과 한계

[분석 코드](reaching_flags.py), [지점별 경로와 결과](reaching-flags.json).

원본 바이트를 Capstone으로 재디코딩하고 기존 export의 명령 경계와 일치시킨 뒤,
직접 분기와 fallthrough의 선행 노드를 역방향으로 탐색했다. CALL은 알 수 없는
AF 반환값, POPFD/IRET는 복원된 flags, 함수 진입은 외부에서 들어온 flags로 구분했다.
AF를 정의하지 않는 명령은 통과하고, undefined AF는 정상 정의와 구분한다.
가변 shift count는 flags를 보존할 가능성도 남긴다.

| 항목 | 수 |
|---|---:|
| PUSHFD 지점 | 22 |
| 해당 함수 단위 | 13 |
| INC/DEC 도달 원점을 가진 지점 | 6 |
| 원점 기록: INC/DEC | 6 |
| 원점 기록: 그 외 AF 정의 | 13 |
| 원점 기록: 함수 진입 | 6 |
| 원점 기록: 불투명 호출 | 2 |
| 원점 기록: flags 복원 | 1 |

한 PUSHFD에 여러 원점이 가능하므로 원점 기록 수와 지점 수는 다르다.
각 INC 도달 지점에는 PIC 설정이 바뀌지 않아 INC를 건너뛰는 CMP 경로도 있다.
기록된 witness는 정적 경로이지 실제 실행 또는 경로 실현 가능성의 증명이 아니다.
함수 밖 진입, 간접 분기의 전체 목적지, 미발견 코드, 비동기 이벤트는 포함하지 않는다.

## LOCK INC 이후 저장값의 행방

[로컬 사용 분석 및 실행 코드](snapshot_review.py), [전체 결과·원본 문맥](snapshot-review.json).

| 함수 | INC | PUSHFD | 저장값 판정 |
|---|---|---|---|
| `_intr_register_irq` | `0018c490` | `0018c497` | `0018c4a5`에서 EAX 전체 덮어쓰기 |
| `_intr_unregister_irq` | `0018c578` | `0018c57f` | `0018c58c` 호출 경계에서 미확정 |
| `_intr_enable_irq` | `0018c615` | `0018c61c` | `0018c629`에서 EAX 전체 덮어쓰기 |
| `_intr_disable_irq` | `0018c6ac` | `0018c6b3` | `0018c6bd`에서 EAX 전체 덮어쓰기 |
| `_intr_change_ipl` | `0018c78f` | `0018c796` | `0018c7a1`에서 EAX 전체 덮어쓰기 |
| `_intr_change_mode` | `0018c83b` | `0018c842` | `0018c84d`에서 EAX 전체 덮어쓰기 |

POP EAX 이후 모든 로컬 후속 경로를 따라가 EAX/AX/AL/AH 읽기, EAX 전체 쓰기,
호출·반환·함수 밖 이동 및 순환 여부를 검사했다. 폐기 판정을 내린 5곳은
저장값 읽기 없이 모든 로컬 경로가 전체 덮어쓰기에 도달한다.
분기 조건은 앞서 저장한 IF를 대상으로 한 별도 CMP/TEST에서 나온다.
이 판정은 EAX로 꺼낸 저장값에 관한 것으로, 중간 CPU 상태가 인터럽트에 관찰되지
않는다는 증명도, 일시적인 스택 기록이 사라진다는 주장도 아니다.

`_intr_unregister_irq`는 STI/CLI 뒤 `_intr_change_mode`를 호출한다.
그 함수 역시 EAX를 덮어쓰기 전에 `001946e0`을 호출하고, 그 안에는 조건부 추가 호출이 있다.
통상 호출 규약만 믿고 입력 EAX가 쓰이지 않는다고 단정하지 않았다.
이번 실행은 `0018c58c`의 CALL 직전에 멈췄으며, 호출 결과를 mock으로 만들어 통과시키지 않았다.

## 원본 실행 검사

모든 실행은 합성 메모리·레지스터를 사용하고 원본 instruction bytes를 그대로 실행했다.
실행한 주소마다 메모리의 코드가 원본과 같은지도 확인했다. 관찰·예상값·마스크·집계는
모두 Python으로 계산했다.

| 검사 | 실행 수 | 확인한 사항 |
|---|---:|---|
| `_intr_disbl`, `_intr_enbl` 전체 함수 | 32 | 반환값은 입력 IF, 실행 후 IF는 disable 또는 인자 조건과 일치; callee-saved·스택 보존 |
| IRQ 함수의 첫 PUSHFD부터 IF 추출까지 | 96 | `SHR 9` 및 `AND 1` 결과는 입력 IF; AF 변화는 이 결과에 영향 없음 |
| IRQ의 마지막 LOCK INC부터 제한된 접미부 | 240 | counter 증가, 실제 AF, 저장 flags, IF 분기, 저장 AF 반전 시 판정 경계의 값 |
| call/trap/syscall 진입 접두부 | 48 | 입력 flags 전체가 프레임 복사 위치에 기록됨; AF도 유지 |
| 합계 | 416 | 설정한 assertion 불일치 없음 |

IRQ 접미부 시험은 counter 경계값, 이전 AF, 저장된 IF를 바꿨다. PUSHFD/POP EAX 뒤
저장값의 AF만 의도적으로 반전한 조건도 검사했다. 폐기되는 5곳에서는 마지막 EAX가
항상 1이며 IF 선택도 같았다. 미확정 함수에서는 반전한 EAX가 CALL 직전까지 남는다.
이 반전은 차이의 전파를 보는 합성 조건이지 Ghidra P-code 전체 실행이 아니다.
직전 OUT 명령, 전체 IRQ 등록·해제 경로, 실제 PIC 장치는 실행하지 않았다.

첫 PUSHFD의 IF 추출 시험은 register/stack의 해당 구간만 실행한다.
전체 IRQ 함수가 AF와 무관하다고 확대 해석하지 않는다.
standalone enable/disable 함수의 산술 연산 후 모든 상태 flags가 보존된다고 주장하지도 않는다.

## 전체 flags를 보존하거나 외부와 교환하는 나머지 문맥

### call/trap/syscall 진입

`_machdep_call_` (`00186ddc`), `_mach_kernel_trap_` (`00186e3c`),
`_unix_syscall_` (`00186e9c`)는 진입 시 PUSHFD의 전체 값을 프레임에 옮긴다.
접두부 실행에서 AF를 포함한 저장값을 확인했다. 합성 진입 스택이며 segment selector
설정 전에 멈췄으므로 실제 call gate, 특권 전환, IRETD의 검증은 아니다.
이 지점의 AF는 함수 밖에서 들어오므로 앞선 counter INC와의 연결도 증명하지 않았다.

### BIOS32

`__bios32`의 `00187112`는 호출 전 flags를 저장하고 `001871c8`에서 POPFD로 복원한다.
원본은 far-call operand를 수정한 뒤 BIOS를 호출한다. 반환 후 `00187168`에서 다시
flags를 저장하며, 그 하위 word를 `001e17cc`를 거쳐 출력 구조체 `[EDX+0x28]`에 기록한다.
AF도 이 word에 포함되므로 해당 상태를 단순 IF 값으로 축소하면 안 된다.
이번 검토는 정적 원본 문맥 확인이며 BIOS를 실행하거나 호출 전후 ABI를 입증하지 않았다.

### CPU 기능 검사

`0018ac31`, `0018ac84`, `0018ac8e`의 저장값은 AC/ID bit 설정·검사와 POPFD 복원에 관여한다.
첫 저장점의 AF 원점은 로컬 `SUB ESP,4`, 다음은 불투명 호출, 마지막은 POPFD이다.
AF 자체를 조건으로 검사하는 명령을 여기서 확인한 것은 아니지만, 전체 flags 복원이 있으므로
저장값 전체를 불필요하다고 판정하지 않았다. CR0, WBINVD, CPUID 및 이전 검토의
decompiler 분기 누락 문제는 이번 제한된 시험으로 해결되지 않는다.

## 보존·재현 및 미완료 항목

실행 순서:

```sh
python3 -B 09_validation/reports/continuous-review-20260911-15/reaching_flags.py
python3 -B 09_validation/reports/continuous-review-20260911-15/snapshot_review.py
python3 -B 09_validation/reports/continuous-review-20260911-15/verify_artifacts.py
```

[검증 코드](verify_artifacts.py), [검증 결과](verification.json),
[입력 해시](input-hashes.json), [이번 산출물 해시](artifact-hashes.json).
이전 보고서 해시와 정본 Ghidra 프로젝트 및 기존 실험 사본을 다시 확인한다.
입력 해시는 이번 검사 종료 시 기록하며, 원본·정본 불변 여부는 이전 manifest와의 대조로 판단한다.

Ghidra 스킬에 따라 기존 export의 해석을 원본 명령과 분리하고, 독립 재디코딩·실행으로
교차검토했다. 이번에는 새 Ghidra 분석이나 IDA 재수출을 수행하지 않았다.
원본 바이너리, Ghidra/IDA 정본, 기존 보고서, `07_kernel`은 수정하지 않았다.

남은 핵심 사항은 호출 경계를 넘는 AF/숨은 입력 추적, 비동기 flags 저장·복원,
AF 누락과 중복 읽기의 분석 파이프라인 통합 처리, 실제 LOCK·fault 동작, 같은 입력의
IDA 비교, GCC 2.7 실컴파일·링크·부팅이다. 전체 분석 완료 판정은 아직 내리지 않는다.
