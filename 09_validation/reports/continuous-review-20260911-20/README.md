# 연속 추가검토 — FS base 0의 근거와 비평면 커널 데이터 주소

대상: OPENSTEP 4.2 mk-183.34.4 / x86. 검토일: 2026-09-11.
원본 SHA-256: `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`.
출발점: [FS 재적재 및 반복 복사의 조건부 차이](../continuous-review-20260911-19/README.md).

## 결론

이전 보고서의 “실제 커널 복사 경로에서도 FS base가 비영인가?”라는 미확정 조건을
원본 GDT 초기화와 진입 명령으로 좁혔다.

원본 `_gdt_init`은 FS에 쓰이는 선택자 `0x50`의 base를 0으로 만든다.
명시적 MOV FS 6곳은 모두 AX에 `0x50`을 적재한 뒤 FS를 쓴다.
초기화된 GDT를 사용하는 12개의 원본 적재·읽기 probe에서도 FS base 0을 확인했다.
따라서 이전의 비영 FS 합성 반례를 곧바로 정상 진입 경로의 커널 장애로 해석하면 안 된다.

하지만 **FS base 0만으로 평면 RAM 해석이 충분해지는 것은 아니다.**
같은 GDT의 커널 데이터 선택자 `0x10`은 base `0xc0000000`이다.
원본 초기화 descriptor를 FS/ES에 적재한 반복 복사 24개 조건에서는 source 읽기는 같지만,
ES base를 반영한 원본 선형 destination과 평면 raw 모델의 destination이 달랐다.
이는 분석 주소 공간과 세그먼트 상대 주소의 대응을 명시해야 한다는 증거다.

모든 복사 호출 경로의 FS base 0 불변 조건은 아직 증명되지 않았다.
POP FS의 저장값, GDT alias 쓰기, firmware·비동기 경로와 paging 대응은 남아 있다.
원본 커널의 실제 복사가 잘못됐다고 판정하지 않는다.

## 원본 정적 추적

[검색·추적 코드](gdt_review.py), [참조·호출·FS 설정·원본 문맥](gdt-review.json).

기존 export의 고유 instruction head 286,091개를 원본에서 재디코딩했다.
GDT pointer, 초기 GDT 영역, GDTR operand에 대한 명시적 절대 참조와 지정한 직접 호출을 검색했다.

| 항목 | 결과 |
|---|---:|
| GDT 관련 명시적 참조 명령 | 45 |
| 참조 소유 함수 | 14 |
| GDT pointer 저장소에 대한 명시적 직접 쓰기 | 0 |
| `_gdt_init` 직접 호출 | 1 |
| `_locate_gdt` 직접 호출 | 1 |
| `_copyin` 직접 호출 | 53 |
| `_copyinmsg` 직접 호출 | 2 |
| 상수 선택자를 사용하는 MOV FS | 6 |
| 저장된 선택자를 사용하는 POP FS | 7 |

이미지에 저장된 GDT pointer 값은 `0x001e18b0`이다.
직접 쓰기 0이라는 결과는 alias·indexed·외부 쓰기까지 없다는 뜻이 아니다.
GDT를 참조하는 task/context/BIOS 관련 함수의 원본 문맥도 함께 보존했다.

MOV FS 직전 AX 정의를 원본 명령으로 확인했으며 6곳 모두 `0x50`이다.
이 사실은 당시 GDTR과 descriptor 값이 올바르다는 전제를 대체하지 않는다.
POP FS 7곳은 stack 값의 전체 provenance를 아직 확정하지 않아 미해결로 유지했다.
직접 copy 호출 수는 모든 간접 호출·진입을 포함하는 coverage 수치가 아니다.

## GDT 초기화의 실제 결과

[실행 코드](gdt_execution.py), [descriptor 및 실행 결과](gdt-execution.json).

원본 `_gdt_init` 전체를 합성 호출 스택에서 실행했다.
원래 테이블 주소 및 별도 합성 테이블 주소, 초기 fill 패턴을 바꾼 6개 조건을 검사했다.
원본이 descriptor를 조립하고 LGDT를 수행하는 것까지 실행했다.

| 선택자 | 용도 | base | 유효 limit |
|---|---|---|---|
| `0x08` | 커널 code | `0xc0000000` | `0x3fffffff` |
| `0x10` | 커널 data | `0xc0000000` | `0x3fffffff` |
| `0x48` | 선형 code | `0` | `0xbfffffff` |
| `0x50` | 선형 data / FS 적재값 | `0` | `0xbfffffff` |
| `0x60` | 사용자 대체 code | `0` | `0xbfffffff` |
| `0x68` | 사용자 대체 data | `0` | `0xbfffffff` |

descriptor의 base 조각·limit·granularity는 Python으로 디코딩했다.
GDTR, callee-saved register, 호출 stack 복원, 실행한 원본 바이트도 확인했다.
임의 fill 조건은 초기화 필드의 결정성을 검사한 것이며 예약 bit까지 유효하다는 검사가 아니다.
후속 FS 적재 probe는 초기 fill 0의 정상 descriptor 조건만 사용했다.

