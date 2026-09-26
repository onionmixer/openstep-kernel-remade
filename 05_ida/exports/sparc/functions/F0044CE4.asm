F0044CE4: 9de3bf80                 save    %sp, -0x80, %sp
F0044CE8: a207bfe0                 add     %fp, var_20, %l1
F0044CEC: e0062018                 ld      [%i0+0x18], %l0
F0044CF0: 90100011                 mov     %l1, %o0! XDR *
F0044CF4: 92042018                 add     %l0, 0x18, %o1
F0044CF8: d2242004                 st      %o1, [%l0+4]
F0044CFC: 92042118                 add     %l0, 0x118, %o1
F0044D00: d2242014                 st      %o1, [%l0+0x14]
F0044D04: e6066020                 ld      [%i1+0x20], %l3
F0044D08: 96102001                 mov     1, %o3! xdr_op
F0044D0C: d206601c                 ld      [%i1+0x1C], %o1! char *
F0044D10: 400004f4                 call    _xdrmem_create
F0044D14: 94100013                 mov     %l3, %o2
F0044D18: d207bfe4                 ld      [%fp+var_20.x_ops], %o1
F0044D1C: d4026018                 ld      [%o1+0x18], %o2! size_t
F0044D20: 90100011                 mov     %l1, %o0
F0044D24: 9fc28000                 call    %o2
F0044D28: 92100013                 mov     %l3, %o1
F0044D2C: b2920000                 orcc    %o0, %g0, %i1
F0044D30: 02800037                 be      loc_F0044E0C
F0044D34: a4100010                 mov     %l0, %l2
F0044D38: d0064000                 ld      [%i1], %o0
F0044D3C: d0240000                 st      %o0, [%l0]
F0044D40: b2066004                 inc     4, %i1
F0044D44: e2064000                 ld      [%i1], %l1
F0044D48: 80a460ff                 cmp     %l1, 0xFF
F0044D4C: 1480002e                 bg      loc_F0044E04
F0044D50: b2066004                 inc     4, %i1
F0044D54: 90100019                 mov     %i1, %o0! void *
F0044D58: d2042004                 ld      [%l0+4], %o1! void *
F0044D5C: 40013f6d                 call    _bcopy
F0044D60: 94100011                 mov     %l1, %o2
F0044D64: d0042004                 ld      [%l0+4], %o0
F0044D68: 92846003                 addcc   %l1, 3, %o1
F0044D6C: 1c800003                 bpos    loc_F0044D78
F0044D70: c02a0011                 clrb    [%o0+%l1]
F0044D74: 92046006                 add     %l1, 6, %o1
F0044D78: a20a7ffc                 and     %o1, -4, %l1
F0044D7C: b2064011                 add     %i1, %l1, %i1
F0044D80: d0064000                 ld      [%i1], %o0
F0044D84: d0242008                 st      %o0, [%l0+8]
F0044D88: b2066004                 inc     4, %i1
F0044D8C: d0064000                 ld      [%i1], %o0
F0044D90: d024200c                 st      %o0, [%l0+0xC]
F0044D94: b2066004                 inc     4, %i1
F0044D98: d8064000                 ld      [%i1], %o4
F0044D9C: 80a32010                 cmp     %o4, 0x10
F0044DA0: 14800019                 bg      loc_F0044E04
F0044DA4: b2066004                 inc     4, %i1
F0044DA8: 96102000                 mov     0, %o3
F0044DAC: 80a2c00c                 cmp     %o3, %o4
F0044DB0: 1680000a                 bge     loc_F0044DD8
F0044DB4: d8242010                 st      %o4, [%l0+0x10]
F0044DB8: 952ae002                 sll     %o3, 2, %o2
F0044DBC: d204a014                 ld      [%l2+0x14], %o1
F0044DC0: 9602e001                 inc     %o3
F0044DC4: d0064000                 ld      [%i1], %o0
F0044DC8: 80a2c00c                 cmp     %o3, %o4
F0044DCC: d022400a                 st      %o0, [%o1+%o2]
F0044DD0: 06bffffa                 bl      loc_F0044DB8
F0044DD4: b2066004                 inc     4, %i1
F0044DD8: 90032005                 add     %o4, 5, %o0
F0044DDC: 912a2002                 sll     %o0, 2, %o0
F0044DE0: 90020011                 add     %o0, %l1, %o0
F0044DE4: 80a20013                 cmp     %o0, %l3
F0044DE8: 08800016                 bleu    loc_F0044E40
F0044DEC: 9210000c                 mov     %o4, %o1! authunix_parms *
F0044DF0: 113c043790122228         set     aBadAuthLenGidD, %o0! "bad auth_len gid %d str %d auth %d"
F0044DF8: 94100013                 mov     %l3, %o2
F0044DFC: 7fff3e17                 call    _printf
F0044E00: 9610000a                 mov     %o2, %o3
F0044E04: 10800014                 ba      loc_F0044E54
F0044E08: b0102001                 mov     1, %i0
F0044E0C: 90100011                 mov     %l1, %o0! XDR *
F0044E10: 7ffff658                 call    _xdr_authunix_parms
F0044E14: 92100012                 mov     %l2, %o1! authunix_parms *
F0044E18: 80a22000                 cmp     %o0, 0
F0044E1C: 3280000a                 bne,a   loc_F0044E44
F0044E20: d006201c                 ld      [%i0+0x1C], %o0
F0044E24: 90102002                 mov     2, %o0
F0044E28: d027bfe0                 st      %o0, [%fp+var_20.x_op]
F0044E2C: 90100011                 mov     %l1, %o0! XDR *
F0044E30: 7ffff650                 call    _xdr_authunix_parms
F0044E34: 92100012                 mov     %l2, %o1
F0044E38: 10800007                 ba      loc_F0044E54
F0044E3C: b0102001                 mov     1, %i0
F0044E40: d006201c                 ld      [%i0+0x1C], %o0
F0044E44: c0222020                 clr     [%o0+0x20]
F0044E48: d006201c                 ld      [%i0+0x1C], %o0
F0044E4C: b0102000                 mov     0, %i0
F0044E50: c0222028                 clr     [%o0+0x28]
F0044E54: d007bfe4                 ld      [%fp+var_20.x_ops], %o0
F0044E58: d202201c                 ld      [%o0+0x1C], %o1
F0044E5C: 9fc24000                 call    %o1
F0044E60: 9007bfe0                 add     %fp, var_20, %o0
F0044E64: 81c7e008                 ret
F0044E68: 81e80000                 restore
