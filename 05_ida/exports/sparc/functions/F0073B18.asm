F0073B18: 9de3bf98                 save    %sp, -0x68, %sp
F0073B1C: 80a62000                 cmp     %i0, 0
F0073B20: 12800004                 bne     loc_F0073B30
F0073B24: a0102000                 mov     0, %l0
F0073B28: 1080001f                 ba      locret_F0073BA4
F0073B2C: b0102004                 mov     4, %i0
F0073B30: d0060000                 ld      [%i0], %o0
F0073B34: 80a22000                 cmp     %o0, 0
F0073B38: 12bffffe                 bne     loc_F0073B30
F0073B3C: 01000000                 nop
F0073B40: 40008cda                 call    _simple_lock_try
F0073B44: 90100018                 mov     %i0, %o0
F0073B48: 80a22000                 cmp     %o0, 0
F0073B4C: 02bffff9                 be      loc_F0073B30
F0073B50: 01000000                 nop
F0073B54: d0062044                 ld      [%i0+0x44], %o0
F0073B58: 80a22000                 cmp     %o0, 0
F0073B5C: 14800005                 bg      loc_F0073B70
F0073B60: 90023fff                 inc     -1, %o0
F0073B64: c0260000                 clr     [%i0]
F0073B68: 1080000f                 ba      locret_F0073BA4
F0073B6C: b0102005                 mov     5, %i0
F0073B70: 80a22000                 cmp     %o0, 0
F0073B74: 12800003                 bne     loc_F0073B80
F0073B78: d0262044                 st      %o0, [%i0+0x44]
F0073B7C: a0102001                 mov     1, %l0
F0073B80: c0260000                 clr     [%i0]
F0073B84: 80a42000                 cmp     %l0, 0
F0073B88: 12800004                 bne     loc_F0073B98
F0073B8C: 01000000                 nop
F0073B90: 10800005                 ba      locret_F0073BA4
F0073B94: b0102000                 mov     0, %i0
F0073B98: 7ffffee0                 call    _task_release
F0073B9C: 90100018                 mov     %i0, %o0
F0073BA0: b0100008                 mov     %o0, %i0
F0073BA4: 81c7e008                 ret
F0073BA8: 81e80000                 restore
