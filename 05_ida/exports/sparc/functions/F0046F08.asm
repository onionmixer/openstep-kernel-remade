F0046F08: 9de3bf98                 save    %sp, -0x68, %sp
F0046F0C: a2100018                 mov     %i0, %l1
F0046F10: e0046030                 ld      [%l1+0x30], %l0
F0046F14: d0042038                 ld      [%l0+0x38], %o0
F0046F18: d402201c                 ld      [%o0+0x1C], %o2
F0046F1C: d602a014                 ld      [%o2+0x14], %o3
F0046F20: 92100019                 mov     %i1, %o1
F0046F24: 9fc2c000                 call    %o3
F0046F28: 9410001a                 mov     %i2, %o2
F0046F2C: b0920000                 orcc    %o0, %g0, %i0
F0046F30: 12800014                 bne     locret_F0046F80
F0046F34: 01000000                 nop
F0046F38: d004204c                 ld      [%l0+0x4C], %o0
F0046F3C: d0266020                 st      %o0, [%i1+0x20]
F0046F40: d0042050                 ld      [%l0+0x50], %o0
F0046F44: d0266024                 st      %o0, [%i1+0x24]
F0046F48: d0042054                 ld      [%l0+0x54], %o0
F0046F4C: d0266028                 st      %o0, [%i1+0x28]
F0046F50: d0042058                 ld      [%l0+0x58], %o0
F0046F54: d026602c                 st      %o0, [%i1+0x2C]
F0046F58: d004205c                 ld      [%l0+0x5C], %o0
F0046F5C: d0266030                 st      %o0, [%i1+0x30]
F0046F60: d0042060                 ld      [%l0+0x60], %o0
F0046F64: d0266034                 st      %o0, [%i1+0x34]
F0046F68: d0046030                 ld      [%l1+0x30], %o0
F0046F6C: d002207c                 ld      [%o0+0x7C], %o0
F0046F70: d0266018                 st      %o0, [%i1+0x18]
F0046F74: 113c043c                 sethi   %hi(_fifoinfo), %o0
F0046F78: d0022394                 ld      [%o0+%lo(_fifoinfo)], %o0
F0046F7C: d026601c                 st      %o0, [%i1+0x1C]
F0046F80: 81c7e008                 ret
F0046F84: 81e80000                 restore
