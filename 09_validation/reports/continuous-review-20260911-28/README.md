# 신중한 추가 검토28 — 원본 page 할당·해제·cached 재할당

## 판정

원본 `vm_page_alloc_sequential`, `vm_page_free`, `vm_page_addfree`를 실행하여
정상 FIFO 할당/해제/재사용과 cached page의 이전 객체 연결 제거를 검증했다.
empty·reserve 경계·vm_privilege에 따른 거절/허용을 분리했다.

| 관찰 항목 | 결과 |
|---|---:|
| fresh 사례 | 72 |
| 관측 원본 함수 호출 | 592 |
| page 할당 성공 | 88 |
| page 할당 NULL 반환 | 32 |
| alloc 내부 cached/tabled 제거 호출 | 32 |

집계는 Python이며 항목은 겹친다. 전체 커널/VM coverage 또는 모든 allocator
입력의 증명이 아니다. 새 물리 메모리를 OS가 발견한 것이 아니라, 준비한 전용
frame descriptor를 원본 allocator가 free queue에서 꺼내 객체에 연결한 것이다.

## 원본으로 만든 상태와 합성 경계

기존 높은 CS 및 분리된 A/B root fixture를 재사용한다. 원본 zero-BSS template
전제를 확인한 뒤 `vm_page_startup(0x17aa08)`의 prefix를 실행하고 `0x17aade`
직전에 멈춘다. template 전체의 clean/busy 등 초기값, free/active/inactive
sentinel 및 잠금 초기화를 확인했다. 전체 startup이나 실제 메모리 발견을 수행한
것은 아니다. prefix의 미복귀 stack/register는 다음 호출 준비에서 다시 설정한다.

object 두 개·hash arena·전용 물리 backing 및 caller lock은 명시적 합성 입력이다.
template 자체는 API로 쓰지 않는다. 원본 `vm_page_init(0x17b134)`으로 hash가
충돌하는 페이지들을 old object에 삽입하여 memq/hash/tabled/resident 수를 구성한다.

seed는 다음과 같이 구별한다.

- detached: 원본 free로 hash/memq에서 제거한 뒤 free queue에 넣는다.
- cached: wanted=0 상태에서 busy를 해제하는 **합성 준비 경계**를 기록하고,
  원본 addfree로 tabled/hash/memq를 유지한 채 free queue에 넣는다.

중간/처음/마지막 page 순서로 seed를 만들고 원본 alloc의 FIFO 결과를 확인한다.
cached alloc에서는 기존 hash chain 및 memq 제거와 old resident 감소 뒤 새 object
삽입을 실제로 관찰했다. 정상 free→realloc만으로 이 경로를 검증했다고 하지 않는다.

frame backing은 별도 CPU 모델 RAM에 준비했다. 실행 fixture의 A/B 전체 PDE/PTE
스캔에서 이 frame들에 대한 매핑이 없음을 확인했다. 이는 fixture root 범위의
관찰이지 전체 원본 PV/물리 페이지 소유권·pageout 매핑 제거의 증거가 아니다.
독립 audit는 스캔 결과를 소비하며 별도로 page table 전체를 재스캔하지 않는다.

## reserve·policy·잠금 조건

empty queue는 privilege와 무관하게 먼저 NULL을 반환한다. 비어 있지 않은 경우,
free_count<reserved인 ordinary thread는 거절되고 vm_privilege가 있으면 허용된다.
free_count==reserved는 ordinary/privileged 모두 허용된다. above 경계도 대조했다.
입력 count는 유효한 작은 비음수 값이며 signed overflow/비정상 count는 미검증이다.

min/target/inactive-target=0, object policy=0을 합성 입력으로 명시했다. wakeup과
vm_policy_apply 호출은 이 시험에서 실행되지 않았음을 검사했다. sequential 인자
0/1을 대조했고 양쪽 모두 성공 시 last_alloc가 원본 `0x17b52d`에서 갱신됐다.
policy가 켜진 실제 sequential 처리나 pageout 진행을 검증한 것은 아니다.

