# 120차 연속 검토 — page/object/map/pmap 함수군의 간접 call 인벤토리

## 판정

원본 export에서 이름이 `_vm_page`/`__vm_page`, `_vm_object`/`__vm_object`,
`_vm_map`/`__vm_map`, `_pmap`으로 시작하는 함수 113개의 모든 body fragment를 Python
Capstone으로 다시 디코드했다. 직접 절대주소 call을 제외한 register/memory operand call은
4개다. page 24개와 map 27개에는 0개, object 27개에는 1개, `_pmap` 35개에는 3개다.

`_vm_object_special`의 유일한 site `0x0017c218 CALL EDX`는 바로 앞
`0x0017c215 MOV EDX,[EBP+0xc]`에서 target을 받는다. 이 관측 범위에는 그 target을
채우는 주소 table 또는 writer가 없으므로, 콜백 인수라는 레지스터 흐름만 확정한다.

`_pmap_kgetport`의 세 site는 각각 메모리 load 사슬 끝의 EDX를 호출한다.
`0x00135ebe`는 `[EBX+4]`를 ECX로 읽고 `[ECX]`를 EDX로 읽은 뒤 호출한다.
`0x00135ef5`는 `[EBX] -> [EDX+0x20] -> [ECX+0x10]`, `0x00135efe`는
`[EBX+4] -> [EDX+0x10]`을 거쳐 EDX를 호출한다. 이 메모리 형상을 특정 table·vtable의
타입으로 번역하지 않는다.

주소 `0x0018ec70`부터 `0x00191810`까지의 연속 `_pmap` 함수 경계 34개도 별도 집계했다.
이 machine-pmap address window의 간접 call 수는 0이다. 따라서 위 세 `_pmap_kgetport`
site를 machine pmap dispatch로 일반화할 근거는 없다.

## 한계

함수 이름은 export label이며, prefix 기반 인벤토리는 이름이 다른 VM helper나 indirect
jump를 포함하지 않는다. 콜백 인수의 모든 writer, memory-table의 전 생명주기, 그리고
page/object/map/pmap 밖 dispatch는 계속 미해결이다.

