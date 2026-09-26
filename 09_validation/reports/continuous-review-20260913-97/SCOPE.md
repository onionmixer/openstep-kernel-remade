# 97차 범위와 검토 계획

현재 사용자 범위는 OPENSTEP 원본 커널 분석뿐이다. 96차 OPEN_ITEMS의 우선 항목인
PC monitor/state/marker/timer 소비자를 원본에서 추적하고, 해당 수명 계약에 직접 연결된
create/destroy와 callout queue/worker를 함께 확인한다. 외부 소스로 빈 의미를 채우지 않는다.

## 증거와 방법

- 기준은 x86 mk-183.34.4 `03_original/x86/binaries/mach_kernel`과 동일 해시의
  `04_ghidra/exports/x86/full-pass5` ASM/C/함수 본문 메타데이터다.
- Ghidra 스킬의 함수 본문·호출 관계·제어 이전 대조 절차를 기존 export에 적용한다.
  도구가 붙인 C 타입·서명·noreturn 가정은 확정 근거로 사용하지 않는다.
- 원본 Mach-O file mapping으로 각 명령의 실제 바이트를 찾고 Python/Capstone에서
  재디코드한다. 본문 byte union, instruction head/폭, 직접 분기 target을 검사한다.
  간접 CALL은 원본 레지스터/저장 필드의 출처까지만 기록한다.
- 본문 ASM/C를 전체 읽고 critical operand·상태 매핑·콜백 실행 순서를 대조한다.
  계산·주소/폭/개수/마스크·해시는 모두 Python으로 처리한다.
- 이전 보존 목록과 96차 체크포인트·입력을 재해시한다. 현재 범위 밖 경로는
  다시 열지 않으며, 이전 외부 소스 비교를 현재 의미 증거로 승계하지 않는다.
- 새 증거 JSON과 문서를 작성한 다음 원본에서 새로 재계산하고 문서 링크 및
  체크포인트 해시를 재검증한다. 검사 스크립트를 커널 실행/에뮬레이션으로 세지 않는다.

새 독립 계획 교차검토는 수신하지 않았다. `independent_plan_review_received=false`이며
자체 검사 통과를 독립 교차검토 통과로 표기하지 않는다. 새 소스 구현이나 DB 수정은 없다.
이 보고서를 교차검토가 완료된 코딩 계획으로 사용하지 않는다.

## 선택한 본문

PCcreate `0x1a0e48`, PCdestroy `0x1a1040`, PCldt `0x1a10d8`,
PCexception `0x1a13a0`, continuation `0x1a1514`, PCresume `0x1a15c4`,
PCcallMonitor `0x1a1750`, PCbopFA/FC/FD `0x1a18c8/0x1a1918/0x1a1968`,
timer callbacks `0x1a19c8/0x1a19e8`, schedule/deliver/pending/cancel/cancelall
`0x1a1a00/0x1a1aa4/0x1a1abc/0x1a1ad4/0x1a1af8`,
thread_user_state `0x18dc54`, thread_exception_return `0x18dec0`,
return_with_state `0x186f04`, calloutDeadlineFromInterval `0x1691e8`,
calloutDispatchDelayed `0x1693ec`, 그 panic 뒤 fragment `0x16943e`,
calloutRemove `0x16957c`, callback worker `0x169cb0`를 포함한다.

선택 본문 밖 callee의 전체 계약, 모든 caller/간접 호출/alias writer, live shared-state
변경, delayed→ready 승격, 초기화 gate, IRQ/SMP·scheduler·descriptor·allocator 동작은
지역 명령 확인만으로 완료 처리하지 않는다. 원본 symbol과 함수 이름은 식별용이며
기대 동작을 이름에서 추정하지 않는다.

## 변경과 비변경

이번 디렉터리에 보고서/증거/보존 해시/체크포인트만 추가한다.
원본 바이너리·Ghidra/IDA DB·기존 export·기존 확정 보고서는 수정하지 않는다.
`01_resources`, `07_kernel`, 다른 kernel 코드·외부 사이트는 참조하지 않는다.
소스 복원·구현·빌드·포팅·커널 실행·새 Python 파일 작성은 하지 않는다.
GCC 2.7 요구는 향후 복원의 조건일 뿐 현재 분석을 구현 단계로 확대하는 권한이 아니다.

자료: [결과](README.md), [증거](object-lifetime-evidence.json),
[미완료 항목](OPEN_ITEMS.md), [C 의미 누락 목록](DECOMPILER_ISSUES.md).
