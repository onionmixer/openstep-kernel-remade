F0098140: 9de3bf98                 save    %sp, -0x68, %sp
F0098144: a2102000                 mov     0, %l1
F0098148: 40005ccc                 call    _prom_nextnode
F009814C: 90102000                 mov     0, %o0
F0098150: 92102000                 mov     0, %o1
F0098154: 4000001f                 call    sub_F00981D0
F0098158: 94102000                 mov     0, %o2
F009815C: 113c044b                 sethi   %hi(off_F0112DF4), %o0! "iommu"
F0098160: d20221f4                 ld      [%o0+%lo(off_F0112DF4)], %o1! "iommu"
F0098164: 80a26000                 cmp     %o1, 0
F0098168: 02800010                 be      loc_F00981A8
F009816C: a01221f4                 or      %o0, %lo(off_F0112DF4), %l0! "iommu"
F0098170: 253c044b                 sethi   -0xFEED400, %l2
F0098174: d0042008                 ld      [%l0+8], %o0
F0098178: 808a2006                 btst    6, %o0
F009817C: 32800007                 bne,a   loc_F0098198
F0098180: a004200c                 inc     0xC, %l0
F0098184: 9014a2a0                 or      %l2, 0x2A0, %o0
F0098188: d2040000                 ld      [%l0], %o1
F009818C: 40005d7b                 call    _prom_printf
F0098190: a2046001                 inc     %l1
F0098194: a004200c                 inc     0xC, %l0
F0098198: d0040000                 ld      [%l0], %o0
F009819C: 80a22000                 cmp     %o0, 0
F00981A0: 32bffff6                 bne,a   loc_F0098178
F00981A4: d0042008                 ld      [%l0+8], %o0
F00981A8: 80a46000                 cmp     %l1, 0
F00981AC: 02800004                 be      loc_F00981BC
F00981B0: 113c044b                 sethi   %hi(aMapWellknownDe), %o0! "map_wellknown_devices"
F00981B4: 7ffdf3ef                 call    _panic
F00981B8: 901222c0                 bset    %lo(aMapWellknownDe), %o0! "map_wellknown_devices"
F00981BC: 133c04f6                 sethi   %hi(_utimersp), %o1
F00981C0: 113fbfe4                 sethi   -0x1007000, %o0
F00981C4: d02261e8                 st      %o0, [%o1+%lo(_utimersp)]
F00981C8: 81c7e008                 ret
F00981CC: 81e80000                 restore
