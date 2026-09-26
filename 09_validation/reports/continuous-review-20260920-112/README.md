# 112차 연속 검토 — map entry `WORD +0x28`의 값 변화와 수명 경계

## 판정

원본 x86 명령으로 map object의 dword `+0x28`과 map entry의 WORD `+0x28`을 분리했다.
`_vm_map_create`는 map pointer에 대해 dword `+0x28=0`, `+0x2c=1`을 기록한다. 반면
`_vm_map_insert`가 얻은 새 entry는 parent map `+0x2c`가 nonzero인 분기에서만 entry
`WORD +0x28=0`을 기록한다. map object `+0x28`은 entry range 크기를 더하고 빼는 dword
연산의 대상이므로 entry word와 같은 필드가 아니다.

`_vm_map_pageable`의 `param_4==0` 경로는 entry word를 AX로 읽어 SI로 옮긴 뒤 `DEC SI`와
store를 수행한다. **감소 전** AX가 1이면 `_vm_fault_unwire(map, entry)`를 호출한다.
반대 경로는 AX를 읽어 `INC SI` 후 store하며, **증가 전** AX가 0인 경우에만 뒤의
object/shadow allocation 분기로 들어간다. 따라서 정적으로 확인된 transition은 0→1,
1→0와 nonzero→nonzero이며, wraparound, concurrent interleaving, 그리고 해당 allocation
분기들의 전체 결과는 이 판정에 포함하지 않는다.

entry를 split하는 같은 함수는 `ECX=0x0b; REP MOVSD`로 11 dword를 새 entry에 복사한다.
Python 산출값으로 복사 범위는 44 bytes이며 `+0x28` word를 포함한다. `_vm_map_entry_unwire`
는 `_vm_fault_unwire` 뒤 word를 0으로 쓰고, `_vm_map_entry_delete`도 nonzero인지 검사한
뒤 helper 호출과 zero store를 수행한다. 따라서 직접 추적한 수명 경계는 conditional
initialization, split-copy, pageable increment/decrement, unwire/delete clear다.

## 원시 명령 검증

Python Capstone x86/32 decode에서 14개 assertion을 검사했다.

- insert zero store: `0x00174983`.
- split copy: `0x00175dcf` (`ECX=0x0b`), `0x00175dd4` (`REP MOVSD`).
- pageable down: `0x00175e3f`..`0x00175e56` (read, decrement, store, old value 1 compare, unwire call).
- pageable up: `0x00175f4b`..`0x00175f57` (read, increment, store, old value zero test).
- unwire/delete clear: `0x00176075`, `0x0017609e`.

세부 기록은 [`map-entry-word28-evidence.json`](map-entry-word28-evidence.json)에 있다.

## 미해결

모든 map-copy/fork alias 및 rollback에서 이 word의 최종 값, `map+0x2c==0`인 모든 실제
생성 경로, lock interleaving과 16-bit overflow 동작은 추가 원시 추적이 필요하다.
