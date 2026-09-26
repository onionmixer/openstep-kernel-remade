# 연속 추가검토 — ObjC dispatch·가변 인자·숨은 구조체 반환 인자

대상: OPENSTEP 4.2 mk-183.34.4 / x86. 검토일: 2026-09-11.
원본 SHA-256: `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`.
선행 검토: [padding 교정 후 반환 정보 누락](../continuous-review-20260911-05/README.md).

## 결론

디스패처의 간접 JMP는 인자를 새로 구성하는 일반 C 호출이 아니라,
원래 호출 스택을 메서드로 전달하는 tail transfer다.
실제 원본 dispatch와 메서드를 연결한 실행으로 반환 계약의 차이도 확인했다.

| 원본 메서드 | 바이너리 타입 문자열 | 확인한 반환 방식 |
|---|---|---|
| `-[KernBusRangeMapping mappedRange]` | `{?=II}8@8:12` | EAX·EDX에 결과 필드 |
| `-[SCSIGeneric SCSI3_lun]` | `Q8@8:12` | EAX·EDX에 결과 필드 |
| `-[IOTokenRing nodeAddress]` | `{?=[6C]}8@8:12` | EBX로 받은 출력 버퍼에 기록, EAX에 버퍼 주소 |

따라서 디스패처나 forwarding의 반환형을 일괄 `void`, `id`, `undefined8`로 정하면 안 된다.
특히 `nodeAddress`의 숨은 EBX 입력은 기존 Ghidra C에서 미해석 레지스터로 남아 있다.
저장된 IDA C도 원본의 receiver와 숨은 반환 버퍼를 올바르게 구분한 표현으로 보기 어렵다.
이것은 GCC 2.7용 소스 복원 전에 해결해야 할 구체적인 ABI 결함이다.

이번 Python 시험 250건은 모두 통과했다. 이는 아래 제한된 계약의 검증이며
전체 런타임 의미·모든 반환형·실제 부팅·GCC 2.7 호환성 완료를 뜻하지 않는다.

## 방법과 원본 보존

Ghidra·IDA 분석 스킬에 따라 원본 명령, 도구의 해석, 참조 선언, 실행 시험을 분리했다.
라이브 DB를 수정하지 않고 기존 export를 원본 바이트로 독립 디코딩했다.
계산·주소 변환·스택/캐시 배치·집계·해시 검증은 모두 Python으로 수행했다.

Unicorn 2.1.4의 별도 메모리에 원본 커널 세그먼트를 로드했다.
객체·class·cache·인자 프레임·호출 스택은 합성 자료이며 multithread mask와 lock도
시험용 메모리에서 설정했다. 디스크의 원본 커널이나 프로젝트를 패치하지 않았다.
메서드까지 연결한 시험을 제외한 기본 행렬은 합성 IMP를 사용한다.
캐시 miss 시험에서는 lookup 함수 진입을 확인하고 반환을 명시적으로 모의한다.

실행 도중 이전 종료 주소에서 다시 시작할 때 Unicorn의 translation cache 때문에
명령이 진행하지 않는 현상을 재현했다. 재개 주소의 translation을 무효화한 뒤
실행 주소·스택·결과를 모두 확인하도록 하네스를 보완했다. 커널 명령 패치로 처리하지 않았다.

## 실제 dispatch 실행 결과

[실행 자료](dispatch-execution.json), [재현 스크립트](dispatch_execution.py).

| 검사 묶음 | 통과 사례 | 검증 대상 |
|---|---:|---|
| 일반/super dispatch | 48 | 잠금 유무, cache hit·collision·miss, bucket wrap, tail stack |
| nil receiver | 6 | `objc_msgSend`의 EAX=0, EDX 보존, 잠금 미접근 |
| 정상 forwarding | 4 | 원본 forwarder와 dispatcher를 연결한 인자/반환 전달 |
| `objc_msgSendv` | 156 | 인자 크기별 복사 순서, 인자 수, 반환 레지스터, 스택 복원 |
| 원본 메서드 연결 | 36 | 위 메서드의 실제 명령과 일반/super/vector 경로 |

### Tail transfer와 super receiver

캐시 구조를 `class + 0x20`, cache mask, bucket 배열, method의 selector/IMP 필드로 구성했다.
선택한 selector의 bucket에 불일치 항목을 놓아 linear probe와 끝 bucket에서의 wrap도 실행했다.
이 배치는 원본 명령 및 로컬 SDK의 non-`OBJC_COPY_CACHE` 구조와 일치한다.
모든 빌드 설정이 이 매크로 조합이라고 일반화하지 않는다.

