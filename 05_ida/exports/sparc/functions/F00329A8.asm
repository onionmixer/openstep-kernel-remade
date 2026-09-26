F00329A8: 9de3bf90                 save    %sp, -0x70, %sp
F00329AC: ac10200c                 mov     0xC, %l6
F00329B0: d00e0000                 ldub    [%i0], %o0
F00329B4: 900a200f                 and     %o0, 0xF, %o0
F00329B8: 912a2002                 sll     %o0, 2, %o0
F00329BC: a8023fec                 add     %o0, -0x14, %l4
F00329C0: 80a52000                 cmp     %l4, 0
F00329C4: 048000c4                 ble     loc_F0032CD4
F00329C8: a4062014                 add     %i0, 0x14, %l2
F00329CC: 353c0431                 sethi   -0xFEF3C00, %i2
F00329D0: 113c0431aa1223dc         set     _ipaddr, %l5
F00329D8: ae056004                 add     %l5, 4, %l7
F00329DC: e20c8000                 ldub    [%l2], %l1
F00329E0: 80a46000                 cmp     %l1, 0
F00329E4: 028000bc                 be      loc_F0032CD4
F00329E8: 80a46001                 cmp     %l1, 1
F00329EC: 32800004                 bne,a   loc_F00329FC
F00329F0: e60ca001                 ldub    [%l2+1], %l3
F00329F4: 10800009                 ba      loc_F0032A18
F00329F8: a6102001                 mov     1, %l3
F00329FC: 80a4e000                 cmp     %l3, 0
F0032A00: 04800004                 ble     loc_F0032A10
F0032A04: 80a4c014                 cmp     %l3, %l4
F0032A08: 04800005                 ble     loc_F0032A1C
F0032A0C: 80a46044                 cmp     %l1, 0x44 ! 'D'
F0032A10: 108000b7                 ba      loc_F0032CEC
F0032A14: 90063fff                 add     %i0, -1, %o0
F0032A18: 80a46044                 cmp     %l1, 0x44 ! 'D'
F0032A1C: 0280005f                 be      loc_F0032B98
F0032A20: 80a46044                 cmp     %l1, 0x44 ! 'D'
F0032A24: 14800007                 bg      loc_F0032A40
F0032A28: 80a46083                 cmp     %l1, 0x83
F0032A2C: 80a46007                 cmp     %l1, 7
F0032A30: 22800040                 be,a    loc_F0032B30
F0032A34: e00ca002                 ldub    [%l2+2], %l0
F0032A38: 108000a4                 ba      loc_F0032CC8
F0032A3C: a8250013                 sub     %l4, %l3, %l4
F0032A40: 02800004                 be      loc_F0032A50
F0032A44: 80a46089                 cmp     %l1, 0x89
F0032A48: 328000a0                 bne,a   loc_F0032CC8
F0032A4C: a8250013                 sub     %l4, %l3, %l4
F0032A50: e00ca002                 ldub    [%l2+2], %l0
F0032A54: 80a42003                 cmp     %l0, 3
F0032A58: 048000a4                 ble     loc_F0032CE8
F0032A5C: 90100015                 mov     %l5, %o0
F0032A60: d2062010                 ld      [%i0+0x10], %o1
F0032A64: 7fffdb99                 call    _ifa_ifwithaddr
F0032A68: d2256004                 st      %o1, [%l5+4]
F0032A6C: 80a22000                 cmp     %o0, 0
F0032A70: 32800007                 bne,a   loc_F0032A8C
F0032A74: a0043fff                 inc     -1, %l0
F0032A78: 80a46089                 cmp     %l1, 0x89
F0032A7C: 12800093                 bne     loc_F0032CC8
F0032A80: a8250013                 sub     %l4, %l3, %l4
F0032A84: 10800024                 ba      loc_F0032B14
F0032A88: ac102003                 mov     3, %l6
F0032A8C: 9004fffc                 add     %l3, -4, %o0
F0032A90: 80a40008                 cmp     %l0, %o0
F0032A94: 08800008                 bleu    loc_F0032AB4
F0032A98: 90100012                 mov     %l2, %o0
F0032A9C: d406200c                 ld      [%i0+0xC], %o2! size_t
F0032AA0: 9207bff4                 add     %fp, var_C, %o1
F0032AA4: 400000d1                 call    _save_rte
F0032AA8: d427bff4                 st      %o2, [%fp+var_C]
F0032AAC: 10800087                 ba      loc_F0032CC8
F0032AB0: a8250013                 sub     %l4, %l3, %l4
F0032AB4: a0048010                 add     %l2, %l0, %l0
F0032AB8: 90100010                 mov     %l0, %o0! void *
F0032ABC: 92056004                 add     %l5, 4, %o1! void *
F0032AC0: 40018814                 call    _bcopy
F0032AC4: 94102004                 mov     4, %o2
F0032AC8: 80a46089                 cmp     %l1, 0x89
F0032ACC: 1280000b                 bne     loc_F0032AF8
F0032AD0: d2056004                 ld      [%l5+4], %o1
F0032AD4: 9007bff4                 add     %fp, var_C, %o0
F0032AD8: 7fffef1f                 call    _in_netof
F0032ADC: d227bff4                 st      %o1, [%fp+var_C]
F0032AE0: 7ffff1f8                 call    _in_iaonnetof
F0032AE4: 01000000                 nop
F0032AE8: 80a22000                 cmp     %o0, 0
F0032AEC: 2280000a                 be,a    loc_F0032B14
F0032AF0: ac102003                 mov     3, %l6
F0032AF4: d2056004                 ld      [%l5+4], %o1
F0032AF8: 9007bff4                 add     %fp, var_C, %o0
F0032AFC: 40000086                 call    _ip_rtaddr
F0032B00: d227bff4                 st      %o1, [%fp+var_C]
F0032B04: 80a22000                 cmp     %o0, 0
F0032B08: 12800005                 bne     loc_F0032B1C
F0032B0C: 90022004                 inc     4, %o0
F0032B10: ac102003                 mov     3, %l6
F0032B14: 10800077                 ba      loc_F0032CF0
F0032B18: 98102005                 mov     5, %o4
F0032B1C: 92100010                 mov     %l0, %o1
F0032B20: d6056004                 ld      [%l5+4], %o3
F0032B24: 94102004                 mov     4, %o2! size_t
F0032B28: 10800016                 ba      loc_F0032B80
F0032B2C: d6262010                 st      %o3, [%i0+0x10]
F0032B30: 80a42003                 cmp     %l0, 3
F0032B34: 0480006d                 ble     loc_F0032CE8
F0032B38: a0043fff                 inc     -1, %l0
F0032B3C: 9004fffc                 add     %l3, -4, %o0
F0032B40: 80a40008                 cmp     %l0, %o0
F0032B44: 38800061                 bgu,a   loc_F0032CC8
F0032B48: a8250013                 sub     %l4, %l3, %l4
F0032B4C: 90062010                 add     %i0, 0x10, %o0! void *
F0032B50: 9216a3e0                 or      %i2, 0x3E0, %o1! void *
F0032B54: 400187ef                 call    _bcopy
F0032B58: 94102004                 mov     4, %o2
F0032B5C: d206a3e0                 ld      [%i2+0x3E0], %o1
F0032B60: 9007bff4                 add     %fp, var_C, %o0
F0032B64: 4000006c                 call    _ip_rtaddr
F0032B68: d227bff4                 st      %o1, [%fp+var_C]
F0032B6C: 80a22000                 cmp     %o0, 0
F0032B70: 0280005b                 be      loc_F0032CDC
F0032B74: 90022004                 inc     4, %o0! void *
F0032B78: 92048010                 add     %l2, %l0, %o1! void *
F0032B7C: 94102004                 mov     4, %o2! size_t
F0032B80: 400187e4                 call    _bcopy
F0032B84: a8250013                 sub     %l4, %l3, %l4
F0032B88: d00ca002                 ldub    [%l2+2], %o0
F0032B8C: 90022004                 inc     4, %o0
F0032B90: 1080004e                 ba      loc_F0032CC8
F0032B94: d02ca002                 stb     %o0, [%l2+2]
F0032B98: d60ca001                 ldub    [%l2+1], %o3
F0032B9C: 98248018                 sub     %l2, %i0, %o4
F0032BA0: 80a2e004                 cmp     %o3, 4
F0032BA4: 08800053                 bleu    loc_F0032CF0
F0032BA8: a2100012                 mov     %l2, %l1
F0032BAC: d40ca002                 ldub    [%l2+2], %o2
F0032BB0: 9002fffc                 add     %o3, -4, %o0
F0032BB4: 80a28008                 cmp     %o2, %o0
F0032BB8: 0880000e                 bleu    loc_F0032BF0
F0032BBC: d0048000                 ld      [%l2], %o0
F0032BC0: 940a3f0f                 and     %o0, -0xF1, %o2
F0032BC4: 91322004                 srl     %o0, 4, %o0
F0032BC8: 900a200f                 and     %o0, 0xF, %o0
F0032BCC: 90022001                 inc     %o0
F0032BD0: 900a200f                 and     %o0, 0xF, %o0
F0032BD4: 932a2004                 sll     %o0, 4, %o1
F0032BD8: 94128009                 bset    %o1, %o2! size_t
F0032BDC: 80a22000                 cmp     %o0, 0
F0032BE0: 02800044                 be      loc_F0032CF0
F0032BE4: d4248000                 st      %o2, [%l2]
F0032BE8: 10800038                 ba      loc_F0032CC8
F0032BEC: a8250013                 sub     %l4, %l3, %l4
F0032BF0: 920a200f                 and     %o0, 0xF, %o1
F0032BF4: 80a26001                 cmp     %o1, 1
F0032BF8: 9004800a                 add     %l2, %o2, %o0
F0032BFC: 0280000d                 be      loc_F0032C30
F0032C00: a0023fff                 add     %o0, -1, %l0
F0032C04: 80a26001                 cmp     %o1, 1
F0032C08: 14800006                 bg      loc_F0032C20
F0032C0C: 80a26002                 cmp     %o1, 2
F0032C10: 80a26000                 cmp     %o1, 0
F0032C14: 02800021                 be      loc_F0032C98
F0032C18: 90100018                 mov     %i0, %o0
F0032C1C: 30800036                 ba,a    loc_F0032CF4
F0032C20: 02800010                 be      loc_F0032C60
F0032C24: 9002a008                 add     %o2, 8, %o0
F0032C28: 10800033                 ba      loc_F0032CF4
F0032C2C: 90100018                 mov     %i0, %o0
F0032C30: 9002a008                 add     %o2, 8, %o0
F0032C34: 80a2000b                 cmp     %o0, %o3
F0032C38: 1880002f                 bgu     loc_F0032CF4
F0032C3C: 90100018                 mov     %i0, %o0
F0032C40: 7ffffb5a                 call    _ifptoia
F0032C44: 90100019                 mov     %i1, %o0
F0032C48: 90022004                 inc     4, %o0! void *
F0032C4C: 92100010                 mov     %l0, %o1! void *
F0032C50: 400187b0                 call    _bcopy
F0032C54: 94102004                 mov     4, %o2! size_t
F0032C58: 1080000e                 ba      loc_F0032C90
F0032C5C: d00ca002                 ldub    [%l2+2], %o0
F0032C60: 80a2000b                 cmp     %o0, %o3
F0032C64: 18800023                 bgu     loc_F0032CF0
F0032C68: 90100010                 mov     %l0, %o0! void *
F0032C6C: 92100017                 mov     %l7, %o1! void *
F0032C70: 400187a8                 call    _bcopy
F0032C74: 94102004                 mov     4, %o2
F0032C78: 7fffdb14                 call    _ifa_ifwithaddr
F0032C7C: 9005fffc                 add     %l7, -4, %o0
F0032C80: 80a22000                 cmp     %o0, 0
F0032C84: 22800011                 be,a    loc_F0032CC8
F0032C88: a8250013                 sub     %l4, %l3, %l4
F0032C8C: d00ca002                 ldub    [%l2+2], %o0
F0032C90: 90022004                 inc     4, %o0
F0032C94: d02ca002                 stb     %o0, [%l2+2]
F0032C98: 7ffffb77                 call    _iptime
F0032C9C: a8250013                 sub     %l4, %l3, %l4
F0032CA0: d027bff0                 st      %o0, [%fp+var_10]
F0032CA4: 9007bff0                 add     %fp, var_10, %o0! void *
F0032CA8: d20c6002                 ldub    [%l1+2], %o1
F0032CAC: 94102004                 mov     4, %o2! size_t
F0032CB0: 92048009                 add     %l2, %o1, %o1! void *
F0032CB4: 40018797                 call    _bcopy
F0032CB8: 92027fff                 inc     -1, %o1
F0032CBC: d00c6002                 ldub    [%l1+2], %o0
F0032CC0: 90022004                 inc     4, %o0
F0032CC4: d02c6002                 stb     %o0, [%l1+2]
F0032CC8: 80a52000                 cmp     %l4, 0
F0032CCC: 14bfff44                 bg      loc_F00329DC
F0032CD0: a4048013                 add     %l2, %l3, %l2
F0032CD4: 1080000e                 ba      locret_F0032D0C
F0032CD8: b0102000                 mov     0, %i0
F0032CDC: ac102003                 mov     3, %l6
F0032CE0: 10800004                 ba      loc_F0032CF0
F0032CE4: 98102001                 mov     1, %o4
F0032CE8: 90063ffe                 add     %i0, -2, %o0
F0032CEC: 98248008                 sub     %l2, %o0, %o4
F0032CF0: 90100018                 mov     %i0, %o0
F0032CF4: 92100016                 mov     %l6, %o1
F0032CF8: 9410000c                 mov     %o4, %o2
F0032CFC: 96100019                 mov     %i1, %o3
F0032D00: 7ffff8db                 call    _icmp_error
F0032D04: 98102000                 mov     0, %o4
F0032D08: b0102001                 mov     1, %i0
F0032D0C: 81c7e008                 ret
F0032D10: 81e80000                 restore
