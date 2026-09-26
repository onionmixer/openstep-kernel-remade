F00D9C24: 9de3bf90                 save    %sp, -0x70, %sp
F00D9C28: d0062128                 ld      [%i0+0x128], %o0! id
F00D9C2C: 133c0505                 sethi   %hi(paChannelbuffera), %o1! SEL
F00D9C30: 40005f10                 call    _objc_msgSend
F00D9C34: d20260f4                 ld      [%o1+%lo(paChannelbuffera)], %o1
F00D9C38: d0268000                 st      %o0, [%i2]
F00D9C3C: d0062128                 ld      [%i0+0x128], %o0! id
F00D9C40: 133c0505                 sethi   %hi(paDescriptorsize), %o1! SEL
F00D9C44: 40005f0b                 call    _objc_msgSend
F00D9C48: d20261a4                 ld      [%o1+%lo(paDescriptorsize)], %o1
F00D9C4C: a0100008                 mov     %o0, %l0
F00D9C50: d0062128                 ld      [%i0+0x128], %o0! id
F00D9C54: 133c0505                 sethi   %hi(paDmacount), %o1! SEL
F00D9C58: 40005f06                 call    _objc_msgSend
F00D9C5C: d20261c4                 ld      [%o1+%lo(paDmacount)], %o1
F00D9C60: 92100008                 mov     %o0, %o1
F00D9C64: 7ffcb227                 call    _umul
F00D9C68: 90100010                 mov     %l0, %o0
F00D9C6C: d026c000                 st      %o0, [%i3]
F00D9C70: 81c7e008                 ret
F00D9C74: 81e80000                 restore
