F0078BF0: 9de3bf98                 save    %sp, -0x68, %sp
F0078BF4: 113c04d1                 sethi   %hi(_kernel_map), %o0
F0078BF8: 133c04f2                 sethi   %hi(_zone_min), %o1
F0078BFC: 153c04f2                 sethi   %hi(_zone_max), %o2
F0078C00: 173c0442                 sethi   %hi(_zone_map_size), %o3
F0078C04: 921263e0                 bset    %lo(_zone_min), %o1
F0078C08: d0022340                 ld      [%o0+%lo(_kernel_map)], %o0
F0078C0C: 9412a3d8                 bset    %lo(_zone_max), %o2
F0078C10: d602e3f0                 ld      [%o3+%lo(_zone_map_size)], %o3
F0078C14: 40002b6f                 call    _kmem_suballoc
F0078C18: 98102000                 mov     0, %o4
F0078C1C: 133c0442                 sethi   %hi(_zone_map), %o1
F0078C20: d02263ec                 st      %o0, [%o1+%lo(_zone_map)]
F0078C24: 81c7e008                 ret
F0078C28: 81e80000                 restore
