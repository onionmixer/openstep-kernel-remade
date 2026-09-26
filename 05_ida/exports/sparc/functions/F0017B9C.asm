F0017B9C: 9de3bf98                 save    %sp, -0x68, %sp
F0017BA0: 40000d52                 call    _ttynty
F0017BA4: 90100019                 mov     %i1, %o0
F0017BA8: 273c04cf                 sethi   %hi(_active_u), %l3
F0017BAC: d204e1d8                 ld      [%l3+%lo(_active_u)], %o1
F0017BB0: e2024000                 ld      [%o1], %l1
F0017BB4: a4100008                 mov     %o0, %l2
F0017BB8: 7fffdbda                 call    _get_posix_proc
F0017BBC: d0546030                 ldsh    [%l1+0x30], %o0
F0017BC0: 13000010                 sethi   0x4000, %o1
F0017BC4: d4046014                 ld      [%l1+0x14], %o2
F0017BC8: 808a8009                 btst    %o1, %o2
F0017BCC: 02800025                 be      loc_F0017C60
F0017BD0: a0100008                 mov     %o0, %l0
F0017BD4: d0042010                 ld      [%l0+0x10], %o0
F0017BD8: d2022008                 ld      [%o0+8], %o1
F0017BDC: d0026004                 ld      [%o1+4], %o0
F0017BE0: 80a20011                 cmp     %o0, %l1
F0017BE4: 12800044                 bne     loc_F0017CF4
F0017BE8: 01000000                 nop
F0017BEC: d0026008                 ld      [%o1+8], %o0
F0017BF0: 80a22000                 cmp     %o0, 0
F0017BF4: 12800040                 bne     loc_F0017CF4
F0017BF8: 01000000                 nop
F0017BFC: d004a008                 ld      [%l2+8], %o0
F0017C00: 80a22000                 cmp     %o0, 0
F0017C04: 1280003c                 bne     loc_F0017CF4
F0017C08: 01000000                 nop
F0017C0C: d0042018                 ld      [%l0+0x18], %o0
F0017C10: 13100000                 sethi   0x40000000, %o1
F0017C14: 808a0009                 btst    %o1, %o0
F0017C18: 12800037                 bne     loc_F0017CF4
F0017C1C: d004e1d8                 ld      [%l3+0x1D8], %o0
F0017C20: f2222164                 st      %i1, [%o0+0x164]
F0017C24: d004e1d8                 ld      [%l3+0x1D8], %o0
F0017C28: f0322168                 sth     %i0, [%o0+0x168]
F0017C2C: d0042010                 ld      [%l0+0x10], %o0
F0017C30: d0022008                 ld      [%o0+8], %o0
F0017C34: d024a008                 st      %o0, [%l2+8]
F0017C38: d0042010                 ld      [%l0+0x10], %o0
F0017C3C: d0022008                 ld      [%o0+8], %o0
F0017C40: f2222008                 st      %i1, [%o0+8]
F0017C44: d0042010                 ld      [%l0+0x10], %o0
F0017C48: d024a00c                 st      %o0, [%l2+0xC]
F0017C4C: d0042010                 ld      [%l0+0x10], %o0
F0017C50: d002200c                 ld      [%o0+0xC], %o0
F0017C54: d0366044                 sth     %o0, [%i1+0x44]
F0017C58: 10800025                 ba      loc_F0017CEC
F0017C5C: d0046028                 ld      [%l1+0x28], %o0
F0017C60: d2046028                 ld      [%l1+0x28], %o1
F0017C64: 11100000                 sethi   0x40000000, %o0
F0017C68: 808a4008                 btst    %o0, %o1
F0017C6C: 12800022                 bne     loc_F0017CF4
F0017C70: d004e1d8                 ld      [%l3+0x1D8], %o0
F0017C74: f2222164                 st      %i1, [%o0+0x164]
F0017C78: d004e1d8                 ld      [%l3+0x1D8], %o0
F0017C7C: f0322168                 sth     %i0, [%o0+0x168]
F0017C80: d0042010                 ld      [%l0+0x10], %o0
F0017C84: d0022008                 ld      [%o0+8], %o0
F0017C88: d024a008                 st      %o0, [%l2+8]
F0017C8C: d0042010                 ld      [%l0+0x10], %o0
F0017C90: d0022008                 ld      [%o0+8], %o0
F0017C94: f2222008                 st      %i1, [%o0+8]
F0017C98: d2566044                 ldsh    [%i1+0x44], %o1
F0017C9C: 80a26000                 cmp     %o1, 0
F0017CA0: 3280000c                 bne,a   loc_F0017CD0
F0017CA4: d054602e                 ldsh    [%l1+0x2E], %o0
F0017CA8: 90100011                 mov     %l1, %o0
F0017CAC: d2546030                 ldsh    [%l1+0x30], %o1
F0017CB0: 7fffda81                 call    _enterpgrp
F0017CB4: 94102001                 mov     1, %o2
F0017CB8: d0042010                 ld      [%l0+0x10], %o0
F0017CBC: d024a00c                 st      %o0, [%l2+0xC]
F0017CC0: d0042010                 ld      [%l0+0x10], %o0
F0017CC4: d002200c                 ld      [%o0+0xC], %o0
F0017CC8: 10800007                 ba      loc_F0017CE4
F0017CCC: d0366044                 sth     %o0, [%i1+0x44]
F0017CD0: 80a24008                 cmp     %o1, %o0
F0017CD4: 02800004                 be      loc_F0017CE4
F0017CD8: 90100011                 mov     %l1, %o0
F0017CDC: 7fffda76                 call    _enterpgrp
F0017CE0: 94102000                 mov     0, %o2
F0017CE4: d0046028                 ld      [%l1+0x28], %o0
F0017CE8: 13100000                 sethi   0x40000000, %o1
F0017CEC: 90120009                 bset    %o1, %o0
F0017CF0: d0246028                 st      %o0, [%l1+0x28]
F0017CF4: 4001fbb1                 call    _spltty
F0017CF8: f0366038                 sth     %i0, [%i1+0x38]
F0017CFC: d2066040                 ld      [%i1+0x40], %o1
F0017D00: 940a7ffd                 and     %o1, -3, %o2
F0017D04: d4266040                 st      %o2, [%i1+0x40]
F0017D08: 808a6004                 btst    4, %o1
F0017D0C: 12800018                 bne     loc_F0017D6C
F0017D10: 92100008                 mov     %o0, %o1! size_t
F0017D14: 9012a004                 or      %o2, 4, %o0
F0017D18: d0266040                 st      %o0, [%i1+0x40]
F0017D1C: 4001fc02                 call    _splx
F0017D20: 90100009                 mov     %o1, %o0
F0017D24: 110709469012221c         set     0x1C251A1C, %o0
F0017D2C: d024a010                 st      %o0, [%l2+0x10]
F0017D30: 9010205c                 mov     0x5C, %o0 ! '\'
F0017D34: d02ca014                 stb     %o0, [%l2+0x14]
F0017D38: 90102001                 mov     1, %o0
F0017D3C: d02ca015                 stb     %o0, [%l2+0x15]
F0017D40: c02ca016                 clrb    [%l2+0x16]
F0017D44: 9006605c                 add     %i1, 0x5C, %o0 ! '\'! void *
F0017D48: 4001f444                 call    _bzero
F0017D4C: 92102008                 mov     8, %o1
F0017D50: d04e6047                 ldsb    [%i1+0x47], %o0
F0017D54: 80a22002                 cmp     %o0, 2
F0017D58: 02800007                 be      loc_F0017D74
F0017D5C: 01000000                 nop
F0017D60: 7ffffb04                 call    _ttywflush
F0017D64: 90100019                 mov     %i1, %o0
F0017D68: 30800003                 ba,a    loc_F0017D74
F0017D6C: 4001fbee                 call    _splx
F0017D70: 90100009                 mov     %o1, %o0
F0017D74: 7ffffa01                 call    _ttysetspec
F0017D78: 90100012                 mov     %l2, %o0
F0017D7C: 81c7e008                 ret
F0017D80: 91e82000                 restore %g0, 0, %o0
