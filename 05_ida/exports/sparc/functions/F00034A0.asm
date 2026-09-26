F00034A0: e003a05c                 ld      [%sp+arg_5C], %l0
F00034A4: 808c2040                 btst    0x40, %l0 ! '@'
F00034A8: 128000b6                 bne     loc_F0003780
F00034AC: 83480000                 rdhpr   %hpstate, %g1
F00034B0: 0b3c04288a116024         set     _active_pcb, %g5
F00034B8: ca014000                 ld      [%g5], %g5
F00034BC: e0016234                 ld      [%g5+0x234], %l0
F00034C0: 8208601f                 and     %g1, 0x1F, %g1
F00034C4: a02c201f                 bclr    0x1F, %l0
F00034C8: a0140001                 bset    %g1, %l0
F00034CC: 818c0000                 saved
F00034D0: 01000000                 nop
F00034D4: 01000000                 nop
F00034D8: 01000000                 nop
F00034DC: 053c04cf                 sethi   %hi(_need_ast), %g2
F00034E0: c400a160                 ld      [%g2+%lo(_need_ast)], %g2
F00034E4: 80908000                 tst     %g2
F00034E8: 0280000a                 be      loc_F0003510
F00034EC: 01000000                 nop
F00034F0: 818c2020                 saved
F00034F4: 01000000                 nop
F00034F8: 01000000                 nop
F00034FC: 01000000                 nop
F0003500: 40029ad8                 call    _check_for_ast
F0003504: 90016234                 add     %g5, 0x234, %o0
F0003508: 10bfffe6                 ba      sys_rtt
F000350C: 01000000                 nop
F0003510: c6016230                 ld      [%g5+0x230], %g3
F0003514: 8090c000                 tst     %g3
F0003518: 2280000b                 be,a    loc_F0003544
F000351C: e801600c                 ld      [%g5+0xC], %l4
F0003520: 818c0000                 saved
F0003524: 818c2020                 saved
F0003528: 01000000                 nop
F000352C: 01000000                 nop
F0003530: 01000000                 nop
F0003534: 90102005                 mov     5, %o0
F0003538: 400294f6                 call    _trap
F000353C: 92016234                 add     %g5, 0x234, %o1
F0003540: 30bfffd8                 ba,a    sys_rtt
F0003544: f0196260                 ldd     [%g5+0x260], %i0
F0003548: f4196268                 ldd     [%g5+0x268], %i2
F000354C: f8196270                 ldd     [%g5+0x270], %i4
F0003550: fc196278                 ldd     [%g5+0x278], %fp
F0003554: 80950000                 tst     %l4
F0003558: 12800038                 bne     loc_F0003638
F000355C: e2016238                 ld      [%g5+0x238], %l1
F0003560: 2d3c000c                 sethi   %hi(_nwindows), %l6
F0003564: ec05a03c                 ld      [%l6+%lo(_nwindows)], %l6
F0003568: ac25a001                 dec     %l6
F000356C: a7500000                 rdpr    %tpc, %l3
F0003570: a92ce001                 sll     %l3, 1, %l4
F0003574: ab34c016                 srl     %l3, %l6, %l5
F0003578: aa154014                 bset    %l4, %l5
F000357C: 81954000                 wrpr    %l5, %g0, %tpc
F0003580: 808fa007                 btst    7, %fp
F0003584: 0280000c                 be      loc_F00035B4
F0003588: 01000000                 nop
F000358C: 8194c000                 wrpr    %l3, %g0, %tpc
F0003590: 818c0000                 saved
F0003594: 818c2020                 saved
F0003598: 01000000                 nop
F000359C: 01000000                 nop
F00035A0: 01000000                 nop
F00035A4: 90102007                 mov     7, %o0
F00035A8: 400294da                 call    _trap
F00035AC: 92016234                 add     %g5, 0x234, %o1
F00035B0: 30bfffbc                 ba,a    sys_rtt
F00035B4: 033c0000                 sethi   -0x10000000, %g1
F00035B8: 80a0401e                 cmp     %g1, %fp
F00035BC: 18800005                 bgu     loc_F00035D0
F00035C0: 01000000                 nop
F00035C4: 8210200e                 mov     0xE, %g1
F00035C8: 10800009                 ba      loc_F00035EC
F00035CC: 8410001e                 mov     %fp, %g2
F00035D0: 033c045c                 sethi   %hi(_v_mmu_sys_unf), %g1
F00035D4: c20062e4                 ld      [%g1+%lo(_v_mmu_sys_unf)], %g1
F00035D8: 81c04000                 jmp     %g1
F00035DC: 01000000                 nop
F0003780: 0b3c000c                 sethi   %hi(_nwindows), %g5
F0003784: ca01603c                 ld      [%g5+%lo(_nwindows)], %g5
F0003788: fc03a0a0                 ld      [%sp+arg_A0], %fp
F000378C: 82184010                 btog    %l0, %g1
F0003790: 8088601f                 btst    0x1F, %g1
F0003794: 22800024                 be,a    loc_F0003824
F0003798: 818c0000                 saved
F000379C: 01000000                 nop
F00037A0: 01000000                 nop
F00037A4: 01000000                 nop
F00037A8: 86100010                 mov     %l0, %g3
F00037AC: 8810000e                 mov     %sp, %g4
F00037B0: f03ba020                 std     %i0, [%sp+arg_20]
F00037B4: f43ba028                 std     %i2, [%sp+arg_28]
F00037B8: f83ba030                 std     %i4, [%sp+arg_30]
F00037BC: fc3ba038                 std     %fp, [%sp+arg_38]
F00037C0: 8188c000                 saved
F00037C4: 01000000                 nop
F00037C8: 01000000                 nop
F00037CC: 01000000                 nop
F00037D0: 82102004                 mov     4, %g1
F00037D4: 83284003                 sll     %g1, %g3, %g1
F00037D8: 85304005                 srl     %g1, %g5, %g2
F00037DC: 82104002                 bset    %g2, %g1
F00037E0: 81904000                 wrpr    %g1, %g0, %tpc
F00037E4: 9c100004                 mov     %g4, %sp
F00037E8: f01ba020                 ldd     [%sp+arg_20], %i0
F00037EC: f41ba028                 ldd     [%sp+arg_28], %i2
F00037F0: f81ba030                 ldd     [%sp+arg_30], %i4
F00037F4: fc1ba038                 ldd     [%sp+arg_38], %fp
F00037F8: 81e80000                 restore
F00037FC: e01ba000                 ldd     [%sp+arg_0], %l0
F0003800: e41ba008                 ldd     [%sp+arg_8], %l2
F0003804: e81ba010                 ldd     [%sp+arg_10], %l4
F0003808: ec1ba018                 ldd     [%sp+arg_18], %l6
F000380C: f01ba020                 ldd     [%sp+arg_20], %i0
F0003810: f41ba028                 ldd     [%sp+arg_28], %i2
F0003814: f81ba030                 ldd     [%sp+arg_30], %i4
F0003818: fc1ba038                 ldd     [%sp+arg_38], %fp
F000381C: 1080001f                 ba      loc_F0003898
F0003820: 81e00000                 save
F0003824: 82102002                 mov     2, %g1
F0003828: 83284010                 sll     %g1, %l0, %g1
F000382C: 85304005                 srl     %g1, %g5, %g2
F0003830: 82104002                 bset    %g2, %g1
F0003834: 85500000                 rdpr    %tpc, %g2
F0003838: 80884002                 btst    %g2, %g1
F000383C: 02800017                 be      loc_F0003898
F0003840: 818c0000                 saved
F0003844: 01000000                 nop
F0003848: 01000000                 nop
F000384C: 01000000                 nop
F0003850: 8328a001                 sll     %g2, 1, %g1
F0003854: 8a216001                 dec     %g5
F0003858: 85308005                 srl     %g2, %g5, %g2
F000385C: 82104002                 bset    %g2, %g1
F0003860: 81904000                 wrpr    %g1, %g0, %tpc
F0003864: 01000000                 nop
F0003868: 01000000                 nop
F000386C: 01000000                 nop
F0003870: 81e80000                 restore
F0003874: e01ba000                 ldd     [%sp+arg_0], %l0
F0003878: e41ba008                 ldd     [%sp+arg_8], %l2
F000387C: e81ba010                 ldd     [%sp+arg_10], %l4
F0003880: ec1ba018                 ldd     [%sp+arg_18], %l6
F0003884: f01ba020                 ldd     [%sp+arg_20], %i0
F0003888: f41ba028                 ldd     [%sp+arg_28], %i2
F000388C: f81ba030                 ldd     [%sp+arg_30], %i4
F0003890: fc1ba038                 ldd     [%sp+arg_38], %fp
F0003894: 81e00000                 save
F0003898: c203a068                 ld      [%sp+arg_68], %g1
F000389C: 81804000                 mov     %g1, %y
F00038A0: c203a06c                 ld      [%sp+arg_6C], %g1
F00038A4: c41ba070                 ldd     [%sp+arg_70], %g2
F00038A8: c81ba078                 ldd     [%sp+arg_78], %g4
F00038AC: cc1ba080                 ldd     [%sp+arg_80], %g6
F00038B0: e203a060                 ld      [%sp+arg_60], %l1
F00038B4: e403a064                 ld      [%sp+arg_64], %l2
F00038B8: a4100012                 bset    %g0, %l2
F00038BC: 81c44000                 jmp     %l1
F00038C0: 81cc8000                 return  %l2
