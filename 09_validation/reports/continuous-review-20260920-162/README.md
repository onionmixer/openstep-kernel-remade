# `_vm_object_collapse` direct caller EAX 경계

Object `+0x30` clear를 포함하는 export label상 `_vm_object_collapse`의 direct
`CALL rel32` caller는 4개다. `_vm_fault` `0x00172b15`, `_vm_object_copy`
`0x00179445`, `_vm_object_coalesce` `0x00179c65`, `_vm_pageout_scan`
`0x00179f45`이다.

각 call 뒤 raw instruction은 EAX를 읽지 않는다. fault는 `INC WORD[EDI+0x44]` 뒤 jump,
object-copy는 `MOV EBX,[ESI+0x1c]; TEST EBX,EBX`, coalesce는 `CMP WORD[ESI+0x18],1`로
간다. pageout-scan은 `INC WORD[EDI+0x44]`와 stack cleanup 뒤 `XOR EAX,EAX`로 즉시
덮어쓴다. 따라서 collapse EAX를 error/rollback status로 직접 분기한다는 증거는 이 네
direct edge에 없다.

이는 clear instruction의 도달 조건, field alias, helper side effect, indirect caller 및
runtime lifetime을 판정하지 않는다.

Clear block의 raw gate도 확인했다. `0x001799b6 CMP WORD[ESI+0x18],1`이 equal일 때만
`0x001799c1 CMP [ESI],ESI` loop에 들어가며, equal branch `0x00179a60`에서 transfer와
clear가 실행된다. `0x00179a60..0x00179a6f`는 ESI `+0x28/+0x2c`를 input object로 옮기고,
그 다음 `0x00179a72/+0x00179a79/+0x00179a80`이 ESI `+0x28/+0x30/+0x34`를 zero로 쓴다.
이것은 local branch predicate와 write ordering일 뿐, pointer type이나 concurrent path의
전체 lifetime 결론은 아니다.
