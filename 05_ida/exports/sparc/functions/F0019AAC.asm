F0019AAC: 9de3bf28                 save    %sp, -0xD8, %sp
F0019AB0: 4000058e                 call    _ttynty
F0019AB4: 90100018                 mov     %i0, %o0
F0019AB8: a8100008                 mov     %o0, %l4
F0019ABC: b6102000                 mov     0, %i3
F0019AC0: d20e204a                 ldub    [%i0+0x4A], %o1
F0019AC4: 113c042d                 sethi   %hi(_tthiwat), %o0
F0019AC8: d8066014                 ld      [%i1+0x14], %o4
F0019ACC: 90122320                 bset    %lo(_tthiwat), %o0
F0019AD0: d827bf8c                 st      %o4, [%fp+var_74]
F0019AD4: 920a601f                 and     %o1, 0x1F, %o1
F0019AD8: 932a6001                 sll     %o1, 1, %o1
F0019ADC: e6524008                 ldsh    [%o1+%o0], %l3
F0019AE0: d4062040                 ld      [%i0+0x40], %o2
F0019AE4: 808aa010                 btst    0x10, %o2
F0019AE8: 12800020                 bne     loc_F0019B68
F0019AEC: 233c04cf                 sethi   %hi(_active_u), %l1
F0019AF0: d0052010                 ld      [%l4+0x10], %o0
F0019AF4: 13000020                 sethi   0x8000, %o1
F0019AF8: 808a0009                 btst    %o1, %o0
F0019AFC: 3280001c                 bne,a   loc_F0019B6C
F0019B00: d40461d8                 ld      [%l1+%lo(_active_u)], %o2
F0019B04: 21000008                 sethi   0x2000, %l0
F0019B08: 233c04cf                 sethi   -0xFECC400, %l1
F0019B0C: 25000010                 sethi   0x4000, %l2
F0019B10: 808a8009                 btst    %o1, %o2
F0019B14: 02800039                 be      loc_F0019BF8
F0019B18: 808a8010                 btst    %l0, %o2
F0019B1C: 02800007                 be      loc_F0019B38
F0019B20: d00461d8                 ld      [%l1+0x1D8], %o0
F0019B24: d0020000                 ld      [%o0], %o0
F0019B28: d0022014                 ld      [%o0+0x14], %o0
F0019B2C: b0102023                 mov     0x23, %i0 ! '#'
F0019B30: 10800149                 ba      loc_F001A054
F0019B34: 808a0012                 btst    %l2, %o0
F0019B38: 90100018                 mov     %i0, %o0! unsigned int
F0019B3C: 7fffe2cf                 call    _sleep
F0019B40: 9210201c                 mov     0x1C, %o1
F0019B44: d4062040                 ld      [%i0+0x40], %o2
F0019B48: 808aa010                 btst    0x10, %o2
F0019B4C: 12800006                 bne     loc_F0019B64
F0019B50: 13000020                 sethi   0x8000, %o1
F0019B54: d0052010                 ld      [%l4+0x10], %o0
F0019B58: 808a0009                 btst    %o1, %o0
F0019B5C: 02bfffee                 be      loc_F0019B14
F0019B60: 808a8009                 btst    %o1, %o2
F0019B64: 233c04cf                 sethi   -0xFECC400, %l1
F0019B68: d40461d8                 ld      [%l1+0x1D8], %o2
F0019B6C: e0028000                 ld      [%o2], %l0
F0019B70: d2042014                 ld      [%l0+0x14], %o1
F0019B74: 11000010                 sethi   0x4000, %o0
F0019B78: 808a4008                 btst    %o0, %o1
F0019B7C: 22800029                 be,a    loc_F0019C20
F0019B80: d654202e                 ldsh    [%l0+0x2E], %o3
F0019B84: 7fffd3e7                 call    _get_posix_proc
F0019B88: d0542030                 ldsh    [%l0+0x30], %o0
F0019B8C: d4022010                 ld      [%o0+0x10], %o2
F0019B90: d0562044                 ldsh    [%i0+0x44], %o0
F0019B94: d602a00c                 ld      [%o2+0xC], %o3
F0019B98: 80a2c008                 cmp     %o3, %o0
F0019B9C: 02800044                 be      loc_F0019CAC
F0019BA0: d00461d8                 ld      [%l1+0x1D8], %o0
F0019BA4: d0022164                 ld      [%o0+0x164], %o0
F0019BA8: 80a60008                 cmp     %i0, %o0
F0019BAC: 32800041                 bne,a   loc_F0019CB0
F0019BB0: d0066014                 ld      [%i1+0x14], %o0
F0019BB4: d206203c                 ld      [%i0+0x3C], %o1
F0019BB8: 11001000                 sethi   0x400000, %o0
F0019BBC: 808a4008                 btst    %o0, %o1
F0019BC0: 0280003b                 be      loc_F0019CAC
F0019BC4: 13000800                 sethi   0x200000, %o1
F0019BC8: d0042020                 ld      [%l0+0x20], %o0
F0019BCC: 808a0009                 btst    %o1, %o0
F0019BD0: 32800038                 bne,a   loc_F0019CB0
F0019BD4: d0066014                 ld      [%i1+0x14], %o0
F0019BD8: d004201c                 ld      [%l0+0x1C], %o0
F0019BDC: 808a0009                 btst    %o1, %o0
F0019BE0: 32800034                 bne,a   loc_F0019CB0
F0019BE4: d0066014                 ld      [%i1+0x14], %o0
F0019BE8: d002a010                 ld      [%o2+0x10], %o0
F0019BEC: 80a22000                 cmp     %o0, 0
F0019BF0: 12800027                 bne     loc_F0019C8C
F0019BF4: 9010000b                 mov     %o3, %o0
F0019BF8: 10800122                 ba      locret_F001A080
F0019BFC: b0102005                 mov     5, %i0
F0019C00: 7ffff3de                 call    _ttstart
F0019C04: 90100018                 mov     %i0, %o0
F0019C08: 113c04d190122350         set     _lbolt, %o0! unsigned int
F0019C10: 7fffe29a                 call    _sleep
F0019C14: 9210201d                 mov     0x1D, %o1
F0019C18: 108000b0                 ba      loc_F0019ED8
F0019C1C: d2064000                 ld      [%i1], %o1
F0019C20: d0562044                 ldsh    [%i0+0x44], %o0
F0019C24: 80a2c008                 cmp     %o3, %o0
F0019C28: 22800022                 be,a    loc_F0019CB0
F0019C2C: d0066014                 ld      [%i1+0x14], %o0
F0019C30: d002a164                 ld      [%o2+0x164], %o0
F0019C34: 80a60008                 cmp     %i0, %o0
F0019C38: 3280001e                 bne,a   loc_F0019CB0
F0019C3C: d0066014                 ld      [%i1+0x14], %o0
F0019C40: d206203c                 ld      [%i0+0x3C], %o1
F0019C44: 11001000                 sethi   0x400000, %o0
F0019C48: 808a4008                 btst    %o0, %o1
F0019C4C: 02800018                 be      loc_F0019CAC
F0019C50: 11000004                 sethi   0x1000, %o0
F0019C54: d2042028                 ld      [%l0+0x28], %o1
F0019C58: 808a4008                 btst    %o0, %o1
F0019C5C: 32800015                 bne,a   loc_F0019CB0
F0019C60: d0066014                 ld      [%i1+0x14], %o0
F0019C64: d0042020                 ld      [%l0+0x20], %o0
F0019C68: 13000800                 sethi   0x200000, %o1
F0019C6C: 808a0009                 btst    %o1, %o0
F0019C70: 32800010                 bne,a   loc_F0019CB0
F0019C74: d0066014                 ld      [%i1+0x14], %o0
F0019C78: d004201c                 ld      [%l0+0x1C], %o0
F0019C7C: 808a0009                 btst    %o1, %o0
F0019C80: 3280000c                 bne,a   loc_F0019CB0
F0019C84: d0066014                 ld      [%i1+0x14], %o0
F0019C88: 9010000b                 mov     %o3, %o0
F0019C8C: 7fffde14                 call    _gsignal
F0019C90: 92102016                 mov     0x16, %o1
F0019C94: 113c04d190122350         set     _lbolt, %o0! unsigned int
F0019C9C: 7fffe277                 call    _sleep
F0019CA0: 9210201c                 mov     0x1C, %o1
F0019CA4: 10bfff90                 ba      loc_F0019AE4
F0019CA8: d4062040                 ld      [%i0+0x40], %o2
F0019CAC: d0066014                 ld      [%i1+0x14], %o0
F0019CB0: 80a22000                 cmp     %o0, 0
F0019CB4: 048000b9                 ble     loc_F0019F98
F0019CB8: 2b002000                 sethi   0x800000, %l5
F0019CBC: 11000800ba122024         set     0x200024, %i5
F0019CC4: 2d040000                 sethi   0x10000000, %l6
F0019CC8: 2f3c04d1                 sethi   -0xFECBC00, %l7
F0019CCC: 11000800b8122020         set     0x200020, %i4
F0019CD4: 353c04d0                 sethi   -0xFECC000, %i2
F0019CD8: d0064000                 ld      [%i1], %o0
F0019CDC: e2022004                 ld      [%o0+4], %l1
F0019CE0: 80a46000                 cmp     %l1, 0
F0019CE4: 12800010                 bne     loc_F0019D24
F0019CE8: 80a46064                 cmp     %l1, 0x64 ! 'd'
F0019CEC: d0066004                 ld      [%i1+4], %o0
F0019CF0: d2064000                 ld      [%i1], %o1
F0019CF4: 90023fff                 inc     -1, %o0
F0019CF8: d0266004                 st      %o0, [%i1+4]
F0019CFC: 92026008                 inc     8, %o1
F0019D00: d0066004                 ld      [%i1+4], %o0
F0019D04: 80a22000                 cmp     %o0, 0
F0019D08: 148000a0                 bg      loc_F0019F88
F0019D0C: d2264000                 st      %o1, [%i1]
F0019D10: 113c042e                 sethi   %hi(aTtwrite), %o0! "ttwrite"
F0019D14: 7fffed17                 call    _panic
F0019D18: 901220a0                 bset    %lo(aTtwrite), %o0! "ttwrite"
F0019D1C: 1080009c                 ba      loc_F0019F8C
F0019D20: d0066014                 ld      [%i1+0x14], %o0
F0019D24: 34800002                 bg,a    loc_F0019D2C
F0019D28: a2102064                 mov     0x64, %l1 ! 'd'
F0019D2C: a407bf90                 add     %fp, var_70, %l2
F0019D30: 90100012                 mov     %l2, %o0
F0019D34: 92100011                 mov     %l1, %o1
F0019D38: 94102001                 mov     1, %o2
F0019D3C: 7fffe177                 call    _uiomove
F0019D40: 96100019                 mov     %i1, %o3
F0019D44: b6920000                 orcc    %o0, %g0, %i3
F0019D48: 12800094                 bne     loc_F0019F98
F0019D4C: 01000000                 nop
F0019D50: d0062018                 ld      [%i0+0x18], %o0
F0019D54: 80a20013                 cmp     %o0, %l3
F0019D58: 14800094                 bg      loc_F0019FA8
F0019D5C: 01000000                 nop
F0019D60: d006203c                 ld      [%i0+0x3C], %o0
F0019D64: 808a0015                 btst    %l5, %o0
F0019D68: 32800089                 bne,a   loc_F0019F8C
F0019D6C: d0066014                 ld      [%i1+0x14], %o0
F0019D70: 900a001d                 and     %o0, %i5, %o0
F0019D74: 80a22004                 cmp     %o0, 4
F0019D78: 32800020                 bne,a   loc_F0019DF8
F0019D7C: d206203c                 ld      [%i0+0x3C], %o1
F0019D80: d0052010                 ld      [%l4+0x10], %o0
F0019D84: 808a0016                 btst    %l6, %o0
F0019D88: 0280001b                 be      loc_F0019DF4
F0019D8C: 80a46000                 cmp     %l1, 0
F0019D90: 2480007f                 ble,a   loc_F0019F8C
F0019D94: d0066014                 ld      [%i1+0x14], %o0
F0019D98: d04c8000                 ldsb    [%l2], %o0
F0019D9C: a404a001                 inc     %l2
F0019DA0: c02e204b                 clrb    [%i0+0x4B]
F0019DA4: 7ffffc7b                 call    _ttyoutput
F0019DA8: 92100018                 mov     %i0, %o1
F0019DAC: 80a22000                 cmp     %o0, 0
F0019DB0: 26800009                 bl,a    loc_F0019DD4
F0019DB4: d0062018                 ld      [%i0+0x18], %o0
F0019DB8: 7ffff370                 call    _ttstart
F0019DBC: 90100018                 mov     %i0, %o0
F0019DC0: 9015e350                 or      %l7, 0x350, %o0! unsigned int
F0019DC4: 7fffe22d                 call    _sleep
F0019DC8: 9210201d                 mov     0x1D, %o1
F0019DCC: 1080003f                 ba      loc_F0019EC8
F0019DD0: c02e204b                 clrb    [%i0+0x4B]
F0019DD4: 80a20013                 cmp     %o0, %l3
F0019DD8: 14800074                 bg      loc_F0019FA8
F0019DDC: a2047fff                 inc     -1, %l1
F0019DE0: 80a46000                 cmp     %l1, 0
F0019DE4: 34bfffee                 bg,a    loc_F0019D9C
F0019DE8: d04c8000                 ldsb    [%l2], %o0
F0019DEC: 10800068                 ba      loc_F0019F8C
F0019DF0: d0066014                 ld      [%i1+0x14], %o0
F0019DF4: d206203c                 ld      [%i0+0x3C], %o1
F0019DF8: 1100880090122020         set     0x2200020, %o0
F0019E00: 808a4008                 btst    %o0, %o1
F0019E04: 1280005f                 bne     loc_F0019F80
F0019E08: 80a46000                 cmp     %l1, 0
F0019E0C: d0052010                 ld      [%l4+0x10], %o0
F0019E10: 808a0016                 btst    %l6, %o0
F0019E14: 0280005b                 be      loc_F0019F80
F0019E18: 80a46000                 cmp     %l1, 0
F0019E1C: 900a2300                 and     %o0, 0x300, %o0
F0019E20: 80a22300                 cmp     %o0, 0x300
F0019E24: 02800057                 be      loc_F0019F80
F0019E28: 80a46000                 cmp     %l1, 0
F0019E2C: a0847fff                 addcc   %l1, -1, %l0
F0019E30: 0c800053                 bneg    loc_F0019F7C
F0019E34: 92100012                 mov     %l2, %o1
F0019E38: d00a4000                 ldub    [%o1], %o0
F0019E3C: a0843fff                 inccc   -1, %l0
F0019E40: 900a207f                 and     %o0, 0x7F, %o0
F0019E44: d02a4000                 stb     %o0, [%o1]
F0019E48: 1cbffffc                 bpos    loc_F0019E38
F0019E4C: 92026001                 inc     %o1
F0019E50: 1080004c                 ba      loc_F0019F80
F0019E54: 80a46000                 cmp     %l1, 0
F0019E58: 808a001c                 btst    %i4, %o0
F0019E5C: 12800030                 bne     loc_F0019F1C
F0019E60: a0100011                 mov     %l1, %l0
F0019E64: d0052010                 ld      [%l4+0x10], %o0
F0019E68: 808a0016                 btst    %l6, %o0
F0019E6C: 12800004                 bne     loc_F0019E7C
F0019E70: 90100011                 mov     %l1, %o0
F0019E74: 1080002b                 ba      loc_F0019F20
F0019E78: c02e204b                 clrb    [%i0+0x4B]
F0019E7C: 92100012                 mov     %l2, %o1
F0019E80: 153c042d9412a1a0         set     _partab, %o2
F0019E88: 4000d9de                 call    _scanc
F0019E8C: 9610203f                 mov     0x3F, %o3 ! '?'
F0019E90: a0a44008                 subcc   %l1, %o0, %l0
F0019E94: 12800023                 bne     loc_F0019F20
F0019E98: c02e204b                 clrb    [%i0+0x4B]
F0019E9C: d04c8000                 ldsb    [%l2], %o0
F0019EA0: 7ffffc3c                 call    _ttyoutput
F0019EA4: 92100018                 mov     %i0, %o1
F0019EA8: 80a22000                 cmp     %o0, 0
F0019EAC: 26800019                 bl,a    loc_F0019F10
F0019EB0: a404a001                 inc     %l2
F0019EB4: 7ffff331                 call    _ttstart
F0019EB8: 90100018                 mov     %i0, %o0
F0019EBC: 9015e350                 or      %l7, 0x350, %o0! unsigned int
F0019EC0: 7fffe1ee                 call    _sleep
F0019EC4: 9210201d                 mov     0x1D, %o1
F0019EC8: 80a46000                 cmp     %l1, 0
F0019ECC: 22bfff06                 be,a    loc_F0019AE4
F0019ED0: d4062040                 ld      [%i0+0x40], %o2
F0019ED4: d2064000                 ld      [%i1], %o1
F0019ED8: d0024000                 ld      [%o1], %o0
F0019EDC: 90220011                 sub     %o0, %l1, %o0
F0019EE0: d0224000                 st      %o0, [%o1]
F0019EE4: d2064000                 ld      [%i1], %o1
F0019EE8: d0026004                 ld      [%o1+4], %o0
F0019EEC: 90020011                 add     %o0, %l1, %o0
F0019EF0: d0226004                 st      %o0, [%o1+4]
F0019EF4: d0066014                 ld      [%i1+0x14], %o0
F0019EF8: d2066008                 ld      [%i1+8], %o1
F0019EFC: 90020011                 add     %o0, %l1, %o0
F0019F00: d0266014                 st      %o0, [%i1+0x14]
F0019F04: 92224011                 sub     %o1, %l1, %o1
F0019F08: 10bffef6                 ba      loc_F0019AE0
F0019F0C: d2266008                 st      %o1, [%i1+8]
F0019F10: d006203c                 ld      [%i0+0x3C], %o0
F0019F14: 10800013                 ba      loc_F0019F60
F0019F18: a2047fff                 inc     -1, %l1
F0019F1C: c02e204b                 clrb    [%i0+0x4B]
F0019F20: 90100012                 mov     %l2, %o0
F0019F24: 92100010                 mov     %l0, %o1
F0019F28: 40000b55                 call    _b_to_q
F0019F2C: 94062018                 add     %i0, 0x18, %o2
F0019F30: a0240008                 sub     %l0, %o0, %l0
F0019F34: a4048010                 add     %l2, %l0, %l2
F0019F38: d20e2048                 ldub    [%i0+0x48], %o1
F0019F3C: a2244010                 sub     %l1, %l0, %l1
F0019F40: 92024010                 add     %o1, %l0, %o1
F0019F44: d22e2048                 stb     %o1, [%i0+0x48]
F0019F48: d206a220                 ld      [%i2+0x220], %o1
F0019F4C: 80a22000                 cmp     %o0, 0
F0019F50: 92024010                 add     %o1, %l0, %o1
F0019F54: 14bfff2b                 bg      loc_F0019C00
F0019F58: d226a220                 st      %o1, [%i2+0x220]
F0019F5C: d006203c                 ld      [%i0+0x3C], %o0
F0019F60: 808a0015                 btst    %l5, %o0
F0019F64: 12800011                 bne     loc_F0019FA8
F0019F68: 01000000                 nop
F0019F6C: d0062018                 ld      [%i0+0x18], %o0
F0019F70: 80a20013                 cmp     %o0, %l3
F0019F74: 1480000d                 bg      loc_F0019FA8
F0019F78: 01000000                 nop
F0019F7C: 80a46000                 cmp     %l1, 0
F0019F80: 34bfffb6                 bg,a    loc_F0019E58
F0019F84: d006203c                 ld      [%i0+0x3C], %o0
F0019F88: d0066014                 ld      [%i1+0x14], %o0
F0019F8C: 80a22000                 cmp     %o0, 0
F0019F90: 34bfff53                 bg,a    loc_F0019CDC
F0019F94: d0064000                 ld      [%i1], %o0
F0019F98: 7ffff2f8                 call    _ttstart
F0019F9C: 90100018                 mov     %i0, %o0
F0019FA0: 10800038                 ba      locret_F001A080
F0019FA4: b010001b                 mov     %i3, %i0
F0019FA8: 4001f304                 call    _spltty
F0019FAC: 01000000                 nop
F0019FB0: 80a46000                 cmp     %l1, 0
F0019FB4: 02800010                 be      loc_F0019FF4
F0019FB8: a0100008                 mov     %o0, %l0
F0019FBC: d2064000                 ld      [%i1], %o1
F0019FC0: d0024000                 ld      [%o1], %o0
F0019FC4: 90220011                 sub     %o0, %l1, %o0
F0019FC8: d0224000                 st      %o0, [%o1]
F0019FCC: d2064000                 ld      [%i1], %o1
F0019FD0: d0026004                 ld      [%o1+4], %o0
F0019FD4: 90020011                 add     %o0, %l1, %o0
F0019FD8: d0226004                 st      %o0, [%o1+4]
F0019FDC: d0066014                 ld      [%i1+0x14], %o0
F0019FE0: d2066008                 ld      [%i1+8], %o1
F0019FE4: 90020011                 add     %o0, %l1, %o0
F0019FE8: d0266014                 st      %o0, [%i1+0x14]
F0019FEC: 92224011                 sub     %o1, %l1, %o1
F0019FF0: d2266008                 st      %o1, [%i1+8]
F0019FF4: 7ffff2e1                 call    _ttstart
F0019FF8: 90100018                 mov     %i0, %o0
F0019FFC: d0062018                 ld      [%i0+0x18], %o0
F001A000: 80a20013                 cmp     %o0, %l3
F001A004: 0480001b                 ble     loc_F001A070
F001A008: 11000008                 sethi   0x2000, %o0
F001A00C: d2062040                 ld      [%i0+0x40], %o1
F001A010: 808a4008                 btst    %o0, %o1
F001A014: 02800013                 be      loc_F001A060
F001A018: 90126040                 or      %o1, 0x40, %o0
F001A01C: 4001f342                 call    _splx
F001A020: 90100010                 mov     %l0, %o0
F001A024: d0066014                 ld      [%i1+0x14], %o0
F001A028: d807bf8c                 ld      [%fp+var_74], %o4
F001A02C: 80a2000c                 cmp     %o0, %o4
F001A030: 12800014                 bne     locret_F001A080
F001A034: b0102000                 mov     0, %i0
F001A038: 113c04cf                 sethi   %hi(_active_u), %o0
F001A03C: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F001A040: d0020000                 ld      [%o0], %o0
F001A044: d2022014                 ld      [%o0+0x14], %o1
F001A048: b0102023                 mov     0x23, %i0 ! '#'
F001A04C: 11000010                 sethi   0x4000, %o0
F001A050: 808a4008                 btst    %o0, %o1
F001A054: 3280000b                 bne,a   locret_F001A080
F001A058: b010200b                 mov     0xB, %i0
F001A05C: 30800009                 ba,a    locret_F001A080
F001A060: d0262040                 st      %o0, [%i0+0x40]
F001A064: 90062018                 add     %i0, 0x18, %o0! unsigned int
F001A068: 7fffe184                 call    _sleep
F001A06C: 9210201d                 mov     0x1D, %o1
F001A070: 4001f32d                 call    _splx
F001A074: 90100010                 mov     %l0, %o0
F001A078: 10bffe9b                 ba      loc_F0019AE4
F001A07C: d4062040                 ld      [%i0+0x40], %o2
F001A080: 81c7e008                 ret
F001A084: 81e80000                 restore
