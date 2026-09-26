F0097CDC: 9de3bf98                 save    %sp, -0x68, %sp
F0097CE0: 86100018                 mov     %i0, %g3
F0097CE4: b0102000                 mov     0, %i0
F0097CE8: 80a6001a                 cmp     %i0, %i2
F0097CEC: 3a80000c                 bcc,a   locret_F0097D1C
F0097CF0: b010001a                 mov     %i2, %i0
F0097CF4: c448c000                 ldsb    [%g3], %g2
F0097CF8: 80a0a000                 cmp     %g2, 0
F0097CFC: 02800008                 be      locret_F0097D1C
F0097D00: 8600e001                 inc     %g3
F0097D04: c42e4000                 stb     %g2, [%i1]
F0097D08: b0062001                 inc     %i0
F0097D0C: 80a6001a                 cmp     %i0, %i2
F0097D10: 0abffff9                 bcs     loc_F0097CF4
F0097D14: b2066001                 inc     %i1
F0097D18: b010001a                 mov     %i2, %i0
F0097D1C: 81c7e008                 ret
F0097D20: 81e80000                 restore
