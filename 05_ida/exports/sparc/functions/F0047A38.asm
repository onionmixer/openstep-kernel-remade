F0047A38: 9de3bf98                 save    %sp, -0x68, %sp
F0047A3C: 133c04bd                 sethi   %hi(dword_F012F56C), %o1
F0047A40: d002616c                 ld      [%o1+%lo(dword_F012F56C)], %o0
F0047A44: 80a22000                 cmp     %o0, 0
F0047A48: 12800024                 bne     locret_F0047AD8
F0047A4C: 90102001                 mov     1, %o0
F0047A50: d022616c                 st      %o0, [%o1+%lo(dword_F012F56C)]
F0047A54: 113c04eba0122130         set     _stable, %l0
F0047A5C: 90042040                 add     %l0, 0x40, %o0 ! '@'
F0047A60: 80a40008                 cmp     %l0, %o0
F0047A64: 3a80001c                 bcc,a   loc_F0047AD4
F0047A68: 113c04bd                 sethi   -0xFED0C00, %o0
F0047A6C: a2100008                 mov     %o0, %l1
F0047A70: f0040000                 ld      [%l0], %i0
F0047A74: 80a62000                 cmp     %i0, 0
F0047A78: 22800013                 be,a    loc_F0047AC4
F0047A7C: a0042004                 inc     4, %l0
F0047A80: d0162008                 lduh    [%i0+8], %o0
F0047A84: 808a2080                 btst    0x80, %o0
F0047A88: 1280000a                 bne     loc_F0047AB0
F0047A8C: 92062004                 add     %i0, 4, %o1
F0047A90: d006202c                 ld      [%i0+0x2C], %o0
F0047A94: 80a22003                 cmp     %o0, 3
F0047A98: 32800007                 bne,a   loc_F0047AB4
F0047A9C: f0060000                 ld      [%i0], %i0
F0047AA0: 90100009                 mov     %o1, %o0
F0047AA4: 92103fff                 mov     -1, %o1
F0047AA8: 7fff760b                 call    _bflush
F0047AAC: 94103fff                 mov     -1, %o2
F0047AB0: f0060000                 ld      [%i0], %i0
F0047AB4: 80a62000                 cmp     %i0, 0
F0047AB8: 32bffff3                 bne,a   loc_F0047A84
F0047ABC: d0162008                 lduh    [%i0+8], %o0
F0047AC0: a0042004                 inc     4, %l0
F0047AC4: 80a40011                 cmp     %l0, %l1
F0047AC8: 2abfffeb                 bcs,a   loc_F0047A74
F0047ACC: f0040000                 ld      [%l0], %i0
F0047AD0: 113c04bd                 sethi   -0xFED0C00, %o0
F0047AD4: c022216c                 clr     [%o0+0x16C]
F0047AD8: 81c7e008                 ret
F0047ADC: 91e82000                 restore %g0, 0, %o0
