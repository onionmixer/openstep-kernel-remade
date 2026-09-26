F00B2EF0: 9de3be98                 save    %sp, -0x168, %sp
F00B2EF4: 113c04fb                 sethi   %hi(_top_devinfo), %o0
F00B2EF8: 80a62000                 cmp     %i0, 0
F00B2EFC: 12800008                 bne     loc_F00B2F1C
F00B2F00: e0022088                 ld      [%o0+%lo(_top_devinfo)], %l0
F00B2F04: 10800048                 ba      locret_F00B3024
F00B2F08: b0102000                 mov     0, %i0
F00B2F0C: 80a2602f                 cmp     %o1, 0x2F ! '/'
F00B2F10: 12800008                 bne     loc_F00B2F30
F00B2F14: 253c0477                 sethi   -0xFEE2400, %l2
F00B2F18: b0062001                 inc     %i0
F00B2F1C: d04e0000                 ldsb    [%i0], %o0
F00B2F20: 80a22000                 cmp     %o0, 0
F00B2F24: 12bffffa                 bne     loc_F00B2F0C
F00B2F28: d20e0000                 ldub    [%i0], %o1
F00B2F2C: 253c0477                 sethi   -0xFEE2400, %l2
F00B2F30: d004a1a0                 ld      [%l2+0x1A0], %o0
F00B2F34: 80a22000                 cmp     %o0, 0
F00B2F38: 02800005                 be      loc_F00B2F4C
F00B2F3C: 113c0477                 sethi   %hi(aPathS), %o0! "path: '%s'\n"
F00B2F40: 90122220                 bset    %lo(aPathS), %o0! "path: '%s'\n"
F00B2F44: 7ffd85c5                 call    _printf
F00B2F48: 92100018                 mov     %i0, %o1
F00B2F4C: d04e0000                 ldsb    [%i0], %o0
F00B2F50: 80a22000                 cmp     %o0, 0
F00B2F54: 22800034                 be,a    locret_F00B3024
F00B2F58: b0100010                 mov     %l0, %i0
F00B2F5C: a207bf78                 add     %fp, var_88, %l1
F00B2F60: 90100018                 mov     %i0, %o0
F00B2F64: 7fffff7d                 call    sub_F00B2D58
F00B2F68: 92100011                 mov     %l1, %o1
F00B2F6C: d204a1a0                 ld      [%l2+0x1A0], %o1
F00B2F70: 80a26000                 cmp     %o1, 0
F00B2F74: 02800007                 be      loc_F00B2F90
F00B2F78: b0100008                 mov     %o0, %i0
F00B2F7C: 113c047790122230         set     aNameSRemainder, %o0! "name: '%s' remainder: '%s'\n"
F00B2F84: 92100011                 mov     %l1, %o1
F00B2F88: 7ffd85b4                 call    _printf
F00B2F8C: 94100018                 mov     %i0, %o2
F00B2F90: d04e0000                 ldsb    [%i0], %o0
F00B2F94: 80a22040                 cmp     %o0, 0x40 ! '@'
F00B2F98: 32800006                 bne,a   loc_F00B2FB0
F00B2F9C: c02fbef8                 clrb    [%fp+var_108]
F00B2FA0: 90062001                 add     %i0, 1, %o0
F00B2FA4: 7fffff6d                 call    sub_F00B2D58
F00B2FA8: 9207bef8                 add     %fp, var_108, %o1
F00B2FAC: b0100008                 mov     %o0, %i0
F00B2FB0: d004a1a0                 ld      [%l2+0x1A0], %o0
F00B2FB4: 80a22000                 cmp     %o0, 0
F00B2FB8: 02800006                 be      loc_F00B2FD0
F00B2FBC: 113c0477                 sethi   %hi(aAddrspecSRemai), %o0! "addrspec: '%s' remainder: '%s'\n"
F00B2FC0: 90122250                 bset    %lo(aAddrspecSRemai), %o0! "addrspec: '%s' remainder: '%s'\n"
F00B2FC4: 9207bef8                 add     %fp, var_108, %o1
F00B2FC8: 7ffd85a4                 call    _printf
F00B2FCC: 94100018                 mov     %i0, %o2
F00B2FD0: 9007bf78                 add     %fp, var_88, %o0
F00B2FD4: 9207bef8                 add     %fp, var_108, %o1
F00B2FD8: 7fffffaf                 call    sub_F00B2E94
F00B2FDC: 94100010                 mov     %l0, %o2
F00B2FE0: a0920000                 orcc    %o0, %g0, %l0
F00B2FE4: 22800010                 be,a    locret_F00B3024
F00B2FE8: b0100010                 mov     %l0, %i0
F00B2FEC: 10800006                 ba      loc_F00B3004
F00B2FF0: d04e0000                 ldsb    [%i0], %o0
F00B2FF4: 80a2602f                 cmp     %o1, 0x2F ! '/'
F00B2FF8: 02800006                 be      loc_F00B3010
F00B2FFC: b0062001                 inc     %i0
F00B3000: d04e0000                 ldsb    [%i0], %o0
F00B3004: 80a22000                 cmp     %o0, 0
F00B3008: 12bffffb                 bne     loc_F00B2FF4
F00B300C: d20e0000                 ldub    [%i0], %o1
F00B3010: d04e0000                 ldsb    [%i0], %o0
F00B3014: 80a22000                 cmp     %o0, 0
F00B3018: 12bfffd3                 bne     loc_F00B2F64
F00B301C: 90100018                 mov     %i0, %o0
F00B3020: b0100010                 mov     %l0, %i0
F00B3024: 81c7e008                 ret
F00B3028: 81e80000                 restore
