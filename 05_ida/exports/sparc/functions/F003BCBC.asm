F003BCBC: 9de3bf98                 save    %sp, -0x68, %sp
F003BCC0: 073c0432                 sethi   %hi(_rfsfreesp), %g3
F003BCC4: c400e1f0                 ld      [%g3+%lo(_rfsfreesp)], %g2
F003BCC8: c4260000                 st      %g2, [%i0]
F003BCCC: f020e1f0                 st      %i0, [%g3+%lo(_rfsfreesp)]
F003BCD0: 81c7e008                 ret
F003BCD4: 81e80000                 restore
