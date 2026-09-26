# 연속 추가검토 — 숨은 반환 인자와 잘못된 prototype의 분리 교정 실험

대상: OPENSTEP 4.2 mk-183.34.4 / x86. 검토일: 2026-09-11.
SHA-256: `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`.
선행 근거: [ObjC 실제 반환 시험](../continuous-review-20260911-06/README.md),
[EBX 후보 및 실제 caller 검증](../continuous-review-20260911-07/README.md).

## 결과

확인된 숨은 EBX 인자를 Ghidra에 명시하면 callee의 `unaff_EBX`가 사라지고,
실제 caller의 결과 구조체 주소도 C에 연결된다.
이와 별개로 `_compress`의 부적합한 원형을 고치면 `_acct`의 불필요한 EBX·ESI 인자가 사라진다.
서로 다른 원인이라는 것을 **각각의 독립 프로세스 실험**으로 확인했다.

| 단계 | 직접 메타데이터 변경 함수 | C가 바뀐 함수 |
|---|---:|---:|
| baseline | 0 | 0 |
| hidden_only | 2 | 3 |
| compress_only | 1 | 2 |
| combined | 3 | 5 |
| reopened_baseline | 0 | 0 |

선택한 함수는 7개이며, 기준 C는 기존 full-pass5와 export 머리말을 제외하고 모두 일치했다.
최종 fresh-open의 C와 선택 함수 메타데이터도 baseline과 정확히 같았다.
이 결과는 canonical 분석 프로젝트의 수정 완료나 GCC 2.7용 완성 소스를 뜻하지 않는다.

## 실험을 독립 비교로 인정하기 위한 보완

첫 시도에서는 같은 headless 실행 안에서 transaction 취소로 상태를 되돌리려 했다.
하지만 추출 메타데이터를 비교하니 다음 단계와 `restored` 단계에 변경된 원형이 남았다.
따라서 그 시도를 가역적/독립적인 비교 결과로 채택하지 않았다.
원래 프로젝트와 저장된 복사본의 해시는 이때도 유지됐다.
즉 메모리 내 복원 실패와 디스크 원본 보존은 서로 다른 검사다.

그 다음 시도에서는 새 프로세스를 사용했지만 일부 로그와 산출물에 이전 스크립트의
전체 단계 실행이 나타났다. 스크립트 검색 경로에는 동명의 이전 Java 원본과 실행 캐시가
존재했다. 내부 선택 원인을 완전히 특정한 것은 아니므로 단순히 캐시 버그라고 단정하지 않는다.
해당 실행도 성공 비교에서 제외했다.

두 시도의 자료는 삭제하지 않고 다음에 분리 보존했다.

- `rejected-transaction-attempt/`: 취소 후 메모리 상태가 복원되지 않은 실험.
- `rejected-script-selection-attempt/`: 요청한 단계와 실제 실행이 일치하지 않은 실험.

최종 채택 실험에서는 다음을 모두 확인했다.

1. 유일한 새 클래스명 `IsolatedStorageExperiment` 사용.
2. 이전 Java 원본은 `.java.txt`로 보존하여 실행 스크립트 검색 대상에서 제외.
3. 단계마다 새 JVM, 별도 runtime/settings/cache 경로 사용.
4. 각 단계가 클래스명·버전·요청 단계의 실행 표식을 출력하고 Python이 일치 여부 확인.
5. 변경 전 전체 함수 메타데이터 5,253개가 매 단계 baseline과 같은지 확인.
6. 실행 후 원본 프로젝트와 복사본의 파일 해시 검사.
7. 마지막 프로세스는 변경 없이 재개방하여 baseline C와 메타데이터 비교.

기존 프로젝트의 파일 9개와 복사본의 파일 9개는 모든 채택 단계에서 변하지 않았다.
복사본: `04_ghidra/projects/experiments/storage-isolated-v2-review-20260911/`.
이전 실패 시도의 복사본도 별도로 유지했다. Canonical DB에 적용하거나 저장하지 않았다.

## EBX 계약의 표현

두 함수에 `CUSTOM_STORAGE`를 적용하고 물리적 저장 위치를 다음과 같이 명시했다.

