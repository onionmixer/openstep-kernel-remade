F00461EC: 9de3bf98                 save    %sp, -0x68, %sp
F00461F0: a0100018                 mov     %i0, %l0
F00461F4: d0042014                 ld      [%l0+0x14], %o0
F00461F8: 92100019                 mov     %i1, %o1! void *
F00461FC: 9022001a                 sub     %o0, %i2, %o0
F0046200: 80a22000                 cmp     %o0, 0
F0046204: 0680000a                 bl      loc_F004622C
F0046208: d0242014                 st      %o0, [%l0+0x14]
F004620C: d004200c                 ld      [%l0+0xC], %o0! void *
F0046210: 40013a40                 call    _bcopy
F0046214: 9410001a                 mov     %i2, %o2
F0046218: d004200c                 ld      [%l0+0xC], %o0
F004621C: b0102001                 mov     1, %i0
F0046220: 9002001a                 add     %o0, %i2, %o0
F0046224: 10800003                 ba      locret_F0046230
F0046228: d024200c                 st      %o0, [%l0+0xC]
F004622C: b0102000                 mov     0, %i0
F0046230: 81c7e008                 ret
F0046234: 81e80000                 restore
