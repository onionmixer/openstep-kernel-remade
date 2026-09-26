F00A4B04: 9de3bf98                 save    %sp, -0x68, %sp
F00A4B08: 92100018                 mov     %i0, %o1
F00A4B0C: 80a26003                 cmp     %o1, 3
F00A4B10: 12800005                 bne     loc_F00A4B24
F00A4B14: 90100019                 mov     %i1, %o0
F00A4B18: 7fffc393                 call    _vac_pagectxflush
F00A4B1C: 9210001a                 mov     %i2, %o1
F00A4B20: 30800013                 ba,a    locret_F00A4B6C
F00A4B24: 80a26002                 cmp     %o1, 2
F00A4B28: 12800005                 bne     loc_F00A4B3C
F00A4B2C: 80a26001                 cmp     %o1, 1
F00A4B30: 7fffc36e                 call    _vac_segflush
F00A4B34: 9210001a                 mov     %i2, %o1
F00A4B38: 3080000d                 ba,a    locret_F00A4B6C
F00A4B3C: 12800005                 bne     loc_F00A4B50
F00A4B40: 80a26000                 cmp     %o1, 0
F00A4B44: 7fffc358                 call    _vac_rgnflush
F00A4B48: 9210001a                 mov     %i2, %o1
F00A4B4C: 30800008                 ba,a    locret_F00A4B6C
F00A4B50: 12800005                 bne     loc_F00A4B64
F00A4B54: 113c0466                 sethi   -0xFEE6800, %o0
F00A4B58: 7fffc33b                 call    _vac_ctxflush
F00A4B5C: 9010001a                 mov     %i2, %o0! char *
F00A4B60: 30800003                 ba,a    locret_F00A4B6C
F00A4B64: 7ffdc183                 call    _panic
F00A4B68: 90122018                 bset    0x18, %o0
F00A4B6C: 81c7e008                 ret
F00A4B70: 81e80000                 restore
