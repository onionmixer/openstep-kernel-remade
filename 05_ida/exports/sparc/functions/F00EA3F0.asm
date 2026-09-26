F00EA3F0: 9c03bf90                 inc     -0x70, %sp
F00EA3F4: c0222004                 clr     [%o0+4]
F00EA3F8: d8222010                 st      %o4, [%o0+0x10]
F00EA3FC: 80a2a000                 cmp     %o2, 0
F00EA400: 12800005                 bne     loc_F00EA414
F00EA404: d4222008                 st      %o2, [%o0+8]
F00EA408: 053c03f38410a118         set     asc_F00FCD18, %g2! "@"
F00EA410: c4222008                 st      %g2, [%o0+8]
F00EA414: 80a2e000                 cmp     %o3, 0
F00EA418: 12800005                 bne     loc_F00EA42C
F00EA41C: d622200c                 st      %o3, [%o0+0xC]
F00EA420: 053c03f38410a118         set     asc_F00FCD18, %g2! "@"
F00EA428: c422200c                 st      %g2, [%o0+0xC]
F00EA42C: c0222014                 clr     [%o0+0x14]
F00EA430: 81c3e008                 retl
F00EA434: 9c23bf90                 dec     -0x70, %sp
