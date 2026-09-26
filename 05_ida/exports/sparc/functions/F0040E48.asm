F0040E48: 9de3bf98                 save    %sp, -0x68, %sp
F0040E4C: 80a6a000                 cmp     %i2, 0
F0040E50: 32800002                 bne,a   loc_F0040E58
F0040E54: f0268000                 st      %i0, [%i2]
F0040E58: 80a6e000                 cmp     %i3, 0
F0040E5C: 0280000c                 be      locret_F0040E8C
F0040E60: 01000000                 nop
F0040E64: d0062024                 ld      [%i0+0x24], %o0
F0040E68: d0022128                 ld      [%o0+0x128], %o0
F0040E6C: d2022024                 ld      [%o0+0x24], %o1
F0040E70: 80a26000                 cmp     %o1, 0
F0040E74: 26800002                 bl,a    loc_F0040E7C
F0040E78: 920263ff                 inc     0x3FF, %o1
F0040E7C: 90100019                 mov     %i1, %o0
F0040E80: 7fff15a0                 call    _umul
F0040E84: 933a600a                 sra     %o1, 10, %o1
F0040E88: d026c000                 st      %o0, [%i3]
F0040E8C: 81c7e008                 ret
F0040E90: 91e82000                 restore %g0, 0, %o0
