# 133차 연속 검토 — `_smmap` table-selected callback과 `_vm_object_special`

`_vm_object_special`의 유일한 direct caller는 `_smmap`의 `0x00107007`이다. 그 call의
second argument는 ESI이며, `_vm_object_special`은 `0x0017c215 MOV EDX,[EBP+0xc]` 뒤
`CALL EDX`로 이 값을 callback target으로 사용한다.

`_smmap`은 byte를 읽어 EAX에 두고, `5×` 및 `3×` LEA를 거쳐 EDX를 만들며
`0x00106f65 MOV ESI,[EDX*4+0x001e2f58]`로 target을 선택한다. Python 계산상
index factor 15와 dword scale 4의 곱은 row stride 60 bytes다. 동일한 ESI는
`0x00106fae CALL ESI`로도 직접 호출되며, 이후 `_vm_object_special`에 second
argument로 전달된다.

이는 table base·stride·selected register flow의 원시 사실이다. byte index의 허용 범위,
row 구조체 전체, table writer, callback target의 type/semantic, and runtime reachability는
이 보고서에서 확정하지 않는다.

