F0009D8C: 9de3bf88                 save    %sp, -0x78, %sp
F0009D90: 113c04d0                 sethi   %hi(_active_threads), %o0
F0009D94: e6022260                 ld      [%o0+%lo(_active_threads)], %l3
F0009D98: 400236dc                 call    _clock_value
F0009D9C: 90102001                 mov     1, %o0
F0009DA0: 94102000                 mov     0, %o2
F0009DA4: 961023e8                 mov     0x3E8, %o3
F0009DA8: 253c04d2                 sethi   %hi(_last_hardclock), %l2
F0009DAC: d81ca228                 ldd     [%l2+%lo(_last_hardclock)], %o4
F0009DB0: a0100008                 mov     %o0, %l0
F0009DB4: a2100009                 mov     %o1, %l1
F0009DB8: 9aa4400d                 subcc   %l1, %o5, %o5
F0009DBC: 9864000c                 subc    %l0, %o4, %o4
F0009DC0: 9010000c                 mov     %o4, %o0
F0009DC4: 9210000d                 mov     %o5, %o1
F0009DC8: 7ffff00a                 call    __udivdi3
F0009DCC: 01000000                 nop
F0009DD0: e03ca228                 std     %l0, [%l2+%lo(_last_hardclock)]
F0009DD4: 808e6040                 btst    0x40, %i1 ! '@'
F0009DD8: 12800027                 bne     loc_F0009E74
F0009DDC: a4100009                 mov     %o1, %l2
F0009DE0: 113c04cf                 sethi   %hi(_active_u), %o0
F0009DE4: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F0009DE8: d4020000                 ld      [%o0], %o2
F0009DEC: 80a2a000                 cmp     %o2, 0
F0009DF0: 2280000f                 be,a    loc_F0009E2C
F0009DF4: 213c04cf                 sethi   -0xFECC400, %l0
F0009DF8: d0022258                 ld      [%o0+0x258], %o0
F0009DFC: 80a22000                 cmp     %o0, 0
F0009E00: 0280000a                 be      loc_F0009E28
F0009E04: 13000800                 sethi   0x200000, %o1
F0009E08: d002a028                 ld      [%o2+0x28], %o0
F0009E0C: 90120009                 bset    %o1, %o0
F0009E10: d022a028                 st      %o0, [%o2+0x28]
F0009E14: 133c04cf                 sethi   %hi(_need_ast), %o1
F0009E18: d0026160                 ld      [%o1+%lo(_need_ast)], %o0
F0009E1C: 90122020                 bset    0x20, %o0 ! ' '
F0009E20: d0226160                 st      %o0, [%o1+%lo(_need_ast)]
F0009E24: d0026160                 ld      [%o1+%lo(_need_ast)], %o0
F0009E28: 213c04cf                 sethi   -0xFECC400, %l0
F0009E2C: d20421d8                 ld      [%l0+0x1D8], %o1
F0009E30: d0026214                 ld      [%o1+0x214], %o0
F0009E34: 80a22000                 cmp     %o0, 0
F0009E38: 12800006                 bne     loc_F0009E50
F0009E3C: 9002620c                 add     %o1, 0x20C, %o0
F0009E40: d0026218                 ld      [%o1+0x218], %o0
F0009E44: 80a22000                 cmp     %o0, 0
F0009E48: 0280000b                 be      loc_F0009E74
F0009E4C: 9002620c                 add     %o1, 0x20C, %o0
F0009E50: 400025d8                 call    _itimerdecr
F0009E54: 92100012                 mov     %l2, %o1! char *
F0009E58: 80a22000                 cmp     %o0, 0
F0009E5C: 32800007                 bne,a   loc_F0009E78
F0009E60: 213c04cf                 sethi   -0xFECC400, %l0
F0009E64: d00421d8                 ld      [%l0+0x1D8], %o0
F0009E68: d0020000                 ld      [%o0], %o0! unsigned int
F0009E6C: 40001dc2                 call    _psignal
F0009E70: 9210201a                 mov     0x1A, %o1
F0009E74: 213c04cf                 sethi   -0xFECC400, %l0
F0009E78: d20421d8                 ld      [%l0+0x1D8], %o1
F0009E7C: d0024000                 ld      [%o1], %o0
F0009E80: 80a22000                 cmp     %o0, 0
F0009E84: 02800037                 be      loc_F0009F60
F0009E88: 90100018                 mov     %i0, %o0
F0009E8C: d004e04c                 ld      [%l3+0x4C], %o0
F0009E90: 808a2080                 btst    0x80, %o0
F0009E94: 12800033                 bne     loc_F0009F60
F0009E98: 90100018                 mov     %i0, %o0
F0009E9C: d2026260                 ld      [%o1+0x260], %o1
F0009EA0: 111fffff901223ff         set     0x7FFFFFFF, %o0
F0009EA8: 80a24008                 cmp     %o1, %o0
F0009EAC: 02800019                 be      loc_F0009F10
F0009EB0: 90100013                 mov     %l3, %o0
F0009EB4: 9207bfe8                 add     %fp, var_18, %o1
F0009EB8: 4001b6cf                 call    _thread_read_times
F0009EBC: 9407bff0                 add     %fp, var_10, %o2
F0009EC0: d007bff0                 ld      [%fp+var_10], %o0
F0009EC4: d207bfe8                 ld      [%fp+var_18], %o1
F0009EC8: d40421d8                 ld      [%l0+0x1D8], %o2
F0009ECC: 90020009                 add     %o0, %o1, %o0
F0009ED0: d202a260                 ld      [%o2+0x260], %o1! char *
F0009ED4: 90022001                 inc     %o0
F0009ED8: 80a20009                 cmp     %o0, %o1
F0009EDC: 2480000e                 ble,a   loc_F0009F14
F0009EE0: 213c04cf                 sethi   -0xFECC400, %l0
F0009EE4: d0028000                 ld      [%o2], %o0! unsigned int
F0009EE8: 40001da3                 call    _psignal
F0009EEC: 92102018                 mov     0x18, %o1
F0009EF0: d20421d8                 ld      [%l0+0x1D8], %o1
F0009EF4: d4026260                 ld      [%o1+0x260], %o2
F0009EF8: d0026264                 ld      [%o1+0x264], %o0
F0009EFC: 80a28008                 cmp     %o2, %o0
F0009F00: 16800005                 bge     loc_F0009F14
F0009F04: 213c04cf                 sethi   -0xFECC400, %l0
F0009F08: 9002a005                 add     %o2, 5, %o0
F0009F0C: d0226260                 st      %o0, [%o1+0x260]
F0009F10: 213c04cf                 sethi   -0xFECC400, %l0
F0009F14: d20421d8                 ld      [%l0+0x1D8], %o1
F0009F18: d0026224                 ld      [%o1+0x224], %o0
F0009F1C: 80a22000                 cmp     %o0, 0
F0009F20: 12800006                 bne     loc_F0009F38
F0009F24: 9002621c                 add     %o1, 0x21C, %o0
F0009F28: d0026228                 ld      [%o1+0x228], %o0
F0009F2C: 80a22000                 cmp     %o0, 0
F0009F30: 0280000b                 be      loc_F0009F5C
F0009F34: 9002621c                 add     %o1, 0x21C, %o0
F0009F38: 4000259e                 call    _itimerdecr
F0009F3C: 92100012                 mov     %l2, %o1! char *
F0009F40: 80a22000                 cmp     %o0, 0
F0009F44: 12800007                 bne     loc_F0009F60
F0009F48: 90100018                 mov     %i0, %o0
F0009F4C: d00421d8                 ld      [%l0+0x1D8], %o0
F0009F50: d0020000                 ld      [%o0], %o0! unsigned int
F0009F54: 40001d88                 call    _psignal
F0009F58: 9210201b                 mov     0x1B, %o1
F0009F5C: 90100018                 mov     %i0, %o0
F0009F60: 40000004                 call    _gatherstats
F0009F64: 92100019                 mov     %i1, %o1
F0009F68: 81c7e008                 ret
F0009F6C: 81e80000                 restore
