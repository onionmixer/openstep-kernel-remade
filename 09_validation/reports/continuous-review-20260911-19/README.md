# 연속 추가검토 — FS 재적재와 반복 복사의 세그먼트 효과

대상: OPENSTEP 4.2 mk-183.34.4 / x86. 검토일: 2026-09-11.
원본 SHA-256: `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`.
출발점: [CPU 상태·descriptor 표현 검토](../continuous-review-20260911-18/README.md).

## 결론

서로 다른 두 종류의 세그먼트 표현 부족을 확인했다.

첫째, FS/GS 선택자 쓰기는 raw P-code에 선택자 갱신만 있으며 숨겨진 base 갱신이나
이를 수행하는 userop이 없다. 실제 원본 FS 적재 명령 13곳을 이용한 단계별 실행에서는,
GDT의 base를 바꾸고 **같은 선택자를 다시 적재할 때** 실제 읽기 주소가 새 base를 따른다.
raw 모델은 이전 FS_OFFSET을 유지하여 78개 단계별 사례의 마지막 읽기가 달라졌다.

둘째, `_copyin`, `_copyinmsg`의 FS-prefixed REP MOVS 6곳은 raw P-code가
FS_OFFSET을 입력으로 사용하지 않는다. 반복 수가 양수이고 FS base가 0이 아닌 36개
검사 조건에서는 FS_OFFSET을 올바르게 초기화했어도 복사 데이터가 달랐다.
FS base가 0인 양수 반복 대조군 36개는 일치했다.

**이것만으로 원본 커널의 실제 복사 경로가 잘못됐다고 판정하지 않는다.**
원본의 진입·GDT 설정이 해당 복사 경로에서 항상 FS base 0을 보장하는지는 별도 검토가 필요하다.
이번 결과는 분석 모형이 정확하려면 어떤 상태 전제나 보완 계약이 필요한지 보여 준다.

## 전수 검색과 읽기 전용 재추출

[검색 코드](scan.py), [원본 인벤토리](scan.json), [추출 실행기](extract_pcode.py),
[명령](command.json), [실행 결과](run-result.json), [raw/high 자료](exports/pcode.json).

기존 함수 단위 5,253개, 고유 instruction head 286,091개를 원본에서 다시 디코딩했다.
명시적 FS/GS register 및 memory operand를 가진 명령은 144곳, 소유 함수는 42개다.
새 `segment-state-review-20260911` 사본을 독립 JVM에서 `-readOnly -noanalysis`로 열었다.
기존 추출 driver와 API 전용 Java exporter를 수정 없이 재사용했다.
42개 함수의 새 C는 provenance header를 제외하면 정본과 모두 일치한다.

| 항목 | 수 |
|---|---:|
| FS 선택자 쓰기 | 13 |
| GS 선택자 쓰기 | 13 |
| 각 선택자의 MOV | 6 |
| 각 선택자의 POP | 7 |
| FS/GS memory override 지점 | 106 |
| raw에서 숨겨진 base를 참조하는 memory 지점 | 100 |

선택자 쓰기와 memory 지점은 검색 분류이며 모든 암묵적 segment 효과를 포함하지 않는다.
CS/SS/DS/ES 전체, far return, LDT 전환의 완전한 검증은 이번 범위가 아니다.

## 선택자와 숨겨진 base의 연결 부족

[대조 코드](audit_pcode.py), [주소별 결과·언어 정의 근거](pcode-audit.json).

설치된 Ghidra 언어 정의와 실제 program varnode를 대조했다.
MOV FS/GS는 AX 등을 선택자 register에 복사한다.
POP FS/GS는 stack에서 선택자를 읽고 ESP를 갱신한다.
이 26곳의 raw 연산에는 FS_OFFSET/GS_OFFSET 쓰기나 세그먼트 적재 효과 userop이 없다.
같은 원래 주소의 high P-code에는 선택자·숨겨진 base 쓰기가 모두 없다.

