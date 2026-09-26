F000E514: 9de3bf98                 save    %sp, -0x68, %sp
F000E518: 073c04d3                 sethi   %hi(_pidhash), %g3
F000E51C: c4162030                 lduh    [%i0+0x30], %g2
F000E520: 8610e170                 bset    %lo(_pidhash), %g3
F000E524: 8408a03f                 and     %g2, 0x3F, %g2
F000E528: 8528a002                 sll     %g2, 2, %g2
F000E52C: f2008003                 ld      [%g2+%g3], %i1
F000E530: f2262040                 st      %i1, [%i0+0x40]
F000E534: f0208003                 st      %i0, [%g2+%g3]
F000E538: 81c7e008                 ret
F000E53C: 81e80000                 restore
