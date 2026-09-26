F00283EC: 9de3bf58                 save    %sp, -0xA8, %sp
F00283F0: 253c04cf                 sethi   %hi(dword_F0133DDC), %l2
F00283F4: d004a1dc                 ld      [%l2+%lo(dword_F0133DDC)], %o0
F00283F8: e0022024                 ld      [%o0+0x24], %l0
F00283FC: a207bfb8                 add     %fp, var_48, %l1
F0028400: 40000425                 call    _vattr_null
F0028404: 90100011                 mov     %l1, %o0
F0028408: d0042004                 ld      [%l0+4], %o0
F002840C: 900a2fff                 and     %o0, 0xFFF, %o0
F0028410: d037bfbc                 sth     %o0, [%fp+var_44]
F0028414: d0040000                 ld      [%l0], %o0
F0028418: 40000100                 call    _fdsetattr
F002841C: 92100011                 mov     %l1, %o1
F0028420: d204a1dc                 ld      [%l2+%lo(dword_F0133DDC)], %o1
F0028424: d02a6038                 stb     %o0, [%o1+0x38]
F0028428: 81c7e008                 ret
F002842C: 81e80000                 restore
