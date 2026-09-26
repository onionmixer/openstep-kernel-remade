F00EE140: 9de3bf88                 save    %sp, -0x78, %sp
F00EE144: a0960000                 orcc    %i0, %g0, %l0
F00EE148: 0280002c                 be      loc_F00EE1F8
F00EE14C: 313c04bc                 sethi   %hi(dword_F012F084), %i0
F00EE150: 113c04bc                 sethi   %hi(dword_F012F088), %o0
F00EE154: d2022088                 ld      [%o0+%lo(dword_F012F088)], %o1
F00EE158: 92026001                 inc     %o1
F00EE15C: d2222088                 st      %o1, [%o0+%lo(dword_F012F088)]
F00EE160: d0062084                 ld      [%i0+%lo(dword_F012F084)], %o0
F00EE164: 80a22000                 cmp     %o0, 0
F00EE168: 12800012                 bne     loc_F00EE1B0
F00EE16C: 113c04bc                 sethi   %hi(dword_F012F298), %o0
F00EE170: 113c03c292122298         set     _NXStrPrototype, %o1
F00EE178: d0022298                 ld      [%o0+%lo(dword_F012F298)], %o0
F00EE17C: d027bfe8                 st      %o0, [%fp+var_18]
F00EE180: d0026004                 ld      [%o1+4], %o0
F00EE184: d027bfec                 st      %o0, [%fp+var_14]
F00EE188: d0026008                 ld      [%o1+8], %o0
F00EE18C: d027bff0                 st      %o0, [%fp+var_10]
F00EE190: d002600c                 ld      [%o1+0xC], %o0
F00EE194: d027bff4                 st      %o0, [%fp+var_C]
F00EE198: 9007bfe8                 add     %fp, var_18, %o0! prototype
F00EE19C: 92102000                 mov     0, %o1! data
F00EE1A0: 7ffffbf1                 call    _NXCreateHashTable
F00EE1A4: 94102000                 mov     0, %o2
F00EE1A8: d0262084                 st      %o0, [%i0+0x84]
F00EE1AC: 113c04bc                 sethi   -0xFED1000, %o0
F00EE1B0: d0022084                 ld      [%o0+0x84], %o0! table
F00EE1B4: 7ffffd42                 call    _NXHashGet
F00EE1B8: 92100010                 mov     %l0, %o1! data
F00EE1BC: b0920000                 orcc    %o0, %g0, %i0
F00EE1C0: 1280000f                 bne     locret_F00EE1FC
F00EE1C4: 01000000                 nop
F00EE1C8: 7fffff9a                 call    sub_F00EE030
F00EE1CC: 90100010                 mov     %l0, %o0
F00EE1D0: b0100008                 mov     %o0, %i0
F00EE1D4: 113c04bc                 sethi   %hi(dword_F012F084), %o0
F00EE1D8: d0022084                 ld      [%o0+%lo(dword_F012F084)], %o0! table
F00EE1DC: 7ffffda7                 call    _NXHashInsert
F00EE1E0: 92100018                 mov     %i0, %o1
F00EE1E4: 80a22000                 cmp     %o0, 0
F00EE1E8: 02800005                 be      locret_F00EE1FC
F00EE1EC: 113c03f3                 sethi   %hi(aNxuniquestring), %o0! "*** NXUniqueString: invariant broken\n"
F00EE1F0: 400009d6                 call    __NXLogError
F00EE1F4: 90122328                 bset    %lo(aNxuniquestring), %o0! "*** NXUniqueString: invariant broken\n"
F00EE1F8: b0102000                 mov     0, %i0
F00EE1FC: 81c7e008                 ret
F00EE200: 81e80000                 restore
