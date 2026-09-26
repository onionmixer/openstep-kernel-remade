F00B2D04: 9de3bf98                 save    %sp, -0x68, %sp
F00B2D08: 113c0477                 sethi   %hi(_dev_path_opstab), %o0! __s1
F00B2D0C: 80a62000                 cmp     %i0, 0
F00B2D10: 0280000f                 be      loc_F00B2D4C
F00B2D14: a01223bc                 or      %o0, %lo(_dev_path_opstab), %l0
F00B2D18: d2040000                 ld      [%l0], %o1! __s2
F00B2D1C: 80a26000                 cmp     %o1, 0
F00B2D20: 2280000c                 be,a    locret_F00B2D50
F00B2D24: b0102000                 mov     0, %i0
F00B2D28: 7ffd5521                 call    _strcmp
F00B2D2C: d006200c                 ld      [%i0+0xC], %o0
F00B2D30: 80a22000                 cmp     %o0, 0
F00B2D34: 12800004                 bne     loc_F00B2D44
F00B2D38: 80a62000                 cmp     %i0, 0
F00B2D3C: 10800005                 ba      locret_F00B2D50
F00B2D40: f004200c                 ld      [%l0+0xC], %i0
F00B2D44: 12bffff5                 bne     loc_F00B2D18
F00B2D48: a0042010                 inc     0x10, %l0
F00B2D4C: b0102000                 mov     0, %i0
F00B2D50: 81c7e008                 ret
F00B2D54: 81e80000                 restore
