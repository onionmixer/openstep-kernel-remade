F00282CC: 9de3bf70                 save    %sp, -0x90, %sp
F00282D0: 233c04cf                 sethi   %hi(dword_F0133DDC), %l1
F00282D4: 92102000                 mov     0, %o1
F00282D8: d00461dc                 ld      [%l1+%lo(dword_F0133DDC)], %o0
F00282DC: 94102000                 mov     0, %o2
F00282E0: e0022024                 ld      [%o0+0x24], %l0
F00282E4: 96102000                 mov     0, %o3
F00282E8: d0040000                 ld      [%l0], %o0
F00282EC: 7ffff9b6                 call    _lookupname
F00282F0: 9807bfd4                 add     %fp, var_2C, %o4
F00282F4: d20461dc                 ld      [%l1+%lo(dword_F0133DDC)], %o1
F00282F8: d02a6038                 stb     %o0, [%o1+0x38]
F00282FC: d20461dc                 ld      [%l1+%lo(dword_F0133DDC)], %o1
F0028300: d04a6038                 ldsb    [%o1+0x38], %o0
F0028304: 80a22000                 cmp     %o0, 0
F0028308: 12800025                 bne     locret_F002839C
F002830C: a41461dc                 or      %l1, %lo(dword_F0133DDC), %l2
F0028310: d607bfd4                 ld      [%fp+var_2C], %o3
F0028314: d002e028                 ld      [%o3+0x28], %o0
F0028318: 80a22005                 cmp     %o0, 5
F002831C: 22800004                 be,a    loc_F002832C
F0028320: d0042004                 ld      [%l0+4], %o0
F0028324: 10800015                 ba      loc_F0028378
F0028328: 90102016                 mov     0x16, %o0
F002832C: d027bff0                 st      %o0, [%fp+var_10]
F0028330: d0042008                 ld      [%l0+8], %o0
F0028334: d027bff4                 st      %o0, [%fp+var_C]
F0028338: 9007bff0                 add     %fp, var_10, %o0
F002833C: d027bfd8                 st      %o0, [%fp+var_28]
F0028340: 90102001                 mov     1, %o0
F0028344: d027bfdc                 st      %o0, [%fp+var_24]
F0028348: c027bfe0                 clr     [%fp+var_20]
F002834C: c027bfe4                 clr     [%fp+var_1C]
F0028350: d0042008                 ld      [%l0+8], %o0
F0028354: d204bffc                 ld      [%l2-4], %o1
F0028358: d027bfec                 st      %o0, [%fp+var_14]
F002835C: d402601c                 ld      [%o1+0x1C], %o2
F0028360: d202e01c                 ld      [%o3+0x1C], %o1
F0028364: 9010000b                 mov     %o3, %o0
F0028368: d6026044                 ld      [%o1+0x44], %o3
F002836C: 9fc2c000                 call    %o3
F0028370: 9207bfd8                 add     %fp, var_28, %o1
F0028374: d20461dc                 ld      [%l1+0x1DC], %o1
F0028378: d02a6038                 stb     %o0, [%o1+0x38]
F002837C: 400001fa                 call    _vn_rele
F0028380: d007bfd4                 ld      [%fp+var_2C], %o0
F0028384: d2042008                 ld      [%l0+8], %o1
F0028388: d407bfec                 ld      [%fp+var_14], %o2
F002838C: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F0028390: d00221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o0
F0028394: 9222400a                 sub     %o1, %o2, %o1
F0028398: d2222030                 st      %o1, [%o0+0x30]
F002839C: 81c7e008                 ret
F00283A0: 81e80000                 restore
