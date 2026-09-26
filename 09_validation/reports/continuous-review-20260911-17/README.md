# 연속 추가검토 — 포트 I/O 전수 대조와 인터럽트 제어 손실

대상: OPENSTEP 4.2 mk-183.34.4 / x86. 검토일: 2026-09-11.
원본 SHA-256: `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`.
출발점: [직접 호출의 AF 비트 및 I/O 순서 차이](../continuous-review-20260911-16/README.md).

## 결론

현재 export의 원본 명령 전체에서 포트 I/O와 지정한 인터럽트 제어 명령을 재검색했다.
해당 명령을 가진 함수 78개를 새 Ghidra 읽기 전용 사본에서 다시 디컴파일하고,
raw/high P-code를 주소별로 대조했다. 새 C는 provenance header를 제외하면 정본과 모두 같다.
따라서 아래 차이는 이번 추출에서 새롭게 발생한 출력 변화가 아니다.

CLI/STI 104곳은 raw P-code에 IF 갱신으로 모두 남지만, high P-code에서는
103곳의 원래 주소에 IF 쓰기가 남아 있지 않다. 해당 소유 함수 중 32개는 high P-code
전체에도 IF 쓰기가 없다. 다만 주소별 부재 수만으로 모든 함수의 동작 차이를 증명하지 않는다.

`_intr_disbl`, `_intr_enbl`의 실제 원본 실행과 작은 high-IR 실행기를 비교한 16건에서는
반환값은 모두 같지만 최종 IF가 8건 다르다. 인터럽트 enable/disable helper의
핵심 부작용과 `_intr_enbl`의 인자에 따른 선택이 사라지는 구체적 반례다.

포트 I/O 483곳은 모두 같은 주소의 CALLOTHER 표기를 하나씩 유지한다.
이것은 명령 표기 보존이지 주변 메모리·counter·I/O 순서까지 보존한다는 뜻이 아니다.
이전 보고서에서 확인한 순서 문제는 여전히 남는다.

## 전수 인벤토리의 정확한 범위

[검색 코드](scan.py), [명령별 원본 바이트·주소·소유 함수](scan.json).

함수 export 5,253개 단위, 고유 instruction head 286,091개를 독립 재디코딩했다.
현재 export 경계 안의 IN/OUT, INS/OUTS 계열, CLI/STI/PUSHF/POPF/IRET 계열을 검색했다.
실제로 발견된 항목은 다음과 같다.

| 명령 | 지점 수 |
|---|---:|
| OUT | 442 |
| IN | 41 |
| CLI | 57 |
| STI | 47 |
| PUSHFD | 22 |
| POPFD | 5 |
| IRETD | 6 |
| 합계 | 620 |

포트 I/O는 483곳, 나머지 지정한 제어 명령은 137곳이다.
포트 I/O operand 폭은 byte 474곳, word 7곳, dword 2곳이다.
검색한 string I/O 명령은 발견되지 않았다. 미발견 코드가 없다는 증명이나
MMIO, 모든 제어 레지스터 접근, 모든 privileged instruction의 전수 검토를 뜻하지 않는다.

## 새 Ghidra 추출과 보존

[읽기 전용 실행기](extract_pcode.py), [실행 명령](command.json), [실행 결과](run-result.json),
[raw/high P-code](exports/pcode.json).

정본 프로젝트를 새 `io-control-review-20260911` 사본으로 복사하고,
독립 설정·캐시 경로의 새 JVM에서 `-readOnly -noanalysis`로 열었다.
기존 `WaitPcodeEvidence.java`를 수정 없이 재사용했다. Java는 Ghidra API 자료 추출만 하며,
함수 선택·주소·갯수·마스크·해시·차이 계산은 Python으로 수행한다.
이번 작업은 재디컴파일이며 analyzer를 다시 실행한 것이 아니다.

대상 78개 함수는 모두 decompileCompleted 상태였다. 정본·새 사본의 기존 프로젝트 파일
9개는 실행 전후 해시가 일치했다. 정본·과거 실험 사본·기존 보고서는 수정하지 않았다.
추출 C의 완성 상태는 해당 코드가 올바른 커널 복원 소스라는 판정이 아니다.

## CLI/STI의 raw/high 차이

[대조 코드](audit_pcode.py), [주소별 결과와 언어 정의 근거](pcode-audit.json).

설치된 x86 언어 정의에서 IF register 위치를 Python으로 해석했다.
CLI는 `IF = 0`, STI는 `IF = 1`이라는 raw COPY다.
이 형태는 원본 CLI/STI 104곳 모두에서 확인했다.

high P-code에서 같은 주소의 IF 쓰기가 남은 곳은 `__bios32`의 `00187160` CLI 하나다.
그 함수에는 뒤따르는 far call의 IF INDIRECT 표현도 있다.
이 예외를 누락시키거나 모든 CLI/STI가 일괄 삭제됐다고 표현하지 않았다.

