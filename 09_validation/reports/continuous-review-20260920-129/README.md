# 129차 연속 검토 — `_vm_object_shadow` direct caller 경계

원본 export에서 `_vm_object_shadow` (`0x001795a0`)의 direct unconditional caller는 2개다.
`_vm_map_pageable`의 `0x00175f7c` call은 `AND BYTE [EBX+0x18],0xbf`, stack 정리, jump로
이어진다. `_vm_map_lookup`의 `0x001782ed` call은 entry byte 수정 뒤 lock helper call로
진행한다. 두 site 모두 call 직후 EAX를 저장·test·compare하지 않는다.

이는 shadow가 output pointer를 바꾸는 107차 원시 관측을 caller edge까지 확장한 것이다.
두 caller가 전달하는 pointer의 전체 provenance, helper 내부 잠금, shadow allocation failure,
and indirect callers는 이 보고서 범위 밖이다.

