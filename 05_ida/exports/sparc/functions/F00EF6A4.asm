F00EF6A4: 9de3bf88                 save    %sp, -0x78, %sp
F00EF6A8: 233c04bc                 sethi   %hi(dword_F012F0DC), %l1
F00EF6AC: d00460dc                 ld      [%l1+%lo(dword_F012F0DC)], %o0
F00EF6B0: 80a22000                 cmp     %o0, 0
F00EF6B4: 12800014                 bne     loc_F00EF704
F00EF6B8: 213c04bc                 sethi   -0xFED1000, %l0
F00EF6BC: 113c03c2921222d8         set     _NXStrValueMapPrototype, %o1
F00EF6C4: d00222d8                 ld      [%o0+0x2D8], %o0
F00EF6C8: d027bfe8                 st      %o0, [%fp+var_18]
F00EF6CC: d0026004                 ld      [%o1+4], %o0
F00EF6D0: d027bfec                 st      %o0, [%fp+var_14]
F00EF6D4: d0026008                 ld      [%o1+8], %o0
F00EF6D8: d027bff0                 st      %o0, [%fp+var_10]
F00EF6DC: d002600c                 ld      [%o1+0xC], %o0
F00EF6E0: d027bff4                 st      %o0, [%fp+var_C]
F00EF6E4: 40000475                 call    __objc_create_zone
F00EF6E8: a007bfe8                 add     %fp, var_18, %l0
F00EF6EC: 94100008                 mov     %o0, %o2
F00EF6F0: 90100010                 mov     %l0, %o0
F00EF6F4: 7ffffb40                 call    _NXCreateMapTableFromZone
F00EF6F8: 92102008                 mov     8, %o1
F00EF6FC: d02460dc                 st      %o0, [%l1+0xDC]
F00EF700: 213c04bc                 sethi   -0xFED1000, %l0
F00EF704: d00420dc                 ld      [%l0+0xDC], %o0
F00EF708: 7ffffc4a                 call    _NXMapGet
F00EF70C: d2062008                 ld      [%i0+8], %o1
F00EF710: 80a22000                 cmp     %o0, 0
F00EF714: 12800005                 bne     locret_F00EF728
F00EF718: d00420dc                 ld      [%l0+0xDC], %o0
F00EF71C: d2062008                 ld      [%i0+8], %o1
F00EF720: 7ffffcdd                 call    _NXMapInsert
F00EF724: 94100018                 mov     %i0, %o2
F00EF728: 81c7e008                 ret
F00EF72C: 81e80000                 restore
