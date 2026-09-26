F0094310: 9de3bf88                 save    %sp, -0x78, %sp
F0094314: 90100018                 mov     %i0, %o0! void *
F0094318: a007bfe8                 add     %fp, var_18, %l0
F009431C: 92100010                 mov     %l0, %o1! void *
F0094320: 400001fc                 call    _bcopy
F0094324: 9410200c                 mov     0xC, %o2
F0094328: c027bfec                 clr     [%fp+var_14]
F009432C: a4102001                 mov     1, %l2
F0094330: e427bff0                 st      %l2, [%fp+var_10]
F0094334: c027bff4                 clr     [%fp+var_C]
F0094338: f627bff8                 st      %i3, [%fp+var_8]
F009433C: f827bffc                 st      %i4, [%fp+var_4]
F0094340: fa278000                 st      %i5, [%fp+arg_0]
F0094344: 90100010                 mov     %l0, %o0! void *
F0094348: 92100018                 mov     %i0, %o1! void *
F009434C: 153f8000                 sethi   -0x2000000, %o2
F0094350: 233c04f1                 sethi   %hi(byte_F013C416), %l1
F0094354: 2100003f                 sethi   0xFC00, %l0
F0094358: d607bfe8                 ld      [%fp+var_18], %o3
F009435C: a01423ff                 bset    0x3FF, %l0
F0094360: 942ac00a                 andn    %o3, %o2, %o2
F0094364: 17068000                 sethi   0x1A000000, %o3
F0094368: 9412800b                 bset    %o3, %o2
F009436C: 17004000                 sethi   0x1000000, %o3
F0094370: 962a800b                 andn    %o2, %o3, %o3
F0094374: d40c6016                 ldub    [%l1+%lo(byte_F013C416)], %o2
F0094378: d627bfe8                 st      %o3, [%fp+var_18]
F009437C: d42fbfe9                 stb     %o2, [%fp+var_18+1]
F0094380: 9410200c                 mov     0xC, %o2
F0094384: d437bfea                 sth     %o2, [%fp+var_18+2]
F0094388: 9410201c                 mov     0x1C, %o2
F009438C: d437bfea                 sth     %o2, [%fp+var_18+2]
F0094390: d407bfe8                 ld      [%fp+var_18], %o2! size_t
F0094394: a2146016                 bset    0x16, %l1
F0094398: 400001de                 call    _bcopy
F009439C: 940a8010                 and     %o2, %l0, %o2
F00943A0: d0147ffe                 lduh    [%l1-2], %o0
F00943A4: e4246002                 st      %l2, [%l1+2]
F00943A8: d0368000                 sth     %o0, [%i2]
F00943AC: d007bfe8                 ld      [%fp+var_18], %o0
F00943B0: 900a0010                 and     %o0, %l0, %o0
F00943B4: d0264000                 st      %o0, [%i1]
F00943B8: 81c7e008                 ret
F00943BC: 81e80000                 restore
