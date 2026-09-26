F0022B30: 9de3bf50                 save    %sp, -0xB0, %sp
F0022B34: d0062004                 ld      [%i0+4], %o0
F0022B38: d2066004                 ld      [%i1+4], %o1
F0022B3C: 80a22000                 cmp     %o0, 0
F0022B40: 12800006                 bne     loc_F0022B58
F0022B44: a2064009                 add     %i1, %o1, %l1
F0022B48: d0566008                 ldsh    [%i1+8], %o0
F0022B4C: 80a22070                 cmp     %o0, 0x70 ! 'p'
F0022B50: 32800004                 bne,a   loc_F0022B60
F0022B54: c02c4008                 clrb    [%l1+%o0]
F0022B58: 10800022                 ba      locret_F0022BE0
F0022B5C: b0102016                 mov     0x16, %i0
F0022B60: a007bfb8                 add     %fp, var_48, %l0
F0022B64: 40001a4c                 call    _vattr_null
F0022B68: 90100010                 mov     %l0, %o0
F0022B6C: 90102006                 mov     6, %o0
F0022B70: d027bfb8                 st      %o0, [%fp+var_48]
F0022B74: 901021ff                 mov     0x1FF, %o0
F0022B78: d037bfbc                 sth     %o0, [%fp+var_44]
F0022B7C: 90046002                 add     %l1, 2, %o0
F0022B80: 92102001                 mov     1, %o1
F0022B84: 94100010                 mov     %l0, %o2
F0022B88: 96102001                 mov     1, %o3
F0022B8C: 98102000                 mov     0, %o4
F0022B90: 40001899                 call    _vn_create
F0022B94: 9a07bfb4                 add     %fp, var_4C, %o5
F0022B98: 80a22000                 cmp     %o0, 0
F0022B9C: 02800006                 be      loc_F0022BB4
F0022BA0: 80a22011                 cmp     %o0, 0x11
F0022BA4: 1280000f                 bne     locret_F0022BE0
F0022BA8: b0100008                 mov     %o0, %i0
F0022BAC: 1080000d                 ba      locret_F0022BE0
F0022BB0: b0102030                 mov     0x30, %i0 ! '0'
F0022BB4: 90100019                 mov     %i1, %o0
F0022BB8: 92102000                 mov     0, %o1
F0022BBC: d607bfb4                 ld      [%fp+var_4C], %o3
F0022BC0: 150ee6b2                 sethi   0x3B9AC800, %o2
F0022BC4: d8060000                 ld      [%i0], %o4
F0022BC8: 9412a200                 bset    0x200, %o2
F0022BCC: d822e020                 st      %o4, [%o3+0x20]
F0022BD0: 7fffec5d                 call    _m_copy
F0022BD4: d6262004                 st      %o3, [%i0+4]
F0022BD8: d0262018                 st      %o0, [%i0+0x18]
F0022BDC: b0102000                 mov     0, %i0
F0022BE0: 81c7e008                 ret
F0022BE4: 81e80000                 restore
