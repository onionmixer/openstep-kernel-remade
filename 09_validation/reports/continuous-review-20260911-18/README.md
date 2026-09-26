# 연속 추가검토 — CPU 제어 상태와 descriptor 표현의 부족

대상: OPENSTEP 4.2 mk-183.34.4 / x86. 검토일: 2026-09-11.
원본 SHA-256: `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`.
출발점: [포트 I/O와 IF 효과 검토](../continuous-review-20260911-17/README.md).

## 결론

이번에는 명시적 control/debug/segment register 접근 및 지정한 CPU 시스템 명령을
원본에서 재검색했다. 발견한 223곳의 소유 함수 48개를 새 읽기 전용 Ghidra 사본에서
다시 추출했다. 새 C는 provenance header를 제외하면 정본과 모두 일치한다.

주요 발견은 서로 다른 층위의 문제다.

- `WBINVD`는 설치된 언어 정의가 빈 의미이며 실제 raw P-code도 비어 있다.
- control/debug register 쓰기와 CLTS의 50곳은 원래 주소의 high register 쓰기가 없다.
- CR0를 설정하는 실제 helper와 high IR의 비교 16건 중 8건은 반환값이 같아도 CR0가 다르다.
- LGDT/LIDT 4곳은 원본 실행이 6바이트 descriptor를 읽지만, raw userop의 값 입력은 4바이트다.
  입력값이 같은데 원본에서 적재되는 base가 달라지는 반례를 확인했다.

따라서 C만이 아니라 raw P-code도 명령별 효과가 충분한지 검증해야 한다.
이 결과는 원본 커널이 고장났다는 판단이 아니라 분석 표현의 부족에 대한 증거다.

## 검색과 추출 범위

[검색 코드](scan.py), [전수 인벤토리](scan.json), [추출 실행기](extract_pcode.py),
[실행 명령](command.json), [실행 결과](run-result.json), [raw/high 자료](exports/pcode.json).

기존 함수 단위 5,253개, 고유 instruction head 286,091개를 원본 바이트로 재디코딩했다.
이번 검색은 명시적인 CR/DR/segment operand와 코드에 열거한 시스템 명령을 대상으로 한다.
모든 privileged instruction, 모든 암묵적 segment 참조 또는 MMIO를 망라했다고 주장하지 않는다.

| 분류 | 지점 수 |
|---|---:|
| 명시적 control/debug register 접근 | 66 |
| 명시적 segment register operand | 81 |
| 나머지 지정 시스템 명령 | 76 |
| 합계 | 223 |

control/debug 접근은 CR0 읽기 10·쓰기 12, CR3 읽기 18·쓰기 22,
CR2 읽기 3, DR6 쓰기 1곳이다.
시스템 명령은 HLT 9, far JMP 2, IRETD 6, far CALL 1, CLTS 15,
LGDT 2, LIDT 2, LLDT 6, LTR 5, INVLPG 26, WBINVD 1, CPUID 1곳이다.
분류는 명시적 operand를 우선하므로 일반적으로 해당 명령이 갖는 모든 CPU 효과의 분류와는 다르다.

새 사본 `cpu-state-review-20260911`을 독립 JVM에서 `-readOnly -noanalysis`로 열었다.
기존 API 전용 `WaitPcodeEvidence.java`를 수정 없이 재사용했다.
48개 함수 모두 재디컴파일이 완료됐고 정본·사본의 기존 프로젝트 파일 9개는 변경되지 않았다.
이전 분석기 설정을 바꾸거나 원본 analyzer를 다시 실행하지 않았다.

## raw 표현과 high 표현의 차이

[대조 코드](audit_pcode.py), [명령별 결과와 언어 정의 근거](pcode-audit.json).

control/debug register 쓰기 및 CLTS 50곳은 raw에서 실제 register 출력을 가지지만,
원래 주소의 high P-code에는 같은 register 출력이 남지 않는다.
이는 주소 대응 결과이며, 다른 주소에서 효과가 재표현됐을 가능성까지 일괄 부정하는 수치는 아니다.
구체적인 실행 반례는 아래 CR0 helper에서 별도로 확인한다.

CR3를 읽고 바로 같은 일반 register 값으로 CR3에 다시 쓰는 인접 쌍은 18곳이다.
그중 16쌍은 두 원래 주소 모두에 high 연산이 전혀 남지 않는다.
이전 값과 이후 값이 같다고 CPU 상태 갱신 동작 자체를 불필요하다고 판단해서는 안 된다.
이번에는 CR3 관련 주소 변환·TLB 동작을 실행 검증하지 않았으므로
이 집계만으로 실제 flush 실패나 모든 pair의 결과를 주장하지 않는다.

`WBINVD`의 `0018ac5c`는 raw 연산 배열 자체가 비어 있다.
설치된 `ia.sinc`의 해당 정의도 `{ }`이며, 이 점은 high 최적화 이후의 누락과 다르다.
cache 동작은 이번 Unicorn 시험에서 검증하지 않았다.
다른 명령과 함께 WBINVD의 별도 효과 계약을 분석 파이프라인에 보완해야 한다.

## CR0와 CLTS 원본 실행

[실행 코드](state_execution.py), [입력별 결과](state-execution.json).

### CLTS

CLTS 15곳을 실제 바이트로 실행하고, 해당 raw P-code도 Python으로 해석했다.
기존 실행 모드의 CR0에 지정한 MP/EM/TS/NE 입력 bit 조합을 적용한 240건에서
원본 CR0, raw 해석 결과, TS bit를 끄는 예상값이 일치했다.
이를 모든 CR0 값·paging 모드·권한·FPU 예외에 대한 검증으로 해석하지 않는다.

