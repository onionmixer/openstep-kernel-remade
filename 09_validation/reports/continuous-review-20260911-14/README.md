# 연속 추가검토 — 전체 INC/DEC의 단일 읽기 계약과 flags

대상: OPENSTEP 4.2 mk-183.34.4 / x86. 검토일: 2026-09-11.
원본 SHA-256: `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`.
출발점: [volatile 확대 적용에서 드러난 중복 읽기](../continuous-review-20260911-13/README.md).

## 결론

원본의 INC/DEC를 한 번 읽은 값과 계산한 새 값으로 표현하는 Python 분석 계약을 만들고,
현재 export에서 발견된 해당 명령 4,140곳을 모두 직접 실행하여 비교했다.
경계값·flags 입력을 바꾼 115,920개 조건에서 값, flags, 레지스터 보존 및
메모리 접근 효과가 일치했다. 8비트 명령은 모든 byte 값에 대한 추가 검사도 수행했다.

이는 **제안한 분석 계약의 검증**이다. Ghidra에 이 계약을 적용한 것이 아니며,
기존 decompiler 출력의 중복 읽기 문제가 해결됐다고 판정하지 않는다.
`normalized-contract.json`은 적용 전 분석용 보조 자료로 명시했다.

추가로, 기존 Ghidra raw P-code 예제는 AF를 갱신하지 않는다는 차이를 확인했다.
안정된 메모리 조건의 예제 비교 56개 중 28개에서 AF가 달랐고 나머지 비교 flags는 같았다.
실제 커널 경로의 잘못된 동작이나 하드웨어 장애로 단정하지 않았다.

## 전수 인벤토리

[원본 재디코딩 코드](scan.py), [명령별 인벤토리](scan.json).

현재 함수 export 5,253개 단위의 고유 instruction head 286,091개를 다시 디코딩했다.
그 안의 모든 INC/DEC를 register/memory, 폭, LOCK prefix 및 주소 방식으로 분류했다.

| 분류 | 지점 수 |
|---|---:|
| 전체 INC/DEC | 4,140 |
| 레지스터 operand | 2,095 |
| 메모리 operand | 2,045 |
| INC | 2,886 |
| DEC | 1,254 |
| 32비트 | 3,692 |
| 16비트 | 406 |
| 8비트 | 42 |
| 명시적 LOCK prefix | 442 |

이전 보고서의 counter RMW 40곳도 이번 집합에 모두 포함된다.
주소 크기는 발견된 명령 모두 32비트이며, 메모리 형태에는 명시적 segment override가 없었다.
미발견 코드, 다른 아키텍처 또는 INC/DEC 외의 RMW까지 포함하는 수치는 아니다.

## 제안한 단일 읽기 계약

[Python 모형·원본 비교기](normalized_execution.py),
[주소별 분석 계약](normalized-contract.json), [계약 생성 코드](contract.py).

계약의 순서는 다음과 같다.

1. operand의 이전 값을 한 번 읽어 임시값 `old`로 보관한다.
2. 해당 폭에서 증가/감소 및 wrap을 계산하여 `new`를 만든다.
3. 결과 flags는 `old`, `new`, 보존해야 하는 입력 flags에서만 계산한다.
4. 메모리 형태는 새 값을 한 번 기록한다. 레지스터 형태는 같은 폭만 갱신한다.

CF는 유지하고 PF/AF/ZF/SF/OF를 계산한다.
8·16비트 레지스터 갱신은 상위 부분을 보존하며, 다른 일반 레지스터도 보존해야 한다.
실행기에서 EFLAGS 전체 비교와 일반 레지스터 비교를 수행했다.

메모리 값을 flags 계산 때마다 다시 읽는 모형은 사용하지 않았다.
LOCK prefix가 있는 명령은 계약에 그 의미를 유지해야 한다고 기록했다.
다만 단일 실행 시험으로 실제 경쟁 환경의 원자성을 입증한 것은 아니다.
이 계약을 일반 C의 분리된 load/store로 번역해도 된다는 뜻도 아니다.

## 원본 명령 실행 검증

[전체 결과](normalized-execution.json).

모든 지점에서 원본 instruction bytes를 그대로 실행했다.
operand는 합성 메모리·레지스터에 배치하고, 입력값과 carry/상태 flags를 바꿨다.
매 시험에서 다음을 확인했다.

- 원본 명령 한 개만 실행하고 그 다음 주소에서 중단하는지.
- 실행한 instruction bytes가 원본과 같은지.
- 새 값과 EFLAGS가 Python 모형과 일치하는지.
- 메모리 형태는 읽기·쓰기 효과가 각각 한 번인지.
- 레지스터 형태는 데이터 메모리 접근이 없고, 부분 레지스터의 상위 비트를 보존하는지.
- 나머지 일반 레지스터가 보존되는지.

