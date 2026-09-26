F0028BC0: 9de3bf10                 save    %sp, -0xF0, %sp
F0028BC4: 900ea001                 and     %i2, 1, %o0
F0028BC8: a08ea402                 andcc   %i2, 0x402, %l0
F0028BCC: 02800003                 be      loc_F0028BD8
F0028BD0: a32a2008                 sll     %o0, 8, %l1
F0028BD4: a2146080                 bset    0x80, %l1
F0028BD8: 808ea200                 btst    0x200, %i2
F0028BDC: 02800019                 be      loc_F0028C40
F0028BE0: 90100018                 mov     %i0, %o0
F0028BE4: a007bfb8                 add     %fp, var_48, %l0
F0028BE8: 4000022b                 call    _vattr_null
F0028BEC: 90100010                 mov     %l0, %o0
F0028BF0: 90102001                 mov     1, %o0
F0028BF4: d027bfb8                 st      %o0, [%fp+var_48]
F0028BF8: 808ea400                 btst    0x400, %i2
F0028BFC: 02800003                 be      loc_F0028C08
F0028C00: f637bfbc                 sth     %i3, [%fp+var_44]
F0028C04: c027bfd0                 clr     [%fp+var_30]
F0028C08: 960ea800                 and     %i2, 0x800, %o3
F0028C0C: b40eb1ff                 and     %i2, -0xE01, %i2
F0028C10: 90100018                 mov     %i0, %o0
F0028C14: 92100019                 mov     %i1, %o1
F0028C18: 94100010                 mov     %l0, %o2
F0028C1C: 80a0000b                 cmp     %g0, %o3
F0028C20: 96402000                 addc    %g0, 0, %o3
F0028C24: 98100011                 mov     %l1, %o4
F0028C28: 40000073                 call    _vn_create
F0028C2C: 9a07bfb4                 add     %fp, var_4C, %o5
F0028C30: b0920000                 orcc    %o0, %g0, %i0
F0028C34: 0280003a                 be      loc_F0028D1C
F0028C38: d207bfb4                 ld      [%fp+var_4C], %o1
F0028C3C: 3080006c                 ba,a    locret_F0028DEC
F0028C40: 92100019                 mov     %i1, %o1
F0028C44: 94102001                 mov     1, %o2
F0028C48: 96102000                 mov     0, %o3
F0028C4C: 7ffff75e                 call    _lookupname
F0028C50: 9807bfb4                 add     %fp, var_4C, %o4
F0028C54: b0920000                 orcc    %o0, %g0, %i0
F0028C58: 12800065                 bne     locret_F0028DEC
F0028C5C: 80a42000                 cmp     %l0, 0
F0028C60: 0280001b                 be      loc_F0028CCC
F0028C64: d007bfb4                 ld      [%fp+var_4C], %o0
F0028C68: d2022028                 ld      [%o0+0x28], %o1
F0028C6C: 80a26002                 cmp     %o1, 2
F0028C70: 32800004                 bne,a   loc_F0028C80
F0028C74: d0022024                 ld      [%o0+0x24], %o0
F0028C78: 10800056                 ba      loc_F0028DD0
F0028C7C: b0102015                 mov     0x15, %i0
F0028C80: d002200c                 ld      [%o0+0xC], %o0
F0028C84: 808a2001                 btst    1, %o0
F0028C88: 02800005                 be      loc_F0028C9C
F0028C8C: 90027ffd                 add     %o1, -3, %o0
F0028C90: 80a22001                 cmp     %o0, 1
F0028C94: 1880004f                 bgu     loc_F0028DD0
F0028C98: b010201e                 mov     0x1E, %i0
F0028C9C: d207bfb4                 ld      [%fp+var_4C], %o1
F0028CA0: d0126004                 lduh    [%o1+4], %o0
F0028CA4: 808a2002                 btst    2, %o0
F0028CA8: 0280000a                 be      loc_F0028CD0
F0028CAC: 113c04cf                 sethi   -0xFECC400, %o0
F0028CB0: 40018d44                 call    _vnode_uncache
F0028CB4: 90100009                 mov     %o1, %o0
F0028CB8: d007bfb4                 ld      [%fp+var_4C], %o0
F0028CBC: d0122004                 lduh    [%o0+4], %o0
F0028CC0: 808a2002                 btst    2, %o0
F0028CC4: 12800043                 bne     loc_F0028DD0
F0028CC8: b010201a                 mov     0x1A, %i0
F0028CCC: 113c04cf                 sethi   -0xFECC400, %o0
F0028CD0: d00221d8                 ld      [%o0+0x1D8], %o0
F0028CD4: d402201c                 ld      [%o0+0x1C], %o2
F0028CD8: d007bfb4                 ld      [%fp+var_4C], %o0
F0028CDC: d602201c                 ld      [%o0+0x1C], %o3
F0028CE0: d602e01c                 ld      [%o3+0x1C], %o3
F0028CE4: 9fc2c000                 call    %o3
F0028CE8: 92100011                 mov     %l1, %o1
F0028CEC: b0920000                 orcc    %o0, %g0, %i0
F0028CF0: 12800039                 bne     loc_F0028DD4
F0028CF4: d207bfb4                 ld      [%fp+var_4C], %o1
F0028CF8: d0026024                 ld      [%o1+0x24], %o0
F0028CFC: d002200c                 ld      [%o0+0xC], %o0
F0028D00: 808a2008                 btst    8, %o0
F0028D04: 02800007                 be      loc_F0028D20
F0028D08: d0026028                 ld      [%o1+0x28], %o0
F0028D0C: 90023ffd                 inc     -3, %o0
F0028D10: 80a22001                 cmp     %o0, 1
F0028D14: 0880002f                 bleu    loc_F0028DD0
F0028D18: b0102001                 mov     1, %i0
F0028D1C: d0026028                 ld      [%o1+0x28], %o0
F0028D20: 80a22006                 cmp     %o0, 6
F0028D24: 12800004                 bne     loc_F0028D34
F0028D28: 233c04cf                 sethi   -0xFECC400, %l1
F0028D2C: 10800029                 ba      loc_F0028DD0
F0028D30: b010202d                 mov     0x2D, %i0 ! '-'
F0028D34: d00461d8                 ld      [%l1+0x1D8], %o0
F0028D38: d202601c                 ld      [%o1+0x1C], %o1
F0028D3C: d402201c                 ld      [%o0+0x1C], %o2
F0028D40: d6024000                 ld      [%o1], %o3
F0028D44: 9007bfb4                 add     %fp, var_4C, %o0
F0028D48: 9fc2c000                 call    %o3
F0028D4C: 9210001a                 mov     %i2, %o1
F0028D50: b0920000                 orcc    %o0, %g0, %i0
F0028D54: 12800020                 bne     loc_F0028DD4
F0028D58: 01000000                 nop
F0028D5C: 808ea400                 btst    0x400, %i2
F0028D60: 0280000f                 be      loc_F0028D9C
F0028D64: 80a62000                 cmp     %i0, 0
F0028D68: a007bf70                 add     %fp, var_90, %l0
F0028D6C: 400001ca                 call    _vattr_null
F0028D70: 90100010                 mov     %l0, %o0
F0028D74: d00461d8                 ld      [%l1+0x1D8], %o0
F0028D78: c027bf88                 clr     [%fp+var_78]
F0028D7C: d402201c                 ld      [%o0+0x1C], %o2
F0028D80: d007bfb4                 ld      [%fp+var_4C], %o0
F0028D84: d602201c                 ld      [%o0+0x1C], %o3
F0028D88: b40ebbff                 and     %i2, -0x401, %i2
F0028D8C: d602e018                 ld      [%o3+0x18], %o3
F0028D90: 9fc2c000                 call    %o3
F0028D94: 92100010                 mov     %l0, %o1
F0028D98: b0920000                 orcc    %o0, %g0, %i0
F0028D9C: 1280000e                 bne     loc_F0028DD4
F0028DA0: 80a62000                 cmp     %i0, 0
F0028DA4: 11100000                 sethi   0x40000000, %o0
F0028DA8: 808e8008                 btst    %o0, %i2
F0028DAC: 1280000a                 bne     loc_F0028DD4
F0028DB0: 80a62000                 cmp     %i0, 0
F0028DB4: d207bfb4                 ld      [%fp+var_4C], %o1
F0028DB8: d0026028                 ld      [%o1+0x28], %o0
F0028DBC: 80a22001                 cmp     %o0, 1
F0028DC0: 12800005                 bne     loc_F0028DD4
F0028DC4: 80a62000                 cmp     %i0, 0
F0028DC8: 40010d4b                 call    _map_vnode
F0028DCC: 90100009                 mov     %o1, %o0
F0028DD0: 80a62000                 cmp     %i0, 0
F0028DD4: 02800005                 be      loc_F0028DE8
F0028DD8: d007bfb4                 ld      [%fp+var_4C], %o0
F0028DDC: 7fffff62                 call    _vn_rele
F0028DE0: d007bfb4                 ld      [%fp+var_4C], %o0
F0028DE4: 30800002                 ba,a    locret_F0028DEC
F0028DE8: d0270000                 st      %o0, [%i4]
F0028DEC: 81c7e008                 ret
F0028DF0: 81e80000                 restore
