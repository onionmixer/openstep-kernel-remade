F0083AF4: 9de3bf98                 save    %sp, -0x68, %sp! int
F0083AF8: d0062024                 ld      [%i0+0x24], %o0
F0083AFC: 133c04f0                 sethi   %hi(_kernel_pmap), %o1
F0083B00: d2026100                 ld      [%o1+%lo(_kernel_pmap)], %o1! void *
F0083B04: 80a20009                 cmp     %o0, %o1
F0083B08: 12800007                 bne     loc_F0083B24
F0083B0C: 9410001b                 mov     %i3, %o2! int
F0083B10: 90100019                 mov     %i1, %o0! void *
F0083B14: 400043ff                 call    _bcopy
F0083B18: 9210001a                 mov     %i2, %o1! int
F0083B1C: 1080000d                 ba      locret_F0083B50
F0083B20: b0102000                 mov     0, %i0
F0083B24: 113c04d0                 sethi   %hi(_active_threads), %o0
F0083B28: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F0083B2C: d002200c                 ld      [%o0+0xC], %o0
F0083B30: d002200c                 ld      [%o0+0xC], %o0
F0083B34: 80a20018                 cmp     %o0, %i0
F0083B38: 12800006                 bne     locret_F0083B50
F0083B3C: b0102001                 mov     1, %i0
F0083B40: 90100019                 mov     %i1, %o0! int
F0083B44: 40005145                 call    _copyin
F0083B48: 9210001a                 mov     %i2, %o1
F0083B4C: b0100008                 mov     %o0, %i0
F0083B50: 81c7e008                 ret
F0083B54: 81e80000                 restore