| 값 | 저장 위치 | 의미 |
|---|---|---|
| result_buffer | EBX | caller가 제공한 결과 버퍼 |
| 명시적 첫 인자 | 진입 ESP+4 | ifnet 또는 receiver |
| 명시적 다음 인자 | 진입 ESP+8 | sockaddr 또는 selector |
| 반환 주소값 | EAX | result_buffer 주소 |

여기서 stack offset은 EBP 기준이 아니라 함수 진입 ESP 기준이다.
Python이 포인터 폭과 stack offset을 구성했고, 추출된 Ghidra storage가 이를 정확히 유지하는지 검사했다.
함수 이름, 함수 본문, calling-convention 이름을 임의로 변경하지 않았다.
변경 API의 강제 충돌 제거 옵션도 사용하지 않았고, 전체 함수의 기존 로컬 변수 기록은 동일했다.

출력 타입은 기존 실행에서 확인한 바이트 배치만 반영했다.
`ifreq_result_bytes`는 이름 영역과 sockaddr 바이트 영역,
`token_address_bytes`는 주소 바이트 배열이다. 완성된 SDK 구조체 정의를 복원했다는 뜻은 아니다.
ifnet/receiver/selector의 상세 타입도 이번에는 opaque pointer로 남겼다.

### `in_bootp_makeifreq` 대응 함수와 caller

원래 `FUN_00124cb8` C는 선언되지 않은 입력 `unaff_EBX`를 사용했다.
교정 후에는 `result_buffer`를 명시적으로 받아 결과를 기록하고 그 주소를 반환한다.

더 중요한 변화는 `_in_bootp`다. 기존 C에서 끊어져 있던 로컬 구조체 초기화가
`FUN_00124cb8(&local_24,param_1,param_2)` 형태로 나타난다.
뒤의 네트워크 초기화 호출과 sockaddr 복사에서도 같은 로컬 결과 객체를 사용한다.

`0x0012417a` CALL의 high p-code 인자 수를 직접 비교했다.
기준/압축 원형만 교정/재개방 단계에서는 2개,
EBX 교정/결합 단계에서는 3개다. CALL target 자체는 인자 수에서 제외했다.
단순히 C 문자열 모양만 바뀐 것으로 판정하지 않았다.

- [기존 caller C](exports/baseline/00124154.c)
- [EBX 교정 caller C](exports/hidden_only/00124154.c)
- [EBX 교정 callee C](exports/hidden_only/00124cb8.c)

### `nodeAddress`

`FUN_001ab830`도 결과 버퍼를 EBX 인자로 받고 EAX에 그 주소를 반환하는 C가 됐다.
receiver와 출력 버퍼를 분리하며, 쓰기 위치도 버퍼의 주소 바이트 배열로 표현된다.
원본 명령/실행으로 확인했던 계약을 decompiler가 더 잘 표현하도록 만든 것이다.

- [기존 C](exports/baseline/001ab830.c)
- [EBX 교정 C](exports/hidden_only/001ab830.c)

두 함수에는 여전히 `Unknown calling convention` 경고가 있다.
이를 숨기기 위해 일반 cdecl로 표시하지 않았다. 물리적 storage를 아는 것과
해당 NeXT/GCC 2.7 ABI를 compiler-spec 및 컴파일 가능한 선언으로 구현하는 것은 별개다.
복사 루프와 캐스트도 여전히 저수준이므로 교정된 C를 그대로 복원 소스로 채택하지 않는다.

## `_compress` 교정의 독립적인 효과

Baseline에는 `/zconf.h/Bytef *` 등의 포인터 타입을 갖는 인자 네 개가 저장돼 있다.
이는 실제 회계용 숫자 변환 함수와 맞지 않는다.
타입 경로와 signature source는 이번 메타데이터에 기록했지만, 최초 설정 주체나 import 시점은 미확정이다.

이번에는 해당 함수만 signed 32-bit 인자 두 개와 EAX 반환으로 교정했다.
기존 호출 규약에서 동적 storage를 사용했으며 EBX custom storage는 적용하지 않았다.
표현은 `int seconds, int microseconds`다. 참고 소스의 `long`과 목표 환경의 폭/ABI 관계를
GCC 2.7로 실컴파일 검증한 것은 아니므로 최종 소스 선언 선택으로 간주하지 않는다.