IMP 진입 시 확인한 사항:

- 일반 dispatch는 원래 RET 주소, receiver, selector, 추가 인자들과 ESP를 유지한다.
- super dispatch는 스택의 `objc_super *` 인자 자리를 그 구조체의 receiver로 교체한다.
- EBX·ESI·EDI·EBP는 보존된다.
- 잠금 경로는 IMP로 JMP하기 전에 lock을 해제한다.
- miss lookup에는 class와 selector가 전달된다. 잠금 경로에서는 lookup 시 lock이 유지된다.
- lookup 반환의 ECX·EDX를 모의로 덮어써도 tail transfer의 인자 스택은 유지된다.

Ghidra의 `(*code)()`와 IDA의 `return Cache()` 같은 출력은 이 스택 계약을 충분히 표현하지 않는다.
인자 없는 일반 C 함수 호출로 옮기는 것은 원본과 동등하다고 볼 수 없다.
스택에 새로운 복귀 주소를 추가하는 CALL로 바꾸는 것과도 구분해야 한다.

### Nil 반환의 범위

원본 `objc_msgSend`의 nil 경로는 EAX=0 상태에서 RET하지만 EDX는 초기화하지 않는다.
잠금이 이미 설정된 합성 조건에서도 이 경로는 lock을 만지지 않았다.
따라서 이 명령만으로 “nil은 모든 폭의 반환 레지스터와 구조체 버퍼를 0으로 만든다”고
해석해서는 안 된다. 이는 언어 전체의 nil 반환 규칙에 대한 주장이 아니다.
`objc_msgSendSuper`의 nil 안전성을 검사한 결과도 아니다.

### `objc_msgSendv`의 실제 인자 복사

시험한 `arg_size`는 0–35 및 63, 64, 65다. 일부는 의도적인 경계/비정렬 입력이며
유효한 API 사용이라고 인정한 것이 아니다.
이 범위에서 추가로 복사하는 word 수는 Python 기준식
`max((arg_size >> 2) - 2, 0)`과 일치했다.

인자 프레임의 앞부분에는 일부러 다른 receiver/selector 값을 넣었다.
실제 dispatch에는 `objc_msgSendv`의 명시적 receiver/selector 인자가 전달되고,
추가 인자는 프레임의 `+8` 이후에서 뒤쪽 word부터 PUSH됐다.
각 프레임 read의 주소·폭·순서도 비교했다.

저장된 IDA C는 지역 변수 `v7` 하나를 가변 인자로 표시한다.
원본의 가변 길이 stack 구성이나 복사하지 않는 조건을 충실히 표현한 C가 아니다.
Ghidra C의 미해석 stack 표현도 그대로 구현에 사용할 수 없다.
매우 큰 길이, 잘못된 포인터, 페이지 fault, stack 고갈은 이번 행렬에 포함하지 않았다.

## 실제 메서드의 반환 — 새로 구체화된 ABI 문제

기본 시험의 합성 IMP에서 더 나아가, 실제 원본 메서드에 대해 일반 dispatch,
super dispatch, `msgSendv` 경로를 실행했다. 이 묶음에서는 lookup이나 IMP를 모의하지 않았다.
객체와 cache만 합성했으며 실제 클래스 초기화/메타클래스 등록까지 실행한 것은 아니다.

### `mappedRange`와 `SCSI3_lun`

`mappedRange` (`0x0017f348`)는 receiver의 `+8`, `+0xc`에서 각각 EAX·EDX를 읽는다.
메타데이터는 구조체 반환을 나타내며, Darwin 참조 구현도 `return _mappedRange`다.
Ghidra의 `undefined8`은 레지스터 폭의 힌트일 뿐 올바른 구조체 타입을 복원한 것은 아니다.

`SCSI3_lun` (`0x001ae96c`)은 `+0x110`, `+0x114`에서 EAX·EDX를 읽는다.
바이너리 `Q` 인코딩과 참조 구현의 `unsigned long long` 선언이 이를 뒷받침한다.
동일한 레지스터 쌍을 사용해도 앞 메서드와 소스 반환 타입은 다르다.

### `nodeAddress` — EBX 숨은 출력 포인터

`nodeAddress` (`0x001ab830`)의 원본은 다음 계약을 보인다.

