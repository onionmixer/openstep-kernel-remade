F0093A8C: 9de3bf98                 save    %sp, -0x68, %sp
F0093A90: 213c04c4                 sethi   %hi(unk_F0131251), %l0
F0093A94: d04c2251                 ldsb    [%l0+%lo(unk_F0131251)], %o0
F0093A98: 80a22000                 cmp     %o0, 0
F0093A9C: 12800008                 bne     loc_F0093ABC
F0093AA0: b00e3ff8                 and     %i0, -8, %i0
F0093AA4: 113c04c490122254         set     unk_F0131254, %o0
F0093AAC: 7fff5497                 call    _lock_init
F0093AB0: 92102001                 mov     1, %o1
F0093AB4: 90102001                 mov     1, %o0
F0093AB8: d02c2251                 stb     %o0, [%l0+%lo(unk_F0131251)]
F0093ABC: 113c04c4                 sethi   %hi(unk_F0131254), %o0
F0093AC0: 7fff54c1                 call    _lock_write
F0093AC4: 90122254                 bset    %lo(unk_F0131254), %o0
F0093AC8: 133c0449                 sethi   %hi(off_F0112520), %o1
F0093ACC: d4026120                 ld      [%o1+%lo(off_F0112520)], %o2
F0093AD0: 96126120                 or      %o1, %lo(off_F0112520), %o3
F0093AD4: 80a2800b                 cmp     %o2, %o3
F0093AD8: 02800021                 be      loc_F0093B5C
F0093ADC: 113c04c4                 sethi   -0xFECF000, %o0
F0093AE0: 912e2010                 sll     %i0, 16, %o0
F0093AE4: a33a2010                 sra     %o0, 16, %l1
F0093AE8: a4100009                 mov     %o1, %l2
F0093AEC: a010000b                 mov     %o3, %l0
F0093AF0: d052a00c                 ldsh    [%o2+0xC], %o0
F0093AF4: 80a20011                 cmp     %o0, %l1
F0093AF8: 02800006                 be      loc_F0093B10
F0093AFC: f0028000                 ld      [%o2], %i0
F0093B00: d052a00e                 ldsh    [%o2+0xE], %o0
F0093B04: 80a20011                 cmp     %o0, %l1
F0093B08: 32800011                 bne,a   loc_F0093B4C
F0093B0C: 94100018                 mov     %i0, %o2
F0093B10: 80a60010                 cmp     %i0, %l0
F0093B14: d002a004                 ld      [%o2+4], %o0
F0093B18: 12800004                 bne     loc_F0093B28
F0093B1C: 92100018                 mov     %i0, %o1
F0093B20: 10800003                 ba      loc_F0093B2C
F0093B24: d0242004                 st      %o0, [%l0+4]
F0093B28: d0262004                 st      %o0, [%i0+4]
F0093B2C: 80a20010                 cmp     %o0, %l0
F0093B30: 32800003                 bne,a   loc_F0093B3C
F0093B34: d2220000                 st      %o1, [%o0]
F0093B38: d224a120                 st      %o1, [%l2+0x120]
F0093B3C: 9010000a                 mov     %o2, %o0
F0093B40: 7fff5198                 call    _kfree
F0093B44: 92102064                 mov     0x64, %o1 ! 'd'
F0093B48: 94100018                 mov     %i0, %o2
F0093B4C: 80a28010                 cmp     %o2, %l0
F0093B50: 32bfffe9                 bne,a   loc_F0093AF4
F0093B54: d052a00c                 ldsh    [%o2+0xC], %o0
F0093B58: 113c04c4                 sethi   -0xFECF000, %o0
F0093B5C: 7fff5536                 call    _lock_done
F0093B60: 90122254                 bset    0x254, %o0
F0093B64: 81c7e008                 ret
F0093B68: 81e80000                 restore
