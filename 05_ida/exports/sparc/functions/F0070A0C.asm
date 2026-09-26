F0070A0C: 9de3bf98                 save    %sp, -0x68, %sp
F0070A10: 40008f46                 call    _kdp_intr_disbl
F0070A14: 01000000                 nop
F0070A18: 80a6e000                 cmp     %i3, 0
F0070A1C: 12800005                 bne     loc_F0070A30
F0070A20: a2100008                 mov     %o0, %l1
F0070A24: 113c0440                 sethi   %hi(aKdpRaiseExcept), %o0! "kdp_raise_exception with NULL state\n"
F0070A28: 7ffff574                 call    _safe_prf
F0070A2C: 90122348                 bset    %lo(aKdpRaiseExcept), %o0! "kdp_raise_exception with NULL state\n"
F0070A30: 80a62006                 cmp     %i0, 6
F0070A34: 02800012                 be      loc_F0070A7C
F0070A38: 94100018                 mov     %i0, %o2
F0070A3C: 80a62006                 cmp     %i0, 6
F0070A40: 18800004                 bgu     loc_F0070A50
F0070A44: 80a62000                 cmp     %i0, 0
F0070A48: 12800004                 bne     loc_F0070A58
F0070A4C: 113c0440                 sethi   -0xFEF0000, %o0
F0070A50: 94102000                 mov     0, %o2
F0070A54: 113c0440                 sethi   -0xFEF0000, %o0
F0070A58: 90122370                 bset    0x370, %o0
F0070A5C: 133c0440921261a8         set     unk_F01101A8, %o1
F0070A64: 952aa002                 sll     %o2, 2, %o2
F0070A68: d2028009                 ld      [%o2+%o1], %o1
F0070A6C: 96100019                 mov     %i1, %o3
F0070A70: 9810001a                 mov     %i2, %o4
F0070A74: 7ffff561                 call    _safe_prf
F0070A78: 94100018                 mov     %i0, %o2
F0070A7C: 40008f4f                 call    _kdp_flush_cache
F0070A80: 01000000                 nop
F0070A84: 113c04f1a0122000         set     _kdp, %l0
F0070A8C: 113c04bf                 sethi   %hi(dword_F012FF24), %o0
F0070A90: d0022324                 ld      [%o0+%lo(dword_F012FF24)], %o0
F0070A94: 80a22000                 cmp     %o0, 0
F0070A98: 02800005                 be      loc_F0070AAC
F0070A9C: f624200c                 st      %i3, [%l0+0xC]
F0070AA0: 113c0440                 sethi   %hi(aKdpRaiseExcept_0), %o0! "kdp_raise_exception"
F0070AA4: 40008f0d                 call    _kdp_panic
F0070AA8: 90122390                 bset    %lo(aKdpRaiseExcept_0), %o0! "kdp_raise_exception"
F0070AAC: d0042008                 ld      [%l0+8], %o0
F0070AB0: 80a22000                 cmp     %o0, 0
F0070AB4: 12800006                 bne     loc_F0070ACC
F0070AB8: 90100018                 mov     %i0, %o0
F0070ABC: 7fffff55                 call    sub_F0070810
F0070AC0: 313c04f1                 sethi   %hi(dword_F013C408), %i0
F0070AC4: 10800007                 ba      loc_F0070AE0
F0070AC8: d0062008                 ld      [%i0+%lo(dword_F013C408)], %o0
F0070ACC: 92100019                 mov     %i1, %o1
F0070AD0: 7fffff9d                 call    sub_F0070944
F0070AD4: 9410001a                 mov     %i2, %o2
F0070AD8: 313c04f1                 sethi   %hi(dword_F013C408), %i0
F0070ADC: d0062008                 ld      [%i0+%lo(dword_F013C408)], %o0
F0070AE0: 80a22000                 cmp     %o0, 0
F0070AE4: 0280000c                 be      loc_F0070B14
F0070AE8: 92162008                 or      %i0, 8, %o1
F0070AEC: 90102001                 mov     1, %o0
F0070AF0: d0226008                 st      %o0, [%o1+8]
F0070AF4: 7fffff02                 call    sub_F00706FC
F0070AF8: 9010001b                 mov     %i3, %o0
F0070AFC: d0062008                 ld      [%i0+8], %o0
F0070B00: 80a22000                 cmp     %o0, 0
F0070B04: 12800004                 bne     loc_F0070B14
F0070B08: 113c0440                 sethi   %hi(aRemoteDebugger), %o0! "Remote debugger disconnected.\n"
F0070B0C: 7ffff53b                 call    _safe_prf
F0070B10: 901223a8                 bset    %lo(aRemoteDebugger), %o0! "Remote debugger disconnected.\n"
F0070B14: 40008f29                 call    _kdp_flush_cache
F0070B18: 01000000                 nop
F0070B1C: 40008f0a                 call    _kdp_intr_enbl
F0070B20: 90100011                 mov     %l1, %o0
F0070B24: 81c7e008                 ret
F0070B28: 81e80000                 restore
