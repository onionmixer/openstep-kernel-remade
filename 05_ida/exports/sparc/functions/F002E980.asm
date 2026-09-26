F002E980: 9de3bf98                 save    %sp, -0x68, %sp
F002E984: f0060000                 ld      [%i0], %i0
F002E988: 07380000                 sethi   -0x20000000, %g3
F002E98C: 840e0003                 and     %i0, %g3, %g2
F002E990: 80a08003                 cmp     %g2, %g3
F002E994: 02800009                 be      loc_F002E9B8
F002E998: 80a62000                 cmp     %i0, 0
F002E99C: 06800009                 bl      loc_F002E9C0
F002E9A0: 053fc000                 sethi   -0x1000000, %g2
F002E9A4: 848e0002                 andcc   %i0, %g2, %g2
F002E9A8: 02800004                 be      loc_F002E9B8
F002E9AC: 80a0a07f                 cmp     %g2, 0x7F
F002E9B0: 12800005                 bne     locret_F002E9C4
F002E9B4: b0102001                 mov     1, %i0
F002E9B8: 10800003                 ba      locret_F002E9C4
F002E9BC: b0102000                 mov     0, %i0
F002E9C0: b0102001                 mov     1, %i0
F002E9C4: 81c7e008                 ret
F002E9C8: 81e80000                 restore
