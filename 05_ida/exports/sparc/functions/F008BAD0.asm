F008BAD0: 9de3bf98                 save    %sp, -0x68, %sp
F008BAD4: 133c04c3                 sethi   %hi(dword_F0130F64), %o1
F008BAD8: d0026364                 ld      [%o1+%lo(dword_F0130F64)], %o0
F008BADC: 94126364                 or      %o1, %lo(dword_F0130F64), %o2
F008BAE0: 80a2000a                 cmp     %o0, %o2
F008BAE4: 02800019                 be      locret_F008BB48
F008BAE8: a4100009                 mov     %o1, %l2
F008BAEC: a210000a                 mov     %o2, %l1
F008BAF0: 273c04c3                 sethi   -0xFECF400, %l3
F008BAF4: e004a364                 ld      [%l2+0x364], %l0
F008BAF8: 7ffe741b                 call    _vn_rele
F008BAFC: d0042008                 ld      [%l0+8], %o0
F008BB00: d2040000                 ld      [%l0], %o1
F008BB04: 80a24011                 cmp     %o1, %l1
F008BB08: 12800004                 bne     loc_F008BB18
F008BB0C: d0042004                 ld      [%l0+4], %o0
F008BB10: 10800003                 ba      loc_F008BB1C
F008BB14: d0246004                 st      %o0, [%l1+4]
F008BB18: d0226004                 st      %o0, [%o1+4]
F008BB1C: 80a20011                 cmp     %o0, %l1
F008BB20: 32800003                 bne,a   loc_F008BB2C
F008BB24: d2220000                 st      %o1, [%o0]
F008BB28: d224a364                 st      %o1, [%l2+0x364]
F008BB2C: d004e36c                 ld      [%l3+0x36C], %o0
F008BB30: 133c04c3                 sethi   %hi(dword_F0130F64), %o1
F008BB34: d2026364                 ld      [%o1+%lo(dword_F0130F64)], %o1
F008BB38: 90023fff                 inc     -1, %o0
F008BB3C: 80a24011                 cmp     %o1, %l1
F008BB40: 12bfffed                 bne     loc_F008BAF4
F008BB44: d024e36c                 st      %o0, [%l3+0x36C]
F008BB48: 81c7e008                 ret
F008BB4C: 81e80000                 restore
