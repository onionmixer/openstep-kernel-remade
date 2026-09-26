F00998A8: 9de3bf98                 save    %sp, -0x68, %sp
F00998AC: 113c04f6                 sethi   %hi(_ioptes), %o0
F00998B0: d0022308                 ld      [%o0+%lo(_ioptes)], %o0
F00998B4: c0260000                 clr     [%i0]
F00998B8: b0260008                 sub     %i0, %o0, %i0
F00998BC: b13e2002                 sra     %i0, 2, %i0
F00998C0: b12e200c                 sll     %i0, 12, %i0
F00998C4: 113fc000                 sethi   -0x1000000, %o0
F00998C8: 7ffff5f4                 call    _iommu_addr_flush
F00998CC: 90060008                 add     %i0, %o0, %o0
F00998D0: 81c7e008                 ret
F00998D4: 81e80000                 restore
