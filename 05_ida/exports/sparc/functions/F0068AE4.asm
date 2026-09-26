F0068AE4: 9de3bf98                 save    %sp, -0x68, %sp
F0068AE8: 113c04f0                 sethi   %hi(_stack_queue_lock), %o0
F0068AEC: 400000b6                 call    _lock_write
F0068AF0: 901220e0                 bset    %lo(_stack_queue_lock), %o0
F0068AF4: 113c043e                 sethi   %hi(dword_F010FB00), %o0
F0068AF8: d0022300                 ld      [%o0+%lo(dword_F010FB00)], %o0
F0068AFC: 80a22000                 cmp     %o0, 0
F0068B00: 0280001d                 be      loc_F0068B74
F0068B04: 153c04bd                 sethi   %hi(dword_F012F670), %o2
F0068B08: d202a270                 ld      [%o2+%lo(dword_F012F670)], %o1
F0068B0C: 9612a270                 or      %o2, %lo(dword_F012F670), %o3
F0068B10: 80a2400b                 cmp     %o1, %o3
F0068B14: 32800004                 bne,a   loc_F0068B24
F0068B18: d0024000                 ld      [%o1], %o0
F0068B1C: 10800006                 ba      loc_F0068B34
F0068B20: a0102000                 mov     0, %l0
F0068B24: d6222004                 st      %o3, [%o0+4]
F0068B28: d0024000                 ld      [%o1], %o0
F0068B2C: a0100009                 mov     %o1, %l0
F0068B30: d022a270                 st      %o0, [%o2+0x270]
F0068B34: 90102002                 mov     2, %o0
F0068B38: d0242008                 st      %o0, [%l0+8]
F0068B3C: 173c043e                 sethi   %hi(dword_F010FB00), %o3
F0068B40: a004200c                 inc     0xC, %l0
F0068B44: 153c04f0                 sethi   %hi(_stackStats), %o2
F0068B48: d002e300                 ld      [%o3+%lo(dword_F010FB00)], %o0
F0068B4C: 9412a0c0                 bset    %lo(_stackStats), %o2
F0068B50: d202a008                 ld      [%o2+8], %o1
F0068B54: 90023fff                 inc     -1, %o0
F0068B58: d022e300                 st      %o0, [%o3+%lo(dword_F010FB00)]
F0068B5C: 92027fff                 inc     -1, %o1
F0068B60: d002a004                 ld      [%o2+4], %o0
F0068B64: d222a008                 st      %o1, [%o2+8]
F0068B68: 90022001                 inc     %o0
F0068B6C: 10800003                 ba      loc_F0068B78
F0068B70: d022a004                 st      %o0, [%o2+4]
F0068B74: a0102000                 mov     0, %l0
F0068B78: 113c04f0                 sethi   %hi(_stack_queue_lock), %o0
F0068B7C: 4000012e                 call    _lock_done
F0068B80: 901220e0                 bset    %lo(_stack_queue_lock), %o0
F0068B84: 92940000                 orcc    %l0, %g0, %o1
F0068B88: 22800002                 be,a    loc_F0068B90
F0068B8C: d2062030                 ld      [%i0+0x30], %o1
F0068B90: 80a26000                 cmp     %o1, 0
F0068B94: 12800004                 bne     loc_F0068BA4
F0068B98: 90100018                 mov     %i0, %o0
F0068B9C: 10800005                 ba      locret_F0068BB0
F0068BA0: b0102000                 mov     0, %i0
F0068BA4: 4000ccac                 call    _stack_attach
F0068BA8: 94100019                 mov     %i1, %o2
F0068BAC: b0102001                 mov     1, %i0
F0068BB0: 81c7e008                 ret
F0068BB4: 81e80000                 restore
