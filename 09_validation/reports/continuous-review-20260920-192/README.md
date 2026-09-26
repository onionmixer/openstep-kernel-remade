# Open item 1 completion audit — static closure와 미확정 runtime 경계

Open item 1은 아직 완료가 아니다. 171–191차의 원본-byte evidence를 요구별로 대조하면,
exact-prefix exported-body의 indirect transfer·지정 offset writer·selected initializer는 크게
좁혀졌지만, alias/runtime 요구는 해당 static scope보다 넓다.

| 요구 | 확인된 원본 근거 | 완료를 막는 범위 |
|---|---|---|
| page size/shift | direct boot path, unique absolute writers, conditional 8192/13 | computed/non-export writer, runtime execution·reinitialization |
| page template | common-section writer transform, 48-byte copy, static caller gap | loader/common state, computed writer, copy reachability/lifetime |
| object `+0x30` | object-prefix explicit writer 1, copy coverage/direct construction | alias/bulk/non-export writer, live object value/lifetime |
| map entry WORD `+0x28` | map-prefix 15 exact writers, direct allocation root tree | alias/bulk/non-export writer, indirect caller, runtime entry state |
| pmap table/initializer | four prefix indirect transfers source-resolved, derived globals | differently named/non-export path, overwrite/lifetime |
| object callback table | 43-cell setter/reset and reader precondition | input byte source, caller guards, runtime table mutation/callback lifetime |

따라서 prefix-operand inventory의 “closure”를 binary-wide alias closure나 actual runtime lifetime
proof로 승격할 수 없다. 이 보고서는 완료 선언이 아니라, 다음 분석이 computed pointer,
non-export code와 runtime state boundary에 집중해야 한다는 completion-audit 결과다.

machine-readable evidence matrix는 [open-item1-completion-audit.json](open-item1-completion-audit.json)에 있다.
