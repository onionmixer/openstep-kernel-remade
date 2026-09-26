F0073DE0: 9de3bf98                 save    %sp, -0x68, %sp
F0073DE4: 80a62000                 cmp     %i0, 0
F0073DE8: 12800004                 bne     loc_F0073DF8
F0073DEC: a0102000                 mov     0, %l0
F0073DF0: 10800024                 ba      locret_F0073E80
F0073DF4: b0102004                 mov     4, %i0
F0073DF8: d0060000                 ld      [%i0], %o0
F0073DFC: 80a22000                 cmp     %o0, 0
F0073E00: 12bffffe                 bne     loc_F0073DF8
F0073E04: 01000000                 nop
F0073E08: 40008c28                 call    _simple_lock_try
F0073E0C: 90100018                 mov     %i0, %o0
F0073E10: 80a22000                 cmp     %o0, 0
F0073E14: 02bffff9                 be      loc_F0073DF8
F0073E18: 01000000                 nop
F0073E1C: d0062044                 ld      [%i0+0x44], %o0
F0073E20: 90022001                 inc     %o0
F0073E24: 80a22001                 cmp     %o0, 1
F0073E28: 12800003                 bne     loc_F0073E34
F0073E2C: d0262044                 st      %o0, [%i0+0x44]
F0073E30: a0102001                 mov     1, %l0
F0073E34: c0260000                 clr     [%i0]
F0073E38: 80a42000                 cmp     %l0, 0
F0073E3C: 22800011                 be,a    locret_F0073E80
F0073E40: b0102000                 mov     0, %i0
F0073E44: 7ffffdd0                 call    _task_hold
F0073E48: 90100018                 mov     %i0, %o0
F0073E4C: 80a22000                 cmp     %o0, 0
F0073E50: 02800004                 be      loc_F0073E60
F0073E54: 113c04d0                 sethi   -0xFECC000, %o0
F0073E58: 1080000a                 ba      locret_F0073E80
F0073E5C: b0102005                 mov     5, %i0
F0073E60: d2022260                 ld      [%o0+0x260], %o1
F0073E64: d002600c                 ld      [%o1+0xC], %o0
F0073E68: 80a20018                 cmp     %o0, %i0
F0073E6C: 12800005                 bne     locret_F0073E80
F0073E70: b0102000                 mov     0, %i0
F0073E74: 400004fa                 call    _thread_hold
F0073E78: 90100009                 mov     %o1, %o0
F0073E7C: b0102000                 mov     0, %i0
F0073E80: 81c7e008                 ret
F0073E84: 81e80000                 restore
