F00D9460: 9de3bf90                 save    %sp, -0x70, %sp
F00D9464: d006212c                 ld      [%i0+0x12C], %o0! id
F00D9468: 133c0505                 sethi   %hi(paChannelbuffera), %o1! SEL
F00D946C: 40006101                 call    _objc_msgSend
F00D9470: d20260f4                 ld      [%o1+%lo(paChannelbuffera)], %o1
F00D9474: d0268000                 st      %o0, [%i2]
F00D9478: d006212c                 ld      [%i0+0x12C], %o0! id
F00D947C: 133c0505                 sethi   %hi(paDescriptorsize), %o1! SEL
F00D9480: 400060fc                 call    _objc_msgSend
F00D9484: d20261a4                 ld      [%o1+%lo(paDescriptorsize)], %o1
F00D9488: a0100008                 mov     %o0, %l0
F00D948C: d006212c                 ld      [%i0+0x12C], %o0! id
F00D9490: 133c0505                 sethi   %hi(paDmacount), %o1! SEL
F00D9494: 400060f7                 call    _objc_msgSend
F00D9498: d20261c4                 ld      [%o1+%lo(paDmacount)], %o1
F00D949C: 92100008                 mov     %o0, %o1
F00D94A0: 7ffcb418                 call    _umul
F00D94A4: 90100010                 mov     %l0, %o0
F00D94A8: d026c000                 st      %o0, [%i3]
F00D94AC: 81c7e008                 ret
F00D94B0: 81e80000                 restore
