F00D5524: 9de3bf98                 save    %sp, -0x68, %sp
F00D5528: 113c0506                 sethi   %hi(paEventdriver_0), %o0
F00D552C: d00222e0                 ld      [%o0+%lo(paEventdriver_0)], %o0! id
F00D5530: 133c0505                 sethi   %hi(paInstance), %o1! SEL
F00D5534: 400070cf                 call    _objc_msgSend
F00D5538: d2026278                 ld      [%o1+%lo(paInstance)], %o1
F00D553C: 133c0505                 sethi   %hi(paEvcloseToken), %o1
F00D5540: 94100018                 mov     %i0, %o2
F00D5544: d2026358                 ld      [%o1+%lo(paEvcloseToken)], %o1! SEL
F00D5548: 400070ca                 call    _objc_msgSend
F00D554C: 96100019                 mov     %i1, %o3
F00D5550: 81c7e008                 ret
F00D5554: 91e80008                 restore %g0, %o0, %o0
