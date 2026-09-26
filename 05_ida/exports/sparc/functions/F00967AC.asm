F00967AC: 2d3c000c                 sethi   %hi(_nwindows), %l6
F00967B0: ec05a03c                 ld      [%l6+%lo(_nwindows)], %l6
F00967B4: ac25a001                 dec     %l6
F00967B8: a7500000                 rdpr    %tpc, %l3
F00967BC: ae100001                 mov     %g1, %l7
F00967C0: aa100002                 mov     %g2, %l5
F00967C4: 8334e001                 srl     %l3, 1, %g1
F00967C8: a92cc016                 sll     %l3, %l6, %l4
F00967CC: 808c2040                 btst    0x40, %l0 ! '@'
F00967D0: 02800020                 be      loc_F0096850
F00967D4: 82150001                 bset    %l4, %g1
F00967D8: 053c04288410a024         set     _active_pcb, %g2
F00967E0: c4008000                 ld      [%g2], %g2
F00967E4: e800a00c                 ld      [%g2+0xC], %l4
F00967E8: 80950000                 tst     %l4
F00967EC: 32800015                 bne,a   loc_F0096840
F00967F0: a82d0001                 bclr    %g1, %l4
F00967F4: 81e00000                 save
F00967F8: 81904000                 wrpr    %g1, %g0, %tpc
F00967FC: e03ba000                 std     %l0, [%sp+arg_0]
F0096800: e43ba008                 std     %l2, [%sp+arg_8]
F0096804: e83ba010                 std     %l4, [%sp+arg_10]
F0096808: ec3ba018                 std     %l6, [%sp+arg_18]
F009680C: f03ba020                 std     %i0, [%sp+arg_20]
F0096810: f43ba028                 std     %i2, [%sp+arg_28]
F0096814: f83ba030                 std     %i4, [%sp+arg_30]
F0096818: fc3ba038                 std     %fp, [%sp+arg_38]
F009681C: 81e80000                 restore
F0096820: 84100015                 mov     %l5, %g2
F0096824: 818c0000                 saved
F0096828: 01000000                 nop
F009682C: 01000000                 nop
F0096830: 01000000                 nop
F0096834: 82100017                 mov     %l7, %g1
F0096838: 81c44000                 jmp     %l1
F009683C: 81cc8000                 return  %l2
F0096840: 053c04288410a024         set     _active_pcb, %g2
F0096848: c4008000                 ld      [%g2], %g2
F009684C: e820a00c                 st      %l4, [%g2+0xC]
F0096850: a8100003                 mov     %g3, %l4
F0096854: 81e00000                 save
F0096858: 81904000                 wrpr    %g1, %g0, %tpc
F009685C: 808ba007                 btst    7, %sp
F0096860: 0280000d                 be      loc_F0096894
F0096864: 01000000                 nop
F0096868: 83480000                 rdhpr   %hpstate, %g1
F009686C: 80886040                 btst    0x40, %g1 ! '@'
F0096870: 12800063                 bne     loc_F00969FC
F0096874: 01000000                 nop
F0096878: 81e80000                 restore
F009687C: 86100014                 mov     %l4, %g3
F0096880: 84100015                 mov     %l5, %g2
F0096884: 82100017                 mov     %l7, %g1
F0096888: 8194c000                 wrpr    %l3, %g0, %tpc
F009688C: 10bdb239                 ba      sys_trap
F0096890: a8102007                 mov     7, %l4
F0096894: 033c0000                 sethi   -0x10000000, %g1
F0096898: 80a0400e                 cmp     %g1, %sp
F009689C: 8210208e                 mov     0x8E, %g1
F00968A0: 08800009                 bleu    loc_F00968C4
F00968A4: 8410000e                 mov     %sp, %g2
F00968A8: 033c045c                 sethi   %hi(_v_mmu_wo), %g1
F00968AC: c20062e8                 ld      [%g1+%lo(_v_mmu_wo)], %g1
F00968B0: 81c04000                 jmp     %g1
F00968B4: 01000000                 nop
