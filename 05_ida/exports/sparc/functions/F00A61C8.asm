F00A61C8: 9de3bf98                 save    %sp, -0x68, %sp
F00A61CC: 7fffc4c4                 call    _get_efsr_vaddr
F00A61D0: a6102000                 mov     0, %l3
F00A61D4: 7fffc4c5                 call    _get_efar0_vaddr
F00A61D8: a0100008                 mov     %o0, %l0
F00A61DC: 7fffc4c6                 call    _get_efar1_vaddr
F00A61E0: a2100008                 mov     %o0, %l1
F00A61E4: 133fbfbc                 sethi   -0x1011000, %o1
F00A61E8: 153c0466                 sethi   %hi(_nofault), %o2
F00A61EC: d402a144                 ld      [%o2+%lo(_nofault)], %o2
F00A61F0: c0226008                 clr     [%o1+8]
F00A61F4: a8102000                 mov     0, %l4
F00A61F8: aa102000                 mov     0, %l5
F00A61FC: 80a2a000                 cmp     %o2, 0
F00A6200: 1280003c                 bne     locret_F00A62F0
F00A6204: a4100008                 mov     %o0, %l2
F00A6208: 113c04f8                 sethi   %hi(_cpu), %o0
F00A620C: d0022120                 ld      [%o0+%lo(_cpu)], %o0
F00A6210: 80a22072                 cmp     %o0, 0x72 ! 'r'
F00A6214: 12800017                 bne     loc_F00A6270
F00A6218: 808c2008                 btst    8, %l0
F00A621C: 1100008090122002         set     0x20002, %o0
F00A6224: 808c0008                 btst    %o0, %l0
F00A6228: 02800011                 be      loc_F00A626C
F00A622C: 113c0466                 sethi   %hi(_system_fatal), %o0
F00A6230: 7fffc31e                 call    _simple_lock_try
F00A6234: 90122150                 bset    %lo(_system_fatal), %o0
F00A6238: 80a22000                 cmp     %o0, 0
F00A623C: 1280002d                 bne     locret_F00A62F0
F00A6240: 113c04fb                 sethi   %hi(_sys_fatal_flt), %o0
F00A6244: 92102002                 mov     2, %o1
F00A6248: d2322070                 sth     %o1, [%o0+%lo(_sys_fatal_flt)]
F00A624C: 90122070                 bset    %lo(_sys_fatal_flt), %o0
F00A6250: c0322002                 clrh    [%o0+2]
F00A6254: e0222004                 st      %l0, [%o0+4]
F00A6258: e2222008                 st      %l1, [%o0+8]
F00A625C: e422200c                 st      %l2, [%o0+0xC]
F00A6260: c0222010                 clr     [%o0+0x10]
F00A6264: 10800023                 ba      locret_F00A62F0
F00A6268: c0222014                 clr     [%o0+0x14]
F00A626C: 808c2008                 btst    8, %l0
F00A6270: 02800007                 be      loc_F00A628C
F00A6274: 11020000                 sethi   0x8000000, %o0
F00A6278: 808c4008                 btst    %o0, %l1
F00A627C: 1280000f                 bne     loc_F00A62B8
F00A6280: 113c0466                 sethi   -0xFEE6800, %o0
F00A6284: 10800006                 ba      loc_F00A629C
F00A6288: 113c0464                 sethi   -0xFEE7000, %o0
F00A628C: 808c2001                 btst    1, %l0
F00A6290: 0280000a                 be      loc_F00A62B8
F00A6294: 113c0466                 sethi   -0xFEE6800, %o0
F00A6298: 113c0464                 sethi   -0xFEE7000, %o0
F00A629C: d0022340                 ld      [%o0+0x340], %o0
F00A62A0: 92102002                 mov     2, %o1
F00A62A4: 94100010                 mov     %l0, %o2
F00A62A8: 96100011                 mov     %l1, %o3
F00A62AC: 400000bc                 call    _handle_aflt
F00A62B0: 98100012                 mov     %l2, %o4
F00A62B4: 3080000f                 ba,a    locret_F00A62F0
F00A62B8: 7fffc2fc                 call    _simple_lock_try
F00A62BC: 90122150                 bset    0x150, %o0
F00A62C0: 80a22000                 cmp     %o0, 0
F00A62C4: 1280000b                 bne     locret_F00A62F0
F00A62C8: 113c04fb                 sethi   %hi(_sys_fatal_flt), %o0
F00A62CC: 92102002                 mov     2, %o1
F00A62D0: d2322070                 sth     %o1, [%o0+%lo(_sys_fatal_flt)]
F00A62D4: 90122070                 bset    %lo(_sys_fatal_flt), %o0
F00A62D8: e6322002                 sth     %l3, [%o0+2]
F00A62DC: e0222004                 st      %l0, [%o0+4]
F00A62E0: e2222008                 st      %l1, [%o0+8]
F00A62E4: e422200c                 st      %l2, [%o0+0xC]
F00A62E8: e8222010                 st      %l4, [%o0+0x10]
F00A62EC: ea222014                 st      %l5, [%o0+0x14]
F00A62F0: 81c7e008                 ret
F00A62F4: 81e80000                 restore
