F0027A7C: 9de3bf30                 save    %sp, -0xD0, %sp
F0027A80: 233c04cf                 sethi   %hi(dword_F0133DDC), %l1
F0027A84: d00461dc                 ld      [%l1+%lo(dword_F0133DDC)], %o0
F0027A88: 92102000                 mov     0, %o1
F0027A8C: e4022024                 ld      [%o0+0x24], %l2
F0027A90: a007bf98                 add     %fp, var_68, %l0
F0027A94: d004a004                 ld      [%l2+4], %o0
F0027A98: 7ffffe08                 call    _pn_get
F0027A9C: 94100010                 mov     %l0, %o2
F0027AA0: d20461dc                 ld      [%l1+%lo(dword_F0133DDC)], %o1
F0027AA4: d02a6038                 stb     %o0, [%o1+0x38]
F0027AA8: d00461dc                 ld      [%l1+%lo(dword_F0133DDC)], %o0
F0027AAC: d04a2038                 ldsb    [%o0+0x38], %o0
F0027AB0: 80a22000                 cmp     %o0, 0
F0027AB4: 12800039                 bne     locret_F0027B98
F0027AB8: a61461dc                 or      %l1, %lo(dword_F0133DDC), %l3
F0027ABC: 90100010                 mov     %l0, %o0
F0027AC0: 92102000                 mov     0, %o1
F0027AC4: 9407bf94                 add     %fp, var_6C, %o2
F0027AC8: 7ffffbd1                 call    _lookuppn
F0027ACC: 96102000                 mov     0, %o3
F0027AD0: d20461dc                 ld      [%l1+0x1DC], %o1
F0027AD4: d02a6038                 stb     %o0, [%o1+0x38]
F0027AD8: d20461dc                 ld      [%l1+0x1DC], %o1
F0027ADC: d04a6038                 ldsb    [%o1+0x38], %o0
F0027AE0: 80a22000                 cmp     %o0, 0
F0027AE4: 02800005                 be      loc_F0027AF8
F0027AE8: d007bf94                 ld      [%fp+var_6C], %o0
F0027AEC: 7ffffe7f                 call    _pn_free
F0027AF0: 90100010                 mov     %l0, %o0
F0027AF4: 30800029                 ba,a    locret_F0027B98
F0027AF8: d0022024                 ld      [%o0+0x24], %o0
F0027AFC: d002200c                 ld      [%o0+0xC], %o0
F0027B00: 808a2001                 btst    1, %o0
F0027B04: 22800005                 be,a    loc_F0027B18
F0027B08: d0048000                 ld      [%l2], %o0
F0027B0C: 9010201e                 mov     0x1E, %o0
F0027B10: 1080001e                 ba      loc_F0027B88
F0027B14: d02a6038                 stb     %o0, [%o1+0x38]
F0027B18: 92102000                 mov     0, %o1
F0027B1C: a407bfa8                 add     %fp, var_58, %l2
F0027B20: 7ffffde6                 call    _pn_get
F0027B24: 94100012                 mov     %l2, %o2
F0027B28: d20461dc                 ld      [%l1+0x1DC], %o1
F0027B2C: a007bfb8                 add     %fp, var_48, %l0
F0027B30: d02a6038                 stb     %o0, [%o1+0x38]
F0027B34: 40000658                 call    _vattr_null
F0027B38: 90100010                 mov     %l0, %o0
F0027B3C: 901021ff                 mov     0x1FF, %o0
F0027B40: d20461dc                 ld      [%l1+0x1DC], %o1
F0027B44: d037bfbc                 sth     %o0, [%fp+var_44]
F0027B48: d04a6038                 ldsb    [%o1+0x38], %o0
F0027B4C: 80a22000                 cmp     %o0, 0
F0027B50: 1280000e                 bne     loc_F0027B88
F0027B54: d207bf9c                 ld      [%fp+var_64], %o1
F0027B58: d607bfac                 ld      [%fp+var_54], %o3
F0027B5C: d007bf94                 ld      [%fp+var_6C], %o0
F0027B60: d804fffc                 ld      [%l3-4], %o4
F0027B64: d402201c                 ld      [%o0+0x1C], %o2
F0027B68: da02a040                 ld      [%o2+0x40], %o5
F0027B6C: d803201c                 ld      [%o4+0x1C], %o4
F0027B70: 9fc34000                 call    %o5
F0027B74: 94100010                 mov     %l0, %o2
F0027B78: d20461dc                 ld      [%l1+0x1DC], %o1
F0027B7C: d02a6038                 stb     %o0, [%o1+0x38]
F0027B80: 7ffffe5a                 call    _pn_free
F0027B84: 90100012                 mov     %l2, %o0
F0027B88: 7ffffe58                 call    _pn_free
F0027B8C: 9007bf98                 add     %fp, var_68, %o0
F0027B90: 400003f5                 call    _vn_rele
F0027B94: d007bf94                 ld      [%fp+var_6C], %o0
F0027B98: 81c7e008                 ret
F0027B9C: 81e80000                 restore
