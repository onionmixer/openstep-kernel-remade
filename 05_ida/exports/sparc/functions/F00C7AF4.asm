F00C7AF4: 9de3bf88                 save    %sp, -0x78, %sp
F00C7AF8: 9410001a                 mov     %i2, %o2
F00C7AFC: 9610001b                 mov     %i3, %o3
F00C7B00: 9810001c                 mov     %i4, %o4
F00C7B04: d04e21a8                 ldsb    [%i0+0x1A8], %o0
F00C7B08: 9a10001d                 mov     %i5, %o5
F00C7B0C: 80a22000                 cmp     %o0, 0
F00C7B10: 0280000d                 be      loc_F00C7B44
F00C7B14: c407a05c                 ld      [%fp+arg_5C], %g2
F00C7B18: 113c0507                 sethi   %hi(stru_F0141F0C.ext), %o0
F00C7B1C: d2022338                 ld      [%o0+%lo(stru_F0141F0C.ext)], %o1
F00C7B20: f027bff0                 st      %i0, [%fp+var_10]
F00C7B24: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00C7B28: d227bff4                 st      %o1, [%fp+var_C]
F00C7B2C: 133c0504                 sethi   %hi(paReadasyncatLen), %o1
F00C7B30: d202618c                 ld      [%o1+%lo(paReadasyncatLen)], %o1! SEL
F00C7B34: 4000a792                 call    _objc_msgSendSuper
F00C7B38: c423a05c                 st      %g2, [%sp+0x78+var_1C]
F00C7B3C: 1080000c                 ba      locret_F00C7B6C
F00C7B40: b0100008                 mov     %o0, %i0
F00C7B44: 90100018                 mov     %i0, %o0! id
F00C7B48: 133c0504                 sethi   %hi(paName), %o1
F00C7B4C: d2026008                 ld      [%o1+%lo(paName)], %o1! SEL
F00C7B50: 213c03eb                 sethi   %hi(aSReadAttemptWi), %l0! "%s: Read attempt with no valid label\n"
F00C7B54: 4000a747                 call    _objc_msgSend
F00C7B58: a01421e8                 bset    %lo(aSReadAttemptWi), %l0! "%s: Read attempt with no valid label\n"
F00C7B5C: 92100008                 mov     %o0, %o1
F00C7B60: 7ffff965                 call    _IOLog
F00C7B64: 90100010                 mov     %l0, %o0
F00C7B68: b0103d3e                 mov     -0x2C2, %i0
F00C7B6C: 81c7e008                 ret
F00C7B70: 81e80000                 restore
