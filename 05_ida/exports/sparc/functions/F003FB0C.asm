F003FB0C: 9de3bf60                 save    %sp, -0xA0, %sp
F003FB10: e2062030                 ld      [%i0+0x30], %l1
F003FB14: 7ffff546                 call    _rp_rmhash
F003FB18: 90100011                 mov     %l1, %o0
F003FB1C: d004607c                 ld      [%l1+0x7C], %o0
F003FB20: 80a22000                 cmp     %o0, 0
F003FB24: 0280002c                 be      loc_F003FBD4
F003FB28: b0102000                 mov     0, %i0
F003FB2C: 1100003f                 sethi   0xFC00, %o0
F003FB30: d2146060                 lduh    [%l1+0x60], %o1
F003FB34: 901223ef                 bset    0x3EF, %o0
F003FB38: 920a4008                 and     %o1, %o0, %o1
F003FB3C: d004607c                 ld      [%l1+0x7C], %o0
F003FB40: d2346060                 sth     %o1, [%l1+0x60]
F003FB44: 7ffff6b8                 call    _rlock
F003FB48: d0022030                 ld      [%o0+0x30], %o0
F003FB4C: d2046078                 ld      [%l1+0x78], %o1
F003FB50: a007bfd0                 add     %fp, var_30, %l0
F003FB54: d404607c                 ld      [%l1+0x7C], %o2
F003FB58: 7ffff423                 call    _setdiropargs
F003FB5C: 90100010                 mov     %l0, %o0
F003FB60: 9210200a                 mov     0xA, %o1
F003FB64: 153c0108                 sethi   %hi(_xdr_diropargs), %o2
F003FB68: d004607c                 ld      [%l1+0x7C], %o0
F003FB6C: 9412a208                 bset    %lo(_xdr_diropargs), %o2
F003FB70: d6046074                 ld      [%l1+0x74], %o3
F003FB74: 193c0115                 sethi   %hi(_xdr_enum), %o4
F003FB78: d0022024                 ld      [%o0+0x24], %o0
F003FB7C: 98132348                 bset    %lo(_xdr_enum), %o4
F003FB80: d0022128                 ld      [%o0+0x128], %o0
F003FB84: 9a07bfcc                 add     %fp, var_34, %o5
F003FB88: d623a05c                 st      %o3, [%sp+0xA0+var_44]
F003FB8C: 7ffff2fa                 call    _rfscall
F003FB90: 96100010                 mov     %l0, %o3
F003FB94: b0920000                 orcc    %o0, %g0, %i0
F003FB98: 22800002                 be,a    loc_F003FBA0
F003FB9C: f007bfcc                 ld      [%fp+var_34], %i0
F003FBA0: d004607c                 ld      [%l1+0x7C], %o0
F003FBA4: 7ffff6be                 call    _runlock
F003FBA8: d0022030                 ld      [%o0+0x30], %o0
F003FBAC: 7fffa3ee                 call    _vn_rele
F003FBB0: d004607c                 ld      [%l1+0x7C], %o0
F003FBB4: c024607c                 clr     [%l1+0x7C]
F003FBB8: d0046078                 ld      [%l1+0x78], %o0
F003FBBC: 4000a179                 call    _kfree
F003FBC0: 921020ff                 mov     0xFF, %o1
F003FBC4: d0046074                 ld      [%l1+0x74], %o0
F003FBC8: 7fff3f94                 call    _crfree
F003FBCC: c0246078                 clr     [%l1+0x78]
F003FBD0: c0246074                 clr     [%l1+0x74]
F003FBD4: 7ffff5b6                 call    _rfree
F003FBD8: 90100011                 mov     %l1, %o0
F003FBDC: 81c7e008                 ret
F003FBE0: 81e80000                 restore
