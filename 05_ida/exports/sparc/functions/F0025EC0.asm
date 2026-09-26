F0025EC0: 9de3bf98                 save    %sp, -0x68, %sp
F0025EC4: a0100018                 mov     %i0, %l0
F0025EC8: b72ee003                 sll     %i3, 3, %i3
F0025ECC: 113c04d4901223d0         set     _nc_hash, %o0
F0025ED4: f006c008                 ld      [%i3+%o0], %i0
F0025ED8: b606c008                 add     %i3, %o0, %i3
F0025EDC: 80a6001b                 cmp     %i0, %i3
F0025EE0: 22800033                 be,a    locret_F0025FAC
F0025EE4: b0102000                 mov     0, %i0
F0025EE8: d0062014                 ld      [%i0+0x14], %o0
F0025EEC: 80a20010                 cmp     %o0, %l0
F0025EF0: 3280002b                 bne,a   loc_F0025F9C
F0025EF4: f0060000                 ld      [%i0], %i0
F0025EF8: d04e2018                 ldsb    [%i0+0x18], %o0
F0025EFC: 80a2001a                 cmp     %o0, %i2
F0025F00: 32800027                 bne,a   loc_F0025F9C
F0025F04: f0060000                 ld      [%i0], %i0
F0025F08: d24e2019                 ldsb    [%i0+0x19], %o1
F0025F0C: d04e4000                 ldsb    [%i1], %o0
F0025F10: 80a24008                 cmp     %o1, %o0
F0025F14: 32800022                 bne,a   loc_F0025F9C
F0025F18: f0060000                 ld      [%i0], %i0
F0025F1C: 90062019                 add     %i0, 0x19, %o0! void *
F0025F20: 92100019                 mov     %i1, %o1! void *
F0025F24: 7fff800e                 call    _bcmp
F0025F28: 9410001a                 mov     %i2, %o2
F0025F2C: 80a22000                 cmp     %o0, 0
F0025F30: 3280001b                 bne,a   loc_F0025F9C
F0025F34: f0060000                 ld      [%i0], %i0
F0025F38: 80a73fff                 cmp     %i4, -1
F0025F3C: 0280001c                 be      locret_F0025FAC
F0025F40: 01000000                 nop
F0025F44: d406203c                 ld      [%i0+0x3C], %o2! size_t
F0025F48: 80a2801c                 cmp     %o2, %i4
F0025F4C: 02800018                 be      locret_F0025FAC
F0025F50: 01000000                 nop
F0025F54: d2572002                 ldsh    [%i4+2], %o1
F0025F58: d052a002                 ldsh    [%o2+2], %o0
F0025F5C: 80a24008                 cmp     %o1, %o0
F0025F60: 3280000f                 bne,a   loc_F0025F9C
F0025F64: f0060000                 ld      [%i0], %i0
F0025F68: d2572004                 ldsh    [%i4+4], %o1
F0025F6C: d052a004                 ldsh    [%o2+4], %o0
F0025F70: 80a24008                 cmp     %o1, %o0
F0025F74: 3280000a                 bne,a   loc_F0025F9C
F0025F78: f0060000                 ld      [%i0], %i0
F0025F7C: 9007200a                 add     %i4, 0xA, %o0! void *
F0025F80: 9202a00a                 add     %o2, 0xA, %o1! void *
F0025F84: 7fff7ff6                 call    _bcmp
F0025F88: 94102020                 mov     0x20, %o2 ! ' '
F0025F8C: 80a22000                 cmp     %o0, 0
F0025F90: 02800007                 be      locret_F0025FAC
F0025F94: 01000000                 nop
F0025F98: f0060000                 ld      [%i0], %i0
F0025F9C: 80a6001b                 cmp     %i0, %i3
F0025FA0: 32bfffd3                 bne,a   loc_F0025EEC
F0025FA4: d0062014                 ld      [%i0+0x14], %o0
F0025FA8: b0102000                 mov     0, %i0
F0025FAC: 81c7e008                 ret
F0025FB0: 81e80000                 restore
