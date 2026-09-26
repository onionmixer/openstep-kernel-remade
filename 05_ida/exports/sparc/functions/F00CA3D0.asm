F00CA3D0: 9de3bf98                 save    %sp, -0x68, %sp
F00CA3D4: 7fff0851                 call    __io_vm_task_self
F00CA3D8: 01000000                 nop
F00CA3DC: 9210001a                 mov     %i2, %o1! address
F00CA3E0: 94100019                 mov     %i1, %o2! size
F00CA3E4: 7fff010f                 call    _vm_allocate
F00CA3E8: 96102001                 mov     1, %o3
F00CA3EC: 80a22000                 cmp     %o0, 0
F00CA3F0: 02800004                 be      loc_F00CA400
F00CA3F4: 113c04d0                 sethi   -0xFECC000, %o0
F00CA3F8: 1080001a                 ba      locret_F00CA460
F00CA3FC: b0103d25                 mov     -0x2DB, %i0
F00CA400: d20220d8                 ld      [%o0+0xD8], %o1
F00CA404: f4068000                 ld      [%i2], %i2
F00CA408: 90380009                 xnor    %g0, %o1, %o0
F00CA40C: b40e8008                 and     %i2, %o0, %i2
F00CA410: 92064009                 add     %i1, %o1, %o1
F00CA414: b28a4008                 andcc   %o1, %o0, %i1
F00CA418: 02800011                 be      loc_F00CA45C
F00CA41C: b00e0008                 and     %i0, %o0, %i0
F00CA420: 213c0447                 sethi   -0xFEEE400, %l0
F00CA424: 7fff083d                 call    __io_vm_task_self
F00CA428: 01000000                 nop
F00CA42C: 7fff084c                 call    __io_vm_task_pmap
F00CA430: 01000000                 nop
F00CA434: 9210001a                 mov     %i2, %o1
F00CA438: 94100018                 mov     %i0, %o2
F00CA43C: 96102003                 mov     3, %o3
F00CA440: 7fff501b                 call    _pmap_enter
F00CA444: 98102001                 mov     1, %o4
F00CA448: d004213c                 ld      [%l0+0x13C], %o0
F00CA44C: b4068008                 add     %i2, %o0, %i2
F00CA450: b2a64008                 subcc   %i1, %o0, %i1
F00CA454: 12bffff4                 bne     loc_F00CA424
F00CA458: b0060008                 add     %i0, %o0, %i0
F00CA45C: b0102000                 mov     0, %i0
F00CA460: 81c7e008                 ret
F00CA464: 81e80000                 restore