`_acct`의 CALL 지점 `00103290`, `001032a7`, `001032d7`, `0010338a`에서
high p-code 인자 수가 모두 4개에서 2개로 바뀌었다.
`unaff_EBX`, `unaff_ESI`, `Bytef`, `uLong` 표현도 이 caller C에서 사라졌다.
EBX 출력 인자만 교정한 단계에서는 이 변화가 없었다.

- [기존 회계 함수 C](exports/baseline/00103188.c)
- [원형 교정 후 회계 함수 C](exports/compress_only/00103188.c)
- [교정한 `_compress` C](exports/compress_only/00103428.c)

아직 `_acct`의 모든 간접 호출, syscall 인자, 로컬 상태 의미가 검증된 것은 아니다.
이 결과로 다른 잘못된 원형까지 자동 교정된 것으로 보지 않는다.

## `_compress` 원본 실행의 독립 검증

[실행 자료](compress-execution.json), [Python 모델/실행 코드](compress_execution.py).
원본 함수 전체를 실행한 351개 사례가 signed-32-bit 명령 모델과 일치했다.
초·마이크로초 경계값, 초기 EBX·ESI 및 추가 스택 값을 바꿨다.
관찰한 인자 영역의 read는 진입 stack의 두 인자에만 있었고, 보존 레지스터와 ESP도 확인했다.
이 시험은 함수 모의를 사용하지 않는다.

음수와 overflow 조건도 포함했지만 이는 원본 기계 명령의 결과를 검사하기 위한 것이다.
유효한 회계 입력 범위라고 주장하거나 C의 signed overflow를 정당화하는 시험이 아니다.
Python 모델은 산술 shift, 정수 나눗셈의 0 방향 절삭, 레지스터 폭을 명시적으로 처리한다.

## 전역 영향 및 보존 감사

[감사 결과](audit.json), [감사 코드](audit_experiment.py).

- 각 프로세스의 입력 함수 메타데이터 전체 일치.
- 메타데이터 변경은 요청한 함수들에만 한정.
- 전체 함수 본문과 기존 로컬 변수 기록 불변.
- 전체 code-unit 범위/분류/flow/fallthrough 및 reference TSV 불변.
- 초기화된 메모리 블록 26개 불변, 원본 파일 전체 1,117,920바이트와 일치.
- 선택 함수 모두 decompile 완료 상태 및 CALL 인자 수 검사.
- 대조 함수 `_strcpy`, `_objc_msgSend`의 C 불변.
- 재개방 baseline의 C와 선택 함수 메타데이터 정확한 일치.

JSON의 키 순서는 JVM마다 달라질 수 있어 메모리는 JSON 텍스트가 아니라 파싱한 block 정보와
바이트 payload를 비교했다. 모든 데이터 타입 DB 및 GUI 상태를 전수 비교한 것은 아니다.
임시 타입은 해당 프로세스의 분석 표현이며 저장된 원본 DB에는 추가하지 않았다.

Ghidra·IDA 스킬에 따라 실험/원본/해석을 분리했다. Java는 Ghidra API와 추출만 담당했고,
주소·레이아웃·수량·차이·해시·실행 기대값 계산은 모두 Python으로 수행했다.
이번에는 라이브 IDA를 변경하거나 그 DB 입력을 새로 검증하지 않았다.

## 재현과 남은 작업

`run_experiment.py`는 같은 snapshot 경로가 있으면 덮어쓰기를 거부한다.
Ghidra 단계를 새로 실행하려면 별도의 snapshot/output/runtime 경로를 지정해야 한다.
기존 산출물 검증은 다음 명령으로 수행한다.

```sh
python3 -B 09_validation/reports/continuous-review-20260911-08/audit_experiment.py
python3 -B 09_validation/reports/continuous-review-20260911-08/compress_execution.py
python3 -B 09_validation/reports/continuous-review-20260911-08/verify_artifacts.py
```

다음은 다른 부적합한 prototype의 영향과 전원관리 함수의 초기 EBX 계약을 검토해야 한다.
이번 결과는 canonical 교정안을 위한 검증된 조건이며 실제 분석 DB 교정/재export 완료가 아니다.
나머지 ABI, 예외/문맥 전환, IDA 불일치 및 GCC 2.7 툴체인 검증도 남아 있다.
`07_kernel` 구현은 변경하지 않았고 전체 분석 완료로 판정하지 않는다.

보존 검사: [verification.json](verification.json).
증거 manifest: [artifact-hashes.json](artifact-hashes.json).
