F00EAE6C: 9de3bf90                 save    %sp, -0x70, %sp
F00EAE70: e4062010                 ld      [%i0+0x10], %l2
F00EAE74: e6062014                 ld      [%i0+0x14], %l3
F00EAE78: 9010001a                 mov     %i2, %o0
F00EAE7C: 133c03f392126150         set     aTableSSCountDC, %o1! "Table [%s -> %s]: \tcount: %d\tcapacity"...
F00EAE84: d4062008                 ld      [%i0+8], %o2
F00EAE88: d606200c                 ld      [%i0+0xC], %o3
F00EAE8C: d8062004                 ld      [%i0+4], %o4
F00EAE90: 7ffe8529                 call    _NXPrintf
F00EAE94: 9a100012                 mov     %l2, %o5
F00EAE98: a404bfff                 inc     -1, %l2
F00EAE9C: 80a4bfff                 cmp     %l2, -1
F00EAEA0: 02800029                 be      loc_F00EAF44
F00EAEA4: 9010001a                 mov     %i2, %o0
F00EAEA8: 2d3c03f3                 sethi   -0xFF03400, %l6
F00EAEAC: 2b3c03f3                 sethi   -0xFF03400, %l5
F00EAEB0: 293c03f3                 sethi   -0xFF03400, %l4
F00EAEB4: d404c000                 ld      [%l3], %o2
F00EAEB8: 80a2a000                 cmp     %o2, 0
F00EAEBC: 0280001d                 be      loc_F00EAF30
F00EAEC0: 9010001a                 mov     %i2, %o0
F00EAEC4: a010000a                 mov     %o2, %l0
F00EAEC8: e204e004                 ld      [%l3+4], %l1
F00EAECC: 7ffe851a                 call    _NXPrintf
F00EAED0: 9215a180                 or      %l6, 0x180, %o1
F00EAED4: 10800011                 ba      loc_F00EAF18
F00EAED8: a0043fff                 inc     -1, %l0
F00EAEDC: d2062008                 ld      [%i0+8], %o1
F00EAEE0: 7fffffba                 call    sub_F00EADC8
F00EAEE4: d4044000                 ld      [%l1], %o2
F00EAEE8: 9010001a                 mov     %i2, %o0
F00EAEEC: 7ffe8512                 call    _NXPrintf
F00EAEF0: 92156188                 or      %l5, 0x188, %o1
F00EAEF4: 9010001a                 mov     %i2, %o0
F00EAEF8: d206200c                 ld      [%i0+0xC], %o1
F00EAEFC: 7fffffb3                 call    sub_F00EADC8
F00EAF00: d4046004                 ld      [%l1+4], %o2
F00EAF04: 9010001a                 mov     %i2, %o0
F00EAF08: 7ffe850b                 call    _NXPrintf
F00EAF0C: 92152190                 or      %l4, 0x190, %o1
F00EAF10: a2046008                 inc     8, %l1
F00EAF14: a0043fff                 inc     -1, %l0
F00EAF18: 80a43fff                 cmp     %l0, -1
F00EAF1C: 12bffff0                 bne     loc_F00EAEDC
F00EAF20: 9010001a                 mov     %i2, %o0
F00EAF24: 133c03eb                 sethi   %hi(asc_F00FAC48), %o1! "\n"
F00EAF28: 7ffe8503                 call    _NXPrintf
F00EAF2C: 92126048                 bset    %lo(asc_F00FAC48), %o1! "\n"
F00EAF30: a404bfff                 inc     -1, %l2
F00EAF34: 80a4bfff                 cmp     %l2, -1
F00EAF38: 12bfffdf                 bne     loc_F00EAEB4
F00EAF3C: a604e008                 inc     8, %l3
F00EAF40: 9010001a                 mov     %i2, %o0
F00EAF44: 133c03eb                 sethi   %hi(asc_F00FAC48), %o1! "\n"
F00EAF48: 7ffe84fb                 call    _NXPrintf
F00EAF4C: 92126048                 bset    %lo(asc_F00FAC48), %o1! "\n"
F00EAF50: 7ffe84f6                 call    _NXFlush
F00EAF54: 9010001a                 mov     %i2, %o0
F00EAF58: 81c7e008                 ret
F00EAF5C: 81e80000                 restore
