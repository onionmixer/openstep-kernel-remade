# `_vm_object_special` label의 callback parameter와 sole direct caller

Object-name 표본에 남았던 `0x0017c218 CALL EDX`를 raw dataflow로 분리했다. export label상
`_vm_object_special`인 callee는 `0x0017c215 MOV EDX,[EBP+0x0c]` 후 EDX를 call한다. 즉
이 indirect target은 static table을 자체 load한 값이 아니라 두 번째 stack argument다.

원본 `__text` 전체의 `E8 rel32` target을 Python으로 재계산하면 이 callee entry
`0x0017c17c`의 direct site는 `0x00107007` 하나다. 그 caller (`_smmap` label hypothesis)는
`0x00106f65 MOV ESI,[EDX*4+0x001e2f58]`에서 ESI를 얻어 `0x00107001 PUSH ESI`로 해당
두 번째 argument를 전달한다. 이 instruction 전에 EDX는 zero-extended byte value의 11배로
계산되므로 static address formula는 `0x001e2f58 + 44 * byte_value`다.

caller는 ESI가 zero, `0x0010ccb0`, `0x0010cca4` 중 하나이면 `0x0010719e`로 건너뛰고,
그 외 값일 때에만 `_vm_object_special` call을 준비한다. 같은 ESI는 더 앞선
`0x00106fae CALL ESI`의 target이기도 하다. callee 내부는 loop마다 callback EAX를 page-shift
만큼 왼쪽으로 shift해 local allocation record에 기록한다. 이들은 raw register/argument
flow 사실이며 callback의 type, table structure name, valid byte range, table writer, callback
success 또는 allocation lifetime을 의미하지 않는다.

이 direct-caller one-site 결과도 indirect/computed caller를 배제하지 않는다. `byte_value`에
명시적 bounds check가 보이지 않아 source value와 table allocation/runtime contents를 확인하지
않고 table의 유효 범위나 actual callback target을 확정할 수 없다.

원시 instruction·target·address formula는 [vm-object-special-callback-provenance.json](vm-object-special-callback-provenance.json)에 기록했다.
