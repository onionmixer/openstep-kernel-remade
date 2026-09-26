F0054DCC: 9de3bf98                 save    %sp, -0x68, %sp
F0054DD0: c6064000                 ld      [%i1], %g3
F0054DD4: 80a0c019                 cmp     %g3, %i1
F0054DD8: 12800004                 bne     loc_F0054DE8
F0054DDC: f4066004                 ld      [%i1+4], %i2
F0054DE0: 10800008                 ba      locret_F0054E00
F0054DE4: c0260000                 clr     [%i0]
F0054DE8: c4060000                 ld      [%i0], %g2
F0054DEC: 80a08019                 cmp     %g2, %i1
F0054DF0: 22800002                 be,a    loc_F0054DF8
F0054DF4: c6260000                 st      %g3, [%i0]
F0054DF8: f420e004                 st      %i2, [%g3+4]
F0054DFC: c6268000                 st      %g3, [%i2]
F0054E00: 81c7e008                 ret
F0054E04: 81e80000                 restore
