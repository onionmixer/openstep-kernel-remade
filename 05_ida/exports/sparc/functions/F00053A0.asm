F00053A0: 9de3bf98                 save    %sp, -0x68, %sp
F00053A4: 80a6a000                 cmp     %i2, 0
F00053A8: 0280000f                 be      locret_F00053E4
F00053AC: 84102020                 mov     0x20, %g2 ! ' '
F00053B0: 8420801a                 sub     %g2, %i2, %g2
F00053B4: 80a0a000                 cmp     %g2, 0
F00053B8: 14800006                 bg      loc_F00053D0
F00053BC: b936001a                 srl     %i0, %i2, %i4
F00053C0: b8102000                 mov     0, %i4
F00053C4: 84200002                 neg     %g2
F00053C8: 10800005                 ba      loc_F00053DC
F00053CC: bb360002                 srl     %i0, %g2, %i5
F00053D0: 872e0002                 sll     %i0, %g2, %g3
F00053D4: 8536401a                 srl     %i1, %i2, %g2
F00053D8: ba108003                 or      %g2, %g3, %i5
F00053DC: b010001c                 mov     %i4, %i0
F00053E0: b210001d                 mov     %i5, %i1
F00053E4: 81c7e008                 ret
F00053E8: 81e80000                 restore
