F000EEF8: 9de3bf98                 save    %sp, -0x68, %sp
F000EEFC: 313c04cfb21621dc         set     dword_F0133DDC, %i1
F000EF04: c4067ffc                 ld      [%i1-4], %g2
F000EF08: c60621dc                 ld      [%i0+0x1DC], %g3
F000EF0C: c400a01c                 ld      [%g2+0x1C], %g2
F000EF10: c450a008                 ldsh    [%g2+8], %g2
F000EF14: c420e030                 st      %g2, [%g3+0x30]
F000EF18: c4067ffc                 ld      [%i1-4], %g2
F000EF1C: c60621dc                 ld      [%i0+0x1DC], %g3
F000EF20: c400a01c                 ld      [%g2+0x1C], %g2
F000EF24: c450a004                 ldsh    [%g2+4], %g2
F000EF28: c420e034                 st      %g2, [%g3+0x34]
F000EF2C: 81c7e008                 ret
F000EF30: 81e80000                 restore
