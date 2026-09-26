F00C6AA0: 9de3bf80                 save    %sp, -0x80, %sp
F00C6AA4: 90100018                 mov     %i0, %o0! id
F00C6AA8: 9410001a                 mov     %i2, %o2
F00C6AAC: 9610001b                 mov     %i3, %o3
F00C6AB0: 133c0506                 sethi   %hi(paDiskparamcommo), %o1
F00C6AB4: d20261c4                 ld      [%o1+%lo(paDiskparamcommo)], %o1! SEL
F00C6AB8: 9807bfec                 add     %fp, var_14, %o4
F00C6ABC: f407a05c                 ld      [%fp+arg_5C], %i2
F00C6AC0: 4000ab6c                 call    _objc_msgSend
F00C6AC4: 9a07bfe8                 add     %fp, var_18, %o5
F00C6AC8: 80a22000                 cmp     %o0, 0
F00C6ACC: 1280000a                 bne     locret_F00C6AF4
F00C6AD0: 9810001c                 mov     %i4, %o4
F00C6AD4: d0062184                 ld      [%i0+0x184], %o0! id
F00C6AD8: d407bfec                 ld      [%fp+var_14], %o2
F00C6ADC: 9a10001d                 mov     %i5, %o5
F00C6AE0: d607bfe8                 ld      [%fp+var_18], %o3
F00C6AE4: 133c0504                 sethi   %hi(paReadasyncatLen), %o1
F00C6AE8: d202618c                 ld      [%o1+%lo(paReadasyncatLen)], %o1! SEL
F00C6AEC: 4000ab61                 call    _objc_msgSend
F00C6AF0: f423a05c                 st      %i2, [%sp+0x80+var_24]
F00C6AF4: 81c7e008                 ret
F00C6AF8: 91e80008                 restore %g0, %o0, %o0
