F00D3FF0: 9de3bf90                 save    %sp, -0x70, %sp
F00D3FF4: 80a6a000                 cmp     %i2, 0
F00D3FF8: 16800004                 bge     loc_F00D4008
F00D3FFC: 80a6a040                 cmp     %i2, 0x40 ! '@'
F00D4000: 10800004                 ba      loc_F00D4010
F00D4004: b4102000                 mov     0, %i2
F00D4008: 34800002                 bg,a    loc_F00D4010
F00D400C: b4102040                 mov     0x40, %i2 ! '@'
F00D4010: d00621cc                 ld      [%i0+0x1CC], %o0
F00D4014: 80a68008                 cmp     %i2, %o0
F00D4018: 0280000b                 be      locret_F00D4044
F00D401C: 01000000                 nop
F00D4020: d04e21d3                 ldsb    [%i0+0x1D3], %o0
F00D4024: 80a22000                 cmp     %o0, 0
F00D4028: 12800007                 bne     locret_F00D4044
F00D402C: f42621cc                 st      %i2, [%i0+0x1CC]
F00D4030: 113c0505                 sethi   %hi(paSetbrightness_0), %o0! id
F00D4034: d20222a8                 ld      [%o0+%lo(paSetbrightness_0)], %o1! SEL
F00D4038: 4000760e                 call    _objc_msgSend
F00D403C: 90100018                 mov     %i0, %o0
F00D4040: b0100008                 mov     %o0, %i0
F00D4044: 81c7e008                 ret
F00D4048: 81e80000                 restore