로컬 Darwin `machdep/i386/gdt.c`도 KCS/KDS와 LCODE/LDATA의 초기화 구분을 뒷받침한다.
그 참고 소스가 원본 OPENSTEP 바이너리와 동일하다고 가정하지 않고, 수치는 원본 실행에서 얻었다.

### 명시적 진입 FS 적재

초기화된 두 테이블에 대해 원본 MOV FS 6곳을 각각 실행한 12개 probe에서,
FS selector `0x50`과 원본 FS 읽기의 base 0 주소를 확인했다.
진입 함수 전체, 실제 call gate, interrupt frame 또는 paging 전환을 실행한 것은 아니다.
따라서 이는 정상 초기화 상태에서의 명시적 적재 지점에 관한 증거로 제한한다.

## GDTR의 후속 재설정

`_start`의 `001860e7`은 `_gdt_init`을 직접 호출한다.
`_i386_init`의 `0018ab84`부터는 저장된 GDT pointer를 읽고 `0xc0000000`을 더한 뒤,
`0018ab8f`에서 `_locate_gdt`를 호출한다.

이 실제 호출 구간과 callee를 6개 테이블·fill 조건에서 실행했다.
GDTR base는 가산된 값으로 바뀌고 GDT pointer 저장소의 값은 그대로였다.
이는 table pointer 자체를 임의의 새 descriptor로 바꾸는 단순 대입과 다르다.
다만 해당 선형 주소가 원래 테이블의 어느 physical page로 이어지는지는
실제 page table을 따라가야 하므로 이번 시험으로 그 대응까지 확정하지 않았다.

## FS base 0이어도 남는 ES 주소 문제

이전 보고서의 flat-base 대조군은 FS와 destination의 ES를 flat으로 둔 조건이었다.
이번에는 **원본 `_gdt_init`이 실제 만든 descriptor**에서 FS=`0x50`, ES=`0x10`을 적재했다.
원본의 FS-prefixed REP MOVS 6곳에 반복 수 1/3과 DF의 두 방향을 적용했다.

총 24개 조건에서 source 읽기는 원본과 raw 모델이 같았다.
반면 원본 destination은 ES base와 EDI를 결합한 선형 주소이며,
raw 모델은 EDI를 그대로 RAM 주소로 사용한다.
원본은 높은 선형 주소의 destination을 갱신하고 낮은 주소를 그대로 두었지만,
동일 RAM을 평면으로 해석한 raw 모델은 낮은 주소를 갱신했다.
원본 instruction bytes와 source/destination 메모리 효과를 모두 확인했다.

이 비교에는 중요한 해석 조건이 있다.

- Unicorn의 paging은 끈 상태이며 관찰 주소는 합성 선형 메모리다.
- raw RAM을 같은 선형 주소 공간으로 직접 대응시킨 모형이다.
- 실제 커널 page table, Ghidra의 별도 주소 변환 adapter, GCC/NeXT의 segment 기반 C 포인터
  관례가 추가 문맥을 제공할 가능성을 배제하지 않는다.
- full boot·privilege 전환·fault·SMP·interrupt 또는 실제 컴파일된 C를 검사한 결과가 아니다.

따라서 “원본 kernel memcpy가 틀렸다”가 아니라,
“FS base가 0이라는 사실만으로 모든 세그먼트 효과를 지워도 된다고 판단할 수 없다”가 결론이다.
user source와 kernel destination의 주소 해석을 각각 보존하는 분석 계약이 필요하다.

## 아직 증명되지 않은 사항

남은 우선 검토는 다음과 같다.

- GDT indexed/alias 쓰기가 LDATA descriptor를 바꾸는지와 그 경로 조건.
- POP FS 7곳의 입력 provenance 및 복사 함수로 이어지는 실제 호출 경로.
- firmware·task switch·비동기 진입에서의 선택자와 cached state.
- GDTR의 높은 선형 주소와 실제 page table 대응.
- Ghidra RAM 주소와 세그먼트 상대 주소를 잇는 일관된 분석 모형.

이전 보고서의 비영 FS 합성 반례는 유지하되 실제 경로 적용 조건을 더 좁혔다.
완전한 복사 경로의 FS base 0 불변 조건이나 전체 평면 RAM 동등성은 승인하지 않았다.

## 재현과 보존

```sh
python3 -B 09_validation/reports/continuous-review-20260911-20/gdt_review.py
python3 -B 09_validation/reports/continuous-review-20260911-20/gdt_execution.py
python3 -B 09_validation/reports/continuous-review-20260911-20/verify_artifacts.py
```

[검증 코드](verify_artifacts.py), [검증 결과](verification.json),
[입력 해시](input-hashes.json), [산출물 해시](artifact-hashes.json).
이전 manifest와 정본 및 기존 실험 사본의 해시를 재확인한다.

Ghidra 스킬에 따라 원본 명령, 기존 raw/high 해석, 합성 실행과 경로 불변 조건을 구분했다.
이번에는 새 Ghidra 사본을 만들거나 재디컴파일하지 않았다.
주소·크기·offset·mask·집계·해시는 모두 Python으로 계산했다.
원본 바이너리·Ghidra/IDA 정본·기존 보고서·`07_kernel`은 변경하지 않았다.
분석 모형 보완, 동일 입력 IDA 대조, GCC 2.7 실컴파일·링크·부팅까지 전체 완료는 아직 아니다.
