F0098DB0: 9de3bf68                 save    %sp, -0x98, %sp
F0098DB4: 113c04d0                 sethi   %hi(_active_threads), %o0
F0098DB8: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F0098DBC: d0022028                 ld      [%o0+0x28], %o0
F0098DC0: e4022284                 ld      [%o0+0x284], %l2
F0098DC4: d004a08c                 ld      [%l2+0x8C], %o0
F0098DC8: 80a22000                 cmp     %o0, 0
F0098DCC: 0280001e                 be      loc_F0098E44
F0098DD0: a004a090                 add     %l2, 0x90, %l0
F0098DD4: a807bfc8                 add     %fp, var_38, %l4
F0098DD8: a604a080                 add     %l2, 0x80, %l3
F0098DDC: 2b3c044a                 sethi   -0xFEED800, %l5
F0098DE0: d2040000                 ld      [%l0], %o1
F0098DE4: 90100014                 mov     %l4, %o0
F0098DE8: d6042004                 ld      [%l0+4], %o3
F0098DEC: 40004edf                 call    _fpu_simulator
F0098DF0: 94100013                 mov     %l3, %o2
F0098DF4: a2920000                 orcc    %o0, %g0, %l1
F0098DF8: 0280000d                 be      loc_F0098E2C
F0098DFC: d00560c8                 ld      [%l5+0xC8], %o0
F0098E00: 80a22000                 cmp     %o0, 0
F0098E04: 02800005                 be      loc_F0098E18
F0098E08: 90100014                 mov     %l4, %o0
F0098E0C: 7ffff1bd                 call    __fp_write_pfsr
F0098E10: 90100013                 mov     %l3, %o0
F0098E14: 90100014                 mov     %l4, %o0
F0098E18: 92100011                 mov     %l1, %o1
F0098E1C: 7fffff83                 call    _fp_traps
F0098E20: 94100018                 mov     %i0, %o2
F0098E24: 10800009                 ba      loc_F0098E48
F0098E28: 113c044a                 sethi   -0xFEED800, %o0
F0098E2C: d004a08c                 ld      [%l2+0x8C], %o0
F0098E30: a0042008                 inc     8, %l0
F0098E34: 90023fff                 inc     -1, %o0
F0098E38: 80a22000                 cmp     %o0, 0
F0098E3C: 12bfffe9                 bne     loc_F0098DE0
F0098E40: d024a08c                 st      %o0, [%l2+0x8C]
F0098E44: 113c044a                 sethi   -0xFEED800, %o0
F0098E48: d00220c8                 ld      [%o0+0xC8], %o0
F0098E4C: 80a22000                 cmp     %o0, 0
F0098E50: 0280000c                 be      locret_F0098E80
F0098E54: b0102000                 mov     0, %i0
F0098E58: a0100012                 mov     %l2, %l0
F0098E5C: 90100010                 mov     %l0, %o0
F0098E60: 7ffff11e                 call    __fp_read_pfreg
F0098E64: 92100018                 mov     %i0, %o1
F0098E68: b0062001                 inc     %i0
F0098E6C: 80a6201f                 cmp     %i0, 0x1F
F0098E70: 08bffffb                 bleu    loc_F0098E5C
F0098E74: a0042004                 inc     4, %l0
F0098E78: 7ffff1a2                 call    __fp_write_pfsr
F0098E7C: 9004a080                 add     %l2, 0x80, %o0
F0098E80: 81c7e008                 ret
F0098E84: 81e80000                 restore
