F002BC18: 9de3bf98                 save    %sp, -0x68, %sp
F002BC1C: 90100018                 mov     %i0, %o0
F002BC20: 92100019                 mov     %i1, %o1
F002BC24: d6022038                 ld      [%o0+0x38], %o3
F002BC28: 80a2e000                 cmp     %o3, 0
F002BC2C: 02800006                 be      loc_F002BC44
F002BC30: 9410001a                 mov     %i2, %o2
F002BC34: 9fc2c000                 call    %o3
F002BC38: 01000000                 nop
F002BC3C: 10800003                 ba      locret_F002BC48
F002BC40: b0100008                 mov     %o0, %i0
F002BC44: b0102006                 mov     6, %i0
F002BC48: 81c7e008                 ret
F002BC4C: 81e80000                 restore
