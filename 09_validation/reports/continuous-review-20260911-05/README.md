# 연속 추가검토 — ObjC padding 분류와 정상 반환 경로

대상: OPENSTEP 4.2 mk-183.34.4 / x86. 검토일: 2026-09-11.
원본 SHA-256: `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`.
선행 근거: [R02 최초 검토](../deep-review-20260911/README.md),
[비복귀 계약 실험](../continuous-review-20260911-04/README.md).

## 결론

`__objc_msgForward` 뒤의 padding을 데이터로 분류하고 함수 본문에서 제외하는 것만으로는
잘못된 디컴파일 C가 사라지지 않았다. 오류 처리 함수의 비복귀 계약까지 보완해야
이웃 함수 명령의 혼입이 사라졌다. Listing의 CALL fallthrough는 별도의 속성이므로
추가 교정이 필요했다.

그러나 이렇게 얻은 C도 완성 소스는 아니다. 정상 forwarding 경로가 `void`로 출력되어,
원본에서 관찰되는 디스패처 반환 레지스터의 전달을 명시하지 않는다.
원본 명령을 실행한 제한된 시험으로 EAX·EDX 보존을 확인했지만, 전체 ObjC 반환 ABI는 미확정이다.

기존 프로젝트와 canonical export에는 수정 사항을 적용하지 않았다.
이번 결과는 R02의 교정 조건을 더 구체화한 것이며 전체 분석 완료 판정이 아니다.

## 입력 검증과 가역성

Ghidra·IDA 분석 스킬의 원본/해석 분리 원칙에 따라 새 복사본에서만 실험했다.
이번에는 Ghidra headless와 원본 명령 실행을 사용했으며 IDA DB를 새로 검증하거나 변경하지 않았다.
Java는 Ghidra API 조작과 추출만 담당했다. 주소 범위·크기·개수·해시·차이 계산과
시험 조건 생성은 모두 Python으로 수행했다.

- 오류 CALL: `0x001cebee` → `___objc_error` (`0x001cdd10`).
- 그 다음 영역: `0x001cebf3`–`0x001cebff`, 원본의 zero byte 13개.
- 다음 함수: `_objc_msgSendv`, `0x001cec00`.
- 기존 export에서 이 영역을 직접 가리키는 reference와 symbol은 없었다.
- 이 영역과 겹치는 기존 함수 본문은 `__objc_msgForward`뿐이었다.

참조가 없다는 사실만으로 숨겨진 간접 진입이 절대 없음을 증명하지는 않는다.
오류 경로의 비복귀 근거, 다음 함수 경계, 원본 바이트를 함께 사용한 국소 판정이다.
입력 자료: [padding-job.json](padding-job.json).

복사본 위치는 `04_ghidra/projects/experiments/padding-review-20260911/`이다.
`-readOnly -noanalysis`로 열고 임시 transaction을 취소한 뒤 종료했다.
원래 프로젝트와 복사본 각각의 기존 파일 9개는 실행 전후 해시가 같았다.
원본 파일 전체 1,117,920바이트를 Ghidra 메모리와 대조했고, 초기화된 메모리 블록 26개도
실험 전후 동일했다. 근거: [run-result.json](run-result.json), [audit.json](audit.json).

## 단계별 비교

각 단계에서 새 decompiler 인스턴스로 대상 함수 6개를 추출했다.
아래 본문 크기는 연속 구간 전체 길이가 아니라 함수에 속한 주소 범위들의 바이트 합이다.

| 단계 | padding 분류 | 함수 본문 바이트 | 잘못된 C 경로 | CALL 다음 주소 |
|---|---|---:|---|---|
| baseline | 명령 6개 + undefined 1바이트 | 72 | 존재 | `001cebf3` |
| padding_only | byte 배열 13바이트 | 60 | baseline과 C가 동일 | `001cebf3` |
| combined | 위 분류 + 오류 함수 비복귀 속성 | 60 | 제거됨 | `001cebf3` |
| explicit_no_fallthrough | 위 상태 + CALL fallthrough 제거 | 60 | combined와 C가 동일 | 없음 |

`padding_only`는 `clearCodeUnits`로 해당 영역의 분류를 제거하고 byte 배열로 정의하며,
함수 본문에서 겹치는 주소만 뺀다. 원본 바이트를 지우거나 NOP로 패치하지 않았다.
본문에서 빠진 것은 12바이트이며, 마지막 바이트는 원래부터 본문 밖 undefined였다.

`combined`는 `___objc_error`와 `__objc_error`에만 `noreturn=true`를 추가한다.
이 시점에 C는 개선되지만 Listing의 CALL 다음 주소는 남는다.
마지막 단계는 `Instruction.setFallThrough(null)`로 이 불일치를 해소한다.
`CALL_RETURN` override를 사용해 가상의 RETURN을 삽입한 것은 아니다.
마지막 조작이 C 개선에도 반드시 필요하다고 주장하지 않는다. C는 combined에서 이미 개선됐다.

