F000A1EC: 9de3bf98                 save    %sp, -0x68, %sp
F000A1F0: 133c04cf901261dc         set     dword_F0133DDC, %o0
F000A1F8: e2023ffc                 ld      [%o0-4], %l1
F000A1FC: d00261dc                 ld      [%o1+0x1DC], %o0
F000A200: d2046258                 ld      [%l1+0x258], %o1
F000A204: 80a26000                 cmp     %o1, 0
F000A208: 0280000f                 be      locret_F000A244
F000A20C: e0022024                 ld      [%o0+0x24], %l0
F000A210: 40017798                 call    _kalloc
F000A214: 90102018                 mov     0x18, %o0
F000A218: d2040000                 ld      [%l0], %o1
F000A21C: d2222008                 st      %o1, [%o0+8]
F000A220: d2042004                 ld      [%l0+4], %o1
F000A224: d222200c                 st      %o1, [%o0+0xC]
F000A228: d2042008                 ld      [%l0+8], %o1
F000A22C: d2222010                 st      %o1, [%o0+0x10]
F000A230: d204200c                 ld      [%l0+0xC], %o1
F000A234: d2222014                 st      %o1, [%o0+0x14]
F000A238: d2046248                 ld      [%l1+0x248], %o1
F000A23C: d2222004                 st      %o1, [%o0+4]
F000A240: d0246248                 st      %o0, [%l1+0x248]
F000A244: 81c7e008                 ret
F000A248: 81e80000                 restore
