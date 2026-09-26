# 연속 추가검토 — 전역 lock의 volatile 분석 모델 검증

대상: OPENSTEP 4.2 mk-183.34.4 / x86. 검토일: 2026-09-11.
원본 SHA-256: `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`.
출발점: [이전 lock 대기·재시도 검토](../continuous-review-20260911-11/README.md).

## 결론

복제 Ghidra DB에서 전역 lock 데이터 4개의 mutability만 volatile로 바꾸면,
원본에 있지만 기존 최적화 결과에서 사라졌던 획득 재시도 25곳과 대기 분기 3곳이 복구된다.
선택한 lock의 원본 접근 79곳에 대응하는 읽기 77개·쓰기 54개를
원본 주소와 효과별로 정확히 대조했고, XCHG 52곳의 읽기/쓰기 순서도 확인했다.

이 설정은 원본의 단일 읽기 대기를 반복 메모리 읽기로 바꾸지 않는다.
읽기가 loop 밖에 있었던 경우에는 밖에, 메모리를 매번 읽던 경우에는 안에 남는다.
즉 바이너리를 수정하지 않고 분석 과정에서 누락된 lock 접근을 복구하는 효과다.

그러나 **lock만 volatile로 지정하는 것으로 전체 동시성 의미가 복원되지는 않는다.**
`_mfs_cache_trim`에서는 보호 대상 queue 포인터의 snapshot이 lock 획득 앞에 놓이는
표현이 여전히 남는다. 이 잔여 위험도 원본 prefix 실행과 별도 순서 모형으로 확인했다.
이번 결과를 그대로 GCC 2.7용 구현에 채택하거나 전체 분석 완료로 판정하지 않았다.

## 변경 범위와 격리

[실험 입력](job.json), [Python 실행기](run_experiment.py),
[Ghidra 스크립트](VolatileLockExperiment.java), [실행 결과](run-result.json).

| 분석 데이터 주소 | 역할 |
|---|---|
| `001e9858` | `_panic_lock` |
| `001f64cc` | `_vm_info_lock_data` |
| `001e5534` | `FUN_001ca960`의 전역 lock |
| `001e5540` | `_NXAllocErrorData`의 전역 lock |

이 데이터들은 기존 defined data이고 길이는 각각 4바이트다.
데이터 타입, 크기, 함수 원형, 함수 body, 명령 및 참조를 바꾸지 않았다.
메모리 블록 전체를 volatile로 지정하거나 새 코드를 삽입하지도 않았다.

현재 전체 명령 286,091개를 원본 바이트로 재디코딩해 이 주소에 대한
absolute memory operand/immediate 참조를 추출했다.
직접 참조 함수 18개와 이전 비교 대상·대조군을 합쳐 23개 함수를 선택했다.
동적 alias와 간접 참조의 모든 소비자까지 추적했다는 뜻은 아니다.

baseline, volatile_only, reopened_baseline을 별도 JVM과 별도 설정/cache에서 실행했다.
매 단계의 실행 클래스/버전/단계 marker 및 변경 전 상태를 저장했다.
같은 프로세스에서 rollback을 요청한 것만으로 원상복구를 주장하지 않았다.

| 단계 | 데이터 메타데이터 변경 | 선택 함수 C 변경 |
|---|---:|---:|
| baseline | 0 | 0 |
| volatile_only | 4 | 16 |
| reopened_baseline | 0 | 0 |

전체 함수 레코드 5,253개와 defined data 레코드 23,013개를 비교했다.
해당 데이터의 volatile/mutability 외에는 비교 대상 메타데이터 변경이 없다.
전체 listing, references, 초기화 메모리도 동일하다.
초기화 메모리를 원본 Mach-O에 매핑해 파일 1,117,920바이트 모두 다시 대조했다.
각 단계에서 선택 함수 모두 디컴파일에 성공했고,
새로 연 baseline의 선택 C/P-code/메타데이터는 최초 baseline과 같다.
원본 및 복제 프로젝트 저장 파일도 변경되지 않았다.

## 단순히 C가 좋아 보이는 것으로 판정하지 않은 검증

[자동 비교 코드](audit_experiment.py), [결과와 접근별 목록](audit.json),
[C 차이](decompiler-diffs.patch).

원본 명령의 operand 접근 속성에서 각 lock의 읽기·쓰기를 추출했다.
volatile 단계의 high P-code에서 해당 효과를
`함수 주소 / 원본 명령 주소 / lock 주소 / 읽기 또는 쓰기`로 대응시켰다.
효과가 빠지거나 추가되거나 중복되는 경우 assertion이 실패하도록 했다.

| 항목 | 원본과 대응된 수 |
|---|---:|
| 직접 operand 접근 지점 | 79 |
| 읽기 효과 | 77 |
| 쓰기 효과 | 54 |
| XCHG 구간 | 52 |
| 해당 전역 lock의 대기/획득 재시도 쌍 | 25 |

각 XCHG에 대응하는 연산은 `LOCK → volatile read → volatile write → UNLOCK` 순서다.
이 검사는 분석 IR의 순서와 효과 보존을 확인한다.
출력 C의 분리된 읽기·쓰기가 실제 컴파일 시 원자적 XCHG가 된다는 증명은 아니다.
`LOCK()/UNLOCK()`을 빈 매크로로 구현해도 된다는 뜻은 더욱 아니다.

