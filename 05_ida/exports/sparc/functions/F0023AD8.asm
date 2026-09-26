F0023AD8: 9de3bf90                 save    %sp, -0x70, %sp
F0023ADC: 213c04cf                 sethi   %hi(dword_F0133DDC), %l0
F0023AE0: d00421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o0
F0023AE4: e2022024                 ld      [%o0+0x24], %l1
F0023AE8: d0044000                 ld      [%l1], %o0
F0023AEC: 400013cb                 call    _getvnodefp
F0023AF0: 9207bff4                 add     %fp, var_C, %o1
F0023AF4: d20421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o1
F0023AF8: d02a6038                 stb     %o0, [%o1+0x38]
F0023AFC: d00421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o0
F0023B00: d04a2038                 ldsb    [%o0+0x38], %o0
F0023B04: 80a22000                 cmp     %o0, 0
F0023B08: 12800006                 bne     locret_F0023B20
F0023B0C: d007bff4                 ld      [%fp+var_C], %o0
F0023B10: d2046004                 ld      [%l1+4], %o1
F0023B14: d0022018                 ld      [%o0+0x18], %o0
F0023B18: 40000004                 call    _cstatfs
F0023B1C: d0022024                 ld      [%o0+0x24], %o0
F0023B20: 81c7e008                 ret
F0023B24: 81e80000                 restore
