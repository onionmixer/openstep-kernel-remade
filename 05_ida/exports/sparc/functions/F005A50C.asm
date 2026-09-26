F005A50C: 9de3bf98                 save    %sp, -0x68, %sp
F005A510: f806202c                 ld      [%i0+0x2C], %i4
F005A514: 80a72000                 cmp     %i4, 0
F005A518: 2280000f                 be,a    locret_F005A554
F005A51C: b0102003                 mov     3, %i0
F005A520: fa070000                 ld      [%i4], %i5
F005A524: 80a76000                 cmp     %i5, 0
F005A528: 0280000a                 be      loc_F005A550
F005A52C: 852f6003                 sll     %i5, 3, %g2
F005A530: c6070002                 ld      [%i4+%g2], %g3
F005A534: b0102000                 mov     0, %i0
F005A538: c6270000                 st      %g3, [%i4]
F005A53C: 86070002                 add     %i4, %g2, %g3
F005A540: f220e004                 st      %i1, [%g3+4]
F005A544: f4270002                 st      %i2, [%i4+%g2]
F005A548: 10800003                 ba      locret_F005A554
F005A54C: fa26c000                 st      %i5, [%i3]
F005A550: b0102003                 mov     3, %i0
F005A554: 81c7e008                 ret
F005A558: 81e80000                 restore
