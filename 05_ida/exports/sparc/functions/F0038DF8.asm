F0038DF8: 9de3bf90                 save    %sp, -0x70, %sp
F0038DFC: 113c04ea                 sethi   %hi(_igmpstat), %o0
F0038E00: d20220a0                 ld      [%o0+%lo(_igmpstat)], %o1
F0038E04: 92026001                 inc     %o1
F0038E08: d22220a0                 st      %o1, [%o0+%lo(_igmpstat)]
F0038E0C: d4062004                 ld      [%i0+4], %o2
F0038E10: a206000a                 add     %i0, %o2, %l1
F0038E14: e4546002                 ldsh    [%l1+2], %l2
F0038E18: d20e000a                 ldub    [%i0+%o2], %o1
F0038E1C: 80a4a007                 cmp     %l2, 7
F0038E20: a21220a0                 or      %o0, %lo(_igmpstat), %l1
F0038E24: 920a600f                 and     %o1, 0xF, %o1
F0038E28: 14800008                 bg      loc_F0038E48
F0038E2C: a12a6002                 sll     %o1, 2, %l0
F0038E30: d2046004                 ld      [%l1+4], %o1
F0038E34: 90100018                 mov     %i0, %o0
F0038E38: 92026001                 inc     %o1
F0038E3C: 7fff938a                 call    _m_freem
F0038E40: d2246004                 st      %o1, [%l1+4]
F0038E44: 308000f1                 ba,a    locret_F0039208
F0038E48: 80a2a07c                 cmp     %o2, 0x7C ! '|'
F0038E4C: 18800006                 bgu     loc_F0038E64
F0038E50: 92042008                 add     %l0, 8, %o1
F0038E54: d0562008                 ldsh    [%i0+8], %o0
F0038E58: 80a20009                 cmp     %o0, %o1
F0038E5C: 1680000b                 bge     loc_F0038E88
F0038E60: 90100018                 mov     %i0, %o0
F0038E64: 7fff949c                 call    _m_pullup
F0038E68: 90100018                 mov     %i0, %o0
F0038E6C: b0920000                 orcc    %o0, %g0, %i0
F0038E70: 12800006                 bne     loc_F0038E88
F0038E74: 90100018                 mov     %i0, %o0
F0038E78: d0046004                 ld      [%l1+4], %o0
F0038E7C: 90022001                 inc     %o0
F0038E80: 108000e2                 ba      locret_F0039208
F0038E84: d0246004                 st      %o0, [%l1+4]
F0038E88: d4062004                 ld      [%i0+4], %o2
F0038E8C: 92100012                 mov     %l2, %o1
F0038E90: d6162008                 lduh    [%i0+8], %o3
F0038E94: 94028010                 add     %o2, %l0, %o2
F0038E98: d4262004                 st      %o2, [%i0+4]
F0038E9C: 9622c010                 sub     %o3, %l0, %o3
F0038EA0: e2062004                 ld      [%i0+4], %l1
F0038EA4: 40017ff9                 call    _in_cksum
F0038EA8: d6362008                 sth     %o3, [%i0+8]
F0038EAC: 80a22000                 cmp     %o0, 0
F0038EB0: 0280000a                 be      loc_F0038ED8
F0038EB4: a4060011                 add     %i0, %l1, %l2
F0038EB8: 153c04ea9412a0a0         set     _igmpstat, %o2
F0038EC0: d202a008                 ld      [%o2+8], %o1
F0038EC4: 90100018                 mov     %i0, %o0
F0038EC8: 92026001                 inc     %o1
F0038ECC: 7fff9366                 call    _m_freem
F0038ED0: d222a008                 st      %o1, [%o2+8]
F0038ED4: 308000cd                 ba,a    locret_F0039208
F0038ED8: d0062004                 ld      [%i0+4], %o0
F0038EDC: d2162008                 lduh    [%i0+8], %o1
F0038EE0: 90220010                 sub     %o0, %l0, %o0
F0038EE4: d0262004                 st      %o0, [%i0+4]
F0038EE8: 92024010                 add     %o1, %l0, %o1
F0038EEC: d0062004                 ld      [%i0+4], %o0
F0038EF0: d2362008                 sth     %o1, [%i0+8]
F0038EF4: d20e0011                 ldub    [%i0+%l1], %o1
F0038EF8: 80a26011                 cmp     %o1, 0x11
F0038EFC: 02800007                 be      loc_F0038F18
F0038F00: a2060008                 add     %i0, %o0, %l1
F0038F04: 80a26012                 cmp     %o1, 0x12
F0038F08: 02800060                 be      loc_F0039088
F0038F0C: 113c04ea                 sethi   -0xFEC5800, %o0
F0038F10: 108000b3                 ba      loc_F00391DC
F0038F14: 90100018                 mov     %i0, %o0
F0038F18: 113c04ea941220a0         set     _igmpstat, %o2
F0038F20: d002a00c                 ld      [%o2+0xC], %o0
F0038F24: 133c04d5                 sethi   %hi(_loifp), %o1
F0038F28: d2026268                 ld      [%o1+%lo(_loifp)], %o1
F0038F2C: 90022001                 inc     %o0
F0038F30: 80a64009                 cmp     %i1, %o1
F0038F34: 028000a9                 be      loc_F00391D8
F0038F38: d022a00c                 st      %o0, [%o2+0xC]
F0038F3C: d0046010                 ld      [%l1+0x10], %o0
F0038F40: 133c04bd                 sethi   %hi(dword_F012F4E8), %o1
F0038F44: d20260e8                 ld      [%o1+%lo(dword_F012F4E8)], %o1
F0038F48: 80a20009                 cmp     %o0, %o1
F0038F4C: 0280000a                 be      loc_F0038F74
F0038F50: 90100018                 mov     %i0, %o0
F0038F54: d202a010                 ld      [%o2+0x10], %o1
F0038F58: 92026001                 inc     %o1
F0038F5C: 7fff9342                 call    _m_freem
F0038F60: d222a010                 st      %o1, [%o2+0x10]
F0038F64: 308000a9                 ba,a    locret_F0039208
F0038F68: d0042014                 ld      [%l0+0x14], %o0
F0038F6C: 10800012                 ba      loc_F0038FB4
F0038F70: d027bff4                 st      %o0, [%fp+var_C]
F0038F74: c027bff4                 clr     [%fp+var_C]
F0038F78: 113c04d9                 sethi   %hi(_in_ifaddr), %o0
F0038F7C: d0022070                 ld      [%o0+%lo(_in_ifaddr)], %o0
F0038F80: a0102000                 mov     0, %l0
F0038F84: 80a22000                 cmp     %o0, 0
F0038F88: 0280000b                 be      loc_F0038FB4
F0038F8C: d027bff0                 st      %o0, [%fp+var_10]
F0038F90: d007bff0                 ld      [%fp+var_10], %o0
F0038F94: e0022044                 ld      [%o0+0x44], %l0
F0038F98: d0022040                 ld      [%o0+0x40], %o0
F0038F9C: 80a42000                 cmp     %l0, 0
F0038FA0: 12bffff2                 bne     loc_F0038F68
F0038FA4: d027bff0                 st      %o0, [%fp+var_10]
F0038FA8: 80a22000                 cmp     %o0, 0
F0038FAC: 12bffffa                 bne     loc_F0038F94
F0038FB0: d007bff0                 ld      [%fp+var_10], %o0
F0038FB4: 80a42000                 cmp     %l0, 0
F0038FB8: 02800088                 be      loc_F00391D8
F0038FBC: 2b3c04bd                 sethi   -0xFED0C00, %l5
F0038FC0: 293c04d9                 sethi   -0xFEC9C00, %l4
F0038FC4: 273c04d9                 sethi   -0xFEC9C00, %l3
F0038FC8: 253c0432                 sethi   -0xFEF3800, %l2
F0038FCC: d0042004                 ld      [%l0+4], %o0
F0038FD0: 80a20019                 cmp     %o0, %i1
F0038FD4: 32800016                 bne,a   loc_F003902C
F0038FD8: e007bff4                 ld      [%fp+var_C], %l0
F0038FDC: d0042010                 ld      [%l0+0x10], %o0
F0038FE0: 80a22000                 cmp     %o0, 0
F0038FE4: 32800012                 bne,a   loc_F003902C
F0038FE8: e007bff4                 ld      [%fp+var_C], %l0
F0038FEC: d6040000                 ld      [%l0], %o3
F0038FF0: d00560e8                 ld      [%l5+0xE8], %o0
F0038FF4: 80a2c008                 cmp     %o3, %o0
F0038FF8: 0280000c                 be      loc_F0039028
F0038FFC: d204e070                 ld      [%l3+0x70], %o1
F0039000: d4026004                 ld      [%o1+4], %o2
F0039004: d00520d0                 ld      [%l4+0xD0], %o0
F0039008: 92102032                 mov     0x32, %o1 ! '2'
F003900C: 9002000a                 add     %o0, %o2, %o0
F0039010: 7fff3624                 call    _urem
F0039014: 9002000b                 add     %o0, %o3, %o0
F0039018: 90022001                 inc     %o0
F003901C: d0242010                 st      %o0, [%l0+0x10]
F0039020: 90102001                 mov     1, %o0
F0039024: d024a1cc                 st      %o0, [%l2+0x1CC]
F0039028: e007bff4                 ld      [%fp+var_C], %l0
F003902C: 80a42000                 cmp     %l0, 0
F0039030: 02800005                 be      loc_F0039044
F0039034: d007bff0                 ld      [%fp+var_10], %o0
F0039038: d0042014                 ld      [%l0+0x14], %o0
F003903C: 1080000e                 ba      loc_F0039074
F0039040: d027bff4                 st      %o0, [%fp+var_C]
F0039044: 80a22000                 cmp     %o0, 0
F0039048: 0280000c                 be      loc_F0039078
F003904C: 80a42000                 cmp     %l0, 0
F0039050: d007bff0                 ld      [%fp+var_10], %o0
F0039054: e0022044                 ld      [%o0+0x44], %l0
F0039058: d0022040                 ld      [%o0+0x40], %o0
F003905C: 80a42000                 cmp     %l0, 0
F0039060: 12bffff6                 bne     loc_F0039038
F0039064: d027bff0                 st      %o0, [%fp+var_10]
F0039068: 80a22000                 cmp     %o0, 0
F003906C: 12bffffa                 bne     loc_F0039054
F0039070: d007bff0                 ld      [%fp+var_10], %o0
F0039074: 80a42000                 cmp     %l0, 0
F0039078: 32bfffd6                 bne,a   loc_F0038FD0
F003907C: d0042004                 ld      [%l0+4], %o0
F0039080: 10800057                 ba      loc_F00391DC
F0039084: 90100018                 mov     %i0, %o0
F0039088: 961220a0                 or      %o0, 0xA0, %o3
F003908C: d002e014                 ld      [%o3+0x14], %o0
F0039090: 133c04d5                 sethi   %hi(_loifp), %o1
F0039094: d2026268                 ld      [%o1+%lo(_loifp)], %o1
F0039098: 90022001                 inc     %o0
F003909C: 80a64009                 cmp     %i1, %o1
F00390A0: 0280004e                 be      loc_F00391D8
F00390A4: d022e014                 st      %o0, [%o3+0x14]
F00390A8: d404a004                 ld      [%l2+4], %o2
F00390AC: 113c0000                 sethi   -0x10000000, %o0
F00390B0: 13380000                 sethi   -0x20000000, %o1
F00390B4: 900a8008                 and     %o2, %o0, %o0
F00390B8: 80a20009                 cmp     %o0, %o1
F00390BC: 32800007                 bne,a   loc_F00390D8
F00390C0: d202e018                 ld      [%o3+0x18], %o1
F00390C4: d0046010                 ld      [%l1+0x10], %o0
F00390C8: 80a28008                 cmp     %o2, %o0
F00390CC: 22800008                 be,a    loc_F00390EC
F00390D0: d204600c                 ld      [%l1+0xC], %o1
F00390D4: d202e018                 ld      [%o3+0x18], %o1
F00390D8: 90100018                 mov     %i0, %o0
F00390DC: 92026001                 inc     %o1
F00390E0: 7fff92e1                 call    _m_freem
F00390E4: d222e018                 st      %o1, [%o3+0x18]
F00390E8: 30800048                 ba,a    locret_F0039208
F00390EC: 113fc000                 sethi   -0x1000000, %o0
F00390F0: 808a4008                 btst    %o0, %o1
F00390F4: 12800014                 bne     loc_F0039144
F00390F8: 113c04d9                 sethi   %hi(_in_ifaddr), %o0
F00390FC: d2022070                 ld      [%o0+%lo(_in_ifaddr)], %o1
F0039100: 80a26000                 cmp     %o1, 0
F0039104: 02800010                 be      loc_F0039144
F0039108: 01000000                 nop
F003910C: d0026020                 ld      [%o1+0x20], %o0
F0039110: 80a20019                 cmp     %o0, %i1
F0039114: 02800007                 be      loc_F0039130
F0039118: 80a26000                 cmp     %o1, 0
F003911C: d2026040                 ld      [%o1+0x40], %o1
F0039120: 80a26000                 cmp     %o1, 0
F0039124: 32bffffb                 bne,a   loc_F0039110
F0039128: d0026020                 ld      [%o1+0x20], %o0
F003912C: 80a26000                 cmp     %o1, 0
F0039130: 02800005                 be      loc_F0039144
F0039134: 113c04d9                 sethi   -0xFEC9C00, %o0
F0039138: d0026030                 ld      [%o1+0x30], %o0
F003913C: d024600c                 st      %o0, [%l1+0xC]
F0039140: 113c04d9                 sethi   -0xFEC9C00, %o0
F0039144: d2022070                 ld      [%o0+0x70], %o1
F0039148: 80a26000                 cmp     %o1, 0
F003914C: 0280000b                 be      loc_F0039178
F0039150: 01000000                 nop
F0039154: d0026020                 ld      [%o1+0x20], %o0
F0039158: 80a20019                 cmp     %o0, %i1
F003915C: 02800007                 be      loc_F0039178
F0039160: 80a26000                 cmp     %o1, 0
F0039164: d2026040                 ld      [%o1+0x40], %o1
F0039168: 80a26000                 cmp     %o1, 0
F003916C: 32bffffb                 bne,a   loc_F0039158
F0039170: d0026020                 ld      [%o1+0x20], %o0
F0039174: 80a26000                 cmp     %o1, 0
F0039178: 32800004                 bne,a   loc_F0039188
F003917C: e0026044                 ld      [%o1+0x44], %l0
F0039180: 1080000e                 ba      loc_F00391B8
F0039184: a0102000                 mov     0, %l0
F0039188: 80a42000                 cmp     %l0, 0
F003918C: 02800013                 be      loc_F00391D8
F0039190: 133c04ea                 sethi   -0xFEC5800, %o1
F0039194: d204a004                 ld      [%l2+4], %o1
F0039198: d0040000                 ld      [%l0], %o0
F003919C: 80a20009                 cmp     %o0, %o1
F00391A0: 02800007                 be      loc_F00391BC
F00391A4: 80a42000                 cmp     %l0, 0
F00391A8: e0042014                 ld      [%l0+0x14], %l0
F00391AC: 80a42000                 cmp     %l0, 0
F00391B0: 32bffffb                 bne,a   loc_F003919C
F00391B4: d0040000                 ld      [%l0], %o0
F00391B8: 80a42000                 cmp     %l0, 0
F00391BC: 02800007                 be      loc_F00391D8
F00391C0: 133c04ea                 sethi   %hi(_igmpstat), %o1
F00391C4: c0242010                 clr     [%l0+0x10]
F00391C8: 921260a0                 bset    %lo(_igmpstat), %o1
F00391CC: d002601c                 ld      [%o1+0x1C], %o0
F00391D0: 90022001                 inc     %o0
F00391D4: d022601c                 st      %o0, [%o1+0x1C]
F00391D8: 90100018                 mov     %i0, %o0
F00391DC: 133c0432921261a8         set     unk_F010C9A8, %o1
F00391E4: 153c0432                 sethi   %hi(unk_F010C9AC), %o2
F00391E8: d604600c                 ld      [%l1+0xC], %o3
F00391EC: 9412a1ac                 bset    %lo(unk_F010C9AC), %o2
F00391F0: d622a004                 st      %o3, [%o2+4]
F00391F4: 173c0432                 sethi   %hi(unk_F010C9BC), %o3
F00391F8: d8046010                 ld      [%l1+0x10], %o4
F00391FC: 9612e1bc                 bset    %lo(unk_F010C9BC), %o3
F0039200: 7fffcd2d                 call    _raw_input
F0039204: d822e004                 st      %o4, [%o3+4]
F0039208: 81c7e008                 ret
F003920C: 81e80000                 restore
