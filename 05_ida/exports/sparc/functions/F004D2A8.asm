F004D2A8: 9de3bf98                 save    %sp, -0x68, %sp
F004D2AC: d206a038                 ld      [%i2+0x38], %o1
F004D2B0: d6066008                 ld      [%i1+8], %o3
F004D2B4: 80a2400b                 cmp     %o1, %o3
F004D2B8: 0480000c                 ble     loc_F004D2E8
F004D2BC: 01000000                 nop
F004D2C0: d4064000                 ld      [%i1], %o2
F004D2C4: d002a038                 ld      [%o2+0x38], %o0
F004D2C8: 80a24008                 cmp     %o1, %o0
F004D2CC: 06800004                 bl      loc_F004D2DC
F004D2D0: 80a2000b                 cmp     %o0, %o3
F004D2D4: 16800005                 bge     loc_F004D2E8
F004D2D8: 01000000                 nop
F004D2DC: d426a00c                 st      %o2, [%i2+0xC]
F004D2E0: 10800011                 ba      locret_F004D324
F004D2E4: f4264000                 st      %i2, [%i1]
F004D2E8: 7fffffb4                 call    sub_F004D1B8
F004D2EC: 90100019                 mov     %i1, %o0
F004D2F0: 92920000                 orcc    %o0, %g0, %o1
F004D2F4: 32800006                 bne,a   loc_F004D30C
F004D2F8: d002600c                 ld      [%o1+0xC], %o0
F004D2FC: d0064000                 ld      [%i1], %o0
F004D300: d026a00c                 st      %o0, [%i2+0xC]
F004D304: 10800008                 ba      locret_F004D324
F004D308: f4264000                 st      %i2, [%i1]
F004D30C: d026a00c                 st      %o0, [%i2+0xC]
F004D310: f422600c                 st      %i2, [%o1+0xC]
F004D314: d0066004                 ld      [%i1+4], %o0
F004D318: 80a20009                 cmp     %o0, %o1
F004D31C: 22800002                 be,a    locret_F004D324
F004D320: f4266004                 st      %i2, [%i1+4]
F004D324: 81c7e008                 ret
F004D328: 81e80000                 restore
