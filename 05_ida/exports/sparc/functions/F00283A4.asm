F00283A4: 9de3bf58                 save    %sp, -0xA8, %sp
F00283A8: 253c04cf                 sethi   %hi(dword_F0133DDC), %l2
F00283AC: d004a1dc                 ld      [%l2+%lo(dword_F0133DDC)], %o0
F00283B0: e0022024                 ld      [%o0+0x24], %l0
F00283B4: a207bfb8                 add     %fp, var_48, %l1
F00283B8: 40000437                 call    _vattr_null
F00283BC: 90100011                 mov     %l1, %o0
F00283C0: d0042004                 ld      [%l0+4], %o0
F00283C4: 92102001                 mov     1, %o1
F00283C8: 900a2fff                 and     %o0, 0xFFF, %o0
F00283CC: d037bfbc                 sth     %o0, [%fp+var_44]
F00283D0: d0040000                 ld      [%l0], %o0
F00283D4: 400000f5                 call    _namesetattr
F00283D8: 94100011                 mov     %l1, %o2
F00283DC: d204a1dc                 ld      [%l2+%lo(dword_F0133DDC)], %o1
F00283E0: d02a6038                 stb     %o0, [%o1+0x38]
F00283E4: 81c7e008                 ret
F00283E8: 81e80000                 restore
