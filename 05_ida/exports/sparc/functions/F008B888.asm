F008B888: 9de3bf18                 save    %sp, -0xE8, %sp
F008B88C: a6100018                 mov     %i0, %l3
F008B890: c024c000                 clr     [%l3]
F008B894: 7fff8444                 call    _mfs_uncache
F008B898: 90100019                 mov     %i1, %o0
F008B89C: d0064000                 ld      [%i1], %o0
F008B8A0: d2022038                 ld      [%o0+0x38], %o1
F008B8A4: 11020000                 sethi   0x8000000, %o0
F008B8A8: 808a4008                 btst    %o0, %o1
F008B8AC: 12800087                 bne     locret_F008BAC8
F008B8B0: b0102010                 mov     0x10, %i0
F008B8B4: 113c04cf                 sethi   %hi(_active_u), %o0
F008B8B8: d20221d8                 ld      [%o0+%lo(_active_u)], %o1
F008B8BC: d406601c                 ld      [%i1+0x1C], %o2
F008B8C0: a007bfb8                 add     %fp, var_48, %l0
F008B8C4: e402601c                 ld      [%o1+0x1C], %l2
F008B8C8: 90100019                 mov     %i1, %o0
F008B8CC: d602a014                 ld      [%o2+0x14], %o3
F008B8D0: 92100010                 mov     %l0, %o1
F008B8D4: 9fc2c000                 call    %o3
F008B8D8: 94100012                 mov     %l2, %o2
F008B8DC: e207bfd0                 ld      [%fp+var_30], %l1
F008B8E0: 80a4401a                 cmp     %l1, %i2
F008B8E4: 28800010                 bleu,a  loc_F008B924
F008B8E8: d2064000                 ld      [%i1], %o1
F008B8EC: 7ffe76ea                 call    _vattr_null
F008B8F0: 90100010                 mov     %l0, %o0
F008B8F4: a210001a                 mov     %i2, %l1
F008B8F8: f427bfd0                 st      %i2, [%fp+var_30]
F008B8FC: d406601c                 ld      [%i1+0x1C], %o2
F008B900: 90100019                 mov     %i1, %o0
F008B904: d602a018                 ld      [%o2+0x18], %o3
F008B908: 92100010                 mov     %l0, %o1
F008B90C: 9fc2c000                 call    %o3
F008B910: 94100012                 mov     %l2, %o2
F008B914: b0920000                 orcc    %o0, %g0, %i0
F008B918: 1280006c                 bne     locret_F008BAC8
F008B91C: 01000000                 nop
F008B920: d2064000                 ld      [%i1], %o1
F008B924: 90102040                 mov     0x40, %o0 ! '@'
F008B928: 7fff71d2                 call    _kalloc
F008B92C: e2226014                 st      %l1, [%o1+0x14]
F008B930: d2166006                 lduh    [%i1+6], %o1
F008B934: a0100008                 mov     %o0, %l0
F008B938: 92026001                 inc     %o1
F008B93C: d2366006                 sth     %o1, [%i1+6]
F008B940: f2242008                 st      %i1, [%l0+8]
F008B944: d0148000                 lduh    [%l2], %o0
F008B948: 80a6e000                 cmp     %i3, 0
F008B94C: 90022001                 inc     %o0
F008B950: d0348000                 sth     %o0, [%l2]
F008B954: d0064000                 ld      [%i1], %o0
F008B958: 133c04f4                 sethi   %hi(_page_shift), %o1
F008B95C: d2026348                 ld      [%o1+%lo(_page_shift)], %o1
F008B960: e4222030                 st      %l2, [%o0+0x30]
F008B964: c024200c                 clr     [%l0+0xC]
F008B968: 113c04d0                 sethi   %hi(_page_mask), %o0
F008B96C: d00220d8                 ld      [%o0+%lo(_page_mask)], %o0
F008B970: c0242024                 clr     [%l0+0x24]
F008B974: 94068008                 add     %i2, %o0, %o2
F008B978: 902a8008                 andn    %o2, %o0, %o0
F008B97C: 91320009                 srl     %o0, %o1, %o0
F008B980: 12800011                 bne     loc_F008B9C4
F008B984: d024201c                 st      %o0, [%l0+0x1C]
F008B988: d0066024                 ld      [%i1+0x24], %o0
F008B98C: d4022004                 ld      [%o0+4], %o2
F008B990: d402a00c                 ld      [%o2+0xC], %o2
F008B994: 9fc28000                 call    %o2
F008B998: 9207bf78                 add     %fp, var_88, %o1
F008B99C: b0920000                 orcc    %o0, %g0, %i0
F008B9A0: 02800005                 be      loc_F008B9B4
F008B9A4: 90100010                 mov     %l0, %o0
F008B9A8: 7fff71fe                 call    _kfree
F008B9AC: 92102040                 mov     0x40, %o1 ! '@'
F008B9B0: 30800046                 ba,a    locret_F008BAC8
F008B9B4: d007bf80                 ld      [%fp+var_80], %o0
F008B9B8: 7ffdead2                 call    _umul
F008B9BC: d207bf7c                 ld      [%fp+var_84], %o1
F008B9C0: b6100008                 mov     %o0, %i3
F008B9C4: 113c04f4                 sethi   %hi(_page_shift), %o0
F008B9C8: d0022348                 ld      [%o0+%lo(_page_shift)], %o0
F008B9CC: 9136c008                 srl     %i3, %o0, %o0
F008B9D0: d0242014                 st      %o0, [%l0+0x14]
F008B9D4: d2042014                 ld      [%l0+0x14], %o1
F008B9D8: d0242018                 st      %o0, [%l0+0x18]
F008B9DC: 90826007                 addcc   %o1, 7, %o0
F008B9E0: 2c800002                 bneg,a  loc_F008B9E8
F008B9E4: 9002600e                 add     %o1, 0xE, %o0
F008B9E8: 7fff71a2                 call    _kalloc
F008B9EC: 913a2003                 sra     %o0, 3, %o0
F008B9F0: d0242010                 st      %o0, [%l0+0x10]
F008B9F4: d0042014                 ld      [%l0+0x14], %o0
F008B9F8: 98102000                 mov     0, %o4
F008B9FC: 80a30008                 cmp     %o4, %o0
F008BA00: 16800015                 bge     loc_F008BA54
F008BA04: 90103fff                 mov     -1, %o0
F008BA08: 9a102001                 mov     1, %o5
F008BA0C: 80a32000                 cmp     %o4, 0
F008BA10: 16800003                 bge     loc_F008BA1C
F008BA14: 9410000c                 mov     %o4, %o2
F008BA18: 94032007                 add     %o4, 7, %o2
F008BA1C: 953aa003                 sra     %o2, 3, %o2
F008BA20: 912aa003                 sll     %o2, 3, %o0
F008BA24: d6042010                 ld      [%l0+0x10], %o3
F008BA28: 90230008                 sub     %o4, %o0, %o0
F008BA2C: d20ac00a                 ldub    [%o3+%o2], %o1
F008BA30: 912b4008                 sll     %o5, %o0, %o0
F008BA34: 902a4008                 andn    %o1, %o0, %o0
F008BA38: d02ac00a                 stb     %o0, [%o3+%o2]
F008BA3C: d0042014                 ld      [%l0+0x14], %o0
F008BA40: 98032001                 inc     %o4
F008BA44: 80a30008                 cmp     %o4, %o0
F008BA48: 06bffff2                 bl      loc_F008BA10
F008BA4C: 80a32000                 cmp     %o4, 0
F008BA50: 90103fff                 mov     -1, %o0
F008BA54: d0242020                 st      %o0, [%l0+0x20]
F008BA58: c024202c                 clr     [%l0+0x2C]
F008BA5C: 90042034                 add     %l0, 0x34, %o0 ! '4'
F008BA60: 7fff74aa                 call    _lock_init
F008BA64: 92102001                 mov     1, %o1
F008BA68: 113c04c3                 sethi   %hi(dword_F0130F68), %o0
F008BA6C: d2022368                 ld      [%o0+%lo(dword_F0130F68)], %o1
F008BA70: 94122368                 or      %o0, %lo(dword_F0130F68), %o2
F008BA74: 9002bffc                 add     %o2, -4, %o0
F008BA78: 80a24008                 cmp     %o1, %o0
F008BA7C: 32800003                 bne,a   loc_F008BA88
F008BA80: e0224000                 st      %l0, [%o1]
F008BA84: e022bffc                 st      %l0, [%o2-4]
F008BA88: d2242004                 st      %o1, [%l0+4]
F008BA8C: 113c04c390122364         set     dword_F0130F64, %o0
F008BA94: d0240000                 st      %o0, [%l0]
F008BA98: e0222004                 st      %l0, [%o0+4]
F008BA9C: 133c04c3                 sethi   %hi(dword_F0130F6C), %o1
F008BAA0: d002636c                 ld      [%o1+%lo(dword_F0130F6C)], %o0
F008BAA4: b0102000                 mov     0, %i0
F008BAA8: 90022001                 inc     %o0
F008BAAC: d022636c                 st      %o0, [%o1+%lo(dword_F0130F6C)]
F008BAB0: d0242030                 st      %o0, [%l0+0x30]
F008BAB4: 133c04c392126370         set     unk_F0130F70, %o1
F008BABC: 912a2002                 sll     %o0, 2, %o0
F008BAC0: e0220009                 st      %l0, [%o0+%o1]
F008BAC4: e024c000                 st      %l0, [%l3]
F008BAC8: 81c7e008                 ret
F008BACC: 81e80000                 restore
