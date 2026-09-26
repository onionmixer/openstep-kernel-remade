F0006F88: a7500000                 rdpr    %tpc, %l3
F0006F8C: aa102001                 mov     1, %l5
F0006F90: ab2d4010                 sll     %l5, %l0, %l5
F0006F94: 808d4013                 btst    %l3, %l5
F0006F98: 12bff076                 bne     sys_trap
F0006F9C: a8102002                 mov     2, %l4
F0006FA0: e8044000                 ld      [%l1], %l4
F0006FA4: af35201e                 srl     %l4, 30, %l7
F0006FA8: 80a5e002                 cmp     %l7, 2
F0006FAC: 32bff071                 bne,a   sys_trap
F0006FB0: a8102002                 mov     2, %l4
F0006FB4: 2f3c0429ae15e3c0         set     unk_F010A7C0, %l7
F0006FBC: c43dc000                 std     %g2, [%l7]
F0006FC0: c225e008                 st      %g1, [%l7+8]
F0006FC4: a735200d                 srl     %l4, 13, %l3
F0006FC8: a68ce001                 andcc   %l3, 1, %l3
F0006FCC: 02800004                 be      loc_F0006FDC
F0006FD0: 932d2013                 sll     %l4, 19, %o1
F0006FD4: 10800005                 ba      loc_F0006FE8
F0006FD8: 933a6013                 sra     %o1, 19, %o1
F0006FDC: 4000004e                 call    sub_F0007114
F0006FE0: 900d201f                 and     %l4, 0x1F, %o0
F0006FE4: 92100008                 mov     %o0, %o1
F0006FE8: 9135200e                 srl     %l4, 14, %o0
F0006FEC: 4000004a                 call    sub_F0007114
F0006FF0: 900a201f                 and     %o0, 0x1F, %o0
F0006FF4: ab352013                 srl     %l4, 19, %l5
F0006FF8: aa0d603f                 and     %l5, 0x3F, %l5
F0006FFC: 80a5600a                 cmp     %l5, 0xA
F0007000: 12800009                 bne     loc_F0007024
F0007004: 80a5600b                 cmp     %l5, 0xB
F0007008: 7ffffd3e                 call    _umul
F000700C: 01000000                 nop
F0007010: 81824000                 mov     %o1, %y
F0007014: 95352019                 srl     %l4, 25, %o2
F0007018: 40000070                 call    sub_F00071D8
F000701C: 940aa01f                 and     %o2, 0x1F, %o2
F0007020: 30800035                 ba,a    loc_F00070F4
F0007024: 12800009                 bne     loc_F0007048
F0007028: 80a5601a                 cmp     %l5, 0x1A
F000702C: 7ffffcee                 call    _mul
F0007030: 01000000                 nop
F0007034: 81824000                 mov     %o1, %y
F0007038: 95352019                 srl     %l4, 25, %o2
F000703C: 40000067                 call    sub_F00071D8
F0007040: 940aa01f                 and     %o2, 0x1F, %o2
F0007044: 3080002c                 ba,a    loc_F00070F4
F0007048: 12800013                 bne     loc_F0007094
F000704C: 80a5601b                 cmp     %l5, 0x1B
F0007050: 7ffffd2c                 call    _umul
F0007054: 01000000                 nop
F0007058: 81824000                 mov     %o1, %y
F000705C: 95352019                 srl     %l4, 25, %o2
F0007060: 4000005e                 call    sub_F00071D8
F0007064: 940aa01f                 and     %o2, 0x1F, %o2
F0007068: 9932201f                 srl     %o0, 31, %o4
F000706C: 992b2003                 sll     %o4, 3, %o4
F0007070: 80920000                 tst     %o0
F0007074: 22800002                 be,a    loc_F000707C
F0007078: 98132004                 bset    4, %o4
F000707C: 80924000                 tst     %o1
F0007080: 992b2014                 sll     %o4, 20, %o4
F0007084: 17003c00                 sethi   0xF00000, %o3
F0007088: a02c000b                 bclr    %o3, %l0
F000708C: a014000c                 bset    %o4, %l0
F0007090: 30800019                 ba,a    loc_F00070F4
F0007094: 12800012                 bne     loc_F00070DC
F0007098: 80924000                 tst     %o1
F000709C: 7ffffcd2                 call    _mul
F00070A0: 01000000                 nop
F00070A4: 81824000                 mov     %o1, %y
F00070A8: 95352019                 srl     %l4, 25, %o2
F00070AC: 4000004b                 call    sub_F00071D8
F00070B0: 940aa01f                 and     %o2, 0x1F, %o2
F00070B4: 9732201f                 srl     %o0, 31, %o3
F00070B8: 992ae003                 sll     %o3, 3, %o4
F00070BC: 80920000                 tst     %o0
F00070C0: 22800002                 be,a    loc_F00070C8
F00070C4: 98132004                 bset    4, %o4
F00070C8: 992b2014                 sll     %o4, 20, %o4
F00070CC: 17003c00                 sethi   0xF00000, %o3
F00070D0: a02c000b                 bclr    %o3, %l0
F00070D4: a014000c                 bset    %o4, %l0
F00070D8: 30800007                 ba,a    loc_F00070F4
F00070DC: 2f3c0429ae15e3c0         set     unk_F010A7C0, %l7
F00070E4: c41dc000                 ldd     [%l7], %g2
F00070E8: c205e008                 ld      [%l7+8], %g1
F00070EC: 10bff021                 ba      sys_trap
F00070F0: a8102002                 mov     2, %l4
F00070F4: 2f3c0429ae15e3c0         set     unk_F010A7C0, %l7
F00070FC: c41dc000                 ldd     [%l7], %g2
F0007100: c205e008                 ld      [%l7+8], %g1
F0007104: 818c0000                 saved
F0007108: 01000000                 nop
F000710C: 81c48000                 jmp     %l2
F0007110: 81cca004                 return  %l2+4
