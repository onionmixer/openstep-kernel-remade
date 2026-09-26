F003E87C: 9de3bed0                 save    %sp, -0x130, %sp
F003E880: a6100018                 mov     %i0, %l3
F003E884: f007a05c                 ld      [%fp+arg_5C], %i0
F003E888: e007a060                 ld      [%fp+arg_60], %l0
F003E88C: 4000a5f9                 call    _kalloc
F003E890: 90102070                 mov     0x70, %o0! void *
F003E894: a2100008                 mov     %o0, %l1
F003E898: 40015970                 call    _bzero
F003E89C: 92102070                 mov     0x70, %o1 ! 'p'
F003E8A0: 13200000                 sethi   0x80000000, %o1
F003E8A4: d0046014                 ld      [%l1+0x14], %o0
F003E8A8: 15080000                 sethi   0x20000000, %o2
F003E8AC: 922a0009                 andn    %o0, %o1, %o1
F003E8B0: 901c2001                 xor     %l0, 1, %o0
F003E8B4: 912a201f                 sll     %o0, 31, %o0
F003E8B8: 92124008                 bset    %o0, %o1
F003E8BC: 942a400a                 andn    %o1, %o2, %o2
F003E8C0: 91342006                 srl     %l0, 6, %o0
F003E8C4: 900a2001                 and     %o0, 1, %o0
F003E8C8: 912a201d                 sll     %o0, 29, %o0
F003E8CC: 94128008                 bset    %o0, %o2
F003E8D0: d4246014                 st      %o2, [%l1+0x14]
F003E8D4: d0068000                 ld      [%i2], %o0
F003E8D8: d0244000                 st      %o0, [%l1]
F003E8DC: d006a004                 ld      [%i2+4], %o0
F003E8E0: a4102000                 mov     0, %l2
F003E8E4: d0246004                 st      %o0, [%l1+4]
F003E8E8: 113c04bd                 sethi   %hi(unk_F012F4F4), %o0
F003E8EC: d206a008                 ld      [%i2+8], %o1
F003E8F0: 901220f4                 bset    %lo(unk_F012F4F4), %o0
F003E8F4: d2246008                 st      %o1, [%l1+8]
F003E8F8: d406a00c                 ld      [%i2+0xC], %o2
F003E8FC: 92102020                 mov     0x20, %o1 ! ' '
F003E900: d424600c                 st      %o2, [%l1+0xC]
F003E904: 94102005                 mov     5, %o2
F003E908: d4246030                 st      %o2, [%l1+0x30]
F003E90C: 9410200b                 mov     0xB, %o2! size_t
F003E910: 7fff96d2                 call    _vfs_getnum
F003E914: d424602c                 st      %o2, [%l1+0x2C]
F003E918: d0246028                 st      %o0, [%l1+0x28]
F003E91C: 9010001c                 mov     %i4, %o0! void *
F003E920: 92046034                 add     %l1, 0x34, %o1 ! '4'! void *
F003E924: 4001587b                 call    _bcopy
F003E928: 94102020                 mov     0x20, %o2 ! ' '! size_t
F003E92C: 90102003                 mov     3, %o0
F003E930: d0246060                 st      %o0, [%l1+0x60]
F003E934: 9210203c                 mov     0x3C, %o1 ! '<'
F003E938: d2246064                 st      %o1, [%l1+0x64]
F003E93C: 9010201e                 mov     0x1E, %o0
F003E940: d0246068                 st      %o0, [%l1+0x68]
F003E944: 11000004                 sethi   0x1000, %o0
F003E948: 808c0008                 btst    %o0, %l0
F003E94C: 12800054                 bne     loc_F003EA9C
F003E950: d224606c                 st      %o1, [%l1+0x6C]
F003E954: a0102001                 mov     1, %l0
F003E958: e024605c                 st      %l0, [%l1+0x5C]
F003E95C: 80a62000                 cmp     %i0, 0
F003E960: 06800009                 bl      loc_F003E984
F003E964: f0246058                 st      %i0, [%l1+0x58]
F003E968: 4000a5c2                 call    _kalloc
F003E96C: 90100018                 mov     %i0, %o0
F003E970: 92100008                 mov     %o0, %o1! void *
F003E974: d2246054                 st      %o1, [%l1+0x54]
F003E978: 9010001d                 mov     %i5, %o0! void *
F003E97C: 40015865                 call    _bcopy
F003E980: 94100018                 mov     %i0, %o2
F003E984: 9010001b                 mov     %i3, %o0
F003E988: 92102000                 mov     0, %o1
F003E98C: d6046028                 ld      [%l1+0x28], %o3
F003E990: 94100019                 mov     %i1, %o2
F003E994: d6266014                 st      %o3, [%i1+0x14]
F003E998: e0266018                 st      %l0, [%i1+0x18]
F003E99C: 7ffff8d5                 call    _makenfsnode
F003E9A0: e2266128                 st      %l1, [%i1+0x128]
F003E9A4: a4100008                 mov     %o0, %l2
F003E9A8: d014a004                 lduh    [%l2+4], %o0
F003E9AC: 808a2001                 btst    1, %o0
F003E9B0: 1280003c                 bne     loc_F003EAA0
F003E9B4: b0102016                 mov     0x16, %i0
F003E9B8: 90122001                 bset    1, %o0
F003E9BC: d034a004                 sth     %o0, [%l2+4]
F003E9C0: 353c04cf                 sethi   %hi(_active_u), %i2
F003E9C4: d006a1d8                 ld      [%i2+%lo(_active_u)], %o0
F003E9C8: d204a01c                 ld      [%l2+0x1C], %o1
F003E9CC: d402201c                 ld      [%o0+0x1C], %o2
F003E9D0: a007bfb8                 add     %fp, var_48, %l0
F003E9D4: d6026014                 ld      [%o1+0x14], %o3
F003E9D8: 90100012                 mov     %l2, %o0
F003E9DC: 9fc2c000                 call    %o3
F003E9E0: 92100010                 mov     %l0, %o1
F003E9E4: b0920000                 orcc    %o0, %g0, %i0
F003E9E8: 1280002f                 bne     loc_F003EAA4
F003E9EC: 80a46000                 cmp     %l1, 0
F003E9F0: 7fffa85d                 call    _vn_rele
F003E9F4: 90100012                 mov     %l2, %o0
F003E9F8: 90100010                 mov     %l0, %o0
F003E9FC: a007bf70                 add     %fp, var_90, %l0
F003EA00: 7fffec72                 call    _vattr_to_nattr
F003EA04: 92100010                 mov     %l0, %o1
F003EA08: 9010001b                 mov     %i3, %o0
F003EA0C: 92100010                 mov     %l0, %o1
F003EA10: 7ffff8b8                 call    _makenfsnode
F003EA14: 94100019                 mov     %i1, %o2
F003EA18: a4100008                 mov     %o0, %l2
F003EA1C: d014a004                 lduh    [%l2+4], %o0
F003EA20: 90122001                 bset    1, %o0
F003EA24: d034a004                 sth     %o0, [%l2+4]
F003EA28: e4246010                 st      %l2, [%l1+0x10]
F003EA2C: d2066004                 ld      [%i1+4], %o1
F003EA30: d402600c                 ld      [%o1+0xC], %o2
F003EA34: 90100019                 mov     %i1, %o0
F003EA38: 9fc28000                 call    %o2
F003EA3C: 9207bf30                 add     %fp, var_D0, %o1
F003EA40: b0920000                 orcc    %o0, %g0, %i0
F003EA44: 12800018                 bne     loc_F003EAA4
F003EA48: 80a46000                 cmp     %l1, 0
F003EA4C: 7fffec5b                 call    _nfstsize
F003EA50: b0102000                 mov     0, %i0
F003EA54: 92100008                 mov     %o0, %o1
F003EA58: 7fff5aa9                 call    _min
F003EA5C: 11000008                 sethi   0x2000, %o0
F003EA60: d024601c                 st      %o0, [%l1+0x1C]
F003EA64: 11000008                 sethi   0x2000, %o0
F003EA68: d0246024                 st      %o0, [%l1+0x24]
F003EA6C: d0266010                 st      %o0, [%i1+0x10]
F003EA70: d006a1d8                 ld      [%i2+0x1D8], %o0
F003EA74: d202201c                 ld      [%o0+0x1C], %o1
F003EA78: d0124000                 lduh    [%o1], %o0
F003EA7C: 90022001                 inc     %o0
F003EA80: d0324000                 sth     %o0, [%o1]
F003EA84: d006a1d8                 ld      [%i2+0x1D8], %o0
F003EA88: d204a030                 ld      [%l2+0x30], %o1
F003EA8C: d002201c                 ld      [%o0+0x1C], %o0
F003EA90: d0226070                 st      %o0, [%o1+0x70]
F003EA94: 10800015                 ba      locret_F003EAE8
F003EA98: e424c000                 st      %l2, [%l3]
F003EA9C: b0102016                 mov     0x16, %i0
F003EAA0: 80a46000                 cmp     %l1, 0
F003EAA4: 0280000c                 be      loc_F003EAD4
F003EAA8: 80a4a000                 cmp     %l2, 0
F003EAAC: d2046058                 ld      [%l1+0x58], %o1
F003EAB0: 80a26000                 cmp     %o1, 0
F003EAB4: 06800005                 bl      loc_F003EAC8
F003EAB8: 90100011                 mov     %l1, %o0
F003EABC: 4000a5b9                 call    _kfree
F003EAC0: d0046054                 ld      [%l1+0x54], %o0
F003EAC4: 90100011                 mov     %l1, %o0
F003EAC8: 4000a5b6                 call    _kfree
F003EACC: 92102070                 mov     0x70, %o1 ! 'p'
F003EAD0: 80a4a000                 cmp     %l2, 0
F003EAD4: 22800005                 be,a    locret_F003EAE8
F003EAD8: c024c000                 clr     [%l3]
F003EADC: 7fffa822                 call    _vn_rele
F003EAE0: 90100012                 mov     %l2, %o0
F003EAE4: c024c000                 clr     [%l3]
F003EAE8: 81c7e008                 ret
F003EAEC: 81e80000                 restore
