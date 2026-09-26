F00D52F8: 9de3bf98                 save    %sp, -0x68, %sp
F00D52FC: 90100018                 mov     %i0, %o0! id
F00D5300: 133c0505                 sethi   %hi(paPeriodicevents), %o1
F00D5304: d20262c8                 ld      [%o1+%lo(paPeriodicevents)], %o1! SEL
F00D5308: 4000715a                 call    _objc_msgSend
F00D530C: c02a2210                 clrb    [%o0+0x210]
F00D5310: 81c7e008                 ret
F00D5314: 81e80000                 restore
