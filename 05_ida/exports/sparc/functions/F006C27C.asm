F006C27C: 9de3bf98                 save    %sp, -0x68, %sp
F006C280: 053c04f0                 sethi   %hi(_vm_info_queue), %g2
F006C284: f2062028                 ld      [%i0+0x28], %i1
F006C288: 8410a218                 bset    %lo(_vm_info_queue), %g2
F006C28C: 80a64002                 cmp     %i1, %g2
F006C290: 12800004                 bne     loc_F006C2A0
F006C294: c606202c                 ld      [%i0+0x2C], %g3
F006C298: 10800003                 ba      loc_F006C2A4
F006C29C: c6266004                 st      %g3, [%i1+4]
F006C2A0: c626602c                 st      %g3, [%i1+0x2C]
F006C2A4: 353c04f08416a218         set     _vm_info_queue, %g2
F006C2AC: 80a0c002                 cmp     %g3, %g2
F006C2B0: 32800003                 bne,a   loc_F006C2BC
F006C2B4: f220e028                 st      %i1, [%g3+0x28]
F006C2B8: f226a218                 st      %i1, [%i2+0x218]
F006C2BC: 05200000                 sethi   0x80000000, %g2
F006C2C0: c6062038                 ld      [%i0+0x38], %g3
F006C2C4: 333c043f                 sethi   %hi(_mfs_files_mapped), %i1
F006C2C8: 8428c002                 andn    %g3, %g2, %g2
F006C2CC: c4262038                 st      %g2, [%i0+0x38]
F006C2D0: c606612c                 ld      [%i1+%lo(_mfs_files_mapped)], %g3
F006C2D4: 313c043f                 sethi   %hi(_vm_info_version), %i0
F006C2D8: c4062118                 ld      [%i0+%lo(_vm_info_version)], %g2
F006C2DC: 8600ffff                 inc     -1, %g3
F006C2E0: c626612c                 st      %g3, [%i1+%lo(_mfs_files_mapped)]
F006C2E4: 8400a001                 inc     %g2
F006C2E8: c4262118                 st      %g2, [%i0+%lo(_vm_info_version)]
F006C2EC: 81c7e008                 ret
F006C2F0: 81e80000                 restore
