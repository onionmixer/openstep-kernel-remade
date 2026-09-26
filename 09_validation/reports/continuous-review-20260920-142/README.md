# 142차 연속 검토 — `_vm_fault_copy_entry` direct COW caller 전수

원본 export에서 `_vm_fault_copy_entry` (`0x0017369c`) direct unconditional caller는 3개다.
`_vm_map_copy_entry` `0x00176876`, `_vm_map_copy` `0x0017767c`, `_vm_map_fork`
`0x00177fe8`가 해당한다. map-copy-entry call은 epilogue/RET로 이어지고, map-copy call은
stack 정리 뒤 loop cleanup target으로 jump하며, map-fork call은 stack 정리 뒤 다음 entry
로 이동한다.

이 edge inventory는 107차의 selected `WORD +0x28` COW copy path를 모든 direct caller로
확장한다. 각 call에 이르는 full branch predicate, helper 내부 page allocation/retry,
EAX return meaning, and indirect callers는 이 보고서에서 확정하지 않는다.

후속 원본 CFG 확인에서 `_vm_map_copy` cleanup target `0x001778cf`는 이 call의 old EAX를
읽지 않는다. entry/local 갱신과 조건부 unwire 뒤 `0x00177933 MOV EAX,[EBX+4]`가 처음
EAX를 덮어쓴다. 따라서 이 direct map-copy edge에서 helper EAX로 rollback을 고른다는
증거는 없다.
