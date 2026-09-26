F0073A38: 9de3bf98                 save    %sp, -0x68, %sp
F0073A3C: 80a62000                 cmp     %i0, 0
F0073A40: 12800004                 bne     loc_F0073A50
F0073A44: a0102000                 mov     0, %l0
F0073A48: 10800032                 ba      locret_F0073B10
F0073A4C: b0102004                 mov     4, %i0
F0073A50: d0060000                 ld      [%i0], %o0
F0073A54: 80a22000                 cmp     %o0, 0
F0073A58: 12bffffe                 bne     loc_F0073A50
F0073A5C: 01000000                 nop
F0073A60: 40008d12                 call    _simple_lock_try
F0073A64: 90100018                 mov     %i0, %o0
F0073A68: 80a22000                 cmp     %o0, 0
F0073A6C: 02bffff9                 be      loc_F0073A50
F0073A70: 01000000                 nop
F0073A74: d0062044                 ld      [%i0+0x44], %o0
F0073A78: 90022001                 inc     %o0
F0073A7C: 80a22001                 cmp     %o0, 1
F0073A80: 12800003                 bne     loc_F0073A8C
F0073A84: d0262044                 st      %o0, [%i0+0x44]
F0073A88: a0102001                 mov     1, %l0
F0073A8C: c0260000                 clr     [%i0]
F0073A90: 80a42000                 cmp     %l0, 0
F0073A94: 2280001f                 be,a    locret_F0073B10
F0073A98: b0102000                 mov     0, %i0
F0073A9C: 7ffffeba                 call    _task_hold
F0073AA0: 90100018                 mov     %i0, %o0
F0073AA4: 80a22000                 cmp     %o0, 0
F0073AA8: 3280001a                 bne,a   locret_F0073B10
F0073AAC: b0102005                 mov     5, %i0
F0073AB0: 90100018                 mov     %i0, %o0
F0073AB4: 7ffffeda                 call    _task_dowait
F0073AB8: 92102000                 mov     0, %o1
F0073ABC: 80a22000                 cmp     %o0, 0
F0073AC0: 02800004                 be      loc_F0073AD0
F0073AC4: 113c04d0                 sethi   -0xFECC000, %o0
F0073AC8: 10800012                 ba      locret_F0073B10
F0073ACC: b0102005                 mov     5, %i0
F0073AD0: d2022260                 ld      [%o0+0x260], %o1
F0073AD4: d002600c                 ld      [%o1+0xC], %o0
F0073AD8: 80a20018                 cmp     %o0, %i0
F0073ADC: 1280000d                 bne     locret_F0073B10
F0073AE0: b0102000                 mov     0, %i0
F0073AE4: 400005de                 call    _thread_hold
F0073AE8: 90100009                 mov     %o1, %o0
F0073AEC: 40008c27                 call    _splusclock
F0073AF0: 01000000                 nop
F0073AF4: 133c04cf                 sethi   %hi(_need_ast), %o1
F0073AF8: d4026160                 ld      [%o1+%lo(_need_ast)], %o2
F0073AFC: 9412a004                 bset    4, %o2
F0073B00: d4226160                 st      %o2, [%o1+%lo(_need_ast)]
F0073B04: d2026160                 ld      [%o1+%lo(_need_ast)], %o1
F0073B08: 40008c87                 call    _splx
F0073B0C: b0102000                 mov     0, %i0
F0073B10: 81c7e008                 ret
F0073B14: 81e80000                 restore
