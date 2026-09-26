F00459FC: 9de3bf90                 save    %sp, -0x70, %sp
F0045A00: d0060000                 ld      [%i0], %o0
F0045A04: 80a22000                 cmp     %o0, 0
F0045A08: 0280000a                 be      loc_F0045A30
F0045A0C: e0064000                 ld      [%i1], %l0
F0045A10: 80a22002                 cmp     %o0, 2
F0045A14: 3280000b                 bne,a   loc_F0045A40
F0045A18: 90100018                 mov     %i0, %o0! __s
F0045A1C: 80a42000                 cmp     %l0, 0
F0045A20: 12800004                 bne     loc_F0045A30
F0045A24: 01000000                 nop
F0045A28: 10800034                 ba      locret_F0045AF8
F0045A2C: b0102001                 mov     1, %i0
F0045A30: 7fff0682                 call    _strlen
F0045A34: 90100010                 mov     %l0, %o0
F0045A38: d027bff4                 st      %o0, [%fp+var_C]
F0045A3C: 90100018                 mov     %i0, %o0! XDR *
F0045A40: 7ffffe8b                 call    _xdr_u_int
F0045A44: 9207bff4                 add     %fp, var_C, %o1
F0045A48: 80a22000                 cmp     %o0, 0
F0045A4C: 32800005                 bne,a   loc_F0045A60
F0045A50: d007bff4                 ld      [%fp+var_C], %o0
F0045A54: 113c0438                 sethi   %hi(aXdrStringSizeF), %o0! "xdr_string: size FAILED\n"
F0045A58: 10800026                 ba      loc_F0045AF0
F0045A5C: 90122018                 bset    %lo(aXdrStringSizeF), %o0! "xdr_string: size FAILED\n"
F0045A60: 80a2001a                 cmp     %o0, %i2
F0045A64: 28800005                 bleu,a  loc_F0045A78
F0045A68: d4060000                 ld      [%i0], %o2
F0045A6C: 113c0438                 sethi   %hi(aXdrStringBadSi), %o0! "xdr_string: bad size FAILED\n"
F0045A70: 10800020                 ba      loc_F0045AF0
F0045A74: 90122038                 bset    %lo(aXdrStringBadSi), %o0! "xdr_string: bad size FAILED\n"
F0045A78: 80a2a001                 cmp     %o2, 1
F0045A7C: 02800008                 be      loc_F0045A9C
F0045A80: 92022001                 add     %o0, 1, %o1! char *
F0045A84: 80a2a001                 cmp     %o2, 1
F0045A88: 0a80000e                 bcs     loc_F0045AC0
F0045A8C: 80a2a002                 cmp     %o2, 2
F0045A90: 02800012                 be      loc_F0045AD8
F0045A94: 113c0438                 sethi   -0xFEF2000, %o0
F0045A98: 30800015                 ba,a    loc_F0045AEC
F0045A9C: 80a42000                 cmp     %l0, 0
F0045AA0: 12800007                 bne     loc_F0045ABC
F0045AA4: d007bff4                 ld      [%fp+var_C], %o0
F0045AA8: 40008972                 call    _kalloc
F0045AAC: 90100009                 mov     %o1, %o0
F0045AB0: a0100008                 mov     %o0, %l0
F0045AB4: e0264000                 st      %l0, [%i1]
F0045AB8: d007bff4                 ld      [%fp+var_C], %o0
F0045ABC: c02c0008                 clrb    [%l0+%o0]
F0045AC0: 90100018                 mov     %i0, %o0! XDR *
F0045AC4: d407bff4                 ld      [%fp+var_C], %o2! unsigned int
F0045AC8: 7fffff26                 call    _xdr_opaque
F0045ACC: 92100010                 mov     %l0, %o1
F0045AD0: 1080000a                 ba      locret_F0045AF8
F0045AD4: b0100008                 mov     %o0, %i0
F0045AD8: 400089b2                 call    _kfree
F0045ADC: 90100010                 mov     %l0, %o0
F0045AE0: c0264000                 clr     [%i1]
F0045AE4: 10800005                 ba      locret_F0045AF8
F0045AE8: b0102001                 mov     1, %i0
F0045AEC: 90122058                 bset    0x58, %o0 ! 'X'! char *
F0045AF0: 7fff3ada                 call    _printf
F0045AF4: b0102000                 mov     0, %i0
F0045AF8: 81c7e008                 ret
F0045AFC: 81e80000                 restore