검증 도구의 초기 버전은 raw 연산을 한 개로 가정하여 assertion에서 중단됐다.
실제 CLTS는 INT_NEGATE로 mask를 만들고 INT_AND로 CR0를 갱신하는 두 연산이었다.
register 출력만 선택하도록 대조기를 수정하고 두 연산을 실제로 해석한 뒤 재실행했다.
실패를 통과로 처리하거나 raw 자료를 수정하지 않았다.

### CR0 설정 helper

`FUN_0018a7e4`의 원본은 전역값을 0으로 쓰고, CR0를 읽어 bit 3을 켠 뒤 CR0에 다시 쓴다.
EAX에는 계산한 값이 남아 반환된다. 정본·새 high IR에는 CR0 쓰기가 없고 계산값만 반환한다.

추출된 COPY/INT_OR/RETURN만 허용하는 작은 Python 실행기로 high IR을 해석하고,
원본은 실제 호출 스택에서 함수 전체를 실행했다.
16개 CR0 입력 조건에서 반환값은 모두 같지만 최종 CR0는 8건 다르다.
원본의 callee-saved register 및 호출 스택 복원도 검사했다.
반환값만 보는 검증이 놓치는 또 다른 부작용 반례다.

이 high-IR 실행기는 범용 interpreter가 아니며, 전체 CPU·메모리 상태 동등성도 검사하지 않는다.
CR0 입력은 기존 paging 모드를 유지한다. FPU 명령이나 그 예외를 이어서 실행하지 않았다.

## LGDT/LIDT descriptor 입력 부족

대상은 다음 원본 지점이다.

| 함수 | 명령 주소 | 원본 descriptor 메모리 주소 |
|---|---|---|
| `_locate_gdt` | `0018a918` | `001e17b0` |
| `_gdt_init` | `0018aaef` | `001e17b0` |
| `_locate_idt` | `0018b198` | `001e17b8` |
| `_idt_init` | `0018b29a` | `001e17b8` |

Capstone 원본 디코딩은 memory operand를 6바이트로 보고한다.
원본 명령의 Unicorn 실행에서도 descriptor 시작의 2바이트와 그 뒤의 4바이트를 읽고,
GDTR/IDTR의 limit·base에 각각 해당 값을 적재한다.
반면 Ghidra listing은 dword operand를 표시하며 raw CALLOTHER는
해당 주소의 4바이트 RAM varnode 값 하나를 입력으로 받는다.

limit 및 base 하위 부분은 고정하고 base 상위 부분만 바꾸는 조건을 포함하여
4개 명령에서 총 72건을 실행했다. 원본의 loaded base·limit과 메모리 read 관찰을 모두 확인했다.
같은 raw userop 입력값에 서로 다른 원본 base 값들이 대응하는 묶음은 24개다.
즉 **표시된 4바이트 값 입력만으로는 관찰된 모든 descriptor 상태를 결정할 수 없다.**

userop의 외부 구현이 추가 문맥이나 메모리를 별도로 읽도록 정의된다면 이를 보완할 수 있다.
이번에는 그런 계약이 이미 구현됐다고 가정하지 않았다.
문제는 userop 표기가 존재한다는 사실만으로 명령 의미가 충분하다고 판단할 수 없다는 점이다.

`state-execution.json`에 little-endian limit 2바이트와 base 4바이트를 보존하는
분석용 descriptor 계약을 기록했다. 원래 유효 주소와 전체 값을 유지해야 한다.
이는 **미통합 제안**이며 Ghidra 언어 정의, 분석 DB 또는 복원 커널에 적용하지 않았다.
descriptor fault·권한·후속 selector 적재·주소 변환·interrupt 전달은 별도 의무로 남겼다.
Unicorn의 read hook은 명령 모형 관찰이지 물리 bus cycle 측정이 아니다.

## 보존·재현 및 남은 범위

최초 추출 순서:

```sh
python3 -B 09_validation/reports/continuous-review-20260911-18/scan.py
python3 -B 09_validation/reports/continuous-review-20260911-18/extract_pcode.py
python3 -B 09_validation/reports/continuous-review-20260911-18/audit_pcode.py
python3 -B 09_validation/reports/continuous-review-20260911-18/state_execution.py
python3 -B 09_validation/reports/continuous-review-20260911-18/verify_artifacts.py
```

추출기는 기존 사본 덮어쓰기를 거부한다. 보존된 추출물 재검사는 audit/state_execution/verify로
수행하며, Ghidra 자체를 재실행하려면 별도 새 사본·출력 경로가 필요하다.

[검증 코드](verify_artifacts.py), [검증 결과](verification.json),
[입력 해시](input-hashes.json), [이번 산출물 해시](artifact-hashes.json).
이전 manifest 전체와 정본·기존 실험 사본·새 CPU-state 사본의 해시를 확인한다.

Ghidra 스킬에 따라 원본, raw/high 해석, 제안 계약, 실행 증거를 분리했다.
주소·크기·offset·mask·계수·해시는 모두 Python으로 계산했다.
원본 바이너리·Ghidra/IDA 정본·과거 보고서·`07_kernel`은 수정하지 않았다.

segment cache 및 selector 검증, LLDT/LTR의 충분한 계약, cache/TLB·MMIO·fault·SMP·비동기
이벤트, 같은 입력의 IDA 대조, GCC 2.7 실컴파일·링크·부팅은 아직 남아 있다.
발견한 표현 부족을 분석 파이프라인에 통합해 원본 효과를 보존하는 일도 미완료다.
따라서 전체 분석 완료로 판정하지 않는다.
