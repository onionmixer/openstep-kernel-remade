# 신중한 추가 검토27 — VM 미검증 분기의 원본 근거와 반환 계약

## 판정

원본 vm_fault/pmap_enter와 pager dispatch/PT 확장 helper의 함수 본문 전체를
원본 바이트와 대조하고, 직접 호출·분기 방향·복귀 지점 색인을 작성했다.
기존 report26 실행이 지나지 않은 경로와 후속 시험의 선행조건을 구체화했다.
**새 커널 실행 시험, pager I/O, 할당 성공의 검증은 아니다.**

새로 명확히 한 복원상의 주의점:

- vm_fault의 일부 대기 중단 경로는 매핑 없이 0을 반환한다. 반환값만으로
  fault 명령 재실행 성공을 판정하면 안 된다.
- page_lock 충돌은 이 원본에서 정리 후 EAX=10을 반환한다. NeXTMach 108.1의
  pager unlock/wait 코드를 그대로 가져오면 동작이 달라진다.
- 원본 vm_fault는 다섯 번째 error 인자를 pager에 전달한다. 정본 listing의
  직접 호출자는 모두 이 인자에 0을 넣지만, 간접 호출자의 부재까지 증명하지 않는다.
- PT 확장 실패는 pmap_enter에서 직접 오류 반환으로 전달되지 않는다. 호출자는
  PDE를 다시 검사한다. PV 할당 뒤에도 전체 해당 경로를 재검사한다.

주소·조건·공개 소스의 일치/불일치와 필요한 후속 상태는 [VM 계약](VM_CONTRACTS.md)에
기록했다. 해당 문서는 중요한 분기의 정적 계약이며 모든 함수 경로의 의미 증명은 아니다.

## 원본 본문과 report26 관찰의 차이

| 함수/정본 진입점 | 본문 명령 head | report26 관찰 head | 조건 분기 방향 | report26 관찰 방향 |
|---|---:|---:|---:|---:|
| vm_fault | 1,853 | 202 | 472 | 35 |
| pmap_enter | 372 | 131 | 86 | 22 |
| vm_pager_get | 26 | 0 | 4 | 0 |
| FUN_00190cfc (pmap_expand 해석) | 167 | 0 | 22 | 0 |

모든 집계는 Python이다. 분모는 선택한 정본 함수 body이며 정렬 padding이나 전체
커널이 아니다. 조건 분기의 방향은 정적으로 가능한 target/fallthrough 목록일 뿐,
데이터 조건상 실행 가능한 방향의 수나 분석 완료율이 아니다. report26의 handler
trace만 비교했으며 이전 보고서 전체의 누적 관찰을 대신하지 않는다.

호출자/피호출자의 관계를 잃지 않도록 각 case의 **완전한 trace에서 바로 다음
head**를 읽어 관찰 방향을 판정했다. 함수 밖 명령을 먼저 걸러 내거나 여러 case를
이어 붙여 가짜 edge를 만들지 않는다. call 뒤의 continuation은 피호출자 복귀를
가정한 정적 관계로 분리하며, 직접 관찰된 분기 방향으로 세지 않는다.

vm_fault와 expand helper에 있는 panic 호출 뒤의 가정상 continuation 일부는
정본 body 밖이다. 이를 본문 누락이나 정상 복귀로 단정하지 않고 별도 unresolved
edge로 기록했다. 해당 가정상 continuation이 실행 가능하다는 증거는 없다.

## 검증 범위와 한계

- 원본 Mach-O를 직접 읽어 기준 해시를 확인하고 명령 길이·mnemonic·직접 분기
  목적지를 정본 ASM과 대조했다. body의 누락·중복 및 전 명령의 원본 바이트를 검사했다.
- 별도 audit는 생성기를 import하지 않는다. 직접 상대 분기 목적지를 Python의
  signed displacement로 계산하여 decoder의 목적지 해석과 독립적으로 대조했다.
- 모든 non-control operand 문자열의 동치까지 자동 증명하지는 않는다. 핵심
  반환 상수·필드 오프셋·PTE/PDE store·인자 전달은 원본 operand로 추가 검사했다.
- 직접 vm_fault 호출의 인자 준비 구간을 별도로 대조했다. 예외 caller의
  protection 선택 분기가 PUSH를 건너뛰지 않는지도 검사했다.
- 누락/중복 명령, 잘못된 길이·mnemonic·분기 목적지, body 중복, 불법 관찰 edge,
  잘린 trace, 잘못된 call target, case 간 가짜 연결을 거절하는 음성 대조를 실행했다.
- 이 검산은 정적 색인/기존 관찰의 독립 계산이다. 다른 CPU backend나 실제
  하드웨어의 새 실행, 동시성, scheduler, pager의 정확성을 대신하지 않는다.

[코딩 전 계획](PLAN.md)과 [교차검토 기록](CROSS_REVIEW.md)을 보존한다.
Ghidra 스킬에 따라 원본 사실·해석·공개 소스·관찰·미검증 조건을 구분했다.
정본 DB를 열거나 교정하지 않고 기존 export를 읽었다. 모든 계산은 Python이다.

## 재현과 산출물

```sh
python3 -B 09_validation/reports/continuous-review-20260911-27/branch_inventory.py
python3 -B 09_validation/reports/continuous-review-20260911-27/audit_results.py
python3 -B 09_validation/reports/continuous-review-20260911-27/test_inventory.py
python3 -B 09_validation/reports/continuous-review-20260911-27/reproduce_results.py
python3 -B 09_validation/reports/continuous-review-20260911-27/verify_artifacts.py
```

[전체 명령/분기 색인](branch-inventory.json), [제어 이전 색인](transfer-index.json),
[집계](inventory-summary.json), [직접 호출 인자](caller-contracts.json),
[독립 검산](independent-audit.json), [음성 대조](negative-controls.json),
[재현 해시](reproducibility.json), [실행 전 보존](preservation-before.json),
[실행 후 보존](preservation-after.json), [입력 해시](input-hashes.json),
[최종 검증](verification.json), [산출물 해시](artifact-hashes.json), [잔여 분석](OPEN_ITEMS.md).

기존 원본·reference sources·Ghidra/IDA DB·이전 보고서 및 07_kernel은 보존한다.
전체 분석·GCC 2.7 구현/빌드/부팅·후속 아키텍처의 미완료 상태를 유지한다.
