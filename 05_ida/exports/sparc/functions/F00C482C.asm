F00C482C: 9de3bf98                 save    %sp, -0x68, %sp
F00C4830: 053c04cc                 sethi   %hi(dword_F0133040), %g2
F00C4834: c400a040                 ld      [%g2+%lo(dword_F0133040)], %g2
F00C4838: 80a60002                 cmp     %i0, %g2
F00C483C: 08800006                 bleu    loc_F00C4854
F00C4840: 053c04cc                 sethi   -0xFECD000, %g2
F00C4844: 10800013                 ba      locret_F00C4890
F00C4848: b0103d40                 mov     -0x2C0, %i0
F00C484C: 10800011                 ba      locret_F00C4890
F00C4850: b0102000                 mov     0, %i0
F00C4854: c600a044                 ld      [%g2+0x44], %g3
F00C4858: 8410a044                 bset    0x44, %g2 ! 'D'
F00C485C: 80a0c002                 cmp     %g3, %g2
F00C4860: 2280000c                 be,a    locret_F00C4890
F00C4864: b0103d29                 mov     -0x2D7, %i0
F00C4868: b4100002                 mov     %g2, %i2
F00C486C: c400e004                 ld      [%g3+4], %g2
F00C4870: 80a08018                 cmp     %g2, %i0
F00C4874: 22bffff6                 be,a    loc_F00C484C
F00C4878: c6264000                 st      %g3, [%i1]
F00C487C: c600e014                 ld      [%g3+0x14], %g3
F00C4880: 80a0c01a                 cmp     %g3, %i2
F00C4884: 32bffffb                 bne,a   loc_F00C4870
F00C4888: c400e004                 ld      [%g3+4], %g2
F00C488C: b0103d29                 mov     -0x2D7, %i0
F00C4890: 81c7e008                 ret
F00C4894: 81e80000                 restore
