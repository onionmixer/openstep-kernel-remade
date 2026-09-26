F00975E4: 808d2002                 btst    2, %l4
F00975E8: 02800028                 be      loc_F0097688
F00975EC: 01000000                 nop
F00975F0: 2d3c0428ac15a024         set     _active_pcb, %l6
F00975F8: ec058000                 ld      [%l6], %l6
F00975FC: ee05a2a0                 ld      [%l6+0x2A0], %l7
F0097600: c225a244                 st      %g1, [%l6+0x244]
F0097604: c43da248                 std     %g2, [%l6+0x248]
F0097608: c83da250                 std     %g4, [%l6+0x250]
F009760C: cc3da258                 std     %g6, [%l6+0x258]
F0097610: 83400000                 mov     %y, %g1
F0097614: c225a240                 st      %g1, [%l6+0x240]
F0097618: 81e80000                 restore
F009761C: 89480000                 rdhpr   %hpstate, %g4
F0097620: 81e00000                 save
F0097624: 9c100017                 mov     %l7, %sp
F0097628: f03da260                 std     %i0, [%l6+0x260]
F009762C: f43da268                 std     %i2, [%l6+0x268]
F0097630: f83da270                 std     %i4, [%l6+0x270]
F0097634: fc3da278                 std     %fp, [%l6+0x278]
F0097638: e025a234                 st      %l0, [%l6+0x234]
F009763C: e225a238                 st      %l1, [%l6+0x238]
F0097640: e425a23c                 st      %l2, [%l6+0x23C]
F0097644: 8194c000                 wrpr    %l3, %g0, %tpc
F0097648: 82102001                 mov     1, %g1
F009764C: 83284004                 sll     %g1, %g4, %g1
F0097650: c225a00c                 st      %g1, [%l6+0xC]
F0097654: c025a230                 clr     [%l6+0x230]
F0097658: 818c2020                 saved
F009765C: 01000000                 nop
F0097660: 01000000                 nop
F0097664: 01000000                 nop
F0097668: 90102009                 mov     9, %o0
F009766C: 9205a234                 add     %l6, 0x234, %o1
F0097670: 94100015                 mov     %l5, %o2
F0097674: 96100014                 mov     %l4, %o3
F0097678: 400044a6                 call    _trap
F009767C: 98102002                 mov     2, %o4
F0097680: e023a05c                 st      %l0, [%sp+arg_5C]
F0097684: 30bdaf87                 ba,a    sys_rtt
F0097688: 273c0428a614e024         set     _active_pcb, %l3
F0097690: e604c000                 ld      [%l3], %l3
F0097694: e604e294                 ld      [%l3+0x294], %l3
F0097698: aa100000                 clr     %l5
F009769C: 808ce001                 btst    1, %l3
F00976A0: 0280000e                 be      loc_F00976D8
F00976A4: 818c0000                 saved
F00976A8: 01000000                 nop
F00976AC: 01000000                 nop
F00976B0: 01000000                 nop
F00976B4: 9c100011                 mov     %l1, %sp
F00976B8: 9e100012                 mov     %l2, %o7
F00976BC: a0100000                 clr     %l0
F00976C0: a2100000                 clr     %l1
F00976C4: a4100000                 clr     %l2
F00976C8: a6100000                 clr     %l3
F00976CC: a8100000                 clr     %l4
F00976D0: 81c38000                 jmp     %sp+arg_0
F00976D4: 81cbc000                 return  %o7
F00976D8: 01000000                 nop
F00976DC: 81c44000                 jmp     %l1
F00976E0: 81cc8000                 return  %l2
