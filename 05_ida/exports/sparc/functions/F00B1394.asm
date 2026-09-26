F00B1394: 9de3bf78                 save    %sp, -0x88, %sp
F00B1398: a2102000                 mov     0, %l1
F00B139C: a007bfd8                 add     %fp, var_28, %l0
F00B13A0: 90100010                 mov     %l0, %o0
F00B13A4: 7ffff75b                 call    _prom_getidprom
F00B13A8: 92102020                 mov     0x20, %o1 ! ' '
F00B13AC: 9210200f                 mov     0xF, %o1
F00B13B0: d00c0000                 ldub    [%l0], %o0
F00B13B4: 92827fff                 inccc   -1, %o1
F00B13B8: a21c4008                 btog    %o0, %l1
F00B13BC: 1cbffffd                 bpos    loc_F00B13B0
F00B13C0: a0042001                 inc     %l0
F00B13C4: 920c60ff                 and     %l1, 0xFF, %o1
F00B13C8: 80a26000                 cmp     %o1, 0
F00B13CC: 22800006                 be,a    loc_F00B13E4
F00B13D0: d20fbfd8                 ldub    [%fp+var_28], %o1
F00B13D4: 113c0471                 sethi   %hi(aWarningNvramCh), %o0! "Warning: NVRAM checksum error [%x]\n"
F00B13D8: 7ffd8ca0                 call    _printf
F00B13DC: 901222b8                 bset    %lo(aWarningNvramCh), %o0! "Warning: NVRAM checksum error [%x]\n"
F00B13E0: d20fbfd8                 ldub    [%fp+var_28], %o1
F00B13E4: 80a26001                 cmp     %o1, 1
F00B13E8: 12800006                 bne     loc_F00B1400
F00B13EC: 113c0471                 sethi   -0xFEE3C00, %o0
F00B13F0: 9007bfda                 add     %fp, var_26, %o0! char *
F00B13F4: 7ffdf441                 call    _localetheraddr
F00B13F8: 92102000                 mov     0, %o1
F00B13FC: 30800003                 ba,a    locret_F00B1408
F00B1400: 7ffd8c96                 call    _printf
F00B1404: 901222e0                 bset    0x2E0, %o0
F00B1408: 81c7e008                 ret
F00B140C: 81e80000                 restore
