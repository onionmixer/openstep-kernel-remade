# x86 디컴파일·역어셈블 상세 재검토

검토일: 2026-09-11. 대상: OPENSTEP 4.2 / mk-183.34.4 / RELEASE_I386.
기준 export: `04_ghidra/exports/x86/full-pass5/`.
SHA-256: `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`.

## 결론

**자료 파일은 폭넓게 확보되어 있으나, “부족하거나 누락된 분석이 없다”는 판정은 불가하다.**
실제 디컴파일 오류, 이웃 함수 코드 혼입, 실제 콜백의 잘못된 분류,
IDA의 요청 주소와 다른 함수 결과 반환을 확인했다.
이전 보고서의 “자료 확보 완료”를 “전체 코드의 정확한 디컴파일 완료”로 해석해서는 안 된다.
그런 의미의 완료 판정은 이번 검토 결과로 정정한다.

원본 바이트의 유실이나 대규모 assembly 파일 누락은 발견하지 못했다.
그러나 export 성공, 바이트 포함, 함수 의미·제어 흐름의 충실한 표현은 각각 다른 조건이다.
현재 자료를 그대로 GCC 2.7 소스로 옮기는 단계로 진행하는 것은 권하지 않는다.

이번 작업은 검토다. 원본·기존 export·분석 DB의 함수 경계·타입·코드를 수정하지 않았다.
새 보고서와 읽기 전용 진단 자료만 추가했다. 기존 완료 기록은 과거 판정 이력으로 남겼다.

## 검토 방법과 범위

Ghidra/IDA 분석 스킬의 원본·작업 DB·도구 해석 분리 원칙을 적용했다.
Ghidra 프로젝트를 `-readOnly -noanalysis`로 열고, 모든 분석 단위의 HighFunction
중간 표현(p-code), C 토큰의 원본 주소, 복구된 jump table을 다시 추출했다.
Ghidra Java 스크립트는 도구 정보를 추출하고, 주소 변환·합계·비교·집계는 Python으로 수행했다.
IDA는 보존된 원시 응답과 C 출력을 검토했으며 새 IDA DB 편집은 하지 않았다.

수행한 전수 검사:

- 원본 파일과 Ghidra의 초기화된 메모리 블록을 바이트 단위로 직접 대조.
- 기존 최종 export의 저장 해시 재검증.
- `__text`의 모든 인식된 instruction 시작점에서 Capstone으로 원본 바이트를 다시 decode.
- 직접 분기·call 목적지와 Ghidra listing 경계·참조를 대조. far branch는 selector와 offset을 구분.
- 함수 본문 바이트의 중복 소유·명령 외 데이터 포함·소속 없는 명령 검사.
- 모든 HighFunction의 주소와 listing instruction 경계·선언된 함수 본문을 대조.
- 모든 간접 jump와 복구된 jump table, C 출력의 경고·불명확한 변수 표기를 집계.
- IDA 성공 출력의 주소별 중복·함수 문맥, 실패 목록 및 Ghidra 경고 중첩 검사.
- 원본 BSD syscall/Mach trap 테이블을 헤더 구조에 맞춰 독립 파싱하고 함수 진입점 대조.

또한 아래 확정 사례와 대표 경고·fault recovery·ObjC dispatch·초기화·타이머 콜백을
원본 assembly, 양 도구 출력 및 관련 참고 소스와 직접 대조했다.
모든 함수의 모든 입력·하드웨어 상태에 대한 의미적 동등성을 증명한 것은 아니다.

## 통과한 검사와 그 한계

| 검사 | 결과 | 이 결과가 뜻하지 않는 것 |
|---|---:|---|
| 원본과 Ghidra 초기화 메모리 비교 | 1,117,920바이트 전체 일치, 빠진 파일 바이트 없음 | 함수 경계·타입의 정확성 |
| 초기화된 메모리 블록 비교 | 26개 일치 | 실행 중 패치·동적 상태의 검증 |
| 기존 최종 export 파일 해시 | 15,770개 일치 | 내용의 의미적 정확성 |
| instruction 시작점별 독립 decode | 286,091개, decode 실패·길이 불일치 없음 | 그 위치가 실제 실행 코드인지 여부 |
| 직접 branch/call | 49,884개, 참조 간선 누락 없음 | RET·fault·간접 제어 이동의 완전성 |
| 비정상 직접 목적지 후보 | `__bios32`의 정적 `lcall 0:0`만 남음 | 실제 주소 0 호출이라는 결론; 아래 자체 수정 코드 참조 |
| 중복 소유 바이트 / 소속 없는 명령 | 없음 / 없음 | 인위적으로 부여한 함수 소유 관계의 타당성 |
| HighFunction 재추출 | 5,253개 모두 도구상 성공 | 모든 명령이 C에 충실하게 표현됨 |
| BSD `_sysent` | 184항목, 고유 handler 143개, 진입점 누락 없음 | syscall 내부 구현 검증 |
| `_mach_trap_table` | 70항목, 고유 handler 26개, 진입점 누락 없음 | trap ABI·복귀 문맥 검증 |

