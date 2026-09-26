# PT backing 회수 — 제한된 경로 검증

원본 실행·독립 감사·증거 훼손 대조·처음부터 재실행 결과를 이 보고서에 보존한다.
확정 여부와 보존/해시 gate는 [최종 검증](verification.json) 및
[산출물 manifest](artifact-hashes.json)로 확인한다. **전체 분석/커널 복원 완료가 아니다.**

[계획](PLAN.md)과 [코딩 전 교차검토](CROSS_REVIEW.md)를 거쳐
[원본 실행기](pt_gc_review.py)를 작성했다. Ghidra 스킬로 보존된 ASM/C를 읽기 전용
대조했으며 원본/DB/export/이전 보고서와 `07_kernel`은 수정하지 않았다.
계산과 해시 검사는 Python으로 수행한다.

## 실행 및 독립 검증 증거

[gc-cases.json](gc-cases.json), [gc-summary.json](gc-summary.json)에 다음 결과를 기록했다.

- 기존 root/copy/destination/prefix flags/zone 조건의 32개 GC 실행.
- root A/B에서 last 초기화, delta 0, delta 1을 구분한 시간 gate 대조 6개.
- 총 38개 사례가 실행기 assertion을 통과했고 기록된 원본 instruction heads는 49,462개다.
- GC가 실행된 사례의 최종 active/free/wire 계수는 `1/1/0`, TLB 계수는 `4/4`다.
  gate 대조에서는 각각 `1/0/1`, `2/2`이며 last tick은 갱신된다.

[독립 감사](independent-audit.json)는 전체38 사례의 입력 경계·원본 trace·쓰기 replay·
중간 queue/lock/lookup/PTE·최종 모델을 통과했다. [훼손 대조](negative-controls.json)는
74개 조작을 거부했다. [새 실행 재현](reproducibility.json)은 prefix부터 다시 실행한
주요 산출물9개의 해시가 모두 동일함을 확인했다. 동일 backend 재현이며 native
하드웨어와 독립 실행 엔진의 동등성 증거가 아니다.

`gc-summary.json`의 status는 producer 실행 단계만의 보수적 표시다. 뒤의 감사 및
최종 확정 결과는 위 별도 산출물로 판정하며 실행기가 감사 성공을 대신 주장하지 않는다.

실제 실행에서 확인한 경로는 extension 반환 → kernel map 삭제 → KVA wired bit 해제
→ PT segment에서 PG 조회 → PG의 일시적 active 삽입 → pmap_remove_all → PG free
→ 이미 NP인 KVA의 후속 제거 → KO ref2→1 및 map entry 반환이다.
KO는 resident0/ref1로 존속하고 DATA payload/dirty/object와 최종 active 상태는 유지된다.
PG의 일시적 active 삽입 중에는 DATA queue 링크도 변하므로 전 과정 불변으로 보지 않는다.

`vm_object_page_remove`/`vm_page_free`의 이 실행 경로에서는 KO lock=0이었다.
이는 일반 page-free caller 예제의 합성 object-lock 조건을 모든 경로에 적용하면
안 된다는 관찰이다. 기록된 중간 상태/쓰기 replay 및 최종 model을 감사했으나
다른 caller의 lock 전제나 실제 다중 CPU 경합의 안전성을 증명하지 않는다.

## 발견한 감사 누락과 보완

교차검토의 주장을 그대로 채택하지 않고 root가 Python으로 직접 재현했다.
복귀주소와 stack snapshot을 함께 조작하거나 추가 PTE 쓰기와 파생 walk를 함께
변경하면 종전 감사가 허용하는 문제가 있었다. [감사기](audit_results.py)에 다음을 추가했다.

- ESP/EBP 추적 및 CALL/PUSH 실제 stack slot·값과 RET 실제 읽기의 연결.
- 원본 opcode/operand에 근거한 명령당 store 개수/폭. Capstone이 TEST를 write로
  잘못 표시하는 metadata는 근거로 삼지 않는다.
- KVA PTE 및 PT owner/backlink와 겹치는 모든 쓰기의 허용 목록 검사.
  DATA/PT payload 및 DATA의 queue links 외 보존 metadata에 대한 write 금지.

[대조 코드](test_audit.py)는 snapshot을 일관되게 재작성한 반례와 byte 부분 겹침,
실제 RET 읽기 검사의 단독 대조를 포함한다. [교차검토](CROSS_REVIEW.md)에
발견·재현·수정 후 독립 확인을 구분해 기록했다.

[이전33 stack 회귀](legacy-stack-review.json)는 보존된32행에 새 stack 검사를
읽기 전용으로 적용해 통과했다. 전체33 재감사나32의 pushal/IRETD 검증이 아니다.
일반 EA/값/GPR/flags와 모든 분기 조건을 독립 에뮬레이션했다고 주장하지 않는다.

## prefix와 증거의 한계

[dirty_prefix.py](dirty_prefix.py)는 확정33 함수를 새 위치에 기계 복제한 helper다.
[check_helper.py](check_helper.py)와 [helper-check.json](helper-check.json)은 지정한
변환(case 파일쓰기 제거, live CPU 반환, main 제거) 외 차이가 없는지 검사한다.
원본33의 producer나 save/main을 실행하지 않는다.

새 실행의 전체33 결과를 동일 scenario의 확정33 결과와 비교한 뒤 fresh canonical
hash를 기록하고 live CPU에서 GC를 이어간다. compact 기록은 producer의 full-row
동등성 검사에 의존한다. 독립 GC 감사는 기록된 명시적 입력 경계부터 시작하며
새 prefix의 모든 중간 CPU를 독립 재감사했다고 주장하지 않는다.
tick/last/PD/aging raw는 합성 seed 전후 모두 캡처한다.

합성 scheduler tick/PD empty queue와 caller 입력은 실제 scheduler/전체 boot 또는
memory discovery 실행이 아니다. free PD 회수, active PT aging, tick wraparound,
동시성/자원 부족/pager/COW, native CPU/실제 TLB/cache와 전체 ownership도 미완료다.
이전 보고서의 전체 잔여 의무와 실제 GCC 2.7 구현·빌드·부팅/후속 아키텍처 목표를 유지한다.

## 다음 작업

[잔여 분석](OPEN_ITEMS.md)에 실제 free 자원의 재사용·수명, PD/aging/tick 경계,
이전 전체 소비자의 감사 취약점 회귀와 전체 분석 의무를 남겼다.
GCC 2.7 구현·실컴파일·링크·부팅은 아직 수행하지 않았다.
