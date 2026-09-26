F002868C: 9de3bf58                 save    %sp, -0xA8, %sp
F0028690: 253c04cf                 sethi   %hi(dword_F0133DDC), %l2
F0028694: d204a1dc                 ld      [%l2+%lo(dword_F0133DDC)], %o1
F0028698: e2026024                 ld      [%o1+0x24], %l1
F002869C: d0046004                 ld      [%l1+4], %o0
F00286A0: 80a22000                 cmp     %o0, 0
F00286A4: 16800004                 bge     loc_F00286B4
F00286A8: a007bfb8                 add     %fp, var_48, %l0
F00286AC: 1080000b                 ba      loc_F00286D8
F00286B0: 90102016                 mov     0x16, %o0
F00286B4: 40000378                 call    _vattr_null
F00286B8: 90100010                 mov     %l0, %o0
F00286BC: d0046004                 ld      [%l1+4], %o0
F00286C0: 92102001                 mov     1, %o1
F00286C4: d027bfd0                 st      %o0, [%fp+var_30]
F00286C8: d0044000                 ld      [%l1], %o0
F00286CC: 40000037                 call    _namesetattr
F00286D0: 94100010                 mov     %l0, %o2
F00286D4: d204a1dc                 ld      [%l2+0x1DC], %o1
F00286D8: d02a6038                 stb     %o0, [%o1+0x38]
F00286DC: 81c7e008                 ret
F00286E0: 81e80000                 restore
