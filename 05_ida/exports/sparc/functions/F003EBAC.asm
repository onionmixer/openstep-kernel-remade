F003EBAC: 9de3bf78                 save    %sp, -0x88, %sp
F003EBB0: a2100018                 mov     %i0, %l1
F003EBB4: e0046128                 ld      [%l1+0x128], %l0
F003EBB8: 92102011                 mov     0x11, %o1
F003EBBC: d0042010                 ld      [%l0+0x10], %o0
F003EBC0: 153c0105                 sethi   %hi(_xdr_fhandle), %o2
F003EBC4: d6022030                 ld      [%o0+0x30], %o3
F003EBC8: 9412a29c                 bset    %lo(_xdr_fhandle), %o2
F003EBCC: 113c04cf                 sethi   %hi(_active_u), %o0
F003EBD0: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F003EBD4: 9a07bfe0                 add     %fp, var_20, %o5
F003EBD8: d802201c                 ld      [%o0+0x1C], %o4
F003EBDC: 9602e040                 inc     0x40, %o3 ! '@'
F003EBE0: 90100010                 mov     %l0, %o0
F003EBE4: d823a05c                 st      %o4, [%sp+0x88+var_2C]
F003EBE8: 193c0109                 sethi   %hi(_xdr_statfs), %o4
F003EBEC: 7ffff6e2                 call    _rfscall
F003EBF0: 981320b0                 bset    %lo(_xdr_statfs), %o4
F003EBF4: b0920000                 orcc    %o0, %g0, %i0
F003EBF8: 22800002                 be,a    loc_F003EC00
F003EBFC: f007bfe0                 ld      [%fp+var_20], %i0
F003EC00: 80a62000                 cmp     %i0, 0
F003EC04: 1280001b                 bne     locret_F003EC70
F003EC08: 01000000                 nop
F003EC0C: d2042020                 ld      [%l0+0x20], %o1
F003EC10: 80a26000                 cmp     %o1, 0
F003EC14: 02800007                 be      loc_F003EC30
F003EC18: d007bfe4                 ld      [%fp+var_1C], %o0
F003EC1C: 80a24008                 cmp     %o1, %o0
F003EC20: 2a800004                 bcs,a   loc_F003EC30
F003EC24: 90100009                 mov     %o1, %o0
F003EC28: 10800003                 ba      loc_F003EC34
F003EC2C: d0242020                 st      %o0, [%l0+0x20]
F003EC30: d0242020                 st      %o0, [%l0+0x20]
F003EC34: d007bfe8                 ld      [%fp+var_18], %o0
F003EC38: d0266004                 st      %o0, [%i1+4]
F003EC3C: d207bfec                 ld      [%fp+var_14], %o1
F003EC40: 90046014                 add     %l1, 0x14, %o0! void *
F003EC44: d2266008                 st      %o1, [%i1+8]
F003EC48: d407bff0                 ld      [%fp+var_10], %o2
F003EC4C: 9206601c                 add     %i1, 0x1C, %o1! void *
F003EC50: d426600c                 st      %o2, [%i1+0xC]
F003EC54: d607bff4                 ld      [%fp+var_C], %o3
F003EC58: 94102008                 mov     8, %o2! size_t
F003EC5C: d6266010                 st      %o3, [%i1+0x10]
F003EC60: 96103fff                 mov     -1, %o3
F003EC64: d6266014                 st      %o3, [%i1+0x14]
F003EC68: 400157aa                 call    _bcopy
F003EC6C: d6266018                 st      %o3, [%i1+0x18]
F003EC70: 81c7e008                 ret
F003EC74: 81e80000                 restore
