F0016B10: 9de3bf98                 save    %sp, -0x68, %sp
F0016B14: 40020029                 call    _spltty
F0016B18: 01000000                 nop
F0016B1C: 80a62000                 cmp     %i0, 0
F0016B20: 12800005                 bne     loc_F0016B34
F0016B24: a0100008                 mov     %o0, %l0
F0016B28: 113c042d                 sethi   %hi(aTtrstrt), %o0! "ttrstrt"
F0016B2C: 7ffff991                 call    _panic
F0016B30: 901223f0                 bset    %lo(aTtrstrt), %o0! "ttrstrt"
F0016B34: d0062040                 ld      [%i0+0x40], %o0
F0016B38: d24e2047                 ldsb    [%i0+0x47], %o1
F0016B3C: 900a3ffe                 and     %o0, -2, %o0
F0016B40: d0262040                 st      %o0, [%i0+0x40]
F0016B44: 912a6001                 sll     %o1, 1, %o0
F0016B48: 90020009                 add     %o0, %o1, %o0
F0016B4C: 912a2004                 sll     %o0, 4, %o0
F0016B50: 133c042e921260cc         set     _linesw, %o1
F0016B58: 90020009                 add     %o0, %o1, %o0
F0016B5C: d2022020                 ld      [%o0+0x20], %o1
F0016B60: 9fc24000                 call    %o1
F0016B64: 90100018                 mov     %i0, %o0
F0016B68: 4002006f                 call    _splx
F0016B6C: 90100010                 mov     %l0, %o0
F0016B70: 81c7e008                 ret
F0016B74: 81e80000                 restore
