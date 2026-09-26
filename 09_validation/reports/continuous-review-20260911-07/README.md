# 연속 추가검토 — 숨은 EBX 반환 계약의 범위와 오탐 분리

대상: OPENSTEP 4.2 mk-183.34.4 / x86. 검토일: 2026-09-11.
원본 SHA-256: `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`.
선행 근거: [ObjC 반환 ABI 검토](../continuous-review-20260911-06/README.md).

## 결론

숨은 EBX 출력 포인터 누락은 Objective-C에만 국한되지 않는다.
`FUN_00124cb8`은 참고 소스의 `in_bootp_makeifreq`에 대응하며,
실제 `_in_bootp` 호출자가 EBX에 로컬 결과 구조체 주소를 넣는다.
원본 호출부와 callee, 문자열/메모리 복사 함수들을 연결한 시험 128건에서
이 계약과 결과 바이트를 확인했다. Ghidra의 callee 및 caller C에는 이 인자가 누락돼 있다.

반면 `unaff_EBX`가 있는 C 파일 320개를 모두 같은 ABI 결함으로 세면 안 된다.
분석 fragment 이름을 가진 출력이 포함되고, 원래 register 문맥을 사용하는 assembly와
잘못 적용된 함수 원형 때문에 생긴 표현도 섞여 있다.
이번 검토는 후보 목록을 보존하고, 독립 명령 근거로 확인한 사례와 미해결 사례를 분리했다.

## 전수 후보 추출과 제한된 명령 검사

[후보 자료](abi-candidates.json), [추출 코드](abi_candidates.py).
기존 export의 함수/분석 단위 5,253개를 대상으로 C 검색과 원본 명령 기반 entry-prefix 검사를 수행했다.

| 검사 항목 | 결과 |
|---|---:|
| C에 `unaff_EBX`가 나타나는 단위 | 320 |
| 그중 `__analysis_fragment_` 이름 | 274 |
| 그 외 이름 | 46 |
| entry prefix에서 의미 있는 초기 EBX read 검출 | 11 |

Entry-prefix 검사는 함수 진입부터 최초 제어 이전, EBX 계열 레지스터 write 또는
listing gap까지 따라간다. 최초 `PUSH EBX`는 보존용이라는 가정으로 제외하고,
이후 `PUSH EBX`는 read로 취급한다. `XOR EBX,EBX`와 `SUB EBX,EBX`는 기존 값을
입력으로 소비하는 연산으로 취급하지 않는다.

이 검사는 branch/call을 건너 값을 전파하는 완전한 dataflow가 아니다.
최초 PUSH가 실제 인자 전달인 비표준 진입은 놓칠 수 있고, partial write 이후의 값도 추적하지 않는다.
또한 fragment라는 이름만으로 그 코드가 독립 함수가 아니라는 의미 판정을 확정하지 않는다.
따라서 11개는 **이 기준에 걸린 후보 수**이지 커널 전체의 숨은 ABI 인자 개수가 아니다.

Python으로 기록한 종료 상태는 제어 이전 2,877개, 레지스터 write 1,965개,
listing gap 400개, 초기 EBX read 11개다. Gap을 새로운 미식별 코드나 누락 함수 수로 해석하지 않는다.

## 초기 EBX read 후보의 구분

[분류 근거](evidence.json).

| 분류 | 개수 | 근거/남은 점 |
|---|---:|---|
| 확인된 숨은 aggregate 출력 | 2 | `FUN_00124cb8`, `nodeAddress` |
| 진입 EBX를 카운터로 쓰는 계약 미해결 | 2 | 전원관리 함수에서 초기값을 PUSH하고 증가 |
| Assembly 레지스터 프레임 저장 | 6 | trap/syscall/bios 경로의 `PUSHAL` |
| 레지스터로 받은 호출 대상 | 1 | `__stack_attach`의 `CALL EBX` |

