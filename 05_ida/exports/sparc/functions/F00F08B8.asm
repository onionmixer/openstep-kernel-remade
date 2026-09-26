F00F08B8: 9de3bf98                 save    %sp, -0x68, %sp
F00F08BC: 313c04bc                 sethi   %hi(dword_F012F0E0), %i0
F00F08C0: d00620e0                 ld      [%i0+%lo(dword_F012F0E0)], %o0
F00F08C4: 80a22000                 cmp     %o0, 0
F00F08C8: 1280000b                 bne     loc_F00F08F4
F00F08CC: 113c04bc                 sethi   -0xFED1000, %o0
F00F08D0: 11000008                 sethi   0x2000, %o0
F00F08D4: 92100008                 mov     %o0, %o1
F00F08D8: 400000a3                 call    _NXCreateZone
F00F08DC: 94102001                 mov     1, %o2
F00F08E0: d02620e0                 st      %o0, [%i0+%lo(dword_F012F0E0)]
F00F08E4: 133c03f4                 sethi   %hi(aObjc_0), %o1! "ObjC"
F00F08E8: 400000a2                 call    _NXNameZone
F00F08EC: 92126170                 bset    %lo(aObjc_0), %o1! "ObjC"
F00F08F0: 113c04bc                 sethi   -0xFED1000, %o0
F00F08F4: f00220e0                 ld      [%o0+0xE0], %i0
F00F08F8: 81c7e008                 ret
F00F08FC: 81e80000                 restore