- `[EBP+8]`을 receiver로 사용한다.
- receiver `+0x13c`에서 dword, `+0x140`에서 word를 읽는다.
- 그 값을 진입 당시 EBX의 주소와 `EBX+4`에 기록한다.
- EAX를 EBX로 설정하고, 저장했던 EBX를 복원한 뒤 RET한다.

출력 버퍼를 EBX에 주고 실행한 모든 해당 사례에서 원본 데이터 6바이트가 복사됐고,
뒤에 둔 canary 2바이트는 유지됐다. 실제 dispatcher와 vector wrapper도 EBX를 보존했다.
따라서 이 메서드의 의미를 `void` 및 초기화되지 않은 `unaff_EBX`로 남겨서는 안 된다.

저장된 IDA 출력에는 `retstr`이라는 명시적 인자가 추가되고 그 포인터에서 receiver 필드를 읽는
모양이 나타난다. 원본은 스택의 receiver와 EBX 출력 포인터가 별도다.
이 차이를 기록하지만 live IDA DB의 바이트·calling convention·타입 원인을 새로 확인한 것은 아니다.

현재 export에서 `nodeAddress` selector를 가리키는 참조는 메서드 메타데이터 항목만 검출됐다.
실제 커널 내부의 이 selector 호출 지점을 확인했다는 주장은 하지 않는다.
시험은 원본 callee 계약과 dispatcher의 전달 능력을 보여준다.

## 메타데이터·참조 소스 교차검증

[메타데이터 근거](metadata-evidence.json), [검증 스크립트](metadata_evidence.py).
기존 inventory의 메서드 항목 1,137개에 대해 원본의 selector 포인터/문자열,
type 포인터/문자열, IMP 주소가 일치하는지 다시 검사했다.
이는 기존 항목의 필드 검증이며 모든 동적 메서드의 발견 완료나 owner 분류 전체의 증명은 아니다.

로컬 OPENSTEP SDK는 `objc_msgSend`, `objc_msgSendSuper`, `objc_msgSendv`를 `id` 반환으로 선언한다.
`Object`의 `forward::`, `performv::`는 바이너리에서도 `@16@8:12:16^v20`이다.
그러나 이 선언을 모든 동적 메서드의 반환 규약으로 강제할 수 없다는 것이 위 실제 실행의 요점이다.
Darwin의 대응 메서드 본문은 출처가 다른 참조 소스이지 mk-183.34.4 전체 소스와의 동일성 증거는 아니다.
근거 파일별 해시와 해당 선언/본문의 줄 번호는 JSON에 기록했다.

## 커버리지 해석과 남은 작업

기존 listing 기준 `objc_msgSend`의 명령 시작점 73개, `objc_msgSendSuper`의 80개,
`objc_msgSendv`의 20개가 이 시험에서 모두 실행됐다.
이는 명령 시작점 방문일 뿐 모든 branch outcome·입력·스레드 interleaving 검증이 아니다.
특히 이미 잡힌 lock의 경쟁/진행성, 가득 찬 cache의 종료성, lookup 내부는 미검증이다.
Forwarder는 정상 경로만 실행했으며 오류 경로와 잘못 분류된 padding은 미실행 목록에 남겼다.

다음 검토에서는 EBX 구조체 반환이 다른 메서드와 호출 지점에 어떻게 사용되는지,
그리고 decompiler prototype/storage에 어떤 교정이 필요한지를 확대 조사해야 한다.
모든 aggregate 반환 규칙, x87, GCC 2.7 compiler-spec, 실제 툴체인 코드는 아직 확정하지 않았다.
앞선 예외/문맥 전환 및 IDA 불일치 문제도 남아 있으므로 분석 완료를 선언하지 않는다.

`07_kernel`과 canonical Ghidra/IDA 분석 프로젝트는 변경하지 않았다.
재현은 프로젝트 루트에서 다음과 같이 수행한다.

```sh
python3 -B 09_validation/reports/continuous-review-20260911-06/dispatch_execution.py
python3 -B 09_validation/reports/continuous-review-20260911-06/metadata_evidence.py
python3 -B 09_validation/reports/continuous-review-20260911-06/verify_artifacts.py
```

보존 검증: [verification.json](verification.json).
입력 해시: [input-hashes.json](input-hashes.json).
이 보고서의 증거 manifest: [artifact-hashes.json](artifact-hashes.json).