BSD 테이블은 로컬 SDK `bsd/sys/systm.h`의 `short, short, pointer` 구조로,
Mach trap은 참고 소스 `kernel/kern/syscall_sw.h`의 네 word 구조로 파싱했다.
원본의 count·포인터 범위·진입점 일치도 함께 확인했다. 원본 해시와 입력 자료는
`supplemental.json`, `review-artifact-hashes.json`을 참조한다.

## 확정된 문제

### R01 — 예외 처리 C 출력에 다음 함수가 섞임 [높음]

대상: `_NXDefaultExceptionRaiser`, `0x001cad48`.

- 원래 assembly 본문은 `0x001cae2b`에서 `_jump_label(0x00186fb0)`을 호출하는 곳까지다.
- `_jump_label`은 저장된 ESP와 복귀 주소를 복원한 뒤 `RET`한다.
  일반적인 현재 호출자의 다음 명령으로 돌아오는 함수가 아니다.
- 그런데 Ghidra는 `_jump_label()` 다음에 잠금·`_realloc()`·할당 결과 저장 코드를 C로 출력한다.
  이는 바로 다음 주소 `0x001cae30`에서 시작하는 `_NXAllocErrorData`의 코드다.
- HighFunction에서도 선언된 본문 밖 instruction 주소 15개가 이 함수 결과에 포함된다.
- IDA의 같은 주소 출력은 `longjmp(...)` 및 `__noreturn`으로 표현하며 이웃 함수 혼입이 없다.

판정: 단순 경고가 아니라 **제어 흐름 모델 오류에 따른 다른 함수 코드 혼입**이다.
`_jump_label`의 비지역 복귀 의미와 호출 위치의 fallthrough를 먼저 바로잡고 재분석해야 한다.

근거: Ghidra `functions/001cad48.c`, `.asm`, `00186fb0.asm`, `001cae30.c`;
IDA `functions/001cad48.c`; `pcode-audit.json`의 `outside_body_pcode`.

### R02 — ObjC forwarding의 정렬 바이트를 코드로 오인, 잘못된 경계로 추가 decode [높음]

대상: `__objc_msgForward`, `0x001cebb0`.

- 오류 경로는 `0x001cebee`에서 `___objc_error`를 호출한다.
- 이후 `0x001cebf3`부터 다음 함수 `0x001cec00` 전까지 원본은 0 바이트로 채워져 있다.
  이 13바이트 중 12바이트가 현재 listing에서 `ADD byte ptr [EAX],AL` 명령으로 분류됐다.
- Ghidra C에는 그 결과로 `*pcVar3 += cVar1` 반복과 `in(0x8b)` 등의 잘못된 연산이 나타난다.
- 더 나아가 HighFunction은 `0x001cebff`, `0x001cec02`, `0x001cec05`, `0x001cec07`을
  코드 주소로 사용한다. 이들은 최종 listing의 instruction 시작점이 아니다.
- 모든 HighFunction을 비교했을 때 listing instruction 경계와 이런 불일치를 보인 일반 함수는 이 함수다.

판정: **함수 경계·비복귀 경로·정렬 분류의 확정적인 분석 오류**다.
원본 바이트가 손상된 것이 아니라 도구가 정상 바이트를 잘못 해석했다.
따라서 기존 `instruction_bytes` 값도 순수한 실제 명령 바이트 수라고 단정할 수 없다.

근거: `functions/001cebb0.c`, `.asm`, `001cdd10.c`, `001cdd80.c`;
`pcode-audit.json`의 `offcut_pcode`; 읽기 전용 `ghidra-functions.jsonl`.

### R03 — CPU 초기화·trap 복귀의 중요한 기계 동작이 C에서 생략됨 [높음]

대상: `FUN_0018ac28`, trap 공통 처리 `FUN_00186d20` 등.

