F005EB34: 9de3bf98                 save    %sp, -0x68, %sp
F005EB38: c4062004                 ld      [%i0+4], %g2
F005EB3C: 80a0a000                 cmp     %g2, 0
F005EB40: 02800008                 be      locret_F005EB60
F005EB44: 01000000                 nop
F005EB48: c400a010                 ld      [%g2+0x10], %g2
F005EB4C: c4260000                 st      %g2, [%i0]
F005EB50: 84062008                 add     %i0, 8, %g2
F005EB54: c426200c                 st      %g2, [%i0+0xC]
F005EB58: 84062010                 add     %i0, 0x10, %g2
F005EB5C: c4262014                 st      %g2, [%i0+0x14]
F005EB60: 81c7e008                 ret
F005EB64: 81e80000                 restore
