F0094DF0: 80928000                 tst     %o2
F0094DF4: 34800004                 bg,a    loc_F0094E04
F0094DF8: 96a20009                 subcc   %o0, %o1, %o3
F0094DFC: 81c3e008                 retl
F0094E00: 01000000                 nop
F0094E04: 2c800002                 bneg,a  loc_F0094E0C
F0094E08: 9620000b                 neg     %o3
F0094E0C: 80a2800b                 cmp     %o2, %o3
F0094E10: 04bfff40                 ble     _bcopy
F0094E14: 80a20009                 cmp     %o0, %o1
F0094E18: 0a80000a                 bcs     loc_F0094E40
F0094E1C: 01000000                 nop
F0094E20: d60a0000                 ldub    [%o0], %o3
F0094E24: 90022001                 inc     %o0
F0094E28: d62a4000                 stb     %o3, [%o1]
F0094E2C: 94a2a001                 deccc   %o2
F0094E30: 14bffffc                 bg      loc_F0094E20
F0094E34: 92026001                 inc     %o1
F0094E38: 81c3e008                 retl
F0094E3C: 01000000                 nop
F0094E40: 94a2a001                 deccc   %o2
F0094E44: d60a000a                 ldub    [%o0+%o2], %o3
F0094E48: 14bffffe                 bg      loc_F0094E40
F0094E4C: d62a400a                 stb     %o3, [%o1+%o2]
F0094E50: 81c3e008                 retl
F0094E54: 01000000                 nop
