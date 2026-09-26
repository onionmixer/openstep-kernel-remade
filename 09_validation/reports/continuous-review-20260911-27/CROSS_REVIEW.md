# Codex 교차검토 기록 — 보고서27

## 코딩 전 설계 검토

root는 PLAN.md의 정적 census/실행 trace 차집합 도구를 작성하기 전에 기존
`/root/trap_plan_review`에 읽기 전용 검토를 요청했다. 회신의 핵심 지적:

- 함수 밖 PC를 먼저 제거한 뒤 인접 쌍을 만들면 call/return·재진입·case 경계에서
  가짜 edge가 생긴다. 각 case의 전체 trace에서 바로 다음 head를 먼저 확인해야 한다.
- call 뒤의 정적 fallthrough는 callee가 복귀한다는 가정이다. panic/nonreturn
  뒤의 관계를 관찰된 정상 edge나 실행 가능 경로로 처리하면 안 된다.
- 정적 backedge와 실제 반복을 구별하고, 해석하지 않은 간접/함수 밖 목적지는
  미해결로 남겨야 한다. stop PC를 trace에 넣지 않는 실행기 규약도 구분한다.

root는 report26의 완전한 handler trace와 기존 high_run/독립 audit 규약을 직접
읽고 위 위험을 확인했다. 생성기는 case를 합치거나 함수별 필터링한 trace로
edge를 만들지 않는다. transfer의 다음 head가 없는 경우에는 거절한다.
정적 call continuation은 `call_return_assumed`로 표시하고 관찰 분기 수에 넣지
않는다. 본문 밖 continuation은 별도 unresolved 목록에 보존한다.

이는 코딩 전 **설계 검토**이다. pmap 전체 의미 검토까지 이 회신으로 받았다고
기록하지 않는다. 이후 해당 에이전트 상태가 pending_init인 것을 확인하고 중단했다.
도구/문서 작성 후의 별도 의미 검토는 아래처럼 구분한다.

## 후속 의미 검토

`/root/vm_contract_review27`에 새 문서 VM_CONTRACTS.md의 원본 ASM 대조를
읽기 전용으로 요청했다. 이 요청은 작성 이후이므로 코딩 전 검토로 소급하지 않는다.
검토자는 다음 주소 관계에 오류/과장을 발견하지 못했다고 회신했다.

- expand 실패 `0x190d80 → 0x190f1a`와 호출자 재검사 `0x1907bc → 0x190780`.
- PV zalloc `0x190a06` 뒤 `0x190a11 → 0x19075c` 재시도.
- `0x172376`, `0x172d13`의 매핑 호출 없는 0 반환과 공통 epilogue.
- page_lock 충돌 `0x1724c3` 비영 경로의 정리 및 `0x172572` EAX=10.
- vm_fault `[EBP+0x18]` 인자의 pager/vnode 전달, vnode의 NULL 검사 후 조건부 저장.
- 정본 whole-program 직접 호출자와 문서의 PUSH/보호 분기 구간 대응.

root도 해당 ASM을 직접 읽었고, 원본 Mach-O를 읽는 Python 검산에서 상대 분기
목적지, 선택 operand/상수/오프셋, 직접 호출 인자 및 corpus 집계를 검사했다.
Codex의 동의 자체는 검증 성공 근거가 아니다. 후속 검토자는 실행 가능성·동시성·
원본 바이트 재디코딩·공개 소스 전체 동일성을 증명하지 않았음을 명시했다.

## 검산 한계

음성 대조는 분석기의 누락/잘못된 edge 거절 능력에 관한 시험이다. 원본 kernel
경로의 새 실행이 아니다. 공개 소스의 의미 일치도 확인한 국소 구간에만 적용한다.
Ghidra/IDA 정본과 이전 보고서·참조 입력은 변경하지 않았다.
