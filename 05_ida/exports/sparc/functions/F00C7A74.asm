F00C7A74: 9de3bf88                 save    %sp, -0x78, %sp
F00C7A78: 9410001a                 mov     %i2, %o2
F00C7A7C: 9610001b                 mov     %i3, %o3
F00C7A80: 9810001c                 mov     %i4, %o4
F00C7A84: d04e21a8                 ldsb    [%i0+0x1A8], %o0
F00C7A88: 9a10001d                 mov     %i5, %o5
F00C7A8C: 80a22000                 cmp     %o0, 0
F00C7A90: 0280000d                 be      loc_F00C7AC4
F00C7A94: c407a05c                 ld      [%fp+arg_5C], %g2
F00C7A98: 113c0507                 sethi   %hi(stru_F0141F0C.ext), %o0
F00C7A9C: d2022338                 ld      [%o0+%lo(stru_F0141F0C.ext)], %o1
F00C7AA0: f027bff0                 st      %i0, [%fp+var_10]
F00C7AA4: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00C7AA8: d227bff4                 st      %o1, [%fp+var_C]
F00C7AAC: 133c0506                 sethi   %hi(paReadatLengthBu), %o1
F00C7AB0: d20261c0                 ld      [%o1+%lo(paReadatLengthBu)], %o1! SEL
F00C7AB4: 4000a7b2                 call    _objc_msgSendSuper
F00C7AB8: c423a05c                 st      %g2, [%sp+0x78+var_1C]
F00C7ABC: 1080000c                 ba      locret_F00C7AEC
F00C7AC0: b0100008                 mov     %o0, %i0
F00C7AC4: 90100018                 mov     %i0, %o0! id
F00C7AC8: 133c0504                 sethi   %hi(paName), %o1
F00C7ACC: d2026008                 ld      [%o1+%lo(paName)], %o1! SEL
F00C7AD0: 213c03eb                 sethi   %hi(aSReadAttemptWi), %l0! "%s: Read attempt with no valid label\n"
F00C7AD4: 4000a767                 call    _objc_msgSend
F00C7AD8: a01421e8                 bset    %lo(aSReadAttemptWi), %l0! "%s: Read attempt with no valid label\n"
F00C7ADC: 92100008                 mov     %o0, %o1
F00C7AE0: 7ffff985                 call    _IOLog
F00C7AE4: 90100010                 mov     %l0, %o0
F00C7AE8: b0103d3e                 mov     -0x2C2, %i0
F00C7AEC: 81c7e008                 ret
F00C7AF0: 81e80000                 restore
