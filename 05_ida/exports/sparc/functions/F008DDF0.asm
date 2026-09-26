F008DDF0: 9de3bf98                 save    %sp, -0x68, %sp
F008DDF4: f606e00c                 ld      [%i3+0xC], %i3
F008DDF8: a2100018                 mov     %i0, %l1
F008DDFC: 7fffd8f1                 call    _vm_map_reference
F008DE00: 9010001b                 mov     %i3, %o0
F008DE04: 912f2018                 sll     %i4, 24, %o0
F008DE08: 80a22000                 cmp     %o0, 0
F008DE0C: 02800004                 be      loc_F008DE1C
F008DE10: 113c04d0                 sethi   -0xFECC000, %o0
F008DE14: 10800005                 ba      loc_F008DE28
F008DE18: d006e014                 ld      [%i3+0x14], %o0
F008DE1C: d00220d8                 ld      [%o0+0xD8], %o0
F008DE20: d2068000                 ld      [%i2], %o1
F008DE24: 902a4008                 andn    %o1, %o0, %o0
F008DE28: d0268000                 st      %o0, [%i2]
F008DE2C: 9010001b                 mov     %i3, %o0
F008DE30: 92102000                 mov     0, %o1
F008DE34: 94102000                 mov     0, %o2
F008DE38: 9610001a                 mov     %i2, %o3
F008DE3C: 98100019                 mov     %i1, %o4
F008DE40: 9b2f2018                 sll     %i4, 24, %o5
F008DE44: 7fffd9e3                 call    _vm_map_find
F008DE48: 9b3b6018                 sra     %o5, 24, %o5
F008DE4C: b0920000                 orcc    %o0, %g0, %i0
F008DE50: 02800005                 be      loc_F008DE64
F008DE54: 9010001b                 mov     %i3, %o0
F008DE58: 7fffd8ed                 call    _vm_map_deallocate
F008DE5C: 9010001b                 mov     %i3, %o0
F008DE60: 30800028                 ba,a    locret_F008DF00
F008DE64: 213c04d0                 sethi   %hi(_page_mask), %l0
F008DE68: d20420d8                 ld      [%l0+%lo(_page_mask)], %o1
F008DE6C: 96102002                 mov     2, %o3
F008DE70: d4068000                 ld      [%i2], %o2
F008DE74: 98380009                 xnor    %g0, %o1, %o4
F008DE78: b40a800c                 and     %o2, %o4, %i2
F008DE7C: 92064009                 add     %i1, %o1, %o1
F008DE80: b20a400c                 and     %o1, %o4, %i1
F008DE84: 9210001a                 mov     %i2, %o1
F008DE88: 7fffdb94                 call    _vm_map_inherit
F008DE8C: 94068019                 add     %i2, %i1, %o2
F008DE90: d00420d8                 ld      [%l0+%lo(_page_mask)], %o0
F008DE94: 80a76000                 cmp     %i5, 0
F008DE98: 02800007                 be      loc_F008DEB4
F008DE9C: a22c4008                 bclr    %o0, %l1
F008DEA0: 80a76001                 cmp     %i5, 1
F008DEA4: 02800005                 be      loc_F008DEB8
F008DEA8: a0102001                 mov     1, %l0
F008DEAC: 10800003                 ba      loc_F008DEB8
F008DEB0: a0102000                 mov     0, %l0
F008DEB4: a0102002                 mov     2, %l0
F008DEB8: 80a66000                 cmp     %i1, 0
F008DEBC: 0280000e                 be      loc_F008DEF4
F008DEC0: 313c0447                 sethi   -0xFEEE400, %i0
F008DEC4: 9210001a                 mov     %i2, %o1
F008DEC8: 94100011                 mov     %l1, %o2
F008DECC: 96102003                 mov     3, %o3
F008DED0: 98102001                 mov     1, %o4
F008DED4: d006e024                 ld      [%i3+0x24], %o0
F008DED8: 40004180                 call    _pmap_enter_cache_spec
F008DEDC: 9a100010                 mov     %l0, %o5
F008DEE0: d006213c                 ld      [%i0+0x13C], %o0
F008DEE4: b4068008                 add     %i2, %o0, %i2
F008DEE8: b2a64008                 subcc   %i1, %o0, %i1
F008DEEC: 12bffff6                 bne     loc_F008DEC4
F008DEF0: a2044008                 add     %l1, %o0, %l1
F008DEF4: 7fffd8c6                 call    _vm_map_deallocate
F008DEF8: 9010001b                 mov     %i3, %o0
F008DEFC: b0102000                 mov     0, %i0
F008DF00: 81c7e008                 ret
F008DF04: 81e80000                 restore
