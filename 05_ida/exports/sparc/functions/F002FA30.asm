F002FA30: 9de3bf88                 save    %sp, -0x78, %sp
F002FA34: a0100018                 mov     %i0, %l0
F002FA38: 90102002                 mov     2, %o0
F002FA3C: 9210001a                 mov     %i2, %o1
F002FA40: 94102002                 mov     2, %o2
F002FA44: 7fffbaea                 call    _socreate
F002FA48: 96102000                 mov     0, %o3
F002FA4C: b0920000                 orcc    %o0, %g0, %i0
F002FA50: 02800004                 be      loc_F002FA60
F002FA54: 01000000                 nop
F002FA58: 1080005f                 ba      locret_F002FBD4
F002FA5C: c0268000                 clr     [%i2]
F002FA60: d014200c                 lduh    [%l0+0xC], %o0
F002FA64: 808a2001                 btst    1, %o0
F002FA68: 1280000d                 bne     loc_F002FA9C
F002FA6C: 1320081a                 sethi   -0x7FDF9800, %o1
F002FA70: d014200c                 lduh    [%l0+0xC], %o0
F002FA74: 92126110                 bset    0x110, %o1
F002FA78: 90122021                 bset    0x21, %o0 ! '!'
F002FA7C: d0366010                 sth     %o0, [%i1+0x10]
F002FA80: d0068000                 ld      [%i2], %o0
F002FA84: 7fffe876                 call    _ifioctl
F002FA88: 94100019                 mov     %i1, %o2
F002FA8C: b0920000                 orcc    %o0, %g0, %i0
F002FA90: 02800016                 be      loc_F002FAE8
F002FA94: 9007bfe8                 add     %fp, var_18, %o0
F002FA98: 3080004f                 ba,a    locret_F002FBD4
F002FA9C: d014200c                 lduh    [%l0+0xC], %o0
F002FAA0: 912a2010                 sll     %o0, 16, %o0
F002FAA4: 80a22000                 cmp     %o0, 0
F002FAA8: 16800010                 bge     loc_F002FAE8
F002FAAC: 9007bfe8                 add     %fp, var_18, %o0
F002FAB0: d0068000                 ld      [%i2], %o0
F002FAB4: 1330081a9212610d         set     -0x3FDF96F3, %o1
F002FABC: 7fffe868                 call    _ifioctl
F002FAC0: 94100019                 mov     %i1, %o2
F002FAC4: b0920000                 orcc    %o0, %g0, %i0
F002FAC8: 12800043                 bne     locret_F002FBD4
F002FACC: 01000000                 nop
F002FAD0: b0103fff                 mov     -1, %i0
F002FAD4: d214200c                 lduh    [%l0+0xC], %o1
F002FAD8: 113fffd0                 sethi   -0xC000, %o0
F002FADC: 902a4008                 andn    %o1, %o0, %o0! void *
F002FAE0: d034200c                 sth     %o0, [%l0+0xC]
F002FAE4: 3080003c                 ba,a    locret_F002FBD4
F002FAE8: 92102010                 mov     0x10, %o1! size_t
F002FAEC: d414200c                 lduh    [%l0+0xC], %o2
F002FAF0: 17000010                 sethi   0x4000, %o3
F002FAF4: 9412800b                 bset    %o3, %o2
F002FAF8: d434200c                 sth     %o2, [%l0+0xC]
F002FAFC: 400194d7                 call    _bzero
F002FB00: a0102002                 mov     2, %l0
F002FB04: e037bfe8                 sth     %l0, [%fp+var_18]
F002FB08: e0366010                 sth     %l0, [%i1+0x10]
F002FB0C: d017bfea                 lduh    [%fp+var_16], %o0
F002FB10: d0366012                 sth     %o0, [%i1+0x12]
F002FB14: d017bfec                 lduh    [%fp+var_14], %o0
F002FB18: d0366014                 sth     %o0, [%i1+0x14]
F002FB1C: d017bfee                 lduh    [%fp+var_12], %o0
F002FB20: d0366016                 sth     %o0, [%i1+0x16]
F002FB24: d017bff0                 lduh    [%fp+var_10], %o0
F002FB28: d0366018                 sth     %o0, [%i1+0x18]
F002FB2C: d017bff2                 lduh    [%fp+var_E], %o0
F002FB30: d036601a                 sth     %o0, [%i1+0x1A]
F002FB34: d017bff4                 lduh    [%fp+var_C], %o0
F002FB38: 1320081a                 sethi   -0x7FDF9800, %o1
F002FB3C: d036601c                 sth     %o0, [%i1+0x1C]
F002FB40: d017bff6                 lduh    [%fp+var_A], %o0
F002FB44: 9212610c                 bset    0x10C, %o1
F002FB48: d036601e                 sth     %o0, [%i1+0x1E]
F002FB4C: d0068000                 ld      [%i2], %o0
F002FB50: 7fffe843                 call    _ifioctl
F002FB54: 94100019                 mov     %i1, %o2
F002FB58: b0920000                 orcc    %o0, %g0, %i0
F002FB5C: 1280001e                 bne     locret_F002FBD4
F002FB60: 90102001                 mov     1, %o0
F002FB64: 7fffb77e                 call    _m_get
F002FB68: 92102008                 mov     8, %o1
F002FB6C: b2920000                 orcc    %o0, %g0, %i1
F002FB70: 12800004                 bne     loc_F002FB80
F002FB74: 90102010                 mov     0x10, %o0
F002FB78: 10800017                 ba      locret_F002FBD4
F002FB7C: b0102037                 mov     0x37, %i0 ! '7'
F002FB80: d0366008                 sth     %o0, [%i1+8]
F002FB84: d2066004                 ld      [%i1+4], %o1
F002FB88: 90102044                 mov     0x44, %o0 ! 'D'
F002FB8C: e0364009                 sth     %l0, [%i1+%o1]
F002FB90: 92064009                 add     %i1, %o1, %o1
F002FB94: d0326002                 sth     %o0, [%o1+2]
F002FB98: c0226004                 clr     [%o1+4]
F002FB9C: d0068000                 ld      [%i2], %o0
F002FBA0: 7fffbace                 call    _sobind
F002FBA4: 92100019                 mov     %i1, %o1
F002FBA8: b0100008                 mov     %o0, %i0
F002FBAC: 7fffb82e                 call    _m_freem
F002FBB0: 90100019                 mov     %i1, %o0
F002FBB4: 80a62000                 cmp     %i0, 0
F002FBB8: 12800007                 bne     locret_F002FBD4
F002FBBC: 01000000                 nop
F002FBC0: d2068000                 ld      [%i2], %o1
F002FBC4: d0126006                 lduh    [%o1+6], %o0
F002FBC8: b0102000                 mov     0, %i0
F002FBCC: 90122100                 bset    0x100, %o0
F002FBD0: d0326006                 sth     %o0, [%o1+6]
F002FBD4: 81c7e008                 ret
F002FBD8: 81e80000                 restore
