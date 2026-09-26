F000DE44: 9de3bf98                 save    %sp, -0x68, %sp
F000DE48: 053c04cf                 sethi   %hi(dword_F0133DDC), %g2
F000DE4C: c600a1dc                 ld      [%g2+%lo(dword_F0133DDC)], %g3
F000DE50: 053c0447                 sethi   %hi(_page_size), %g2
F000DE54: c400a13c                 ld      [%g2+%lo(_page_size)], %g2
F000DE58: c420e030                 st      %g2, [%g3+0x30]
F000DE5C: 81c7e008                 ret
F000DE60: 81e80000                 restore