`FUN_0018ac28`의 원본에는 다음 작업이 있으나 Ghidra C에는 충분히 남지 않는다.

- `0x0018ac54`의 CR0 읽기, `0x0018ac5c`의 `WBINVD`, `0x0018ac5e`의 CR0 쓰기.
- `0x0018ac84` 이후 EFLAGS 변경·재읽기 및 `0x0018ac96`의 조건 분기.
- C 출력은 이 조건을 보존하지 않은 채 `cpuid_Version_info(1)`을 실행하는 형태다.

IDA 출력에는 위 CR0·캐시·EFLAGS 동작과 조건이 남아 있다.
단, 같은 함수의 `0x0018ac50` HLT 경로는 EDX에 비트를 OR한 후 동일 EDX를 TEST하는
코드상 도달 불가능 경로이므로 그 제거 자체를 오류라고 판정하지 않았다.

`FUN_00186d20`의 assembly 끝은 `IRETD`이고 세그먼트·스택·인터럽트 상태 복원이 있다.
Ghidra C는 일반 `return CONCAT44(...)` 형태로 표현한다. 이를 일반 C 함수의 return과
동등한 복귀로 간주해서는 안 된다.

판정: **assembly는 확보됐지만 하드웨어 동작을 보존한 디컴파일 자료로는 불충분**하다.
기계의존 경로는 명시적인 assembly 계약과 함께 검토해야 한다.

근거: 양 도구의 `functions/0018ac28.c`, Ghidra `0018ac28.asm`, `00186d20.asm`, `.c`.

### R04 — IDA “성공” 응답 중 요청한 함수 문맥이 아닌 결과가 있음 [높음]

대상 요청 주소: `0x00186d14`, `0x00186d20`, `0x00186d80`.

- 주소별 저장 파일은 서로 다르지만 헤더 주석을 제외한 IDA C 내용이 완전히 같다.
- 모두 `int_0xFF`에서 시작해서 `catch_interrupt()`를 호출하는 결과다.
- 특히 `0x00186d20`의 원본 assembly는 `0x00186d63`에서 `_catch_trap`을 호출한다.
  따라서 해당 파일은 요청 주소를 진입점으로 하는 코드의 올바른 독립 결과가 아니다.
- 원시 응답의 `addr`는 요청 주소와 같았으므로 단순한 `requested_address == addr` 검사로는 잡히지 않았다.

판정: **4,519는 성공 응답 주소 수이지 독립 함수 수나 검증된 함수 수가 아니다.**
중복을 제거해도 나머지 결과의 정확성이 자동으로 보장되는 것은 아니다.
IDA의 실제 containing function·본문 범위·입력 바이트·패치 상태를 확인해야 한다.

근거: `05_ida/exports/x86/functions/00186d14.c`, `00186d20.c`, `00186d80.c`와
Ghidra `functions/00186d20.asm`. 중복 집계는 `supplemental.json`.

### R05 — 실제 호출되는 콜백을 “실제 함수가 아닌 분석 조각”으로 분류 [중간]

대상: `__analysis_fragment_0019f0a0`.

- 원본에 독립적인 `PUSH EBP / MOV EBP,ESP` 진입부와 `RET` 종료가 있다.
- 내부에서는 인자를 받아 ObjC `autoRepeat` 메시지를 전송한다.
- `0x0019f18d`, `0x0019f1c4`에서 이 주소를 인자로 전달하고,
  각각 `_ns_untimeout`, `_ns_abstimeout`을 호출한다.
- 즉, 단순히 기존 함수의 중간 명령 조각이 아니라 등록·해제되는 콜백의 역할이 확인된다.

판정: 코드와 C 파일은 있지만 **함수 인벤토리의 역할 분류가 잘못되어 있다.**
기존 “일반 함수 4,761개 / 조각 492개”는 검증된 실제 함수 구성이 아니다.
직접 CALL만 아니라 콜백 등록 인자·데이터 참조를 포함한 진입점 검토가 필요하다.

근거: Ghidra `functions/0019f0a0.asm`, `.c`, `0019f17c.asm`, `.c`.

## 누락 여부를 더 검토해야 하는 범위

### R06 — 분석 조각은 원래 제어 흐름으로 재결합되지 않음

492개 조각의 선언된 본문은 합계 2,372바이트다. 생성 사유는 panic 뒤 fallthrough,
fault recovery, 인라인 후 남은 코드, 콜백 등이 혼재한다.
panic 뒤 fallthrough로 분류된 생성 작업은 418개이며 해당 호출 대상은 모두 `_panic`이었다.

