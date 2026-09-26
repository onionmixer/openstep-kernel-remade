F0068D08: 9de3bf98                 save    %sp, -0x68, %sp
F0068D0C: 90100018                 mov     %i0, %o0! void *
F0068D10: 4000b052                 call    _bzero
F0068D14: 9210200c                 mov     0xC, %o1
F0068D18: c0262008                 clr     [%i0+8]
F0068D1C: 13000010                 sethi   0x4000, %o1
F0068D20: b20e6001                 and     %i1, 1, %i1
F0068D24: d0062004                 ld      [%i0+4], %o0
F0068D28: b32e600c                 sll     %i1, 12, %i1
F0068D2C: 922a0009                 andn    %o0, %o1, %o1
F0068D30: 11000020                 sethi   0x8000, %o0
F0068D34: 902a4008                 andn    %o1, %o0, %o0
F0068D38: d0262004                 st      %o0, [%i0+4]
F0068D3C: c0362004                 clrh    [%i0+4]
F0068D40: d2062004                 ld      [%i0+4], %o1
F0068D44: 11000004                 sethi   0x1000, %o0
F0068D48: 902a4008                 andn    %o1, %o0, %o0
F0068D4C: 90120019                 bset    %i1, %o0
F0068D50: d0262004                 st      %o0, [%i0+4]
F0068D54: 92103fff                 mov     -1, %o1
F0068D58: d0062004                 ld      [%i0+4], %o0
F0068D5C: d2260000                 st      %o1, [%i0]
F0068D60: 900a3000                 and     %o0, -0x1000, %o0
F0068D64: d0262004                 st      %o0, [%i0+4]
F0068D68: 81c7e008                 ret
F0068D6C: 81e80000                 restore
