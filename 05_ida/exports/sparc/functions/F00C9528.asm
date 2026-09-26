F00C9528: 9de3bf90                 save    %sp, -0x70, %sp
F00C952C: 9010001a                 mov     %i2, %o0! id
F00C9530: 133c0506                 sethi   %hi(paDelegate), %o1
F00C9534: d2026118                 ld      [%o1+%lo(paDelegate)], %o1! SEL
F00C9538: 4000a0ce                 call    _objc_msgSend
F00C953C: d0262108                 st      %o0, [%i0+0x108]
F00C9540: d0262114                 st      %o0, [%i0+0x114]
F00C9544: 81c7e008                 ret
F00C9548: 81e80000                 restore
