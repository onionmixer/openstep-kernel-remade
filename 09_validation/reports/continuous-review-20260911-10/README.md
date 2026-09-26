# 연속 추가검토 — MIG·커널 API 원형 및 반환 계약

대상: OPENSTEP 4.2 mk-183.34.4 / x86. 검토일: 2026-09-11.
원본 SHA-256: `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`.

## 결론

`task_create`, `thread_policy`, `mig_dealloc_reply_port`에 적용된 원형이
현재 바이너리의 인자 전달·사용과 맞지 않는다. Ghidra뿐 아니라 저장된 IDA 출력에도
같은 원형 불일치가 있다. 두 도구의 출력 일치는 이 경우 정확성의 증거가 아니다.

원형 수정과 `noreturn` 수정의 영향을 독립 프로세스에서 분리했다.
원형을 수정하면 선택한 31개 함수 중 29개의 C 출력이 달라지고,
직접 호출 26곳의 P-code 인자 수가 원본에서 확인한 계약에 맞게 줄어든다.
앞선 변환 함수의 인자가 없어 보이던 현상도 함께 해소된다.

원본 명령을 이용한 제한 실행 시험은 181개 조건에서 통과했다.
이는 MIG 경계의 인자·응답 및 특정 오류 경로 검증이지,
태스크 생성·스케줄링·IPC·실제 panic·부팅의 전체 검증이 아니다.
전체 분석 완료 또는 GCC 2.7 호환 완료로 판정하지 않는다.

## 원형별 근거

[원본 CALL·참고 소스 근거](evidence.json), [추출 코드](evidence.py),
[메타데이터·P-code 비교](audit.json).

| 함수 / 주소 | 기존 분석 원형 | 원본과 대응하는 계약 | 직접 CALL |
|---|---|---|---|
| `_task_create` / `00165a20` | parent, ledgers, ledgersCnt, inherit_memory, child_task | parent_task, inherit_memory, child_task 출력 포인터 | 7 |
| `_thread_policy` / `001688f4` | thread, policy, base 포인터, baseCnt, set_limit | thread, policy 정수, data 정수 | 3 |
| `_mig_dealloc_reply_port` / `00158fb4` | reply_port | 인자 없음; panic으로 진입 | 16 |

### task_create

원본은 `[EBP+8]`, `[EBP+0xc]`, `[EBP+0x10]`을 사용한다.
두 번째 인자는 메모리 상속 여부의 조건이고, 세 번째는 새 task를 기록하는 출력 주소다.
기존 C는 이를 `ledgers` 포인터와 `ledgersCnt` 개수로 이름·타입을 붙여 놓았다.
이는 단순한 변수 이름 취향이 아니라 출력 포인터와 논리값의 의미가 바뀐 오류다.

MIG stub `0016f9f0`의 원본 호출 `0016fa34`에서도
변환된 task, 요청의 inherit 값, 지역 출력 슬롯 주소를 전달한다.
기존 출력은 그 뒤에 남아 있던 다른 스택 값과 `unaff_EBX`까지 추가 인자로 붙였다.

로컬 mk-108.1 `kern/task.c`와 `kern/mach_server.c`의 세 인자 원형은
이 인자 역할을 뒷받침한다. 그러나 구현 전체를 그대로 대입할 수는 없다.
현재 원본은 `00165a6a`에서 세 번째 인자 주소를 `_kernel_task` 전역 주소와 비교한다.
참고 소스의 parent-task 비교와 다른 부분이므로, 옛 소스에 맞추어 원본 사실을 바꾸지 않았다.

### thread_policy

원본은 `[EBP+8]`에서 thread, `[EBP+0xc]`에서 policy,
`[EBP+0x10]`에서 data를 가져온다.
세 번째 값은 quantum 계산에 사용되는 정수이며, `policy_base_t` 포인터가 아니다.
MIG stub `0016eb34` 및 `_IOSetThreadPolicy`의 호출도 세 인자 전달과 일치한다.
mk-108.1 `kern/thread.c` 및 `kern/mach_host_server.c` 역시 세 인자 형태다.

thread가 NULL이거나 원본의 policy 범위 검사를 통과하지 못하는 빠른 반환 경로는
모의 callee 없이 실제 원본 명령으로 실행했다. 정상 policy 변경, 경쟁 lock,
우선순위 갱신 및 scheduling 동작은 이번 실행 시험 범위 밖이다.

