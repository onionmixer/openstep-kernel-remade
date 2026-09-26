F006C208: 9de3bf98                 save    %sp, -0x68, %sp
F006C20C: b4100018                 mov     %i0, %i2
F006C210: 053c04f0                 sethi   %hi(dword_F013C21C), %g2
F006C214: c600a21c                 ld      [%g2+%lo(dword_F013C21C)], %g3
F006C218: b010a21c                 or      %g2, %lo(dword_F013C21C), %i0
F006C21C: 84063ffc                 add     %i0, -4, %g2
F006C220: 80a0c002                 cmp     %g3, %g2
F006C224: 32800003                 bne,a   loc_F006C230
F006C228: f420e028                 st      %i2, [%g3+0x28]
F006C22C: f4263ffc                 st      %i2, [%i0-4]
F006C230: c626a02c                 st      %g3, [%i2+0x2C]
F006C234: 053c04f08410a218         set     _vm_info_queue, %g2
F006C23C: c426a028                 st      %g2, [%i2+0x28]
F006C240: f420a004                 st      %i2, [%g2+4]
F006C244: c606a038                 ld      [%i2+0x38], %g3
F006C248: 05200000                 sethi   0x80000000, %g2
F006C24C: 8610c002                 bset    %g2, %g3
F006C250: 333c043f                 sethi   %hi(_mfs_files_mapped), %i1
F006C254: c626a038                 st      %g3, [%i2+0x38]
F006C258: f006612c                 ld      [%i1+%lo(_mfs_files_mapped)], %i0
F006C25C: 073c043f                 sethi   %hi(_vm_info_version), %g3
F006C260: c400e118                 ld      [%g3+%lo(_vm_info_version)], %g2
F006C264: b0062001                 inc     %i0
F006C268: f026612c                 st      %i0, [%i1+%lo(_mfs_files_mapped)]
F006C26C: 8400a001                 inc     %g2
F006C270: c420e118                 st      %g2, [%g3+%lo(_vm_info_version)]
F006C274: 81c7e008                 ret
F006C278: 81e80000                 restore
