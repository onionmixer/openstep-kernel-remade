F0097AB4: 9de3bf98                 save    %sp, -0x68, %sp
F0097AB8: 7ffffc34                 call    _splusclock
F0097ABC: 01000000                 nop
F0097AC0: 133fbfe4                 sethi   -0x1007000, %o1
F0097AC4: 150000109412a004         set     0x4004, %o2
F0097ACC: c402400a                 ld      [%o1+%o2], %g2
F0097AD0: 86100008                 mov     %o0, %g3
F0097AD4: 133c04c5                 sethi   %hi(qword_F0131478), %o1
F0097AD8: 80a0a000                 cmp     %g2, 0
F0097ADC: 1680000b                 bge     loc_F0097B08
F0097AE0: d81a6078                 ldd     [%o1+%lo(qword_F0131478)], %o4
F0097AE4: 90102000                 mov     0, %o0
F0097AE8: 1300000992126310         set     0x2710, %o1
F0097AF0: 9a834009                 addcc   %o5, %o1, %o5
F0097AF4: 98430008                 addc    %o4, %o0, %o4
F0097AF8: 94102000                 mov     0, %o2
F0097AFC: 96102001                 mov     1, %o3
F0097B00: 10800006                 ba      loc_F0097B18
F0097B04: 133c04c5                 sethi   -0xFECEC00, %o1
F0097B08: 9130a00a                 srl     %g2, 10, %o0
F0097B0C: 96100008                 mov     %o0, %o3
F0097B10: 94102000                 mov     0, %o2
F0097B14: 133c04c5                 sethi   -0xFECEC00, %o1
F0097B18: d0026080                 ld      [%o1+0x80], %o0
F0097B1C: 9683400b                 addcc   %o5, %o3, %o3
F0097B20: 9443000a                 addc    %o4, %o2, %o2
F0097B24: 80a2000a                 cmp     %o0, %o2
F0097B28: 12800008                 bne     loc_F0097B48
F0097B2C: 92126080                 bset    0x80, %o1
F0097B30: d0026004                 ld      [%o1+4], %o0
F0097B34: 80a2000b                 cmp     %o0, %o3
F0097B38: 32800005                 bne,a   loc_F0097B4C
F0097B3C: 113c04c5                 sethi   -0xFECEC00, %o0
F0097B40: 9682e001                 inccc   %o3
F0097B44: 9442a000                 addc    %o2, 0, %o2
F0097B48: 113c04c5                 sethi   -0xFECEC00, %o0
F0097B4C: d43a2080                 std     %o2, [%o0+0x80]
F0097B50: d43e0000                 std     %o2, [%i0]
F0097B54: 7ffffc74                 call    _splx
F0097B58: 90100003                 mov     %g3, %o0
F0097B5C: 81c7e008                 ret
F0097B60: 81e80000                 restore
