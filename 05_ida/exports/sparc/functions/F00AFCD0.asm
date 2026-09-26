F00AFCD0: 9de3bf98                 save    %sp, -0x68, %sp
F00AFCD4: 113c0470                 sethi   %hi(_obp_romvec_version), %o0
F00AFCD8: d0022278                 ld      [%o0+%lo(_obp_romvec_version)], %o0
F00AFCDC: 80a22000                 cmp     %o0, 0
F00AFCE0: 12800013                 bne     loc_F00AFD2C
F00AFCE4: a0100018                 mov     %i0, %l0
F00AFCE8: 80a66002                 cmp     %i1, 2
F00AFCEC: 04800020                 ble     loc_F00AFD6C
F00AFCF0: 133c000c                 sethi   %hi(_romp), %o1
F00AFCF4: d0026030                 ld      [%o1+%lo(_romp)], %o0
F00AFCF8: d0022080                 ld      [%o0+0x80], %o0
F00AFCFC: d0020000                 ld      [%o0], %o0
F00AFD00: d00a2084                 ldub    [%o0+0x84], %o0
F00AFD04: d02c0000                 stb     %o0, [%l0]
F00AFD08: d0026030                 ld      [%o1+%lo(_romp)], %o0
F00AFD0C: d0022080                 ld      [%o0+0x80], %o0
F00AFD10: d0020000                 ld      [%o0], %o0
F00AFD14: b0102000                 mov     0, %i0
F00AFD18: d00a2085                 ldub    [%o0+0x85], %o0
F00AFD1C: a0042001                 inc     %l0
F00AFD20: d02c0000                 stb     %o0, [%l0]
F00AFD24: 10800013                 ba      locret_F00AFD70
F00AFD28: c02c2001                 clrb    [%l0+1]
F00AFD2C: 7ffffc32                 call    _prom_bootpath
F00AFD30: 01000000                 nop
F00AFD34: 40000c6f                 call    _path_to_devi
F00AFD38: 01000000                 nop
F00AFD3C: 92920000                 orcc    %o0, %g0, %o1
F00AFD40: 0280000b                 be      loc_F00AFD6C
F00AFD44: 80a66002                 cmp     %i1, 2
F00AFD48: 04800009                 ble     loc_F00AFD6C
F00AFD4C: 90040019                 add     %l0, %i1, %o0
F00AFD50: c02a3fff                 clrb    [%o0-1]
F00AFD54: 90100010                 mov     %l0, %o0! __dst
F00AFD58: d202600c                 ld      [%o1+0xC], %o1! __src
F00AFD5C: 7ffd5ef0                 call    _strncpy
F00AFD60: 94067fff                 add     %i1, -1, %o2
F00AFD64: 10800003                 ba      locret_F00AFD70
F00AFD68: b0102000                 mov     0, %i0
F00AFD6C: b0103fff                 mov     -1, %i0
F00AFD70: 81c7e008                 ret
F00AFD74: 81e80000                 restore
