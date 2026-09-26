F008BB50: 9de3bf80                 save    %sp, -0x80, %sp
F008BB54: 7ffe0f86                 call    _suser
F008BB58: 01000000                 nop
F008BB5C: 80a22000                 cmp     %o0, 0
F008BB60: 12800004                 bne     loc_F008BB70
F008BB64: 90100018                 mov     %i0, %o0
F008BB68: 10800055                 ba      locret_F008BCBC
F008BB6C: b010200d                 mov     0xD, %i0
F008BB70: 92102000                 mov     0, %o1
F008BB74: 153c04cf                 sethi   %hi(dword_F0133DDC), %o2
F008BB78: d602a1dc                 ld      [%o2+%lo(dword_F0133DDC)], %o3
F008BB7C: a207bfe8                 add     %fp, var_18, %l1
F008BB80: 94100011                 mov     %l1, %o2! __n
F008BB84: c02ae038                 clrb    [%o3+0x38]
F008BB88: 7ffe6dcc                 call    _pn_get
F008BB8C: c027bfe4                 clr     [%fp+var_1C]
F008BB90: 80a22000                 cmp     %o0, 0
F008BB94: 1280004a                 bne     locret_F008BCBC
F008BB98: b0102016                 mov     0x16, %i0
F008BB9C: e007bff0                 ld      [%fp+var_10], %l0
F008BBA0: a6042001                 add     %l0, 1, %l3
F008BBA4: 7fff7133                 call    _kalloc
F008BBA8: 90100013                 mov     %l3, %o0! __dst
F008BBAC: a4100008                 mov     %o0, %l2
F008BBB0: d207bfec                 ld      [%fp+__src], %o1! __src
F008BBB4: 7ffdef5a                 call    _strncpy
F008BBB8: 94100010                 mov     %l0, %o2
F008BBBC: 9004c012                 add     %l3, %l2, %o0
F008BBC0: c02a3fff                 clrb    [%o0-1]
F008BBC4: 90100011                 mov     %l1, %o0
F008BBC8: 92102001                 mov     1, %o1
F008BBCC: 94102000                 mov     0, %o2
F008BBD0: 7ffe6b8f                 call    _lookuppn
F008BBD4: 9607bfe4                 add     %fp, var_1C, %o3
F008BBD8: b0100008                 mov     %o0, %i0
F008BBDC: 7ffe6e43                 call    _pn_free
F008BBE0: 90100011                 mov     %l1, %o0
F008BBE4: 80a62000                 cmp     %i0, 0
F008BBE8: 1280002b                 bne     loc_F008BC94
F008BBEC: d007bfe4                 ld      [%fp+var_1C], %o0
F008BBF0: d407bfe4                 ld      [%fp+var_1C], %o2
F008BBF4: d002a028                 ld      [%o2+0x28], %o0
F008BBF8: 80a22001                 cmp     %o0, 1
F008BBFC: 12800025                 bne     loc_F008BC90
F008BC00: b0102016                 mov     0x16, %i0
F008BC04: 113c04c3                 sethi   %hi(dword_F0130F64), %o0
F008BC08: d2022364                 ld      [%o0+%lo(dword_F0130F64)], %o1
F008BC0C: 90122364                 bset    %lo(dword_F0130F64), %o0
F008BC10: 80a24008                 cmp     %o1, %o0
F008BC14: 0280000c                 be      loc_F008BC44
F008BC18: d227bfe0                 st      %o1, [%fp+var_20]
F008BC1C: 96100008                 mov     %o0, %o3
F008BC20: d207bfe0                 ld      [%fp+var_20], %o1
F008BC24: d0026008                 ld      [%o1+8], %o0
F008BC28: 80a2000a                 cmp     %o0, %o2
F008BC2C: 02800008                 be      loc_F008BC4C
F008BC30: 113c04c3                 sethi   -0xFECF400, %o0
F008BC34: d0024000                 ld      [%o1], %o0
F008BC38: 80a2000b                 cmp     %o0, %o3
F008BC3C: 12bffff9                 bne     loc_F008BC20
F008BC40: d027bfe0                 st      %o0, [%fp+var_20]
F008BC44: 113c04c3                 sethi   -0xFECF400, %o0
F008BC48: d207bfe0                 ld      [%fp+var_20], %o1
F008BC4C: 90122364                 bset    0x364, %o0
F008BC50: 80a24008                 cmp     %o1, %o0
F008BC54: 1280000f                 bne     loc_F008BC90
F008BC58: b0102010                 mov     0x10, %i0
F008BC5C: 9007bfe0                 add     %fp, var_20, %o0
F008BC60: d207bfe4                 ld      [%fp+var_1C], %o1
F008BC64: 9410001a                 mov     %i2, %o2
F008BC68: 7fffff08                 call    _vnode_pager_file_init
F008BC6C: 9610001b                 mov     %i3, %o3
F008BC70: b0920000                 orcc    %o0, %g0, %i0
F008BC74: 12800008                 bne     loc_F008BC94
F008BC78: d007bfe4                 ld      [%fp+var_1C], %o0
F008BC7C: d207bfe0                 ld      [%fp+var_20], %o1
F008BC80: 900e6001                 and     %i1, 1, %o0
F008BC84: d022602c                 st      %o0, [%o1+0x2C]
F008BC88: e4226028                 st      %l2, [%o1+0x28]
F008BC8C: a4102000                 mov     0, %l2
F008BC90: d007bfe4                 ld      [%fp+var_1C], %o0
F008BC94: 80a22000                 cmp     %o0, 0
F008BC98: 02800005                 be      loc_F008BCAC
F008BC9C: 80a4a000                 cmp     %l2, 0
F008BCA0: 7ffe73b1                 call    _vn_rele
F008BCA4: 01000000                 nop
F008BCA8: 80a4a000                 cmp     %l2, 0
F008BCAC: 02800004                 be      locret_F008BCBC
F008BCB0: 90100012                 mov     %l2, %o0
F008BCB4: 7fff713b                 call    _kfree
F008BCB8: 92100013                 mov     %l3, %o1
F008BCBC: 81c7e008                 ret
F008BCC0: 81e80000                 restore
