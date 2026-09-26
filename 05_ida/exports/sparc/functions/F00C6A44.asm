F00C6A44: 9de3bf80                 save    %sp, -0x80, %sp
F00C6A48: 90100018                 mov     %i0, %o0! id
F00C6A4C: 9410001a                 mov     %i2, %o2
F00C6A50: 9610001b                 mov     %i3, %o3
F00C6A54: 133c0506                 sethi   %hi(paDiskparamcommo), %o1
F00C6A58: d20261c4                 ld      [%o1+%lo(paDiskparamcommo)], %o1! SEL
F00C6A5C: 9807bfec                 add     %fp, var_14, %o4
F00C6A60: f407a05c                 ld      [%fp+arg_5C], %i2
F00C6A64: 4000ab83                 call    _objc_msgSend
F00C6A68: 9a07bfe8                 add     %fp, var_18, %o5
F00C6A6C: 80a22000                 cmp     %o0, 0
F00C6A70: 1280000a                 bne     locret_F00C6A98
F00C6A74: 9810001c                 mov     %i4, %o4
F00C6A78: d0062184                 ld      [%i0+0x184], %o0! id
F00C6A7C: d407bfec                 ld      [%fp+var_14], %o2
F00C6A80: 9a10001d                 mov     %i5, %o5
F00C6A84: d607bfe8                 ld      [%fp+var_18], %o3
F00C6A88: 133c0506                 sethi   %hi(paReadatLengthBu), %o1
F00C6A8C: d20261c0                 ld      [%o1+%lo(paReadatLengthBu)], %o1! SEL
F00C6A90: 4000ab78                 call    _objc_msgSend
F00C6A94: f423a05c                 st      %i2, [%sp+0x80+var_24]
F00C6A98: 81c7e008                 ret
F00C6A9C: 91e80008                 restore %g0, %o0, %o0
