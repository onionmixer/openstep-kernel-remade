F003C07C: 9de3bf98                 save    %sp, -0x68, %sp
F003C080: c6160000                 lduh    [%i0], %g3
F003C084: c4164000                 lduh    [%i1], %g2
F003C088: 80a0c002                 cmp     %g3, %g2
F003C08C: 3280000a                 bne,a   locret_F003C0B4
F003C090: b0102000                 mov     0, %i0
F003C094: 80a0e002                 cmp     %g3, 2
F003C098: 32800007                 bne,a   locret_F003C0B4
F003C09C: b0102000                 mov     0, %i0
F003C0A0: c4062004                 ld      [%i0+4], %g2
F003C0A4: c6066004                 ld      [%i1+4], %g3
F003C0A8: 84188003                 btog    %g3, %g2
F003C0AC: 80a00002                 cmp     %g0, %g2
F003C0B0: b0603fff                 subc    %g0, -1, %i0
F003C0B4: 81c7e008                 ret
F003C0B8: 81e80000                 restore
