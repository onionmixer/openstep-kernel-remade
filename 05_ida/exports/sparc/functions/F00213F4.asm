F00213F4: 9de3bf88                 save    %sp, -0x78, %sp! int
F00213F8: 233c04cf                 sethi   %hi(dword_F0133DDC), %l1
F00213FC: d00461dc                 ld      [%l1+%lo(dword_F0133DDC)], %o0
F0021400: e6022024                 ld      [%o0+0x24], %l3
F0021404: 92102008                 mov     8, %o1
F0021408: d004e00c                 ld      [%l3+0xC], %o0
F002140C: 4001a26f                 call    _useracc
F0021410: 94102000                 mov     0, %o2
F0021414: 80a22000                 cmp     %o0, 0
F0021418: 12800006                 bne     loc_F0021430
F002141C: ae1461dc                 or      %l1, %lo(dword_F0133DDC), %l7
F0021420: d20461dc                 ld      [%l1+%lo(dword_F0133DDC)], %o1
F0021424: 9010200e                 mov     0xE, %o0
F0021428: 10800071                 ba      locret_F00215EC
F002142C: d02a6038                 stb     %o0, [%o1+0x38]
F0021430: d004c000                 ld      [%l3], %o0
F0021434: d404e004                 ld      [%l3+4], %o2
F0021438: d604e008                 ld      [%l3+8], %o3
F002143C: 7ffff46c                 call    _socreate
F0021440: 9207bfec                 add     %fp, var_14, %o1
F0021444: d20461dc                 ld      [%l1+0x1DC], %o1
F0021448: d02a6038                 stb     %o0, [%o1+0x38]
F002144C: d00461dc                 ld      [%l1+0x1DC], %o0
F0021450: d04a2038                 ldsb    [%o0+0x38], %o0
F0021454: 80a22000                 cmp     %o0, 0
F0021458: 12800065                 bne     locret_F00215EC
F002145C: 01000000                 nop
F0021460: d004c000                 ld      [%l3], %o0
F0021464: d404e004                 ld      [%l3+4], %o2
F0021468: d604e008                 ld      [%l3+8], %o3
F002146C: 7ffff460                 call    _socreate
F0021470: 9207bfe8                 add     %fp, var_18, %o1
F0021474: d20461dc                 ld      [%l1+0x1DC], %o1
F0021478: d02a6038                 stb     %o0, [%o1+0x38]
F002147C: d00461dc                 ld      [%l1+0x1DC], %o0
F0021480: d04a2038                 ldsb    [%o0+0x38], %o0
F0021484: 80a22000                 cmp     %o0, 0
F0021488: 12800057                 bne     loc_F00215E4
F002148C: 01000000                 nop
F0021490: 7fffa7d5                 call    _falloc
F0021494: 01000000                 nop
F0021498: a4920000                 orcc    %o0, %g0, %l2
F002149C: 02800050                 be      loc_F00215DC
F00214A0: d00461dc                 ld      [%l1+0x1DC], %o0
F00214A4: ac102003                 mov     3, %l6
F00214A8: d0022030                 ld      [%o0+0x30], %o0
F00214AC: aa102002                 mov     2, %l5
F00214B0: d027bff0                 st      %o0, [%fp+var_10]
F00214B4: ec24a008                 st      %l6, [%l2+8]
F00214B8: ea34a00c                 sth     %l5, [%l2+0xC]
F00214BC: 113c042da8122190         set     _socketops, %l4
F00214C4: d007bfec                 ld      [%fp+var_14], %o0
F00214C8: e824a014                 st      %l4, [%l2+0x14]
F00214CC: d024a018                 st      %o0, [%l2+0x18]
F00214D0: d00461dc                 ld      [%l1+0x1DC], %o0
F00214D4: d205fffc                 ld      [%l7-4], %o1
F00214D8: d0022030                 ld      [%o0+0x30], %o0
F00214DC: d202614c                 ld      [%o1+0x14C], %o1
F00214E0: 912a2002                 sll     %o0, 2, %o0
F00214E4: 7fffa7c0                 call    _falloc
F00214E8: e4224008                 st      %l2, [%o1+%o0]
F00214EC: a0920000                 orcc    %o0, %g0, %l0
F00214F0: 22800035                 be,a    loc_F00215C4
F00214F4: c034a00e                 clrh    [%l2+0xE]
F00214F8: ec242008                 st      %l6, [%l0+8]
F00214FC: ea34200c                 sth     %l5, [%l0+0xC]
F0021500: d207bfe8                 ld      [%fp+var_18], %o1
F0021504: e8242014                 st      %l4, [%l0+0x14]
F0021508: d2242018                 st      %o1, [%l0+0x18]
F002150C: d40461dc                 ld      [%l1+0x1DC], %o2
F0021510: d605fffc                 ld      [%l7-4], %o3
F0021514: d402a030                 ld      [%o2+0x30], %o2
F0021518: d602e14c                 ld      [%o3+0x14C], %o3! int
F002151C: 952aa002                 sll     %o2, 2, %o2
F0021520: e022c00a                 st      %l0, [%o3+%o2]
F0021524: d40461dc                 ld      [%l1+0x1DC], %o2
F0021528: d402a030                 ld      [%o2+0x30], %o2! int
F002152C: d007bfec                 ld      [%fp+var_14], %o0
F0021530: 7ffff564                 call    _soconnect2
F0021534: d427bff4                 st      %o2, [%fp+var_C]
F0021538: d20461dc                 ld      [%l1+0x1DC], %o1
F002153C: d02a6038                 stb     %o0, [%o1+0x38]
F0021540: d00461dc                 ld      [%l1+0x1DC], %o0
F0021544: d04a2038                 ldsb    [%o0+0x38], %o0
F0021548: 80a22000                 cmp     %o0, 0
F002154C: 32800017                 bne,a   loc_F00215A8
F0021550: c034200e                 clrh    [%l0+0xE]
F0021554: d004e004                 ld      [%l3+4], %o0
F0021558: 80a22002                 cmp     %o0, 2
F002155C: 1280000d                 bne     loc_F0021590
F0021560: d20461dc                 ld      [%l1+0x1DC], %o1
F0021564: d007bfe8                 ld      [%fp+var_18], %o0
F0021568: 7ffff556                 call    _soconnect2
F002156C: d207bfec                 ld      [%fp+var_14], %o1
F0021570: d20461dc                 ld      [%l1+0x1DC], %o1
F0021574: d02a6038                 stb     %o0, [%o1+0x38]
F0021578: d00461dc                 ld      [%l1+0x1DC], %o0
F002157C: d04a2038                 ldsb    [%o0+0x38], %o0
F0021580: 80a22000                 cmp     %o0, 0
F0021584: 32800009                 bne,a   loc_F00215A8
F0021588: c034200e                 clrh    [%l0+0xE]
F002158C: d20461dc                 ld      [%l1+0x1DC], %o1
F0021590: 9007bff0                 add     %fp, var_10, %o0! int
F0021594: c0226030                 clr     [%o1+0x30]
F0021598: d204e00c                 ld      [%l3+0xC], %o1! int
F002159C: 4001dacc                 call    _copyout
F00215A0: 94102008                 mov     8, %o2
F00215A4: 30800012                 ba,a    locret_F00215EC
F00215A8: 113c04cf                 sethi   %hi(_active_u), %o0
F00215AC: d20221d8                 ld      [%o0+%lo(_active_u)], %o1
F00215B0: d007bff4                 ld      [%fp+var_C], %o0
F00215B4: d202614c                 ld      [%o1+0x14C], %o1
F00215B8: 912a2002                 sll     %o0, 2, %o0
F00215BC: c0224008                 clr     [%o1+%o0]
F00215C0: c034a00e                 clrh    [%l2+0xE]
F00215C4: 113c04cf                 sethi   %hi(_active_u), %o0
F00215C8: d20221d8                 ld      [%o0+%lo(_active_u)], %o1
F00215CC: d007bff0                 ld      [%fp+var_10], %o0
F00215D0: d202614c                 ld      [%o1+0x14C], %o1
F00215D4: 912a2002                 sll     %o0, 2, %o0
F00215D8: c0224008                 clr     [%o1+%o0]
F00215DC: 7ffff49a                 call    _soclose
F00215E0: d007bfe8                 ld      [%fp+var_18], %o0
F00215E4: 7ffff498                 call    _soclose
F00215E8: d007bfec                 ld      [%fp+var_14], %o0
F00215EC: 81c7e008                 ret
F00215F0: 81e80000                 restore