전체 HighFunction 중 선언된 본문 밖 주소를 사용하는 것은 470개다.
이 중 468개는 조각이고, 일반 함수 2개는 R01·R02다.
조각은 몇 바이트만 소유하면서 C는 다른 본문의 공통 후속 경로까지 따라가는 경우가 많다.
그러므로 조각의 `.asm` 길이와 `.c`가 나타내는 범위가 동일하다고 보면 안 된다.

예: `__analysis_fragment_001853fc.asm`에는 `0x00185408`에서 시작하는 별도 블록도 들어 있다.
그러나 해당 C와 HighFunction은 첫 진입점에서 `_printf`를 호출하는 경로만 표현하고,
`0x00185408`의 별도 메시지 경로는 표현하지 않는다.
다만 이 구간은 `_vol_panel_disk_num`에 인라인된 공통 panel 코드이며 진입 조건이 제한된다.
실행 가능한 기능이 반드시 누락됐다는 증거로 사용하지 않는다.
**여러 블록을 한 조각으로 묶고 C 파일 하나가 생겼다는 사실만으로 모든 블록의 디컴파일을
완료 처리할 수 없다는 반례**다.

반대로 `_copyin`의 `0x00189b18`은 원본에서 thread 상태에 복귀 주소로 저장되는
실제 fault recovery 코드다. 별도 조각의 C는 있지만 원래 함수의 스택·세그먼트·예외 복귀
문맥과 결합된 검증은 없다. 단순히 일반 C 콜백을 호출하는 코드로 바꾸면 안 된다.
`kernel/machdep/i386/fault_copy.c`, `pc_support/PCemulateREAL.c` 참고 소스에서도
label address를 `thread->recover`에 저장하는 계보를 확인했다. 대상 바이너리와의 전체 동일성은 미검증이다.

### R07 — 간접 분기·비지역 복귀·자체 수정 코드의 계약 미완성

원본 instruction 기준 간접 call 711개, 간접 jump 115개를 확인했다.
HighFunction에는 고유 switch site 104개가 있고 그 case 목적지는 모두 listing 명령 시작점이다.
나머지 jump 11개는 다음과 같다.

| 위치 | 개수 | 성격 |
|---|---:|---|
| `_objc_msgSend` | 4 | 런타임 IMP dispatch |
| `_objc_msgSendSuper` | 4 | superclass IMP dispatch |
| `__switch_tss` | 2 | 저장된 실행 문맥으로 이동 |
| `__call_with_stack` | 1 | 스택을 바꾼 뒤 제어 이동 |

이것을 “일반 switch의 case 11개 누락”이라고 해석하면 안 된다.
분기 대상·인자·반환값·스택·레지스터 보존의 계약을 수작업으로 확인해야 한다는 뜻이다.
`_objc_msgSend` C의 `void` 및 인자 없는 간접 call 표기를 실제 메시지 ABI로 채택할 수 없다.

`__bios32`의 `lcall 0:0`은 앞선 명령이 call instruction의 offset/selector를 수정하는 코드다.
Ghidra의 read-only-address-write 경고 2건 및 `func_0x00000000()` 표기는 이 맥락에서 검토해야 한다.
원본 누락이나 실제 NULL 호출로 판정하지 않았다. 실행 시 패치되는 far-call 계약은 아직 명세되지 않았다.

### R08 — 경고·타입·IDA 실패 목록은 아직 해결 목록이 아님

| 지표 | 집계 |
|---|---:|
| 경고가 있는 분석 단위 | 884: 일반 함수 611, 조각 273 |
| unreachable 제거 경고가 있는 단위 | 43 |
| unreachable 경고에서 지목한 고유 주소 | 270 |
| unreachable 경고 총 발생 | 538 |
| 타입 전파가 수렴하지 않은 단위 | 9 |
| 호출 규약 미상 경고 발생 | 59 |
| `unaff_*`가 있는 단위 | 493: 일반 함수 54, 조각 439 |
| `in_stack_*`가 있는 일반 함수 | 51 |
| IDA 최종 실패 주소 | 244 |
| IDA 실패와 Ghidra 경고가 겹치는 주소 | 14 |

