F00BC974: 9de3bf88                 save    %sp, -0x78, %sp
F00BC978: d2062114                 ld      [%i0+0x114], %o1
F00BC97C: 113c04bb                 sethi   %hi(_sparcfbs), %o0
F00BC980: 80a26003                 cmp     %o1, 3
F00BC984: 02800005                 be      loc_F00BC998
F00BC988: e0022364                 ld      [%o0+%lo(_sparcfbs)], %l0
F00BC98C: 80a26002                 cmp     %o1, 2
F00BC990: 02800004                 be      loc_F00BC9A0
F00BC994: 313c047f                 sethi   -0xFEE0400, %i0
F00BC998: 10800032                 ba      locret_F00BCA60
F00BC99C: b0102010                 mov     0x10, %i0
F00BC9A0: d0062284                 ld      [%i0+0x284], %o0
F00BC9A4: 80a22000                 cmp     %o0, 0
F00BC9A8: 12800007                 bne     loc_F00BC9C4
F00BC9AC: 90102000                 mov     0, %o0
F00BC9B0: 13001999                 sethi   0x666400, %o1
F00BC9B4: 4000a32c                 call    _sparcfbClearDisplay
F00BC9B8: 92126266                 bset    0x266, %o1
F00BC9BC: 90102001                 mov     1, %o0
F00BC9C0: d0262284                 st      %o0, [%i0+0x284]
F00BC9C4: d0042028                 ld      [%l0+0x28], %o0
F00BC9C8: 90023b94                 inc     -0x46C, %o0
F00BC9CC: 9332201f                 srl     %o0, 31, %o1
F00BC9D0: 90020009                 add     %o0, %o1, %o0
F00BC9D4: d2168000                 lduh    [%i2], %o1
F00BC9D8: 913a2001                 sra     %o0, 1, %o0
F00BC9DC: 92024008                 add     %o1, %o0, %o1
F00BC9E0: d2368000                 sth     %o1, [%i2]
F00BC9E4: d004202c                 ld      [%l0+0x2C], %o0
F00BC9E8: 90023cc0                 inc     -0x340, %o0
F00BC9EC: 9332201f                 srl     %o0, 31, %o1
F00BC9F0: 90020009                 add     %o0, %o1, %o0
F00BC9F4: d216a002                 lduh    [%i2+2], %o1
F00BC9F8: 913a2001                 sra     %o0, 1, %o0
F00BC9FC: 92024008                 add     %o1, %o0, %o1
F00BCA00: d236a002                 sth     %o1, [%i2+2]
F00BCA04: 1100003f                 sethi   0xFC00, %o0
F00BCA08: d2168000                 lduh    [%i2], %o1
F00BCA0C: 901223fc                 bset    0x3FC, %o0
F00BCA10: 920a4008                 and     %o1, %o0, %o1
F00BCA14: d016a004                 lduh    [%i2+4], %o0
F00BCA18: d2368000                 sth     %o1, [%i2]
F00BCA1C: d2168000                 lduh    [%i2], %o1
F00BCA20: 90022003                 inc     3, %o0
F00BCA24: 900a3ffc                 and     %o0, -4, %o0
F00BCA28: d036a004                 sth     %o0, [%i2+4]
F00BCA2C: d237bfe8                 sth     %o1, [%fp+var_18]
F00BCA30: d016a002                 lduh    [%i2+2], %o0
F00BCA34: d037bfea                 sth     %o0, [%fp+var_16]
F00BCA38: d216a004                 lduh    [%i2+4], %o1
F00BCA3C: 90102000                 mov     0, %o0
F00BCA40: d237bfec                 sth     %o1, [%fp+var_14]
F00BCA44: d416a006                 lduh    [%i2+6], %o2
F00BCA48: 9207bfe8                 add     %fp, var_18, %o1
F00BCA4C: d437bfee                 sth     %o2, [%fp+var_12]
F00BCA50: d606a008                 ld      [%i2+8], %o3
F00BCA54: 4000a3e9                 call    _sparcfbDrawRect
F00BCA58: 94102002                 mov     2, %o2
F00BCA5C: b0102000                 mov     0, %i0
F00BCA60: 81c7e008                 ret
F00BCA64: 81e80000                 restore
