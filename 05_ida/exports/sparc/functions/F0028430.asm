F0028430: 9de3bf58                 save    %sp, -0xA8, %sp
F0028434: 253c04cf                 sethi   %hi(dword_F0133DDC), %l2
F0028438: d004a1dc                 ld      [%l2+%lo(dword_F0133DDC)], %o0
F002843C: e0022024                 ld      [%o0+0x24], %l0
F0028440: a207bfb8                 add     %fp, var_48, %l1
F0028444: 40000414                 call    _vattr_null
F0028448: 90100011                 mov     %l1, %o0
F002844C: d0042004                 ld      [%l0+4], %o0
F0028450: d037bfbe                 sth     %o0, [%fp+var_42]
F0028454: d0042008                 ld      [%l0+8], %o0
F0028458: 92102000                 mov     0, %o1
F002845C: d037bfc0                 sth     %o0, [%fp+var_40]
F0028460: d0040000                 ld      [%l0], %o0
F0028464: 400000d1                 call    _namesetattr
F0028468: 94100011                 mov     %l1, %o2
F002846C: d204a1dc                 ld      [%l2+%lo(dword_F0133DDC)], %o1
F0028470: d02a6038                 stb     %o0, [%o1+0x38]
F0028474: 81c7e008                 ret
F0028478: 81e80000                 restore
