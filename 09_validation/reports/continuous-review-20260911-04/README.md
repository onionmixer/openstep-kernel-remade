# 연속 추가검토 — 비복귀 계약의 가역적 Ghidra 실험

대상: OPENSTEP 4.2 mk-183.34.4 / x86. 검토일: 2026-09-11.
SHA-256: `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`.
기존 문제: [R01/R02 상세보고서](../deep-review-20260911/README.md),
[예외 복귀 F01](../cautious-followup-20260911/README.md).

## 결과

**비복귀 속성을 보완하면 기존 C 출력의 이웃 함수 혼입과 잘못된 ObjC 오류 경로가 사라진다**는
재현 가능한 근거를 확보했다. 속성을 되돌리면 기존 결과도 정확히 다시 나타났다.

검사한 함수 44개 중 C 출력 37개가 바뀌었으며, 복원 단계의 44개 C 출력은 baseline과 정확히 일치했다.
baseline 44개도 기존 `full-pass5` C와 export용 머리말을 제외하고 일치했다.
이는 새 프로젝트 상태나 decompiler cache의 우연한 차이로 설명되는 결과가 아님을 뒷받침한다.

단, **속성 변경만으로 padding의 잘못된 instruction 분류까지 고쳐지지는 않았다.**
또한 기존 프로젝트와 최종 export는 그대로이므로 이를 canonical 분석 전체의 교정 완료로 보지 않는다.

## 안전한 실험 구성

Ghidra·IDA 스킬에 따라 원본, 기존 도구 자료, 실험 해석을 분리했다.
Java는 Ghidra API 속성을 변경하고 도구 결과를 추출하는 데만 사용했다.
주소 비교·바이트 비교·해시·개수 및 변화량 검증은 모두 Python으로 수행했다.

기존 프로젝트의 저장된 파일을 다음 위치로 복사하고 파일 해시가 같은지 확인했다.

`04_ghidra/projects/experiments/noreturn-review-20260911/`

Ghidra 12.1의 해당 복사본을 `-readOnly -noanalysis`로 열었다.
프로그램 저장을 요청하지 않고 다음 단계를 실행했다.

1. `baseline`: 변경 전의 함수 본문, listing, C와 p-code 주소 추출.
2. `noreturn`: 아래 속성만 변경한 뒤 새 decompiler 인스턴스로 동일 자료 추출.
3. `restored`: 원래 속성으로 되돌린 뒤 다시 추출.
4. 임시 transaction을 취소하고 종료.

기존 프로젝트 파일 9개는 실행 전후 해시가 일치했다.
기존 원본 바이트나 함수 경계, calling convention, signature, instruction flow override는 수정하지 않았다.
실험 중 뽑은 모든 대상 listing의 바이트도 원본 파일과 Python으로 대조했다.

## 변경한 속성과 근거

| 함수 | 임시 변경 | 앞선 원본 근거 |
|---|---|---|
| `_jump_label` | `noreturn=true` | 저장된 ESP/복귀 주소로 비지역 복귀; 현재 CALL 다음으로 정상 반환하지 않음 |
| `___objc_error` | `noreturn=true` | 기본 오류 처리 경로로 이어짐 |
| `__objc_error` | `noreturn=true` | `_abort` → panic/종료 경로 |
| `__return_with_state` | `noreturn=true` | 현재 복귀 주소를 버리고 상태 프레임에서 IRETD |
| `_thread_exception_return` | `noreturn=true` | 위 상태 복귀 경로로 종료 |
| `_thread_syscall_return` | `noreturn=true` | 위 상태 복귀 경로로 종료 |

여기서 noreturn은 현재 호출자의 fallthrough로 돌아오지 않는다는 분석 계약이다.
`_jump_label`처럼 다른 저장 문맥으로 이동하는 동작을 “CPU가 영원히 멈춤”으로 바꾸는 것이 아니다.
표준 C longjmp와 동일한 인자/반환값 ABI라는 의미도 아니다.

이번 실험은 이 속성 묶음의 효과를 확인했다. 각 속성이 개별적으로 반드시 필요한 최소 집합인지까지
분리 실험한 것은 아니며, 다른 함수로의 전이적 비복귀 속성 전파도 완료하지 않았다.

`__switch_tss`, `__call_with_stack`, `_objc_msgSend`, `_NXAllocErrorData`는 대조 대상으로 포함했으며
이 함수들의 C는 바뀌지 않았다. 문맥 재개가 가능한 함수를 일괄 noreturn 처리하지 않았다.

## R01 — 이웃 함수 혼입 제거 확인

