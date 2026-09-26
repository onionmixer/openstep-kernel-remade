F003F570: 9de3bf78                 save    %sp, -0x88, %sp
F003F574: 90100018                 mov     %i0, %o0! void *
F003F578: 9207bfd8                 add     %fp, var_28, %o1! void *
F003F57C: 40015565                 call    _bcopy
F003F580: 94102020                 mov     0x20, %o2 ! ' '
F003F584: a0102000                 mov     0, %l0
F003F588: 233c0435                 sethi   -0xFEF2C00, %l1
F003F58C: b007bff8                 add     %fp, var_8, %i0
F003F590: 901462d0                 or      %l1, 0x2D0, %o0! char *
F003F594: d2063fe0                 ld      [%i0-0x20], %o1
F003F598: 7fff5430                 call    _printf
F003F59C: a0042001                 inc     %l0
F003F5A0: 80a42007                 cmp     %l0, 7
F003F5A4: 08bffffb                 bleu    loc_F003F590
F003F5A8: b0062004                 inc     4, %i0
F003F5AC: 81c7e008                 ret
F003F5B0: 81e80000                 restore
