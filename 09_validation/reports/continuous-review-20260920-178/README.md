# map-entry WORD `+0x28` initialization guard `map+0x2c`의 writer 경계

Entry WORD `+0x28` zero store가 조건부라는 기존 사실을 map-side guard value까지 연결했다.
원본에서 name이 `_vm_map` 또는 `__vm_map`으로 시작하는 27개 body(15,583 bytes, 5,635
instructions)를 decode하고 explicit `dword [register+0x2c]` write operand를 검사했다. 이
선택 범위의 writer는 네 개뿐이며 `_vm_map_create`의 `1` store 하나와 `_vm_map_fork`의
`1`, `1`, `0` store 세 개다.

`_vm_map_create`는 zone allocation의 EAX를 EBX에 놓은 뒤 `0x001746f0 MOV [EBX+0x2c],1`을
수행한다. `_vm_map_fork`도 자체 allocation 결과 EBX에 두 번 `+0x2c=1`을 기록하지만, 두
번째 construction path에서는 이어 `0x00177c33 MOV [EBX+0x2c],0`을 실행한다. 따라서 이
label-selected raw construction paths에서는 guard의 직접 값이 0 또는 1임을 확인한다.

두 entry construction site는 guard가 0일 때 `WORD +0x28` initialization block을 모두
건너뛴다.

| site | guard test | nonzero일 때 수행되는 word store |
|---|---|---|
| `0x00174968` | `CMP [EDI+0x2c],0; JE 0x00174989` | `0x00174983 MOV WORD [EAX+0x28],0` |
| `0x00174d92` | `CMP [EDI+0x2c],0; JE 0x00174db3` | `0x00174dad MOV WORD [EAX+0x28],0` |

따라서 entry zero가 모든 construction branch에서 무조건 발생한다는 정적 주장은 성립하지
않는다. `map+0x2c=0` constructor path가 실제로 이 두 site에 도달하는지, skipped entry
word가 allocator/reuse에서 어떤 값을 갖는지, pointer alias writer와 live entry lifetime은
계속 미확정이다. function label은 pointer type의 증거로 사용하지 않았다.

원시 writer·guard·instruction 집계는 [map-entry-word28-guard-provenance.json](map-entry-word28-guard-provenance.json)에 기록했다.