`_NXDefaultExceptionRaiser`의 baseline p-code는 선언된 함수 본문 밖 주소 15개를 포함했다.
비복귀 속성 단계에서는 이 주소들이 사라지고, 원래 `_jump_label` 호출에서 C가 끝난다.
기존에 섞여 있던 다음 함수의 `_realloc`·잠금 처리 코드가 더 이상 출력되지 않는다.

- [변경 전 C](exports/baseline/001cad48.c)
- [비복귀 속성 적용 C](exports/noreturn/001cad48.c)
- [속성을 되돌린 C](exports/restored/001cad48.c)

원래 함수 본문 범위를 줄여서 문제를 숨긴 것이 아니다. 세 단계의 본문 범위와 listing은 같았다.
`_NXDefaultExceptionRaiser` 자신의 noreturn 속성을 바꾼 것도 아니다. 호출 대상의 계약이 달라진 결과다.

판정: R01의 잘못된 fallthrough를 제거할 **검증된 교정 조건**을 확보했다.
아직 최종 분석 프로젝트에 적용한 것은 아니며 나머지 타입/ABI의 정확성은 별도다.

## R02 — 잘못된 C 경로 제거와 listing 분류 미해결을 구분

`__objc_msgForward`의 baseline p-code에는 instruction 시작점이 아닌
`0x001cebff`, `0x001cec02`, `0x001cec05`, `0x001cec07`이 있었다.
비복귀 속성 단계에서는 이 주소가 모두 사라졌고, C도 `___objc_error` 호출에서 끝난다.
잘못된 byte 덧셈과 `in(0x8b)` 표현도 더 이상 나타나지 않는다.

- [변경 전 C](exports/baseline/001cebb0.c)
- [비복귀 속성 적용 C](exports/noreturn/001cebb0.c)

하지만 `0x001cebf3` 이후의 zero padding을 ADD로 본 기존 listing은 그대로다.
함수의 마지막 body range도 `0x001cebe0`–`0x001cebfe`로 변하지 않았다.
따라서 남은 작업은 해당 padding의 코드/데이터 분류와 함수 본문 범위를 근거에 맞게 고치는 것이다.
이번 실험 결과만으로 R02 전체를 해결 처리하지 않는다.

## F01 — 예외 복귀 뒤의 잘못된 일반 실행 흐름 개선

`_machdep_call`의 새 C에서는 유효한 호출 번호일 때만 테이블 접근 경로에 들어가고,
잘못된 번호에 대한 예외 복귀는 별도의 비복귀 종료 경로로 나타난다.
copyin 오류 뒤 `_thread_exception_return`도 일반 함수처럼 반환해 다음 처리로 진행하는 것으로 보지 않는다.

근거: [개선된 C](exports/noreturn/001925a0.c), [baseline C](exports/baseline/001925a0.c).
여전히 복잡한 stack 임시 변수와 불완전한 인자 타입은 남아 있다.
제어 흐름 개선을 곧바로 GCC 2.7용 완성 소스로 해석하지 않는다.

## Python 감사 결과

[기계 판정 자료](audit.json)는 다음을 검사한다.

- 모든 대상 함수가 실제 decompile 완료 상태인지 확인.
- baseline/noreturn/restored의 함수 집합 일치.
- C 및 추출 metadata의 정확한 복원 일치.
- 모든 단계의 함수 본문과 listing 불변성.
- 대상 listing bytes와 원본 파일의 일치.
- p-code 주소의 본문 밖 사용 및 전체 listing instruction 경계 불일치.
- 대조 함수의 C 불변성.

따라서 단순히 headless 프로세스가 exit 0을 반환한 것만으로 성공 판정하지 않았다.
로그와 환경 정보는 `console.log`, `ghidra.log`, `script.log`, `exports/environment.json`에 있다.

## 재현과 다음 단계

저장된 결과의 Python 재검증:

```sh
python3 -B 09_validation/reports/continuous-review-20260911-04/audit_experiment.py
```

`run_experiment.py`와 `command.json`에는 실제 실행 절차가 있다.
runner는 기존 실험 snapshot을 덮어쓰지 않도록 같은 경로의 재사용을 거부한다.
실험을 새로 실행하려면 별도의 새 snapshot/output 경로를 지정하여 보존된 자료와 분리해야 한다.

다음 우선순위는 R02 padding/함수 범위의 별도 교정 실험과,
비복귀 계약을 다른 호출자까지 전파할 때의 정확성·부작용 검토다.
기존 IDA 입력 검증, 세그먼트 표현, fault 프레임, recover 수명, callback/타입 문제도 계속 미해결로 남긴다.

전체 목표는 미완료다. 이번에는 확정 문제의 원인과 교정 조건에 대한 가역적 도구 실험 증거를 추가했다.
