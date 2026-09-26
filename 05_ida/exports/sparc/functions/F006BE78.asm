F006BE78: 9de3bf98                 save    %sp, -0x68, %sp
F006BE7C: 053c04f0                 sethi   %hi(_machine_info), %g2
F006BE80: c600a040                 ld      [%g2+%lo(_machine_info)], %g3
F006BE84: c6264000                 st      %g3, [%i1]
F006BE88: 8410a040                 bset    %lo(_machine_info), %g2
F006BE8C: c600a004                 ld      [%g2+4], %g3
F006BE90: c6266004                 st      %g3, [%i1+4]
F006BE94: c600a008                 ld      [%g2+8], %g3
F006BE98: c6266008                 st      %g3, [%i1+8]
F006BE9C: c600a00c                 ld      [%g2+0xC], %g3
F006BEA0: c626600c                 st      %g3, [%i1+0xC]
F006BEA4: c400a010                 ld      [%g2+0x10], %g2
F006BEA8: c4266010                 st      %g2, [%i1+0x10]
F006BEAC: 81c7e008                 ret
F006BEB0: 91e82000                 restore %g0, 0, %o0