총 115,920개 조건에서 불일치는 없었다.
메모리 hook은 Unicorn의 명령 수준 관찰이다. 실제 물리 bus access 횟수 측정이 아니다.
정상 완료 경로만 시험했으며 page fault restart, SMP 경쟁, interrupt 및 whole-function 동작은
이 시험에 포함하지 않았다.

### 8비트 전체 값 추가 검사

[추가 검사 코드](exhaustive_byte.py), [추가 결과](exhaustive-byte.json).

8비트 명령 42곳 각각에 모든 256개 byte 값을 넣고 동일한 flags 입력 패턴들을 검사했다.
이것은 byte 값 공간에 대한 추가 검사이며, 모든 가능한 CPU 상태나 실행 환경의 전수 검증은 아니다.
16·32비트는 경계값 중심 검사로 구분한다.

## 별도로 확인한 AF 차이

[raw P-code 비교 코드](flags_review.py), [상세 결과와 예제](flags-review.json),
[앞선 SLEIGH·flags 소스 근거](../continuous-review-20260911-13/source-evidence.json).

`_mfs_cache_trim`의 `0015ec81` DEC와 `0015ec87` INC에 대해
정본에서 추출한 raw P-code를 안정된 메모리 모형으로 실행했다.
언어 정의에서 flag register 주소를 Python으로 해석해 CF/PF/AF/ZF/SF/OF를 대응시켰다.
해당 예제 P-code에는 AF를 쓰는 연산이 없으며, 입력 AF가 그대로 남는다.

입력값·CF·AF를 바꾼 56개 비교 조건 중 28개에서 AF만 달랐다.
이 비교의 상대는 앞에서 원본 명령 실행과 대조한 단일 읽기 계약이다.
모든 Ghidra INC/DEC 폭과 operand 형태의 raw P-code를 추출해 같은 검사를 했다는 뜻은 아니다.

flags를 값으로 꺼내거나 사용하는 특정 명령도 별도로 인벤토리화했다.
검색한 PUSHF 계열/LAHF/DAA/DAS/AAA/AAS 중 현재 export에서 발견된 항목은 PUSHFD 22곳이다.
이 목록은 AF 값이 그 지점까지 도달한다는 dataflow 증명이 아니다.
예외·interrupt가 저장하는 flags, 함수 경계 및 다른 명령의 정의를 포함한 영향 분석은 남아 있다.
따라서 AF 차이가 실제 커널에 영향을 주지 않는다고도, 이미 장애를 일으킨다고도 단정하지 않았다.

## 무엇이 해결됐고 무엇이 남았는가

확인된 것은 현재 발견된 INC/DEC 전체에 대해 정상 완료 조건에서
중복 읽기 없는 값·flags·접근 계약이 원본 실행과 대응한다는 점이다.
실험적 일괄 volatile 설정 대신 필요한 분석 의미를 분리해 표현할 근거가 생겼다.

아직 남은 사항:

- 이 계약을 분석 파이프라인에 통합해 원본 주소·제어흐름·flags·접근 수가 유지되는지 검증.
- Ghidra의 기존 raw/high P-code 및 C 출력에서 확인된 차이의 처리.
- 다른 RMW 명령, 동적 alias, fault restart, LOCK 원자성 및 보호 데이터 순서.
- AF 차이의 실제 reaching-definitions/소비 경로 분석.
- GCC 2.7 실제 코드 생성·커널 링크·부팅 검증.

Ghidra 스킬에 따라 정본의 명령과 raw P-code 근거를 확인했으며,
도구 표현과 제안 모형·실행 증거를 분리해 보존했다.
Ghidra 언어 정의·정본 DB·원본 바이너리·`07_kernel`은 수정하지 않았다.
이번에는 새 Ghidra 프로젝트를 만들지 않았으며 기존 보존본의 해시만 재검증했다.
모든 계산·개수·주소/폭 변환·flags 처리·해시는 Python으로 수행했다.

## 무결성과 재현

[입력 해시](input-hashes.json), [기존 프로젝트 기준 해시](source-project-before.json),
[검증 코드](verify_artifacts.py), [무결성 결과](verification.json),
[이번 산출물 해시](artifact-hashes.json).

이전 manifest는 수정하지 않고 원래 해시로 확인한다.
단일 읽기 모형의 시험 결과와 기존 Ghidra AF 모델의 불일치 판정은 서로 별개다.
무결성 검사 또는 일부 모형 검사 통과를 전체 분석 완료로 보지 않는다.