반면 단순 FS 메모리 접근은 별도의 FS_OFFSET을 더한다.
실행에 사용한 `0018a197`은 원본 `MOV EDX,FS:[EAX]`이며,
raw는 FS_OFFSET+EAX를 계산한 뒤 그 주소에서 읽는다.
선택자 변경과 이 주소 계산 사이를 연결하는 숨겨진 상태 관리가 별도로 필요하다.

## 단계별 FS 재적재 시험

[실행 코드](segment_execution.py), [모든 단계·주소·값·메모리 효과](segment-execution.json).

원본 FS 적재 13곳 모두를 사용했다. 테스트는 원본 명령 조각을 합성 순서로 실행한다.
각 적재 지점에서 `_fuword` 계열 접근 지점까지 원본 CFG가 직접 연결된다고 주장하지 않는다.

합성 GDT의 유효한 writable data descriptor와 32비트 flat stack descriptor를 구성했다.
descriptor 형식은 로컬 OPENSTEP SDK의 `architecture/i386/desc.h`, `sel.h`를 확인했고,
Darwin 참고 코드의 descriptor 조립 방식도 검토했다. 원본 헤더를 수정하거나
호스트 C bitfield 배치가 GCC 2.7의 배치와 같다고 가정하지 않고 Python으로 바이트를 조립했다.

각 사례는 다음 단계를 따른다.

1. 선택자를 적재해 base A를 사용하고 원본 FS 읽기와 raw 읽기를 비교한다.
2. GDT 메모리의 descriptor를 base B로 바꾸되 FS를 다시 적재하지 않고 읽는다.
3. 같은 선택자를 원본 MOV/POP FS로 다시 적재하고 읽는다.

raw FS_OFFSET은 처음부터 정확한 base A로 초기화했다.
원본은 첫 두 단계에서 A, 마지막 단계에서 B를 읽는다.
raw는 선택자만 다시 갱신하므로 마지막 단계에도 A를 읽는다.
base 쌍과 offset을 바꾼 78개 단계별 사례에서 234개의 읽기를 비교했고,
불일치는 마지막 단계의 78개에만 있었다. 실행한 원본 명령 방문 수는 390이다.

실제 FS selector 값, POP의 stack 이동, 읽기 주소·값 및 원본 instruction bytes도 확인했다.
Unicorn에서 descriptor의 accessed bit가 설정되는 효과도 관찰·기록했다.
단, 실제 하드웨어 bus transaction이나 모든 권한·limit·fault 동작을 입증한 것은 아니다.

추가 관찰로, POP FS의 stack read hook은 4바이트를 읽으며 raw LOAD의 출력 폭은 2바이트다.
이번 정상 적재 조건에서는 선택자 값과 ESP 이동이 일치하지만 접근 폭의 동일성까지
통과시킨 것은 아니다. page 경계 fault 및 실제 CPU의 접근 방식은 별도 검토가 필요하다.

### 합성 실행 환경 점검

탐색 실행에서는 명령 종료 주소와 stack descriptor 설정을 보완했다.
최종 실행기는 종료 주소를 원본 명령의 디코딩 길이로 계산한다.
또한 FS 적재 후 POP이 기본 SS 상태의 영향을 받지 않도록 32비트 flat SS를 명시적으로 적재했다.
불완전한 합성 환경에서 발생한 미매핑 접근을 커널 또는 Ghidra 오류로 계산하지 않았다.
보완 후 MOV/POP FS의 모든 대상에 같은 fixture와 검사 조건을 적용했다.

## FS-prefixed REP MOVS의 별도 누락

[REP 원본·raw 실행기](repeat_execution.py), [조건별 결과](repeat-execution.json).

| 함수 | byte 반복 복사 | dword 반복 복사 |
|---|---|---|
| `_copyin` | `00189a7e`, `00189a9f` | `00189ab7` |
| `_copyinmsg` | `00189b65`, `00189b87` | `00189b9f` |

