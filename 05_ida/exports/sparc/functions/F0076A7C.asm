F0076A7C: 9de3bf98                 save    %sp, -0x68, %sp
F0076A80: 113c0442                 sethi   %hi(dword_F0110BB0), %o0
F0076A84: d00223b0                 ld      [%o0+%lo(dword_F0110BB0)], %o0
F0076A88: 80a22000                 cmp     %o0, 0
F0076A8C: 02800052                 be      locret_F0076BD4
F0076A90: 01000000                 nop
F0076A94: 4000803d                 call    _splusclock
F0076A98: 01000000                 nop
F0076A9C: a4100008                 mov     %o0, %l2
F0076AA0: 113c04c3a0122320         set     dword_F0130F20, %l0
F0076AA8: d0040000                 ld      [%l0], %o0
F0076AAC: 80a22000                 cmp     %o0, 0
F0076AB0: 12bffffe                 bne     loc_F0076AA8
F0076AB4: 01000000                 nop
F0076AB8: 400080fc                 call    _simple_lock_try
F0076ABC: 90100010                 mov     %l0, %o0
F0076AC0: 80a22000                 cmp     %o0, 0
F0076AC4: 02bffff9                 be      loc_F0076AA8
F0076AC8: 113c04c3                 sethi   %hi(dword_F0130F2C), %o0
F0076ACC: d602232c                 ld      [%o0+%lo(dword_F0130F2C)], %o3
F0076AD0: 9012232c                 bset    %lo(dword_F0130F2C), %o0
F0076AD4: 80a2c008                 cmp     %o3, %o0
F0076AD8: 22800010                 be,a    loc_F0076B18
F0076ADC: 113c04c3                 sethi   -0xFECF400, %o0
F0076AE0: 92100008                 mov     %o0, %o1
F0076AE4: d002e008                 ld      [%o3+8], %o0
F0076AE8: 80a20018                 cmp     %o0, %i0
F0076AEC: 32800007                 bne,a   loc_F0076B08
F0076AF0: d602c000                 ld      [%o3], %o3
F0076AF4: d002e00c                 ld      [%o3+0xC], %o0
F0076AF8: 80a20019                 cmp     %o0, %i1
F0076AFC: 02800007                 be      loc_F0076B18
F0076B00: 113c04c3                 sethi   -0xFECF400, %o0
F0076B04: d602c000                 ld      [%o3], %o3
F0076B08: 80a2c009                 cmp     %o3, %o1
F0076B0C: 32bffff7                 bne,a   loc_F0076AE8
F0076B10: d002e008                 ld      [%o3+8], %o0
F0076B14: 113c04c3                 sethi   -0xFECF400, %o0
F0076B18: 9012232c                 bset    0x32C, %o0
F0076B1C: 80a2c008                 cmp     %o3, %o0
F0076B20: 1280002a                 bne     loc_F0076BC8
F0076B24: 113c04c3                 sethi   -0xFECF400, %o0
F0076B28: 233c04c3                 sethi   %hi(dword_F0130F24), %l1
F0076B2C: d0046324                 ld      [%l1+%lo(dword_F0130F24)], %o0
F0076B30: a0146324                 or      %l1, %lo(dword_F0130F24), %l0
F0076B34: 80a20010                 cmp     %o0, %l0
F0076B38: 12800006                 bne     loc_F0076B50
F0076B3C: d2046324                 ld      [%l1+%lo(dword_F0130F24)], %o1
F0076B40: 113c0442                 sethi   %hi(aInternalentrya), %o0! "internalEntryAllocate"
F0076B44: 7ffe798b                 call    _panic
F0076B48: 901223b8                 bset    %lo(aInternalentrya), %o0! "internalEntryAllocate"
F0076B4C: d2046324                 ld      [%l1+%lo(dword_F0130F24)], %o1
F0076B50: 80a24010                 cmp     %o1, %l0
F0076B54: 32800004                 bne,a   loc_F0076B64
F0076B58: d0024000                 ld      [%o1], %o0
F0076B5C: 10800005                 ba      loc_F0076B70
F0076B60: 92102000                 mov     0, %o1
F0076B64: e0222004                 st      %l0, [%o0+4]
F0076B68: d0024000                 ld      [%o1], %o0
F0076B6C: d0246324                 st      %o0, [%l1+0x324]
F0076B70: 96100009                 mov     %o1, %o3
F0076B74: f022e008                 st      %i0, [%o3+8]
F0076B78: f222e00c                 st      %i1, [%o3+0xC]
F0076B7C: c022e010                 clr     [%o3+0x10]
F0076B80: 98102000                 mov     0, %o4
F0076B84: 9a102000                 mov     0, %o5
F0076B88: d83ae018                 std     %o4, [%o3+0x18]
F0076B8C: 133c04c39212632c         set     dword_F0130F2C, %o1
F0076B94: d222c000                 st      %o1, [%o3]
F0076B98: d0026004                 ld      [%o1+4], %o0
F0076B9C: 153c04c3                 sethi   %hi(dword_F0130F3C), %o2
F0076BA0: d022e004                 st      %o0, [%o3+4]
F0076BA4: d6220000                 st      %o3, [%o0]
F0076BA8: d002a33c                 ld      [%o2+%lo(dword_F0130F3C)], %o0
F0076BAC: d6226004                 st      %o3, [%o1+4]
F0076BB0: 90022001                 inc     %o0
F0076BB4: d022a33c                 st      %o0, [%o2+%lo(dword_F0130F3C)]
F0076BB8: 90102001                 mov     1, %o0
F0076BBC: 400001fb                 call    sub_F00773A8
F0076BC0: d022e020                 st      %o0, [%o3+0x20]
F0076BC4: 30800002                 ba,a    loc_F0076BCC
F0076BC8: c0222320                 clr     [%o0+0x320]
F0076BCC: 40008056                 call    _splx
F0076BD0: 90100012                 mov     %l2, %o0
F0076BD4: 81c7e008                 ret
F0076BD8: 81e80000                 restore
