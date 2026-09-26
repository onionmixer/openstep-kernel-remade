F00EE204: 9de3bf88                 save    %sp, -0x78, %sp
F00EE208: 113c04bc                 sethi   %hi(dword_F012F088), %o0
F00EE20C: d2022088                 ld      [%o0+%lo(dword_F012F088)], %o1
F00EE210: 92026001                 inc     %o1
F00EE214: d2222088                 st      %o1, [%o0+%lo(dword_F012F088)]
F00EE218: 213c04bc                 sethi   %hi(dword_F012F084), %l0
F00EE21C: d0042084                 ld      [%l0+%lo(dword_F012F084)], %o0
F00EE220: 80a22000                 cmp     %o0, 0
F00EE224: 12800012                 bne     loc_F00EE26C
F00EE228: 113c04bc                 sethi   %hi(dword_F012F298), %o0
F00EE22C: 113c03c292122298         set     _NXStrPrototype, %o1
F00EE234: d0022298                 ld      [%o0+%lo(dword_F012F298)], %o0
F00EE238: d027bfe8                 st      %o0, [%fp+var_18]
F00EE23C: d0026004                 ld      [%o1+4], %o0
F00EE240: d027bfec                 st      %o0, [%fp+var_14]
F00EE244: d0026008                 ld      [%o1+8], %o0
F00EE248: d027bff0                 st      %o0, [%fp+var_10]
F00EE24C: d002600c                 ld      [%o1+0xC], %o0
F00EE250: d027bff4                 st      %o0, [%fp+var_C]
F00EE254: 9007bfe8                 add     %fp, var_18, %o0! prototype
F00EE258: 92102000                 mov     0, %o1! data
F00EE25C: 7ffffbc2                 call    _NXCreateHashTable
F00EE260: 94102000                 mov     0, %o2
F00EE264: d0242084                 st      %o0, [%l0+0x84]
F00EE268: 113c04bc                 sethi   -0xFED1000, %o0
F00EE26C: d0022084                 ld      [%o0+0x84], %o0! table
F00EE270: 7ffffde7                 call    _NXHashInsertIfAbsent
F00EE274: 92100018                 mov     %i0, %o1
F00EE278: 81c7e008                 ret
F00EE27C: 91e80008                 restore %g0, %o0, %o0