원본은 FS source override를 가진다. 추출된 raw 반복 연산은 ESI의 주소를 직접 읽으며
FS 선택자나 FS_OFFSET을 읽지 않는다. ES destination은 이번 실험에서 flat으로 고정했다.

raw COPY/LOAD/STORE/산술/조건 분기/반복 분기를 해석하는 제한된 Python 실행기를 사용했다.
반복 수 0/1/3/8, DF의 두 방향, FS base 0 또는 비영 값을 조합한 96개 조건을 비교했다.
source의 flat 주소와 FS 기반 주소에 서로 다른 데이터를 배치했다.

| 조건 | 검사 수 | 결과 |
|---|---:|---|
| FS base 비영·양수 반복 | 36 | 원본과 raw의 source 주소·복사 데이터가 다름 |
| FS base 0·양수 반복 | 36 | 대조군의 복사 데이터 일치 |
| 반복 수 0 | 24 | 메모리 복사 없이 종료 |

raw FS_OFFSET은 각 조건의 올바른 base로 초기화했다.
따라서 이 차이는 앞선 선택자 재적재 시 숨겨진 base가 갱신되지 않는 문제와 별개다.
ECX 종료값, ESI/EDI 진행 방향·폭, destination 주소와 데이터도 함께 검사했다.

이번에는 REP 중 fault restart, 겹치는 버퍼, concurrent update, 전체 copy 함수 경로를
시험하지 않았다. 앞선 copy fault 검증을 대체하거나 취소하는 결과도 아니다.
원본 진입 상태의 FS base 불변 조건을 확인하기 전에는 실제 커널 복사 장애로 확대 해석하지 않는다.

## 필요한 분석 계약과 미완료 사항

분석용 제안은 `segment-execution.json`에 미통합 상태로 기록했다.
선택자와 cached base/limit/access 속성을 구분해야 하며, 같은 선택자의 재적재도
descriptor를 다시 반영해야 한다. descriptor 메모리 수정만으로 cached base가 바뀐다고
모형화해서도 안 된다. 반복 복사 source override의 의미도 별도 보존이 필요하다.

GS는 이번에 인벤토리·raw/high 대조만 했고 실제 접근 시험은 FS에 한정했다.
null selector, LDT selector, invalid/not-present descriptor, CPL 전환·protection fault,
비동기 interrupt·SMP 조건과 LLDT/LTR 계약은 아직 남아 있다.

## 재현과 보존

최초 추출 순서:

```sh
python3 -B 09_validation/reports/continuous-review-20260911-19/scan.py
python3 -B 09_validation/reports/continuous-review-20260911-19/extract_pcode.py
python3 -B 09_validation/reports/continuous-review-20260911-19/audit_pcode.py
python3 -B 09_validation/reports/continuous-review-20260911-19/segment_execution.py
python3 -B 09_validation/reports/continuous-review-20260911-19/repeat_execution.py
python3 -B 09_validation/reports/continuous-review-20260911-19/verify_artifacts.py
```

추출기는 기존 사본 덮어쓰기를 거부한다. 보존된 raw/high 자료의 재검사는
audit/segment_execution/repeat_execution/verify로 수행한다.

[검증 코드](verify_artifacts.py), [검증 결과](verification.json),
[입력 해시](input-hashes.json), [산출물 해시](artifact-hashes.json).
이전 보고서 manifest와 정본·기존 실험 사본·새 사본을 대조한다.

Ghidra 스킬에 따라 원본 사실, raw/high 해석, 합성 실행과 미통합 제안을 분리했다.
주소·크기·offset·bit·집계·해시 계산은 모두 Python이다.
원본 바이너리·Ghidra/IDA 정본·기존 보고서·`07_kernel`은 변경하지 않았다.
분석 파이프라인 보완 및 GCC 2.7 실컴파일·링크·부팅을 포함한 전체 완료 판정은 아직 내리지 않는다.