`__io_setDriverPowerState`와 `__ioSetDriverPowerManagementState`는 EBX를 초기화하지 않고
첫 메시지의 인자로 PUSH한 뒤 증가시키는 원본 명령이 있다.
이를 구조체 반환으로 분류하지 않았다. 실제 호출자의 초기값, 참조 구현의 변수 초기화,
진입 ABI를 추가 조사해야 한다. 아직 원본 버그 또는 정상 비표준 계약 중 어느 쪽으로도 확정하지 않는다.

`__stack_attach`의 EBX는 출력 버퍼가 아니라 함수 포인터다.
`PUSHAL`을 가진 진입점도 레지스터 문맥 저장이므로 구조체 반환 근거가 아니다.
이 분류는 각 함수의 나머지 분석까지 완료했다는 뜻이 아니다.

## 새 확인 — `in_bootp_makeifreq`의 숨은 반환 버퍼

원본 주소 `0x00124cb8`에는 현재 `FUN_00124cb8`라는 이름이 붙어 있다.
NeXTMach mk-108.1과 Darwin 참고 소스 모두 `in_bootp_makeifreq`라는 `struct ifreq` 반환 함수가 있고,
이름 복사, unit 문자 추가, sockaddr 복사, 구조체 반환이 원본 명령과 대응한다.
참고 소스의 역할을 근거로 식별한 것이며 canonical 심볼을 새로 쓰지는 않았다.

실제 호출부:

- `_in_bootp` 진입: `0x00124154`.
- `0x00124175`에서 ESI에 `[EBP-0x20]` 주소를 구성한다.
- `0x00124178`에서 그 주소를 EBX에 넣는다.
- `0x0012417a`에서 `0x00124cb8`을 CALL한다.
- 명시적 스택 인자는 ifnet과 sockaddr 포인터이며 출력 포인터는 EBX에 별도로 있다.

Callee는 진입 EBX를 로컬에 저장한 뒤, 로컬 구조체를 만들고 원래 EBX의 출력 주소로
`REP MOVSD`를 수행한다. 반환 시 EAX에 그 주소를 놓고, EBX와 다른 보존 레지스터를 복원한다.
원본 명령의 복사 범위는 32바이트다.

기존 Ghidra callee C는 `unaff_EBX`를 사용하지만 이를 매개변수로 선언하지 않는다.
호출자 C도 `FUN_00124cb8(param_1,param_2)`라고만 표시하여 로컬 구조체 초기화와의 연결이 사라진다.
반면 저장된 IDA callee C는 `__usercall`의 EBX 인자와 EAX 반환 주소를 표시한다.
이는 이번 원본 근거와 부합하지만, 곧바로 GCC 2.7에서 컴파일할 수 있는 소스 선언은 아니다.
모든 IDA 출력이 같은 품질이라는 일반화도 하지 않는다.

## 실제 호출부와 callee 연결 시험

[실행 자료](ifreq-execution.json), [시험 코드](ifreq_execution.py).
Python/Unicorn으로 원본 `_in_bootp` 진입부터 호출 직후 `0x0012417f`까지 실행했다.
이 경로 안의 `_strcpy`, `_bcopy`, `_memcpy`도 원본을 실행했다. 함수 반환 모의나 코드 패치는 없었다.
네트워크 부팅의 이후 단계는 실행하지 않았다.

시험 조건은 이름 길이, unit 값, 초기 스택 표식, sockaddr 포인터 정렬을 바꿨다.
빈 이름과 경계 unit 값은 관찰용 조건이지 올바른 인터페이스 설정이라는 뜻은 아니다.
이름은 결과 이름 필드 안에 들어가는 범위만 시험했다. DF=0, 평탄한 세그먼트를 가정했다.

검사 내용:

- Callee 진입에서 실제 EBX와 스택 인자, CALL 복귀 주소 확인.
- 결과 구조체 32바이트 전체와 기대 바이트열 일치.
- 출력 영역의 word write 8회 확인.
- 반환 EAX, callee가 보존하는 EBX/ESI/EDI 및 caller의 EBP·ESP 확인.
- 원본 복사 helper 진입 확인, 합성 IMP 미실행 확인.

