F0028874: 9de3bf90                 save    %sp, -0x70, %sp
F0028878: 213c04cf                 sethi   %hi(dword_F0133DDC), %l0
F002887C: d00421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o0
F0028880: d0022024                 ld      [%o0+0x24], %o0
F0028884: d0020000                 ld      [%o0], %o0
F0028888: 40000064                 call    _getvnodefp
F002888C: 9207bff4                 add     %fp, var_C, %o1
F0028890: 92920000                 orcc    %o0, %g0, %o1
F0028894: 12800005                 bne     loc_F00288A8
F0028898: d007bff4                 ld      [%fp+var_C], %o0
F002889C: 40011227                 call    _mfs_fsync
F00288A0: d0022018                 ld      [%o0+0x18], %o0
F00288A4: 92920000                 orcc    %o0, %g0, %o1
F00288A8: 1280000b                 bne     loc_F00288D4
F00288AC: d00421dc                 ld      [%l0+0x1DC], %o0
F00288B0: d007bff4                 ld      [%fp+var_C], %o0
F00288B4: d2022020                 ld      [%o0+0x20], %o1
F00288B8: d0022018                 ld      [%o0+0x18], %o0
F00288BC: d402201c                 ld      [%o0+0x1C], %o2
F00288C0: d402a048                 ld      [%o2+0x48], %o2
F00288C4: 9fc28000                 call    %o2
F00288C8: 01000000                 nop
F00288CC: 92100008                 mov     %o0, %o1
F00288D0: d00421dc                 ld      [%l0+0x1DC], %o0
F00288D4: d22a2038                 stb     %o1, [%o0+0x38]
F00288D8: 81c7e008                 ret
F00288DC: 81e80000                 restore
