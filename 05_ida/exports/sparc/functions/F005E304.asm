F005E304: 9de3bf98                 save    %sp, -0x68, %sp
F005E308: c6062004                 ld      [%i0+4], %g3
F005E30C: 80a0e000                 cmp     %g3, 0
F005E310: 02800005                 be      loc_F005E324
F005E314: 80a00003                 cmp     %g0, %g3
F005E318: c400e010                 ld      [%g3+0x10], %g2
F005E31C: c4264000                 st      %g2, [%i1]
F005E320: c6268000                 st      %g3, [%i2]
F005E324: b0402000                 addc    %g0, 0, %i0
F005E328: 81c7e008                 ret
F005E32C: 81e80000                 restore