경고 중복은 조각에서 공통 후속 경로를 다시 디컴파일하면서 생기기도 한다.
따라서 538건을 538개의 독립 버그로 세지 않는다.
타입 전파 비수렴 목록에는 `_mach_msg_trap(0x00152aec)`도 있다.
Ghidra 결과가 있다는 이유만으로 IDA 실패 주소가 검증됐다고 볼 수 없다.

일반 함수 81개와 조각 17개는 C가 비어 있거나 `return;`뿐이다.
일반 함수들은 본문이 짧은 stub인 경우가 있어 이 사실만으로 실패 처리하지 않았다.
같은 이유로 모든 HighFunction에 주소가 나타나지 않는 instruction,
또는 table target instruction이 C 토큰에 없다는 것을 즉시 코드 누락으로 집계하지 않았다.
load·register move·stack 조정·조건식은 최적화로 합쳐질 수 있다.

## 기존 검증기의 빈틈

`10_tools/verify_full_analysis.py`는 다음을 검사한다.

- 도구가 `decompiled`를 보고했는가.
- C 파일에 내용과 중괄호가 있는가.
- `.asm` 주소/길이가 같은 도구의 선언된 함수 본문과 일치하는가.
- 모든 인식된 명령에 함수 또는 조각 소유자가 있는가.
- 원본 코드 섹션의 바이트가 listing에 모두 나타나는가.

이 검사는 파일 누락 검출에는 유용하다. 그러나 **잘못 정한 함수 본문을 같은 본문과 비교하는
것만으로는 경계 오류를 검출할 수 없다.** C 중괄호 존재 여부는 block/side effect 누락 검증이 아니다.
전체 linear disassembly도 잘못된 시작점에서 decode하거나 데이터를 명령으로 읽으면서
모든 원본 바이트를 포함할 수 있다.

특히 R01·R02는 기존 검사를 통과했지만 이번 HighFunction 주소 대조에서 검출되었다.
`all_exported_units_have_complete_assembly_and_pseudocode`라는 필드 이름은 현재 검사 수준보다 강하다.
향후 export 존재, byte inventory, 진입점 검토, 제어 흐름 검증, 의미/ABI 검증을 별도 판정해야 한다.

## 권장 보완 순서 — 이번 검토에서는 실행하지 않음

1. `_jump_label`·ObjC 오류 경로의 비지역/비복귀 동작을 모델링하고 R01·R02 재분석.
2. `0x0019f0a0` 같은 콜백 및 fault recovery·trap 공통 entry의 역할을 재분류.
3. 조각별 원래 owner, 모든 entry, 후속 경로, 살아 있는 코드/죽은 코드 근거를 기록.
4. CPU 초기화·스택 전환·IRET·ObjC dispatch·BIOS far call에 assembly/ABI 계약 작성.
5. IDA 실제 함수 경계·입력 바이트를 감사하고 실패·중복·다른 함수 결과 반환을 재검증.
6. 43개 unreachable 경고 단위와 9개 타입 비수렴 단위를 우선 대조하고,
   기본 블록·예외 경로 단위로 설명된 범위와 미해결 범위를 구분해 재export.
7. 수정된 분석의 독립 검증을 통과한 뒤 공개 소스 대조 및 GCC 2.7 복원 단계로 진행.

## 재현 자료

- `instruction-audit.json`: 원본 instruction decode·직접 분기·경고·교차 본문 검사 전체 목록.
- `pcode-audit.json`: HighFunction/listing 경계 불일치, 본문 밖 주소, 간접 jump 등의 전체 목록.
- `ghidra-functions.jsonl`: 읽기 전용으로 재추출한 모든 함수의 p-code/C 토큰 주소와 jump table.
- `ghidra-memory.json`: 원본과 직접 비교한 Ghidra 초기화 메모리 바이트.
- `supplemental.json`: 무결성·테이블·IDA 중복·대표 사례 추가 집계.
- `review-artifact-hashes.json`: 이 검토 자료의 해시.
- `scripts/`: 진단에 사용한 Python·Ghidra 스크립트. 수정을 적용하는 스크립트가 아니다.
- `ghidra-review.log`, `ghidra-review-script.log`: 읽기 전용 실행 기록.

진단 스크립트에는 이번 로컬 프로젝트 및 `/tmp` 입력 경로가 들어 있다.
재실행 시 경로를 확인해야 한다. Ghidra 첫 실행은 넓은 `/tmp` script path에서 준비가
지연되어 중단했고, 전용 script directory로 다시 실행하여 전량 추출을 완료했다.
완료 판정과 집계는 성공한 재실행 자료만 사용했다.
