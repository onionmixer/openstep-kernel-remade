F006E0E4: 9de3bf98                 save    %sp, -0x68, %sp
F006E0E8: 113c043e                 sethi   %hi(_hz), %o0
F006E0EC: d20223e0                 ld      [%o0+%lo(_hz)], %o1! int
F006E0F0: 110ee6b2                 sethi   0x3B9AC800, %o0! int
F006E0F4: 7ffe6145                 call    _div
F006E0F8: 90122200                 bset    0x200, %o0
F006E0FC: 96100008                 mov     %o0, %o3
F006E100: 953a201f                 sra     %o0, 31, %o2
F006E104: 113c04f0                 sethi   %hi(_ns_per_tick), %o0
F006E108: d43a2288                 std     %o2, [%o0+%lo(_ns_per_tick)]
F006E10C: 9010000a                 mov     %o2, %o0
F006E110: 9210000b                 mov     %o3, %o1
F006E114: 4000a5ca                 call    _hardclock_init
F006E118: 01000000                 nop
F006E11C: 81c7e008                 ret
F006E120: 81e80000                 restore
