# 원본 aging 결정 → 실제 전체 PT 제거

이 보고서는 report39가 실행하지 않았던 제거 결정 이후를, 새로 재현한 report32 원본 매핑 상태에 연결한다. 커널 구현이나 전체 분석 완료 보고서가 아니다.

## 확인한 실행 결과

- 원본 실행 36개 사례: 제거 32개, 임계값 동등 유지와 Accessed 해제 대조 4개. 모두 실제 원본 RET와 호출자 스택 복귀를 확인했다.
- 기록한 instruction head 340,938개, 메모리 쓰기 35,242개, 전체 PT scan의 VM bundle 32,768개.
- 제거 사례마다 실제 helper 인자는 `[PMAP, 0, 0x800000, 1]`이다. 전체 section을 줄이지 않았고, PT의 모든 VM bundle을 순서대로 검사했다.
- `EXT.offset=0`의 첫 PDE가 aging 검사 대상이다. 복사된 DATA는 다음 PDE를 사용하며 그 Accessed 비트를 인위적으로 지우지 않았다.
- age 7과 tick 차이 2는 age 9를 저장한 뒤 회수한다. age 6의 경우 결과 8이 임계값과 같아 유지한다. 선택 PDE가 Accessed인 대조는 해당 비트와 age를 지운다.
- 전체 section 회수는 원본 CR3 재적재 경로이다. TLB 계수는 `[1,1]→[2,1]`이며 개별 INVLPG 경로가 아니다.
- dirty DATA의 PTE 해제, PV owner 제거와 dirty/reference 누적, PDE 쌍 present 해제, active-PT→free-PT 큐 이동을 확인했다. DATA payload·active page 상태와 원본 PT backing의 wired·kernel object/map/zone 소유권은 유지된다.
- free-PT sweep 이후에 새 free PT가 등록되므로 이번 호출에서는 backing을 해제하지 않는다. 퇴역 EXT의 age는 9로 남고, saved-next로 원래 active-head에 도달한 뒤 last tick을 3으로 갱신한다.

## 검증과 근거

[계획](PLAN.md) 단계에서 독립 Codex 교차검토를 받았고, 원본 ASM과 Python 계산으로 root가 다시 확인했다. [교차검토 기록](CROSS_REVIEW.md)의 검증기 반례들은 root가 직접 재현한 뒤 수정했다.

[독립 감사](removal-audit.json)는 원본 바이트 기반 명령·쓰기 수/폭, 실제 stack CALL/RET, 기록된 쓰기의 상태 재생, 전체 PT scan, 명시적 critical operand/EA와 최종 상태 모델을 검사한다. [음성 대조](negative-controls.json)의 기록 변조 46개가 모두 거부됐다.

[원본 실행 요약](removal-summary.json), [원본/입력 근거](source-basis.json), [이전 파일 보존](preservation.json)을 별도 보존한다. 새 emulator 실행부터 감사를 반복하여 [재현 산출물 6개](reproducibility.json)의 해시 일치를 확인했다. 같은 backend의 재현성이지 독립 CPU 구현 간 동등성은 아니다. [checkpoint](checkpoint.json)는 전체 사례 재감사·입력 해시·재현 산출물 및 보고서 파일 해시 검사를 기록한다.

## 해석 한계

- 실제 OPENSTEP 부팅이 아니라 synthetic bootstrap/map/object/zone 조건의 Unicorn 실행이다. prefix CPU-frame은 명시적 수동 입력이다. report37/38의 native RF 미해결은 그대로 남는다.
- report32 공통 필드는 새 실행 결과와 정확히 비교하지만, 기존 `points`와 `zero_chunks`는 다시 수집하지 않았다. 전체 report32-row 새 검증이라고 부르지 않는다.
- 이 감사는 전체 CPU의 모든 GPR/flags/EA·자동 paging write를 독립 구현한 것이 아니다. 원본 store를 기록하고 제한된 paging A/D 변화만 허용하는 replay와 특정 operand 검사를 구분한다.
- 단일 active PT·단일 DATA 매핑 및 비어 있는 free-PD queue 조건이다. 스케줄러의 실제 시간 진행, 다중 큐/alias/race, native TLB/cache는 아직 검증하지 않았다.
- 원본/기존 보고서와 Ghidra/IDA DB는 변경하지 않았다. Ghidra 스킬은 보존 export를 읽기 전용으로 대조하는 데 사용했다. `07_kernel` 구현이나 GCC 2.7 실컴파일을 수행하지 않았다.

남은 범위는 [OPEN_ITEMS.md](OPEN_ITEMS.md)에 유지한다.
