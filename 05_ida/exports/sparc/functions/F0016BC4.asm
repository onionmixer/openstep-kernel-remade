F0016BC4: 9de3bf88                 save    %sp, -0x78, %sp
F0016BC8: 40001148                 call    _ttynty
F0016BCC: 90100018                 mov     %i0, %o0
F0016BD0: 1320019d92126011         set     -0x7FF98BEF, %o1
F0016BD8: 80a64009                 cmp     %i1, %o1
F0016BDC: ea562038                 ldsh    [%i0+0x38], %l5
F0016BE0: 02800053                 be      loc_F0016D2C
F0016BE4: a2100008                 mov     %o0, %l1
F0016BE8: 80a64009                 cmp     %i1, %o1
F0016BEC: 14800024                 bg      loc_F0016C7C
F0016BF0: 1108001d                 sethi   0x20007400, %o0
F0016BF4: 1120011d90122076         set     -0x7FFB8B8A, %o0
F0016BFC: 80a64008                 cmp     %i1, %o0
F0016C00: 0280004c                 be      loc_F0016D30
F0016C04: 273c04cf                 sethi   %hi(_active_u), %l3
F0016C08: 1480000e                 bg      loc_F0016C40
F0016C0C: 1120011d                 sethi   -0x7FFB8C00, %o0
F0016C10: 1120011d90122001         set     -0x7FFB8BFF, %o0
F0016C18: 80a64008                 cmp     %i1, %o0
F0016C1C: 22800046                 be,a    loc_F0016D34
F0016C20: d204e1d8                 ld      [%l3+%lo(_active_u)], %o1
F0016C24: 34800005                 bg,a    loc_F0016C38
F0016C28: 1120011d                 sethi   -0x7FFB8C00, %o0
F0016C2C: 1120005d                 sethi   -0x7FFE8C00, %o0
F0016C30: 10800022                 ba      loc_F0016CB8
F0016C34: 90122072                 bset    0x72, %o0 ! 'r'
F0016C38: 10800020                 ba      loc_F0016CB8
F0016C3C: 90122010                 bset    0x10, %o0
F0016C40: 9012207d                 bset    0x7D, %o0 ! '}'
F0016C44: 80a64008                 cmp     %i1, %o0
F0016C48: 0680005d                 bl      loc_F0016DBC
F0016C4C: 1120011d                 sethi   -0x7FFB8C00, %o0
F0016C50: 9012207f                 bset    0x7F, %o0
F0016C54: 80a64008                 cmp     %i1, %o0
F0016C58: 04800035                 ble     loc_F0016D2C
F0016C5C: 1120019d                 sethi   -0x7FF98C00, %o0
F0016C60: 9012200a                 bset    0xA, %o0
F0016C64: 80a64008                 cmp     %i1, %o0
F0016C68: 34800056                 bg,a    loc_F0016DC0
F0016C6C: 1108001d                 sethi   0x20007400, %o0
F0016C70: 1120019d                 sethi   -0x7FF98C00, %o0
F0016C74: 1080002b                 ba      loc_F0016D20
F0016C78: 90122009                 bset    9, %o0
F0016C7C: 9012205e                 bset    0x5E, %o0 ! '^'
F0016C80: 80a64008                 cmp     %i1, %o0
F0016C84: 0280002b                 be      loc_F0016D30
F0016C88: 273c04cf                 sethi   %hi(_active_u), %l3
F0016C8C: 14800017                 bg      loc_F0016CE8
F0016C90: 1108001d                 sethi   0x20007400, %o0
F0016C94: 1120021d90122067         set     -0x7FF78B99, %o0
F0016C9C: 80a64008                 cmp     %i1, %o0
F0016CA0: 02800025                 be      loc_F0016D34
F0016CA4: d204e1d8                 ld      [%l3+%lo(_active_u)], %o1
F0016CA8: 14800009                 bg      loc_F0016CCC
F0016CAC: 1120091d                 sethi   -0x7FDB8C00, %o0
F0016CB0: 1120019d90122075         set     -0x7FF98B8B, %o0
F0016CB8: 80a64008                 cmp     %i1, %o0
F0016CBC: 2280001d                 be,a    loc_F0016D30
F0016CC0: 273c04cf                 sethi   -0xFECC400, %l3
F0016CC4: 1080003f                 ba      loc_F0016DC0
F0016CC8: 1108001d                 sethi   0x20007400, %o0
F0016CCC: 90122016                 bset    0x16, %o0
F0016CD0: 80a64008                 cmp     %i1, %o0
F0016CD4: 3480003b                 bg,a    loc_F0016DC0
F0016CD8: 1108001d                 sethi   0x20007400, %o0
F0016CDC: 1120091d                 sethi   -0x7FDB8C00, %o0
F0016CE0: 10800010                 ba      loc_F0016D20
F0016CE4: 90122014                 bset    0x14, %o0
F0016CE8: 9012206e                 bset    0x6E, %o0 ! 'n'
F0016CEC: 80a64008                 cmp     %i1, %o0
F0016CF0: 06800033                 bl      loc_F0016DBC
F0016CF4: 1108001d                 sethi   0x20007400, %o0
F0016CF8: 9012206f                 bset    0x6F, %o0 ! 'o'
F0016CFC: 80a64008                 cmp     %i1, %o0
F0016D00: 0480000b                 ble     loc_F0016D2C
F0016D04: 1108001d                 sethi   0x20007400, %o0
F0016D08: 9012207b                 bset    0x7B, %o0 ! '{'
F0016D0C: 80a64008                 cmp     %i1, %o0
F0016D10: 1480002c                 bg      loc_F0016DC0
F0016D14: 1108001d                 sethi   0x20007400, %o0
F0016D18: 1108001d9012207a         set     0x2000747A, %o0
F0016D20: 80a64008                 cmp     %i1, %o0
F0016D24: 06800027                 bl      loc_F0016DC0
F0016D28: 1108001d                 sethi   0x20007400, %o0
F0016D2C: 273c04cf                 sethi   -0xFECC400, %l3
F0016D30: d204e1d8                 ld      [%l3+0x1D8], %o1
F0016D34: d0562044                 ldsh    [%i0+0x44], %o0
F0016D38: 25000004                 sethi   0x1000, %l2
F0016D3C: d4024000                 ld      [%o1], %o2
F0016D40: 21000800                 sethi   0x200000, %l0
F0016D44: d652a02e                 ldsh    [%o2+0x2E], %o3
F0016D48: 10800012                 ba      loc_F0016D90
F0016D4C: 293c04d1                 sethi   -0xFECBC00, %l4
F0016D50: 808a0010                 btst    %l0, %o0
F0016D54: 1280001b                 bne     loc_F0016DC0
F0016D58: 1108001d                 sethi   0x20007400, %o0
F0016D5C: d002a01c                 ld      [%o2+0x1C], %o0
F0016D60: 808a0010                 btst    %l0, %o0
F0016D64: 12800016                 bne     loc_F0016DBC
F0016D68: 9010000b                 mov     %o3, %o0
F0016D6C: 7fffe9dc                 call    _gsignal
F0016D70: 92102016                 mov     0x16, %o1
F0016D74: 90152350                 or      %l4, 0x350, %o0! unsigned int
F0016D78: 7fffee40                 call    _sleep
F0016D7C: 9210201d                 mov     0x1D, %o1
F0016D80: d204e1d8                 ld      [%l3+0x1D8], %o1
F0016D84: d0562044                 ldsh    [%i0+0x44], %o0
F0016D88: d4024000                 ld      [%o1], %o2
F0016D8C: d652a02e                 ldsh    [%o2+0x2E], %o3
F0016D90: 80a2c008                 cmp     %o3, %o0
F0016D94: 0280000b                 be      loc_F0016DC0
F0016D98: 1108001d                 sethi   0x20007400, %o0
F0016D9C: d0026164                 ld      [%o1+0x164], %o0
F0016DA0: 80a60008                 cmp     %i0, %o0
F0016DA4: 12800007                 bne     loc_F0016DC0
F0016DA8: 1108001d                 sethi   0x20007400, %o0
F0016DAC: d002a028                 ld      [%o2+0x28], %o0
F0016DB0: 808a0012                 btst    %l2, %o0
F0016DB4: 22bfffe7                 be,a    loc_F0016D50
F0016DB8: d002a020                 ld      [%o2+0x20], %o0
F0016DBC: 1108001d                 sethi   0x20007400, %o0
F0016DC0: 90122002                 bset    2, %o0
F0016DC4: 80a64008                 cmp     %i1, %o0
F0016DC8: 02800111                 be      loc_F001720C
F0016DCC: 01000000                 nop
F0016DD0: 14800064                 bg      loc_F0016F60
F0016DD4: 1110011d                 sethi   0x40047400, %o0
F0016DD8: 1120011d9012207e         set     -0x7FFB8B82, %o0
F0016DE0: 80a64008                 cmp     %i1, %o0
F0016DE4: 22800207                 be,a    loc_F0017600
F0016DE8: d2068000                 ld      [%i2], %o1
F0016DEC: 14800030                 bg      loc_F0016EAC
F0016DF0: 1120019d                 sethi   -0x7FF98C00, %o0
F0016DF4: 1120011d90122001         set     -0x7FFB8BFF, %o0
F0016DFC: 80a64008                 cmp     %i1, %o0
F0016E00: 228000c4                 be,a    loc_F0017110
F0016E04: f4068000                 ld      [%i2], %i2
F0016E08: 14800016                 bg      loc_F0016E60
F0016E0C: 1120011d                 sethi   -0x7FFB8C00, %o0
F0016E10: 112001199012227d         set     -0x7FFB9983, %o0
F0016E18: 80a64008                 cmp     %i1, %o0
F0016E1C: 028001d5                 be      loc_F0017570
F0016E20: 01000000                 nop
F0016E24: 14800009                 bg      loc_F0016E48
F0016E28: 11200119                 sethi   -0x7FFB9C00, %o0
F0016E2C: 1120005d90122072         set     -0x7FFE8B8E, %o0
F0016E34: 80a64008                 cmp     %i1, %o0
F0016E38: 02800139                 be      loc_F001731C
F0016E3C: 113c04cf                 sethi   -0xFECC400, %o0
F0016E40: 10800304                 ba      locret_F0017A50
F0016E44: b0103fff                 mov     -1, %i0
F0016E48: 9012227e                 bset    0x27E, %o0
F0016E4C: 80a64008                 cmp     %i1, %o0
F0016E50: 028001b9                 be      loc_F0017534
F0016E54: 01000000                 nop
F0016E58: 108002fe                 ba      locret_F0017A50
F0016E5C: b0103fff                 mov     -1, %i0
F0016E60: 90122076                 bset    0x76, %o0 ! 'v'
F0016E64: 80a64008                 cmp     %i1, %o0
F0016E68: 22800202                 be,a    loc_F0017670
F0016E6C: 113c04cf                 sethi   -0xFECC400, %o0
F0016E70: 14800009                 bg      loc_F0016E94
F0016E74: 1120011d                 sethi   -0x7FFB8C00, %o0
F0016E78: 1120011d90122010         set     -0x7FFB8BF0, %o0
F0016E80: 80a64008                 cmp     %i1, %o0
F0016E84: 228000ea                 be,a    loc_F001722C
F0016E88: d2068000                 ld      [%i2], %o1
F0016E8C: 108002f1                 ba      locret_F0017A50
F0016E90: b0103fff                 mov     -1, %i0
F0016E94: 9012207d                 bset    0x7D, %o0 ! '}'
F0016E98: 80a64008                 cmp     %i1, %o0
F0016E9C: 028001df                 be      loc_F0017618
F0016EA0: 1100003f                 sethi   0xFC00, %o0
F0016EA4: 108002eb                 ba      locret_F0017A50
F0016EA8: b0103fff                 mov     -1, %i0
F0016EAC: 90122011                 bset    0x11, %o0
F0016EB0: 80a64008                 cmp     %i1, %o0
F0016EB4: 228001be                 be,a    loc_F00175AC
F0016EB8: 9010001a                 mov     %i2, %o0
F0016EBC: 14800012                 bg      loc_F0016F04
F0016EC0: 1120021d                 sethi   -0x7FF78C00, %o0
F0016EC4: 1120011d9012207f         set     -0x7FFB8B81, %o0
F0016ECC: 80a64008                 cmp     %i1, %o0
F0016ED0: 028001c5                 be      loc_F00175E4
F0016ED4: 1120019d                 sethi   -0x7FF98C00, %o0
F0016ED8: 9012200a                 bset    0xA, %o0
F0016EDC: 80a64008                 cmp     %i1, %o0
F0016EE0: 348002dc                 bg,a    locret_F0017A50
F0016EE4: b0103fff                 mov     -1, %i0
F0016EE8: 1120019d90122009         set     -0x7FF98BF7, %o0
F0016EF0: 80a64008                 cmp     %i1, %o0
F0016EF4: 268002d7                 bl,a    locret_F0017A50
F0016EF8: b0103fff                 mov     -1, %i0
F0016EFC: 1080012c                 ba      loc_F00173AC
F0016F00: d00ea002                 ldub    [%i2+2], %o0
F0016F04: 90122067                 bset    0x67, %o0 ! 'g'
F0016F08: 80a64008                 cmp     %i1, %o0
F0016F0C: 22800225                 be,a    loc_F00177A0
F0016F10: 9006205c                 add     %i0, 0x5C, %o0 ! '\'
F0016F14: 14800009                 bg      loc_F0016F38
F0016F18: 1120091d                 sethi   -0x7FDB8C00, %o0
F0016F1C: 1120019d90122075         set     -0x7FF98B8B, %o0
F0016F24: 80a64008                 cmp     %i1, %o0
F0016F28: 028001a3                 be      loc_F00175B4
F0016F2C: 9010001a                 mov     %i2, %o0
F0016F30: 108002c8                 ba      locret_F0017A50
F0016F34: b0103fff                 mov     -1, %i0
F0016F38: 90122016                 bset    0x16, %o0
F0016F3C: 80a64008                 cmp     %i1, %o0
F0016F40: 348002c4                 bg,a    locret_F0017A50
F0016F44: b0103fff                 mov     -1, %i0
F0016F48: 1120091d90122014         set     -0x7FDB8BEC, %o0
F0016F50: 80a64008                 cmp     %i1, %o0
F0016F54: 268002bf                 bl,a    locret_F0017A50
F0016F58: b0103fff                 mov     -1, %i0
F0016F5C: 3080024a                 ba,a    loc_F0017884
F0016F60: 90122060                 bset    0x60, %o0 ! '`'
F0016F64: 80a64008                 cmp     %i1, %o0
F0016F68: 22800066                 be,a    loc_F0017100
F0016F6C: d0062040                 ld      [%i0+0x40], %o0
F0016F70: 14800033                 bg      loc_F001703C
F0016F74: 1110019d                 sethi   0x40067400, %o0
F0016F78: 1108001d90122068         set     0x20007468, %o0
F0016F80: 80a64008                 cmp     %i1, %o0
F0016F84: 22800222                 be,a    loc_F001780C
F0016F88: 113c04d4                 sethi   -0xFECB000, %o0
F0016F8C: 14800016                 bg      loc_F0016FE4
F0016F90: 1108001d                 sethi   0x20007400, %o0
F0016F94: 1108001d9012200e         set     0x2000740E, %o0
F0016F9C: 80a64008                 cmp     %i1, %o0
F0016FA0: 02800096                 be      loc_F00171F8
F0016FA4: 01000000                 nop
F0016FA8: 14800009                 bg      loc_F0016FCC
F0016FAC: 1108001d                 sethi   0x20007400, %o0
F0016FB0: 1108001d9012200d         set     0x2000740D, %o0
F0016FB8: 80a64008                 cmp     %i1, %o0
F0016FBC: 0280008a                 be      loc_F00171E4
F0016FC0: 01000000                 nop
F0016FC4: 108002a3                 ba      locret_F0017A50
F0016FC8: b0103fff                 mov     -1, %i0
F0016FCC: 9012205e                 bset    0x5E, %o0 ! '^'
F0016FD0: 80a64008                 cmp     %i1, %o0
F0016FD4: 0280029a                 be      loc_F0017A3C
F0016FD8: 01000000                 nop
F0016FDC: 1080029d                 ba      locret_F0017A50
F0016FE0: b0103fff                 mov     -1, %i0
F0016FE4: 9012206f                 bset    0x6F, %o0 ! 'o'
F0016FE8: 80a64008                 cmp     %i1, %o0
F0016FEC: 028000a1                 be      loc_F0017270
F0016FF0: 01000000                 nop
F0016FF4: 14800009                 bg      loc_F0017018
F0016FF8: 11100119                 sethi   0x40046400, %o0
F0016FFC: 1108001d9012206e         set     0x2000746E, %o0
F0017004: 80a64008                 cmp     %i1, %o0
F0017008: 028000b1                 be      loc_F00172CC
F001700C: 01000000                 nop
F0017010: 10800290                 ba      locret_F0017A50
F0017014: b0103fff                 mov     -1, %i0
F0017018: 9012227f                 bset    0x27F, %o0
F001701C: 80a64008                 cmp     %i1, %o0
F0017020: 0280008b                 be      loc_F001724C
F0017024: 1110011d                 sethi   0x40047400, %o0
F0017028: 80a64008                 cmp     %i1, %o0
F001702C: 22800037                 be,a    loc_F0017108
F0017030: d04e2047                 ldsb    [%i0+0x47], %o0
F0017034: 10800287                 ba      locret_F0017A50
F0017038: b0103fff                 mov     -1, %i0
F001703C: 90122008                 bset    8, %o0
F0017040: 80a64008                 cmp     %i1, %o0
F0017044: 22800132                 be,a    loc_F001750C
F0017048: d00e2049                 ldub    [%i0+0x49], %o0
F001704C: 14800016                 bg      loc_F00170A4
F0017050: 1110019d                 sethi   0x40067400, %o0
F0017054: 1110011d90122077         set     0x40047477, %o0
F001705C: 80a64008                 cmp     %i1, %o0
F0017060: 228001b4                 be,a    loc_F0017730
F0017064: 113c04cf                 sethi   -0xFECC400, %o0
F0017068: 14800009                 bg      loc_F001708C
F001706C: 1110011d                 sethi   0x40047400, %o0
F0017070: 1110011d90122073         set     0x40047473, %o0
F0017078: 80a64008                 cmp     %i1, %o0
F001707C: 2280007b                 be,a    loc_F0017268
F0017080: d0062018                 ld      [%i0+0x18], %o0
F0017084: 10800273                 ba      locret_F0017A50
F0017088: b0103fff                 mov     -1, %i0
F001708C: 9012207c                 bset    0x7C, %o0 ! '|'
F0017090: 80a64008                 cmp     %i1, %o0
F0017094: 22800175                 be,a    loc_F0017668
F0017098: d016203c                 lduh    [%i0+0x3C], %o0
F001709C: 1080026d                 ba      locret_F0017A50
F00170A0: b0103fff                 mov     -1, %i0
F00170A4: 90122074                 bset    0x74, %o0 ! 't'
F00170A8: 80a64008                 cmp     %i1, %o0
F00170AC: 22800149                 be,a    loc_F00175D0
F00170B0: 90062055                 add     %i0, 0x55, %o0 ! 'U'
F00170B4: 14800009                 bg      loc_F00170D8
F00170B8: 1110021d                 sethi   0x40087400, %o0
F00170BC: 1110019d90122012         set     0x40067412, %o0
F00170C4: 80a64008                 cmp     %i1, %o0
F00170C8: 02800142                 be      loc_F00175D0
F00170CC: 9006204f                 add     %i0, 0x4F, %o0 ! 'O'
F00170D0: 10800260                 ba      locret_F0017A50
F00170D4: b0103fff                 mov     -1, %i0
F00170D8: 90122068                 bset    0x68, %o0 ! 'h'
F00170DC: 80a64008                 cmp     %i1, %o0
F00170E0: 028001c2                 be      loc_F00177E8
F00170E4: 1110091d                 sethi   0x40247400, %o0
F00170E8: 90122013                 bset    0x13, %o0
F00170EC: 80a64008                 cmp     %i1, %o0
F00170F0: 028001e1                 be      loc_F0017874
F00170F4: 90100011                 mov     %l1, %o0
F00170F8: 10800256                 ba      locret_F0017A50
F00170FC: b0103fff                 mov     -1, %i0
F0017100: 10800253                 ba      loc_F0017A4C
F0017104: d0268000                 st      %o0, [%i2]
F0017108: 10800251                 ba      loc_F0017A4C
F001710C: d0268000                 st      %o0, [%i2]
F0017110: 113c042e                 sethi   %hi(_nldisp), %o0
F0017114: d00222ac                 ld      [%o0+%lo(_nldisp)], %o0
F0017118: 80a68008                 cmp     %i2, %o0
F001711C: 1a80000c                 bcc     loc_F001714C
F0017120: 912ea001                 sll     %i2, 1, %o0
F0017124: 9002001a                 add     %o0, %i2, %o0
F0017128: a12a2004                 sll     %o0, 4, %l0
F001712C: 113c042ea21220cc         set     _linesw, %l1
F0017134: d2040011                 ld      [%l0+%l1], %o1
F0017138: 113c005590122040         set     _nodev, %o0
F0017140: 80a24008                 cmp     %o1, %o0
F0017144: 32800004                 bne,a   loc_F0017154
F0017148: d04e2047                 ldsb    [%i0+0x47], %o0
F001714C: 10800241                 ba      locret_F0017A50
F0017150: b0102006                 mov     6, %i0
F0017154: 80a68008                 cmp     %i2, %o0
F0017158: 2280023e                 be,a    locret_F0017A50
F001715C: b0102000                 mov     0, %i0
F0017160: 4001fe96                 call    _spltty
F0017164: 01000000                 nop
F0017168: d24e2047                 ldsb    [%i0+0x47], %o1
F001716C: b6100008                 mov     %o0, %i3
F0017170: 912a6001                 sll     %o1, 1, %o0
F0017174: 90020009                 add     %o0, %o1, %o0
F0017178: 912a2004                 sll     %o0, 4, %o0
F001717C: 90020011                 add     %o0, %l1, %o0
F0017180: d2022004                 ld      [%o0+4], %o1
F0017184: 9fc24000                 call    %o1
F0017188: 90100018                 mov     %i0, %o0
F001718C: c0262084                 clr     [%i0+0x84]
F0017190: 90100015                 mov     %l5, %o0
F0017194: d4040011                 ld      [%l0+%l1], %o2
F0017198: 9fc28000                 call    %o2
F001719C: 92100018                 mov     %i0, %o1
F00171A0: a0920000                 orcc    %o0, %g0, %l0
F00171A4: 0280000e                 be      loc_F00171DC
F00171A8: 90100015                 mov     %l5, %o0
F00171AC: c0262084                 clr     [%i0+0x84]
F00171B0: d24e2047                 ldsb    [%i0+0x47], %o1
F00171B4: 952a6001                 sll     %o1, 1, %o2
F00171B8: 94028009                 add     %o2, %o1, %o2
F00171BC: 952aa004                 sll     %o2, 4, %o2
F00171C0: d4028011                 ld      [%o2+%l1], %o2
F00171C4: 9fc28000                 call    %o2
F00171C8: 92100018                 mov     %i0, %o1
F00171CC: 4001fed6                 call    _splx
F00171D0: 9010001b                 mov     %i3, %o0
F00171D4: 1080021f                 ba      locret_F0017A50
F00171D8: b0100010                 mov     %l0, %i0
F00171DC: 10800214                 ba      loc_F0017A2C
F00171E0: f42e2047                 stb     %i2, [%i0+0x47]
F00171E4: 4001fe75                 call    _spltty
F00171E8: 01000000                 nop
F00171EC: d2062040                 ld      [%i0+0x40], %o1
F00171F0: 1080000b                 ba      loc_F001721C
F00171F4: 92126080                 bset    0x80, %o1
F00171F8: 4001fe70                 call    _spltty
F00171FC: 01000000                 nop
F0017200: d2062040                 ld      [%i0+0x40], %o1
F0017204: 10800006                 ba      loc_F001721C
F0017208: 920a7f7f                 and     %o1, -0x81, %o1
F001720C: 4001fe6b                 call    _spltty
F0017210: 01000000                 nop
F0017214: d2062040                 ld      [%i0+0x40], %o1
F0017218: 92126200                 bset    0x200, %o1
F001721C: 4001fec2                 call    _splx
F0017220: d2262040                 st      %o1, [%i0+0x40]
F0017224: 1080020b                 ba      locret_F0017A50
F0017228: b0102000                 mov     0, %i0
F001722C: 80a26000                 cmp     %o1, 0
F0017230: 12800003                 bne     loc_F001723C
F0017234: 920a6003                 and     %o1, 3, %o1
F0017238: 92102003                 mov     3, %o1
F001723C: 7ffffdfd                 call    _ttyflush
F0017240: 90100018                 mov     %i0, %o0
F0017244: 10800203                 ba      locret_F0017A50
F0017248: b0102000                 mov     0, %i0
F001724C: 4001fe5b                 call    _spltty
F0017250: 01000000                 nop
F0017254: b6100008                 mov     %o0, %i3
F0017258: 40000200                 call    _ttnread
F001725C: 90100011                 mov     %l1, %o0
F0017260: 108001f3                 ba      loc_F0017A2C
F0017264: d0268000                 st      %o0, [%i2]
F0017268: 108001f9                 ba      loc_F0017A4C
F001726C: d0268000                 st      %o0, [%i2]
F0017270: 4001fe52                 call    _spltty
F0017274: 01000000                 nop
F0017278: d2062040                 ld      [%i0+0x40], %o1
F001727C: 808a6100                 btst    0x100, %o1
F0017280: 128001eb                 bne     loc_F0017A2C
F0017284: b6100008                 mov     %o0, %i3
F0017288: 90126100                 or      %o1, 0x100, %o0
F001728C: d4162038                 lduh    [%i0+0x38], %o2
F0017290: d0262040                 st      %o0, [%i0+0x40]
F0017294: 9532a008                 srl     %o2, 8, %o2
F0017298: 932aa001                 sll     %o2, 1, %o1
F001729C: 9202400a                 add     %o1, %o2, %o1
F00172A0: 932a6002                 sll     %o1, 2, %o1
F00172A4: 9222400a                 sub     %o1, %o2, %o1
F00172A8: 932a6002                 sll     %o1, 2, %o1
F00172AC: 153c04729412a1f0         set     _cdevsw, %o2
F00172B4: 9202400a                 add     %o1, %o2, %o1
F00172B8: d4026014                 ld      [%o1+0x14], %o2
F00172BC: 90100018                 mov     %i0, %o0
F00172C0: 9fc28000                 call    %o2
F00172C4: 92102000                 mov     0, %o1
F00172C8: 308001d9                 ba,a    loc_F0017A2C
F00172CC: 4001fe3b                 call    _spltty
F00172D0: 01000000                 nop
F00172D4: d4062040                 ld      [%i0+0x40], %o2
F00172D8: 808aa100                 btst    0x100, %o2
F00172DC: 12800007                 bne     loc_F00172F8
F00172E0: b6100008                 mov     %o0, %i3
F00172E4: d206203c                 ld      [%i0+0x3C], %o1
F00172E8: 11002000                 sethi   0x800000, %o0
F00172EC: 808a4008                 btst    %o0, %o1
F00172F0: 028001cf                 be      loc_F0017A2C
F00172F4: 01000000                 nop
F00172F8: 900abeff                 and     %o2, -0x101, %o0
F00172FC: d0262040                 st      %o0, [%i0+0x40]
F0017300: 90100018                 mov     %i0, %o0
F0017304: d402203c                 ld      [%o0+0x3C], %o2
F0017308: 13002000                 sethi   0x800000, %o1
F001730C: 922a8009                 andn    %o2, %o1, %o1
F0017310: 7ffffe1a                 call    _ttstart
F0017314: d222203c                 st      %o1, [%o0+0x3C]
F0017318: 308001c5                 ba,a    loc_F0017A2C
F001731C: d00221d8                 ld      [%o0+0x1D8], %o0
F0017320: d002201c                 ld      [%o0+0x1C], %o0
F0017324: d0522002                 ldsh    [%o0+2], %o0
F0017328: 80a22000                 cmp     %o0, 0
F001732C: 02800004                 be      loc_F001733C
F0017330: 808ee001                 btst    1, %i3
F0017334: 228001c7                 be,a    locret_F0017A50
F0017338: b0102001                 mov     1, %i0
F001733C: 113c04cf                 sethi   %hi(_active_u), %o0
F0017340: d20221d8                 ld      [%o0+%lo(_active_u)], %o1
F0017344: d002601c                 ld      [%o1+0x1C], %o0
F0017348: d0522002                 ldsh    [%o0+2], %o0
F001734C: 80a22000                 cmp     %o0, 0
F0017350: 02800008                 be      loc_F0017370
F0017354: 01000000                 nop
F0017358: d0026164                 ld      [%o1+0x164], %o0
F001735C: 80a20018                 cmp     %o0, %i0
F0017360: 02800004                 be      loc_F0017370
F0017364: 01000000                 nop
F0017368: 108001ba                 ba      locret_F0017A50
F001736C: b010200d                 mov     0xD, %i0
F0017370: 4001fe12                 call    _spltty
F0017374: 01000000                 nop
F0017378: d44e2047                 ldsb    [%i0+0x47], %o2
F001737C: 932aa001                 sll     %o2, 1, %o1
F0017380: 9202400a                 add     %o1, %o2, %o1
F0017384: 932a6004                 sll     %o1, 4, %o1
F0017388: 153c042e9412a0cc         set     _linesw, %o2
F0017390: 9202400a                 add     %o1, %o2, %o1
F0017394: d4026014                 ld      [%o1+0x14], %o2
F0017398: b6100008                 mov     %o0, %i3
F001739C: d00e8000                 ldub    [%i2], %o0
F00173A0: 9fc28000                 call    %o2
F00173A4: 92100018                 mov     %i0, %o1
F00173A8: 308001a1                 ba,a    loc_F0017A2C
F00173AC: d02e204d                 stb     %o0, [%i0+0x4D]
F00173B0: d00ea003                 ldub    [%i2+3], %o0
F00173B4: d02e204e                 stb     %o0, [%i0+0x4E]
F00173B8: d00e8000                 ldub    [%i2], %o0
F00173BC: d02e2049                 stb     %o0, [%i0+0x49]
F00173C0: d00ea001                 ldub    [%i2+1], %o0
F00173C4: d406203c                 ld      [%i0+0x3C], %o2
F00173C8: d02e204a                 stb     %o0, [%i0+0x4A]
F00173CC: 113fffc0                 sethi   -0x10000, %o0
F00173D0: 940a8008                 and     %o2, %o0, %o2
F00173D4: 1100003f                 sethi   0xFC00, %o0
F00173D8: d256a004                 ldsh    [%i2+4], %o1
F00173DC: 901223ff                 bset    0x3FF, %o0
F00173E0: 920a4008                 and     %o1, %o0, %o1
F00173E4: 4001fdf5                 call    _spltty
F00173E8: a0128009                 or      %o2, %o1, %l0
F00173EC: d406203c                 ld      [%i0+0x3C], %o2! size_t
F00173F0: 808aa020                 btst    0x20, %o2 ! ' '
F00173F4: 1280000a                 bne     loc_F001741C
F00173F8: b6100008                 mov     %o0, %i3
F00173FC: 808c2020                 btst    0x20, %l0 ! ' '
F0017400: 12800007                 bne     loc_F001741C
F0017404: 01000000                 nop
F0017408: 1120019d90122009         set     -0x7FF98BF7, %o0
F0017410: 80a64008                 cmp     %i1, %o0
F0017414: 32800009                 bne,a   loc_F0017438
F0017418: 900aa002                 and     %o2, 2, %o0
F001741C: 7ffffd5d                 call    _ttywait
F0017420: 90100018                 mov     %i0, %o0
F0017424: 90100018                 mov     %i0, %o0
F0017428: 7ffffd82                 call    _ttyflush
F001742C: 92102001                 mov     1, %o1
F0017430: 10800024                 ba      loc_F00174C0
F0017434: e026203c                 st      %l0, [%i0+0x3C]
F0017438: 920c2002                 and     %l0, 2, %o1
F001743C: 80a20009                 cmp     %o0, %o1
F0017440: 0280001f                 be      loc_F00174BC
F0017444: 80a26000                 cmp     %o1, 0
F0017448: 02800018                 be      loc_F00174A8
F001744C: 13080000                 sethi   0x20000000, %o1
F0017450: 90100018                 mov     %i0, %o0
F0017454: 400016e1                 call    _catq
F0017458: 9206200c                 add     %i0, 0xC, %o1
F001745C: d0060000                 ld      [%i0], %o0
F0017460: d027bfe8                 st      %o0, [%fp+var_18]
F0017464: d0062004                 ld      [%i0+4], %o0
F0017468: d027bfec                 st      %o0, [%fp+var_14]
F001746C: d0062008                 ld      [%i0+8], %o0
F0017470: d027bff0                 st      %o0, [%fp+var_10]
F0017474: d006200c                 ld      [%i0+0xC], %o0
F0017478: d2062010                 ld      [%i0+0x10], %o1
F001747C: d0260000                 st      %o0, [%i0]
F0017480: d0062014                 ld      [%i0+0x14], %o0
F0017484: d2262004                 st      %o1, [%i0+4]
F0017488: d0262008                 st      %o0, [%i0+8]
F001748C: d007bfe8                 ld      [%fp+var_18], %o0
F0017490: d026200c                 st      %o0, [%i0+0xC]
F0017494: d007bfec                 ld      [%fp+var_14], %o0
F0017498: d0262010                 st      %o0, [%i0+0x10]
F001749C: d007bff0                 ld      [%fp+var_10], %o0
F00174A0: 10800007                 ba      loc_F00174BC
F00174A4: d0262014                 st      %o0, [%i0+0x14]
F00174A8: 90128009                 or      %o2, %o1, %o0
F00174AC: d026203c                 st      %o0, [%i0+0x3C]
F00174B0: a0140009                 bset    %o1, %l0
F00174B4: 40000c3c                 call    _ttwakeup
F00174B8: 90100018                 mov     %i0, %o0
F00174BC: e026203c                 st      %l0, [%i0+0x3C]
F00174C0: 110709469012221c         set     0x1C251A1C, %o0
F00174C8: d0246010                 st      %o0, [%l1+0x10]
F00174CC: 9010205c                 mov     0x5C, %o0 ! '\'
F00174D0: d02c6014                 stb     %o0, [%l1+0x14]
F00174D4: 90102001                 mov     1, %o0
F00174D8: d02c6015                 stb     %o0, [%l1+0x15]
F00174DC: c02c6016                 clrb    [%l1+0x16]
F00174E0: 7ffffc26                 call    _ttysetspec
F00174E4: 90100011                 mov     %l1, %o0
F00174E8: d006203c                 ld      [%i0+0x3C], %o0
F00174EC: 808a2020                 btst    0x20, %o0 ! ' '
F00174F0: 0280014f                 be      loc_F0017A2C
F00174F4: 90100018                 mov     %i0, %o0
F00174F8: d2062040                 ld      [%i0+0x40], %o1
F00174FC: 920a7eff                 and     %o1, -0x101, %o1
F0017500: 7ffffd9e                 call    _ttstart
F0017504: d2222040                 st      %o1, [%o0+0x40]
F0017508: 30800149                 ba,a    loc_F0017A2C
F001750C: d02e8000                 stb     %o0, [%i2]
F0017510: d00e204a                 ldub    [%i0+0x4A], %o0
F0017514: d02ea001                 stb     %o0, [%i2+1]
F0017518: d00e204d                 ldub    [%i0+0x4D], %o0
F001751C: d02ea002                 stb     %o0, [%i2+2]
F0017520: d00e204e                 ldub    [%i0+0x4E], %o0
F0017524: d02ea003                 stb     %o0, [%i2+3]
F0017528: d006203c                 ld      [%i0+0x3C], %o0
F001752C: 10800148                 ba      loc_F0017A4C
F0017530: d036a004                 sth     %o0, [%i2+4]
F0017534: 4001fda1                 call    _spltty
F0017538: 01000000                 nop
F001753C: d2068000                 ld      [%i2], %o1
F0017540: 80a26000                 cmp     %o1, 0
F0017544: 02800006                 be      loc_F001755C
F0017548: b6100008                 mov     %o0, %i3
F001754C: d0062040                 ld      [%i0+0x40], %o0
F0017550: 13000008                 sethi   0x2000, %o1
F0017554: 10800005                 ba      loc_F0017568
F0017558: 90120009                 bset    %o1, %o0
F001755C: d2062040                 ld      [%i0+0x40], %o1
F0017560: 11000008                 sethi   0x2000, %o0
F0017564: 902a4008                 andn    %o1, %o0, %o0
F0017568: 10800131                 ba      loc_F0017A2C
F001756C: d0262040                 st      %o0, [%i0+0x40]
F0017570: 4001fd92                 call    _spltty
F0017574: 01000000                 nop
F0017578: d2068000                 ld      [%i2], %o1
F001757C: 80a26000                 cmp     %o1, 0
F0017580: 02800006                 be      loc_F0017598
F0017584: b6100008                 mov     %o0, %i3
F0017588: d0062040                 ld      [%i0+0x40], %o0
F001758C: 13000010                 sethi   0x4000, %o1
F0017590: 10800005                 ba      loc_F00175A4
F0017594: 90120009                 bset    %o1, %o0
F0017598: d2062040                 ld      [%i0+0x40], %o1
F001759C: 11000010                 sethi   0x4000, %o0
F00175A0: 902a4008                 andn    %o1, %o0, %o0! void *
F00175A4: 10800122                 ba      loc_F0017A2C
F00175A8: d0262040                 st      %o0, [%i0+0x40]
F00175AC: 10800003                 ba      loc_F00175B8
F00175B0: 9206204f                 add     %i0, 0x4F, %o1 ! 'O'
F00175B4: 92062055                 add     %i0, 0x55, %o1 ! 'U'! void *
F00175B8: 4001f556                 call    _bcopy
F00175BC: 94102006                 mov     6, %o2! size_t
F00175C0: 7ffffbee                 call    _ttysetspec
F00175C4: 90100011                 mov     %l1, %o0! void *
F00175C8: 10800122                 ba      locret_F0017A50
F00175CC: b0102000                 mov     0, %i0
F00175D0: 9210001a                 mov     %i2, %o1! void *
F00175D4: 4001f54f                 call    _bcopy
F00175D8: 94102006                 mov     6, %o2
F00175DC: 1080011d                 ba      locret_F0017A50
F00175E0: b0102000                 mov     0, %i0
F00175E4: d4068000                 ld      [%i2], %o2
F00175E8: 90100011                 mov     %l1, %o0
F00175EC: d206203c                 ld      [%i0+0x3C], %o1
F00175F0: 952aa010                 sll     %o2, 16, %o2
F00175F4: 9212400a                 bset    %o2, %o1
F00175F8: 10800011                 ba      loc_F001763C
F00175FC: d226203c                 st      %o1, [%i0+0x3C]
F0017600: 90100011                 mov     %l1, %o0
F0017604: d406203c                 ld      [%i0+0x3C], %o2
F0017608: 932a6010                 sll     %o1, 16, %o1
F001760C: 922a8009                 andn    %o2, %o1, %o1
F0017610: 1080000b                 ba      loc_F001763C
F0017614: d226203c                 st      %o1, [%i0+0x3C]
F0017618: d406203c                 ld      [%i0+0x3C], %o2
F001761C: 901223ff                 bset    0x3FF, %o0
F0017620: 940a8008                 and     %o2, %o0, %o2
F0017624: d426203c                 st      %o2, [%i0+0x3C]
F0017628: d2068000                 ld      [%i2], %o1
F001762C: 90100011                 mov     %l1, %o0
F0017630: 932a6010                 sll     %o1, 16, %o1
F0017634: 94128009                 bset    %o1, %o2
F0017638: d426203c                 st      %o2, [%i0+0x3C]
F001763C: 130709469212621c         set     0x1C251A1C, %o1
F0017644: d2222010                 st      %o1, [%o0+0x10]
F0017648: 9210205c                 mov     0x5C, %o1 ! '\'
F001764C: d22a2014                 stb     %o1, [%o0+0x14]
F0017650: 92102001                 mov     1, %o1
F0017654: d22a2015                 stb     %o1, [%o0+0x15]
F0017658: 7ffffbc8                 call    _ttysetspec
F001765C: c02a2016                 clrb    [%o0+0x16]
F0017660: 108000fc                 ba      locret_F0017A50
F0017664: b0102000                 mov     0, %i0
F0017668: 108000f9                 ba      loc_F0017A4C
F001766C: d0268000                 st      %o0, [%i2]
F0017670: d40221d8                 ld      [%o0+0x1D8], %o2
F0017674: e0028000                 ld      [%o2], %l0
F0017678: d2042014                 ld      [%l0+0x14], %o1
F001767C: 11000010                 sethi   0x4000, %o0
F0017680: 808a4008                 btst    %o0, %o1
F0017684: 02800020                 be      loc_F0017704
F0017688: f4068000                 ld      [%i2], %i2
F001768C: 7fffdbf5                 call    _pgfind
F0017690: 9010001a                 mov     %i2, %o0
F0017694: b2100008                 mov     %o0, %i1
F0017698: 7fffdd22                 call    _get_posix_proc
F001769C: d0542030                 ldsh    [%l0+0x30], %o0
F00176A0: 80a6a000                 cmp     %i2, 0
F00176A4: 04800004                 ble     loc_F00176B4
F00176A8: 80a66000                 cmp     %i1, 0
F00176AC: 32800004                 bne,a   loc_F00176BC
F00176B0: d0022010                 ld      [%o0+0x10], %o0
F00176B4: 108000e7                 ba      locret_F0017A50
F00176B8: b0102016                 mov     0x16, %i0
F00176BC: d4022008                 ld      [%o0+8], %o2
F00176C0: d0046008                 ld      [%l1+8], %o0
F00176C4: 80a28008                 cmp     %o2, %o0
F00176C8: 328000e2                 bne,a   locret_F0017A50
F00176CC: b0102019                 mov     0x19, %i0
F00176D0: d2042028                 ld      [%l0+0x28], %o1
F00176D4: 11100000                 sethi   0x40000000, %o0
F00176D8: 808a4008                 btst    %o0, %o1
F00176DC: 228000dd                 be,a    locret_F0017A50
F00176E0: b0102019                 mov     0x19, %i0
F00176E4: d0066008                 ld      [%i1+8], %o0
F00176E8: 80a2000a                 cmp     %o0, %o2
F00176EC: 328000d9                 bne,a   locret_F0017A50
F00176F0: b0102001                 mov     1, %i0
F00176F4: f224600c                 st      %i1, [%l1+0xC]
F00176F8: d006600c                 ld      [%i1+0xC], %o0
F00176FC: 108000d4                 ba      loc_F0017A4C
F0017700: d0362044                 sth     %o0, [%i0+0x44]
F0017704: d002a01c                 ld      [%o2+0x1C], %o0
F0017708: d0522002                 ldsh    [%o0+2], %o0
F001770C: 80a22000                 cmp     %o0, 0
F0017710: 02800006                 be      loc_F0017728
F0017714: 808ee001                 btst    1, %i3
F0017718: 328000cd                 bne,a   loc_F0017A4C
F001771C: f4362044                 sth     %i2, [%i0+0x44]
F0017720: 108000cc                 ba      locret_F0017A50
F0017724: b0102001                 mov     1, %i0
F0017728: 108000c9                 ba      loc_F0017A4C
F001772C: f4362044                 sth     %i2, [%i0+0x44]
F0017730: d00221d8                 ld      [%o0+0x1D8], %o0
F0017734: f2020000                 ld      [%o0], %i1
F0017738: d2066014                 ld      [%i1+0x14], %o1
F001773C: 11000010                 sethi   0x4000, %o0
F0017740: 808a4008                 btst    %o0, %o1
F0017744: 22800015                 be,a    loc_F0017798
F0017748: d0562044                 ldsh    [%i0+0x44], %o0
F001774C: 7fffdcf5                 call    _get_posix_proc
F0017750: d0566030                 ldsh    [%i1+0x30], %o0
F0017754: d0022010                 ld      [%o0+0x10], %o0
F0017758: d4022008                 ld      [%o0+8], %o2! size_t
F001775C: d0046008                 ld      [%l1+8], %o0
F0017760: 80a28008                 cmp     %o2, %o0
F0017764: 328000bb                 bne,a   locret_F0017A50
F0017768: b0102019                 mov     0x19, %i0
F001776C: d2066028                 ld      [%i1+0x28], %o1
F0017770: 11100000                 sethi   0x40000000, %o0
F0017774: 808a4008                 btst    %o0, %o1
F0017778: 228000b6                 be,a    locret_F0017A50
F001777C: b0102019                 mov     0x19, %i0
F0017780: d002a008                 ld      [%o2+8], %o0
F0017784: 80a22000                 cmp     %o0, 0
F0017788: 32800004                 bne,a   loc_F0017798
F001778C: d0562044                 ldsh    [%i0+0x44], %o0! void *
F0017790: 108000b0                 ba      locret_F0017A50
F0017794: b0102019                 mov     0x19, %i0
F0017798: 108000ad                 ba      loc_F0017A4C
F001779C: d0268000                 st      %o0, [%i2]
F00177A0: 9210001a                 mov     %i2, %o1! void *
F00177A4: 7fffb9ee                 call    _bcmp
F00177A8: 94102008                 mov     8, %o2
F00177AC: 80a22000                 cmp     %o0, 0
F00177B0: 028000a7                 be      loc_F0017A4C
F00177B4: 9210201c                 mov     0x1C, %o1
F00177B8: d0168000                 lduh    [%i2], %o0
F00177BC: d036205c                 sth     %o0, [%i0+0x5C]
F00177C0: d016a002                 lduh    [%i2+2], %o0
F00177C4: d036205e                 sth     %o0, [%i0+0x5E]
F00177C8: d016a004                 lduh    [%i2+4], %o0
F00177CC: d0362060                 sth     %o0, [%i0+0x60]
F00177D0: d416a006                 lduh    [%i2+6], %o2
F00177D4: d0562044                 ldsh    [%i0+0x44], %o0
F00177D8: 7fffe741                 call    _gsignal
F00177DC: d4362062                 sth     %o2, [%i0+0x62]
F00177E0: 1080009c                 ba      locret_F0017A50
F00177E4: b0102000                 mov     0, %i0
F00177E8: d016205c                 lduh    [%i0+0x5C], %o0
F00177EC: d0368000                 sth     %o0, [%i2]
F00177F0: d016205e                 lduh    [%i0+0x5E], %o0
F00177F4: d036a002                 sth     %o0, [%i2+2]
F00177F8: d0162060                 lduh    [%i0+0x60], %o0
F00177FC: d036a004                 sth     %o0, [%i2+4]
F0017800: d0162062                 lduh    [%i0+0x62], %o0
F0017804: 10800092                 ba      loc_F0017A4C
F0017808: d036a006                 sth     %o0, [%i2+6]
F001780C: 90122190                 bset    0x190, %o0
F0017810: 80a60008                 cmp     %i0, %o0
F0017814: 02800015                 be      loc_F0017868
F0017818: 113c04d4                 sethi   %hi(_cons_tp), %o0
F001781C: d0022290                 ld      [%o0+%lo(_cons_tp)], %o0
F0017820: 1308001a                 sethi   0x20006800, %o1
F0017824: d8122038                 lduh    [%o0+0x38], %o4
F0017828: 92126308                 bset    0x308, %o1
F001782C: 992b2010                 sll     %o4, 16, %o4
F0017830: 913b2010                 sra     %o4, 16, %o0
F0017834: 99332018                 srl     %o4, 24, %o4
F0017838: 972b2001                 sll     %o4, 1, %o3
F001783C: 9602c00c                 add     %o3, %o4, %o3
F0017840: 972ae002                 sll     %o3, 2, %o3
F0017844: 9622c00c                 sub     %o3, %o4, %o3
F0017848: 972ae002                 sll     %o3, 2, %o3
F001784C: 193c0472981321f0         set     _cdevsw, %o4
F0017854: 9602c00c                 add     %o3, %o4, %o3
F0017858: d802e010                 ld      [%o3+0x10], %o4
F001785C: 94102000                 mov     0, %o2
F0017860: 9fc30000                 call    %o4
F0017864: 96102000                 mov     0, %o3
F0017868: 113c04d4                 sethi   %hi(_cons_tp), %o0
F001786C: 10800078                 ba      loc_F0017A4C
F0017870: f0222290                 st      %i0, [%o0+%lo(_cons_tp)]
F0017874: 40000d29                 call    _ttgettermios
F0017878: 9210001a                 mov     %i2, %o1
F001787C: 10800075                 ba      locret_F0017A50
F0017880: b0102000                 mov     0, %i0
F0017884: 4001fccd                 call    _spltty
F0017888: 01000000                 nop
F001788C: d24ea021                 ldsb    [%i2+0x21], %o1
F0017890: 80a26000                 cmp     %o1, 0
F0017894: 12800004                 bne     loc_F00178A4
F0017898: b6100008                 mov     %o0, %i3
F001789C: d00ea022                 ldub    [%i2+0x22], %o0
F00178A0: d02ea021                 stb     %o0, [%i2+0x21]
F00178A4: 111ff6e2901223eb         set     0x7FDB8BEB, %o0
F00178AC: 90064008                 add     %i1, %o0, %o0
F00178B0: 80a22001                 cmp     %o0, 1
F00178B4: 3880000d                 bgu,a   loc_F00178E8
F00178B8: d606a008                 ld      [%i2+8], %o3
F00178BC: 7ffffc35                 call    _ttywait
F00178C0: 90100018                 mov     %i0, %o0
F00178C4: 1120091d90122016         set     -0x7FDB8BEA, %o0
F00178CC: 80a64008                 cmp     %i1, %o0
F00178D0: 32800006                 bne,a   loc_F00178E8
F00178D4: d606a008                 ld      [%i2+8], %o3
F00178D8: 90100018                 mov     %i0, %o0
F00178DC: 7ffffc55                 call    _ttyflush
F00178E0: 92102001                 mov     1, %o1
F00178E4: d606a008                 ld      [%i2+8], %o3
F00178E8: 808ae001                 btst    1, %o3
F00178EC: 32800013                 bne,a   loc_F0017938
F00178F0: d406203c                 ld      [%i0+0x3C], %o2
F00178F4: d4062040                 ld      [%i0+0x40], %o2
F00178F8: 808aa010                 btst    0x10, %o2
F00178FC: 3280000f                 bne,a   loc_F0017938
F0017900: d406203c                 ld      [%i0+0x3C], %o2
F0017904: d0046010                 ld      [%l1+0x10], %o0
F0017908: 13000020                 sethi   0x8000, %o1
F001790C: 808a0009                 btst    %o1, %o0
F0017910: 02800009                 be      loc_F0017934
F0017914: 808ac009                 btst    %o1, %o3
F0017918: 32800008                 bne,a   loc_F0017938
F001791C: d406203c                 ld      [%i0+0x3C], %o2
F0017920: 900abffb                 and     %o2, -5, %o0
F0017924: 90122002                 bset    2, %o0
F0017928: d0262040                 st      %o0, [%i0+0x40]
F001792C: 40000b1e                 call    _ttwakeup
F0017930: 90100018                 mov     %i0, %o0
F0017934: d406203c                 ld      [%i0+0x3C], %o2
F0017938: d206a00c                 ld      [%i2+0xC], %o1
F001793C: 900aa022                 and     %o2, 0x22, %o0
F0017940: 80a00008                 cmp     %g0, %o0
F0017944: a1326005                 srl     %o1, 5, %l0
F0017948: 92603fff                 subc    %g0, -1, %o1
F001794C: 1120091d90122016         set     -0x7FDB8BEA, %o0
F0017954: 80a64008                 cmp     %i1, %o0
F0017958: 02800022                 be      loc_F00179E0
F001795C: a00c2001                 and     %l0, 1, %l0
F0017960: 80a40009                 cmp     %l0, %o1
F0017964: 0280001f                 be      loc_F00179E0
F0017968: 80a42000                 cmp     %l0, 0
F001796C: 02800008                 be      loc_F001798C
F0017970: 11080000                 sethi   0x20000000, %o0
F0017974: 90128008                 bset    %o2, %o0
F0017978: d026203c                 st      %o0, [%i0+0x3C]
F001797C: 40000b0a                 call    _ttwakeup
F0017980: 90100018                 mov     %i0, %o0
F0017984: 10800018                 ba      loc_F00179E4
F0017988: 80a42000                 cmp     %l0, 0
F001798C: 90100018                 mov     %i0, %o0
F0017990: 40001592                 call    _catq
F0017994: 9206200c                 add     %i0, 0xC, %o1
F0017998: d0060000                 ld      [%i0], %o0
F001799C: d027bfe8                 st      %o0, [%fp+var_18]
F00179A0: d0062004                 ld      [%i0+4], %o0
F00179A4: d027bfec                 st      %o0, [%fp+var_14]
F00179A8: d0062008                 ld      [%i0+8], %o0
F00179AC: d027bff0                 st      %o0, [%fp+var_10]
F00179B0: d006200c                 ld      [%i0+0xC], %o0
F00179B4: d2062010                 ld      [%i0+0x10], %o1
F00179B8: d0260000                 st      %o0, [%i0]
F00179BC: d0062014                 ld      [%i0+0x14], %o0
F00179C0: d2262004                 st      %o1, [%i0+4]
F00179C4: d0262008                 st      %o0, [%i0+8]
F00179C8: d007bfe8                 ld      [%fp+var_18], %o0
F00179CC: d026200c                 st      %o0, [%i0+0xC]
F00179D0: d007bfec                 ld      [%fp+var_14], %o0
F00179D4: d0262010                 st      %o0, [%i0+0x10]
F00179D8: d007bff0                 ld      [%fp+var_10], %o0
F00179DC: d0262014                 st      %o0, [%i0+0x14]
F00179E0: 80a42000                 cmp     %l0, 0
F00179E4: 1280000e                 bne     loc_F0017A1C
F00179E8: 90100011                 mov     %l1, %o0
F00179EC: 11003fff                 sethi   0xFFFC00, %o0
F00179F0: d4046014                 ld      [%l1+0x14], %o2
F00179F4: 90122300                 bset    0x300, %o0
F00179F8: d206a018                 ld      [%i2+0x18], %o1
F00179FC: 940a8008                 and     %o2, %o0, %o2
F0017A00: 920a4008                 and     %o1, %o0, %o1
F0017A04: 80a28009                 cmp     %o2, %o1
F0017A08: 02800005                 be      loc_F0017A1C
F0017A0C: 90100011                 mov     %l1, %o0
F0017A10: 40000ae5                 call    _ttwakeup
F0017A14: 90100018                 mov     %i0, %o0
F0017A18: 90100011                 mov     %l1, %o0
F0017A1C: 40000bbd                 call    _ttsettermios
F0017A20: 9210001a                 mov     %i2, %o1
F0017A24: 7ffffad5                 call    _ttysetspec
F0017A28: 90100011                 mov     %l1, %o0
F0017A2C: 4001fcbe                 call    _splx
F0017A30: 9010001b                 mov     %i3, %o0
F0017A34: 10800007                 ba      locret_F0017A50
F0017A38: b0102000                 mov     0, %i0
F0017A3C: 7ffffbd5                 call    _ttywait
F0017A40: 90100018                 mov     %i0, %o0
F0017A44: 10800003                 ba      locret_F0017A50
F0017A48: b0102000                 mov     0, %i0
F0017A4C: b0102000                 mov     0, %i0
F0017A50: 81c7e008                 ret
F0017A54: 81e80000                 restore
