F0083AA4: 9de3bf90                 save    %sp, -0x70, %sp
F0083AA8: 40006f23                 call    _pmap_kernel
F0083AAC: 01000000                 nop
F0083AB0: 133c0000                 sethi   -0x10000000, %o1
F0083AB4: 94100019                 mov     %i1, %o2
F0083AB8: 4000017e                 call    _vm_map_create
F0083ABC: 96102000                 mov     0, %o3
F0083AC0: 133c04d1                 sethi   %hi(_kernel_map), %o1
F0083AC4: d0226340                 st      %o0, [%o1+%lo(_kernel_map)]
F0083AC8: 133c0000                 sethi   -0x10000000, %o1
F0083ACC: d227bff4                 st      %o1, [%fp+var_C]
F0083AD0: 92102000                 mov     0, %o1
F0083AD4: 94102000                 mov     0, %o2
F0083AD8: 9607bff4                 add     %fp, var_C, %o3
F0083ADC: 19040000                 sethi   0x10000000, %o4
F0083AE0: 9806000c                 add     %i0, %o4, %o4
F0083AE4: 400002bb                 call    _vm_map_find
F0083AE8: 9a102000                 mov     0, %o5
F0083AEC: 81c7e008                 ret
F0083AF0: 81e80000                 restore
