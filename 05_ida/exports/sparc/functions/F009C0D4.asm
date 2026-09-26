F009C0D4: 9de3bf98                 save    %sp, -0x68, %sp
F009C0D8: d0062024                 ld      [%i0+0x24], %o0
F009C0DC: d2062020                 ld      [%i0+0x20], %o1
F009C0E0: 9022001b                 sub     %o0, %i3, %o0
F009C0E4: d0262024                 st      %o0, [%i0+0x24]
F009C0E8: 9222401a                 sub     %o1, %i2, %o1
F009C0EC: d0062024                 ld      [%i0+0x24], %o0
F009C0F0: 80a22000                 cmp     %o0, 0
F009C0F4: 06800005                 bl      loc_F009C108
F009C0F8: d2262020                 st      %o1, [%i0+0x20]
F009C0FC: 80a26000                 cmp     %o1, 0
F009C100: 16800005                 bge     locret_F009C114
F009C104: 01000000                 nop
F009C108: 113c045e                 sethi   %hi(aPmapDeallocate), %o0! "pmap_deallocate_mappings"
F009C10C: 7ffde419                 call    _panic
F009C110: 90122310                 bset    %lo(aPmapDeallocate), %o0! "pmap_deallocate_mappings"
F009C114: 81c7e008                 ret
F009C118: 81e80000                 restore
