F008A8F4: 9de3bf98                 save    %sp, -0x68, %sp
F008A8F8: 80a62000                 cmp     %i0, 0
F008A8FC: 0280000d                 be      loc_F008A930
F008A900: 113c04d0                 sethi   %hi(_page_mask), %o0
F008A904: d20220d8                 ld      [%o0+%lo(_page_mask)], %o1
F008A908: 9406401a                 add     %i1, %i2, %o2
F008A90C: 90100018                 mov     %i0, %o0
F008A910: 96380009                 xnor    %g0, %o1, %o3
F008A914: 94028009                 add     %o2, %o1, %o2
F008A918: 920e400b                 and     %i1, %o3, %o1
F008A91C: 940a800b                 and     %o2, %o3, %o2
F008A920: 7fffe8ee                 call    _vm_map_inherit
F008A924: 9610001b                 mov     %i3, %o3
F008A928: 10800003                 ba      locret_F008A934
F008A92C: b0100008                 mov     %o0, %i0
F008A930: b0102004                 mov     4, %i0
F008A934: 81c7e008                 ret
F008A938: 81e80000                 restore
