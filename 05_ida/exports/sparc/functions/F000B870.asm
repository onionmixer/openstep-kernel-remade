F000B870: 9de3be70                 save    %sp, -0x190, %sp
F000B874: 273c04cf                 sethi   %hi(dword_F0133DDC), %l3
F000B878: d004e1dc                 ld      [%l3+%lo(dword_F0133DDC)], %o0
F000B87C: 293c04d0                 sethi   %hi(_active_threads), %l4
F000B880: d4052260                 ld      [%l4+%lo(_active_threads)], %o2
F000B884: ee022024                 ld      [%o0+0x24], %l7
F000B888: d402a00c                 ld      [%o2+0xC], %o2
F000B88C: 92102000                 mov     0, %o1
F000B890: ec02a038                 ld      [%o2+0x38], %l6
F000B894: a007bfa8                 add     %fp, var_58, %l0
F000B898: d005c000                 ld      [%l7], %o0
F000B89C: 40006e87                 call    _pn_get
F000B8A0: 94100010                 mov     %l0, %o2
F000B8A4: b0920000                 orcc    %o0, %g0, %i0
F000B8A8: 128002b8                 bne     loc_F000C388
F000B8AC: d004e1dc                 ld      [%l3+%lo(dword_F0133DDC)], %o0
F000B8B0: 90100010                 mov     %l0, %o0
F000B8B4: 92102001                 mov     1, %o1
F000B8B8: 94102000                 mov     0, %o2
F000B8BC: 40006c54                 call    _lookuppn
F000B8C0: 9607bf34                 add     %fp, var_CC, %o3
F000B8C4: b0920000                 orcc    %o0, %g0, %i0
F000B8C8: 12800005                 bne     loc_F000B8DC
F000B8CC: d007bf34                 ld      [%fp+var_CC], %o0
F000B8D0: 80a22000                 cmp     %o0, 0
F000B8D4: 32800006                 bne,a   loc_F000B8EC
F000B8D8: d405a01c                 ld      [%l6+0x1C], %o2
F000B8DC: 40006f03                 call    _pn_free
F000B8E0: 90100010                 mov     %l0, %o0
F000B8E4: 108002a9                 ba      loc_F000C388
F000B8E8: d004e1dc                 ld      [%l3+0x1DC], %o0
F000B8EC: d602201c                 ld      [%o0+0x1C], %o3
F000B8F0: c027beec                 clr     [%fp+var_114]
F000B8F4: fa52a002                 ldsh    [%o2+2], %i5
F000B8F8: b2102000                 mov     0, %i1
F000B8FC: c652a004                 ldsh    [%o2+4], %g3
F000B900: 9207bfb8                 add     %fp, var_48, %o1
F000B904: d602e014                 ld      [%o3+0x14], %o3
F000B908: 9fc2c000                 call    %o3
F000B90C: c627bef4                 st      %g3, [%fp+var_10C]
F000B910: b0920000                 orcc    %o0, %g0, %i0
F000B914: 1280028b                 bne     loc_F000C340
F000B918: d007bf34                 ld      [%fp+var_CC], %o0
F000B91C: d0022024                 ld      [%o0+0x24], %o0
F000B920: d002200c                 ld      [%o0+0xC], %o0
F000B924: 808a2008                 btst    8, %o0
F000B928: 12800018                 bne     loc_F000B988
F000B92C: d207bfbc                 ld      [%fp+var_44], %o1
F000B930: d017bfbc                 lduh    [%fp+var_44], %o0
F000B934: 808a2c00                 btst    0xC00, %o0
F000B938: 02800024                 be      loc_F000B9C8
F000B93C: d0052260                 ld      [%l4+0x260], %o0
F000B940: 40017179                 call    _task_secure
F000B944: d002200c                 ld      [%o0+0xC], %o0
F000B948: 80a22000                 cmp     %o0, 0
F000B94C: 0280000a                 be      loc_F000B974
F000B950: d017bfbc                 lduh    [%fp+var_44], %o0
F000B954: 808a2800                 btst    0x800, %o0
F000B958: 32800002                 bne,a   loc_F000B960
F000B95C: fa57bfbe                 ldsh    [%fp+var_44+2], %i5
F000B960: 808a2400                 btst    0x400, %o0
F000B964: 02800019                 be      loc_F000B9C8
F000B968: c657bfc0                 ldsh    [%fp+var_40], %g3
F000B96C: 10800017                 ba      loc_F000B9C8
F000B970: c627bef4                 st      %g3, [%fp+var_10C]
F000B974: 113c042b90122278         set     aSPrivilegesDis, %o0! "%s: privileges disabled because of outs"...
F000B97C: 40002349                 call    _uprintf
F000B980: 9205a008                 add     %l6, 8, %o1
F000B984: 30800011                 ba,a    loc_F000B9C8
F000B988: 11030000                 sethi   0xC000000, %o0
F000B98C: 808a4008                 btst    %o0, %o1
F000B990: 0280000e                 be      loc_F000B9C8
F000B994: 92102000                 mov     0, %o1
F000B998: d005c000                 ld      [%l7], %o0
F000B99C: a007bf20                 add     %fp, var_E0, %l0
F000B9A0: 40006e46                 call    _pn_get
F000B9A4: 94100010                 mov     %l0, %o2
F000B9A8: b0920000                 orcc    %o0, %g0, %i0
F000B9AC: 12800265                 bne     loc_F000C340
F000B9B0: d207bf20                 ld      [%fp+var_E0], %o1
F000B9B4: 113c042b                 sethi   %hi(aSSetuidExecuti), %o0! "%s: Setuid execution not allowed\n"
F000B9B8: 4000233a                 call    _uprintf
F000B9BC: 901222c0                 bset    %lo(aSSetuidExecuti), %o0! "%s: Setuid execution not allowed\n"
F000B9C0: 40006eca                 call    _pn_free
F000B9C4: 90100010                 mov     %l0, %o0
F000B9C8: 400002f9                 call    _check_exec_access
F000B9CC: d007bf34                 ld      [%fp+var_CC], %o0
F000B9D0: b0920000                 orcc    %o0, %g0, %i0
F000B9D4: 1280025b                 bne     loc_F000C340
F000B9D8: 90102000                 mov     0, %o0
F000B9DC: c02fbf38                 clrb    [%fp+var_C8]
F000B9E0: 9407bf38                 add     %fp, var_C8, %o2
F000B9E4: 96102020                 mov     0x20, %o3 ! ' '
F000B9E8: 98102000                 mov     0, %o4
F000B9EC: 9a102001                 mov     1, %o5
F000B9F0: d207bf34                 ld      [%fp+var_CC], %o1
F000B9F4: 84102001                 mov     1, %g2
F000B9F8: c423a05c                 st      %g2, [%sp+0x190+var_134]
F000B9FC: 8407bf1c                 add     %fp, var_E4, %g2
F000BA00: 40007415                 call    _vn_rdwr
F000BA04: c423a060                 st      %g2, [%sp+0x190+var_130]
F000BA08: b0920000                 orcc    %o0, %g0, %i0
F000BA0C: 1280024d                 bne     loc_F000C340
F000BA10: d007bf1c                 ld      [%fp+var_E4], %o0
F000BA14: 80a22018                 cmp     %o0, 0x18
F000BA18: 08800005                 bleu    loc_F000BA2C
F000BA1C: d04fbf38                 ldsb    [%fp+var_C8], %o0
F000BA20: 80a22023                 cmp     %o0, 0x23 ! '#'
F000BA24: 32800247                 bne,a   loc_F000C340
F000BA28: b0102008                 mov     8, %i0
F000BA2C: d207bf38                 ld      [%fp+var_C8], %o1
F000BA30: 113fbb7e9a1222ce         set     -0x1120532, %o5
F000BA38: b807bf38                 add     %fp, var_C8, %i4
F000BA3C: 80a2400d                 cmp     %o1, %o5
F000BA40: 12800004                 bne     loc_F000BA50
F000BA44: f827bedc                 st      %i4, [%fp+var_124]
F000BA48: 1080009b                 ba      loc_F000BCB4
F000BA4C: c027bee4                 clr     [%fp+var_11C]
F000BA50: 1132bfae901222be         set     -0x35014542, %o0
F000BA58: 80a24008                 cmp     %o1, %o0
F000BA5C: 0280001c                 be      loc_F000BACC
F000BA60: 86102001                 mov     1, %g3
F000BA64: d027bf00                 st      %o0, [%fp+var_100]
F000BA68: 11003fff981223ff         set     0xFFFFFF, %o4
F000BA70: d00fbf03                 ldub    [%fp+var_100+3], %o0
F000BA74: a20c400c                 and     %l1, %o4, %l1
F000BA78: 912a2018                 sll     %o0, 24, %o0
F000BA7C: a2144008                 bset    %o0, %l1
F000BA80: 113fc03f961223ff         set     -0xFF0001, %o3
F000BA88: d00fbf02                 ldub    [%fp+var_100+2], %o0
F000BA8C: a20c400b                 and     %l1, %o3, %l1
F000BA90: 912a2010                 sll     %o0, 16, %o0
F000BA94: a2144008                 bset    %o0, %l1
F000BA98: 113fffc0941220ff         set     -0xFF01, %o2
F000BAA0: d00fbf01                 ldub    [%fp+var_100+1], %o0
F000BAA4: a20c400a                 and     %l1, %o2, %l1
F000BAA8: 912a2008                 sll     %o0, 8, %o0
F000BAAC: a2144008                 bset    %o0, %l1
F000BAB0: d00fbf00                 ldub    [%fp+var_100], %o0
F000BAB4: a20c7f00                 and     %l1, -0x100, %l1
F000BAB8: a2144008                 bset    %o0, %l1
F000BABC: 80a24011                 cmp     %o1, %l1
F000BAC0: 32800005                 bne,a   loc_F000BAD4
F000BAC4: da27bf00                 st      %o5, [%fp+var_100]
F000BAC8: 86102001                 mov     1, %g3
F000BACC: 1080007a                 ba      loc_F000BCB4
F000BAD0: c627bee4                 st      %g3, [%fp+var_11C]
F000BAD4: d00fbf03                 ldub    [%fp+var_100+3], %o0
F000BAD8: a40c800c                 and     %l2, %o4, %l2
F000BADC: 912a2018                 sll     %o0, 24, %o0
F000BAE0: a4148008                 bset    %o0, %l2
F000BAE4: d00fbf02                 ldub    [%fp+var_100+2], %o0
F000BAE8: a40c800b                 and     %l2, %o3, %l2
F000BAEC: 912a2010                 sll     %o0, 16, %o0
F000BAF0: a4148008                 bset    %o0, %l2
F000BAF4: d00fbf01                 ldub    [%fp+var_100+1], %o0
F000BAF8: a40c800a                 and     %l2, %o2, %l2
F000BAFC: 912a2008                 sll     %o0, 8, %o0
F000BB00: a4148008                 bset    %o0, %l2
F000BB04: d00fbf00                 ldub    [%fp+var_100], %o0
F000BB08: a40cbf00                 and     %l2, -0x100, %l2
F000BB0C: a4148008                 bset    %o0, %l2
F000BB10: 80a24012                 cmp     %o1, %l2
F000BB14: 12800004                 bne     loc_F000BB24
F000BB18: 113fffc0                 sethi   -0x10000, %o0
F000BB1C: 10800209                 ba      loc_F000C340
F000BB20: b0102054                 mov     0x54, %i0 ! 'T'
F000BB24: 900a4008                 and     %o1, %o0, %o0
F000BB28: 1308c840                 sethi   0x23210000, %o1
F000BB2C: 80a20009                 cmp     %o0, %o1
F000BB30: 12800204                 bne     loc_F000C340
F000BB34: b0102008                 mov     8, %i0
F000BB38: 80a66000                 cmp     %i1, 0
F000BB3C: 12800201                 bne     loc_F000C340
F000BB40: a007bf3a                 add     %fp, var_C8+2, %l0
F000BB44: 9007bf58                 add     %fp, var_A8, %o0
F000BB48: 80a40008                 cmp     %l0, %o0
F000BB4C: 3a800012                 bcc,a   loc_F000BB94
F000BB50: d04c0000                 ldsb    [%l0], %o0
F000BB54: 94102020                 mov     0x20, %o2 ! ' '! size_t
F000BB58: 92100008                 mov     %o0, %o1
F000BB5C: d04c0000                 ldsb    [%l0], %o0
F000BB60: 80a22009                 cmp     %o0, 9
F000BB64: 02800006                 be      loc_F000BB7C
F000BB68: 80a2200a                 cmp     %o0, 0xA
F000BB6C: 32800006                 bne,a   loc_F000BB84
F000BB70: a0042001                 inc     %l0
F000BB74: 10800007                 ba      loc_F000BB90
F000BB78: c02c0000                 clrb    [%l0]
F000BB7C: d42c0000                 stb     %o2, [%l0]
F000BB80: a0042001                 inc     %l0
F000BB84: 80a40009                 cmp     %l0, %o1
F000BB88: 2abffff6                 bcs,a   loc_F000BB60
F000BB8C: d04c0000                 ldsb    [%l0], %o0
F000BB90: d04c0000                 ldsb    [%l0], %o0
F000BB94: 80a22000                 cmp     %o0, 0
F000BB98: 128001ea                 bne     loc_F000C340
F000BB9C: b0102008                 mov     8, %i0
F000BBA0: d04fbf3a                 ldsb    [%fp+var_C8+2], %o0
F000BBA4: 80a22020                 cmp     %o0, 0x20 ! ' '
F000BBA8: 12800007                 bne     loc_F000BBC4
F000BBAC: a007bf3a                 add     %fp, var_C8+2, %l0
F000BBB0: a0042001                 inc     %l0
F000BBB4: d04c0000                 ldsb    [%l0], %o0
F000BBB8: 80a22020                 cmp     %o0, 0x20 ! ' '
F000BBBC: 22bffffe                 be,a    loc_F000BBB4
F000BBC0: a0042001                 inc     %l0
F000BBC4: d04c0000                 ldsb    [%l0], %o0
F000BBC8: 10800007                 ba      loc_F000BBE4
F000BBCC: a6100010                 mov     %l0, %l3
F000BBD0: 80a26020                 cmp     %o1, 0x20 ! ' '
F000BBD4: 22800008                 be,a    loc_F000BBF4
F000BBD8: c02fbf88                 clrb    [%fp+var_78]
F000BBDC: a0042001                 inc     %l0
F000BBE0: d04c0000                 ldsb    [%l0], %o0
F000BBE4: 80a22000                 cmp     %o0, 0
F000BBE8: 12bffffa                 bne     loc_F000BBD0
F000BBEC: d20c0000                 ldub    [%l0], %o1
F000BBF0: c02fbf88                 clrb    [%fp+var_78]
F000BBF4: d04c0000                 ldsb    [%l0], %o0
F000BBF8: 80a22000                 cmp     %o0, 0
F000BBFC: 02800010                 be      loc_F000BC3C
F000BC00: d007bf34                 ld      [%fp+var_CC], %o0
F000BC04: c02c0000                 clrb    [%l0]
F000BC08: a0042001                 inc     %l0
F000BC0C: d04c0000                 ldsb    [%l0], %o0
F000BC10: 80a22020                 cmp     %o0, 0x20 ! ' '
F000BC14: 22bffffe                 be,a    loc_F000BC0C
F000BC18: a0042001                 inc     %l0
F000BC1C: d04c0000                 ldsb    [%l0], %o0
F000BC20: 80a22000                 cmp     %o0, 0
F000BC24: 02800005                 be      loc_F000BC38
F000BC28: 90100010                 mov     %l0, %o0! void *
F000BC2C: 9207bf88                 add     %fp, var_78, %o1! void *
F000BC30: 400223b8                 call    _bcopy
F000BC34: 94102020                 mov     0x20, %o2 ! ' '
F000BC38: d007bf34                 ld      [%fp+var_CC], %o0
F000BC3C: 400073ca                 call    _vn_rele
F000BC40: b2102001                 mov     1, %i1
F000BC44: c027bf34                 clr     [%fp+var_CC]
F000BC48: a007bfa8                 add     %fp, var_58, %l0
F000BC4C: 90100010                 mov     %l0, %o0
F000BC50: 40006dbf                 call    _pn_set
F000BC54: 92100013                 mov     %l3, %o1
F000BC58: b0920000                 orcc    %o0, %g0, %i0
F000BC5C: 128001b9                 bne     loc_F000C340
F000BC60: 90100010                 mov     %l0, %o0
F000BC64: 92102001                 mov     1, %o1
F000BC68: 94102000                 mov     0, %o2
F000BC6C: 40006b68                 call    _lookuppn
F000BC70: 9607bf34                 add     %fp, var_CC, %o3
F000BC74: b0920000                 orcc    %o0, %g0, %i0
F000BC78: 128001b2                 bne     loc_F000C340
F000BC7C: 113c04cf                 sethi   %hi(_active_u), %o0
F000BC80: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F000BC84: d402201c                 ld      [%o0+0x1C], %o2
F000BC88: d007bf34                 ld      [%fp+var_CC], %o0
F000BC8C: d602201c                 ld      [%o0+0x1C], %o3
F000BC90: d602e014                 ld      [%o3+0x14], %o3
F000BC94: 9fc2c000                 call    %o3
F000BC98: 9207bfb8                 add     %fp, var_48, %o1
F000BC9C: b0920000                 orcc    %o0, %g0, %i0
F000BCA0: 02bfff4a                 be      loc_F000B9C8
F000BCA4: 01000000                 nop
F000BCA8: 308001a6                 ba,a    loc_F000C340
F000BCAC: 10800076                 ba      loc_F000BE84
F000BCB0: b010200e                 mov     0xE, %i0
F000BCB4: aa102000                 mov     0, %l5
F000BCB8: b4102000                 mov     0, %i2
F000BCBC: a6102000                 mov     0, %l3
F000BCC0: 113c04d0                 sethi   %hi(_kernel_pageable_map), %o0
F000BCC4: d00220c0                 ld      [%o0+%lo(_kernel_pageable_map)], %o0
F000BCC8: 4001e07f                 call    _kmem_alloc_wait
F000BCCC: 13000028                 sethi   0xA000, %o1
F000BCD0: d027beec                 st      %o0, [%fp+var_114]
F000BCD4: d005e004                 ld      [%l7+4], %o0
F000BCD8: 29000028                 sethi   0xA000, %l4
F000BCDC: 80a22000                 cmp     %o0, 0
F000BCE0: 02800069                 be      loc_F000BE84
F000BCE4: e007beec                 ld      [%fp+var_114], %l0
F000BCE8: 11000027b61223fe         set     0x9FFE, %i3
F000BCF0: a2102000                 mov     0, %l1
F000BCF4: 80a66000                 cmp     %i1, 0
F000BCF8: 0280000b                 be      loc_F000BD24
F000BCFC: a4102000                 mov     0, %l2
F000BD00: 80a56000                 cmp     %l5, 0
F000BD04: 12800008                 bne     loc_F000BD24
F000BD08: 80a66000                 cmp     %i1, 0
F000BD0C: e207bfa8                 ld      [%fp+var_58], %l1
F000BD10: d005e004                 ld      [%l7+4], %o0
F000BD14: a4100011                 mov     %l1, %l2
F000BD18: 90022004                 inc     4, %o0
F000BD1C: 10800024                 ba      loc_F000BDAC
F000BD20: d025e004                 st      %o0, [%l7+4]
F000BD24: 0280000b                 be      loc_F000BD50
F000BD28: 80a56001                 cmp     %l5, 1
F000BD2C: 1280000a                 bne     loc_F000BD54
F000BD30: 80a66000                 cmp     %i1, 0
F000BD34: d04fbf88                 ldsb    [%fp+var_78], %o0
F000BD38: 80a22000                 cmp     %o0, 0
F000BD3C: 02800006                 be      loc_F000BD54
F000BD40: 80a66000                 cmp     %i1, 0
F000BD44: a207bf88                 add     %fp, var_78, %l1
F000BD48: 10800019                 ba      loc_F000BDAC
F000BD4C: a4100011                 mov     %l1, %l2
F000BD50: 80a66000                 cmp     %i1, 0
F000BD54: 0280000c                 be      loc_F000BD84
F000BD58: 80a56001                 cmp     %l5, 1
F000BD5C: 02800008                 be      loc_F000BD7C
F000BD60: 80a56002                 cmp     %l5, 2
F000BD64: 32800009                 bne,a   loc_F000BD88
F000BD68: d005e004                 ld      [%l7+4], %o0
F000BD6C: d04fbf88                 ldsb    [%fp+var_78], %o0
F000BD70: 80a22000                 cmp     %o0, 0
F000BD74: 22800005                 be,a    loc_F000BD88
F000BD78: d005e004                 ld      [%l7+4], %o0
F000BD7C: 1080000c                 ba      loc_F000BDAC
F000BD80: e205c000                 ld      [%l7], %l1
F000BD84: d005e004                 ld      [%l7+4], %o0
F000BD88: 80a22000                 cmp     %o0, 0
F000BD8C: 02800009                 be      loc_F000BDB0
F000BD90: 80a46000                 cmp     %l1, 0
F000BD94: 4001f898                 call    _fuword
F000BD98: 01000000                 nop
F000BD9C: d205e004                 ld      [%l7+4], %o1
F000BDA0: a2100008                 mov     %o0, %l1
F000BDA4: 92026004                 inc     4, %o1
F000BDA8: d225e004                 st      %o1, [%l7+4]
F000BDAC: 80a46000                 cmp     %l1, 0
F000BDB0: 1280000f                 bne     loc_F000BDEC
F000BDB4: 80a46000                 cmp     %l1, 0
F000BDB8: d005e008                 ld      [%l7+8], %o0
F000BDBC: 80a22000                 cmp     %o0, 0
F000BDC0: 0280000b                 be      loc_F000BDEC
F000BDC4: 80a46000                 cmp     %l1, 0
F000BDC8: 4001f88b                 call    _fuword
F000BDCC: c025e004                 clr     [%l7+4]
F000BDD0: a2920000                 orcc    %o0, %g0, %l1
F000BDD4: 2280002c                 be,a    loc_F000BE84
F000BDD8: 80a47fff                 cmp     %l1, -1
F000BDDC: d005e008                 ld      [%l7+8], %o0
F000BDE0: b406a001                 inc     %i2
F000BDE4: 90022004                 inc     4, %o0
F000BDE8: d025e008                 st      %o0, [%l7+8]
F000BDEC: 02800026                 be      loc_F000BE84
F000BDF0: 80a47fff                 cmp     %l1, -1
F000BDF4: 02bfffae                 be      loc_F000BCAC
F000BDF8: aa056001                 inc     %l5
F000BDFC: 1080001b                 ba      loc_F000BE68
F000BE00: 80a4c01b                 cmp     %l3, %i3
F000BE04: 0280000a                 be      loc_F000BE2C
F000BE08: 90100012                 mov     %l2, %o0
F000BE0C: 92100010                 mov     %l0, %o1
F000BE10: 94100014                 mov     %l4, %o2
F000BE14: 4002302c                 call    _copystr
F000BE18: 9607befc                 add     %fp, var_104, %o3
F000BE1C: d207befc                 ld      [%fp+var_104], %o1
F000BE20: b0100008                 mov     %o0, %i0
F000BE24: 1080000a                 ba      loc_F000BE4C
F000BE28: a4048009                 add     %l2, %o1, %l2
F000BE2C: 90100011                 mov     %l1, %o0
F000BE30: 92100010                 mov     %l0, %o1
F000BE34: 94100014                 mov     %l4, %o2
F000BE38: 40022fbb                 call    _copyinstr
F000BE3C: 9607befc                 add     %fp, var_104, %o3
F000BE40: d207befc                 ld      [%fp+var_104], %o1
F000BE44: b0100008                 mov     %o0, %i0
F000BE48: a2044009                 add     %l1, %o1, %l1
F000BE4C: d007befc                 ld      [%fp+var_104], %o0
F000BE50: 80a62002                 cmp     %i0, 2
F000BE54: a0040008                 add     %l0, %o0, %l0
F000BE58: a604c008                 add     %l3, %o0, %l3
F000BE5C: 12800006                 bne     loc_F000BE74
F000BE60: a8250008                 sub     %l4, %o0, %l4
F000BE64: 80a4c01b                 cmp     %l3, %i3
F000BE68: 04bfffe7                 ble     loc_F000BE04
F000BE6C: 80a4a000                 cmp     %l2, 0
F000BE70: b0102007                 mov     7, %i0
F000BE74: 80a62000                 cmp     %i0, 0
F000BE78: 12800132                 bne     loc_F000C340
F000BE7C: a2102000                 mov     0, %l1
F000BE80: 30bfff9d                 ba,a    loc_F000BCF4
F000BE84: 9004e003                 add     %l3, 3, %o0
F000BE88: c607bee4                 ld      [%fp+var_11C], %g3
F000BE8C: 80a0e000                 cmp     %g3, 0
F000BE90: 02800026                 be      loc_F000BF28
F000BE94: a60a3ffc                 and     %o0, -4, %l3
F000BE98: d007bf34                 ld      [%fp+var_CC], %o0
F000BE9C: d207bedc                 ld      [%fp+var_124], %o1
F000BEA0: 400179e9                 call    _fatfile_getarch
F000BEA4: 9407bf70                 add     %fp, var_90, %o2
F000BEA8: 80a22000                 cmp     %o0, 0
F000BEAC: 1280007c                 bne     loc_F000C09C
F000BEB0: 9407bf38                 add     %fp, var_C8, %o2
F000BEB4: 90102000                 mov     0, %o0
F000BEB8: 9610201c                 mov     0x1C, %o3
F000BEBC: d207bf34                 ld      [%fp+var_CC], %o1
F000BEC0: 9a102001                 mov     1, %o5
F000BEC4: d807bf78                 ld      [%fp+var_88], %o4
F000BEC8: 84102001                 mov     1, %g2
F000BECC: c423a05c                 st      %g2, [%sp+0x190+var_134]
F000BED0: 8407bf1c                 add     %fp, var_E4, %g2
F000BED4: 400072e0                 call    _vn_rdwr
F000BED8: c423a060                 st      %g2, [%sp+0x190+var_130]
F000BEDC: b0920000                 orcc    %o0, %g0, %i0
F000BEE0: 12800118                 bne     loc_F000C340
F000BEE4: d007bf1c                 ld      [%fp+var_E4], %o0
F000BEE8: 80a22000                 cmp     %o0, 0
F000BEEC: 22800004                 be,a    loc_F000BEFC
F000BEF0: d2070000                 ld      [%i4], %o1
F000BEF4: 10800113                 ba      loc_F000C340
F000BEF8: b0102053                 mov     0x53, %i0 ! 'S'
F000BEFC: 113fbb7e901222ce         set     -0x1120532, %o0
F000BF04: 80a24008                 cmp     %o1, %o0
F000BF08: 02800004                 be      loc_F000BF18
F000BF0C: d007bf34                 ld      [%fp+var_CC], %o0
F000BF10: 1080010c                 ba      loc_F000C340
F000BF14: b0102008                 mov     8, %i0
F000BF18: d407bf78                 ld      [%fp+var_88], %o2
F000BF1C: 9210001c                 mov     %i4, %o1
F000BF20: 10800007                 ba      loc_F000BF3C
F000BF24: d607bf7c                 ld      [%fp+var_84], %o3
F000BF28: d007bf34                 ld      [%fp+var_CC], %o0
F000BF2C: 9210001c                 mov     %i4, %o1
F000BF30: d6020000                 ld      [%o0], %o3
F000BF34: 94102000                 mov     0, %o2
F000BF38: d602e014                 ld      [%o3+0x14], %o3! flags
F000BF3C: 40017a14                 call    _load_machfile
F000BF40: 9807bf58                 add     %fp, var_A8, %o4! new_protection
F000BF44: 80a22000                 cmp     %o0, 0
F000BF48: 12800055                 bne     loc_F000C09C
F000BF4C: 01000000                 nop
F000BF50: d2058000                 ld      [%l6], %o1
F000BF54: d0026028                 ld      [%o1+0x28], %o0
F000BF58: 808a2010                 btst    0x10, %o0
F000BF5C: 32800027                 bne,a   loc_F000BFF8
F000BF60: 90102006                 mov     6, %o0
F000BF64: 40000aef                 call    _get_posix_proc
F000BF68: d0526030                 ldsh    [%o1+0x30], %o0
F000BF6C: 133c04cf                 sethi   %hi(_active_u), %o1
F000BF70: d20261d8                 ld      [%o1+%lo(_active_u)], %o1
F000BF74: a0100008                 mov     %o0, %l0
F000BF78: 40017393                 call    _lock_write
F000BF7C: 90026020                 add     %o1, 0x20, %o0 ! ' '
F000BF80: d205a01c                 ld      [%l6+0x1C], %o1
F000BF84: d0526002                 ldsh    [%o1+2], %o0
F000BF88: 80a74008                 cmp     %i5, %o0
F000BF8C: 12800006                 bne     loc_F000BFA4
F000BF90: c607bef4                 ld      [%fp+var_10C], %g3
F000BF94: d0526004                 ldsh    [%o1+4], %o0
F000BF98: 80a0c008                 cmp     %g3, %o0
F000BF9C: 22800006                 be,a    loc_F000BFB4
F000BFA0: d005a01c                 ld      [%l6+0x1C], %o0
F000BFA4: 40000eb3                 call    _crcopy
F000BFA8: 90100009                 mov     %o1, %o0
F000BFAC: d025a01c                 st      %o0, [%l6+0x1C]
F000BFB0: d005a01c                 ld      [%l6+0x1C], %o0
F000BFB4: fa322002                 sth     %i5, [%o0+2]
F000BFB8: d0058000                 ld      [%l6], %o0
F000BFBC: c617bef6                 lduh    [%fp+var_10C+2], %g3
F000BFC0: fa32202c                 sth     %i5, [%o0+0x2C]
F000BFC4: d005a01c                 ld      [%l6+0x1C], %o0
F000BFC8: c6322004                 sth     %g3, [%o0+4]
F000BFCC: 113c04cf                 sethi   %hi(_active_u), %o0
F000BFD0: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F000BFD4: 40017418                 call    _lock_done
F000BFD8: 90022020                 inc     0x20, %o0 ! ' '
F000BFDC: c617bef6                 lduh    [%fp+var_10C+2], %g3
F000BFE0: c6342008                 sth     %g3, [%l0+8]
F000BFE4: d005a01c                 ld      [%l6+0x1C], %o0
F000BFE8: d0122006                 lduh    [%o0+6], %o0
F000BFEC: d0342004                 sth     %o0, [%l0+4]
F000BFF0: 10800005                 ba      loc_F000C004
F000BFF4: fa342006                 sth     %i5, [%l0+6]
F000BFF8: 92102000                 mov     0, %o1
F000BFFC: 40015f88                 call    _exception_from_kernel
F000C000: 94102000                 mov     0, %o2
F000C004: 233c0447                 sethi   %hi(_page_size), %l1
F000C008: d404613c                 ld      [%l1+%lo(_page_size)], %o2! size
F000C00C: 213c04d0                 sethi   %hi(_active_threads), %l0
F000C010: d0042260                 ld      [%l0+%lo(_active_threads)], %o0
F000C014: c027bef8                 clr     [%fp+var_108]
F000C018: d002200c                 ld      [%o0+0xC], %o0
F000C01C: 9207bef8                 add     %fp, var_108, %o1! address
F000C020: d002200c                 ld      [%o0+0xC], %o0! target_task
F000C024: 4001f9ff                 call    _vm_allocate
F000C028: 96102000                 mov     0, %o3
F000C02C: 80a22000                 cmp     %o0, 0
F000C030: 1280000b                 bne     loc_F000C05C
F000C034: 80a62000                 cmp     %i0, 0
F000C038: d404613c                 ld      [%l1+%lo(_page_size)], %o2! size
F000C03C: d0042260                 ld      [%l0+%lo(_active_threads)], %o0
F000C040: 92102000                 mov     0, %o1! address
F000C044: d002200c                 ld      [%o0+0xC], %o0
F000C048: 96102000                 mov     0, %o3! set_maximum
F000C04C: d002200c                 ld      [%o0+0xC], %o0! target_task
F000C050: 4001fa3b                 call    _vm_protect
F000C054: 98102000                 mov     0, %o4
F000C058: 80a62000                 cmp     %i0, 0
F000C05C: 128000b9                 bne     loc_F000C340
F000C060: 01000000                 nop
F000C064: 400072c0                 call    _vn_rele
F000C068: d007bf34                 ld      [%fp+var_CC], %o0
F000C06C: d007bf68                 ld      [%fp+var_98], %o0
F000C070: 80a22000                 cmp     %o0, 0
F000C074: 1680000e                 bge     loc_F000C0AC
F000C078: c027bf34                 clr     [%fp+var_CC]
F000C07C: d0042260                 ld      [%l0+0x260], %o0
F000C080: d207bf60                 ld      [%fp+var_A0], %o1
F000C084: d002200c                 ld      [%o0+0xC], %o0
F000C088: 400000c3                 call    _create_unix_stack
F000C08C: d002200c                 ld      [%o0+0xC], %o0
F000C090: 80a22000                 cmp     %o0, 0
F000C094: 02800006                 be      loc_F000C0AC
F000C098: 90102005                 mov     5, %o0
F000C09C: 40000175                 call    sub_F000C670
F000C0A0: 01000000                 nop
F000C0A4: 108000a7                 ba      loc_F000C340
F000C0A8: b0100008                 mov     %o0, %i0
F000C0AC: d0058000                 ld      [%l6], %o0
F000C0B0: d207bf68                 ld      [%fp+var_98], %o1
F000C0B4: 80a26000                 cmp     %o1, 0
F000C0B8: 16800043                 bge     loc_F000C1C4
F000C0BC: e4022084                 ld      [%o0+0x84], %l2
F000C0C0: 11100000                 sethi   0x40000000, %o0
F000C0C4: 808a4008                 btst    %o0, %o1
F000C0C8: 02800010                 be      loc_F000C108
F000C0CC: 912d6002                 sll     %l5, 2, %o0
F000C0D0: 9004c008                 add     %l3, %o0, %o0
F000C0D4: 9002201b                 inc     0x1B, %o0
F000C0D8: 900a3ff8                 and     %o0, -8, %o0
F000C0DC: a2248008                 sub     %l2, %o0, %l1
F000C0E0: d207bf58                 ld      [%fp+var_A8], %o1
F000C0E4: 4001f7ba                 call    _suword
F000C0E8: 90100011                 mov     %l1, %o0
F000C0EC: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F000C0F0: d00221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o0
F000C0F4: 92047fc0                 add     %l1, -0x40, %o1
F000C0F8: d0020000                 ld      [%o0], %o0
F000C0FC: a2046004                 inc     4, %l1
F000C100: 1080000b                 ba      loc_F000C12C
F000C104: d2222044                 st      %o1, [%o0+0x44]
F000C108: 9004c008                 add     %l3, %o0, %o0
F000C10C: 90022017                 inc     0x17, %o0
F000C110: 900a3ff8                 and     %o0, -8, %o0
F000C114: 133c04cf                 sethi   %hi(dword_F0133DDC), %o1
F000C118: d20261dc                 ld      [%o1+%lo(dword_F0133DDC)], %o1
F000C11C: a2248008                 sub     %l2, %o0, %l1
F000C120: d2024000                 ld      [%o1], %o1
F000C124: 90047fc0                 add     %l1, -0x40, %o0
F000C128: d0226044                 st      %o0, [%o1+0x44]
F000C12C: 912d6002                 sll     %l5, 2, %o0
F000C130: 90044008                 add     %l1, %o0, %o0
F000C134: a402200c                 add     %o0, 0xC, %l2
F000C138: 90100011                 mov     %l1, %o0
F000C13C: 4001f7a4                 call    _suword
F000C140: 9225401a                 sub     %l5, %i2, %o1
F000C144: e007beec                 ld      [%fp+var_114], %l0
F000C148: 29000028                 sethi   0xA000, %l4
F000C14C: 80a5401a                 cmp     %l5, %i2
F000C150: 12800006                 bne     loc_F000C168
F000C154: a2046004                 inc     4, %l1
F000C158: 90100011                 mov     %l1, %o0
F000C15C: 4001f79c                 call    _suword
F000C160: 92102000                 mov     0, %o1
F000C164: a2046004                 inc     4, %l1
F000C168: aa857fff                 inccc   -1, %l5
F000C16C: 0c800013                 bneg    loc_F000C1B8
F000C170: 90100011                 mov     %l1, %o0
F000C174: 4001f796                 call    _suword
F000C178: 92100012                 mov     %l2, %o1
F000C17C: 90100010                 mov     %l0, %o0
F000C180: 92100012                 mov     %l2, %o1
F000C184: 94100014                 mov     %l4, %o2
F000C188: 40022f6a                 call    _copyoutstr
F000C18C: 9607befc                 add     %fp, var_104, %o3
F000C190: b0100008                 mov     %o0, %i0
F000C194: d007befc                 ld      [%fp+var_104], %o0
F000C198: 80a62002                 cmp     %i0, 2
F000C19C: a4048008                 add     %l2, %o0, %l2
F000C1A0: a0040008                 add     %l0, %o0, %l0
F000C1A4: 02bffff6                 be      loc_F000C17C
F000C1A8: a8250008                 sub     %l4, %o0, %l4
F000C1AC: 80a6200e                 cmp     %i0, 0xE
F000C1B0: 12bfffe8                 bne     loc_F000C150
F000C1B4: 80a5401a                 cmp     %l5, %i2
F000C1B8: 90100011                 mov     %l1, %o0
F000C1BC: 4001f784                 call    _suword
F000C1C0: 92102000                 mov     0, %o1
F000C1C4: 153c04cf                 sethi   %hi(dword_F0133DDC), %o2
F000C1C8: d002a1dc                 ld      [%o2+%lo(dword_F0133DDC)], %o0
F000C1CC: d2020000                 ld      [%o0], %o1
F000C1D0: d007bf5c                 ld      [%fp+var_A4], %o0
F000C1D4: d0226004                 st      %o0, [%o1+4]
F000C1D8: d202a1dc                 ld      [%o2+%lo(dword_F0133DDC)], %o1
F000C1DC: d007bf5c                 ld      [%fp+var_A4], %o0
F000C1E0: d2024000                 ld      [%o1], %o1
F000C1E4: 90022004                 inc     4, %o0
F000C1E8: d0226008                 st      %o0, [%o1+8]
F000C1EC: e2058000                 ld      [%l6], %l1
F000C1F0: d0046024                 ld      [%l1+0x24], %o0! int
F000C1F4: 80a22000                 cmp     %o0, 0
F000C1F8: 22800014                 be,a    loc_F000C248
F000C1FC: c025a148                 clr     [%l6+0x148]
F000C200: a4102001                 mov     1, %l2
F000C204: e0046024                 ld      [%l1+0x24], %l0
F000C208: 7fffef69                 call    _ffs
F000C20C: 90100010                 mov     %l0, %o0
F000C210: a6100008                 mov     %o0, %l3
F000C214: 9004ffff                 add     %l3, -1, %o0
F000C218: 912c8008                 sll     %l2, %o0, %o0
F000C21C: 902c0008                 andn    %l0, %o0, %o0
F000C220: d0246024                 st      %o0, [%l1+0x24]
F000C224: 912ce002                 sll     %l3, 2, %o0
F000C228: 90020016                 add     %o0, %l6, %o0
F000C22C: c0222030                 clr     [%o0+0x30]
F000C230: e2058000                 ld      [%l6], %l1
F000C234: d0046024                 ld      [%l1+0x24], %o0
F000C238: 80a22000                 cmp     %o0, 0
F000C23C: 32bffff3                 bne,a   loc_F000C208
F000C240: e0046024                 ld      [%l1+0x24], %l0
F000C244: c025a148                 clr     [%l6+0x148]
F000C248: c025a144                 clr     [%l6+0x144]
F000C24C: c025a138                 clr     [%l6+0x138]
F000C250: e605a154                 ld      [%l6+0x154], %l3
F000C254: 80a4e000                 cmp     %l3, 0
F000C258: 06800018                 bl      loc_F000C2B8
F000C25C: c025a13c                 clr     [%l6+0x13C]
F000C260: d005a150                 ld      [%l6+0x150], %o0
F000C264: d00a0013                 ldub    [%o0+%l3], %o0
F000C268: 808a2001                 btst    1, %o0
F000C26C: 0280000c                 be      loc_F000C29C
F000C270: a32ce002                 sll     %l3, 2, %l1
F000C274: d005a14c                 ld      [%l6+0x14C], %o0
F000C278: e0020011                 ld      [%o0+%l1], %l0
F000C27C: 400068be                 call    _vno_lockrelease
F000C280: 90100010                 mov     %l0, %o0
F000C284: 7ffffc97                 call    _closef
F000C288: 90100010                 mov     %l0, %o0
F000C28C: d005a14c                 ld      [%l6+0x14C], %o0
F000C290: c0220011                 clr     [%o0+%l1]
F000C294: d005a150                 ld      [%l6+0x150], %o0
F000C298: c02a0013                 clrb    [%o0+%l3]
F000C29C: d205a150                 ld      [%l6+0x150], %o1
F000C2A0: d00a4013                 ldub    [%o1+%l3], %o0
F000C2A4: 900a3ffd                 and     %o0, -3, %o0
F000C2A8: d02a4013                 stb     %o0, [%o1+%l3]
F000C2AC: a684ffff                 inccc   -1, %l3
F000C2B0: 3cbfffed                 bpos,a  loc_F000C264
F000C2B4: d005a150                 ld      [%l6+0x150], %o0
F000C2B8: 10800003                 ba      loc_F000C2C4
F000C2BC: d405a154                 ld      [%l6+0x154], %o2
F000C2C0: d425a154                 st      %o2, [%l6+0x154]
F000C2C4: 80a2a000                 cmp     %o2, 0
F000C2C8: 06800007                 bl      loc_F000C2E4
F000C2CC: 932aa002                 sll     %o2, 2, %o1
F000C2D0: d005a14c                 ld      [%l6+0x14C], %o0
F000C2D4: d0020009                 ld      [%o0+%o1], %o0
F000C2D8: 80a22000                 cmp     %o0, 0
F000C2DC: 22bffff9                 be,a    loc_F000C2C0
F000C2E0: 9402bfff                 inc     -1, %o2
F000C2E4: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F000C2E8: d20221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o1
F000C2EC: 90102001                 mov     1, %o0
F000C2F0: d02a6039                 stb     %o0, [%o1+0x39]
F000C2F4: d015a240                 lduh    [%l6+0x240], %o0
F000C2F8: 900a3ffe                 and     %o0, -2, %o0
F000C2FC: d035a240                 sth     %o0, [%l6+0x240]
F000C300: d007bfb0                 ld      [%fp+var_50], %o0
F000C304: 80a22010                 cmp     %o0, 0x10
F000C308: 28800005                 bleu,a  loc_F000C31C
F000C30C: d407bfb0                 ld      [%fp+var_50], %o2
F000C310: 90102010                 mov     0x10, %o0
F000C314: d027bfb0                 st      %o0, [%fp+var_50]
F000C318: d407bfb0                 ld      [%fp+var_50], %o2! size_t
F000C31C: 9205a008                 add     %l6, 8, %o1! void *
F000C320: d007bfa8                 ld      [%fp+var_58], %o0! void *
F000C324: 400221fb                 call    _bcopy
F000C328: 9402a001                 inc     %o2
F000C32C: d4058000                 ld      [%l6], %o2
F000C330: d002a028                 ld      [%o2+0x28], %o0
F000C334: 13200000                 sethi   0x80000000, %o1
F000C338: 90120009                 bset    %o1, %o0
F000C33C: d022a028                 st      %o0, [%o2+0x28]
F000C340: 40006c6a                 call    _pn_free
F000C344: 9007bfa8                 add     %fp, var_58, %o0
F000C348: c607beec                 ld      [%fp+var_114], %g3
F000C34C: 80a0e000                 cmp     %g3, 0
F000C350: 02800006                 be      loc_F000C368
F000C354: 113c04d0                 sethi   %hi(_kernel_pageable_map), %o0
F000C358: d00220c0                 ld      [%o0+%lo(_kernel_pageable_map)], %o0
F000C35C: d207beec                 ld      [%fp+var_114], %o1
F000C360: 4001df0e                 call    _kmem_free_wakeup
F000C364: 15000028                 sethi   0xA000, %o2
F000C368: d007bf34                 ld      [%fp+var_CC], %o0
F000C36C: 80a22000                 cmp     %o0, 0
F000C370: 22800005                 be,a    loc_F000C384
F000C374: 113c04cf                 sethi   -0xFECC400, %o0
F000C378: 400071fb                 call    _vn_rele
F000C37C: 01000000                 nop
F000C380: 113c04cf                 sethi   -0xFECC400, %o0
F000C384: d00221dc                 ld      [%o0+0x1DC], %o0
F000C388: f02a2038                 stb     %i0, [%o0+0x38]
F000C38C: 81c7e008                 ret
F000C390: 81e80000                 restore
