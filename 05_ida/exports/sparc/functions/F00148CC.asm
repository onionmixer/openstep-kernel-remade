F00148CC: 9de3bf48                 save    %sp, -0xB8, %sp
F00148D0: ac102000                 mov     0, %l6
F00148D4: 10800008                 ba      loc_F00148F4! jumptable F0014968 cases 1-29,32-38,40,43,44,46-50,52-60,64-70,72,75,76,79,81,82
F00148D8: ae102001                 mov     1, %l7
F00148DC: 80a42000                 cmp     %l0, 0
F00148E0: 028001d5                 be      locret_F0015034
F00148E4: 90100010                 mov     %l0, %o0
F00148E8: 9210001a                 mov     %i2, %o1
F00148EC: 40000281                 call    sub_F00152F0
F00148F0: 9410001b                 mov     %i3, %o2
F00148F4: e04e0000                 ldsb    [%i0], %l0! jumptable F0014968 cases 1-29,32-38,40,43,44,46-50,52-60,64-70,72,75,76,79,81,82
F00148F8: 80a42025                 cmp     %l0, 0x25 ! '%'! jumptable F0014968 default case
F00148FC: 12bffff8                 bne     loc_F00148DC
F0014900: b0062001                 inc     %i0
F0014904: e04e0000                 ldsb    [%i0], %l0! jumptable F0014968 case 71
F0014908: 80a42030                 cmp     %l0, 0x30 ! '0'
F001490C: 12800003                 bne     loc_F0014918
F0014910: b0062001                 inc     %i0
F0014914: ac102030                 mov     0x30, %l6 ! '0'
F0014918: 10800008                 ba      loc_F0014938
F001491C: 9a102000                 mov     0, %o5
F0014920: 9002000d                 add     %o0, %o5, %o0
F0014924: 912a2001                 sll     %o0, 1, %o0
F0014928: 90020010                 add     %o0, %l0, %o0
F001492C: e04e0000                 ldsb    [%i0], %l0
F0014930: 9a023fd0                 add     %o0, -0x30, %o5
F0014934: b0062001                 inc     %i0
F0014938: 90043fd0                 add     %l0, -0x30, %o0
F001493C: 80a22009                 cmp     %o0, 9
F0014940: 28bffff8                 bleu,a  loc_F0014920
F0014944: 912b6002                 sll     %o5, 2, %o0
F0014948: 92043fdb                 add     %l0, -0x25, %o1
F001494C: 80a26053                 cmp     %o1, 0x53 ! 'S'! switch 84 cases
F0014950: 38bfffea                 bgu,a   def_F0014968! jumptable F0014968 default case
F0014954: e04e0000                 ldsb    [%i0], %l0
F0014958: 113c005290122170         set     jpt_F0014968, %o0
F0014960: 932a6002                 sll     %o1, 2, %o1
F0014964: d0024008                 ld      [%o1+%o0], %o0
F0014968: 81c20000                 jmp     %o0! switch jump
F001496C: 01000000                 nop
F0014AC0: 10800005                 ba      loc_F0014AD4! jumptable F0014968 cases 51,83
F0014AC4: aa102010                 mov     0x10, %l5
F0014AC8: 10800003                 ba      loc_F0014AD4! jumptable F0014968 cases 31,63,80
F0014ACC: aa10200a                 mov     0xA, %l5
F0014AD0: aa102008                 mov     8, %l5! jumptable F0014968 cases 42,74
F0014AD4: b2066004                 inc     4, %i1
F0014AD8: d0067ffc                 ld      [%i1-4], %o0
F0014ADC: 92100015                 mov     %l5, %o1
F0014AE0: 9410001a                 mov     %i2, %o2
F0014AE4: 9610001b                 mov     %i3, %o3
F0014AE8: 40000163                 call    sub_F0015074
F0014AEC: 98100016                 mov     %l6, %o4
F0014AF0: 10bfff82                 ba      def_F0014968! jumptable F0014968 default case
F0014AF4: e04e0000                 ldsb    [%i0], %l0
F0014AF8: b2066004                 inc     4, %i1! jumptable F0014968 case 62
F0014AFC: ea067ffc                 ld      [%i1-4], %l5
F0014B00: a4102018                 mov     0x18, %l2
F0014B04: 913d4012                 sra     %l5, %l2, %o0
F0014B08: a08a207f                 andcc   %o0, 0x7F, %l0
F0014B0C: 02800005                 be      loc_F0014B20
F0014B10: 90100010                 mov     %l0, %o0
F0014B14: 9210001a                 mov     %i2, %o1
F0014B18: 400001f6                 call    sub_F00152F0
F0014B1C: 9410001b                 mov     %i3, %o2
F0014B20: a484bff8                 inccc   -8, %l2
F0014B24: 1cbffff9                 bpos    loc_F0014B08
F0014B28: 913d4012                 sra     %l5, %l2, %o0
F0014B2C: 10bfff73                 ba      def_F0014968! jumptable F0014968 default case
F0014B30: e04e0000                 ldsb    [%i0], %l0
F0014B34: b2066004                 inc     4, %i1! jumptable F0014968 case 61
F0014B38: 9410001a                 mov     %i2, %o2
F0014B3C: 9610001b                 mov     %i3, %o3
F0014B40: 98102000                 mov     0, %o4
F0014B44: ea067ffc                 ld      [%i1-4], %l5
F0014B48: 9a102000                 mov     0, %o5
F0014B4C: b2066004                 inc     4, %i1
F0014B50: e2067ffc                 ld      [%i1-4], %l1
F0014B54: a8102000                 mov     0, %l4
F0014B58: d24c4000                 ldsb    [%l1], %o1
F0014B5C: 90100015                 mov     %l5, %o0
F0014B60: 40000145                 call    sub_F0015074
F0014B64: a2046001                 inc     %l1
F0014B68: 80a56000                 cmp     %l5, 0
F0014B6C: 22bfff63                 be,a    def_F0014968! jumptable F0014968 default case
F0014B70: e04e0000                 ldsb    [%i0], %l0
F0014B74: 10800045                 ba      loc_F0014C88
F0014B78: e44c4000                 ldsb    [%l1], %l2
F0014B7C: d04c4000                 ldsb    [%l1], %o0
F0014B80: 80a22020                 cmp     %o0, 0x20 ! ' '
F0014B84: 34800022                 bg,a    loc_F0014C0C
F0014B88: 9004bfff                 add     %l2, -1, %o0
F0014B8C: a8052001                 inc     %l4
F0014B90: 80a52001                 cmp     %l4, 1
F0014B94: 02800005                 be      loc_F0014BA8
F0014B98: 9010202c                 mov     0x2C, %o0 ! ','
F0014B9C: 9210001a                 mov     %i2, %o1
F0014BA0: 400001d4                 call    sub_F00152F0
F0014BA4: 9410001b                 mov     %i3, %o2
F0014BA8: 10800005                 ba      loc_F0014BBC
F0014BAC: e64c4000                 ldsb    [%l1], %l3
F0014BB0: 9210001a                 mov     %i2, %o1
F0014BB4: 400001cf                 call    sub_F00152F0
F0014BB8: 9410001b                 mov     %i3, %o2
F0014BBC: a2046001                 inc     %l1
F0014BC0: e04c4000                 ldsb    [%l1], %l0
F0014BC4: 80a42020                 cmp     %l0, 0x20 ! ' '
F0014BC8: 14bffffa                 bg      loc_F0014BB0
F0014BCC: 90100010                 mov     %l0, %o0
F0014BD0: 9004ffff                 add     %l3, -1, %o0
F0014BD4: 913d4008                 sra     %l5, %o0, %o0
F0014BD8: 94248013                 sub     %l2, %l3, %o2
F0014BDC: 92102002                 mov     2, %o1
F0014BE0: 932a400a                 sll     %o1, %o2, %o1
F0014BE4: 92027fff                 inc     -1, %o1
F0014BE8: 900a0009                 and     %o0, %o1, %o0
F0014BEC: 92102008                 mov     8, %o1
F0014BF0: 9410001a                 mov     %i2, %o2
F0014BF4: 9610001b                 mov     %i3, %o3
F0014BF8: 98102000                 mov     0, %o4
F0014BFC: 4000011e                 call    sub_F0015074
F0014C00: 9a102000                 mov     0, %o5
F0014C04: 10800021                 ba      loc_F0014C88
F0014C08: e44c4000                 ldsb    [%l1], %l2
F0014C0C: 913d4008                 sra     %l5, %o0, %o0
F0014C10: 808a2001                 btst    1, %o0
F0014C14: 22800018                 be,a    loc_F0014C74
F0014C18: a2046001                 inc     %l1
F0014C1C: 80a52000                 cmp     %l4, 0
F0014C20: 02800003                 be      loc_F0014C2C
F0014C24: 9010203c                 mov     0x3C, %o0 ! '<'
F0014C28: 9010202c                 mov     0x2C, %o0 ! ','
F0014C2C: 9210001a                 mov     %i2, %o1
F0014C30: 400001b0                 call    sub_F00152F0
F0014C34: 9410001b                 mov     %i3, %o2
F0014C38: e04c4000                 ldsb    [%l1], %l0
F0014C3C: 80a42020                 cmp     %l0, 0x20 ! ' '
F0014C40: 04800011                 ble     loc_F0014C84
F0014C44: a8102001                 mov     1, %l4
F0014C48: 90100010                 mov     %l0, %o0
F0014C4C: 9210001a                 mov     %i2, %o1
F0014C50: 400001a8                 call    sub_F00152F0
F0014C54: 9410001b                 mov     %i3, %o2
F0014C58: a2046001                 inc     %l1
F0014C5C: e04c4000                 ldsb    [%l1], %l0
F0014C60: 80a42020                 cmp     %l0, 0x20 ! ' '
F0014C64: 14bffffa                 bg      loc_F0014C4C
F0014C68: 90100010                 mov     %l0, %o0
F0014C6C: 10800007                 ba      loc_F0014C88
F0014C70: e44c4000                 ldsb    [%l1], %l2
F0014C74: d04c4000                 ldsb    [%l1], %o0
F0014C78: 80a22020                 cmp     %o0, 0x20 ! ' '
F0014C7C: 34bffffe                 bg,a    loc_F0014C74
F0014C80: a2046001                 inc     %l1
F0014C84: e44c4000                 ldsb    [%l1], %l2
F0014C88: 80a4a000                 cmp     %l2, 0
F0014C8C: 12bfffbc                 bne     loc_F0014B7C
F0014C90: a2046001                 inc     %l1
F0014C94: 10bfff15                 ba      loc_F00148E8
F0014C98: 9010203e                 mov     0x3E, %o0 ! '>'
F0014C9C: b2066004                 inc     4, %i1! jumptable F0014968 case 78
F0014CA0: e2067ffc                 ld      [%i1-4], %l1
F0014CA4: e04c4000                 ldsb    [%l1], %l0
F0014CA8: 80a42000                 cmp     %l0, 0
F0014CAC: 02bfff12                 be      loc_F00148F4! jumptable F0014968 cases 1-29,32-38,40,43,44,46-50,52-60,64-70,72,75,76,79,81,82
F0014CB0: a2046001                 inc     %l1
F0014CB4: 90100010                 mov     %l0, %o0
F0014CB8: 9210001a                 mov     %i2, %o1
F0014CBC: 4000018d                 call    sub_F00152F0
F0014CC0: 9410001b                 mov     %i3, %o2
F0014CC4: e04c4000                 ldsb    [%l1], %l0
F0014CC8: 80a42000                 cmp     %l0, 0
F0014CCC: 12bffffa                 bne     loc_F0014CB4
F0014CD0: a2046001                 inc     %l1
F0014CD4: 10bfff09                 ba      def_F0014968! jumptable F0014968 default case
F0014CD8: e04e0000                 ldsb    [%i0], %l0
F0014CDC: 10bfff03                 ba      loc_F00148E8! jumptable F0014968 case 0
F0014CE0: 90102025                 mov     0x25, %o0 ! '%'
F0014CE4: b2066004                 inc     4, %i1! jumptable F0014968 case 30
F0014CE8: ea067ffc                 ld      [%i1-4], %l5
F0014CEC: a4102018                 mov     0x18, %l2
F0014CF0: 913d4012                 sra     %l5, %l2, %o0
F0014CF4: a08a20ff                 andcc   %o0, 0xFF, %l0
F0014CF8: 02800005                 be      loc_F0014D0C
F0014CFC: 90100010                 mov     %l0, %o0
F0014D00: 9210001a                 mov     %i2, %o1
F0014D04: 4000017b                 call    sub_F00152F0
F0014D08: 9410001b                 mov     %i3, %o2
F0014D0C: a484bff8                 inccc   -8, %l2
F0014D10: 1cbffff9                 bpos    loc_F0014CF4
F0014D14: 913d4012                 sra     %l5, %l2, %o0
F0014D18: 10bffef8                 ba      def_F0014968! jumptable F0014968 default case
F0014D1C: e04e0000                 ldsb    [%i0], %l0
F0014D20: b2066004                 inc     4, %i1! jumptable F0014968 cases 45,77
F0014D24: ea067ffc                 ld      [%i1-4], %l5
F0014D28: b2066004                 inc     4, %i1
F0014D2C: 80a42052                 cmp     %l0, 0x52 ! 'R'
F0014D30: 1280000e                 bne     loc_F0014D68
F0014D34: e2067ffc                 ld      [%i1-4], %l1
F0014D38: 113c042d90122090         set     unk_F010B490, %o0
F0014D40: 9210001a                 mov     %i2, %o1
F0014D44: 400000be                 call    sub_F001503C
F0014D48: 9410001b                 mov     %i3, %o2
F0014D4C: 90100015                 mov     %l5, %o0
F0014D50: 92102010                 mov     0x10, %o1
F0014D54: 9410001a                 mov     %i2, %o2
F0014D58: 9610001b                 mov     %i3, %o3
F0014D5C: 98102000                 mov     0, %o4
F0014D60: 400000c5                 call    sub_F0015074
F0014D64: 9a102000                 mov     0, %o5
F0014D68: 80a42072                 cmp     %l0, 0x72 ! 'r'
F0014D6C: 02800005                 be      loc_F0014D80
F0014D70: a8102000                 mov     0, %l4
F0014D74: 80a56000                 cmp     %l5, 0
F0014D78: 22bffee0                 be,a    def_F0014968! jumptable F0014968 default case
F0014D7C: e04e0000                 ldsb    [%i0], %l0
F0014D80: 9010203c                 mov     0x3C, %o0 ! '<'
F0014D84: 9210001a                 mov     %i2, %o1
F0014D88: 4000015a                 call    sub_F00152F0
F0014D8C: 9410001b                 mov     %i3, %o2
F0014D90: d0044000                 ld      [%l1], %o0
F0014D94: 80a22000                 cmp     %o0, 0
F0014D98: 02800074                 be      loc_F0014F68
F0014D9C: a6100011                 mov     %l1, %l3
F0014DA0: a2046010                 inc     0x10, %l1
F0014DA4: d004c000                 ld      [%l3], %o0
F0014DA8: d2047ff4                 ld      [%l1-0xC], %o1
F0014DAC: 80a26000                 cmp     %o1, 0
F0014DB0: 04800009                 ble     loc_F0014DD4
F0014DB4: a40d4008                 and     %l5, %o0, %l2
F0014DB8: 10800009                 ba      loc_F0014DDC
F0014DBC: a52c8009                 sll     %l2, %o1, %l2
F0014DC0: 9210001a                 mov     %i2, %o1
F0014DC4: 4000009e                 call    sub_F001503C
F0014DC8: 9410001b                 mov     %i3, %o2
F0014DCC: 1080005a                 ba      loc_F0014F34
F0014DD0: d0042004                 ld      [%l0+4], %o0
F0014DD4: 90200009                 neg     %o1, %o0
F0014DD8: a5348008                 srl     %l2, %o0, %l2
F0014DDC: 80a52000                 cmp     %l4, 0
F0014DE0: 22800014                 be,a    loc_F0014E30
F0014DE4: d0047ff8                 ld      [%l1-8], %o0
F0014DE8: d0047ffc                 ld      [%l1-4], %o0
F0014DEC: 80a22000                 cmp     %o0, 0
F0014DF0: 1280000c                 bne     loc_F0014E20
F0014DF4: 9010202c                 mov     0x2C, %o0 ! ','
F0014DF8: d0044000                 ld      [%l1], %o0
F0014DFC: 80a22000                 cmp     %o0, 0
F0014E00: 12800008                 bne     loc_F0014E20
F0014E04: 9010202c                 mov     0x2C, %o0 ! ','
F0014E08: d0047ff8                 ld      [%l1-8], %o0
F0014E0C: 80a22000                 cmp     %o0, 0
F0014E10: 02800008                 be      loc_F0014E30
F0014E14: 80a4a000                 cmp     %l2, 0
F0014E18: 02800005                 be      loc_F0014E2C
F0014E1C: 9010202c                 mov     0x2C, %o0 ! ','
F0014E20: 9210001a                 mov     %i2, %o1
F0014E24: 40000133                 call    sub_F00152F0
F0014E28: 9410001b                 mov     %i3, %o2
F0014E2C: d0047ff8                 ld      [%l1-8], %o0
F0014E30: 80a22000                 cmp     %o0, 0
F0014E34: 2280001f                 be,a    loc_F0014EB0
F0014E38: d4047ffc                 ld      [%l1-4], %o2
F0014E3C: d0047ffc                 ld      [%l1-4], %o0
F0014E40: 80a22000                 cmp     %o0, 0
F0014E44: 3280000a                 bne,a   loc_F0014E6C
F0014E48: d0047ff8                 ld      [%l1-8], %o0
F0014E4C: d0044000                 ld      [%l1], %o0
F0014E50: 80a22000                 cmp     %o0, 0
F0014E54: 32800006                 bne,a   loc_F0014E6C
F0014E58: d0047ff8                 ld      [%l1-8], %o0
F0014E5C: 80a4a000                 cmp     %l2, 0
F0014E60: 22800008                 be,a    loc_F0014E80
F0014E64: d0047ffc                 ld      [%l1-4], %o0
F0014E68: d0047ff8                 ld      [%l1-8], %o0
F0014E6C: 9210001a                 mov     %i2, %o1
F0014E70: 9410001b                 mov     %i3, %o2
F0014E74: 40000072                 call    sub_F001503C
F0014E78: a8102001                 mov     1, %l4
F0014E7C: d0047ffc                 ld      [%l1-4], %o0
F0014E80: 80a22000                 cmp     %o0, 0
F0014E84: 12800006                 bne     loc_F0014E9C
F0014E88: 9010203d                 mov     0x3D, %o0 ! '='
F0014E8C: d0044000                 ld      [%l1], %o0
F0014E90: 80a22000                 cmp     %o0, 0
F0014E94: 02800006                 be      loc_F0014EAC
F0014E98: 9010203d                 mov     0x3D, %o0 ! '='
F0014E9C: 9210001a                 mov     %i2, %o1
F0014EA0: 40000114                 call    sub_F00152F0
F0014EA4: 9410001b                 mov     %i3, %o2
F0014EA8: a8102001                 mov     1, %l4
F0014EAC: d4047ffc                 ld      [%l1-4], %o2
F0014EB0: 80a2a000                 cmp     %o2, 0
F0014EB4: 0280000d                 be      loc_F0014EE8
F0014EB8: 9010001a                 mov     %i2, %o0
F0014EBC: 9210001b                 mov     %i3, %o1
F0014EC0: 7ffffe78                 call    __printf
F0014EC4: 96100012                 mov     %l2, %o3
F0014EC8: d0044000                 ld      [%l1], %o0
F0014ECC: 80a22000                 cmp     %o0, 0
F0014ED0: 02800008                 be      loc_F0014EF0
F0014ED4: a8102001                 mov     1, %l4
F0014ED8: 9010203a                 mov     0x3A, %o0 ! ':'
F0014EDC: 9210001a                 mov     %i2, %o1
F0014EE0: 40000104                 call    sub_F00152F0
F0014EE4: 9410001b                 mov     %i3, %o2
F0014EE8: d0044000                 ld      [%l1], %o0
F0014EEC: 80a22000                 cmp     %o0, 0
F0014EF0: 2280001a                 be,a    loc_F0014F58
F0014EF4: a604e014                 inc     0x14, %l3
F0014EF8: a0100008                 mov     %o0, %l0
F0014EFC: d0042004                 ld      [%l0+4], %o0
F0014F00: 80a22000                 cmp     %o0, 0
F0014F04: 0280000d                 be      loc_F0014F38
F0014F08: a8102001                 mov     1, %l4
F0014F0C: d0040000                 ld      [%l0], %o0
F0014F10: 80a48008                 cmp     %l2, %o0
F0014F14: 22bfffab                 be,a    loc_F0014DC0
F0014F18: d0042004                 ld      [%l0+4], %o0
F0014F1C: a0042008                 inc     8, %l0
F0014F20: d0042004                 ld      [%l0+4], %o0
F0014F24: 80a22000                 cmp     %o0, 0
F0014F28: 32bffffa                 bne,a   loc_F0014F10
F0014F2C: d0040000                 ld      [%l0], %o0
F0014F30: d0042004                 ld      [%l0+4], %o0
F0014F34: 80a22000                 cmp     %o0, 0
F0014F38: 32800008                 bne,a   loc_F0014F58
F0014F3C: a604e014                 inc     0x14, %l3
F0014F40: 113c042d90122098         set     unk_F010B498, %o0
F0014F48: 9210001a                 mov     %i2, %o1
F0014F4C: 4000003c                 call    sub_F001503C
F0014F50: 9410001b                 mov     %i3, %o2
F0014F54: a604e014                 inc     0x14, %l3
F0014F58: d004c000                 ld      [%l3], %o0
F0014F5C: 80a22000                 cmp     %o0, 0
F0014F60: 12bfff92                 bne     loc_F0014DA8
F0014F64: a2046014                 inc     0x14, %l1
F0014F68: 10bffe60                 ba      loc_F00148E8
F0014F6C: 9010203e                 mov     0x3E, %o0 ! '>'
F0014F70: 9210001a                 mov     %i2, %o1
F0014F74: 40000032                 call    sub_F001503C
F0014F78: 9410001b                 mov     %i3, %o2
F0014F7C: 10800010                 ba      loc_F0014FBC
F0014F80: d0046004                 ld      [%l1+4], %o0
F0014F84: b2066004                 inc     4, %i1! jumptable F0014968 cases 41,73
F0014F88: ea067ffc                 ld      [%i1-4], %l5
F0014F8C: b2066004                 inc     4, %i1
F0014F90: 10800006                 ba      loc_F0014FA8
F0014F94: e2067ffc                 ld      [%i1-4], %l1
F0014F98: 80a54008                 cmp     %l5, %o0
F0014F9C: 22bffff5                 be,a    loc_F0014F70
F0014FA0: d0046004                 ld      [%l1+4], %o0
F0014FA4: a2046008                 inc     8, %l1
F0014FA8: d0046004                 ld      [%l1+4], %o0
F0014FAC: 80a22000                 cmp     %o0, 0
F0014FB0: 32bffffa                 bne,a   loc_F0014F98
F0014FB4: d0044000                 ld      [%l1], %o0
F0014FB8: d0046004                 ld      [%l1+4], %o0
F0014FBC: 80a22000                 cmp     %o0, 0
F0014FC0: 12800008                 bne     loc_F0014FE0
F0014FC4: 80a4204e                 cmp     %l0, 0x4E ! 'N'
F0014FC8: 113c042d901220a0         set     unk_F010B4A0, %o0
F0014FD0: 9210001a                 mov     %i2, %o1
F0014FD4: 4000001a                 call    sub_F001503C
F0014FD8: 9410001b                 mov     %i3, %o2
F0014FDC: 80a4204e                 cmp     %l0, 0x4E ! 'N'
F0014FE0: 02800007                 be      loc_F0014FFC
F0014FE4: 9010203a                 mov     0x3A, %o0 ! ':'
F0014FE8: d0046004                 ld      [%l1+4], %o0
F0014FEC: 80a22000                 cmp     %o0, 0
F0014FF0: 32bffe42                 bne,a   def_F0014968! jumptable F0014968 default case
F0014FF4: e04e0000                 ldsb    [%i0], %l0
F0014FF8: 9010203a                 mov     0x3A, %o0 ! ':'
F0014FFC: 9210001a                 mov     %i2, %o1
F0015000: 400000bc                 call    sub_F00152F0
F0015004: 9410001b                 mov     %i3, %o2
F0015008: 90100015                 mov     %l5, %o0
F001500C: 9210200a                 mov     0xA, %o1
F0015010: 9410001a                 mov     %i2, %o2
F0015014: 9610001b                 mov     %i3, %o3
F0015018: 98102000                 mov     0, %o4
F001501C: 40000016                 call    sub_F0015074
F0015020: 9a102000                 mov     0, %o5
F0015024: 10bffe35                 ba      def_F0014968! jumptable F0014968 default case
F0015028: e04e0000                 ldsb    [%i0], %l0
F001502C: 10bffe32                 ba      loc_F00148F4! jumptable F0014968 case 39
F0015030: ae102000                 mov     0, %l7
F0015034: 81c7e008                 ret
F0015038: 91e80017                 restore %g0, %l7, %o0
