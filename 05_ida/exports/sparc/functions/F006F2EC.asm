F006F2EC: 9de3bf98                 save    %sp, -0x68, %sp
F006F2F0: 053c04f0                 sethi   %hi(_min_quantum), %g2
F006F2F4: c600a290                 ld      [%g2+%lo(_min_quantum)], %g3
F006F2F8: 053c04d4                 sethi   %hi(dword_F013512C), %g2
F006F2FC: c620a12c                 st      %g3, [%g2+%lo(dword_F013512C)]
F006F300: 81c7e008                 ret
F006F304: 81e80000                 restore
