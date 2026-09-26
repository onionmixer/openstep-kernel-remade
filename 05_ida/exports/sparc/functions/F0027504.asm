F0027504: 9de3bf90                 save    %sp, -0x70, %sp
F0027508: 213c04cf                 sethi   %hi(dword_F0133DDC), %l0
F002750C: d00421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o0
F0027510: d0022024                 ld      [%o0+0x24], %o0
F0027514: d0020000                 ld      [%o0], %o0
F0027518: 4000002f                 call    _chdirec
F002751C: 9207bff4                 add     %fp, var_C, %o1
F0027520: d20421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o1
F0027524: d02a6038                 stb     %o0, [%o1+0x38]
F0027528: d00421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o0
F002752C: d04a2038                 ldsb    [%o0+0x38], %o0
F0027530: 80a22000                 cmp     %o0, 0
F0027534: 12800008                 bne     locret_F0027554
F0027538: a01421dc                 bset    %lo(dword_F0133DDC), %l0
F002753C: d0043ffc                 ld      [%l0-4], %o0
F0027540: 40000589                 call    _vn_rele
F0027544: d002215c                 ld      [%o0+0x15C], %o0
F0027548: d2043ffc                 ld      [%l0-4], %o1
F002754C: d007bff4                 ld      [%fp+var_C], %o0
F0027550: d022615c                 st      %o0, [%o1+0x15C]
F0027554: 81c7e008                 ret
F0027558: 81e80000                 restore
