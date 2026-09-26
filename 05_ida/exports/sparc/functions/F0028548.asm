F0028548: 9de3bf48                 save    %sp, -0xB8, %sp! int
F002854C: 133c04cfa01261dc         set     dword_F0133DDC, %l0
F0028554: d0043ffc                 ld      [%l0-4], %o0
F0028558: d20261dc                 ld      [%o1+0x1DC], %o1
F002855C: d0020000                 ld      [%o0], %o0
F0028560: e4026024                 ld      [%o1+0x24], %l2
F0028564: 7fff996f                 call    _get_posix_proc
F0028568: d0522030                 ldsh    [%o0+0x30], %o0
F002856C: a2100008                 mov     %o0, %l1
F0028570: 7fffaa87                 call    _getthetime
F0028574: 9007bfa8                 add     %fp, var_58, %o0
F0028578: 400003c7                 call    _vattr_null
F002857C: 9007bfb0                 add     %fp, var_50, %o0
F0028580: d0043ffc                 ld      [%l0-4], %o0
F0028584: d0020000                 ld      [%o0], %o0
F0028588: d2022014                 ld      [%o0+0x14], %o1
F002858C: 11000010                 sethi   0x4000, %o0
F0028590: 808a4008                 btst    %o0, %o1
F0028594: 22800010                 be,a    loc_F00285D4
F0028598: 9207bff0                 add     %fp, var_10, %o1
F002859C: d004a004                 ld      [%l2+4], %o0
F00285A0: 80a22000                 cmp     %o0, 0
F00285A4: 3280000d                 bne,a   loc_F00285D8
F00285A8: 9207bff0                 add     %fp, var_10, %o1
F00285AC: d01fbfa8                 ldd     [%fp+var_58], %o0
F00285B0: d027bfd8                 st      %o0, [%fp+var_28]
F00285B4: d027bfd0                 st      %o0, [%fp+var_30]
F00285B8: d227bfdc                 st      %o1, [%fp+var_24]
F00285BC: d227bfd4                 st      %o1, [%fp+var_2C]
F00285C0: d0046018                 ld      [%l1+0x18], %o0
F00285C4: 13200000                 sethi   0x80000000, %o1! int
F00285C8: 90120009                 bset    %o1, %o0
F00285CC: 10800013                 ba      loc_F0028618
F00285D0: d0246018                 st      %o0, [%l1+0x18]
F00285D4: d004a004                 ld      [%l2+4], %o0! int
F00285D8: 4001bea0                 call    _copyin
F00285DC: 94102008                 mov     8, %o2
F00285E0: 153c04cf                 sethi   %hi(dword_F0133DDC), %o2
F00285E4: d202a1dc                 ld      [%o2+%lo(dword_F0133DDC)], %o1
F00285E8: d02a6038                 stb     %o0, [%o1+0x38]
F00285EC: d002a1dc                 ld      [%o2+%lo(dword_F0133DDC)], %o0
F00285F0: d04a2038                 ldsb    [%o0+0x38], %o0
F00285F4: 80a22000                 cmp     %o0, 0
F00285F8: 12800023                 bne     locret_F0028684
F00285FC: 01000000                 nop
F0028600: c027bfdc                 clr     [%fp+var_24]
F0028604: d207bff0                 ld      [%fp+var_10], %o1
F0028608: c027bfd4                 clr     [%fp+var_2C]
F002860C: d007bff4                 ld      [%fp+var_C], %o0
F0028610: d227bfd0                 st      %o1, [%fp+var_30]
F0028614: d027bfd8                 st      %o0, [%fp+var_28]
F0028618: 92102001                 mov     1, %o1
F002861C: d0048000                 ld      [%l2], %o0
F0028620: 40000062                 call    _namesetattr
F0028624: 9407bfb0                 add     %fp, var_50, %o2
F0028628: 13200000                 sethi   0x80000000, %o1
F002862C: d4046018                 ld      [%l1+0x18], %o2
F0028630: 173c04cf                 sethi   %hi(dword_F0133DDC), %o3
F0028634: 922a8009                 andn    %o2, %o1, %o1
F0028638: d2246018                 st      %o1, [%l1+0x18]
F002863C: 9212e1dc                 or      %o3, %lo(dword_F0133DDC), %o1
F0028640: d2027ffc                 ld      [%o1-4], %o1
F0028644: d2024000                 ld      [%o1], %o1
F0028648: d4026014                 ld      [%o1+0x14], %o2
F002864C: 13000010                 sethi   0x4000, %o1
F0028650: 808a8009                 btst    %o1, %o2
F0028654: d402e1dc                 ld      [%o3+%lo(dword_F0133DDC)], %o2
F0028658: 02800009                 be      loc_F002867C
F002865C: 92100008                 mov     %o0, %o1
F0028660: 80a26001                 cmp     %o1, 1
F0028664: 12800007                 bne     loc_F0028680
F0028668: 90100009                 mov     %o1, %o0
F002866C: d004a004                 ld      [%l2+4], %o0
F0028670: 80a22000                 cmp     %o0, 0
F0028674: 02800003                 be      loc_F0028680
F0028678: 9010200d                 mov     0xD, %o0
F002867C: 90100009                 mov     %o1, %o0
F0028680: d02aa038                 stb     %o0, [%o2+0x38]
F0028684: 81c7e008                 ret
F0028688: 81e80000                 restore
