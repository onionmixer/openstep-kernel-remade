F00BC878: 9de3bf98                 save    %sp, -0x68, %sp
F00BC87C: 213c04fd                 sethi   %hi(_kmId), %l0
F00BC880: d0042240                 ld      [%l0+%lo(_kmId)], %o0
F00BC884: 80a22000                 cmp     %o0, 0
F00BC888: 02800034                 be      locret_F00BC958
F00BC88C: b0102000                 mov     0, %i0
F00BC890: d0022108                 ld      [%o0+0x108], %o0
F00BC894: 133c0504                 sethi   %hi(paLock), %o1
F00BC898: 153c04c8                 sethi   %hi(dword_F0132068), %o2
F00BC89C: d402a068                 ld      [%o2+%lo(dword_F0132068)], %o2
F00BC8A0: 9fc28000                 call    %o2
F00BC8A4: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00BC8A8: d2042240                 ld      [%l0+%lo(_kmId)], %o1
F00BC8AC: d0026114                 ld      [%o1+0x114], %o0
F00BC8B0: 80a22003                 cmp     %o0, 3
F00BC8B4: 32800021                 bne,a   loc_F00BC938
F00BC8B8: b0102016                 mov     0x16, %i0
F00BC8BC: d002611c                 ld      [%o1+0x11C], %o0
F00BC8C0: 80a22000                 cmp     %o0, 0
F00BC8C4: 32800004                 bne,a   loc_F00BC8D4
F00BC8C8: 90023fff                 inc     -1, %o0
F00BC8CC: 1080001b                 ba      loc_F00BC938
F00BC8D0: b0102010                 mov     0x10, %i0
F00BC8D4: 80a22000                 cmp     %o0, 0
F00BC8D8: 12800018                 bne     loc_F00BC938
F00BC8DC: d022611c                 st      %o0, [%o1+0x11C]
F00BC8E0: d0026118                 ld      [%o1+0x118], %o0
F00BC8E4: 80a22003                 cmp     %o0, 3
F00BC8E8: 0280000f                 be      loc_F00BC924
F00BC8EC: d0226114                 st      %o0, [%o1+0x114]
F00BC8F0: d0026110                 ld      [%o1+0x110], %o0
F00BC8F4: d2022008                 ld      [%o0+8], %o1
F00BC8F8: 9fc24000                 call    %o1
F00BC8FC: 01000000                 nop
F00BC900: d2042240                 ld      [%l0+0x240], %o1
F00BC904: d2026110                 ld      [%o1+0x110], %o1
F00BC908: b0100008                 mov     %o0, %i0
F00BC90C: d4024000                 ld      [%o1], %o2
F00BC910: 9fc28000                 call    %o2
F00BC914: 90100009                 mov     %o1, %o0
F00BC918: d0042240                 ld      [%l0+0x240], %o0
F00BC91C: 10800007                 ba      loc_F00BC938
F00BC920: c0222110                 clr     [%o0+0x110]
F00BC924: 113c047f                 sethi   %hi(aKmdeviceRecurs), %o0! "kmDevice: Recursive SCM_ALERT in restor"...
F00BC928: 400025f3                 call    _IOLog
F00BC92C: 90122390                 bset    %lo(aKmdeviceRecurs), %o0! "kmDevice: Recursive SCM_ALERT in restor"...
F00BC930: 10800003                 ba      loc_F00BC93C
F00BC934: 113c0504                 sethi   -0xFEBF000, %o0
F00BC938: 113c0504                 sethi   -0xFEBF000, %o0
F00BC93C: d2022244                 ld      [%o0+0x244], %o1
F00BC940: 153c04c8                 sethi   %hi(dword_F013206C), %o2
F00BC944: d402a06c                 ld      [%o2+%lo(dword_F013206C)], %o2
F00BC948: 113c04fd                 sethi   %hi(_kmId), %o0
F00BC94C: d0022240                 ld      [%o0+%lo(_kmId)], %o0
F00BC950: 9fc28000                 call    %o2
F00BC954: d0022108                 ld      [%o0+0x108], %o0
F00BC958: 81c7e008                 ret
F00BC95C: 81e80000                 restore
