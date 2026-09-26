# 코딩 전/후 독립 Codex 교차검토 — 보고서29

reviewer: `/root/vm_contract_review27`. 검토는 읽기 전용이고, root가 코드를 작성했다.
모든 계산은 Python. Codex의 의견을 독립적인 실행 증거로 사용하지 않는다.

## 코딩 전

PLAN.md가 검증 코드보다 먼저 작성되었다. reviewer는 원본 anonymous lookup miss
→ alloc → zero-fill → new mapping 연결의 조건을 검토했다.

- 데이터 frame의 high direct alias, PT descriptor+extension 필요성: 채택.
  root가 원본 0x17b9a6 → 0x191438 → 0x1019cc 및 0x190f57–0x190f7d를 재확인했다.
- literal low identity mapping이 필요하다는 해석: 채택하지 않음. 높은 DS 아래
  물리주소 offset이 supervisor high alias로 접근된다. reviewer도 이를 정정했다.
- 기존 single private PDE1만으로 PT 통계를 검증하는 계획: 사용하지 않음.
  root가 section-aligned PDE0와 연속 PT pair의 필요성을 확인하고 추가 검토를 받았다.
  Python에서 0x810000/0x811000 및 PTE 0x811800/0x811804 대응을 확인했다.
- report28의 caller lock=1을 fault 진입까지 유지하지 않기: 채택. 원본 init/free
  이후 잠금 해제를 명시적인 fault-preparation 경계로 둔다.
- active root만 user 영역을 비웠으므로 inactive bootstrap low aliases가 남는다는
  지적: 채택. 스캔 결과를 기록하며 전체 root에 high alias만 있다고 쓰지 않는다.
- extension의 descriptor/phys/owner/section/active PT list도 일관되게 구성하기:
  채택. 원본 expand의 store offsets를 root가 읽고 모델을 설정했다. 실제 expand
  실행이나 전체 PT/PV 소유권 검증으로 부르지 않는다.

## 코딩 후

reviewer는 원본 동작 우회나 PT/PV byte 모델과 ASM 사이의 불일치를 발견하지
못했다고 보고했다. 이는 무결성의 보증이 아니며 아래 구체적 누락을 함께 제시했다.

1. 독립 audit의 trace_check가 빈 목록을 허용하여 seed/startup 실행을 생략한
   관찰 자료도 통과할 수 있었다.
2. fault trace 마지막 원소와 실제 fault PC의 결합 검사가 없었다.
3. direct_aliases 목록의 원소는 검사했지만 필수 주소 집합은 검사하지 않았다.

root는 원본 JSON의 메모리 내 복사에서 seed trace 제거, startup trace 제거,
fault terminal head 교체를 각각 수행했고 수정 전 모두 잘못 통과함을 직접
재현했다. 원본/정본/이전 보고서나 정상 JSON을 훼손한 시험이 아니다.

수정: 빈 trace 거절, seed/prefix entry와 정상 error/interrupt/종료 상태 대조,
seed callee-saved 및 stack 대조, fault terminal head 고정, 필수 direct alias
주소 집합 및 PDE/PTE address/권한/물리주소 산술 검사를 추가했다. 추가 음성 대조로
이 사례들을 보존했다. 정상 전체 matrix와 모든 음성 대조를 root가 다시 실행했다.

## 해석 제한

다른 root 보존은 root directory 바이트와 기존 copy buffer 해시 범위다. 공유 high
PT 전체의 CPU A/D 변화를 배제한 전체 주소공간 불변 주장이 아니다. 독립 audit는
기록된 alias walk/전체 root 스캔 결과를 소비하며 다른 backend의 독립 walker가 아니다.
handler의 전체 CPU write 기록 검사는 prefix/seed/CR3 사전 준비에 적용되지 않는다.
사전 준비는 별도 원본 trace/종료/최종 입력 상태 검증 범위다.
