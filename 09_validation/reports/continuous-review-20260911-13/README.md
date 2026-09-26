# 연속 추가검토 — 보호 데이터의 volatile 확대 적용과 접근 수 불일치

대상: OPENSTEP 4.2 mk-183.34.4 / x86. 검토일: 2026-09-11.
원본 SHA-256: `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`.
출발점: [lock만 volatile로 지정했을 때 남은 읽기 순서 문제](../continuous-review-20260911-12/README.md).

## 결론: 일괄 확대 설정은 원본에 충실한 모델로 채택하지 않음

관련 전역 데이터까지 volatile로 지정하면 `_mfs_cache_trim`의 queue snapshot이
lock 획득 뒤 원본 읽기 위치로 돌아온다. lock 설정도 함께 적용하면 획득 재시도도 보존된다.
그러나 counter의 INC/DEC에서 원본 명령 모델보다 volatile 읽기가 늘어나는 역효과가 있다.

선택 영역의 INC 26곳·DEC 14곳에서 읽기가 각각 1개가 아니라 5개로 표현된다.
추가된 읽기는 총 160개다. 따라서 C가 읽기 쉬워지거나 최종 값이 맞는 것만으로
이 확대 설정을 올바른 복원 모델로 판정할 수 없다.

원본 명령과 high P-code의 메모리 효과 부분을 480개 조건에서 비교했다.
최종 값은 모두 같았지만 접근 trace는 모두 달랐다.
`audit.json`과 `rmw-execution.json`에는 이 충실도 판정을 **false**로 기록했다.
검토 스크립트가 정상 종료한 것과 실험한 모델이 원본 검증을 통과한 것은 다른 판정이다.

## 실험 범위

[입력과 원본 참조 목록](job.json), [실행기](run_experiment.py),
[Ghidra 스크립트](ProtectedDataExperiment.java), [실행 결과](run-result.json).

이전 보고서의 lock 데이터 4개를 한 그룹으로 유지했다.
추가 그룹은 `_mfs_cache_trim` 원본에서 직접 접근하는 나머지 전역 데이터 5개다.

| 주소 | 역할 |
|---|---|
| `001f64d0` | queue head의 앞 포인터 |
| `001f64d4` | queue head의 뒤 포인터 |
| `001def50` | `_vm_info_version` |
| `001def64` | `_mfs_files_mapped` |
| `001def60` | `_mfs_files_max` |

이 그룹은 실험을 위해 원본의 직접 operand로 정한 관련 데이터다.
모든 접근이 같은 lock으로 보호된다거나 실제 소스 선언이 volatile이었다는 뜻은 아니다.

현재 export된 명령 286,091개를 원본에서 다시 디코딩해 직접 operand/immediate 참조를 찾았다.
참조 237개는 값 읽기·쓰기뿐 아니라 주소 상수도 포함하므로 메모리 접근 횟수로 세지 않았다.
직접 참조 함수 20개와 대조군을 합쳐 25개 함수를 디컴파일했다.
모든 동적 alias 또는 미발견 코드까지 포괄하는 조사라는 뜻은 아니다.

## 독립 단계 비교

모든 단계는 별도 JVM·설정·cache에서 같은 복제 DB를 새로 열어 실행했다.

| 단계 | 변경 데이터 수 | C 출력 변경 함수 수 | queue 읽기 위치 | 획득 재시도 |
|---|---:|---:|---|---|
| baseline | 0 | 0 | 앞당겨진 snapshot 남음 | 누락 상태 재현 |
| lock_only | 4 | 16 | 앞당겨진 snapshot 남음 | 복구 |
| data_only | 5 | 16 | 원본 위치 복구 | 누락 상태 재현 |
| combined | 9 | 19 | 원본 위치 복구 | 복구 |
| reopened_baseline | 0 | 0 | 첫 baseline과 같음 | 첫 baseline과 같음 |

queue 위치·재시도 비교는 `_mfs_cache_trim`의 첫 획득 경로를 대상으로 한다.
combined에서 queue read `0015ec54`의 block은
획득 재시도 분기를 벗어나는 성공 경로의 block에 의해 지배된다.
즉 해당 high P-code CFG에서 그 queue read에 도달하려면 성공 경로를 먼저 거쳐야 한다.
이 결과를 전체 커널의 memory barrier 보존으로 확대 해석하지 않는다.

비교기는 단순히 C 문자열 위치만 보지 않았다.
block의 실제 incoming/outgoing edge를 추출해 지배 관계를 Python으로 계산했다.
초기 비교기 초안이 선행 COPY의 주소를 고정값으로 가정해 실패했는데,
baseline과 lock_only의 COPY 주소가 다름을 확인하고 CFG·operation 순서 비교로 보완했다.
기초 실험의 export와 실행 결과는 재작성하지 않았다.

전체 함수 레코드 5,253개, defined data 23,013개를 비교했고
지정한 volatile/mutability 외의 데이터·함수 메타데이터는 그대로다.
전체 listing, references, 초기화 메모리도 동일하며
원본 파일 1,117,920바이트를 다시 대조했다.
이전 보고서에서 선택한 23개 함수의 baseline/lock-only C도 그대로 재현됐다.

## 접근 효과 검증에서 드러난 역효과

[검증 코드](audit_experiment.py), [상세 판정](audit.json), [C 차이](decompiler-diffs.patch).

