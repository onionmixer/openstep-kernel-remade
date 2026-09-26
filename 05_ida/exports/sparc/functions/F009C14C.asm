F009C14C: 9de3bf98                 save    %sp, -0x68, %sp
F009C150: 253c04f79a14a390         set     _reg_active, %o5
F009C158: c0236008                 clr     [%o5+8]
F009C15C: 233c04f7981463b0         set     _reg_semi_active, %o4
F009C164: c0232008                 clr     [%o4+8]
F009C168: 213c04f7961423a0         set     _reg_free, %o3
F009C170: c022e008                 clr     [%o3+8]
F009C174: 1f3c04f79413e3c0         set     _seg_active, %o2
F009C17C: c022a008                 clr     [%o2+8]
F009C180: 073c04f79210e3e0         set     _seg_semi_active, %o1
F009C188: c0226008                 clr     [%o1+8]
F009C18C: 053c04f79010a3d0         set     _seg_free, %o0
F009C194: c0222008                 clr     [%o0+8]
F009C198: da236004                 st      %o5, [%o5+4]
F009C19C: da24a390                 st      %o5, [%l2+0x390]
F009C1A0: d8232004                 st      %o4, [%o4+4]
F009C1A4: d82463b0                 st      %o4, [%l1+0x3B0]
F009C1A8: d622e004                 st      %o3, [%o3+4]
F009C1AC: d62423a0                 st      %o3, [%l0+0x3A0]
F009C1B0: d422a004                 st      %o2, [%o2+4]
F009C1B4: d423e3c0                 st      %o2, [%o7+0x3C0]
F009C1B8: d2226004                 st      %o1, [%o1+4]
F009C1BC: d220e3e0                 st      %o1, [%g3+0x3E0]
F009C1C0: d0222004                 st      %o0, [%o0+4]
F009C1C4: d020a3d0                 st      %o0, [%g2+0x3D0]
F009C1C8: 133c04f790126218         set     _garbage, %o0
F009C1D0: d0222004                 st      %o0, [%o0+4]
F009C1D4: d0226218                 st      %o0, [%o1+0x218]
F009C1D8: 912e6003                 sll     %i1, 3, %o0
F009C1DC: 90220019                 sub     %o0, %i1, %o0
F009C1E0: 912a2002                 sll     %o0, 2, %o0
F009C1E4: 92060008                 add     %i0, %o0, %o1
F009C1E8: 80a60009                 cmp     %i0, %o1
F009C1EC: 1a80000f                 bcc     loc_F009C228
F009C1F0: 96102000                 mov     0, %o3
F009C1F4: 113c04f4                 sethi   %hi(_page_shift), %o0
F009C1F8: da022348                 ld      [%o0+%lo(_page_shift)], %o5
F009C1FC: 98100009                 mov     %o1, %o4
F009C200: 94062014                 add     %i0, 0x14, %o2
F009C204: d002a004                 ld      [%o2+4], %o0
F009C208: b006201c                 inc     0x1C, %i0
F009C20C: d2028000                 ld      [%o2], %o1
F009C210: 80a6000c                 cmp     %i0, %o4
F009C214: 90220009                 sub     %o0, %o1, %o0
F009C218: 9132000d                 srl     %o0, %o5, %o0
F009C21C: 9602c008                 add     %o3, %o0, %o3
F009C220: 0abffff9                 bcs     loc_F009C204
F009C224: 9402a01c                 inc     0x1C, %o2
F009C228: b0102000                 mov     0, %i0
F009C22C: 233c04f4                 sethi   -0xFEC3000, %l1
F009C230: 113c04d0                 sethi   -0xFECC000, %o0
F009C234: a6100008                 mov     %o0, %l3
F009C238: 113c0447                 sethi   -0xFEEE400, %o0
F009C23C: b2100008                 mov     %o0, %i1
F009C240: 2b3c04f0                 sethi   -0xFEC4000, %l5
F009C244: a4102000                 mov     0, %l2
F009C248: 912ae002                 sll     %o3, 2, %o0
F009C24C: 9002000b                 add     %o0, %o3, %o0
F009C250: e004e0d8                 ld      [%l3+0xD8], %l0
F009C254: 912a2002                 sll     %o0, 2, %o0
F009C258: d206613c                 ld      [%i1+0x13C], %o1
F009C25C: 90020010                 add     %o0, %l0, %o0
F009C260: a02a0010                 andn    %o0, %l0, %l0
F009C264: 7fffa8a7                 call    _vm_alloc_from_regions
F009C268: 90100010                 mov     %l0, %o0! void *
F009C26C: 133c04f7                 sethi   %hi(_pg_desc_tbl), %o1! size_t
F009C270: d0226260                 st      %o0, [%o1+%lo(_pg_desc_tbl)]
F009C274: 7fffe2f9                 call    _bzero
F009C278: 92100010                 mov     %l0, %o1
F009C27C: 113c04f7901223f0         set     _tmp_maps, %o0
F009C284: a8022008                 add     %o0, 8, %l4
F009C288: a0100008                 mov     %o0, %l0
F009C28C: 92102000                 mov     0, %o1
F009C290: 94102000                 mov     0, %o2
F009C294: d6046390                 ld      [%l1+0x390], %o3
F009C298: 98102007                 mov     7, %o4
F009C29C: d004e0d8                 ld      [%l3+0xD8], %o0
F009C2A0: 9a102001                 mov     1, %o5
F009C2A4: 9602c008                 add     %o3, %o0, %o3
F009C2A8: 902ac008                 andn    %o3, %o0, %o0
F009C2AC: d0246390                 st      %o0, [%l1+0x390]
F009C2B0: d606613c                 ld      [%i1+0x13C], %o3
F009C2B4: 40000017                 call    _pmap_map
F009C2B8: d0242004                 st      %o0, [%l0+4]
F009C2BC: d0056100                 ld      [%l5+0x100], %o0
F009C2C0: b0062001                 inc     %i0
F009C2C4: d2046390                 ld      [%l1+0x390], %o1
F009C2C8: 400001bc                 call    _pmap_page_table_entry
F009C2CC: 94102003                 mov     3, %o2
F009C2D0: d0240000                 st      %o0, [%l0]
F009C2D4: c0248014                 clr     [%l2+%l4]
F009C2D8: a004200c                 inc     0xC, %l0
F009C2DC: d0046390                 ld      [%l1+0x390], %o0
F009C2E0: a404a00c                 inc     0xC, %l2
F009C2E4: d206613c                 ld      [%i1+0x13C], %o1
F009C2E8: 80a62004                 cmp     %i0, 4
F009C2EC: 90020009                 add     %o0, %o1, %o0
F009C2F0: 04bfffe7                 ble     loc_F009C28C
F009C2F4: d0246390                 st      %o0, [%l1+0x390]
F009C2F8: 113c0000                 sethi   -0x10000000, %o0
F009C2FC: d0268000                 st      %o0, [%i2]
F009C300: 113fc000                 sethi   -0x1000000, %o0
F009C304: d026c000                 st      %o0, [%i3]
F009C308: 81c7e008                 ret
F009C30C: 81e80000                 restore
