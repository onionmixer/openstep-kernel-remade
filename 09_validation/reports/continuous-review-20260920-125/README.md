# 125차 연속 검토 — `_vm_map_deallocate` direct caller의 첫 post-call 명령

원본 export가 기록한 `_vm_map_deallocate` direct unconditional call 37개를 모두 원시
명령으로 다시 디코드했다. 각 call 다음 첫 명령의 mnemonic은 `mov` 17개, `lea` 8개,
`cmp` 5개, `add` 3개, `xor` 2개, `jmp` 및 `push` 각 1개다. 첫 post-call 명령이 EAX를
test/compare하는 site는 0개다.

이는 116차의 3-instruction EAX 관측을 첫 명령 전수로 독립 재집계한 것이다. `cmp` 5개는
각각 object memory operand를 비교하며 EAX가 아니다. 이 결과는 caller가 이후에 반환
레지스터를 읽지 않는다는 전체 증명이나 deallocate/helper 내부의 rollback·lock 의미가
아니다.

