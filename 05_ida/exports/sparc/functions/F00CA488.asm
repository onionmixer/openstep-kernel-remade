F00CA488: 9de3bf90                 save    %sp, -0x70, %sp
F00CA48C: b2102000                 mov     0, %i1
F00CA490: 86102128                 mov     0x128, %g3
F00CA494: c0260003                 clr     [%i0+%g3]
F00CA498: 84060003                 add     %i0, %g3, %g2
F00CA49C: c020a004                 clr     [%g2+4]
F00CA4A0: c028a008                 clrb    [%g2+8]
F00CA4A4: b2066001                 inc     %i1
F00CA4A8: 80a66003                 cmp     %i1, 3
F00CA4AC: 08bffffa                 bleu    loc_F00CA494
F00CA4B0: 8600e05c                 inc     0x5C, %g3 ! '\'
F00CA4B4: 81c7e008                 ret
F00CA4B8: 81e80000                 restore
