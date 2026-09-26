F00D9C78: 9de3bf90                 save    %sp, -0x70, %sp
F00D9C7C: d006212c                 ld      [%i0+0x12C], %o0! id
F00D9C80: 133c0505                 sethi   %hi(paChannelbuffera), %o1! SEL
F00D9C84: 40005efb                 call    _objc_msgSend
F00D9C88: d20260f4                 ld      [%o1+%lo(paChannelbuffera)], %o1
F00D9C8C: d0268000                 st      %o0, [%i2]
F00D9C90: d006212c                 ld      [%i0+0x12C], %o0! id
F00D9C94: 133c0505                 sethi   %hi(paDescriptorsize), %o1! SEL
F00D9C98: 40005ef6                 call    _objc_msgSend
F00D9C9C: d20261a4                 ld      [%o1+%lo(paDescriptorsize)], %o1
F00D9CA0: a0100008                 mov     %o0, %l0
F00D9CA4: d006212c                 ld      [%i0+0x12C], %o0! id
F00D9CA8: 133c0505                 sethi   %hi(paDmacount), %o1! SEL
F00D9CAC: 40005ef1                 call    _objc_msgSend
F00D9CB0: d20261c4                 ld      [%o1+%lo(paDmacount)], %o1
F00D9CB4: 92100008                 mov     %o0, %o1
F00D9CB8: 7ffcb212                 call    _umul
F00D9CBC: 90100010                 mov     %l0, %o0
F00D9CC0: d026c000                 st      %o0, [%i3]
F00D9CC4: 81c7e008                 ret
F00D9CC8: 81e80000                 restore
