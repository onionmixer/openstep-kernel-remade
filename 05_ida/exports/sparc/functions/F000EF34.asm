F000EF34: 9de3bf98                 save    %sp, -0x68, %sp
F000EF38: 073c04cf8410e1dc         set     dword_F0133DDC, %g2
F000EF40: c400bffc                 ld      [%g2-4], %g2
F000EF44: c4008000                 ld      [%g2], %g2
F000EF48: c400a014                 ld      [%g2+0x14], %g2
F000EF4C: c600e1dc                 ld      [%g3+0x1DC], %g3
F000EF50: 8530a00e                 srl     %g2, 14, %g2
F000EF54: 8408a001                 and     %g2, 1, %g2
F000EF58: c420e030                 st      %g2, [%g3+0x30]
F000EF5C: 81c7e008                 ret
F000EF60: 81e80000                 restore
