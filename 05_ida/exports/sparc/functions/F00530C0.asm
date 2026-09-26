F00530C0: 9de3bf98                 save    %sp, -0x68, %sp
F00530C4: 80a6600b                 cmp     %i1, 0xB
F00530C8: 1480000a                 bg      loc_F00530F0
F00530CC: f0062030                 ld      [%i0+0x30], %i0
F00530D0: d4062050                 ld      [%i0+0x50], %o2
F00530D4: d202a050                 ld      [%o2+0x50], %o1
F00530D8: 90066001                 add     %i1, 1, %o0
F00530DC: d6062070                 ld      [%i0+0x70], %o3
F00530E0: 912a0009                 sll     %o0, %o1, %o0
F00530E4: 80a2c008                 cmp     %o3, %o0
F00530E8: 2a800005                 bcs,a   loc_F00530FC
F00530EC: d002a048                 ld      [%o2+0x48], %o0
F00530F0: d0062050                 ld      [%i0+0x50], %o0
F00530F4: 10800008                 ba      loc_F0053114
F00530F8: e0022030                 ld      [%o0+0x30], %l0
F00530FC: d202a034                 ld      [%o2+0x34], %o1
F0053100: 902ac008                 andn    %o3, %o0, %o0
F0053104: 90020009                 add     %o0, %o1, %o0
F0053108: d202a04c                 ld      [%o2+0x4C], %o1
F005310C: 90023fff                 inc     -1, %o0
F0053110: a00a0009                 and     %o0, %o1, %l0
F0053114: 90100018                 mov     %i0, %o0
F0053118: 92100019                 mov     %i1, %o1
F005311C: 94102001                 mov     1, %o2
F0053120: 96102000                 mov     0, %o3
F0053124: 7fffde74                 call    _bmap
F0053128: 98102000                 mov     0, %o4
F005312C: d2062050                 ld      [%i0+0x50], %o1
F0053130: d2026064                 ld      [%o1+0x64], %o1
F0053134: 932a0009                 sll     %o0, %o1, %o1! size_t
F0053138: 80a26000                 cmp     %o1, 0
F005313C: 3680000a                 bge,a   loc_F0053164
F0053140: d0062058                 ld      [%i0+0x58], %o0
F0053144: 7fff46c1                 call    _geteblk
F0053148: 90100010                 mov     %l0, %o0
F005314C: a0100008                 mov     %o0, %l0
F0053150: d0042020                 ld      [%l0+0x20], %o0! void *
F0053154: 40010741                 call    _bzero
F0053158: d2042014                 ld      [%l0+0x14], %o1
F005315C: 10800011                 ba      loc_F00531A0
F0053160: c0242028                 clr     [%l0+0x28]
F0053164: 90022001                 inc     %o0
F0053168: 80a20019                 cmp     %o0, %i1
F005316C: 1280000a                 bne     loc_F0053194
F0053170: d0062040                 ld      [%i0+0x40], %o0
F0053174: 153c04eb                 sethi   %hi(_rablock), %o2
F0053178: d602a170                 ld      [%o2+%lo(_rablock)], %o3
F005317C: 153c04eb                 sethi   %hi(_rasize), %o2
F0053180: d802a178                 ld      [%o2+%lo(_rasize)], %o4
F0053184: 7fff4515                 call    _breada
F0053188: 94100010                 mov     %l0, %o2
F005318C: 10800005                 ba      loc_F00531A0
F0053190: a0100008                 mov     %o0, %l0
F0053194: 7fff44e3                 call    _bread
F0053198: 94100010                 mov     %l0, %o2
F005319C: a0100008                 mov     %o0, %l0
F00531A0: f2262058                 st      %i1, [%i0+0x58]
F00531A4: 333c04d4                 sethi   %hi(_iuniqtime), %i1
F00531A8: d2162044                 lduh    [%i0+0x44], %o1
F00531AC: 90166148                 or      %i1, %lo(_iuniqtime), %o0
F00531B0: 92126004                 bset    4, %o1
F00531B4: 40006d07                 call    _microtime
F00531B8: d2362044                 sth     %o1, [%i0+0x44]
F00531BC: d0162044                 lduh    [%i0+0x44], %o0
F00531C0: 808a2004                 btst    4, %o0
F00531C4: 02800003                 be      loc_F00531D0
F00531C8: d0066148                 ld      [%i1+%lo(_iuniqtime)], %o0
F00531CC: d0262074                 st      %o0, [%i0+0x74]
F00531D0: d0162044                 lduh    [%i0+0x44], %o0
F00531D4: 808a2002                 btst    2, %o0
F00531D8: 02800003                 be      loc_F00531E4
F00531DC: d0066148                 ld      [%i1+0x148], %o0
F00531E0: d026207c                 st      %o0, [%i0+0x7C]
F00531E4: d0162044                 lduh    [%i0+0x44], %o0
F00531E8: 808a2040                 btst    0x40, %o0 ! '@'
F00531EC: 22800006                 be,a    loc_F0053204
F00531F0: d0040000                 ld      [%l0], %o0
F00531F4: c026204c                 clr     [%i0+0x4C]
F00531F8: d0066148                 ld      [%i1+0x148], %o0
F00531FC: d0262084                 st      %o0, [%i0+0x84]
F0053200: d0040000                 ld      [%l0], %o0
F0053204: 808a2004                 btst    4, %o0
F0053208: 12800004                 bne     loc_F0053218
F005320C: b0102000                 mov     0, %i0
F0053210: 10800005                 ba      locret_F0053224
F0053214: e0268000                 st      %l0, [%i2]
F0053218: 7fff4594                 call    _brelse
F005321C: 90100010                 mov     %l0, %o0
F0053220: b0102005                 mov     5, %i0
F0053224: 81c7e008                 ret
F0053228: 81e80000                 restore
