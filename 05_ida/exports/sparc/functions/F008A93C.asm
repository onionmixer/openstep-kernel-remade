F008A93C: 9de3bf98                 save    %sp, -0x68, %sp
F008A940: 80a62000                 cmp     %i0, 0
F008A944: 0280000e                 be      loc_F008A97C
F008A948: 9810001b                 mov     %i3, %o4
F008A94C: 113c04d0                 sethi   %hi(_page_mask), %o0
F008A950: d20220d8                 ld      [%o0+%lo(_page_mask)], %o1
F008A954: 9406401a                 add     %i1, %i2, %o2
F008A958: 90100018                 mov     %i0, %o0
F008A95C: 96380009                 xnor    %g0, %o1, %o3
F008A960: 94028009                 add     %o2, %o1, %o2
F008A964: 920e400b                 and     %i1, %o3, %o1
F008A968: 940a800b                 and     %o2, %o3, %o2
F008A96C: 7fffe827                 call    _vm_map_protect
F008A970: 9610001c                 mov     %i4, %o3
F008A974: 10800003                 ba      locret_F008A980
F008A978: b0100008                 mov     %o0, %i0
F008A97C: b0102004                 mov     4, %i0
F008A980: 81c7e008                 ret
F008A984: 81e80000                 restore
