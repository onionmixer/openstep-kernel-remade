# 132차 연속 검토 — OPEN_ITEMS 1·2 완료 감사표

## 판정

`OPEN_ITEMS.md`의 1·2번은 아직 **in progress**다. 아래 표는 완료 주장이 아니라, 원본
명령으로 확인한 범위와 완료에 필요한 미확인 범위를 분리한다.

| 항목 | 현재 원본 증거 | 완료를 막는 미확인 범위 |
|---|---|---|
| 1: page init | page size/mask/shift absolute writer 전수, 48-byte template copy 및 static writer | computed store, 함수 밖 code, runtime 도달·재초기화 |
| 1: object `+0x30` | template `+0x30` clear와 object-prefix relative writer 1개 | prefix 밖 alias, pointer provenance, runtime lifetime |
| 1: map entry word `+0x28` | map-prefix word-width access 34개와 writer 15개 | outside-prefix alias, computed address, runtime reachability |
| 1: indirect/table/pmap | selected VM family indirect-call inventory, vnode slots와 static writer 경계, pmap PV retry | indirect jump, callback writer, table object lifetime |
| 2: COW/shadow | object-copy/shadow direct caller inventory, copy status cleanup | allocation/pager helper 내부 경로, indirect callers |
| 2: pager/PV | vnode dispatch and PV retry raw paths | all pager-record writers and runtime table choice |
| 2: `vm_fault` | direct caller 5개 및 EAX 흐름 | indirect caller, trap/helper recovery 전체 |
| 2: copy/fork/deallocate | map-copy caller 13개, fork caller 1개, deallocate caller 37개, selected cleanup order | caller-local lock/rollback의 전 경로와 computed callers |

다음 원시 분석은 이 표의 미확인 범위를 직접 줄여야 하며, 현재 증거만으로 1·2번 완료를
선언하지 않는다.

