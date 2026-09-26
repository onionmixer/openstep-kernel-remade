F008A238: 9de3bf98                 save    %sp, -0x68, %sp
F008A23C: 80a62000                 cmp     %i0, 0
F008A240: 02800007                 be      loc_F008A25C
F008A244: 84103fff                 mov     -1, %g2
F008A248: f006203c                 ld      [%i0+0x3C], %i0
F008A24C: 80a62000                 cmp     %i0, 0
F008A250: 32800006                 bne,a   loc_F008A268
F008A254: c4562030                 ldsh    [%i0+0x30], %g2
F008A258: 84103fff                 mov     -1, %g2
F008A25C: c4264000                 st      %g2, [%i1]
F008A260: 10800004                 ba      locret_F008A270
F008A264: b0102005                 mov     5, %i0
F008A268: b0102000                 mov     0, %i0
F008A26C: c4264000                 st      %g2, [%i1]
F008A270: 81c7e008                 ret
F008A274: 81e80000                 restore
