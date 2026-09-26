F0069AF4: 9de3bf98                 save    %sp, -0x68, %sp
F0069AF8: 80a62000                 cmp     %i0, 0
F0069AFC: 12800004                 bne     loc_F0069B0C
F0069B00: 053c043f                 sethi   -0xFEF0400, %g2
F0069B04: 1080000d                 ba      locret_F0069B38
F0069B08: b0102016                 mov     0x16, %i0
F0069B0C: f000a000                 ld      [%g2], %i0
F0069B10: c4060000                 ld      [%i0], %g2
F0069B14: c4264000                 st      %g2, [%i1]
F0069B18: c4062004                 ld      [%i0+4], %g2
F0069B1C: c6064000                 ld      [%i1], %g3
F0069B20: c4266004                 st      %g2, [%i1+4]
F0069B24: c4062008                 ld      [%i0+8], %g2
F0069B28: 80a0c002                 cmp     %g3, %g2
F0069B2C: 32bffffa                 bne,a   loc_F0069B14
F0069B30: c4060000                 ld      [%i0], %g2
F0069B34: b0102000                 mov     0, %i0
F0069B38: 81c7e008                 ret
F0069B3C: 81e80000                 restore
