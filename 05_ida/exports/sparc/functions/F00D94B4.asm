F00D94B4: 9de3bf90                 save    %sp, -0x70, %sp
F00D94B8: d0062128                 ld      [%i0+0x128], %o0! id
F00D94BC: 133c0505                 sethi   %hi(paChannelbuffera), %o1! SEL
F00D94C0: 400060ec                 call    _objc_msgSend
F00D94C4: d20260f4                 ld      [%o1+%lo(paChannelbuffera)], %o1
F00D94C8: d0268000                 st      %o0, [%i2]
F00D94CC: d0062128                 ld      [%i0+0x128], %o0! id
F00D94D0: 133c0505                 sethi   %hi(paDescriptorsize), %o1! SEL
F00D94D4: 400060e7                 call    _objc_msgSend
F00D94D8: d20261a4                 ld      [%o1+%lo(paDescriptorsize)], %o1
F00D94DC: a0100008                 mov     %o0, %l0
F00D94E0: d0062128                 ld      [%i0+0x128], %o0! id
F00D94E4: 133c0505                 sethi   %hi(paDmacount), %o1! SEL
F00D94E8: 400060e2                 call    _objc_msgSend
F00D94EC: d20261c4                 ld      [%o1+%lo(paDmacount)], %o1
F00D94F0: 92100008                 mov     %o0, %o1
F00D94F4: 7ffcb403                 call    _umul
F00D94F8: 90100010                 mov     %l0, %o0
F00D94FC: d026c000                 st      %o0, [%i3]
F00D9500: 81c7e008                 ret
F00D9504: 81e80000                 restore
