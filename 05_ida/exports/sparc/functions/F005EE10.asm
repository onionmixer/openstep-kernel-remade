F005EE10: 9de3bf98                 save    %sp, -0x68, %sp
F005EE14: c6066090                 ld      [%i1+0x90], %g3
F005EE18: 80a0c019                 cmp     %g3, %i1
F005EE1C: 12800004                 bne     loc_F005EE2C
F005EE20: f4066094                 ld      [%i1+0x94], %i2
F005EE24: 1080000a                 ba      locret_F005EE4C
F005EE28: c0260000                 clr     [%i0]
F005EE2C: c4060000                 ld      [%i0], %g2
F005EE30: 80a08019                 cmp     %g2, %i1
F005EE34: 22800002                 be,a    loc_F005EE3C
F005EE38: c6260000                 st      %g3, [%i0]
F005EE3C: f420e094                 st      %i2, [%g3+0x94]
F005EE40: c626a090                 st      %g3, [%i2+0x90]
F005EE44: f2266090                 st      %i1, [%i1+0x90]
F005EE48: f2266094                 st      %i1, [%i1+0x94]
F005EE4C: 81c7e008                 ret
F005EE50: 81e80000                 restore