함수 본문 밖 p-code 주소도 검사했다. Baseline에서는 다음 주소가 검출됐다.
`001cebff`, `001cec02`, `001cec05`, `001cec07`.
Padding-only 단계에서는 기존 명령 영역을 본문에서 제외했는데도 같은 C를 만들기 때문에,
그 padding 주소들까지 본문 밖 p-code로 남는다. Combined와 마지막 단계에서는 검출되지 않았다.
즉 함수 본문 범위와 데이터 분류를 고쳤다는 사실만으로 decompiler의 실행 흐름도 교정됐다고 볼 수 없다.

- [기존 C](exports/baseline/001cebb0.c)
- [padding만 교정한 C](exports/padding_only/001cebb0.c)
- [비복귀 계약까지 적용한 C](exports/combined/001cebb0.c)
- [Listing 흐름까지 교정한 C](exports/explicit_no_fallthrough/001cebb0.c)

## 전역 영향 검사

전체 함수 본문 5,253개를 비교했으며 변경은 `__objc_msgForward`에만 있었다.
본문의 마지막 구간은 `001cebe0`–`001cebfe`에서 `001cebe0`–`001cebf2`로 줄었다.
전체 code-unit 비교에서 차이가 있는 시작 주소는 8개이며 모두 padding 영역 또는 해당 CALL에 속했다.
Reference edge의 추가와 삭제는 모두 없었다.

이 비교가 검사한 code-unit 속성은 시작/끝 주소, instruction/data/undefined 분류,
flow override, fallthrough이다. 모든 Ghidra 데이터 타입과 메타데이터를 전수 비교했다는 뜻은 아니다.
초기화된 메모리 바이트는 별도로 전수 비교했다.

대조 함수 `_objc_msgSendv`, `_objc_msgSend`, `__switch_tss`의 C는 모든 단계에서 같았다.
이는 실험의 국소성을 뒷받침하지만 이 대조 함수들의 ABI나 디컴파일 의미가 정확하다는 증명은 아니다.

## 추가 발견 — 정상 forwarding 반환 정보 누락

오류 경로를 정리한 출력은 다음과 같은 형태다.

```c
void __objc_msgForward(...) {
    /* 정상 경로 */
    _objc_msgSend(...);
    return;
    /* 별도 오류 경로는 비복귀 호출 */
}
```

위 코드는 형태를 설명하기 위한 발췌이며 컴파일용 선언이 아니다.
원본 정상 경로는 `001cebd0`에서 `_objc_msgSend`를 CALL하고,
`001cebd5`부터 `MOV ESP,EBP; POP EBP; RET`를 수행한다.
이 epilogue는 EAX와 EDX를 덮어쓰지 않는다.

[Python 실행 시험](forwarding-return-tests.json)은 원본 prologue와 CALL을 실행하여
receiver, forwarding selector, 원래 selector, 인자 목록 포인터의 전달을 확인했다.
디스패처 진입에서 실행을 멈춘 다음 반환 레지스터를 모의하고 원본 epilogue를 실행했다.
12개 조건 모두 EAX·EDX 전달과 EBP·ESP 복원을 통과했다.

제한 사항:

- `_objc_msgSend` 내부와 실제 메서드를 실행한 시험이 아니다.
- EDX 보존만으로 모든 메서드의 반환형을 64비트 정수라고 정할 수 없다.
- x87, 구조체 반환, 실제 메서드 signature, GCC 2.7의 코드 생성은 검증하지 않았다.
- `void` C가 우연히 같은 레지스터를 남기는 경우와 ABI를 소스로 올바르게 표현하는 것은 다르다.

따라서 정상 반환값이 필요한 호출까지 재구성하려면 dispatcher/forwarder의 반환 계약을
별도로 확정해야 한다. 비복귀 속성으로 C가 간결해졌다는 이유로 이를 완료 처리하면 안 된다.

## 재현과 남은 검토

`run_padding.py`는 기존 실험 디렉터리가 있으면 덮어쓰기를 거부한다.
새 snapshot/output 위치를 지정하여 실행해야 Ghidra 단계를 재현할 수 있다.
이미 추출된 자료와 원본 기반 시험은 다음 명령으로 재검증할 수 있다.

```sh
python3 -B 09_validation/reports/continuous-review-20260911-05/audit_padding.py
python3 -B 09_validation/reports/continuous-review-20260911-05/verify_artifacts.py
```

다음 우선 검토는 ObjC forwarding/dispatch 반환 계약과 타입 근거다.
이후에도 전이적 비복귀 속성, 예외/문맥 전환, IDA export 불일치 및 나머지 분석 경고가 남아 있다.
이번에는 `07_kernel` 구현을 수정하지 않았고 GCC 2.7 컴파일 가능성을 검증한 것도 아니다.

보존 검증은 [verification.json](verification.json), 새 증거 파일 해시는
[artifact-hashes.json](artifact-hashes.json)에 기록한다. Runtime cache는 증거 manifest에서 제외한다.
