F0095580: 818c2020                 saved
F0095584: 2f3c0254ae15e14c         set     loc_F009514C, %l7
F009558C: 80a44017                 cmp     %l1, %l7
F0095590: 1280000c                 bne     loc_F00955C0
F0095594: 2b000004                 sethi   0x1000, %l5
F0095598: 2d3c044a                 sethi   %hi(_fpu_exists), %l6
F009559C: c025a0c8                 clr     [%l6+%lo(_fpu_exists)]
F00955A0: ec03a05c                 ld      [%sp+arg_5C], %l6
F00955A4: ac2d8015                 bclr    %l5, %l6
F00955A8: ec23a05c                 st      %l6, [%sp+arg_5C]
F00955AC: ec03a064                 ld      [%sp+arg_64], %l6
F00955B0: ec23a060                 st      %l6, [%sp+arg_60]
F00955B4: ac05a004                 inc     4, %l6
F00955B8: 10bdb7ba                 ba      sys_rtt
F00955BC: ec23a064                 st      %l6, [%sp+arg_64]
F00955C0: 2f3c0428ae15e024         set     _active_pcb, %l7
F00955C8: ee05c000                 ld      [%l7], %l7
F00955CC: 40000dc8                 call    _fp_is_disabled
F00955D0: 9005e234                 add     %l7, 0x234, %o0
F00955D4: 10bdb7b3                 ba      sys_rtt
F00955D8: 01000000                 nop
