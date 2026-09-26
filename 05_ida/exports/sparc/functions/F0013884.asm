F0013884: 9de3bf98                 save    %sp, -0x68, %sp
F0013888: 053c04cf                 sethi   %hi(dword_F0133DDC), %g2
F001388C: c600a1dc                 ld      [%g2+%lo(dword_F0133DDC)], %g3
F0013890: 053c04d1                 sethi   %hi(_hostid), %g2
F0013894: c400a228                 ld      [%g2+%lo(_hostid)], %g2
F0013898: c420e030                 st      %g2, [%g3+0x30]
F001389C: 81c7e008                 ret
F00138A0: 81e80000                 restore
