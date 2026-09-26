# `_pmap_kgetport` indirect callback과 유일한 direct caller

Open item 1의 pmap-prefix indirect-call 범위를 원본 명령으로 확장했다. Export label상
`_pmap_kgetport` (`0x00135df4`)의 direct `CALL rel32` caller는 하나,
`0x001308c9`뿐이다. Caller는 stack 정리 뒤 `CMP EAX,-1; JE 0x001309ac`와
`CMP EAX,1; JNE 0x001308f8`을 수행한다. 따라서 이 특정 caller는 raw EAX의 두 값을
분기 조건으로 쓴다. 값의 의미는 추정하지 않는다.

Callee는 `0x00135ebc MOV EDX,[ECX]; CALL EDX`와 두 tail call을 가진다.
두 tail chain은 각각 `[EBX] -> [EDX+0x20] -> [ECX+0x10] -> CALL EDX`,
`[EBX+4] -> [EDX+0x10] -> CALL EDX`다. 끝에서 `MOV EAX,[EBP-0x28]`로 caller가
비교한 값을 반환한다.

이 세 target pointer가 table, vtable, object field 중 무엇인지와 writer/lifetime은 이
body의 raw loads만으로 판정할 수 없다. `EBX`도 앞선 direct helper return에서 오므로,
이 보고서는 machine-pmap dispatch나 runtime callback identity를 주장하지 않는다.

상세 명령과 Python assertion은
[pmap-kgetport-callback-flow.json](pmap-kgetport-callback-flow.json)에 있다.
