F000E2E0: 9de3bf98                 save    %sp, -0x68, %sp
F000E2E4: 053c04cf                 sethi   %hi(_active_u), %g2
F000E2E8: c400a1d8                 ld      [%g2+%lo(_active_u)], %g2
F000E2EC: c600a150                 ld      [%g2+0x150], %g3
F000E2F0: c408c018                 ldub    [%g3+%i0], %g2
F000E2F4: 8408bffd                 and     %g2, -3, %g2
F000E2F8: c428c018                 stb     %g2, [%g3+%i0]
F000E2FC: 81c7e008                 ret
F000E300: 81e80000                 restore