나머지 103곳은 원래 주소의 IF 출력이 없고, 32개 소유 함수는 high 단계에서 IF 출력 자체가 없다.
raw 명령 효과가 내부 register 값으로만 모델링된 상태와 high 단계의 표현 손실을 구분했다.
이번 증거만으로 최적화 내부의 특정 pass가 유일한 원인이라고 확정하지 않는다.
모든 IF 부재가 동일한 실행상 문제를 일으킨다는 주장도 아니다.

### 원본 단일 명령과 raw IF 모델

[실행 코드](if_execution.py), [입력별 결과](if-execution.json).

CLI/STI 104곳 각각에서 입력 IF·AF·CF를 바꾼 832건을 원본 바이트로 실행했다.
전체 EFLAGS를 raw COPY에 대응한 Python 예상값과 비교했고 불일치는 없었다.
이는 IF 비트 갱신과 나머지 입력 flags 보존을 해당 조건에서 확인한 것이다.
STI의 interrupt shadow, 권한 검사, 가상화된 IF, 실제 interrupt 전달은 검증하지 않았다.
따라서 raw COPY가 STI/CLI의 모든 CPU 의미를 완전하게 모델링한다는 결론은 아니다.

### 두 helper의 high-IR 반례

원본 `_intr_disbl`은 IF를 끄고 이전 IF를 반환한다.
원본 `_intr_enbl`은 스택 인자가 0인지에 따라 CLI/STI를 선택하고 이전 IF를 반환한다.
새 high P-code는 두 함수 모두 이전 IF의 하위 bit를 반환하는 단일 블록으로 단순화된다.
`_intr_enbl`의 인자 load와 해당 분기도 남지 않는다.

추출된 INT_AND/COPY/RETURN만 허용하는 Python 실행기로 high IR을 실행하고,
원본은 합성 호출 스택에서 실제 함수 전체를 실행했다.
입력 IF·AF와 enable 인자 0/1/`0xffffffff`를 바꾼 비교 16건에서
반환값 불일치는 0건, 최종 IF 불일치는 8건이다.
원본의 callee-saved register와 호출 스택 복원도 확인했다.

이는 반환값만 확인하는 회귀검사가 놓치는 반례다.
최소 high-IR 실행기는 범용 decompiler interpreter가 아니며,
비교 범위도 모든 flags·메모리 상태가 아니라 반환값과 IF다.
high IR에 비동기 interrupt를 추가로 실행한 시험은 아니다.

## 포트 I/O 표기와 반환 폭

IN/OUT 483곳 모두에서 raw CALLOTHER와 같은 종류의 high CALLOTHER가
같은 원본 주소에 정확히 하나씩 남았다. raw operand 폭은 원본 명령 폭과 모두 일치했다.
high 데이터 폭까지 직접 비교 가능한 477곳은 일치했다.

나머지 6곳은 잘못된 폭으로 바뀐 것으로 판정하지 않았다.
IN의 결과 varnode가 없어 high 표기만으로 반환 폭을 읽을 수 없는 경우다.
I/O 연산 자체는 유지된다.

| 함수 | 결과 varnode가 없는 IN 주소 |
|---|---|
| `_get_dma_count` | `00189654`, `0018966c`, `00189692` |
| `_VGASetGraphicsMode` | `00197a16`, `00197af1`, `00197c14` |

해당 원본은 모두 `IN AL,DX`이며 byte 입력이다.
복원 시 반환값을 버리더라도 실제 read와 그 폭·장치 부작용을 원본 근거로 보존해야 한다.
high 표기만 보고 폭을 임의로 선택하거나 I/O를 삭제하면 안 된다.
이번에는 이 장치들의 상태 전이·포트 operand 값·fault·버스 순서를 전부 실행하지 않았다.

## 재현 및 미완료 판정

최초 추출 순서:

```sh
python3 -B 09_validation/reports/continuous-review-20260911-17/scan.py
python3 -B 09_validation/reports/continuous-review-20260911-17/extract_pcode.py
python3 -B 09_validation/reports/continuous-review-20260911-17/audit_pcode.py
python3 -B 09_validation/reports/continuous-review-20260911-17/if_execution.py
python3 -B 09_validation/reports/continuous-review-20260911-17/verify_artifacts.py
```

추출기는 기존 새 사본을 덮어쓰지 않도록 재실행을 거부한다.
보존된 추출물의 재검사는 audit/if_execution/verify 단계로 수행한다.
다시 Ghidra를 실행하려면 별도의 새 출력·사본 경로가 필요하다.

[보존 검증 코드](verify_artifacts.py), [검증 결과](verification.json),
[입력 해시](input-hashes.json), [이번 산출물 해시](artifact-hashes.json).

Ghidra 스킬에 따라 원본, raw 의미, high/C 해석과 실행 증거를 분리했다.
IF/RMW/I/O 의미를 보존하는 분석 IR 수정은 아직 적용하지 않았다.
원본 바이너리·Ghidra/IDA 정본·`07_kernel`은 변경하지 않았다.
MMIO·STI 지연 효과·fault·SMP·비동기 이벤트, 같은 입력의 IDA 검토,
GCC 2.7 실컴파일·링크·부팅은 남아 있다. 전체 분석 완료는 아직 아니다.
