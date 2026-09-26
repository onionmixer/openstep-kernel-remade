F009751C: 2d3c000c                 sethi   %hi(_nwindows), %l6
F0097520: ec05a03c                 ld      [%l6+%lo(_nwindows)], %l6
F0097524: ac25a001                 dec     %l6
F0097528: a7500000                 rdpr    %tpc, %l3
F009752C: a92ce001                 sll     %l3, 1, %l4
F0097530: ab34c016                 srl     %l3, %l6, %l5
F0097534: aa154014                 bset    %l4, %l5
F0097538: 81954000                 wrpr    %l5, %g0, %tpc
F009753C: 808c2040                 btst    0x40, %l0 ! '@'
F0097540: 02800013                 be      loc_F009758C
F0097544: 81e80000                 restore
F0097548: 81e80000                 restore
F009754C: e01ba000                 ldd     [%sp+arg_0], %l0
F0097550: e41ba008                 ldd     [%sp+arg_8], %l2
F0097554: e81ba010                 ldd     [%sp+arg_10], %l4
F0097558: ec1ba018                 ldd     [%sp+arg_18], %l6
F009755C: f01ba020                 ldd     [%sp+arg_20], %i0
F0097560: f41ba028                 ldd     [%sp+arg_28], %i2
F0097564: f81ba030                 ldd     [%sp+arg_30], %i4
F0097568: fc1ba038                 ldd     [%sp+arg_38], %fp
F009756C: 81e00000                 save
F0097570: 81e00000                 save
F0097574: 818c0000                 saved
F0097578: 01000000                 nop
F009757C: 01000000                 nop
F0097580: 01000000                 nop
F0097584: 81c44000                 jmp     %l1
F0097588: 81cc8000                 return  %l2
F009758C: 81e80000                 restore
F0097590: 808ba007                 btst    7, %sp
F0097594: 02800007                 be      loc_F00975B0
F0097598: 01000000                 nop
F009759C: 81e00000                 save
F00975A0: 81e00000                 save
F00975A4: 8194c000                 wrpr    %l3, %g0, %tpc
F00975A8: 10bdaef2                 ba      sys_trap
F00975AC: a8102007                 mov     7, %l4
F00975B0: 293c0000                 sethi   -0x10000000, %l4
F00975B4: 80a5000e                 cmp     %l4, %sp
F00975B8: 08800006                 bleu    loc_F00975D0
F00975BC: 01000000                 nop
F00975C0: 293c045c                 sethi   %hi(_v_mmu_wu), %l4
F00975C4: e80522ec                 ld      [%l4+%lo(_v_mmu_wu)], %l4
F00975C8: 81c50000                 jmp     %l4
F00975CC: 01000000                 nop
F00975D0: 81e00000                 save
F00975D4: 81e00000                 save
F00975D8: a810200e                 mov     0xE, %l4
F00975DC: 10800005                 ba      loc_F00975F0
F00975E0: aa10000e                 mov     %sp, %l5
