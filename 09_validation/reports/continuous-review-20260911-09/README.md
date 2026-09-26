# 연속 추가검토 — 전원관리 순회의 초기 EBX 의존

대상: OPENSTEP 4.2 mk-183.34.4 / x86. 검토일: 2026-09-11.
SHA-256: `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`.
출발점: [초기 EBX read 후보](../continuous-review-20260911-07/README.md).

## 결론

`__io_setDriverPowerState`와 `__ioSetDriverPowerManagementState`가 EBX를 초기화하지 않고
첫 장치 번호로 사용하는 것은 원본 명령의 실제 동작이다. 단순한 decompiler 누락으로만
설명할 수 없으며, 이전에 확인한 숨은 구조체 반환 인자와도 다른 사례다.

더 나아가 실제 호출 경로에서 값의 출처를 확인했다.
`_power_init` 경로는 EBX를 0으로 만들지만, `_power_callout`은 두 번째 인자인
콜백 핸들을 EBX에 넣고 같은 전원관리 경로를 호출한다.
`_PMSetPowerState`는 전원 메시지를 보내기 전에 EBX를 장치 순회용으로 재설정하지 않는다.

합성 장치 레지스트리와 명시적인 경계 모의를 사용한 392개 실행 조건에서
이 차이에 따른 조회/메시지 전송 결과가 일관되게 재현됐다.
현재 대상 이미지의 초기 레지스터 의존은 확인됐지만, 실제 하드웨어 장애,
정식 배포본의 버그, 컴파일러 버그 또는 과거 바이너리 패치 여부까지 확정한 것은 아니다.

## 원본 명령과 직접 호출 관계

[기계 근거](evidence.json), [추출 코드](evidence.py).

| 함수 | 원본에서 확인한 동작 |
|---|---|
| `__io_setDriverPowerState`, `0017e5ec` | EBX를 저장한 후 초기화 없이 PUSH하고 증가 |
| `__ioSetDriverPowerManagementState`, `0017e67c` | 동일한 초기 EBX 의존, 다른 전원 메시지 selector |
| `_md_shutdown_devices`, `0018cfb8` | 상태 3을 스택으로 전달하며 EBX를 설정하지 않음 |
| `_PMSetPowerState`, `001874ec` | device=1 경로에서 기존 EBX를 유지한 채 wrapper 호출 |
| `_kern_PMSetPowerState`, `00160cf8` | host 조건 통과 시 device/state를 전달하며 EBX를 설정하지 않음 |
| `_power_callout`, `00160adc` | `[EBP+0xc]`의 콜백 핸들을 EBX에 넣음 |
| `_power_init`, `00160bd4` | 성공 초기화 경로에서 `XOR EBX,EBX` 수행 |

기존 전체 instruction export를 원본 바이트로 다시 디코딩해 두 wrapper로 향하는
직접 CALL을 추출했고, 저장 reference와 일치했다.
첫 wrapper의 직접 CALL은 `_PMSetPowerState`와 `_md_shutdown_devices`에서 검출됐다.
management wrapper의 직접 CALL은 검출되지 않았다. 이를 런타임 간접 호출까지 없다는 증명으로 보지 않는다.

`_boot`의 경로도 별도로 확인했다. 일부 경로에서는 EBX가 버퍼 대기 개수로 사용되거나
버퍼 순회 자체가 생략된 채 `_md_shutdown_devices`로 이어진다.
따라서 종료 경로가 항상 EBX=0을 제공한다고 정적 명령만으로 가정할 수 없다.
이번에는 `_boot` 전체의 버퍼 동기화/종료를 실제 실행하지 않았다.

## 조회 helper의 원본 계약

ObjC 메타데이터의 `+[IODevice(GlobalParameter) lookupByObjectNumber:instance:]`는
IMP `001a4bdc`, 타입 문자열 `i16@8:12I16^@20`이다.
원본 메타데이터 바이트와 selector/type 문자열을 다시 대조했다.
이 메서드는 lock 메시지, 내부 helper `001a3d58`, unlock 메시지를 순서대로 호출한다.

내부 helper의 동작은 다음과 같다.

- 장치 번호를 global counter와 unsigned 비교한다.
- 번호가 counter 이상이면 `IO_R_NO_DEVICE`를 반환한다.
- 범위 안이면 연결 목록에서 같은 object number를 찾는다.
- 찾으면 출력 포인터에 instance를 쓰고 성공을 반환한다.
- 목록 끝까지 없으면 `IO_R_OFFLINE`을 반환한다.

이 역할은 로컬 Darwin `IODevice.m`의 `objectNumToId`와 대응한다.
범위 밖과 목록의 hole은 다른 결과다. Power wrapper는 범위 밖에서 종료하고,
offline이면 다음 번호로 진행한다.

초기 EBX가 큰 포인터 값이면 그 첫 값이 범위 밖이 되어 즉시 종료할 수 있다.
`INC EBX`의 wrap 이후 다시 0부터 조회한다고 해석해서는 안 된다.
번호는 증가 전에 인자로 PUSH되며, 첫 조회의 종료 결과를 받으면 반복을 끝낸다.

## 실행 시험의 범위

[실행 결과](power-execution.json), [Python 시험 코드](power_execution.py).

원본을 실행한 경로:

- power wrapper 직접 진입.
- management wrapper 직접 진입.
- `_md_shutdown_devices` → power wrapper.
- `_PMSetPowerState` → power wrapper.
- `_kern_PMSetPowerState` → `_PMSetPowerState` → power wrapper.
- `_power_callout` → 실제 event 분기 → `_PMSetPowerState` → power wrapper.
- `_power_init` → 실제 초기화/event 분기 → `_PMSetPowerState` → power wrapper.

