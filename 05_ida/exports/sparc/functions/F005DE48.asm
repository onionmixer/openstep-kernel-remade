F005DE48: 9de3bf98                 save    %sp, -0x68, %sp
F005DE4C: d0060000                 ld      [%i0], %o0
F005DE50: 80a22000                 cmp     %o0, 0
F005DE54: 12bffffe                 bne     loc_F005DE4C
F005DE58: 01000000                 nop
F005DE5C: 4000e413                 call    _simple_lock_try
F005DE60: 90100018                 mov     %i0, %o0
F005DE64: 80a22000                 cmp     %o0, 0
F005DE68: 02bffff9                 be      loc_F005DE4C
F005DE6C: 01000000                 nop
F005DE70: d0062004                 ld      [%i0+4], %o0
F005DE74: c0260000                 clr     [%i0]
F005DE78: 90023fff                 inc     -1, %o0
F005DE7C: 80a22000                 cmp     %o0, 0
F005DE80: 12800006                 bne     locret_F005DE98
F005DE84: d0262004                 st      %o0, [%i0+4]
F005DE88: 113c04ef                 sethi   %hi(_ipc_space_zone), %o0
F005DE8C: d0022340                 ld      [%o0+%lo(_ipc_space_zone)], %o0
F005DE90: 40006cd0                 call    _zfree
F005DE94: 92100018                 mov     %i0, %o1
F005DE98: 81c7e008                 ret
F005DE9C: 81e80000                 restore