대상 원본 심볼은 **vm_page_alloc_sequential**이며 인자가 셋이다. Darwin의
vm_page_alloc 매크로는 이 함수를 호출하지만, 오래된 공개 소스의 두 인자 함수
정의를 원본에 그대로 적용하면 안 된다.

caller 소유 object/global queue lock=1을 준비하고 보존했다. 함수가 해당 잠금을
자체 획득하는 것으로 모델링하지 않았다. 내부 free/hash lock은 원본 코드가
획득·해제하고, 종료 시 해제되어 있다. 실제 경쟁·비동기 interrupt는 범위 밖이다.

## 실행 및 독립 검산

원본 함수를 patch/mock하지 않았고 호출 도중 API로 자료를 교정하지 않았다.
각 함수의 원본 trace, CPU·callee-saved·stack, 전체 object/descriptor/hash/queue와
count 상태를 전후 저장했다. template 복사의 REP에서 ECX·ESI·EDI·DF를 매 방문
관찰하여 진행과 종료를 검사했다. descriptor만 초기화되며 물리 backing 데이터는
바뀌지 않음을 확인했다. 즉 page alloc을 zero-fill로 잘못 해석하지 않는다.

object/descriptor 주변 guard와 기존 복사 버퍼·stack guard를 검사했다. 관측 함수
call() 동안에는 허용된 stack/metadata/global 영역 밖 쓰기를 거절했다. last_alloc
store를 양성 witness로 기록하여 write hook이 작동하는지도 검사했다. startup
prefix에는 이 write hook을 적용하지 않았으며 별도의 trace/최종 상태 검사 범위다.

독립 audit는 fixture를 import하지 않는다. 별도 byte 모델로 연결 리스트 제거·삽입,
resident WORD·free count·template/phys 보존·last_alloc를 계산하고 **관측 metadata
전체 바이트**를 비교한다. hash/memq/free queue graph 정합, 원본 call/return/branch,
REP 진행, case에서 도출한 호출 schedule/인자/entry/reserve/privilege를 대조한다.
같은 backend 관찰의 독립 검산이며 다른 하드웨어에서의 재실행 증거는 아니다.

후속 Codex 검토가 지적한 scenario/entry/schedule 검산 누락을 수정하고, 잘못된
입력을 거절하는 음성 대조를 추가했다. 상세는 [계획](PLAN.md)과
[교차검토 기록](CROSS_REVIEW.md)에 있다. Ghidra 스킬에 따라 원본·공개 소스·
합성 준비·관찰을 분리했고 정본 DB를 변경하지 않았다. 모든 계산은 Python이다.

## 산출물과 재현

```sh
python3 -B 09_validation/reports/continuous-review-20260911-28/allocator_review.py
python3 -B 09_validation/reports/continuous-review-20260911-28/audit_results.py
python3 -B 09_validation/reports/continuous-review-20260911-28/test_audit.py
python3 -B 09_validation/reports/continuous-review-20260911-28/reproduce_results.py
python3 -B 09_validation/reports/continuous-review-20260911-28/verify_artifacts.py
```

[원시 실행 결과](allocator-cases.json), [집계](allocator-summary.json),
[독립 검산](independent-audit.json), [음성 대조](negative-controls.json),
[마지막 호출 진단](latest-diagnostic.json), [재현 해시](reproducibility.json),
[실행 전 보존](preservation-before.json), [실행 후 보존](preservation-after.json),
[입력 해시](input-hashes.json), [최종 보존 검증](verification.json),
[산출물 해시](artifact-hashes.json), [잔여 분석](OPEN_ITEMS.md).

원본·정본 Ghidra/IDA DB·reference sources·이전 보고서·07_kernel은 보존한다.
전체 분석·원본 VM 생성·pager/실제 pageout·GCC 2.7 구현/빌드/부팅·후속
아키텍처를 이번 시험으로 완료 처리하지 않는다.
