F0068888: 9de3bf98                 save    %sp, -0x68, %sp
F006888C: 113c04d0                 sethi   %hi(_page_mask), %o0
F0068890: d00220d8                 ld      [%o0+%lo(_page_mask)], %o0
F0068894: 98102000                 mov     0, %o4
F0068898: 842e0008                 andn    %i0, %o0, %g2
F006889C: 113c04bd                 sethi   %hi(dword_F012F67C), %o0
F00688A0: d202227c                 ld      [%o0+%lo(dword_F012F67C)], %o1
F00688A4: 80a30009                 cmp     %o4, %o1
F00688A8: 16800022                 bge     loc_F0068930
F00688AC: 96100002                 mov     %g2, %o3
F00688B0: 033c04bd86106270         set     dword_F012F670, %g3
F00688B8: 313c043e                 sethi   -0xFEF0800, %i0
F00688BC: 113c04f09e1220c0         set     _stackStats, %o7
F00688C4: 113c04bd                 sethi   %hi(dword_F012F678), %o0
F00688C8: da022278                 ld      [%o0+%lo(dword_F012F678)], %o5
F00688CC: 88100009                 mov     %o1, %g4
F00688D0: 9400a004                 add     %g2, 4, %o2
F00688D4: d002a004                 ld      [%o2+4], %o0
F00688D8: 80a22000                 cmp     %o0, 0
F00688DC: 32800011                 bne,a   loc_F0068920
F00688E0: 9402800d                 add     %o2, %o5, %o2
F00688E4: d002c000                 ld      [%o3], %o0
F00688E8: d2028000                 ld      [%o2], %o1
F00688EC: 80a24003                 cmp     %o1, %g3
F00688F0: 12800004                 bne     loc_F0068900
F00688F4: d2222004                 st      %o1, [%o0+4]
F00688F8: 10800003                 ba      loc_F0068904
F00688FC: d0206270                 st      %o0, [%g1+0x270]
F0068900: d0224000                 st      %o0, [%o1]
F0068904: d0062300                 ld      [%i0+0x300], %o0
F0068908: d203e008                 ld      [%o7+8], %o1
F006890C: 90023fff                 inc     -1, %o0
F0068910: d0262300                 st      %o0, [%i0+0x300]
F0068914: 92027fff                 inc     -1, %o1
F0068918: d223e008                 st      %o1, [%o7+8]
F006891C: 9402800d                 add     %o2, %o5, %o2
F0068920: 98032001                 inc     %o4
F0068924: 80a30004                 cmp     %o4, %g4
F0068928: 06bfffeb                 bl      loc_F00688D4
F006892C: 9602c00d                 add     %o3, %o5, %o3
F0068930: 113fbb7e901222ce         set     -0x1120532, %o0
F0068938: d0208000                 st      %o0, [%g2]
F006893C: 133c04bd                 sethi   %hi(dword_F012F678), %o1
F0068940: d4026278                 ld      [%o1+%lo(dword_F012F678)], %o2
F0068944: 113c04d1                 sethi   %hi(_kernel_map), %o0
F0068948: d0022340                 ld      [%o0+%lo(_kernel_map)], %o0
F006894C: 133c04d0                 sethi   %hi(_page_mask), %o1
F0068950: d60260d8                 ld      [%o1+%lo(_page_mask)], %o3
F0068954: 9400800a                 add     %g2, %o2, %o2
F0068958: 9402800b                 add     %o2, %o3, %o2
F006895C: 92100002                 mov     %g2, %o1
F0068960: 942a800b                 bclr    %o3, %o2
F0068964: 40007122                 call    _vm_map_pageable
F0068968: 96102001                 mov     1, %o3
F006896C: 133c04f0921260c0         set     _stackStats, %o1
F0068974: d0026010                 ld      [%o1+0x10], %o0
F0068978: 90022001                 inc     %o0
F006897C: d0226010                 st      %o0, [%o1+0x10]
F0068980: 81c7e008                 ret
F0068984: 81e80000                 restore
