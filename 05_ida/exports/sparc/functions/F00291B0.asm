F00291B0: 9de3bf68                 save    %sp, -0x98, %sp
F00291B4: c027bfd0                 clr     [%fp+var_30]
F00291B8: c027bfcc                 clr     [%fp+var_34]
F00291BC: c027bfd4                 clr     [%fp+var_2C]
F00291C0: 90100018                 mov     %i0, %o0
F00291C4: 9210001a                 mov     %i2, %o1
F00291C8: a007bfe8                 add     %fp, var_18, %l0
F00291CC: 7ffff83b                 call    _pn_get
F00291D0: 94100010                 mov     %l0, %o2
F00291D4: b0920000                 orcc    %o0, %g0, %i0
F00291D8: 1280004c                 bne     locret_F0029308
F00291DC: 90100019                 mov     %i1, %o0
F00291E0: 9210001a                 mov     %i2, %o1
F00291E4: b207bfd8                 add     %fp, var_28, %i1
F00291E8: 7ffff834                 call    _pn_get
F00291EC: 94100019                 mov     %i1, %o2
F00291F0: b0920000                 orcc    %o0, %g0, %i0
F00291F4: 02800005                 be      loc_F0029208
F00291F8: 90100010                 mov     %l0, %o0
F00291FC: 7ffff8bb                 call    _pn_free
F0029200: 90100010                 mov     %l0, %o0
F0029204: 30800041                 ba,a    locret_F0029308
F0029208: 92102000                 mov     0, %o1
F002920C: 9407bfd4                 add     %fp, var_2C, %o2
F0029210: 7ffff5ff                 call    _lookuppn
F0029214: 9607bfd0                 add     %fp, var_30, %o3
F0029218: b0920000                 orcc    %o0, %g0, %i0
F002921C: 12800025                 bne     loc_F00292B0
F0029220: d007bfd0                 ld      [%fp+var_30], %o0
F0029224: 80a22000                 cmp     %o0, 0
F0029228: 12800004                 bne     loc_F0029238
F002922C: 90100019                 mov     %i1, %o0
F0029230: 10800020                 ba      loc_F00292B0
F0029234: b0102002                 mov     2, %i0
F0029238: 92102000                 mov     0, %o1
F002923C: 9407bfcc                 add     %fp, var_34, %o2
F0029240: 7ffff5f3                 call    _lookuppn
F0029244: 96102000                 mov     0, %o3
F0029248: b0920000                 orcc    %o0, %g0, %i0
F002924C: 12800019                 bne     loc_F00292B0
F0029250: d007bfd0                 ld      [%fp+var_30], %o0
F0029254: d407bfcc                 ld      [%fp+var_34], %o2
F0029258: d2022024                 ld      [%o0+0x24], %o1
F002925C: d002a024                 ld      [%o2+0x24], %o0
F0029260: 80a24008                 cmp     %o1, %o0
F0029264: 12800013                 bne     loc_F00292B0
F0029268: b0102012                 mov     0x12, %i0
F002926C: d002600c                 ld      [%o1+0xC], %o0
F0029270: 808a2001                 btst    1, %o0
F0029274: 1280000f                 bne     loc_F00292B0
F0029278: b010201e                 mov     0x1E, %i0
F002927C: 40018bd1                 call    _vnode_uncache
F0029280: 9010000a                 mov     %o2, %o0
F0029284: d207bfec                 ld      [%fp+var_14], %o1
F0029288: d407bfcc                 ld      [%fp+var_34], %o2
F002928C: d607bfdc                 ld      [%fp+var_24], %o3
F0029290: d007bfd4                 ld      [%fp+var_2C], %o0
F0029294: 193c04cf                 sethi   %hi(_active_u), %o4
F0029298: d80321d8                 ld      [%o4+%lo(_active_u)], %o4
F002929C: da02201c                 ld      [%o0+0x1C], %o5
F00292A0: da036030                 ld      [%o5+0x30], %o5
F00292A4: 9fc34000                 call    %o5
F00292A8: d803201c                 ld      [%o4+0x1C], %o4
F00292AC: b0100008                 mov     %o0, %i0
F00292B0: 7ffff88e                 call    _pn_free
F00292B4: 9007bfe8                 add     %fp, var_18, %o0
F00292B8: 7ffff88c                 call    _pn_free
F00292BC: 9007bfd8                 add     %fp, var_28, %o0
F00292C0: d007bfd0                 ld      [%fp+var_30], %o0
F00292C4: 80a22000                 cmp     %o0, 0
F00292C8: 22800005                 be,a    loc_F00292DC
F00292CC: d007bfd4                 ld      [%fp+var_2C], %o0
F00292D0: 7ffffe25                 call    _vn_rele
F00292D4: 01000000                 nop
F00292D8: d007bfd4                 ld      [%fp+var_2C], %o0
F00292DC: 80a22000                 cmp     %o0, 0
F00292E0: 22800005                 be,a    loc_F00292F4
F00292E4: d007bfcc                 ld      [%fp+var_34], %o0
F00292E8: 7ffffe1f                 call    _vn_rele
F00292EC: 01000000                 nop
F00292F0: d007bfcc                 ld      [%fp+var_34], %o0
F00292F4: 80a22000                 cmp     %o0, 0
F00292F8: 02800004                 be      locret_F0029308
F00292FC: 01000000                 nop
F0029300: 7ffffe19                 call    _vn_rele
F0029304: 01000000                 nop
F0029308: 81c7e008                 ret
F002930C: 81e80000                 restore
