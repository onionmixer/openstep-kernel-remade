F008D520: 9de3bf90                 save    %sp, -0x70, %sp
F008D524: 9010001a                 mov     %i2, %o0! id
F008D528: d406201c                 ld      [%i0+0x1C], %o2
F008D52C: 133c0503                 sethi   %hi(paFree), %o1
F008D530: d20263fc                 ld      [%o1+%lo(paFree)], %o1! SEL
F008D534: 9402bfff                 inc     -1, %o2
F008D538: 400190ce                 call    _objc_msgSend
F008D53C: d426201c                 st      %o2, [%i0+0x1C]
F008D540: 81c7e008                 ret
F008D544: 91e80008                 restore %g0, %o0, %o0
