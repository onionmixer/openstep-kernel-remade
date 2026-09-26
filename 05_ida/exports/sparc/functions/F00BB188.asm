F00BB188: 9de3bf98                 save    %sp, -0x68, %sp
F00BB18C: c4066004                 ld      [%i1+4], %g2
F00BB190: c4260000                 st      %g2, [%i0]
F00BB194: c4066008                 ld      [%i1+8], %g2
F00BB198: c4262004                 st      %g2, [%i0+4]
F00BB19C: c406600c                 ld      [%i1+0xC], %g2
F00BB1A0: c4262008                 st      %g2, [%i0+8]
F00BB1A4: 053c02ec8410a068         set     _zslevel6intr, %g2
F00BB1AC: c426200c                 st      %g2, [%i0+0xC]
F00BB1B0: f226201c                 st      %i1, [%i0+0x1C]
F00BB1B4: 81c7e008                 ret
F00BB1B8: 81e80000                 restore
