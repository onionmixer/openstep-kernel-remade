F00B2C3C: 9de3bf98                 save    %sp, -0x68, %sp
F00B2C40: 113c0477                 sethi   %hi(_dev_path_opstab), %o0! __s1
F00B2C44: 80a62000                 cmp     %i0, 0
F00B2C48: 0280000f                 be      loc_F00B2C84
F00B2C4C: a01223bc                 or      %o0, %lo(_dev_path_opstab), %l0
F00B2C50: d2040000                 ld      [%l0], %o1! __s2
F00B2C54: 80a26000                 cmp     %o1, 0
F00B2C58: 2280000c                 be,a    locret_F00B2C88
F00B2C5C: b0102000                 mov     0, %i0
F00B2C60: 7ffd5553                 call    _strcmp
F00B2C64: d006200c                 ld      [%i0+0xC], %o0
F00B2C68: 80a22000                 cmp     %o0, 0
F00B2C6C: 12800004                 bne     loc_F00B2C7C
F00B2C70: 80a62000                 cmp     %i0, 0
F00B2C74: 10800005                 ba      locret_F00B2C88
F00B2C78: f0042004                 ld      [%l0+4], %i0
F00B2C7C: 12bffff5                 bne     loc_F00B2C50
F00B2C80: a0042010                 inc     0x10, %l0
F00B2C84: b0102000                 mov     0, %i0
F00B2C88: 81c7e008                 ret
F00B2C8C: 81e80000                 restore
