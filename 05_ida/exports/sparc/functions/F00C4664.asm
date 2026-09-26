F00C4664: 9de3bf98                 save    %sp, -0x68, %sp
F00C4668: 053c04cc                 sethi   %hi(dword_F0133030), %g2
F00C466C: c600a030                 ld      [%g2+%lo(dword_F0133030)], %g3
F00C4670: 053c04cc                 sethi   %hi(dword_F0133034), %g2
F00C4674: f400a034                 ld      [%g2+%lo(dword_F0133034)], %i2
F00C4678: 80a60003                 cmp     %i0, %g3
F00C467C: 0a800007                 bcs     loc_F00C4698
F00C4680: 8410a034                 bset    %lo(dword_F0133034), %g2
F00C4684: 10800012                 ba      locret_F00C46CC
F00C4688: b0103d40                 mov     -0x2C0, %i0
F00C468C: b0102000                 mov     0, %i0
F00C4690: 1080000f                 ba      locret_F00C46CC
F00C4694: c4264000                 st      %g2, [%i1]
F00C4698: 80a68002                 cmp     %i2, %g2
F00C469C: 2280000c                 be,a    locret_F00C46CC
F00C46A0: b0103d29                 mov     -0x2D7, %i0
F00C46A4: 86100002                 mov     %g2, %g3
F00C46A8: c406a004                 ld      [%i2+4], %g2
F00C46AC: 80a08018                 cmp     %g2, %i0
F00C46B0: 22bffff7                 be,a    loc_F00C468C
F00C46B4: c4068000                 ld      [%i2], %g2
F00C46B8: f406a008                 ld      [%i2+8], %i2
F00C46BC: 80a68003                 cmp     %i2, %g3
F00C46C0: 32bffffb                 bne,a   loc_F00C46AC
F00C46C4: c406a004                 ld      [%i2+4], %g2
F00C46C8: b0103d29                 mov     -0x2D7, %i0
F00C46CC: 81c7e008                 ret
F00C46D0: 81e80000                 restore
