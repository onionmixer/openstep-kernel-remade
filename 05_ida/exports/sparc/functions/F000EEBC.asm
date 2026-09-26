F000EEBC: 9de3bf98                 save    %sp, -0x68, %sp
F000EEC0: 313c04cfb21621dc         set     dword_F0133DDC, %i1
F000EEC8: c4067ffc                 ld      [%i1-4], %g2
F000EECC: c60621dc                 ld      [%i0+0x1DC], %g3
F000EED0: c400a01c                 ld      [%g2+0x1C], %g2
F000EED4: c450a006                 ldsh    [%g2+6], %g2
F000EED8: c420e030                 st      %g2, [%g3+0x30]
F000EEDC: c4067ffc                 ld      [%i1-4], %g2
F000EEE0: c60621dc                 ld      [%i0+0x1DC], %g3
F000EEE4: c400a01c                 ld      [%g2+0x1C], %g2
F000EEE8: c450a002                 ldsh    [%g2+2], %g2
F000EEEC: c420e034                 st      %g2, [%g3+0x34]
F000EEF0: 81c7e008                 ret
F000EEF4: 81e80000                 restore
