F0098AB0: 9de3bf98                 save    %sp, -0x68, %sp
F0098AB4: 7fff3d6f                 call    _kalloc
F0098AB8: 90102110                 mov     0x110, %o0
F0098ABC: b0920000                 orcc    %o0, %g0, %i0
F0098AC0: 32800006                 bne,a   loc_F0098AD8
F0098AC4: c0262080                 clr     [%i0+0x80]
F0098AC8: 113c044d                 sethi   %hi(aCanTAllocateFp), %o0! "Can't allocate FPU context structure!"
F0098ACC: 7ffdf1a9                 call    _panic
F0098AD0: 90122080                 bset    %lo(aCanTAllocateFp), %o0! "Can't allocate FPU context structure!"
F0098AD4: c0262080                 clr     [%i0+0x80]
F0098AD8: 90103fff                 mov     -1, %o0
F0098ADC: d0260000                 st      %o0, [%i0]
F0098AE0: d0262004                 st      %o0, [%i0+4]
F0098AE4: d0262008                 st      %o0, [%i0+8]
F0098AE8: d026200c                 st      %o0, [%i0+0xC]
F0098AEC: d0262010                 st      %o0, [%i0+0x10]
F0098AF0: d0262014                 st      %o0, [%i0+0x14]
F0098AF4: d0262018                 st      %o0, [%i0+0x18]
F0098AF8: d026201c                 st      %o0, [%i0+0x1C]
F0098AFC: d0262020                 st      %o0, [%i0+0x20]
F0098B00: d0262024                 st      %o0, [%i0+0x24]
F0098B04: d0262028                 st      %o0, [%i0+0x28]
F0098B08: d026202c                 st      %o0, [%i0+0x2C]
F0098B0C: d0262030                 st      %o0, [%i0+0x30]
F0098B10: d0262034                 st      %o0, [%i0+0x34]
F0098B14: d0262038                 st      %o0, [%i0+0x38]
F0098B18: d026203c                 st      %o0, [%i0+0x3C]
F0098B1C: d0262040                 st      %o0, [%i0+0x40]
F0098B20: d0262044                 st      %o0, [%i0+0x44]
F0098B24: d0262048                 st      %o0, [%i0+0x48]
F0098B28: d026204c                 st      %o0, [%i0+0x4C]
F0098B2C: d0262050                 st      %o0, [%i0+0x50]
F0098B30: d0262054                 st      %o0, [%i0+0x54]
F0098B34: d0262058                 st      %o0, [%i0+0x58]
F0098B38: d026205c                 st      %o0, [%i0+0x5C]
F0098B3C: d0262060                 st      %o0, [%i0+0x60]
F0098B40: d0262064                 st      %o0, [%i0+0x64]
F0098B44: d0262068                 st      %o0, [%i0+0x68]
F0098B48: d026206c                 st      %o0, [%i0+0x6C]
F0098B4C: d0262070                 st      %o0, [%i0+0x70]
F0098B50: d0262074                 st      %o0, [%i0+0x74]
F0098B54: d0262078                 st      %o0, [%i0+0x78]
F0098B58: d026207c                 st      %o0, [%i0+0x7C]
F0098B5C: 81c7e008                 ret
F0098B60: 81e80000                 restore
