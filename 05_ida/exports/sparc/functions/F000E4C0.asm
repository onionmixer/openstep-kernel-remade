F000E4C0: 9de3bf98                 save    %sp, -0x68, %sp
F000E4C4: b2100018                 mov     %i0, %i1
F000E4C8: 860e603f                 and     %i1, 0x3F, %g3
F000E4CC: 053c04d38410a170         set     _pidhash, %g2
F000E4D4: 8728e002                 sll     %g3, 2, %g3
F000E4D8: f000c002                 ld      [%g3+%g2], %i0
F000E4DC: 80a62000                 cmp     %i0, 0
F000E4E0: 2280000b                 be,a    locret_F000E50C
F000E4E4: b0102000                 mov     0, %i0
F000E4E8: c4562030                 ldsh    [%i0+0x30], %g2
F000E4EC: 80a08019                 cmp     %g2, %i1
F000E4F0: 02800007                 be      locret_F000E50C
F000E4F4: 01000000                 nop
F000E4F8: f0062040                 ld      [%i0+0x40], %i0
F000E4FC: 80a62000                 cmp     %i0, 0
F000E500: 32bffffb                 bne,a   loc_F000E4EC
F000E504: c4562030                 ldsh    [%i0+0x30], %g2
F000E508: b0102000                 mov     0, %i0
F000E50C: 81c7e008                 ret
F000E510: 81e80000                 restore
