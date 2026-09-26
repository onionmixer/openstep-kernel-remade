F00968B8: 80886002                 btst    2, %g1
F00968BC: 02800075                 be      loc_F0096A90
F00968C0: 01000000                 nop
F00968C4: 87480000                 rdhpr   %hpstate, %g3
F00968C8: 8088e040                 btst    0x40, %g3 ! '@'
F00968CC: 1280004c                 bne     loc_F00969FC
F00968D0: 01000000                 nop
F00968D4: 073c04288610e024         set     _active_pcb, %g3
F00968DC: c600c000                 ld      [%g3], %g3
F00968E0: dc20e210                 st      %sp, [%g3+0x210]
F00968E4: e038e010                 std     %l0, [%g3+0x10]
F00968E8: e438e018                 std     %l2, [%g3+0x18]
F00968EC: e838e020                 std     %l4, [%g3+0x20]
F00968F0: ec38e028                 std     %l6, [%g3+0x28]
F00968F4: f038e030                 std     %i0, [%g3+0x30]
F00968F8: f438e038                 std     %i2, [%g3+0x38]
F00968FC: f838e040                 std     %i4, [%g3+0x40]
F0096900: fc38e048                 std     %fp, [%g3+0x48]
F0096904: 81e80000                 restore
F0096908: 87500000                 rdpr    %tpc, %g3
F009690C: 8610c013                 bset    %l3, %g3
F0096910: 8638c000                 not     %g3
F0096914: a6103ffe                 mov     -2, %l3
F0096918: a72cc016                 sll     %l3, %l6, %l3
F009691C: 8628c013                 bclr    %l3, %g3
F0096920: 273c0428a614e024         set     _active_pcb, %l3
F0096928: e604c000                 ld      [%l3], %l3
F009692C: c624e00c                 st      %g3, [%l3+0xC]
F0096930: 86102001                 mov     1, %g3
F0096934: c624e230                 st      %g3, [%l3+0x230]
F0096938: dc04e2a0                 ld      [%l3+0x2A0], %sp
F009693C: 86100014                 mov     %l4, %g3
F0096940: a8100001                 mov     %g1, %l4
F0096944: ac100002                 mov     %g2, %l6
F0096948: 82100017                 mov     %l7, %g1
F009694C: 84100015                 mov     %l5, %g2
F0096950: 808c2040                 btst    0x40, %l0 ! '@'
F0096954: 12800012                 bne     loc_F009699C
F0096958: 01000000                 nop
F009695C: c224e244                 st      %g1, [%l3+0x244]
F0096960: c43ce248                 std     %g2, [%l3+0x248]
F0096964: c83ce250                 std     %g4, [%l3+0x250]
F0096968: cc3ce258                 std     %g6, [%l3+0x258]
F009696C: 83400000                 mov     %y, %g1
F0096970: c224e240                 st      %g1, [%l3+0x240]
F0096974: f03ce260                 std     %i0, [%l3+0x260]
F0096978: f43ce268                 std     %i2, [%l3+0x268]
F009697C: f83ce270                 std     %i4, [%l3+0x270]
F0096980: fc3ce278                 std     %fp, [%l3+0x278]
F0096984: e024e234                 st      %l0, [%l3+0x234]
F0096988: e224e238                 st      %l1, [%l3+0x238]
F009698C: e424e23c                 st      %l2, [%l3+0x23C]
F0096990: e023a05c                 st      %l0, [%sp+arg_5C]
F0096994: 10800010                 ba      loc_F00969D4
F0096998: 9204e234                 add     %l3, 0x234, %o1
F009699C: c223a06c                 st      %g1, [%sp+arg_6C]
F00969A0: c43ba070                 std     %g2, [%sp+arg_70]
F00969A4: c83ba078                 std     %g4, [%sp+arg_78]
F00969A8: cc3ba080                 std     %g6, [%sp+arg_80]
F00969AC: 83400000                 mov     %y, %g1
F00969B0: c223a068                 st      %g1, [%sp+arg_68]
F00969B4: f03ba088                 std     %i0, [%sp+arg_88]
F00969B8: f43ba090                 std     %i2, [%sp+arg_90]
F00969BC: f83ba098                 std     %i4, [%sp+arg_98]
F00969C0: fc3ba0a0                 std     %fp, [%sp+arg_A0]
F00969C4: e023a05c                 st      %l0, [%sp+arg_5C]
F00969C8: e223a060                 st      %l1, [%sp+arg_60]
F00969CC: e423a064                 st      %l2, [%sp+arg_64]
F00969D0: 9203a05c                 add     %sp, arg_5C, %o1
F00969D4: 818c2020                 saved
F00969D8: 01000000                 nop
F00969DC: 01000000                 nop
F00969E0: 01000000                 nop
F00969E4: 90102009                 mov     9, %o0
F00969E8: 94100016                 mov     %l6, %o2
F00969EC: 96100014                 mov     %l4, %o3
F00969F0: 400047c8                 call    _trap
F00969F4: 98102002                 mov     2, %o4
F00969F8: 30bdb2aa                 ba,a    sys_rtt
F00969FC: 053c04288410a024         set     _active_pcb, %g2
F0096A04: c4008000                 ld      [%g2], %g2
F0096A08: c200a230                 ld      [%g2+0x230], %g1
F0096A0C: 83286002                 sll     %g1, 2, %g1
F0096A10: 82004002                 add     %g1, %g2, %g1
F0096A14: dc206210                 st      %sp, [%g1+0x210]
F0096A18: 82204002                 sub     %g1, %g2, %g1
F0096A1C: 83286004                 sll     %g1, 4, %g1
F0096A20: 8400a010                 inc     0x10, %g2
F0096A24: 82004002                 add     %g1, %g2, %g1
F0096A28: e0386000                 std     %l0, [%g1]
F0096A2C: e4386008                 std     %l2, [%g1+8]
F0096A30: e8386010                 std     %l4, [%g1+0x10]
F0096A34: ec386018                 std     %l6, [%g1+0x18]
F0096A38: f0386020                 std     %i0, [%g1+0x20]
F0096A3C: f4386028                 std     %i2, [%g1+0x28]
F0096A40: f8386030                 std     %i4, [%g1+0x30]
F0096A44: fc386038                 std     %fp, [%g1+0x38]
F0096A48: 82204002                 sub     %g1, %g2, %g1
F0096A4C: 8420a010                 dec     0x10, %g2
F0096A50: 83306006                 srl     %g1, 6, %g1
F0096A54: 82006001                 inc     %g1
F0096A58: 053c04288410a024         set     _active_pcb, %g2
F0096A60: c4008000                 ld      [%g2], %g2
F0096A64: c220a230                 st      %g1, [%g2+0x230]
F0096A68: 81e80000                 restore
F0096A6C: 818c0000                 saved
F0096A70: 01000000                 nop
F0096A74: 01000000                 nop
F0096A78: 01000000                 nop
F0096A7C: 82100017                 mov     %l7, %g1
F0096A80: 84100015                 mov     %l5, %g2
F0096A84: 86100014                 mov     %l4, %g3
F0096A88: 81c44000                 jmp     %l1
F0096A8C: 81cc8000                 return  %l2
F0096A90: 81e80000                 restore
F0096A94: 273c0428a614e024         set     _active_pcb, %l3
F0096A9C: e604c000                 ld      [%l3], %l3
F0096AA0: 84100015                 mov     %l5, %g2
F0096AA4: e604e294                 ld      [%l3+0x294], %l3
F0096AA8: 82100017                 mov     %l7, %g1
F0096AAC: 86100014                 mov     %l4, %g3
F0096AB0: 808ce001                 btst    1, %l3
F0096AB4: 02800017                 be      loc_F0096B10
F0096AB8: 818c0000                 saved
F0096ABC: 01000000                 nop
F0096AC0: 01000000                 nop
F0096AC4: 01000000                 nop
F0096AC8: 9c100011                 mov     %l1, %sp
F0096ACC: 9e100012                 mov     %l2, %o7
F0096AD0: a0100000                 clr     %l0
F0096AD4: a2100000                 clr     %l1
F0096AD8: a4100000                 clr     %l2
F0096ADC: a6100000                 clr     %l3
F0096AE0: a8100000                 clr     %l4
F0096AE4: aa100000                 clr     %l5
F0096AE8: ac100000                 clr     %l6
F0096AEC: ae100000                 clr     %l7
F0096AF0: 90100000                 clr     %o0
F0096AF4: 92100000                 clr     %o1
F0096AF8: 94100000                 clr     %o2
F0096AFC: 96100000                 clr     %o3
F0096B00: 98100000                 clr     %o4
F0096B04: 9a100000                 clr     %o5
F0096B08: 81c38000                 jmp     %sp+arg_0
F0096B0C: 81cbc000                 return  %o7
F0096B10: 01000000                 nop
F0096B14: 81c44000                 jmp     %l1
F0096B18: 81cc8000                 return  %l2
