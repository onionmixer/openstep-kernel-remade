# 원본 바이트 전용 contract 분석 기준

## 목적과 범위

이 문서는 OPENSTEP 원본 x86·m68k·SPARC 커널에서 호출 규약, 인자·반환값,
구조체·객체 layout을 검토할 때 사용하는 증거 기준을 고정한다. 분석 입력은 각
`03_original/<architecture>/binaries/mach_kernel`과 그 원본에서 생성한 listing,
function candidate, direct-call export뿐이다. Mach4·NeXTMach·Darwin, `01_resources`,
컴파일러 ABI 문서, Objective-C runtime schema는 사용하지 않는다.

각 아키텍처는 독립적이다. x86은 little-endian, m68k·SPARC는 big-endian으로만
원본 값을 읽는다. 한 아키텍처의 관측으로 다른 아키텍처의 ABI를 확정하지 않는다.

## 증거 ledger

[contract evidence ledger](../09_validation/reports/multiarch-input-20260921/binary-only-contract-evidence-ledger-20260923.json)는 함수 또는 analysis fragment별로 다음을 기록한다.

- current candidate body와 original-byte 대조 상태
- entry 및 lexical-exit의 현재 listing 관측
- x86 `EBP`, m68k `a6` 상대 displacement, SPARC `%i`·`%o` token 관측
- direct-call의 원본 instruction bytes와 직후 item 또는 SPARC delay-slot/post-delay item 관측
- `__OBJC` section의 architecture-native-endian raw 32-bit word 배치와 원본 payload hash

Python 재계산 집계는 다음과 같다.

| 대상 | 함수/fragment | code item | direct call | entry pattern | raw `__OBJC` word |
|---|---:|---:|---:|---:|---:|
| x86 | 5,253 | 286,091 | 15,823 | `push ebp; mov ebp,esp` 4,487 | 17,981 |
| m68k | 3,214 | 199,247 | 10,543 | `link` 742 | 0 |
| SPARC | 5,075 | 243,727 | 17,607 | `save` 4,725 | 18,065 |

이 숫자는 각각 raw instruction·current listing의 분포를 뜻한다. 함수 경계,
instruction 실행, call return, operand 역할은 뜻하지 않는다.

## 결론 규칙

다음은 **확정하지 않는다.**

- positive displacement가 인자이고 negative displacement가 local이라는 주장
- `E8` 뒤 `add esp`, m68k call 뒤 `sp` 언급, SPARC `%o` token이 호출 규약 또는 stack cleanup을 뜻한다는 주장
- lexical `ret`·`rts`·`rte`·`retl`이 실행되거나 특정 register가 반환값이라는 주장
- raw `__OBJC` word가 pointer·field·class·method·instance-variable record라는 주장
- structure/object field offset, type, size, ownership, inheritance 또는 ABI

그 결론에는 원본 바이트 외에 runtime path, operand role, type identity 또는 ABI/runtime
schema의 증거가 필요하다. 현재 사용자 지정 binary-only 범위에서는 그 증거를 도입하지
않으므로, ledger의 관측은 이후 사용자가 지정하는 개별 함수·edge·metadata range의
가설 검토 입력으로만 사용한다.

## 완료 판정

[completion audit](../09_validation/reports/multiarch-input-20260921/binary-only-contract-evidence-completion-audit-20260923.json)는 세 아키텍처에서 다음을 독립 대조한다.

1. architecture별 byte order와 original SHA-256
2. source function/fragment start set 및 code-item 분모
3. direct-call 분모와 source instruction bytes
4. `__OBJC` raw section word count 및 payload hash
5. ledger의 모든 함수 record가 original code-item byte match를 보고하는지

`raw_evidence_acquisition_complete: true`는 이 증거 수집과 provenance 대조의
완료만 뜻한다. audit의 calling convention·argument·return·layout confirmation 값이
`false`인 것은 실패가 아니라, 증거 범위를 넘어선 의미 주장을 방지하는 보류 결과다.

## Direct-call 인자·반환값 window census

[direct-call window audit](../09_validation/reports/multiarch-input-20260921/binary-only-direct-call-argument-return-window-audit-20260923.json)는 current direct-call edge 전부에 대해 직전 네 current text item과 직후 네 item을 원본 바이트로 대조한다. SPARC의 직후 window는 call 다음 item, 즉 현재 listing의 delay-slot 위치에서 시작한다.

| 대상 | direct-call window | static literal 관측 | 직후 후보 반환-register token |
|---|---:|---:|---:|
| x86 | 15,823 | raw `push imm32` 2,554, `push imm8` 2,755 | `EAX` 14,143 item |
| m68k | 10,543 | immediate-to-`-(sp)` 166 | `D0` 7,450 item |
| SPARC | 17,607 | immediate construction with `%o*` 20,042 | `%o0` 27,870 item |

literal의 bit pattern과 현재 listing의 token은 정확히 기록한다. 그러나 그 literal이
callee 인자라는 것, register가 return carrier라는 것, 값이 호출 시점에 유지된다는 것,
또는 어느 실행 path가 선택된다는 것은 기록하지 않는다. 따라서 runtime 인자값과 runtime
반환값은 여전히 확정하지 않는다.

[window completion audit](../09_validation/reports/multiarch-input-20260921/binary-only-direct-call-argument-return-window-completion-audit-20260923.json)는 각 record set가 contract ledger의 direct-call 분모와 같고, 중복 source/target/instruction record가 없으며, 모든 source/window item이 원본과 일치함을 대조한다.

## 실기 없이 가능한 정적 후속 작업 closure

[static-only follow-up closure](../09_validation/reports/multiarch-input-20260921/static-only-semantic-followup-closure-20260923.json)는 다음 원본 바이트 전용 작업을 하나의 종료 조건으로 교차한다.

1. 모든 direct-call의 pre/post-window provenance와 후보 literal/register 관측
2. x86 non-`E8` current `CALL`/non-relative `JMP`, m68k JSR/JMP effective-address pattern, SPARC `op=2/op3=0x38` register-target pattern의 전수 raw census
3. architecture-native-endian raw `__OBJC` word layout
4. x86의 C/ASM artifact와 original hash·entry header binding, m68k·SPARC candidate의 live-C 또는 tool-failure partition·provenance

이 closure는 static evidence 작업의 완료를 뜻한다. 이 범위에서 더 깊은 dataflow
해석은 current decoder의 mnemonic·token을 operand role이나 실행 path로 승격해야 하므로
허용된 원본-byte 검증 규칙을 벗어난다. 따라서 runtime argument/return position·value,
indirect/tail runtime target, structure/object field layout은 `false` disposition으로 보존한다.
