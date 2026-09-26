F00A62F8: 9de3bf98                 save    %sp, -0x68, %sp
F00A62FC: 113fbfa8                 sethi   -0x1016000, %o0
F00A6300: e0020000                 ld      [%o0], %l0
F00A6304: c0220000                 clr     [%o0]
F00A6308: 113c0466                 sethi   %hi(_nofault), %o0
F00A630C: d2022144                 ld      [%o0+%lo(_nofault)], %o1
F00A6310: 113fbfa8                 sethi   -0x1016000, %o0
F00A6314: 80a26000                 cmp     %o1, 0
F00A6318: 1280001c                 bne     locret_F00A6388
F00A631C: e2022004                 ld      [%o0+4], %l1
F00A6320: 11004200                 sethi   0x1080000, %o0
F00A6324: 808c0008                 btst    %o0, %l0
F00A6328: 02800011                 be      loc_F00A636C
F00A632C: 113c0466                 sethi   %hi(_system_fatal), %o0
F00A6330: 7fffc2de                 call    _simple_lock_try
F00A6334: 90122150                 bset    %lo(_system_fatal), %o0
F00A6338: 80a22000                 cmp     %o0, 0
F00A633C: 12800013                 bne     locret_F00A6388
F00A6340: 113c04fb                 sethi   %hi(_sys_fatal_flt), %o0
F00A6344: 92102004                 mov     4, %o1
F00A6348: d2322070                 sth     %o1, [%o0+%lo(_sys_fatal_flt)]
F00A634C: 90122070                 bset    %lo(_sys_fatal_flt), %o0
F00A6350: c0322002                 clrh    [%o0+2]
F00A6354: e0222004                 st      %l0, [%o0+4]
F00A6358: e2222008                 st      %l1, [%o0+8]
F00A635C: c022200c                 clr     [%o0+0xC]
F00A6360: c0222010                 clr     [%o0+0x10]
F00A6364: 10800009                 ba      locret_F00A6388
F00A6368: c0222014                 clr     [%o0+0x14]
F00A636C: 113c0464                 sethi   %hi(_cpuid), %o0
F00A6370: d0022340                 ld      [%o0+%lo(_cpuid)], %o0
F00A6374: 92102004                 mov     4, %o1
F00A6378: 94100010                 mov     %l0, %o2
F00A637C: 96100011                 mov     %l1, %o3
F00A6380: 40000087                 call    _handle_aflt
F00A6384: 98102000                 mov     0, %o4
F00A6388: 81c7e008                 ret
F00A638C: 81e80000                 restore