volatile 접근은 high P-code에서 내장 CALLOTHER로 표현된다.
해당 builtin ID는 설치된 Ghidra 소스의 정의와 대조했다.
언어 정의 user-op 이름에 나타나지 않는다고 누락으로 판정하지 않았다.
주소 annotation varnode의 크기와 실제 메모리 접근 폭도 구분했다.
읽기의 output 또는 쓰기 value의 크기로 4바이트 접근임을 확인했다.
[도구 소스 근거](tool-source-evidence.json), [도구 소스 해시](tool-source-hashes.json).

## 복구된 대기와 재시도

전체 25개 선택 전역 lock 대기 지점에서 원본 대기 분기와 획득 재시도가 모두 표현된다.
baseline에서는 그중 재시도 25곳과 대기 3곳이 최적화된 P-code에서 사라져 있었다.
이전 보고서의 더 작은 선택 집합과 조사 범위가 다르므로 수치 증가를 혼동하면 안 된다.

`_panic`은 이제 다음 동작을 구분해 표시한다.

- lock 값을 먼저 한 번 읽음.
- 읽어 둔 지역값을 대기 loop 안에서 검사함.
- XCHG의 이전 값과 새 값 기록을 표시함.
- 이전 값이 이미 획득된 상태이면 원래 읽기 위치로 재시도함.

`_mfs_cache_trim`의 두 번째 대기도 다시 나타난다.
메모리 CMP로 반복하던 라이브러리 대조군은 volatile read가 loop 안에 남는다.
스크립트는 block의 주소 범위로 추측하지 않고 실제 branch operation과
volatile read operation의 block 소속을 비교한다.

분석 DB의 volatile 설정은 읽기·쓰기 효과를 제거하지 않도록 지시하는 모델링 실험이다.
원래 소스 필드가 반드시 volatile이었다는 역추론은 하지 않았다.
원본 소스를 다시 작성할 때 volatile을 추가하는 일과도 별개의 결정이다.

## 남은 위험: lock 이외의 보호 데이터

[잔여 위험 검토 코드](protected_read_review.py), [근거와 실행 결과](protected-read-review.json).

`_mfs_cache_trim`의 원본은 다음 순서다.

1. `0015ec19`: lock XCHG 및 획득 결과 검사.
2. 조건 통과 후 `0015ec54`: `_vm_info_queue`를 EBX에 읽음.

그러나 lock만 volatile로 지정한 C에는
`puVar4 = _vm_info_queue;`가 첫 lock 읽기·획득보다 먼저 놓인다.
high P-code에도 `0015ec08` block의 queue snapshot COPY가 남아 있다.
보호 대상 데이터까지 포괄하는 barrier/alias 모델이 완성됐다고 볼 수 없다.

이를 확인하기 위해 원본의 첫 획득 prefix를 실행하고,
XCHG 직전 queue head를 합성 외부 사건으로 변경했다.
원본은 lock 획득 뒤 새 queue head를 읽는다.
반면 출력 C에 보이는 선행 snapshot의 순서만 모델링하면 이전 값을 보관하게 된다.
9개 조건 중 queue head가 바뀐 6개 조건에서 두 snapshot이 달랐다.

이 비교는 **원본 prefix 실행 대 출력 C의 부분 순서 모형**이다.
전체 C를 컴파일해 실행한 결과, 실제 동시 실행 updater, 전체 list 조작·커널 실행 시험은 아니다.
따라서 실제 메모리 손상이나 런타임 장애가 발생했다고 단정하지 않았다.
다만 lock 접근 복구만으로 보호 데이터 읽기 위치까지 검증됐다는 주장은 배제할 수 있다.

## 후속 검토 대상

- 보호 데이터의 읽기/쓰기와 획득·해제 사이 순서를 보존하는 분석 모델.
- volatile 데이터 지정과 memory barrier/atomic 모델의 역할 차이.
- 구조체 내부 lock, 동적 포인터 alias 및 다른 원자 연산의 표현 손실.
- 최종 GCC 2.7/NeXT 툴체인에서의 실제 코드 생성·원자성·순서 검증.
- 실제 경쟁 가능 경로, interrupt 규약, 하드웨어·부팅 검증.

Ghidra 스킬에 따라 원본 명령, 프로그램 데이터 속성, high P-code와 C를 단계별로 대조했다.
검증된 설정 효과와 미해결 protected-data 문제를 분리해 기록했다.
정본 DB·원본 바이너리·기존 보고서·`07_kernel`은 수정하지 않았다.
계산·주소/폭 변환·개수·해시·모형 비교는 모두 Python으로 진행했다.

## 무결성과 재현

[입력 해시](input-hashes.json), [프로젝트 사전 해시](source-project-before.json),
[검증 스크립트](verify_artifacts.py), [검증 결과](verification.json),
[산출물 해시](artifact-hashes.json).

이전 manifest를 갱신하지 않고 그 원래 해시로 검증한다.
이번 runtime/cache는 산출물 manifest에서 제외한다.
실험기는 기존 snapshot 덮어쓰기를 거부하므로 재실행하려면 새 경로를 지정해야 한다.