### mig_dealloc_reply_port

본문은 인자를 읽지 않는다. 고정 문자열 주소를 PUSH한 뒤 `_panic`을 호출한다.
문자열은 `mig_dealloc_reply_port`이며, 옛 소스의 panic 문자열과는 다르다.
옛 소스는 인자 없음과 panic 진입이라는 역할의 보조 근거일 뿐 동일 본문 증명이 아니다.

Ghidra의 저장된 함수 속성은 `noreturn=false`였다.
자기 본문에서는 panic 때문에 비반환 경고가 나오더라도,
호출자에게 비반환 계약이 정확히 전파됐다는 뜻은 아니었다.
저장된 IDA C에는 `__noreturn`이 이미 있지만, 불필요한 reply_port 인자는 남아 있다.
IDA 결과는 기존 ps2 snapshot 출력이며, 새 동일-input DB 검증 결과로 취급하지 않는다.

## 독립 Ghidra 실험

[실험 입력과 호출 목록](job.json), [Python 실행기](run_experiment.py),
[Ghidra 추출·변경 스크립트](ApiContractExperiment.java), [실행 기록](run-result.json),
[자동 검증 코드](audit_experiment.py), [C 출력 차이](decompiler-diffs.patch).

| 단계 | 변경한 함수 메타데이터 | 선택 함수 중 C 변경 | 확인 목적 |
|---|---:|---:|---|
| baseline | 0 | 0 | 기존 full-pass5 출력 재현 |
| prototype_only | 3 | 29 | 인자 원형의 영향 |
| noreturn_only | 1 | 16 | 비반환 계약만의 영향 |
| combined | 3 | 29 | 두 변경의 결합 |
| reopened_baseline | 0 | 0 | 변경 없는 DB를 새로 열어 초기 상태 재현 |

각 단계는 별도 JVM·settings·cache·temp·prefs를 사용한다.
실행 클래스/버전/단계 marker와 변경 전 전체 함수 메타데이터를 저장했고,
모든 단계가 같은 초기 상태에서 시작했는지 비교했다.
같은 프로세스의 transaction rollback만으로 상태 복구를 주장하지 않는다.

검증 결과:

- 전체 함수 레코드 5,253개의 body와 locals가 그대로다.
- 전체 listing, references, 초기화 메모리가 단계 사이에서 같다.
- 초기화 메모리 26개 블록을 원본 파일에 매핑해 1,117,920바이트 모두 대조했다.
- 선택 함수 31개 모두 각 단계에서 디컴파일을 완료했다.
- `_strcpy`, `_objc_msgSend` 대조군은 C 출력이 변하지 않았다.
- 새로 연 baseline의 선택 C·P-code·메타데이터는 첫 baseline과 동일하다.
- 원본 프로젝트와 실험 복제본의 저장 파일도 변경되지 않았다.

실험 타입의 `void *`와 `void **`는 잘못된 상세 타입을 강요하지 않기 위한
불투명 포인터다. task/thread의 전체 구조체 layout을 복원했다는 뜻이 아니다.
생성된 C는 GCC 2.7용 채택 소스가 아니며 그대로 컴파일·복원 소스로 사용하면 안 된다.

## 호출 인자 손상의 전파

직접 CALL의 원본 바이트·대상은 저장 reference에서만 가져오지 않고,
현재 전체 함수 export의 원본 instruction을 다시 디코딩한 결과와 대조했다.
발견된 CALL 집합은 reference의 집합과 정확히 일치한다.
이는 현재 발견된 명령의 직접 호출 집합 검증이며, 미발견 코드나 간접 호출의 부재 증명은 아니다.

P-code 비교에서 `task_create`와 `thread_policy` 호출은 5개에서 3개 인자로,
`mig_dealloc_reply_port` 호출은 1개에서 0개 인자로 바뀌었다.
`noreturn`만 수정한 단계에서는 잘못된 인자 수가 그대로였다.
따라서 인자 원형과 반환 계약은 별도로 교정해야 한다.

또한 MIG stub의 변환 호출은 다음과 같이 바뀌었다.

| 호출 주소 | 대상 | baseline 인자 수 | combined 인자 수 |
|---|---|---:|---:|
| `0016fa24` | `_convert_port_to_task` | 0 | 1 |
| `0016eb6c` | `_convert_port_to_thread` | 0 | 1 |

