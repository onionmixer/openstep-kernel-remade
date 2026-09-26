F000E9A8: 9de3bf98                 save    %sp, -0x68, %sp
F000E9AC: d0062044                 ld      [%i0+0x44], %o0
F000E9B0: e0066008                 ld      [%i1+8], %l0
F000E9B4: 4000005b                 call    _get_posix_proc
F000E9B8: d0522030                 ldsh    [%o0+0x30], %o0
F000E9BC: d2022010                 ld      [%o0+0x10], %o1
F000E9C0: 80a24019                 cmp     %o1, %i1
F000E9C4: 22800013                 be,a    loc_F000EA10
F000E9C8: f0062048                 ld      [%i0+0x48], %i0
F000E9CC: d0026008                 ld      [%o1+8], %o0
F000E9D0: 80a20010                 cmp     %o0, %l0
F000E9D4: 3280000f                 bne,a   loc_F000EA10
F000E9D8: f0062048                 ld      [%i0+0x48], %i0
F000E9DC: 80a6a000                 cmp     %i2, 0
F000E9E0: 02800005                 be      loc_F000E9F4
F000E9E4: d0066010                 ld      [%i1+0x10], %o0
F000E9E8: 90022001                 inc     %o0
F000E9EC: 10800008                 ba      loc_F000EA0C
F000E9F0: d0266010                 st      %o0, [%i1+0x10]
F000E9F4: 90023fff                 inc     -1, %o0
F000E9F8: 80a22000                 cmp     %o0, 0
F000E9FC: 12800004                 bne     loc_F000EA0C
F000EA00: d0266010                 st      %o0, [%i1+0x10]
F000EA04: 40000026                 call    sub_F000EA9C
F000EA08: 90100019                 mov     %i1, %o0
F000EA0C: f0062048                 ld      [%i0+0x48], %i0
F000EA10: 80a62000                 cmp     %i0, 0
F000EA14: 02800020                 be      locret_F000EA94
F000EA18: 01000000                 nop
F000EA1C: 40000041                 call    _get_posix_proc
F000EA20: d0562030                 ldsh    [%i0+0x30], %o0
F000EA24: d2022010                 ld      [%o0+0x10], %o1
F000EA28: 80a24019                 cmp     %o1, %i1
F000EA2C: 22800017                 be,a    loc_F000EA88
F000EA30: f006204c                 ld      [%i0+0x4C], %i0
F000EA34: d0026008                 ld      [%o1+8], %o0
F000EA38: 80a20010                 cmp     %o0, %l0
F000EA3C: 32800013                 bne,a   loc_F000EA88
F000EA40: f006204c                 ld      [%i0+0x4C], %i0
F000EA44: d04e2013                 ldsb    [%i0+0x13], %o0
F000EA48: 80a22005                 cmp     %o0, 5
F000EA4C: 2280000f                 be,a    loc_F000EA88
F000EA50: f006204c                 ld      [%i0+0x4C], %i0
F000EA54: 80a6a000                 cmp     %i2, 0
F000EA58: 02800005                 be      loc_F000EA6C
F000EA5C: d0026010                 ld      [%o1+0x10], %o0
F000EA60: 90022001                 inc     %o0
F000EA64: 10800008                 ba      loc_F000EA84
F000EA68: d0226010                 st      %o0, [%o1+0x10]
F000EA6C: 90023fff                 inc     -1, %o0
F000EA70: 80a22000                 cmp     %o0, 0
F000EA74: 12800004                 bne     loc_F000EA84
F000EA78: d0226010                 st      %o0, [%o1+0x10]
F000EA7C: 40000008                 call    sub_F000EA9C
F000EA80: 90100009                 mov     %o1, %o0
F000EA84: f006204c                 ld      [%i0+0x4C], %i0
F000EA88: 80a62000                 cmp     %i0, 0
F000EA8C: 12bfffe4                 bne     loc_F000EA1C
F000EA90: 01000000                 nop
F000EA94: 81c7e008                 ret
F000EA98: 81e80000                 restore
