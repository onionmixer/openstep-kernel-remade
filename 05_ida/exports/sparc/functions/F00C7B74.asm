F00C7B74: 9de3bf88                 save    %sp, -0x78, %sp
F00C7B78: 9410001a                 mov     %i2, %o2
F00C7B7C: 9610001b                 mov     %i3, %o3
F00C7B80: 9810001c                 mov     %i4, %o4
F00C7B84: d04e21a8                 ldsb    [%i0+0x1A8], %o0
F00C7B88: 9a10001d                 mov     %i5, %o5
F00C7B8C: 80a22000                 cmp     %o0, 0
F00C7B90: 0280000d                 be      loc_F00C7BC4
F00C7B94: c407a05c                 ld      [%fp+arg_5C], %g2
F00C7B98: 113c0507                 sethi   %hi(stru_F0141F0C.ext), %o0
F00C7B9C: d2022338                 ld      [%o0+%lo(stru_F0141F0C.ext)], %o1
F00C7BA0: f027bff0                 st      %i0, [%fp+var_10]
F00C7BA4: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00C7BA8: d227bff4                 st      %o1, [%fp+var_C]
F00C7BAC: 133c0506                 sethi   %hi(paWriteatLengthB), %o1
F00C7BB0: d20261b8                 ld      [%o1+%lo(paWriteatLengthB)], %o1! SEL
F00C7BB4: 4000a772                 call    _objc_msgSendSuper
F00C7BB8: c423a05c                 st      %g2, [%sp+0x78+var_1C]
F00C7BBC: 1080000c                 ba      locret_F00C7BEC
F00C7BC0: b0100008                 mov     %o0, %i0
F00C7BC4: 90100018                 mov     %i0, %o0! id
F00C7BC8: 133c0504                 sethi   %hi(paName), %o1
F00C7BCC: d2026008                 ld      [%o1+%lo(paName)], %o1! SEL
F00C7BD0: 213c03eb                 sethi   %hi(aSWriteAttemptW), %l0! "%s: Write attempt with no valid label\n"
F00C7BD4: 4000a727                 call    _objc_msgSend
F00C7BD8: a0142210                 bset    %lo(aSWriteAttemptW), %l0! "%s: Write attempt with no valid label\n"
F00C7BDC: 92100008                 mov     %o0, %o1
F00C7BE0: 7ffff945                 call    _IOLog
F00C7BE4: 90100010                 mov     %l0, %o0
F00C7BE8: b0103d3e                 mov     -0x2C2, %i0
F00C7BEC: 81c7e008                 ret
F00C7BF0: 81e80000                 restore
