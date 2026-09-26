F00BCD38: 9de3bf98                 save    %sp, -0x68, %sp
F00BCD3C: 113c04c8a0122070         set     dword_F0132070, %l0
F00BCD44: d0040000                 ld      [%l0], %o0
F00BCD48: 80a22000                 cmp     %o0, 0
F00BCD4C: 12bffffe                 bne     loc_F00BCD44
F00BCD50: 01000000                 nop
F00BCD54: 7fff6855                 call    _simple_lock_try
F00BCD58: 90100010                 mov     %l0, %o0
F00BCD5C: 80a22000                 cmp     %o0, 0
F00BCD60: 02bffff9                 be      loc_F00BCD44
F00BCD64: 153c047f                 sethi   %hi(dword_F011FEBC), %o2
F00BCD68: d202a2bc                 ld      [%o2+%lo(dword_F011FEBC)], %o1
F00BCD6C: 80a26000                 cmp     %o1, 0
F00BCD70: 04800009                 ble     loc_F00BCD94
F00BCD74: 113c04fd                 sethi   %hi(_prettyp), %o0
F00BCD78: 92200009                 neg     %o1
F00BCD7C: d222a2bc                 st      %o1, [%o2+%lo(dword_F011FEBC)]
F00BCD80: d0022250                 ld      [%o0+%lo(_prettyp)], %o0
F00BCD84: 133c047f                 sethi   %hi(unk_F011FE4C), %o1
F00BCD88: d4022010                 ld      [%o0+0x10], %o2
F00BCD8C: 9fc28000                 call    %o2
F00BCD90: 9212624c                 bset    %lo(unk_F011FE4C), %o1
F00BCD94: 113c04c8                 sethi   %hi(dword_F0132070), %o0
F00BCD98: c0222070                 clr     [%o0+%lo(dword_F0132070)]
F00BCD9C: 81c7e008                 ret
F00BCDA0: 81e80000                 restore
