F0025DF8: 9de3bf98                 save    %sp, -0x68, %sp
F0025DFC: d206200c                 ld      [%i0+0xC], %o1
F0025E00: d0062008                 ld      [%i0+8], %o0
F0025E04: d0226008                 st      %o0, [%o1+8]
F0025E08: d2062008                 ld      [%i0+8], %o1
F0025E0C: d006200c                 ld      [%i0+0xC], %o0
F0025E10: d022600c                 st      %o0, [%o1+0xC]
F0025E14: d2060000                 ld      [%i0], %o1
F0025E18: d0062004                 ld      [%i0+4], %o0
F0025E1C: d0226004                 st      %o0, [%o1+4]
F0025E20: d2062004                 ld      [%i0+4], %o1
F0025E24: d0060000                 ld      [%i0], %o0
F0025E28: d0224000                 st      %o0, [%o1]
F0025E2C: 40000b4e                 call    _vn_rele
F0025E30: d0062014                 ld      [%i0+0x14], %o0
F0025E34: d0062010                 ld      [%i0+0x10], %o0
F0025E38: 40000b4b                 call    _vn_rele
F0025E3C: c0262014                 clr     [%i0+0x14]
F0025E40: d006203c                 ld      [%i0+0x3C], %o0
F0025E44: 80a22000                 cmp     %o0, 0
F0025E48: 02800005                 be      loc_F0025E5C
F0025E4C: c0262010                 clr     [%i0+0x10]
F0025E50: 7fffa6f2                 call    _crfree
F0025E54: 01000000                 nop
F0025E58: c026203c                 clr     [%i0+0x3C]
F0025E5C: d04e2044                 ldsb    [%i0+0x44], %o0
F0025E60: 80a22000                 cmp     %o0, 0
F0025E64: 02800008                 be      loc_F0025E84
F0025E68: 113c04d5                 sethi   -0xFECAC00, %o0
F0025E6C: d0062040                 ld      [%i0+0x40], %o0
F0025E70: 400108cc                 call    _kfree
F0025E74: d2562046                 ldsh    [%i0+0x46], %o1
F0025E78: c02e2044                 clrb    [%i0+0x44]
F0025E7C: c0362046                 clrh    [%i0+0x46]
F0025E80: 113c04d5                 sethi   -0xFECAC00, %o0
F0025E84: 901221d0                 bset    0x1D0, %o0
F0025E88: d2022008                 ld      [%o0+8], %o1
F0025E8C: f0222008                 st      %i0, [%o0+8]
F0025E90: d2262008                 st      %o1, [%i0+8]
F0025E94: f022600c                 st      %i0, [%o1+0xC]
F0025E98: d026200c                 st      %o0, [%i0+0xC]
F0025E9C: f0262004                 st      %i0, [%i0+4]
F0025EA0: f0260000                 st      %i0, [%i0]
F0025EA4: 133c04d5921261f0         set     _ncstats, %o1
F0025EAC: d0026020                 ld      [%o1+0x20], %o0
F0025EB0: 90023fff                 inc     -1, %o0
F0025EB4: d0226020                 st      %o0, [%o1+0x20]
F0025EB8: 81c7e008                 ret
F0025EBC: 81e80000                 restore
