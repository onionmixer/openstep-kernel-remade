F003CEF4: 9de3bf98                 save    %sp, -0x68, %sp
F003CEF8: c40e204a                 ldub    [%i0+0x4A], %g2
F003CEFC: f20e204b                 ldub    [%i0+0x4B], %i1
F003CF00: c60e204c                 ldub    [%i0+0x4C], %g3
F003CF04: 373c04ea                 sethi   -0xFEC5800, %i3
F003CF08: f40e2059                 ldub    [%i0+0x59], %i2
F003CF0C: 84188019                 btog    %i1, %g2
F003CF10: f20e204d                 ldub    [%i0+0x4D], %i1
F003CF14: 8618c002                 btog    %g2, %g3
F003CF18: c40e204e                 ldub    [%i0+0x4E], %g2
F003CF1C: b21e4003                 btog    %g3, %i1
F003CF20: c60e204f                 ldub    [%i0+0x4F], %g3
F003CF24: 84188019                 btog    %i1, %g2
F003CF28: f20e2050                 ldub    [%i0+0x50], %i1
F003CF2C: 8618c002                 btog    %g2, %g3
F003CF30: c40e2051                 ldub    [%i0+0x51], %g2
F003CF34: b21e4003                 btog    %g3, %i1
F003CF38: c60e2054                 ldub    [%i0+0x54], %g3
F003CF3C: 84188019                 btog    %i1, %g2
F003CF40: f20e2055                 ldub    [%i0+0x55], %i1
F003CF44: 8618c002                 btog    %g2, %g3
F003CF48: c40e2056                 ldub    [%i0+0x56], %g2
F003CF4C: b21e4003                 btog    %g3, %i1
F003CF50: c60e2057                 ldub    [%i0+0x57], %g3
F003CF54: 84188019                 btog    %i1, %g2
F003CF58: f20e2058                 ldub    [%i0+0x58], %i1
F003CF5C: 8618c002                 btog    %g2, %g3
F003CF60: b21e4003                 btog    %g3, %i1
F003CF64: c60e205a                 ldub    [%i0+0x5A], %g3
F003CF68: b616e2a0                 bset    0x2A0, %i3
F003CF6C: c40e205b                 ldub    [%i0+0x5B], %g2
F003CF70: b41e8019                 btog    %i1, %i2
F003CF74: f20e204a                 ldub    [%i0+0x4A], %i1
F003CF78: 8618c01a                 btog    %i2, %g3
F003CF7C: 84188003                 btog    %g3, %g2
F003CF80: 8408a03f                 and     %g2, 0x3F, %g2
F003CF84: 8528a002                 sll     %g2, 2, %g2
F003CF88: c400801b                 ld      [%g2+%i3], %g2
F003CF8C: c60e204b                 ldub    [%i0+0x4B], %g3
F003CF90: f40e2058                 ldub    [%i0+0x58], %i2
F003CF94: c4262008                 st      %g2, [%i0+8]
F003CF98: c40e204c                 ldub    [%i0+0x4C], %g2
F003CF9C: b21e4003                 btog    %g3, %i1
F003CFA0: c60e204d                 ldub    [%i0+0x4D], %g3
F003CFA4: 84188019                 btog    %i1, %g2
F003CFA8: f20e204e                 ldub    [%i0+0x4E], %i1
F003CFAC: 8618c002                 btog    %g2, %g3
F003CFB0: c40e204f                 ldub    [%i0+0x4F], %g2
F003CFB4: b21e4003                 btog    %g3, %i1
F003CFB8: c60e2050                 ldub    [%i0+0x50], %g3
F003CFBC: 84188019                 btog    %i1, %g2
F003CFC0: f20e2051                 ldub    [%i0+0x51], %i1
F003CFC4: 8618c002                 btog    %g2, %g3
F003CFC8: c40e2054                 ldub    [%i0+0x54], %g2
F003CFCC: b21e4003                 btog    %g3, %i1
F003CFD0: c60e2055                 ldub    [%i0+0x55], %g3
F003CFD4: 84188019                 btog    %i1, %g2
F003CFD8: f20e2056                 ldub    [%i0+0x56], %i1
F003CFDC: 8618c002                 btog    %g2, %g3
F003CFE0: c40e2057                 ldub    [%i0+0x57], %g2
F003CFE4: b21e4003                 btog    %g3, %i1
F003CFE8: 84188019                 btog    %i1, %g2
F003CFEC: f20e2059                 ldub    [%i0+0x59], %i1
F003CFF0: c60e205a                 ldub    [%i0+0x5A], %g3
F003CFF4: b41e8002                 btog    %g2, %i2
F003CFF8: c40e205b                 ldub    [%i0+0x5B], %g2
F003CFFC: b21e401a                 btog    %i2, %i1
F003D000: 8618c019                 btog    %i1, %g3
F003D004: 84188003                 btog    %g3, %g2
F003D008: 8408a03f                 and     %g2, 0x3F, %g2
F003D00C: 8528a002                 sll     %g2, 2, %g2
F003D010: f020801b                 st      %i0, [%g2+%i3]
F003D014: 073c04ea                 sethi   %hi(_rnhash), %g3
F003D018: c400e278                 ld      [%g3+%lo(_rnhash)], %g2
F003D01C: 8400a001                 inc     %g2
F003D020: c420e278                 st      %g2, [%g3+%lo(_rnhash)]
F003D024: 81c7e008                 ret
F003D028: 81e80000                 restore
