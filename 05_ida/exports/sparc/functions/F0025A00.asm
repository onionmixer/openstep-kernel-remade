F0025A00: 9de3bf98                 save    %sp, -0x68, %sp
F0025A04: 92100019                 mov     %i1, %o1! void *
F0025A08: f206a008                 ld      [%i2+8], %i1
F0025A0C: 80a66000                 cmp     %i1, 0
F0025A10: 02800032                 be      locret_F0025AD8
F0025A14: 90100018                 mov     %i0, %o0
F0025A18: 7fffffe4                 call    _dnlc_lookupSymLink
F0025A1C: 01000000                 nop
F0025A20: b0920000                 orcc    %o0, %g0, %i0
F0025A24: 0280002d                 be      locret_F0025AD8
F0025A28: 01000000                 nop
F0025A2C: d04e2044                 ldsb    [%i0+0x44], %o0
F0025A30: 80a22000                 cmp     %o0, 0
F0025A34: 02800010                 be      loc_F0025A74
F0025A38: 01000000                 nop
F0025A3C: d4562046                 ldsh    [%i0+0x46], %o2! size_t
F0025A40: d006a008                 ld      [%i2+8], %o0
F0025A44: 80a28008                 cmp     %o2, %o0
F0025A48: 32800009                 bne,a   loc_F0025A6C
F0025A4C: d0062040                 ld      [%i0+0x40], %o0
F0025A50: d0068000                 ld      [%i2], %o0! void *
F0025A54: 7fff8142                 call    _bcmp
F0025A58: d2062040                 ld      [%i0+0x40], %o1
F0025A5C: 80a22000                 cmp     %o0, 0
F0025A60: 0280001e                 be      locret_F0025AD8
F0025A64: 01000000                 nop
F0025A68: d0062040                 ld      [%i0+0x40], %o0
F0025A6C: 400109cd                 call    _kfree
F0025A70: d2562046                 ldsh    [%i0+0x46], %o1
F0025A74: 4001097f                 call    _kalloc
F0025A78: 90100019                 mov     %i1, %o0
F0025A7C: 80a22000                 cmp     %o0, 0
F0025A80: 02800016                 be      locret_F0025AD8
F0025A84: d0262040                 st      %o0, [%i0+0x40]
F0025A88: 90102001                 mov     1, %o0
F0025A8C: d02e2044                 stb     %o0, [%i0+0x44]
F0025A90: f2362046                 sth     %i1, [%i0+0x46]
F0025A94: d0068000                 ld      [%i2], %o0! void *
F0025A98: d2062040                 ld      [%i0+0x40], %o1! void *
F0025A9C: 4001bc1d                 call    _bcopy
F0025AA0: 94100019                 mov     %i1, %o2
F0025AA4: d206200c                 ld      [%i0+0xC], %o1
F0025AA8: d0062008                 ld      [%i0+8], %o0
F0025AAC: d0226008                 st      %o0, [%o1+8]
F0025AB0: d2062008                 ld      [%i0+8], %o1
F0025AB4: d006200c                 ld      [%i0+0xC], %o0
F0025AB8: d022600c                 st      %o0, [%o1+0xC]
F0025ABC: 113c04d5                 sethi   %hi(dword_F01355DC), %o0
F0025AC0: d00221dc                 ld      [%o0+%lo(dword_F01355DC)], %o0
F0025AC4: d2022008                 ld      [%o0+8], %o1
F0025AC8: f0222008                 st      %i0, [%o0+8]
F0025ACC: d2262008                 st      %o1, [%i0+8]
F0025AD0: f022600c                 st      %i0, [%o1+0xC]
F0025AD4: d026200c                 st      %o0, [%i0+0xC]
F0025AD8: 81c7e008                 ret
F0025ADC: 81e80000                 restore