128건이 모두 통과했다. 모의 helper는 없었다.
잘못된 포인터, 길이 초과 이름, overlapping 입력, 페이지 fault, 실제 장치 상태는 범위 밖이다.

### 초기화되지 않은 이름 필드의 나머지 바이트

이 함수는 이름 뒤에 unit 문자와 NUL을 넣지만 이름 필드 전체를 zero-fill하지 않는다.
시험 중 96건에서 NUL 뒤의 미기록 바이트가 초기 스택 표식 그대로 복사되는 것을 확인했다.
이는 원본 명령과 참고 소스의 부분 초기화에 부합한다.

따라서 바이트 동일성을 요구하는 재구성에 임의의 전체 `memset`을 넣으면 원본 동작과 달라질 수 있다.
동시에 C의 초기화되지 않은 저장 공간을 읽는 동작을 이 시험으로 언어적으로 정당화한 것은 아니다.
이 차이가 실제 외부 노출이나 보안 문제로 이어지는지도 이번에는 추적하지 않았다.

Unit 문자도 정수 전체의 십진 변환이 아니라 원본의 하위 바이트 덧셈 결과다.
시험의 Python 기대식은 `(unit + ord('0')) & 0xff`이며, 여러 자리 수를 문자열로 만든 것이 아니다.

## 다른 원인 사례 — `_compress`의 부적합한 함수 원형

`_acct`의 C에 나오는 `unaff_EBX` 일부는 별도로 조사할 필요가 있다.
현재 `_compress` (`0x00103428`)에는 다음과 같은 원형이 저장돼 있다.

```c
int _compress(Bytef *dest, uLongf *destLen, Bytef *source, uLong sourceLen);
```

그러나 원본은 `[EBP+8]`, `[EBP+0xc]`를 숫자로 사용하여 회계용 지수/가수 인코딩을 만들고,
EBX는 먼저 0으로 초기화한다. NeXTMach 참조 소스의 선언도 `compress(long t, long ut)`에 해당한다.
저장된 포인터형 인자 네 개는 이 동작과 맞지 않는다.

Ghidra `_acct` C가 이 호출에 추가 EBX/ESI 값을 붙이는 것을 숨은 구조체 인자로 보아서는 안 된다.
이는 잘못된 callee 원형이 caller 해석을 흐리는 구체적인 교정 대상이다.
타입이 어떤 import/분석 단계에서 들어왔는지는 아직 추적하지 않았고,
이번에는 prototype 수정 후의 decompiler 재실험까지 진행하지 않았다.

## 보존·재현·다음 작업

Ghidra·IDA 스킬에 따라 원본/참고 소스/분석 해석/실행 증거를 분리했다.
모든 주소 변환·수량·차이·해시 계산은 Python으로 수행했다.
원본 커널, 기존 프로젝트 및 기존 증거 파일 해시는 보존 검증을 통과했다.
`07_kernel` 구현이나 canonical 분석 DB를 변경하지 않았다.

```sh
python3 -B 09_validation/reports/continuous-review-20260911-07/abi_candidates.py
python3 -B 09_validation/reports/continuous-review-20260911-07/ifreq_execution.py
python3 -B 09_validation/reports/continuous-review-20260911-07/evidence.py
python3 -B 09_validation/reports/continuous-review-20260911-07/verify_artifacts.py
```

다음 우선순위는 확인된 EBX 출력 계약의 custom storage 교정 실험과
부적합한 callee prototype의 caller 영향 검증이다.
전원관리 EBX 초기값, 나머지 `unaff_EBX` 후보, 다른 레지스터의 숨은 입력,
예외/문맥 전환, GCC 2.7 ABI 및 전체 분석 미해결 목록도 남아 있다.
이번 후보 추출이나 시험 통과를 전체 분석 완료로 판정하지 않는다.

입력 근거: [input-hashes.json](input-hashes.json).
보존 검증: [verification.json](verification.json).
새 산출물 manifest: [artifact-hashes.json](artifact-hashes.json).
