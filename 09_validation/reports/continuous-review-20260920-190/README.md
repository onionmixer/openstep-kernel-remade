# 정확한 VM-object prefix의 `dword +0x30` explicit/copy writer closure

Object `+0x30`을 정확한 `_vm_object*`/`__vm_object*` prefix body 전체에서 재집계했다.
27 body(5,112 bytes, 1,776 instructions)에 exact decoded `dword ptr [register+0x30]` write
operand는 하나뿐이며, `_vm_object_collapse` label의 `0x00179a79 MOV [ESI+0x30],0`이다.

명시적 displacement writer와 별도로, `__vm_object_allocate` label의 `ECX=0x16; REP MOVSD`
template copy는 destination `+0x30`을 포함한다. 177차의 full-`__text` direct call inventory는
이 helper의 5개 site와 template `+0x30` clear를 확인했다. 따라서 template-clear와 copy가
실행된 direct construction paths에서는 field가 zero로 시작하며, selected prefix 안의 유일한
명시적 dword writer도 zero store다.

이 결론은 nonzero가 runtime에 불가능하다는 주장이 아니다. bulk-copy source mutation,
arithmetic/pointer alias, non-export/differently named writer, indirect helper caller, actual
initializer execution 및 live object lifetime은 operand-prefix closure로 증명되지 않는다.

전체 집계와 copy relation은 [vm-object-field30-writer-closure.json](vm-object-field30-writer-closure.json)에 기록했다.
