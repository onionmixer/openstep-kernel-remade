F00286E4: 9de3bf50                 save    %sp, -0xB0, %sp
F00286E8: 273c04cf                 sethi   %hi(dword_F0133DDC), %l3
F00286EC: d204e1dc                 ld      [%l3+%lo(dword_F0133DDC)], %o1
F00286F0: e4026024                 ld      [%o1+0x24], %l2
F00286F4: d004a004                 ld      [%l2+4], %o0
F00286F8: 80a22000                 cmp     %o0, 0
F00286FC: 36800004                 bge,a   loc_F002870C
F0028700: d0048000                 ld      [%l2], %o0
F0028704: 10800026                 ba      loc_F002879C
F0028708: 90102016                 mov     0x16, %o0
F002870C: 400000c3                 call    _getvnodefp
F0028710: 9207bff4                 add     %fp, var_C, %o1
F0028714: d204e1dc                 ld      [%l3+0x1DC], %o1
F0028718: d02a6038                 stb     %o0, [%o1+0x38]
F002871C: d404e1dc                 ld      [%l3+0x1DC], %o2
F0028720: d04aa038                 ldsb    [%o2+0x38], %o0
F0028724: 80a22000                 cmp     %o0, 0
F0028728: 1280001e                 bne     locret_F00287A0
F002872C: d007bff4                 ld      [%fp+var_C], %o0
F0028730: d2022008                 ld      [%o0+8], %o1
F0028734: 808a6002                 btst    2, %o1
F0028738: 12800005                 bne     loc_F002874C
F002873C: e2022018                 ld      [%o0+0x18], %l1
F0028740: 90102016                 mov     0x16, %o0
F0028744: 10800017                 ba      locret_F00287A0
F0028748: d02aa038                 stb     %o0, [%o2+0x38]
F002874C: d0046024                 ld      [%l1+0x24], %o0
F0028750: d002200c                 ld      [%o0+0xC], %o0
F0028754: 808a2001                 btst    1, %o0
F0028758: 02800005                 be      loc_F002876C
F002875C: a007bfb0                 add     %fp, var_50, %l0
F0028760: 9010201e                 mov     0x1E, %o0
F0028764: 1080000f                 ba      locret_F00287A0
F0028768: d02aa038                 stb     %o0, [%o2+0x38]
F002876C: 4000034a                 call    _vattr_null
F0028770: 90100010                 mov     %l0, %o0
F0028774: d004a004                 ld      [%l2+4], %o0
F0028778: d207bff4                 ld      [%fp+var_C], %o1
F002877C: d027bfc8                 st      %o0, [%fp+var_38]
F0028780: d004601c                 ld      [%l1+0x1C], %o0
F0028784: d4026020                 ld      [%o1+0x20], %o2
F0028788: d6022018                 ld      [%o0+0x18], %o3
F002878C: 92100010                 mov     %l0, %o1
F0028790: 9fc2c000                 call    %o3
F0028794: 90100011                 mov     %l1, %o0
F0028798: d204e1dc                 ld      [%l3+0x1DC], %o1
F002879C: d02a6038                 stb     %o0, [%o1+0x38]
F00287A0: 81c7e008                 ret
F00287A4: 81e80000                 restore
