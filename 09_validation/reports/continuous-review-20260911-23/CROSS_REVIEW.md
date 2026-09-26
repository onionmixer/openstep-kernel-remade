# Codex 교차검토 및 주 에이전트 재확인

## 코딩 전

독립 Codex `/root/copyout_plan_review`는 원본 및 기존 보고서를 읽기 전용으로
검토했다. 새 코드나 에뮬레이션을 작성·실행하지 않았다. 주 에이전트도 원본
`00189cec.asm`, `00189e8c.asm`과 report22 fixture를 직접 읽었다.

핵심 지적은 tail의 offset 2→1→0 쓰기 순서, caller/local destination 슬롯 차이,
정렬 dword 비실행 경로, paging fault와 실제 trap 복구의 구분이었다.
source를 dword 정렬한 fault 사례와 fresh fixture의 PTE 변경 조건을 확정한 뒤
PLAN.md를 작성하고 코딩을 시작했다.

## 사후 읽기 전용 검토

독립 검토자는 JSON과 원본을 다시 대조했다. 다음 의견은 주 에이전트가
Python 재계산 및 코드 검사로 다시 확인했다.

- 이번 backend에서 FS store의 memory-write hook 주소는 물리 주소로 관찰된다.
  주 에이전트의 독립 JSON 검사도 주소를 물리 변환한 뒤 정상 기록의 불일치가
  없음을 확인했다. 이후 코드에 PC·주소·폭·값·순서 비교를 넣어 재실행했다.
- fault의 마지막 pending store에는 이번 관찰에서 hook이 없었다. 그러나 hook
  부재 자체를 commit 증명으로 채택하지 않았다. 실제 backing 버퍼, 원본 store
  operand replay 및 독립 예상 부분 쓰기를 모두 검사한다.
- canonical C도 tail 순서를 보존한다. 주 에이전트가 두 C의 offset2 store,
  offset1 label로의 goto, 마지막 offset0 store를 직접 확인했다. 새로운 tail
  디컴파일 누락으로 보고하지 않는다.
- 최초 코드는 caller 인자를 기록만 했다. 주 에이전트가 원본 `189dbe/189e29`
  및 msg의 local 대응 명령을 다시 읽고 정렬 prefix와 tail 진입 조건을 Python으로
  모델링해 재실행 assertion에 추가했다. 관찰값만 남긴 것을 검증 완료로 부르지 않았다.
- PF error-code 비트는 수집하지 않았다. vector14·EIP·CR2와 PTE/WP 통제 조건만
  검증한 것으로 한계를 명시했다.

Codex 의견이나 모델 간 동의를 정확성의 근거로 사용하지 않았다. 최종 채택 근거는
원본 명령, 입력 매핑, Python 예상 상태, 실행 결과 및 재현성 검사이다.
