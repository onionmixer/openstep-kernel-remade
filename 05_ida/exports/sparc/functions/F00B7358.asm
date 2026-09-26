F00B7358: 9de3bf98                 save    %sp, -0x68, %sp
F00B735C: c02e2028                 clrb    [%i0+0x28]
F00B7360: c0262024                 clr     [%i0+0x24]
F00B7364: c02e202a                 clrb    [%i0+0x2A]
F00B7368: c6062020                 ld      [%i0+0x20], %g3
F00B736C: c02e2029                 clrb    [%i0+0x29]
F00B7370: c406201c                 ld      [%i0+0x1C], %g2
F00B7374: c626202c                 st      %g3, [%i0+0x2C]
F00B7378: c4262030                 st      %g2, [%i0+0x30]
F00B737C: c0288000                 clrb    [%g2]
F00B7380: 0500003b                 sethi   0xEC00, %g2
F00B7384: c616205c                 lduh    [%i0+0x5C], %g3
F00B7388: 8410a3cf                 bset    0x3CF, %g2
F00B738C: 8608c002                 and     %g3, %g2, %g3
F00B7390: c4062018                 ld      [%i0+0x18], %g2
F00B7394: c636205c                 sth     %g3, [%i0+0x5C]
F00B7398: 80a0a000                 cmp     %g2, 0
F00B739C: 02800005                 be      loc_F00B73B0
F00B73A0: c4262058                 st      %g2, [%i0+0x58]
F00B73A4: c416205c                 lduh    [%i0+0x5C], %g2
F00B73A8: 8410a020                 bset    0x20, %g2 ! ' '
F00B73AC: c436205c                 sth     %g2, [%i0+0x5C]
F00B73B0: c416205c                 lduh    [%i0+0x5C], %g2
F00B73B4: 8088a001                 btst    1, %g2
F00B73B8: 0280000a                 be      locret_F00B73E0
F00B73BC: 84062048                 add     %i0, 0x48, %g2 ! 'H'
F00B73C0: c4262054                 st      %g2, [%i0+0x54]
F00B73C4: c026204c                 clr     [%i0+0x4C]
F00B73C8: c606203c                 ld      [%i0+0x3C], %g3
F00B73CC: c0262050                 clr     [%i0+0x50]
F00B73D0: c406203c                 ld      [%i0+0x3C], %g2
F00B73D4: c6262038                 st      %g3, [%i0+0x38]
F00B73D8: c6262034                 st      %g3, [%i0+0x34]
F00B73DC: c4262048                 st      %g2, [%i0+0x48]
F00B73E0: 81c7e008                 ret
F00B73E4: 81e80000                 restore
