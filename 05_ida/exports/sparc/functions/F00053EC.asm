F00053EC: 9de3bf98                 save    %sp, -0x68, %sp
F00053F0: 80a6a000                 cmp     %i2, 0
F00053F4: 0280000f                 be      locret_F0005430
F00053F8: 84102020                 mov     0x20, %g2 ! ' '
F00053FC: 8420801a                 sub     %g2, %i2, %g2
F0005400: 80a0a000                 cmp     %g2, 0
F0005404: 14800006                 bg      loc_F000541C
F0005408: bb2e401a                 sll     %i1, %i2, %i5
F000540C: ba102000                 mov     0, %i5
F0005410: 84200002                 neg     %g2
F0005414: 10800005                 ba      loc_F0005428
F0005418: b92e4002                 sll     %i1, %g2, %i4
F000541C: 87364002                 srl     %i1, %g2, %g3
F0005420: 852e001a                 sll     %i0, %i2, %g2
F0005424: b8108003                 or      %g2, %g3, %i4
F0005428: b010001c                 mov     %i4, %i0
F000542C: b210001d                 mov     %i5, %i1
F0005430: 81c7e008                 ret
F0005434: 81e80000                 restore
