F001EA28: 9de3bf98                 save    %sp, -0x68, %sp
F001EA2C: d0162002                 lduh    [%i0+2], %o0
F001EA30: 808a2002                 btst    2, %o0
F001EA34: 02800004                 be      loc_F001EA44
F001EA38: 01000000                 nop
F001EA3C: 1080001f                 ba      locret_F001EAB8
F001EA40: b010202d                 mov     0x2D, %i0 ! '-'
F001EA44: 4001e094                 call    _splnet
F001EA48: 01000000                 nop
F001EA4C: d2162006                 lduh    [%i0+6], %o1
F001EA50: 808a6006                 btst    6, %o1
F001EA54: 0280000e                 be      loc_F001EA8C
F001EA58: a0100008                 mov     %o0, %l0
F001EA5C: d006200c                 ld      [%i0+0xC], %o0
F001EA60: d012200a                 lduh    [%o0+0xA], %o0
F001EA64: 808a2004                 btst    4, %o0
F001EA68: 32800012                 bne,a   loc_F001EAB0
F001EA6C: b0102038                 mov     0x38, %i0 ! '8'
F001EA70: 40000025                 call    _sodisconnect
F001EA74: 90100018                 mov     %i0, %o0
F001EA78: 80a22000                 cmp     %o0, 0
F001EA7C: 02800005                 be      loc_F001EA90
F001EA80: 90100018                 mov     %i0, %o0
F001EA84: 1080000b                 ba      loc_F001EAB0
F001EA88: b0102038                 mov     0x38, %i0 ! '8'
F001EA8C: 90100018                 mov     %i0, %o0
F001EA90: 92102004                 mov     4, %o1
F001EA94: d802200c                 ld      [%o0+0xC], %o4
F001EA98: 94102000                 mov     0, %o2
F001EA9C: da03201c                 ld      [%o4+0x1C], %o5
F001EAA0: 96100019                 mov     %i1, %o3
F001EAA4: 9fc34000                 call    %o5
F001EAA8: 98102000                 mov     0, %o4
F001EAAC: b0100008                 mov     %o0, %i0
F001EAB0: 4001e09d                 call    _splx
F001EAB4: 90100010                 mov     %l0, %o0
F001EAB8: 81c7e008                 ret
F001EABC: 81e80000                 restore