표의 수치는 각 단계에서 volatile로 활성화한 데이터 그룹만 대상으로 한다.
baseline은 활성 그룹이 비어 있으므로 그 비교가 같다고 나와도 전체 분석 통과를 의미하지 않는다.

| 단계 | 원본 기준 읽기 | 출력의 volatile 읽기 | 원본 기준 쓰기 | 출력의 volatile 쓰기 | 해당 그룹 접근 충실도 |
|---|---:|---:|---:|---:|---|
| lock_only | 77 | 77 | 54 | 54 | 일치 |
| data_only | 69 | 229 | 82 | 82 | 불일치 |
| combined | 146 | 306 | 136 | 136 | 불일치 |

관련 데이터의 counter INC/DEC 40곳이 추가 읽기를 만든다.
이 현상은 기존 lock 설정이 복구한 XCHG 접근과 구분해야 한다.
쓰기 누락을 숨기거나 추가 읽기를 무시하여 통과 처리하지 않았다.

## 왜 INC/DEC에서 읽기가 늘어나는가

[로컬 원본·도구 소스 근거](source-evidence.json), [추출 코드](source_evidence.py).

설치된 x86 SLEIGH의 메모리 INC/DEC 정의는 같은 메모리 operand를
overflow 계산, 값 계산 및 result flags 계산에서 반복 참조한다.
정본 raw P-code의 예제 `0015ec81`/`0015ec87`에서도
동일 RAM varnode가 입력으로 각각 5번 사용된다.

일반 비volatile 분석에서는 일부 중간 flags 계산이나 불필요한 값을 제거할 수 있다.
해당 데이터가 volatile이면 Ghidra의 `replaceVolatile`이 이를 별도 읽기 효과로 표현하며,
불필요한 읽기도 제거되지 않은 채 남을 수 있다.
실제 combined 출력에는 다음과 같은 효과 순서가 나타난다.

```text
read → read → write → read → read → read
```

이는 현재 도구의 instruction 의미 확장과 volatile 처리의 상호작용에 대한 근거다.
원본 x86이 물리 버스에서 반드시 어떤 횟수로 접근한다는 주장,
옛 커널 소스 자체의 오류 또는 특정 GCC의 컴파일 오류로 단정하지 않았다.
설치된 Ghidra 소스나 SLEIGH 정의도 수정하지 않았다.

## 원본 단일 명령 실행과 메모리 효과 부분의 비교

[Python 시험](rmw_execution.py), [전체 조건·trace](rmw-execution.json).

40곳 각각에서 경계값을 포함한 입력값과 carry 입력을 바꾸어 총 480개 조건을 실행했다.
원본의 INC/DEC 한 명령만 실행하고 그 명령의 메모리 hook을 기록했다.
Unicorn 명령 모델에서는 읽기 1개와 쓰기 1개가 관찰됐다.
이는 물리 버스 측정이 아니라 에뮬레이터의 명령 수준 관찰이다.

원본 결과와 CF/PF/AF/ZF/SF/OF를 Python의 명시적 계산과 대조했다.
별도로 high P-code에서 volatile 읽기·쓰기 및 그 값의 의존 연산만 추려 실행했다.
선택 영역 밖에서 쓰이는 독립 COPY는 메모리 효과의 의존성이 아님을 확인해 제외했다.
IR 전체의 flags나 전체 디컴파일 함수를 실행했다고 주장하지 않는다.

안정된 메모리 값에서는 불필요한 읽기가 있어도 최종 값은 같았다.
그러나 원본 측 접근과 high P-code 효과 trace는 480개 조건 모두 달랐다.
따라서 값 비교만으로 역어셈블·디컴파일의 메모리 접근 의미를 검증할 수 없다.

## 남은 분석과 채택 원칙

- lock 접근 복구, 보호 데이터 순서 복구, RMW 접근 횟수 보존은 각각 별도 조건이다.
- 관련 전역 데이터 전체에 volatile을 일괄 적용하는 방법은 이번 형태로 채택하지 않는다.
- 포인터의 단순 읽기/쓰기와 counter RMW를 구분한 모델을 검토해야 한다.
- RMW의 내부 값·flags 계산을 temporary로 보존하는 의미 정규화와 실제 접근 효과를 구분해야 한다.
- 포인터가 가리키는 구조체 필드, 동적 alias, 다른 연산 및 실제 동시 실행은 아직 미검증이다.
- GCC 2.7 재컴파일 결과와 실제 커널 실행을 대신하는 검증은 아니다.

Ghidra 스킬에 따라 원본·raw/high P-code·데이터 설정·관련 도구 소스를 단계별로 대조했다.
긍정적 효과와 접근 충실도 실패를 함께 남겼으며, 실패한 설정을 정본에 반영하지 않았다.
원본 바이너리·정본 DB·기존 보고서·`07_kernel`은 변경하지 않았다.
모든 계산·주소 변환·집계·해시·실행 비교는 Python으로 수행했다.

## 무결성과 재현

[입력 해시](input-hashes.json), [프로젝트 사전 해시](source-project-before.json),
[검증 코드](verify_artifacts.py), [무결성 검증 결과](verification.json),
[이번 산출물 해시](artifact-hashes.json).

무결성 검사 통과는 위에 기록한 모델 충실도 실패를 취소하지 않는다.
이전 manifest는 원래 해시로 확인하며 재생성하지 않는다.
이번 runtime/cache는 manifest에서 제외한다.
실험 실행기는 기존 snapshot 덮어쓰기를 거부하므로 재실행은 별도 새 경로에서 진행해야 한다.
