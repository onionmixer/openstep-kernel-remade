F0061E14: 9de3bf98                 save    %sp, -0x68, %sp
F0061E18: e0064000                 ld      [%i1], %l0
F0061E1C: 11000140                 sethi   0x50000, %o0
F0061E20: 808c0008                 btst    %o0, %l0
F0061E24: 02800021                 be      loc_F0061EA8
F0061E28: e2066008                 ld      [%i1+8], %l1
F0061E2C: f2066004                 ld      [%i1+4], %i1
F0061E30: d0064000                 ld      [%i1], %o0
F0061E34: 80a22000                 cmp     %o0, 0
F0061E38: 12bffffe                 bne     loc_F0061E30
F0061E3C: 01000000                 nop
F0061E40: 4000d41a                 call    _simple_lock_try
F0061E44: 90100019                 mov     %i1, %o0
F0061E48: 80a22000                 cmp     %o0, 0
F0061E4C: 02bffff9                 be      loc_F0061E30
F0061E50: 01000000                 nop
F0061E54: d0066008                 ld      [%i1+8], %o0
F0061E58: 80a22000                 cmp     %o0, 0
F0061E5C: 06800005                 bl      loc_F0061E70
F0061E60: 92102000                 mov     0, %o1
F0061E64: d006600c                 ld      [%i1+0xC], %o0
F0061E68: 90220018                 sub     %o0, %i0, %o0
F0061E6C: 9332201f                 srl     %o0, 31, %o1
F0061E70: c0264000                 clr     [%i1]
F0061E74: 80a26000                 cmp     %o1, 0
F0061E78: 0280000c                 be      loc_F0061EA8
F0061E7C: 11001000                 sethi   0x400000, %o0
F0061E80: 808c0008                 btst    %o0, %l0
F0061E84: 1280001e                 bne     locret_F0061EFC
F0061E88: 11000fc0                 sethi   0x3F0000, %o0
F0061E8C: a02c0008                 bclr    %o0, %l0
F0061E90: 11000400                 sethi   0x100000, %o0
F0061E94: 80a46000                 cmp     %l1, 0
F0061E98: 02800003                 be      loc_F0061EA4
F0061E9C: a0140008                 bset    %o0, %l0
F0061EA0: a0042001                 inc     %l0
F0061EA4: a2102000                 mov     0, %l1
F0061EA8: 110007c0                 sethi   0x1F0000, %o0
F0061EAC: 940c0008                 and     %l0, %o0, %o2
F0061EB0: 11001000                 sethi   0x400000, %o0
F0061EB4: 808c0008                 btst    %o0, %l0
F0061EB8: 12800005                 bne     loc_F0061ECC
F0061EBC: 11080000                 sethi   0x20000000, %o0
F0061EC0: 80a46000                 cmp     %l1, 0
F0061EC4: 02800003                 be      loc_F0061ED0
F0061EC8: 11200000                 sethi   0x80000000, %o0
F0061ECC: 94128008                 bset    %o0, %o2
F0061ED0: 11000800                 sethi   0x200000, %o0
F0061ED4: 808c0008                 btst    %o0, %l0
F0061ED8: 02800003                 be      loc_F0061EE4
F0061EDC: 11100000                 sethi   0x40000000, %o0
F0061EE0: 94128008                 bset    %o0, %o2
F0061EE4: d0074000                 ld      [%i5], %o0
F0061EE8: 932a2002                 sll     %o0, 2, %o1
F0061EEC: f426c009                 st      %i2, [%i3+%o1]
F0061EF0: d4270009                 st      %o2, [%i4+%o1]
F0061EF4: 90022001                 inc     %o0
F0061EF8: d0274000                 st      %o0, [%i5]
F0061EFC: 81c7e008                 ret
F0061F00: 81e80000                 restore
