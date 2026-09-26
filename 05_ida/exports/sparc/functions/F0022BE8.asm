F0022BE8: 9de3bf90                 save    %sp, -0x70, %sp
F0022BEC: d4566008                 ldsh    [%i1+8], %o2
F0022BF0: a0100018                 mov     %i0, %l0
F0022BF4: d2066004                 ld      [%i1+4], %o1
F0022BF8: 9002bff4                 add     %o2, -0xC, %o0
F0022BFC: 90020009                 add     %o0, %o1, %o0
F0022C00: 80a22070                 cmp     %o0, 0x70 ! 'p'
F0022C04: 12800004                 bne     loc_F0022C14
F0022C08: 90064009                 add     %i1, %o1, %o0
F0022C0C: 1080002e                 ba      locret_F0022CC4
F0022C10: b0102028                 mov     0x28, %i0 ! '('
F0022C14: c02a000a                 clrb    [%o0+%o2]
F0022C18: 90022002                 inc     2, %o0
F0022C1C: 92102001                 mov     1, %o1
F0022C20: 94102001                 mov     1, %o2
F0022C24: 96102000                 mov     0, %o3
F0022C28: 40000f67                 call    _lookupname
F0022C2C: 9807bff4                 add     %fp, var_C, %o4
F0022C30: b0920000                 orcc    %o0, %g0, %i0
F0022C34: 12800024                 bne     locret_F0022CC4
F0022C38: d207bff4                 ld      [%fp+var_C], %o1
F0022C3C: d0026028                 ld      [%o1+0x28], %o0
F0022C40: 80a22006                 cmp     %o0, 6
F0022C44: 1280001e                 bne     loc_F0022CBC
F0022C48: b0102026                 mov     0x26, %i0 ! '&'
F0022C4C: d4026020                 ld      [%o1+0x20], %o2
F0022C50: 80a2a000                 cmp     %o2, 0
F0022C54: 0280001a                 be      loc_F0022CBC
F0022C58: b010203d                 mov     0x3D, %i0 ! '='
F0022C5C: d2540000                 ldsh    [%l0], %o1
F0022C60: d0528000                 ldsh    [%o2], %o0
F0022C64: 80a24008                 cmp     %o1, %o0
F0022C68: 12800015                 bne     loc_F0022CBC
F0022C6C: b0102029                 mov     0x29, %i0 ! ')'
F0022C70: d004200c                 ld      [%l0+0xC], %o0
F0022C74: d012200a                 lduh    [%o0+0xA], %o0
F0022C78: 808a2004                 btst    4, %o0
F0022C7C: 0280000d                 be      loc_F0022CB0
F0022C80: 90100010                 mov     %l0, %o0
F0022C84: d012a002                 lduh    [%o2+2], %o0
F0022C88: 808a2002                 btst    2, %o0
F0022C8C: 0280000c                 be      loc_F0022CBC
F0022C90: b010203d                 mov     0x3D, %i0 ! '='
F0022C94: 7ffff510                 call    _sonewconn
F0022C98: 9010000a                 mov     %o2, %o0
F0022C9C: 94920000                 orcc    %o0, %g0, %o2
F0022CA0: 12800004                 bne     loc_F0022CB0
F0022CA4: 90100010                 mov     %l0, %o0
F0022CA8: 10800005                 ba      loc_F0022CBC
F0022CAC: b010203d                 mov     0x3D, %i0 ! '='
F0022CB0: 40000007                 call    _unp_connect2
F0022CB4: 9210000a                 mov     %o2, %o1
F0022CB8: b0100008                 mov     %o0, %i0
F0022CBC: 400017aa                 call    _vn_rele
F0022CC0: d007bff4                 ld      [%fp+var_C], %o0
F0022CC4: 81c7e008                 ret
F0022CC8: 81e80000                 restore
