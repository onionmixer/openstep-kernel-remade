F00C7BF4: 9de3bf88                 save    %sp, -0x78, %sp
F00C7BF8: 9410001a                 mov     %i2, %o2
F00C7BFC: 9610001b                 mov     %i3, %o3
F00C7C00: 9810001c                 mov     %i4, %o4
F00C7C04: d04e21a8                 ldsb    [%i0+0x1A8], %o0
F00C7C08: 9a10001d                 mov     %i5, %o5
F00C7C0C: 80a22000                 cmp     %o0, 0
F00C7C10: 0280000d                 be      loc_F00C7C44
F00C7C14: c407a05c                 ld      [%fp+arg_5C], %g2
F00C7C18: 113c0507                 sethi   %hi(stru_F0141F0C.ext), %o0
F00C7C1C: d2022338                 ld      [%o0+%lo(stru_F0141F0C.ext)], %o1
F00C7C20: f027bff0                 st      %i0, [%fp+var_10]
F00C7C24: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00C7C28: d227bff4                 st      %o1, [%fp+var_C]
F00C7C2C: 133c0504                 sethi   %hi(paWriteasyncatLe), %o1
F00C7C30: d2026190                 ld      [%o1+%lo(paWriteasyncatLe)], %o1! SEL
F00C7C34: 4000a752                 call    _objc_msgSendSuper
F00C7C38: c423a05c                 st      %g2, [%sp+0x78+var_1C]
F00C7C3C: 1080000c                 ba      locret_F00C7C6C
F00C7C40: b0100008                 mov     %o0, %i0
F00C7C44: 90100018                 mov     %i0, %o0! id
F00C7C48: 133c0504                 sethi   %hi(paName), %o1
F00C7C4C: d2026008                 ld      [%o1+%lo(paName)], %o1! SEL
F00C7C50: 213c03eb                 sethi   %hi(aSWriteAttemptW), %l0! "%s: Write attempt with no valid label\n"
F00C7C54: 4000a707                 call    _objc_msgSend
F00C7C58: a0142210                 bset    %lo(aSWriteAttemptW), %l0! "%s: Write attempt with no valid label\n"
F00C7C5C: 92100008                 mov     %o0, %o1
F00C7C60: 7ffff925                 call    _IOLog
F00C7C64: 90100010                 mov     %l0, %o0
F00C7C68: b0103d3e                 mov     -0x2C2, %i0
F00C7C6C: 81c7e008                 ret
F00C7C70: 81e80000                 restore
