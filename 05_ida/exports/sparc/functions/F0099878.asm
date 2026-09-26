F0099878: 9de3bf98                 save    %sp, -0x68, %sp
F009987C: 900e3000                 and     %i0, -0x1000, %o0
F0099880: 153c04f6                 sethi   %hi(_ioptes), %o2
F0099884: 13004000                 sethi   0x1000000, %o1
F0099888: b0060009                 add     %i0, %o1, %i0
F009988C: b136200c                 srl     %i0, 12, %i0
F0099890: d202a308                 ld      [%o2+%lo(_ioptes)], %o1
F0099894: b12e2002                 sll     %i0, 2, %i0
F0099898: 7ffff600                 call    _iommu_addr_flush
F009989C: c0224018                 clr     [%o1+%i0]
F00998A0: 81c7e008                 ret
F00998A4: 81e80000                 restore
