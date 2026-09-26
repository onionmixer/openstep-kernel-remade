# 정확한 VM/pmap prefix body의 indirect transfer closure

이전의 name-substring inventory는 vnode·IPC·DriverKit 등의 이름 충돌을 포함했다. 이번에는
정확한 `_vm_page*`, `_vm_object*`, `__vm_object*`, `_vm_map*`, `__vm_map*`, `_pmap*`
prefix만 선택해 원본 body를 다시 decode했다. 113개 body, 34,110 bytes, 11,835 instructions에서
register/memory operand를 목표로 하는 `CALL`/`JMP`는 5개다.

| prefix family | bodies | indirect transfer |
|---|---:|---:|
| page | 24 | 0 |
| object | 27 | 1 (`0x0017c218 CALL EDX`) |
| map | 27 | 0 |
| pmap | 35 | 4 |

object site는 176차에서 callee-local table load가 아닌 second stack argument callback임을
확인했고, sole direct caller가 table-derived pointer를 전달한다. pmap의 세 `CALL EDX`는
171차의 allocation/static-`__DATA` chain, indexed `JMP`는 174차의 8-cell `__text` table로
각각 연결된다. 따라서 이 exact-prefix exported-body scope에서 원시 target source가 전혀
기록되지 않은 indirect transfer는 남지 않는다.

이는 alias/type closure가 아니다. object callback의 runtime target value, table overwrite,
indirect/computed caller, non-export code 및 다른 이름을 가진 VM-adjacent function은 이 scope
밖이다. 또한 raw transfer target이 API type·ABI·lifetime을 증명하지 않는다.

집계·site·기존 evidence 연결은 [vm-prefix-indirect-transfer-closure.json](vm-prefix-indirect-transfer-closure.json)에 기록했다.
