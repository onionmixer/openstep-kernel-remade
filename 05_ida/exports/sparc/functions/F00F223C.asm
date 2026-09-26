F00F223C: 9de3bf88                 save    %sp, -0x78, %sp
F00F2240: 7ffffec7                 call    _objc_lookUpClass
F00F2244: d0062004                 ld      [%i0+4], %o0
F00F2248: 80a22000                 cmp     %o0, 0
F00F224C: 02800005                 be      loc_F00F2260
F00F2250: 90100018                 mov     %i0, %o0
F00F2254: 7fffffa6                 call    __objc_add_category
F00F2258: 92100019                 mov     %i1, %o1
F00F225C: 30800029                 ba,a    locret_F00F2300
F00F2260: 233c04bc                 sethi   %hi(dword_F012F14C), %l1
F00F2264: d004614c                 ld      [%l1+%lo(dword_F012F14C)], %o0
F00F2268: 80a22000                 cmp     %o0, 0
F00F226C: 12800014                 bne     loc_F00F22BC
F00F2270: 253c04bc                 sethi   -0xFED1000, %l2
F00F2274: 113c03c2921222d8         set     _NXStrValueMapPrototype, %o1
F00F227C: d00222d8                 ld      [%o0+0x2D8], %o0
F00F2280: d027bfe8                 st      %o0, [%fp+var_18]
F00F2284: d0026004                 ld      [%o1+4], %o0
F00F2288: d027bfec                 st      %o0, [%fp+var_14]
F00F228C: d0026008                 ld      [%o1+8], %o0
F00F2290: d027bff0                 st      %o0, [%fp+var_10]
F00F2294: d002600c                 ld      [%o1+0xC], %o0
F00F2298: d027bff4                 st      %o0, [%fp+var_C]
F00F229C: 7ffff987                 call    __objc_create_zone
F00F22A0: a007bfe8                 add     %fp, var_18, %l0
F00F22A4: 94100008                 mov     %o0, %o2
F00F22A8: 90100010                 mov     %l0, %o0
F00F22AC: 7ffff052                 call    _NXCreateMapTableFromZone
F00F22B0: 92102080                 mov     0x80, %o1
F00F22B4: d024614c                 st      %o0, [%l1+0x14C]
F00F22B8: 253c04bc                 sethi   -0xFED1000, %l2
F00F22BC: d004a14c                 ld      [%l2+0x14C], %o0
F00F22C0: 7ffff15c                 call    _NXMapGet
F00F22C4: d2062004                 ld      [%i0+4], %o1
F00F22C8: 7ffff97c                 call    __objc_create_zone
F00F22CC: a2100008                 mov     %o0, %l1
F00F22D0: 7ffff97a                 call    __objc_create_zone
F00F22D4: a0100008                 mov     %o0, %l0
F00F22D8: d4042004                 ld      [%l0+4], %o2
F00F22DC: 9fc28000                 call    %o2
F00F22E0: 9210200c                 mov     0xC, %o1
F00F22E4: 94100008                 mov     %o0, %o2
F00F22E8: e2228000                 st      %l1, [%o2]
F00F22EC: f022a004                 st      %i0, [%o2+4]
F00F22F0: f222a008                 st      %i1, [%o2+8]
F00F22F4: d004a14c                 ld      [%l2+0x14C], %o0
F00F22F8: 7ffff1e7                 call    _NXMapInsert
F00F22FC: d2062004                 ld      [%i0+4], %o1
F00F2300: 81c7e008                 ret
F00F2304: 81e80000                 restore
