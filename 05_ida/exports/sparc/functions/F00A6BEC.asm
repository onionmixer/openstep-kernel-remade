F00A6BEC: 9de3bf98                 save    %sp, -0x68, %sp
F00A6BF0: 113c0464                 sethi   %hi(_use_pe), %o0
F00A6BF4: d00222ec                 ld      [%o0+%lo(_use_pe)], %o0
F00A6BF8: 80a22000                 cmp     %o0, 0
F00A6BFC: 02800004                 be      loc_F00A6C0C
F00A6C00: 113c046b                 sethi   -0xFEE5400, %o0! char *
F00A6C04: 7fffc21c                 call    _p4m35_memerr_init_asm
F00A6C08: 9e03e008                 inc     8, %o7
F00A6C0C: 7ffdb693                 call    _printf
F00A6C10: 901222a8                 bset    0x2A8, %o0
F00A6C14: 81c7e008                 ret
F00A6C18: 81e80000                 restore