각 경로는 원본 lookup 메서드와 내부 registry helper까지 실행한다.
Registry는 빈 목록, 모든 장치 존재, 중간 hole 및 일부 protocol 미지원,
모든 장치 protocol 미지원 조건으로 구성했다.
초기 EBX/콜백 핸들 및 요청 상태도 바꿨다.

명시적으로 모의한 경계:

- ObjC dispatcher에서 해당 lookup IMP로의 routing.
- lock/unlock 및 class/conforms/perform 메시지 결과.
- APM connect와 event 반환.

실제 ObjC cache lookup, mutex 동시성, 드라이버 메서드, APM BIOS 및 timer scheduler는
이번 시험에서 실행하지 않았다. APM 연결 flag는 이후 BIOS 실행을 피하도록 합성 메모리에서 설정했다.
Init/callout은 첫 `_PMSetPowerState` 복귀 직후에 멈추므로 재예약 단계의 실행 증거가 아니다.
커널 명령 바이트는 패치하지 않았고 예상 밖 원본 주소 실행은 assertion으로 거부한다.

## 재현된 조회 차이

아래는 번호 0–3의 장치가 모두 존재하고 protocol에 부합하는 같은 레지스트리다.
`4` 조회의 범위 밖 결과가 정상 반복 종료를 만든다.

| 경로 | 입력 EBX/콜백 핸들 | 실제 조회 번호 | perform 대상 |
|---|---|---|---|
| init | `0x600100` | 0, 1, 2, 3, 4 | 0, 1, 2, 3 |
| callout | 0 | 0, 1, 2, 3, 4 | 0, 1, 2, 3 |
| callout | 1 | 1, 2, 3, 4 | 1, 2, 3 |
| callout | `0x600100` | `0x600100`만 | 없음 |
| shutdown | 1 | 1, 2, 3, 4 | 1, 2, 3 |
| shutdown | `0x600100` | `0x600100`만 | 없음 |

표는 임의의 모델 출력만이 아니라 실제 wrapper/lookup helper 실행 기록에서 추출했다.
초기값 이후의 모든 조회 번호, helper 결과, perform 대상/selector/state를 기대값과 비교했다.
직접 복귀 경로의 ESP와 callee-saved 레지스터도 확인했다.
총 392건이 통과했다. 메시지 전송이 없었던 조건에는 정상적인 빈 목록/미지원 protocol도
포함되므로 그 개수를 모두 장애 사례 수로 세지 않는다.

## 참고 소스와의 차이 및 원인 판단의 한계

Darwin `autoconfCommon.m`의 `_io_sendPowerMessage`는 `IOObjectNumber i = 0`으로 시작한다.
Wrappers의 소스 선언에는 상태 인자만 있고, 시작 번호를 별도의 EBX 인자로 받는 선언은 없다.
`power.c`의 콜백 인자는 장치 번호가 아니라 재예약에 사용할 callout 객체 역할이다.
원본 `_power_callout`에서도 이 값이 뒤의 delayed dispatch 호출에 사용되는 명령을 확인했다.

하지만 Darwin 참조 소스가 mk-183.34.4를 만든 정확한 translation unit이라고 가정하지 않는다.
현재 대상의 NOP 쌍 `0017e5fe` 및 `0017e68e`는 원본 바이트 그대로 `9090`이다.
이 위치에 과거 초기화 명령이 있었을 것이라고 역으로 추정해 패치하지 않았다.

Import manifest에 기재된 로컬 커널 복사본들을 다시 해시 비교했으며 대상과 일치했다.
동일한 복사본들이 있다는 사실은 정식 배포본의 순정성이나 과거 패치 이력을 증명하지 않는다.
따라서 정확한 판정은 **현재 대상 이미지의 전원 메시지 순회가 초기 EBX에 의존하며,
실제 caller의 값 전달 때문에 합성 registry에서 조회 누락이 재현된다**는 것이다.

## 디컴파일/복원 작업에 대한 의미

Ghidra의 `unaff_EBX`를 무조건 0으로 치환하면 현재 대상 명령의 동작이 바뀐다.
반대로 IDA의 `__usercall` EBX 매개변수 표기를 공인 API의 의도된 인자로 받아들여도 안 된다.
그 표기는 실제 레지스터 의존을 표현하지만, 호출자가 장치 번호를 의도적으로 전달한다는 증명은 아니다.

현재 바이트에 충실한 복원과 참고 소스의 0부터 순회하는 의미는 별도 요구로 관리해야 한다.
원본 문제를 고칠지 결정하지 않은 분석 단계에서 어느 쪽도 몰래 대체하지 않는다.
이번에는 구현 소스나 원본 바이너리, canonical Ghidra/IDA DB를 수정하지 않았다.

Ghidra·IDA 분석 스킬에 따라 원본·도구 해석·참고 소스·실행 모의를 분리했다.
모든 계산, 주소 변환, 호출 집계, 기대값 및 해시 비교는 Python으로 수행했다.

## 재현과 남은 확인

```sh
python3 -B 09_validation/reports/continuous-review-20260911-09/power_execution.py
python3 -B 09_validation/reports/continuous-review-20260911-09/evidence.py
python3 -B 09_validation/reports/continuous-review-20260911-09/verify_artifacts.py
```

실제 커널의 registry/콜백 핸들 값, 정식 배포본 비교, 초기화 누락의 발생 경위는 미확정이다.
다른 잘못된 prototype, 예외/문맥 전환, IDA 불일치 및 GCC 2.7 툴체인 검증도 남아 있다.
이 국소 실행 결과를 전체 분석 완료나 실제 하드웨어 검증으로 확대하지 않는다.

입력 해시: [input-hashes.json](input-hashes.json).
기존 자료 보존 검증: [verification.json](verification.json).
새 증거 manifest: [artifact-hashes.json](artifact-hashes.json).
