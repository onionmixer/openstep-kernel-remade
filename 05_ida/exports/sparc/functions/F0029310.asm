F0029310: 9de3bf80                 save    %sp, -0x80, %sp
F0029314: 90100018                 mov     %i0, %o0
F0029318: 92100019                 mov     %i1, %o1
F002931C: b207bfe8                 add     %fp, var_18, %i1
F0029320: 7ffff7e6                 call    _pn_get
F0029324: 94100019                 mov     %i1, %o2
F0029328: b0920000                 orcc    %o0, %g0, %i0
F002932C: 1280004a                 bne     locret_F0029454
F0029330: 90100019                 mov     %i1, %o0
F0029334: c027bfe0                 clr     [%fp+var_20]
F0029338: 92102000                 mov     0, %o1
F002933C: 9407bfe4                 add     %fp, var_1C, %o2
F0029340: 7ffff5b3                 call    _lookuppn
F0029344: 9607bfe0                 add     %fp, var_20, %o3
F0029348: b0920000                 orcc    %o0, %g0, %i0
F002934C: 02800005                 be      loc_F0029360
F0029350: d207bfe0                 ld      [%fp+var_20], %o1
F0029354: 7ffff865                 call    _pn_free
F0029358: 90100019                 mov     %i1, %o0
F002935C: 3080003e                 ba,a    locret_F0029454
F0029360: 80a26000                 cmp     %o1, 0
F0029364: 32800004                 bne,a   loc_F0029374
F0029368: d0026024                 ld      [%o1+0x24], %o0
F002936C: 10800030                 ba      loc_F002942C
F0029370: b0102002                 mov     2, %i0
F0029374: d002200c                 ld      [%o0+0xC], %o0
F0029378: 808a2001                 btst    1, %o0
F002937C: 1280002c                 bne     loc_F002942C
F0029380: b010201e                 mov     0x1E, %i0
F0029384: d0126004                 lduh    [%o1+4], %o0
F0029388: 808a2001                 btst    1, %o0
F002938C: 12800028                 bne     loc_F002942C
F0029390: b0102010                 mov     0x10, %i0
F0029394: 40018b8b                 call    _vnode_uncache
F0029398: 90100009                 mov     %o1, %o0
F002939C: d207bfe0                 ld      [%fp+var_20], %o1
F00293A0: d0026028                 ld      [%o1+0x28], %o0
F00293A4: 80a22002                 cmp     %o0, 2
F00293A8: 12800013                 bne     loc_F00293F4
F00293AC: 80a6a000                 cmp     %i2, 0
F00293B0: 80a6a001                 cmp     %i2, 1
F00293B4: 1280001e                 bne     loc_F002942C
F00293B8: b0102001                 mov     1, %i0
F00293BC: d0026010                 ld      [%o1+0x10], %o0
F00293C0: 80a22000                 cmp     %o0, 0
F00293C4: 1280001a                 bne     loc_F002942C
F00293C8: b0102042                 mov     0x42, %i0 ! 'B'
F00293CC: 7ffffde6                 call    _vn_rele
F00293D0: 90100009                 mov     %o1, %o0
F00293D4: 113c04cf                 sethi   %hi(_active_u), %o0
F00293D8: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F00293DC: d207bfec                 ld      [%fp+var_14], %o1
F00293E0: d402201c                 ld      [%o0+0x1C], %o2
F00293E4: d007bfe4                 ld      [%fp+var_1C], %o0
F00293E8: d602201c                 ld      [%o0+0x1C], %o3
F00293EC: 1080000d                 ba      loc_F0029420
F00293F0: d602e038                 ld      [%o3+0x38], %o3
F00293F4: 1280000e                 bne     loc_F002942C
F00293F8: b0102014                 mov     0x14, %i0
F00293FC: 7ffffdda                 call    _vn_rele
F0029400: 90100009                 mov     %o1, %o0
F0029404: 113c04cf                 sethi   %hi(_active_u), %o0
F0029408: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F002940C: d207bfec                 ld      [%fp+var_14], %o1
F0029410: d402201c                 ld      [%o0+0x1C], %o2
F0029414: d007bfe4                 ld      [%fp+var_1C], %o0
F0029418: d602201c                 ld      [%o0+0x1C], %o3
F002941C: d602e028                 ld      [%o3+0x28], %o3
F0029420: 9fc2c000                 call    %o3
F0029424: c027bfe0                 clr     [%fp+var_20]
F0029428: b0100008                 mov     %o0, %i0
F002942C: 7ffff82f                 call    _pn_free
F0029430: 9007bfe8                 add     %fp, var_18, %o0
F0029434: d007bfe0                 ld      [%fp+var_20], %o0
F0029438: 80a22000                 cmp     %o0, 0
F002943C: 02800004                 be      loc_F002944C
F0029440: 01000000                 nop
F0029444: 7ffffdc8                 call    _vn_rele
F0029448: 01000000                 nop
F002944C: 7ffffdc6                 call    _vn_rele
F0029450: d007bfe4                 ld      [%fp+var_1C], %o0
F0029454: 81c7e008                 ret
F0029458: 81e80000                 restore