원본은 두 지점 모두 요청의 port 값을 PUSH한다.
변환 함수 자체의 저장 원형을 변경하지 않아도 뒤쪽 API의 잘못된 인자를 제거하자
앞선 호출에 올바른 인자가 다시 붙었다.
호출 한 곳의 오해가 주변 호출의 C 표현까지 손상시킨 구체적 사례다.

## 제한 실행 검증

[Python 실행 시험](mig_execution.py), [전체 조건·trace·결과](mig-execution.json).

| 시험 | 조건 수 | 검증한 범위 |
|---|---:|---|
| task_create MIG stub | 27 | 요청 검사, 세 인자, 출력 슬롯, 성공/오류 reply |
| thread_policy MIG stub | 124 | 요청 검사, 세 인자, 반환값 reply, thread 해제 호출 |
| thread_policy 자체 빠른 반환 | 27 | NULL/범위 밖 policy의 원본 반환값 및 stack/register 복구 |
| port_allocate 외부 stub 오류 | 3 | 특수 오류의 dealloc→panic 진입 및 일반 오류 반환 |
| 합계 | 181 | assertion 실패 0 |

MIG 시험에는 길이, complex 비트, 타입 descriptor가 잘못된 요청 7개가 포함된다.
잘못된 요청에서는 API를 호출하지 않고 오류 reply만 기록하는지 검사했다.
정상 요청은 원본 stub을 실행하되 conversion, task_create/thread_policy,
deallocate, task-to-port 등의 callee 결과를 명시적으로 모의했다.
NULL conversion 및 임의 오류값을 포함한 조건은 경계 동작 시험용이며,
해당 조합이 실제 kernel service에서 발생한다는 주장이 아니다.

요청 버퍼 불변, reply 전체 비교, 원본 실행 바이트, stack 균형,
callee-saved 레지스터 보존을 검사했다. 성공 reply의 complex 비트 설정을 확인하도록
reply 초기 표식의 최상위 비트는 0으로 두었다.

`_port_allocate_EXTERNAL` 시험은 `mig_get_reply_port`와 `msg_rpc`만 모의한다.
특수 오류 `-202`에서는 원본이 인자 PUSH 없이 `_mig_dealloc_reply_port`를 호출하고,
그 원본 함수가 실제 `_panic` 진입점에 도달함을 확인했다.
panic 본문은 실행하지 않고 진입점에서 중단했다. 다른 오류 조건은 원래 반환 경로를 실행했다.
따라서 이 시험만으로 실제 panic의 최종 정지 동작을 검증했다고 표현하지 않는다.

## 아직 남아 있는 문제

- 이번 변경은 세 API에 한정된다. 전체 API 원형의 정합성을 보장하지 않는다.
- 수정 후 `_task_create` 안에도 `_pmap_create`/`_vm_map_create` 사이의
  인자 귀속이 원본 호출 준비와 맞는지 재검토할 부분이 남는다.
- `_thread_policy`의 경쟁 lock 경로는 실제 역분기 대상과 메모리 재읽기 여부를
  별도로 검토해야 한다. 이번 빠른 반환 시험은 이 경로에 진입하지 않는다.
- task/thread 구조체, 전체 scheduler, IPC 및 메시지 descriptor의 완전한 타입 복원은 남아 있다.
- IDA의 동일 원본 DB 검증·실패 항목, 이전 보고서의 경계·간접 호출·ABI 문제도 남아 있다.
- GCC 2.7 실제 빌드, 커널 링크·부팅, SPARC 등 후속 아키텍처 검증은 수행하지 않았다.

원본 바이너리·정본 Ghidra/IDA 분석물과 `07_kernel`은 수정하지 않았다.
실험용 복제 프로젝트와 이번 보고서 디렉터리에만 새 분석 산출물을 추가했다.
모든 주소·개수·크기·비교·해시·실행 모델 계산은 Python으로 수행했다.

## 무결성과 재현

[입력 해시](input-hashes.json), [원본 프로젝트 사전 해시](source-project-before.json),
[검증 스크립트](verify_artifacts.py), [검증 결과](verification.json),
[이번 산출물 해시](artifact-hashes.json).

이전 보고서의 manifest는 갱신하지 않고 원래 해시로 검사한다.
이번 manifest에는 새 분석 자료를 포함하되 재생성되는 runtime/cache는 제외한다.
실험 실행기는 기존 snapshot 덮어쓰기를 거부한다. 재실행하려면 별도 새 경로를 정해야 한다.
