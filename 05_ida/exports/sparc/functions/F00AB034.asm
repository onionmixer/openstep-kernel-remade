F00AB034: 9de3bf98                 save    %sp, -0x68, %sp
F00AB038: 113c04d0                 sethi   %hi(_page_mask), %o0
F00AB03C: d20220d8                 ld      [%o0+%lo(_page_mask)], %o1
F00AB040: 94060019                 add     %i0, %i1, %o2
F00AB044: 113c04d1                 sethi   %hi(_kernel_map), %o0
F00AB048: 96380009                 xnor    %g0, %o1, %o3
F00AB04C: 94028009                 add     %o2, %o1, %o2
F00AB050: 920e000b                 and     %i0, %o3, %o1
F00AB054: d0022340                 ld      [%o0+%lo(_kernel_map)], %o0
F00AB058: 7fff68ba                 call    _vm_map_remove
F00AB05C: 940a800b                 and     %o2, %o3, %o2
F00AB060: 81c7e008                 ret
F00AB064: 81e80000                 restore
