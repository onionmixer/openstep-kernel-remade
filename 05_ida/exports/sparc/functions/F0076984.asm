F0076984: 9de3bf98                 save    %sp, -0x68, %sp
F0076988: 113c0442                 sethi   %hi(dword_F0110BB0), %o0
F007698C: d00223b0                 ld      [%o0+%lo(dword_F0110BB0)], %o0
F0076990: 80a22000                 cmp     %o0, 0
F0076994: 02800038                 be      locret_F0076A74
F0076998: 01000000                 nop
F007699C: 4000807b                 call    _splusclock
F00769A0: 01000000                 nop
F00769A4: a4100008                 mov     %o0, %l2
F00769A8: 113c04c3a0122320         set     dword_F0130F20, %l0
F00769B0: d0040000                 ld      [%l0], %o0
F00769B4: 80a22000                 cmp     %o0, 0
F00769B8: 12bffffe                 bne     loc_F00769B0
F00769BC: 01000000                 nop
F00769C0: 4000813a                 call    _simple_lock_try
F00769C4: 90100010                 mov     %l0, %o0
F00769C8: 80a22000                 cmp     %o0, 0
F00769CC: 02bffff9                 be      loc_F00769B0
F00769D0: 233c04c3                 sethi   %hi(dword_F0130F24), %l1
F00769D4: d0046324                 ld      [%l1+%lo(dword_F0130F24)], %o0
F00769D8: a0146324                 or      %l1, %lo(dword_F0130F24), %l0
F00769DC: 80a20010                 cmp     %o0, %l0
F00769E0: 12800006                 bne     loc_F00769F8
F00769E4: d2046324                 ld      [%l1+%lo(dword_F0130F24)], %o1
F00769E8: 113c0442                 sethi   %hi(aInternalentrya), %o0! "internalEntryAllocate"
F00769EC: 7ffe79e1                 call    _panic
F00769F0: 901223b8                 bset    %lo(aInternalentrya), %o0! "internalEntryAllocate"
F00769F4: d2046324                 ld      [%l1+%lo(dword_F0130F24)], %o1
F00769F8: 80a24010                 cmp     %o1, %l0
F00769FC: 32800004                 bne,a   loc_F0076A0C
F0076A00: d0024000                 ld      [%o1], %o0
F0076A04: 10800006                 ba      loc_F0076A1C
F0076A08: 96102000                 mov     0, %o3
F0076A0C: e0222004                 st      %l0, [%o0+4]
F0076A10: d0024000                 ld      [%o1], %o0
F0076A14: 96100009                 mov     %o1, %o3
F0076A18: d0246324                 st      %o0, [%l1+0x324]
F0076A1C: f022e008                 st      %i0, [%o3+8]
F0076A20: f222e00c                 st      %i1, [%o3+0xC]
F0076A24: c022e010                 clr     [%o3+0x10]
F0076A28: 98102000                 mov     0, %o4
F0076A2C: 9a102000                 mov     0, %o5
F0076A30: d83ae018                 std     %o4, [%o3+0x18]
F0076A34: 133c04c39212632c         set     dword_F0130F2C, %o1
F0076A3C: d222c000                 st      %o1, [%o3]
F0076A40: d0026004                 ld      [%o1+4], %o0
F0076A44: 153c04c3                 sethi   %hi(dword_F0130F3C), %o2
F0076A48: d022e004                 st      %o0, [%o3+4]
F0076A4C: d6220000                 st      %o3, [%o0]
F0076A50: d002a33c                 ld      [%o2+%lo(dword_F0130F3C)], %o0
F0076A54: d6226004                 st      %o3, [%o1+4]
F0076A58: 90022001                 inc     %o0
F0076A5C: d022a33c                 st      %o0, [%o2+%lo(dword_F0130F3C)]
F0076A60: 90102001                 mov     1, %o0
F0076A64: 40000251                 call    sub_F00773A8
F0076A68: d022e020                 st      %o0, [%o3+0x20]
F0076A6C: 400080ae                 call    _splx
F0076A70: 90100012                 mov     %l2, %o0
F0076A74: 81c7e008                 ret
F0076A78: 81e80000                 restore
