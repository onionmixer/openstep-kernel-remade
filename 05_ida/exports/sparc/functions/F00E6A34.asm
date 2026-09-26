F00E6A34: 9de3bf20                 save    %sp, -0xE0, %sp
F00E6A38: f027bfbc                 st      %i0, [%fp+var_44]
F00E6A3C: c20621fc                 ld      [%i0+0x1FC], %g1
F00E6A40: c227bfb4                 st      %g1, [%fp+var_4C]
F00E6A44: 7fff7103                 call    _ev_try_lock
F00E6A48: 90006004                 add     %g1, 4, %o0
F00E6A4C: 80a22000                 cmp     %o0, 0
F00E6A50: 028005b3                 be      loc_F00E811C
F00E6A54: c607bfb4                 ld      [%fp+var_4C], %g3
F00E6A58: f620c000                 st      %i3, [%g3]
F00E6A5C: d0168000                 lduh    [%i2], %o0
F00E6A60: d030e01c                 sth     %o0, [%g3+0x1C]
F00E6A64: d016a002                 lduh    [%i2+2], %o0
F00E6A68: d030e01e                 sth     %o0, [%g3+0x1E]
F00E6A6C: d208e008                 ldub    [%g3+8], %o1
F00E6A70: 90026001                 add     %o1, 1, %o0! id
F00E6A74: d028e008                 stb     %o0, [%g3+8]
F00E6A78: 80a26000                 cmp     %o1, 0
F00E6A7C: 12800099                 bne     loc_F00E6CE0
F00E6A80: c207bfb4                 ld      [%fp+var_4C], %g1
F00E6A84: 213c0504                 sethi   %hi(paDisplayinfo), %l0
F00E6A88: d20423ac                 ld      [%l0+%lo(paDisplayinfo)], %o1! SEL
F00E6A8C: 40002b79                 call    _objc_msgSend
F00E6A90: d007bfbc                 ld      [%fp+var_44], %o0
F00E6A94: d0022018                 ld      [%o0+0x18], %o0! id
F00E6A98: 80a22003                 cmp     %o0, 3
F00E6A9C: 18800008                 bgu     loc_F00E6ABC
F00E6AA0: 80a22002                 cmp     %o0, 2
F00E6AA4: 1a80008e                 bcc     loc_F00E6CDC
F00E6AA8: 80a22001                 cmp     %o0, 1
F00E6AAC: 02800009                 be      loc_F00E6AD0
F00E6AB0: d20423ac                 ld      [%l0+%lo(paDisplayinfo)], %o1
F00E6AB4: 1080008b                 ba      loc_F00E6CE0
F00E6AB8: c207bfb4                 ld      [%fp+var_4C], %g1
F00E6ABC: 80a22004                 cmp     %o0, 4
F00E6AC0: 0280004b                 be      loc_F00E6BEC
F00E6AC4: d20423ac                 ld      [%l0+0x3AC], %o1! SEL
F00E6AC8: 10800086                 ba      loc_F00E6CE0
F00E6ACC: c207bfb4                 ld      [%fp+var_4C], %g1
F00E6AD0: 40002b68                 call    _objc_msgSend
F00E6AD4: d007bfbc                 ld      [%fp+var_44], %o0
F00E6AD8: c207bfbc                 ld      [%fp+var_44], %g1
F00E6ADC: e00061fc                 ld      [%g1+0x1FC], %l0
F00E6AE0: d214200c                 lduh    [%l0+0xC], %o1
F00E6AE4: d237bfe8                 sth     %o1, [%fp+var_18]
F00E6AE8: d214200e                 lduh    [%l0+0xE], %o1
F00E6AEC: d237bfea                 sth     %o1, [%fp+var_16]
F00E6AF0: d4142010                 lduh    [%l0+0x10], %o2
F00E6AF4: a2100008                 mov     %o0, %l1
F00E6AF8: d437bfec                 sth     %o2, [%fp+var_14]
F00E6AFC: d2142012                 lduh    [%l0+0x12], %o1
F00E6B00: 952aa010                 sll     %o2, 16, %o2
F00E6B04: d237bfee                 sth     %o1, [%fp+var_12]
F00E6B08: e4046008                 ld      [%l1+8], %l2
F00E6B0C: 953aa010                 sra     %o2, 16, %o2
F00E6B10: d2142034                 lduh    [%l0+0x34], %o1
F00E6B14: 90100012                 mov     %l2, %o0
F00E6B18: 932a6010                 sll     %o1, 16, %o1
F00E6B1C: 933a6010                 sra     %o1, 16, %o1
F00E6B20: 7ffc7e78                 call    _umul
F00E6B24: 92228009                 sub     %o2, %o1, %o1
F00E6B28: d4046014                 ld      [%l1+0x14], %o2
F00E6B2C: d2142030                 lduh    [%l0+0x30], %o1
F00E6B30: 9a042848                 add     %l0, 0x848, %o5
F00E6B34: d617bfea                 lduh    [%fp+var_16], %o3
F00E6B38: 94028008                 add     %o2, %o0, %o2
F00E6B3C: 932a6010                 sll     %o1, 16, %o1
F00E6B40: d057bfe8                 ldsh    [%fp+var_18], %o0
F00E6B44: 933a6010                 sra     %o1, 16, %o1
F00E6B48: 92220009                 sub     %o0, %o1, %o1
F00E6B4C: 98028009                 add     %o2, %o1, %o4
F00E6B50: 9622c008                 sub     %o3, %o0, %o3
F00E6B54: 932ae010                 sll     %o3, 16, %o1
F00E6B58: 933a6010                 sra     %o1, 16, %o1
F00E6B5C: d017bfee                 lduh    [%fp+var_12], %o0
F00E6B60: d417bfec                 lduh    [%fp+var_14], %o2
F00E6B64: 9022000a                 sub     %o0, %o2, %o0
F00E6B68: 90023fff                 inc     -1, %o0
F00E6B6C: 84100008                 mov     %o0, %g2
F00E6B70: 912a2010                 sll     %o0, 16, %o0
F00E6B74: 913a2010                 sra     %o0, 16, %o0
F00E6B78: 80a23fff                 cmp     %o0, -1
F00E6B7C: 02800058                 be      loc_F00E6CDC
F00E6B80: a4248009                 sub     %l2, %o1, %l2
F00E6B84: 9002ffff                 add     %o3, -1, %o0
F00E6B88: 94100008                 mov     %o0, %o2
F00E6B8C: 912a2010                 sll     %o0, 16, %o0
F00E6B90: 913a2010                 sra     %o0, 16, %o0
F00E6B94: 80a23fff                 cmp     %o0, -1
F00E6B98: 0280000d                 be      loc_F00E6BCC
F00E6B9C: 9000bfff                 add     %g2, -1, %o0
F00E6BA0: 9002bfff                 add     %o2, -1, %o0
F00E6BA4: 94100008                 mov     %o0, %o2
F00E6BA8: d20b4000                 ldub    [%o5], %o1! SEL
F00E6BAC: 912a2010                 sll     %o0, 16, %o0
F00E6BB0: 913a2010                 sra     %o0, 16, %o0
F00E6BB4: 80a23fff                 cmp     %o0, -1
F00E6BB8: d22b0000                 stb     %o1, [%o4]
F00E6BBC: 9a036001                 inc     %o5
F00E6BC0: 12bffff8                 bne     loc_F00E6BA0
F00E6BC4: 98032001                 inc     %o4
F00E6BC8: 9000bfff                 add     %g2, -1, %o0
F00E6BCC: 84100008                 mov     %o0, %g2
F00E6BD0: 912a2010                 sll     %o0, 16, %o0
F00E6BD4: 913a2010                 sra     %o0, 16, %o0! id
F00E6BD8: 80a23fff                 cmp     %o0, -1
F00E6BDC: 12bfffea                 bne     loc_F00E6B84
F00E6BE0: 98030012                 add     %o4, %l2, %o4
F00E6BE4: 1080003f                 ba      loc_F00E6CE0
F00E6BE8: c207bfb4                 ld      [%fp+var_4C], %g1
F00E6BEC: 40002b21                 call    _objc_msgSend
F00E6BF0: d007bfbc                 ld      [%fp+var_44], %o0
F00E6BF4: c607bfbc                 ld      [%fp+var_44], %g3
F00E6BF8: e000e1fc                 ld      [%g3+0x1FC], %l0
F00E6BFC: d214200c                 lduh    [%l0+0xC], %o1
F00E6C00: d237bfe8                 sth     %o1, [%fp+var_18]
F00E6C04: d214200e                 lduh    [%l0+0xE], %o1
F00E6C08: d237bfea                 sth     %o1, [%fp+var_16]
F00E6C0C: d4142010                 lduh    [%l0+0x10], %o2
F00E6C10: a2100008                 mov     %o0, %l1
F00E6C14: d437bfec                 sth     %o2, [%fp+var_14]
F00E6C18: d2142012                 lduh    [%l0+0x12], %o1
F00E6C1C: 952aa010                 sll     %o2, 16, %o2
F00E6C20: d237bfee                 sth     %o1, [%fp+var_12]
F00E6C24: e4046008                 ld      [%l1+8], %l2
F00E6C28: 953aa010                 sra     %o2, 16, %o2
F00E6C2C: d2142034                 lduh    [%l0+0x34], %o1
F00E6C30: 90100012                 mov     %l2, %o0
F00E6C34: 932a6010                 sll     %o1, 16, %o1
F00E6C38: 933a6010                 sra     %o1, 16, %o1
F00E6C3C: 7ffc7e31                 call    _umul
F00E6C40: 92228009                 sub     %o2, %o1, %o1
F00E6C44: 1300000492126048         set     0x1048, %o1
F00E6C4C: d4046014                 ld      [%l1+0x14], %o2
F00E6C50: 98040009                 add     %l0, %o1, %o4
F00E6C54: d2142030                 lduh    [%l0+0x30], %o1
F00E6C58: 912a2002                 sll     %o0, 2, %o0
F00E6C5C: d657bfe8                 ldsh    [%fp+var_18], %o3
F00E6C60: 94028008                 add     %o2, %o0, %o2
F00E6C64: 932a6010                 sll     %o1, 16, %o1
F00E6C68: 933a6010                 sra     %o1, 16, %o1
F00E6C6C: 9222c009                 sub     %o3, %o1, %o1
F00E6C70: 932a6002                 sll     %o1, 2, %o1
F00E6C74: d057bfea                 ldsh    [%fp+var_16], %o0
F00E6C78: 94028009                 add     %o2, %o1, %o2
F00E6C7C: d257bfee                 ldsh    [%fp+var_12], %o1
F00E6C80: 9a22000b                 sub     %o0, %o3, %o5
F00E6C84: d057bfec                 ldsh    [%fp+var_14], %o0
F00E6C88: 92224008                 sub     %o1, %o0, %o1
F00E6C8C: 92027fff                 inc     -1, %o1
F00E6C90: 80a27fff                 cmp     %o1, -1
F00E6C94: 02800012                 be      loc_F00E6CDC
F00E6C98: a424800d                 sub     %l2, %o5, %l2
F00E6C9C: 852ca002                 sll     %l2, 2, %g2
F00E6CA0: 96037fff                 add     %o5, -1, %o3
F00E6CA4: 80a2ffff                 cmp     %o3, -1
F00E6CA8: 2280000a                 be,a    loc_F00E6CD0
F00E6CAC: 92027fff                 inc     -1, %o1
F00E6CB0: 9602ffff                 inc     -1, %o3
F00E6CB4: d0030000                 ld      [%o4], %o0
F00E6CB8: 80a2ffff                 cmp     %o3, -1
F00E6CBC: d0228000                 st      %o0, [%o2]
F00E6CC0: 98032004                 inc     4, %o4
F00E6CC4: 12bffffb                 bne     loc_F00E6CB0
F00E6CC8: 9402a004                 inc     4, %o2
F00E6CCC: 92027fff                 inc     -1, %o1
F00E6CD0: 80a27fff                 cmp     %o1, -1
F00E6CD4: 12bffff3                 bne     loc_F00E6CA0
F00E6CD8: 94028002                 add     %o2, %g2, %o2
F00E6CDC: c207bfb4                 ld      [%fp+var_4C], %g1
F00E6CE0: d0086009                 ldub    [%g1+9], %o0
F00E6CE4: 80a22000                 cmp     %o0, 0
F00E6CE8: 0280000c                 be      loc_F00E6D18
F00E6CEC: c607bfb4                 ld      [%fp+var_4C], %g3
F00E6CF0: c0286009                 clrb    [%g1+9]
F00E6CF4: d0086008                 ldub    [%g1+8], %o0
F00E6CF8: 80a22000                 cmp     %o0, 0
F00E6CFC: 02800007                 be      loc_F00E6D18
F00E6D00: c607bfb4                 ld      [%fp+var_4C], %g3
F00E6D04: d0086008                 ldub    [%g1+8], %o0
F00E6D08: 90023fff                 inc     -1, %o0
F00E6D0C: d0286008                 stb     %o0, [%g1+8]
F00E6D10: d0086008                 ldub    [%g1+8], %o0
F00E6D14: c607bfb4                 ld      [%fp+var_4C], %g3
F00E6D18: d008e00a                 ldub    [%g3+0xA], %o0
F00E6D1C: 80a22000                 cmp     %o0, 0
F00E6D20: 028002ed                 be      loc_F00E78D4
F00E6D24: c207bfbc                 ld      [%fp+var_44], %g1
F00E6D28: d80061fc                 ld      [%g1+0x1FC], %o4
F00E6D2C: d0030000                 ld      [%o4], %o0
F00E6D30: 912a2002                 sll     %o0, 2, %o0
F00E6D34: 9002000c                 add     %o0, %o4, %o0
F00E6D38: d4122038                 lduh    [%o0+0x38], %o2
F00E6D3C: d437bfe0                 sth     %o2, [%fp+var_20]
F00E6D40: d612203a                 lduh    [%o0+0x3A], %o3
F00E6D44: d637bfe2                 sth     %o3, [%fp+var_1E]
F00E6D48: d213201c                 lduh    [%o4+0x1C], %o1
F00E6D4C: 9a102000                 mov     0, %o5
F00E6D50: 9222400a                 sub     %o1, %o2, %o1
F00E6D54: d237bfd8                 sth     %o1, [%fp+var_28]
F00E6D58: 84026010                 add     %o1, 0x10, %g2
F00E6D5C: c437bfda                 sth     %g2, [%fp+var_26]
F00E6D60: d013201e                 lduh    [%o4+0x1E], %o0
F00E6D64: 932a6010                 sll     %o1, 16, %o1
F00E6D68: 9422000b                 sub     %o0, %o3, %o2
F00E6D6C: d437bfdc                 sth     %o2, [%fp+var_24]
F00E6D70: 9602a010                 add     %o2, 0x10, %o3
F00E6D74: d637bfde                 sth     %o3, [%fp+var_22]
F00E6D78: d0132016                 lduh    [%o4+0x16], %o0
F00E6D7C: 933a6010                 sra     %o1, 16, %o1
F00E6D80: 912a2010                 sll     %o0, 16, %o0
F00E6D84: 913a2010                 sra     %o0, 16, %o0
F00E6D88: 80a24008                 cmp     %o1, %o0
F00E6D8C: 1680001b                 bge     loc_F00E6DF8
F00E6D90: 01000000                 nop
F00E6D94: d2132014                 lduh    [%o4+0x14], %o1
F00E6D98: 9128a010                 sll     %g2, 16, %o0
F00E6D9C: 913a2010                 sra     %o0, 16, %o0
F00E6DA0: 932a6010                 sll     %o1, 16, %o1
F00E6DA4: 933a6010                 sra     %o1, 16, %o1
F00E6DA8: 80a24008                 cmp     %o1, %o0
F00E6DAC: 16800013                 bge     loc_F00E6DF8
F00E6DB0: 01000000                 nop
F00E6DB4: d013201a                 lduh    [%o4+0x1A], %o0
F00E6DB8: 932aa010                 sll     %o2, 16, %o1
F00E6DBC: 933a6010                 sra     %o1, 16, %o1
F00E6DC0: 912a2010                 sll     %o0, 16, %o0
F00E6DC4: 913a2010                 sra     %o0, 16, %o0
F00E6DC8: 80a24008                 cmp     %o1, %o0
F00E6DCC: 1680000b                 bge     loc_F00E6DF8
F00E6DD0: 01000000                 nop
F00E6DD4: d2132018                 lduh    [%o4+0x18], %o1
F00E6DD8: 912ae010                 sll     %o3, 16, %o0
F00E6DDC: 913a2010                 sra     %o0, 16, %o0
F00E6DE0: 932a6010                 sll     %o1, 16, %o1
F00E6DE4: 933a6010                 sra     %o1, 16, %o1
F00E6DE8: 80a24008                 cmp     %o1, %o0
F00E6DEC: 26800003                 bl,a    loc_F00E6DF8
F00E6DF0: 9a102001                 mov     1, %o5
F00E6DF4: 9a102000                 mov     0, %o5
F00E6DF8: d00b200b                 ldub    [%o4+0xB], %o0
F00E6DFC: 912a2018                 sll     %o0, 24, %o0
F00E6E00: 913a2018                 sra     %o0, 24, %o0
F00E6E04: 80a34008                 cmp     %o5, %o0
F00E6E08: 228002b4                 be,a    loc_F00E78D8
F00E6E0C: c207bfb4                 ld      [%fp+var_4C], %g1
F00E6E10: da2b200b                 stb     %o5, [%o4+0xB]
F00E6E14: d00b200b                 ldub    [%o4+0xB], %o0
F00E6E18: 80a22000                 cmp     %o0, 0
F00E6E1C: 028000a1                 be      loc_F00E70A0
F00E6E20: c607bfbc                 ld      [%fp+var_44], %g3
F00E6E24: d000e1fc                 ld      [%g3+0x1FC], %o0! id
F00E6E28: d40a2008                 ldub    [%o0+8], %o2
F00E6E2C: 9202a001                 add     %o2, 1, %o1
F00E6E30: d22a2008                 stb     %o1, [%o0+8]
F00E6E34: 80a2a000                 cmp     %o2, 0
F00E6E38: 128002a8                 bne     loc_F00E78D8
F00E6E3C: c207bfb4                 ld      [%fp+var_4C], %g1
F00E6E40: 213c0504                 sethi   %hi(paDisplayinfo), %l0
F00E6E44: d20423ac                 ld      [%l0+%lo(paDisplayinfo)], %o1! SEL
F00E6E48: 40002a8a                 call    _objc_msgSend
F00E6E4C: d007bfbc                 ld      [%fp+var_44], %o0
F00E6E50: d0022018                 ld      [%o0+0x18], %o0! id
F00E6E54: 80a22003                 cmp     %o0, 3
F00E6E58: 18800008                 bgu     loc_F00E6E78
F00E6E5C: 80a22002                 cmp     %o0, 2
F00E6E60: 1a80029d                 bcc     loc_F00E78D4
F00E6E64: 80a22001                 cmp     %o0, 1
F00E6E68: 02800009                 be      loc_F00E6E8C
F00E6E6C: d20423ac                 ld      [%l0+%lo(paDisplayinfo)], %o1
F00E6E70: 1080029a                 ba      loc_F00E78D8
F00E6E74: c207bfb4                 ld      [%fp+var_4C], %g1
F00E6E78: 80a22004                 cmp     %o0, 4
F00E6E7C: 0280004b                 be      loc_F00E6FA8
F00E6E80: d20423ac                 ld      [%l0+0x3AC], %o1! SEL
F00E6E84: 10800295                 ba      loc_F00E78D8
F00E6E88: c207bfb4                 ld      [%fp+var_4C], %g1
F00E6E8C: 40002a79                 call    _objc_msgSend
F00E6E90: d007bfbc                 ld      [%fp+var_44], %o0
F00E6E94: c207bfbc                 ld      [%fp+var_44], %g1
F00E6E98: e00061fc                 ld      [%g1+0x1FC], %l0
F00E6E9C: d214200c                 lduh    [%l0+0xC], %o1
F00E6EA0: d237bfd0                 sth     %o1, [%fp+var_30]
F00E6EA4: d214200e                 lduh    [%l0+0xE], %o1
F00E6EA8: d237bfd2                 sth     %o1, [%fp+var_2E]
F00E6EAC: d4142010                 lduh    [%l0+0x10], %o2
F00E6EB0: a2100008                 mov     %o0, %l1
F00E6EB4: d437bfd4                 sth     %o2, [%fp+var_2C]
F00E6EB8: d2142012                 lduh    [%l0+0x12], %o1
F00E6EBC: 952aa010                 sll     %o2, 16, %o2
F00E6EC0: d237bfd6                 sth     %o1, [%fp+var_2A]
F00E6EC4: e4046008                 ld      [%l1+8], %l2
F00E6EC8: 953aa010                 sra     %o2, 16, %o2
F00E6ECC: d2142034                 lduh    [%l0+0x34], %o1
F00E6ED0: 90100012                 mov     %l2, %o0
F00E6ED4: 932a6010                 sll     %o1, 16, %o1
F00E6ED8: 933a6010                 sra     %o1, 16, %o1
F00E6EDC: 7ffc7d89                 call    _umul
F00E6EE0: 92228009                 sub     %o2, %o1, %o1
F00E6EE4: d4046014                 ld      [%l1+0x14], %o2
F00E6EE8: d2142030                 lduh    [%l0+0x30], %o1
F00E6EEC: 9a042848                 add     %l0, 0x848, %o5
F00E6EF0: d617bfd2                 lduh    [%fp+var_2E], %o3
F00E6EF4: 94028008                 add     %o2, %o0, %o2
F00E6EF8: 932a6010                 sll     %o1, 16, %o1
F00E6EFC: d057bfd0                 ldsh    [%fp+var_30], %o0
F00E6F00: 933a6010                 sra     %o1, 16, %o1
F00E6F04: 92220009                 sub     %o0, %o1, %o1
F00E6F08: 98028009                 add     %o2, %o1, %o4
F00E6F0C: 9622c008                 sub     %o3, %o0, %o3
F00E6F10: 932ae010                 sll     %o3, 16, %o1
F00E6F14: 933a6010                 sra     %o1, 16, %o1
F00E6F18: d017bfd6                 lduh    [%fp+var_2A], %o0
F00E6F1C: d417bfd4                 lduh    [%fp+var_2C], %o2
F00E6F20: 9022000a                 sub     %o0, %o2, %o0
F00E6F24: 90023fff                 inc     -1, %o0
F00E6F28: 84100008                 mov     %o0, %g2
F00E6F2C: 912a2010                 sll     %o0, 16, %o0
F00E6F30: 913a2010                 sra     %o0, 16, %o0
F00E6F34: 80a23fff                 cmp     %o0, -1
F00E6F38: 02800267                 be      loc_F00E78D4
F00E6F3C: a4248009                 sub     %l2, %o1, %l2
F00E6F40: 9002ffff                 add     %o3, -1, %o0
F00E6F44: 94100008                 mov     %o0, %o2
F00E6F48: 912a2010                 sll     %o0, 16, %o0
F00E6F4C: 913a2010                 sra     %o0, 16, %o0
F00E6F50: 80a23fff                 cmp     %o0, -1
F00E6F54: 0280000d                 be      loc_F00E6F88
F00E6F58: 9000bfff                 add     %g2, -1, %o0
F00E6F5C: 9002bfff                 add     %o2, -1, %o0
F00E6F60: 94100008                 mov     %o0, %o2
F00E6F64: d20b4000                 ldub    [%o5], %o1! SEL
F00E6F68: 912a2010                 sll     %o0, 16, %o0
F00E6F6C: 913a2010                 sra     %o0, 16, %o0
F00E6F70: 80a23fff                 cmp     %o0, -1
F00E6F74: d22b0000                 stb     %o1, [%o4]
F00E6F78: 9a036001                 inc     %o5
F00E6F7C: 12bffff8                 bne     loc_F00E6F5C
F00E6F80: 98032001                 inc     %o4
F00E6F84: 9000bfff                 add     %g2, -1, %o0
F00E6F88: 84100008                 mov     %o0, %g2
F00E6F8C: 912a2010                 sll     %o0, 16, %o0
F00E6F90: 913a2010                 sra     %o0, 16, %o0! id
F00E6F94: 80a23fff                 cmp     %o0, -1
F00E6F98: 12bfffea                 bne     loc_F00E6F40
F00E6F9C: 98030012                 add     %o4, %l2, %o4
F00E6FA0: 1080024e                 ba      loc_F00E78D8
F00E6FA4: c207bfb4                 ld      [%fp+var_4C], %g1
F00E6FA8: 40002a32                 call    _objc_msgSend
F00E6FAC: d007bfbc                 ld      [%fp+var_44], %o0
F00E6FB0: c607bfbc                 ld      [%fp+var_44], %g3
F00E6FB4: e000e1fc                 ld      [%g3+0x1FC], %l0
F00E6FB8: d214200c                 lduh    [%l0+0xC], %o1
F00E6FBC: d237bfd0                 sth     %o1, [%fp+var_30]
F00E6FC0: d214200e                 lduh    [%l0+0xE], %o1
F00E6FC4: d237bfd2                 sth     %o1, [%fp+var_2E]
F00E6FC8: d4142010                 lduh    [%l0+0x10], %o2
F00E6FCC: a2100008                 mov     %o0, %l1
F00E6FD0: d437bfd4                 sth     %o2, [%fp+var_2C]
F00E6FD4: d2142012                 lduh    [%l0+0x12], %o1
F00E6FD8: 952aa010                 sll     %o2, 16, %o2
F00E6FDC: d237bfd6                 sth     %o1, [%fp+var_2A]
F00E6FE0: e4046008                 ld      [%l1+8], %l2
F00E6FE4: 953aa010                 sra     %o2, 16, %o2
F00E6FE8: d2142034                 lduh    [%l0+0x34], %o1
F00E6FEC: 90100012                 mov     %l2, %o0
F00E6FF0: 932a6010                 sll     %o1, 16, %o1
F00E6FF4: 933a6010                 sra     %o1, 16, %o1
F00E6FF8: 7ffc7d42                 call    _umul
F00E6FFC: 92228009                 sub     %o2, %o1, %o1
F00E7000: 1300000492126048         set     0x1048, %o1
F00E7008: d4046014                 ld      [%l1+0x14], %o2
F00E700C: 98040009                 add     %l0, %o1, %o4
F00E7010: d2142030                 lduh    [%l0+0x30], %o1
F00E7014: 912a2002                 sll     %o0, 2, %o0
F00E7018: d657bfd0                 ldsh    [%fp+var_30], %o3
F00E701C: 94028008                 add     %o2, %o0, %o2
F00E7020: 932a6010                 sll     %o1, 16, %o1
F00E7024: 933a6010                 sra     %o1, 16, %o1
F00E7028: 9222c009                 sub     %o3, %o1, %o1
F00E702C: 932a6002                 sll     %o1, 2, %o1
F00E7030: d057bfd2                 ldsh    [%fp+var_2E], %o0
F00E7034: 94028009                 add     %o2, %o1, %o2
F00E7038: d257bfd6                 ldsh    [%fp+var_2A], %o1
F00E703C: 9a22000b                 sub     %o0, %o3, %o5
F00E7040: d057bfd4                 ldsh    [%fp+var_2C], %o0
F00E7044: 92224008                 sub     %o1, %o0, %o1
F00E7048: 92027fff                 inc     -1, %o1
F00E704C: 80a27fff                 cmp     %o1, -1
F00E7050: 02800221                 be      loc_F00E78D4
F00E7054: a424800d                 sub     %l2, %o5, %l2
F00E7058: 852ca002                 sll     %l2, 2, %g2
F00E705C: 96037fff                 add     %o5, -1, %o3
F00E7060: 80a2ffff                 cmp     %o3, -1
F00E7064: 2280000a                 be,a    loc_F00E708C
F00E7068: 92027fff                 inc     -1, %o1
F00E706C: 9602ffff                 inc     -1, %o3
F00E7070: d0030000                 ld      [%o4], %o0
F00E7074: 80a2ffff                 cmp     %o3, -1
F00E7078: d0228000                 st      %o0, [%o2]
F00E707C: 98032004                 inc     4, %o4
F00E7080: 12bffffb                 bne     loc_F00E706C
F00E7084: 9402a004                 inc     4, %o2
F00E7088: 92027fff                 inc     -1, %o1
F00E708C: 80a27fff                 cmp     %o1, -1
F00E7090: 12bffff3                 bne     loc_F00E705C
F00E7094: 94028002                 add     %o2, %g2, %o2
F00E7098: 10800210                 ba      loc_F00E78D8
F00E709C: c207bfb4                 ld      [%fp+var_4C], %g1
F00E70A0: c207bfbc                 ld      [%fp+var_44], %g1
F00E70A4: d20061fc                 ld      [%g1+0x1FC], %o1
F00E70A8: d00a6008                 ldub    [%o1+8], %o0
F00E70AC: 80a22000                 cmp     %o0, 0
F00E70B0: 2280020a                 be,a    loc_F00E78D8
F00E70B4: c207bfb4                 ld      [%fp+var_4C], %g1
F00E70B8: d00a6008                 ldub    [%o1+8], %o0
F00E70BC: 90023fff                 inc     -1, %o0
F00E70C0: d02a6008                 stb     %o0, [%o1+8]
F00E70C4: d00a6008                 ldub    [%o1+8], %o0
F00E70C8: 80a22000                 cmp     %o0, 0
F00E70CC: 32800203                 bne,a   loc_F00E78D8
F00E70D0: c207bfb4                 ld      [%fp+var_4C], %g1
F00E70D4: c60061fc                 ld      [%g1+0x1FC], %g3
F00E70D8: d000c000                 ld      [%g3], %o0
F00E70DC: 912a2002                 sll     %o0, 2, %o0
F00E70E0: 90020003                 add     %o0, %g3, %o0
F00E70E4: d2122038                 lduh    [%o0+0x38], %o1
F00E70E8: d237bfc8                 sth     %o1, [%fp+var_38]
F00E70EC: d012203a                 lduh    [%o0+0x3A], %o0
F00E70F0: d037bfca                 sth     %o0, [%fp+var_36]
F00E70F4: d010e01c                 lduh    [%g3+0x1C], %o0
F00E70F8: 90220009                 sub     %o0, %o1, %o0
F00E70FC: d030e020                 sth     %o0, [%g3+0x20]
F00E7100: d010e020                 lduh    [%g3+0x20], %o0
F00E7104: 90022010                 inc     0x10, %o0
F00E7108: d030e022                 sth     %o0, [%g3+0x22]
F00E710C: d210e01e                 lduh    [%g3+0x1E], %o1
F00E7110: d417bfca                 lduh    [%fp+var_36], %o2
F00E7114: 213c0504                 sethi   %hi(paDisplayinfo), %l0
F00E7118: d007bfbc                 ld      [%fp+var_44], %o0! id
F00E711C: 9222400a                 sub     %o1, %o2, %o1
F00E7120: d230e024                 sth     %o1, [%g3+0x24]
F00E7124: d410e024                 lduh    [%g3+0x24], %o2
F00E7128: c627bfac                 st      %g3, [%fp+var_54]
F00E712C: d20423ac                 ld      [%l0+%lo(paDisplayinfo)], %o1! SEL
F00E7130: 9402a010                 inc     0x10, %o2
F00E7134: d430e026                 sth     %o2, [%g3+0x26]
F00E7138: 400029ce                 call    _objc_msgSend
F00E713C: 01000000                 nop
F00E7140: d0022018                 ld      [%o0+0x18], %o0! id
F00E7144: 80a22003                 cmp     %o0, 3
F00E7148: 18800008                 bgu     loc_F00E7168
F00E714C: 80a22002                 cmp     %o0, 2
F00E7150: 1a8001d8                 bcc     loc_F00E78B0
F00E7154: 80a22001                 cmp     %o0, 1
F00E7158: 02800009                 be      loc_F00E717C
F00E715C: d20423ac                 ld      [%l0+0x3AC], %o1
F00E7160: 108001d5                 ba      loc_F00E78B4
F00E7164: c607bfac                 ld      [%fp+var_54], %g3
F00E7168: 80a22004                 cmp     %o0, 4
F00E716C: 028000f2                 be      loc_F00E7534
F00E7170: d20423ac                 ld      [%l0+0x3AC], %o1! SEL
F00E7174: 108001d0                 ba      loc_F00E78B4
F00E7178: c607bfac                 ld      [%fp+var_54], %g3
F00E717C: 400029bd                 call    _objc_msgSend
F00E7180: d007bfbc                 ld      [%fp+var_44], %o0
F00E7184: c207bfbc                 ld      [%fp+var_44], %g1
F00E7188: e00061fc                 ld      [%g1+0x1FC], %l0
F00E718C: d8142020                 lduh    [%l0+0x20], %o4
F00E7190: d837bfc0                 sth     %o4, [%fp+var_40]
F00E7194: da142022                 lduh    [%l0+0x22], %o5
F00E7198: da37bfc2                 sth     %o5, [%fp+var_3E]
F00E719C: d4142024                 lduh    [%l0+0x24], %o2
F00E71A0: a2100008                 mov     %o0, %l1
F00E71A4: d437bfc4                 sth     %o2, [%fp+var_3C]
F00E71A8: d6142026                 lduh    [%l0+0x26], %o3
F00E71AC: 952aa010                 sll     %o2, 16, %o2
F00E71B0: d637bfc6                 sth     %o3, [%fp+var_3A]
F00E71B4: d2142034                 lduh    [%l0+0x34], %o1
F00E71B8: 953aa010                 sra     %o2, 16, %o2
F00E71BC: 932a6010                 sll     %o1, 16, %o1
F00E71C0: 933a6010                 sra     %o1, 16, %o1
F00E71C4: 80a28009                 cmp     %o2, %o1
F00E71C8: 16800004                 bge     loc_F00E71D8
F00E71CC: 01000000                 nop
F00E71D0: d0142034                 lduh    [%l0+0x34], %o0
F00E71D4: d037bfc4                 sth     %o0, [%fp+var_3C]
F00E71D8: d0142036                 lduh    [%l0+0x36], %o0
F00E71DC: 932ae010                 sll     %o3, 16, %o1
F00E71E0: 933a6010                 sra     %o1, 16, %o1
F00E71E4: 912a2010                 sll     %o0, 16, %o0
F00E71E8: 913a2010                 sra     %o0, 16, %o0
F00E71EC: 80a24008                 cmp     %o1, %o0
F00E71F0: 04800004                 ble     loc_F00E7200
F00E71F4: 01000000                 nop
F00E71F8: d0142036                 lduh    [%l0+0x36], %o0
F00E71FC: d037bfc6                 sth     %o0, [%fp+var_3A]
F00E7200: d0142030                 lduh    [%l0+0x30], %o0
F00E7204: 932b2010                 sll     %o4, 16, %o1
F00E7208: 933a6010                 sra     %o1, 16, %o1
F00E720C: 912a2010                 sll     %o0, 16, %o0
F00E7210: 913a2010                 sra     %o0, 16, %o0
F00E7214: 80a24008                 cmp     %o1, %o0
F00E7218: 16800004                 bge     loc_F00E7228
F00E721C: 01000000                 nop
F00E7220: d0142030                 lduh    [%l0+0x30], %o0
F00E7224: d037bfc0                 sth     %o0, [%fp+var_40]
F00E7228: d0142032                 lduh    [%l0+0x32], %o0
F00E722C: 932b6010                 sll     %o5, 16, %o1
F00E7230: 933a6010                 sra     %o1, 16, %o1
F00E7234: 912a2010                 sll     %o0, 16, %o0
F00E7238: 913a2010                 sra     %o0, 16, %o0
F00E723C: 80a24008                 cmp     %o1, %o0
F00E7240: 04800005                 ble     loc_F00E7254
F00E7244: d017bfc0                 lduh    [%fp+var_40], %o0
F00E7248: d0142032                 lduh    [%l0+0x32], %o0
F00E724C: d037bfc2                 sth     %o0, [%fp+var_3E]
F00E7250: d017bfc0                 lduh    [%fp+var_40], %o0
F00E7254: d034200c                 sth     %o0, [%l0+0xC]
F00E7258: d017bfc2                 lduh    [%fp+var_3E], %o0
F00E725C: d034200e                 sth     %o0, [%l0+0xE]
F00E7260: d017bfc4                 lduh    [%fp+var_3C], %o0
F00E7264: d0342010                 sth     %o0, [%l0+0x10]
F00E7268: d017bfc6                 lduh    [%fp+var_3A], %o0
F00E726C: d0342012                 sth     %o0, [%l0+0x12]
F00E7270: c6046008                 ld      [%l1+8], %g3
F00E7274: d2142034                 lduh    [%l0+0x34], %o1
F00E7278: d457bfc4                 ldsh    [%fp+var_3C], %o2
F00E727C: c627bfa4                 st      %g3, [%fp+var_5C]
F00E7280: 932a6010                 sll     %o1, 16, %o1
F00E7284: 933a6010                 sra     %o1, 16, %o1
F00E7288: d007bfa4                 ld      [%fp+var_5C], %o0
F00E728C: 7ffc7c9d                 call    _umul
F00E7290: 92228009                 sub     %o2, %o1, %o1
F00E7294: d4046014                 ld      [%l1+0x14], %o2
F00E7298: d2142030                 lduh    [%l0+0x30], %o1
F00E729C: d657bfc0                 ldsh    [%fp+var_40], %o3
F00E72A0: ae042848                 add     %l0, 0x848, %l7
F00E72A4: c207bfa4                 ld      [%fp+var_5C], %g1
F00E72A8: 94028008                 add     %o2, %o0, %o2
F00E72AC: 932a6010                 sll     %o1, 16, %o1
F00E72B0: 933a6010                 sra     %o1, 16, %o1
F00E72B4: 9222c009                 sub     %o3, %o1, %o1
F00E72B8: d057bfc2                 ldsh    [%fp+var_3E], %o0
F00E72BC: b4028009                 add     %o2, %o1, %i2
F00E72C0: d204601c                 ld      [%l1+0x1C], %o1
F00E72C4: 9022000b                 sub     %o0, %o3, %o0
F00E72C8: d027bf9c                 st      %o0, [%fp+var_64]
F00E72CC: 82204008                 sub     %g1, %o0, %g1
F00E72D0: c227bfa4                 st      %g1, [%fp+var_5C]
F00E72D4: d0040000                 ld      [%l0], %o0
F00E72D8: 80a26001                 cmp     %o1, 1
F00E72DC: c607bf9c                 ld      [%fp+var_64], %g3
F00E72E0: 912a2008                 sll     %o0, 8, %o0
F00E72E4: 90022048                 inc     0x48, %o0 ! 'H'
F00E72E8: d4040000                 ld      [%l0], %o2
F00E72EC: a8040008                 add     %l0, %o0, %l4
F00E72F0: 952aa008                 sll     %o2, 8, %o2
F00E72F4: 9402a448                 inc     0x448, %o2
F00E72F8: d2142024                 lduh    [%l0+0x24], %o1
F00E72FC: b604000a                 add     %l0, %o2, %i3
F00E7300: d457bfc4                 ldsh    [%fp+var_3C], %o2
F00E7304: 932a6010                 sll     %o1, 16, %o1
F00E7308: 933a6010                 sra     %o1, 16, %o1
F00E730C: 92228009                 sub     %o2, %o1, %o1
F00E7310: d0142020                 lduh    [%l0+0x20], %o0
F00E7314: 932a6004                 sll     %o1, 4, %o1
F00E7318: 912a2010                 sll     %o0, 16, %o0
F00E731C: 913a2010                 sra     %o0, 16, %o0
F00E7320: 9622c008                 sub     %o3, %o0, %o3
F00E7324: aa02400b                 add     %o1, %o3, %l5
F00E7328: a8050015                 add     %l4, %l5, %l4
F00E732C: d057bfc6                 ldsh    [%fp+var_3A], %o0
F00E7330: b606c015                 add     %i3, %l5, %i3
F00E7334: 9222000a                 sub     %o0, %o2, %o1
F00E7338: 90102010                 mov     0x10, %o0
F00E733C: 12800023                 bne     loc_F00E73C8
F00E7340: b2220003                 sub     %o0, %g3, %i1
F00E7344: aa827fff                 addcc   %o1, -1, %l5
F00E7348: 0c80015a                 bneg    loc_F00E78B0
F00E734C: a21020ff                 mov     0xFF, %l1
F00E7350: c207bf9c                 ld      [%fp+var_64], %g1
F00E7354: a4807fff                 addcc   %g1, -1, %l2
F00E7358: 2c800015                 bneg,a  loc_F00E73AC
F00E735C: a8050019                 add     %l4, %i1, %l4
F00E7360: d00e8000                 ldub    [%i2], %o0
F00E7364: d02dc000                 stb     %o0, [%l7]
F00E7368: ae05e001                 inc     %l7
F00E736C: e00d0000                 ldub    [%l4], %l0
F00E7370: d20ec000                 ldub    [%i3], %o1
F00E7374: a8052001                 inc     %l4
F00E7378: 7ffc7c62                 call    _umul
F00E737C: 92244009                 sub     %l1, %o1, %o1
F00E7380: b606e001                 inc     %i3
F00E7384: 933a2008                 sra     %o0, 8, %o1
F00E7388: 90020009                 add     %o0, %o1, %o0
F00E738C: 90022001                 inc     %o0
F00E7390: 913a2008                 sra     %o0, 8, %o0
F00E7394: a0040008                 add     %l0, %o0, %l0
F00E7398: e02e8000                 stb     %l0, [%i2]
F00E739C: a484bfff                 inccc   -1, %l2
F00E73A0: 1cbffff0                 bpos    loc_F00E7360
F00E73A4: b406a001                 inc     %i2
F00E73A8: a8050019                 add     %l4, %i1, %l4
F00E73AC: b606c019                 add     %i3, %i1, %i3
F00E73B0: c607bfa4                 ld      [%fp+var_5C], %g3
F00E73B4: aa857fff                 inccc   -1, %l5
F00E73B8: 1cbfffe6                 bpos    loc_F00E7350
F00E73BC: b4068003                 add     %i2, %g3, %i2
F00E73C0: 1080013d                 ba      loc_F00E78B4
F00E73C4: c607bfac                 ld      [%fp+var_54], %g3
F00E73C8: c207bfbc                 ld      [%fp+var_44], %g1
F00E73CC: fa006208                 ld      [%g1+0x208], %i5
F00E73D0: aa827fff                 addcc   %o1, -1, %l5
F00E73D4: 0c800137                 bneg    loc_F00E78B0
F00E73D8: ec00620c                 ld      [%g1+0x20C], %l6
F00E73DC: 113fc03fb0122300         set     -0xFF0100, %i0
F00E73E4: c607bf9c                 ld      [%fp+var_64], %g3
F00E73E8: a480ffff                 addcc   %g3, -1, %l2
F00E73EC: 0c80004a                 bneg    loc_F00E7514
F00E73F0: 11003fc0                 sethi   0xFF0000, %o0
F00E73F4: b81220ff                 or      %o0, 0xFF, %i4
F00E73F8: d00e8000                 ldub    [%i2], %o0
F00E73FC: d02dc000                 stb     %o0, [%l7]
F00E7400: e00ec000                 ldub    [%i3], %l0
F00E7404: 80a42000                 cmp     %l0, 0
F00E7408: 2280003e                 be,a    loc_F00E7500
F00E740C: ae05e001                 inc     %l7
F00E7410: e60d0000                 ldub    [%l4], %l3
F00E7414: 90380010                 xnor    %g0, %l0, %o0
F00E7418: 808a20ff                 btst    0xFF, %o0
F00E741C: 02800037                 be      loc_F00E74F8
F00E7420: a0100008                 mov     %o0, %l0
F00E7424: d00e8000                 ldub    [%i2], %o0
F00E7428: a00c20ff                 and     %l0, 0xFF, %l0
F00E742C: 912a2002                 sll     %o0, 2, %o0
F00E7430: e2074008                 ld      [%i5+%o0], %l1
F00E7434: 92100010                 mov     %l0, %o1
F00E7438: 900c4018                 and     %l1, %i0, %o0
F00E743C: 7ffc7c31                 call    _umul
F00E7440: 91322008                 srl     %o0, 8, %o0
F00E7444: 94100008                 mov     %o0, %o2
F00E7448: 900c401c                 and     %l1, %i4, %o0
F00E744C: 92100010                 mov     %l0, %o1
F00E7450: 0300004082106001         set     0x10001, %g1
F00E7458: a0028001                 add     %o2, %g1, %l0
F00E745C: 940a8018                 and     %o2, %i0, %o2
F00E7460: 9532a008                 srl     %o2, 8, %o2
F00E7464: 7ffc7c27                 call    _umul
F00E7468: a004000a                 add     %l0, %o2, %l0
F00E746C: 070000408610e001         set     0x10001, %g3
F00E7474: 92020003                 add     %o0, %g3, %o1
F00E7478: 900a0018                 and     %o0, %i0, %o0
F00E747C: 91322008                 srl     %o0, 8, %o0
F00E7480: 92024008                 add     %o1, %o0, %o1
F00E7484: a00c0018                 and     %l0, %i0, %l0
F00E7488: 93326008                 srl     %o1, 8, %o1
F00E748C: 920a401c                 and     %o1, %i4, %o1
F00E7490: 912ce002                 sll     %l3, 2, %o0
F00E7494: a0140009                 bset    %o1, %l0
F00E7498: 03003fff                 sethi   0xFFFC00, %g1
F00E749C: d0074008                 ld      [%i5+%o0], %o0
F00E74A0: 82106300                 bset    0x300, %g1
F00E74A4: 900a3f00                 and     %o0, -0x100, %o0
F00E74A8: a2020010                 add     %o0, %l0, %l1
F00E74AC: 97346008                 srl     %l1, 8, %o3
F00E74B0: 901c400b                 xor     %l1, %o3, %o0
F00E74B4: 808a0001                 btst    %g1, %o0
F00E74B8: 0280000d                 be      loc_F00E74EC
F00E74BC: 93346018                 srl     %l1, 24, %o1
F00E74C0: 91346010                 srl     %l1, 16, %o0
F00E74C4: 900a20ff                 and     %o0, 0xFF, %o0
F00E74C8: d40d8009                 ldub    [%l6+%o1], %o2
F00E74CC: 90020016                 add     %o0, %l6, %o0
F00E74D0: 920ae0ff                 and     %o3, 0xFF, %o1
F00E74D4: d60a2100                 ldub    [%o0+0x100], %o3
F00E74D8: 92024016                 add     %o1, %l6, %o1! SEL
F00E74DC: d00a6200                 ldub    [%o1+0x200], %o0
F00E74E0: 9402800b                 add     %o2, %o3, %o2
F00E74E4: 10800005                 ba      loc_F00E74F8
F00E74E8: a602000a                 add     %o0, %o2, %l3
F00E74EC: 91346018                 srl     %l1, 24, %o0
F00E74F0: 90020016                 add     %o0, %l6, %o0! id
F00E74F4: e60a2300                 ldub    [%o0+0x300], %l3
F00E74F8: e62e8000                 stb     %l3, [%i2]
F00E74FC: ae05e001                 inc     %l7
F00E7500: b606e001                 inc     %i3
F00E7504: a8052001                 inc     %l4
F00E7508: a484bfff                 inccc   -1, %l2
F00E750C: 1cbfffbb                 bpos    loc_F00E73F8
F00E7510: b406a001                 inc     %i2
F00E7514: a8050019                 add     %l4, %i1, %l4
F00E7518: b606c019                 add     %i3, %i1, %i3
F00E751C: c607bfa4                 ld      [%fp+var_5C], %g3
F00E7520: aa857fff                 inccc   -1, %l5
F00E7524: 1cbfffb0                 bpos    loc_F00E73E4
F00E7528: b4068003                 add     %i2, %g3, %i2
F00E752C: 108000e2                 ba      loc_F00E78B4
F00E7530: c607bfac                 ld      [%fp+var_54], %g3
F00E7534: 400028cf                 call    _objc_msgSend
F00E7538: d007bfbc                 ld      [%fp+var_44], %o0
F00E753C: c207bfbc                 ld      [%fp+var_44], %g1
F00E7540: e00061fc                 ld      [%g1+0x1FC], %l0
F00E7544: d8142020                 lduh    [%l0+0x20], %o4
F00E7548: d837bfc0                 sth     %o4, [%fp+var_40]
F00E754C: da142022                 lduh    [%l0+0x22], %o5
F00E7550: da37bfc2                 sth     %o5, [%fp+var_3E]
F00E7554: d4142024                 lduh    [%l0+0x24], %o2
F00E7558: a2100008                 mov     %o0, %l1
F00E755C: d437bfc4                 sth     %o2, [%fp+var_3C]
F00E7560: d6142026                 lduh    [%l0+0x26], %o3
F00E7564: 952aa010                 sll     %o2, 16, %o2
F00E7568: d637bfc6                 sth     %o3, [%fp+var_3A]
F00E756C: d2142034                 lduh    [%l0+0x34], %o1
F00E7570: 953aa010                 sra     %o2, 16, %o2
F00E7574: 932a6010                 sll     %o1, 16, %o1
F00E7578: 933a6010                 sra     %o1, 16, %o1
F00E757C: 80a28009                 cmp     %o2, %o1
F00E7580: 16800004                 bge     loc_F00E7590
F00E7584: 01000000                 nop
F00E7588: d0142034                 lduh    [%l0+0x34], %o0
F00E758C: d037bfc4                 sth     %o0, [%fp+var_3C]
F00E7590: d0142036                 lduh    [%l0+0x36], %o0
F00E7594: 932ae010                 sll     %o3, 16, %o1
F00E7598: 933a6010                 sra     %o1, 16, %o1
F00E759C: 912a2010                 sll     %o0, 16, %o0
F00E75A0: 913a2010                 sra     %o0, 16, %o0
F00E75A4: 80a24008                 cmp     %o1, %o0
F00E75A8: 04800004                 ble     loc_F00E75B8
F00E75AC: 01000000                 nop
F00E75B0: d0142036                 lduh    [%l0+0x36], %o0
F00E75B4: d037bfc6                 sth     %o0, [%fp+var_3A]
F00E75B8: d0142030                 lduh    [%l0+0x30], %o0
F00E75BC: 932b2010                 sll     %o4, 16, %o1
F00E75C0: 933a6010                 sra     %o1, 16, %o1
F00E75C4: 912a2010                 sll     %o0, 16, %o0
F00E75C8: 913a2010                 sra     %o0, 16, %o0
F00E75CC: 80a24008                 cmp     %o1, %o0
F00E75D0: 16800004                 bge     loc_F00E75E0
F00E75D4: 01000000                 nop
F00E75D8: d0142030                 lduh    [%l0+0x30], %o0
F00E75DC: d037bfc0                 sth     %o0, [%fp+var_40]
F00E75E0: d0142032                 lduh    [%l0+0x32], %o0
F00E75E4: 932b6010                 sll     %o5, 16, %o1
F00E75E8: 933a6010                 sra     %o1, 16, %o1
F00E75EC: 912a2010                 sll     %o0, 16, %o0
F00E75F0: 913a2010                 sra     %o0, 16, %o0
F00E75F4: 80a24008                 cmp     %o1, %o0
F00E75F8: 04800005                 ble     loc_F00E760C
F00E75FC: d017bfc0                 lduh    [%fp+var_40], %o0
F00E7600: d0142032                 lduh    [%l0+0x32], %o0
F00E7604: d037bfc2                 sth     %o0, [%fp+var_3E]
F00E7608: d017bfc0                 lduh    [%fp+var_40], %o0
F00E760C: d034200c                 sth     %o0, [%l0+0xC]
F00E7610: d017bfc2                 lduh    [%fp+var_3E], %o0
F00E7614: d034200e                 sth     %o0, [%l0+0xE]
F00E7618: d017bfc4                 lduh    [%fp+var_3C], %o0
F00E761C: d0342010                 sth     %o0, [%l0+0x10]
F00E7620: d017bfc6                 lduh    [%fp+var_3A], %o0
F00E7624: d0342012                 sth     %o0, [%l0+0x12]
F00E7628: f2046008                 ld      [%l1+8], %i1
F00E762C: d2142034                 lduh    [%l0+0x34], %o1
F00E7630: d457bfc4                 ldsh    [%fp+var_3C], %o2
F00E7634: 90100019                 mov     %i1, %o0
F00E7638: 932a6010                 sll     %o1, 16, %o1
F00E763C: 933a6010                 sra     %o1, 16, %o1
F00E7640: 7ffc7bb0                 call    _umul
F00E7644: 92228009                 sub     %o2, %o1, %o1
F00E7648: 1300000492126048         set     0x1048, %o1
F00E7650: d4046014                 ld      [%l1+0x14], %o2
F00E7654: ac040009                 add     %l0, %o1, %l6
F00E7658: d2142030                 lduh    [%l0+0x30], %o1
F00E765C: d657bfc0                 ldsh    [%fp+var_40], %o3
F00E7660: 912a2002                 sll     %o0, 2, %o0
F00E7664: d84c6020                 ldsb    [%l1+0x20], %o4
F00E7668: 94028008                 add     %o2, %o0, %o2
F00E766C: 932a6010                 sll     %o1, 16, %o1
F00E7670: 933a6010                 sra     %o1, 16, %o1
F00E7674: 9222c009                 sub     %o3, %o1, %o1
F00E7678: 932a6002                 sll     %o1, 2, %o1
F00E767C: d057bfc2                 ldsh    [%fp+var_3E], %o0
F00E7680: a4028009                 add     %o2, %o1, %l2
F00E7684: d2040000                 ld      [%l0], %o1
F00E7688: 80a32041                 cmp     %o4, 0x41 ! 'A'
F00E768C: d457bfc4                 ldsh    [%fp+var_3C], %o2
F00E7690: b022000b                 sub     %o0, %o3, %i0
F00E7694: b2264018                 sub     %i1, %i0, %i1
F00E7698: 932a600a                 sll     %o1, 10, %o1
F00E769C: 92026048                 inc     0x48, %o1 ! 'H'
F00E76A0: d0142024                 lduh    [%l0+0x24], %o0
F00E76A4: a8040009                 add     %l0, %o1, %l4
F00E76A8: 912a2010                 sll     %o0, 16, %o0
F00E76AC: 913a2010                 sra     %o0, 16, %o0
F00E76B0: 90228008                 sub     %o2, %o0, %o0
F00E76B4: d2142020                 lduh    [%l0+0x20], %o1
F00E76B8: 912a2004                 sll     %o0, 4, %o0
F00E76BC: 932a6010                 sll     %o1, 16, %o1
F00E76C0: 933a6010                 sra     %o1, 16, %o1
F00E76C4: 9622c009                 sub     %o3, %o1, %o3
F00E76C8: 9002000b                 add     %o0, %o3, %o0
F00E76CC: 912a2002                 sll     %o0, 2, %o0
F00E76D0: a8050008                 add     %l4, %o0, %l4
F00E76D4: 90102010                 mov     0x10, %o0
F00E76D8: 02800005                 be      loc_F00E76EC
F00E76DC: ba220018                 sub     %o0, %i0, %i5
F00E76E0: 80a3202d                 cmp     %o4, 0x2D ! '-'
F00E76E4: 1280003f                 bne     loc_F00E77E0
F00E76E8: d057bfc6                 ldsh    [%fp+var_3A], %o0
F00E76EC: d057bfc6                 ldsh    [%fp+var_3A], %o0
F00E76F0: aa22000a                 sub     %o0, %o2, %l5
F00E76F4: aa057fff                 inc     -1, %l5
F00E76F8: 80a57fff                 cmp     %l5, -1
F00E76FC: 0280006d                 be      loc_F00E78B0
F00E7700: 113fc03f                 sethi   -0xFF0400, %o0
F00E7704: b8122300                 or      %o0, 0x300, %i4
F00E7708: 11003fc0ae1220ff         set     0xFF00FF, %l7
F00E7710: a6063fff                 add     %i0, -1, %l3
F00E7714: 80a4ffff                 cmp     %l3, -1
F00E7718: 0280002a                 be      loc_F00E77C0
F00E771C: 912f6002                 sll     %i5, 2, %o0
F00E7720: d0048000                 ld      [%l2], %o0
F00E7724: d0258000                 st      %o0, [%l6]
F00E7728: b4100008                 mov     %o0, %i2
F00E772C: f6050000                 ld      [%l4], %i3
F00E7730: ac05a004                 inc     4, %l6
F00E7734: a336e018                 srl     %i3, 24, %l1
F00E7738: 80a46000                 cmp     %l1, 0
F00E773C: 0280001c                 be      loc_F00E77AC
F00E7740: a8052004                 inc     4, %l4
F00E7744: 80a460ff                 cmp     %l1, 0xFF
F00E7748: 32800004                 bne,a   loc_F00E7758
F00E774C: b72ee008                 sll     %i3, 8, %i3
F00E7750: 10800017                 ba      loc_F00E77AC
F00E7754: f6248000                 st      %i3, [%l2]
F00E7758: b52ea008                 sll     %i2, 8, %i2
F00E775C: a21c60ff                 btog    0xFF, %l1
F00E7760: 900e801c                 and     %i2, %i4, %o0
F00E7764: 91322008                 srl     %o0, 8, %o0
F00E7768: 7ffc7b66                 call    _umul
F00E776C: 92100011                 mov     %l1, %o1
F00E7770: a0100008                 mov     %o0, %l0
F00E7774: 900e8017                 and     %i2, %l7, %o0
F00E7778: 92100011                 mov     %l1, %o1
F00E777C: a0040017                 add     %l0, %l7, %l0
F00E7780: 7ffc7b60                 call    _umul
F00E7784: a00c001c                 and     %l0, %i4, %l0
F00E7788: 90020017                 add     %o0, %l7, %o0
F00E778C: 91322008                 srl     %o0, 8, %o0
F00E7790: 900a0017                 and     %o0, %l7, %o0
F00E7794: a0140008                 bset    %o0, %l0
F00E7798: b406c010                 add     %i3, %l0, %i2
F00E779C: 9136a008                 srl     %i2, 8, %o0
F00E77A0: 133fc000                 sethi   -0x1000000, %o1
F00E77A4: 90120009                 bset    %o1, %o0
F00E77A8: d0248000                 st      %o0, [%l2]
F00E77AC: a604ffff                 inc     -1, %l3
F00E77B0: 80a4ffff                 cmp     %l3, -1
F00E77B4: 12bfffdb                 bne     loc_F00E7720
F00E77B8: a404a004                 inc     4, %l2
F00E77BC: 912f6002                 sll     %i5, 2, %o0
F00E77C0: a8050008                 add     %l4, %o0, %l4
F00E77C4: 912e6002                 sll     %i1, 2, %o0
F00E77C8: aa057fff                 inc     -1, %l5
F00E77CC: 80a57fff                 cmp     %l5, -1
F00E77D0: 12bfffd0                 bne     loc_F00E7710
F00E77D4: a4048008                 add     %l2, %o0, %l2
F00E77D8: 10800037                 ba      loc_F00E78B4
F00E77DC: c607bfac                 ld      [%fp+var_54], %g3
F00E77E0: aa22000a                 sub     %o0, %o2, %l5
F00E77E4: aa057fff                 inc     -1, %l5
F00E77E8: 80a57fff                 cmp     %l5, -1
F00E77EC: 02800031                 be      loc_F00E78B0
F00E77F0: 113fc03f                 sethi   -0xFF0400, %o0
F00E77F4: b8122300                 or      %o0, 0x300, %i4
F00E77F8: 11003fc0ae1220ff         set     0xFF00FF, %l7
F00E7800: a6063fff                 add     %i0, -1, %l3
F00E7804: 80a4ffff                 cmp     %l3, -1
F00E7808: 02800024                 be      loc_F00E7898
F00E780C: 912f6002                 sll     %i5, 2, %o0
F00E7810: d0048000                 ld      [%l2], %o0
F00E7814: d0258000                 st      %o0, [%l6]
F00E7818: b4100008                 mov     %o0, %i2
F00E781C: f6050000                 ld      [%l4], %i3
F00E7820: ac05a004                 inc     4, %l6
F00E7824: a28ee0ff                 andcc   %i3, 0xFF, %l1
F00E7828: 02800017                 be      loc_F00E7884
F00E782C: a8052004                 inc     4, %l4
F00E7830: 80a460ff                 cmp     %l1, 0xFF
F00E7834: 12800004                 bne     loc_F00E7844
F00E7838: a21c60ff                 btog    0xFF, %l1
F00E783C: 10800012                 ba      loc_F00E7884
F00E7840: f6248000                 st      %i3, [%l2]
F00E7844: 900e801c                 and     %i2, %i4, %o0
F00E7848: 91322008                 srl     %o0, 8, %o0
F00E784C: 7ffc7b2d                 call    _umul
F00E7850: 92100011                 mov     %l1, %o1
F00E7854: a0100008                 mov     %o0, %l0
F00E7858: 900e8017                 and     %i2, %l7, %o0
F00E785C: 92100011                 mov     %l1, %o1
F00E7860: a0040017                 add     %l0, %l7, %l0
F00E7864: 7ffc7b27                 call    _umul
F00E7868: a00c001c                 and     %l0, %i4, %l0
F00E786C: 90020017                 add     %o0, %l7, %o0
F00E7870: 91322008                 srl     %o0, 8, %o0
F00E7874: 900a0017                 and     %o0, %l7, %o0
F00E7878: a0140008                 bset    %o0, %l0
F00E787C: b406c010                 add     %i3, %l0, %i2
F00E7880: f4248000                 st      %i2, [%l2]
F00E7884: a604ffff                 inc     -1, %l3
F00E7888: 80a4ffff                 cmp     %l3, -1
F00E788C: 12bfffe1                 bne     loc_F00E7810
F00E7890: a404a004                 inc     4, %l2
F00E7894: 912f6002                 sll     %i5, 2, %o0
F00E7898: a8050008                 add     %l4, %o0, %l4
F00E789C: 912e6002                 sll     %i1, 2, %o0
F00E78A0: aa057fff                 inc     -1, %l5
F00E78A4: 80a57fff                 cmp     %l5, -1
F00E78A8: 12bfffd6                 bne     loc_F00E7800
F00E78AC: a4048008                 add     %l2, %o0, %l2
F00E78B0: c607bfac                 ld      [%fp+var_54], %g3
F00E78B4: d010e020                 lduh    [%g3+0x20], %o0
F00E78B8: d030e028                 sth     %o0, [%g3+0x28]
F00E78BC: d010e022                 lduh    [%g3+0x22], %o0
F00E78C0: d030e02a                 sth     %o0, [%g3+0x2A]
F00E78C4: d010e024                 lduh    [%g3+0x24], %o0
F00E78C8: d030e02c                 sth     %o0, [%g3+0x2C]
F00E78CC: d010e026                 lduh    [%g3+0x26], %o0
F00E78D0: d030e02e                 sth     %o0, [%g3+0x2E]
F00E78D4: c207bfb4                 ld      [%fp+var_4C], %g1
F00E78D8: d0086008                 ldub    [%g1+8], %o0
F00E78DC: 80a22000                 cmp     %o0, 0
F00E78E0: 2280020d                 be,a    loc_F00E8114
F00E78E4: c207bfb4                 ld      [%fp+var_4C], %g1
F00E78E8: d0086008                 ldub    [%g1+8], %o0
F00E78EC: 90023fff                 inc     -1, %o0
F00E78F0: d0286008                 stb     %o0, [%g1+8]
F00E78F4: d0086008                 ldub    [%g1+8], %o0
F00E78F8: 80a22000                 cmp     %o0, 0
F00E78FC: 12800206                 bne     loc_F00E8114
F00E7900: c207bfb4                 ld      [%fp+var_4C], %g1
F00E7904: c607bfbc                 ld      [%fp+var_44], %g3
F00E7908: c600e1fc                 ld      [%g3+0x1FC], %g3
F00E790C: d000c000                 ld      [%g3], %o0
F00E7910: 912a2002                 sll     %o0, 2, %o0
F00E7914: 90020003                 add     %o0, %g3, %o0
F00E7918: d2122038                 lduh    [%o0+0x38], %o1
F00E791C: d237bfc8                 sth     %o1, [%fp+var_38]
F00E7920: d012203a                 lduh    [%o0+0x3A], %o0
F00E7924: d037bfca                 sth     %o0, [%fp+var_36]
F00E7928: d010e01c                 lduh    [%g3+0x1C], %o0
F00E792C: 90220009                 sub     %o0, %o1, %o0
F00E7930: d030e020                 sth     %o0, [%g3+0x20]
F00E7934: d010e020                 lduh    [%g3+0x20], %o0
F00E7938: 90022010                 inc     0x10, %o0
F00E793C: d030e022                 sth     %o0, [%g3+0x22]
F00E7940: d210e01e                 lduh    [%g3+0x1E], %o1
F00E7944: d417bfca                 lduh    [%fp+var_36], %o2
F00E7948: 213c0504                 sethi   %hi(paDisplayinfo), %l0
F00E794C: d007bfbc                 ld      [%fp+var_44], %o0! id
F00E7950: 9222400a                 sub     %o1, %o2, %o1
F00E7954: d230e024                 sth     %o1, [%g3+0x24]
F00E7958: d410e024                 lduh    [%g3+0x24], %o2
F00E795C: c627bf94                 st      %g3, [%fp+var_6C]
F00E7960: d20423ac                 ld      [%l0+%lo(paDisplayinfo)], %o1! SEL
F00E7964: 9402a010                 inc     0x10, %o2
F00E7968: d430e026                 sth     %o2, [%g3+0x26]
F00E796C: 400027c1                 call    _objc_msgSend
F00E7970: 01000000                 nop
F00E7974: d0022018                 ld      [%o0+0x18], %o0! id
F00E7978: 80a22003                 cmp     %o0, 3
F00E797C: 18800008                 bgu     loc_F00E799C
F00E7980: 80a22002                 cmp     %o0, 2
F00E7984: 1a8001da                 bcc     loc_F00E80EC
F00E7988: 80a22001                 cmp     %o0, 1
F00E798C: 02800009                 be      loc_F00E79B0
F00E7990: d20423ac                 ld      [%l0+0x3AC], %o1
F00E7994: 108001d7                 ba      loc_F00E80F0
F00E7998: c607bf94                 ld      [%fp+var_6C], %g3
F00E799C: 80a22004                 cmp     %o0, 4
F00E79A0: 028000f2                 be      loc_F00E7D68
F00E79A4: d20423ac                 ld      [%l0+0x3AC], %o1! SEL
F00E79A8: 108001d2                 ba      loc_F00E80F0
F00E79AC: c607bf94                 ld      [%fp+var_6C], %g3
F00E79B0: 400027b0                 call    _objc_msgSend
F00E79B4: d007bfbc                 ld      [%fp+var_44], %o0
F00E79B8: c207bfbc                 ld      [%fp+var_44], %g1
F00E79BC: e00061fc                 ld      [%g1+0x1FC], %l0
F00E79C0: d8142020                 lduh    [%l0+0x20], %o4
F00E79C4: d837bfc0                 sth     %o4, [%fp+var_40]
F00E79C8: da142022                 lduh    [%l0+0x22], %o5
F00E79CC: da37bfc2                 sth     %o5, [%fp+var_3E]
F00E79D0: d4142024                 lduh    [%l0+0x24], %o2
F00E79D4: a2100008                 mov     %o0, %l1
F00E79D8: d437bfc4                 sth     %o2, [%fp+var_3C]
F00E79DC: d6142026                 lduh    [%l0+0x26], %o3
F00E79E0: 952aa010                 sll     %o2, 16, %o2
F00E79E4: d637bfc6                 sth     %o3, [%fp+var_3A]
F00E79E8: d2142034                 lduh    [%l0+0x34], %o1
F00E79EC: 953aa010                 sra     %o2, 16, %o2
F00E79F0: 932a6010                 sll     %o1, 16, %o1
F00E79F4: 933a6010                 sra     %o1, 16, %o1
F00E79F8: 80a28009                 cmp     %o2, %o1
F00E79FC: 16800004                 bge     loc_F00E7A0C
F00E7A00: 01000000                 nop
F00E7A04: d0142034                 lduh    [%l0+0x34], %o0
F00E7A08: d037bfc4                 sth     %o0, [%fp+var_3C]
F00E7A0C: d0142036                 lduh    [%l0+0x36], %o0
F00E7A10: 932ae010                 sll     %o3, 16, %o1
F00E7A14: 933a6010                 sra     %o1, 16, %o1
F00E7A18: 912a2010                 sll     %o0, 16, %o0
F00E7A1C: 913a2010                 sra     %o0, 16, %o0
F00E7A20: 80a24008                 cmp     %o1, %o0
F00E7A24: 04800004                 ble     loc_F00E7A34
F00E7A28: 01000000                 nop
F00E7A2C: d0142036                 lduh    [%l0+0x36], %o0
F00E7A30: d037bfc6                 sth     %o0, [%fp+var_3A]
F00E7A34: d0142030                 lduh    [%l0+0x30], %o0
F00E7A38: 932b2010                 sll     %o4, 16, %o1
F00E7A3C: 933a6010                 sra     %o1, 16, %o1
F00E7A40: 912a2010                 sll     %o0, 16, %o0
F00E7A44: 913a2010                 sra     %o0, 16, %o0
F00E7A48: 80a24008                 cmp     %o1, %o0
F00E7A4C: 16800004                 bge     loc_F00E7A5C
F00E7A50: 01000000                 nop
F00E7A54: d0142030                 lduh    [%l0+0x30], %o0
F00E7A58: d037bfc0                 sth     %o0, [%fp+var_40]
F00E7A5C: d0142032                 lduh    [%l0+0x32], %o0
F00E7A60: 932b6010                 sll     %o5, 16, %o1
F00E7A64: 933a6010                 sra     %o1, 16, %o1
F00E7A68: 912a2010                 sll     %o0, 16, %o0
F00E7A6C: 913a2010                 sra     %o0, 16, %o0
F00E7A70: 80a24008                 cmp     %o1, %o0
F00E7A74: 04800005                 ble     loc_F00E7A88
F00E7A78: d017bfc0                 lduh    [%fp+var_40], %o0
F00E7A7C: d0142032                 lduh    [%l0+0x32], %o0
F00E7A80: d037bfc2                 sth     %o0, [%fp+var_3E]
F00E7A84: d017bfc0                 lduh    [%fp+var_40], %o0
F00E7A88: d034200c                 sth     %o0, [%l0+0xC]
F00E7A8C: d017bfc2                 lduh    [%fp+var_3E], %o0
F00E7A90: d034200e                 sth     %o0, [%l0+0xE]
F00E7A94: d017bfc4                 lduh    [%fp+var_3C], %o0
F00E7A98: d0342010                 sth     %o0, [%l0+0x10]
F00E7A9C: d017bfc6                 lduh    [%fp+var_3A], %o0
F00E7AA0: d0342012                 sth     %o0, [%l0+0x12]
F00E7AA4: c6046008                 ld      [%l1+8], %g3
F00E7AA8: d2142034                 lduh    [%l0+0x34], %o1
F00E7AAC: d457bfc4                 ldsh    [%fp+var_3C], %o2
F00E7AB0: c627bf8c                 st      %g3, [%fp+var_74]
F00E7AB4: 932a6010                 sll     %o1, 16, %o1
F00E7AB8: 933a6010                 sra     %o1, 16, %o1
F00E7ABC: d007bf8c                 ld      [%fp+var_74], %o0
F00E7AC0: 7ffc7a90                 call    _umul
F00E7AC4: 92228009                 sub     %o2, %o1, %o1
F00E7AC8: d4046014                 ld      [%l1+0x14], %o2
F00E7ACC: d2142030                 lduh    [%l0+0x30], %o1
F00E7AD0: d657bfc0                 ldsh    [%fp+var_40], %o3
F00E7AD4: ae042848                 add     %l0, 0x848, %l7
F00E7AD8: c207bf8c                 ld      [%fp+var_74], %g1
F00E7ADC: 94028008                 add     %o2, %o0, %o2
F00E7AE0: 932a6010                 sll     %o1, 16, %o1
F00E7AE4: 933a6010                 sra     %o1, 16, %o1
F00E7AE8: 9222c009                 sub     %o3, %o1, %o1
F00E7AEC: d057bfc2                 ldsh    [%fp+var_3E], %o0
F00E7AF0: b4028009                 add     %o2, %o1, %i2
F00E7AF4: d204601c                 ld      [%l1+0x1C], %o1
F00E7AF8: 9022000b                 sub     %o0, %o3, %o0
F00E7AFC: d027bf84                 st      %o0, [%fp+var_7C]
F00E7B00: 82204008                 sub     %g1, %o0, %g1
F00E7B04: c227bf8c                 st      %g1, [%fp+var_74]
F00E7B08: d0040000                 ld      [%l0], %o0
F00E7B0C: 80a26001                 cmp     %o1, 1
F00E7B10: c607bf84                 ld      [%fp+var_7C], %g3
F00E7B14: 912a2008                 sll     %o0, 8, %o0
F00E7B18: 90022048                 inc     0x48, %o0 ! 'H'
F00E7B1C: d4040000                 ld      [%l0], %o2
F00E7B20: a8040008                 add     %l0, %o0, %l4
F00E7B24: 952aa008                 sll     %o2, 8, %o2
F00E7B28: 9402a448                 inc     0x448, %o2
F00E7B2C: d2142024                 lduh    [%l0+0x24], %o1
F00E7B30: b604000a                 add     %l0, %o2, %i3
F00E7B34: d457bfc4                 ldsh    [%fp+var_3C], %o2
F00E7B38: 932a6010                 sll     %o1, 16, %o1
F00E7B3C: 933a6010                 sra     %o1, 16, %o1
F00E7B40: 92228009                 sub     %o2, %o1, %o1
F00E7B44: d0142020                 lduh    [%l0+0x20], %o0
F00E7B48: 932a6004                 sll     %o1, 4, %o1
F00E7B4C: 912a2010                 sll     %o0, 16, %o0
F00E7B50: 913a2010                 sra     %o0, 16, %o0
F00E7B54: 9622c008                 sub     %o3, %o0, %o3
F00E7B58: aa02400b                 add     %o1, %o3, %l5
F00E7B5C: a8050015                 add     %l4, %l5, %l4
F00E7B60: d057bfc6                 ldsh    [%fp+var_3A], %o0
F00E7B64: b606c015                 add     %i3, %l5, %i3
F00E7B68: 9222000a                 sub     %o0, %o2, %o1
F00E7B6C: 90102010                 mov     0x10, %o0
F00E7B70: 12800023                 bne     loc_F00E7BFC
F00E7B74: b2220003                 sub     %o0, %g3, %i1
F00E7B78: aa827fff                 addcc   %o1, -1, %l5
F00E7B7C: 0c80015c                 bneg    loc_F00E80EC
F00E7B80: a21020ff                 mov     0xFF, %l1
F00E7B84: c207bf84                 ld      [%fp+var_7C], %g1
F00E7B88: a4807fff                 addcc   %g1, -1, %l2
F00E7B8C: 2c800015                 bneg,a  loc_F00E7BE0
F00E7B90: a8050019                 add     %l4, %i1, %l4
F00E7B94: d00e8000                 ldub    [%i2], %o0
F00E7B98: d02dc000                 stb     %o0, [%l7]
F00E7B9C: ae05e001                 inc     %l7
F00E7BA0: e00d0000                 ldub    [%l4], %l0
F00E7BA4: d20ec000                 ldub    [%i3], %o1
F00E7BA8: a8052001                 inc     %l4
F00E7BAC: 7ffc7a55                 call    _umul
F00E7BB0: 92244009                 sub     %l1, %o1, %o1
F00E7BB4: b606e001                 inc     %i3
F00E7BB8: 933a2008                 sra     %o0, 8, %o1
F00E7BBC: 90020009                 add     %o0, %o1, %o0
F00E7BC0: 90022001                 inc     %o0
F00E7BC4: 913a2008                 sra     %o0, 8, %o0
F00E7BC8: a0040008                 add     %l0, %o0, %l0
F00E7BCC: e02e8000                 stb     %l0, [%i2]
F00E7BD0: a484bfff                 inccc   -1, %l2
F00E7BD4: 1cbffff0                 bpos    loc_F00E7B94
F00E7BD8: b406a001                 inc     %i2
F00E7BDC: a8050019                 add     %l4, %i1, %l4
F00E7BE0: b606c019                 add     %i3, %i1, %i3
F00E7BE4: c607bf8c                 ld      [%fp+var_74], %g3
F00E7BE8: aa857fff                 inccc   -1, %l5
F00E7BEC: 1cbfffe6                 bpos    loc_F00E7B84
F00E7BF0: b4068003                 add     %i2, %g3, %i2
F00E7BF4: 1080013f                 ba      loc_F00E80F0
F00E7BF8: c607bf94                 ld      [%fp+var_6C], %g3
F00E7BFC: c207bfbc                 ld      [%fp+var_44], %g1
F00E7C00: fa006208                 ld      [%g1+0x208], %i5
F00E7C04: aa827fff                 addcc   %o1, -1, %l5
F00E7C08: 0c800139                 bneg    loc_F00E80EC
F00E7C0C: ec00620c                 ld      [%g1+0x20C], %l6
F00E7C10: 113fc03fb0122300         set     -0xFF0100, %i0
F00E7C18: c607bf84                 ld      [%fp+var_7C], %g3
F00E7C1C: a480ffff                 addcc   %g3, -1, %l2
F00E7C20: 0c80004a                 bneg    loc_F00E7D48
F00E7C24: 11003fc0                 sethi   0xFF0000, %o0
F00E7C28: b81220ff                 or      %o0, 0xFF, %i4
F00E7C2C: d00e8000                 ldub    [%i2], %o0
F00E7C30: d02dc000                 stb     %o0, [%l7]
F00E7C34: e00ec000                 ldub    [%i3], %l0
F00E7C38: 80a42000                 cmp     %l0, 0
F00E7C3C: 2280003e                 be,a    loc_F00E7D34
F00E7C40: ae05e001                 inc     %l7
F00E7C44: e60d0000                 ldub    [%l4], %l3
F00E7C48: 90380010                 xnor    %g0, %l0, %o0
F00E7C4C: 808a20ff                 btst    0xFF, %o0
F00E7C50: 02800037                 be      loc_F00E7D2C
F00E7C54: a0100008                 mov     %o0, %l0
F00E7C58: d00e8000                 ldub    [%i2], %o0
F00E7C5C: a00c20ff                 and     %l0, 0xFF, %l0
F00E7C60: 912a2002                 sll     %o0, 2, %o0
F00E7C64: e2074008                 ld      [%i5+%o0], %l1
F00E7C68: 92100010                 mov     %l0, %o1
F00E7C6C: 900c4018                 and     %l1, %i0, %o0
F00E7C70: 7ffc7a24                 call    _umul
F00E7C74: 91322008                 srl     %o0, 8, %o0
F00E7C78: 94100008                 mov     %o0, %o2
F00E7C7C: 900c401c                 and     %l1, %i4, %o0
F00E7C80: 92100010                 mov     %l0, %o1
F00E7C84: 0300004082106001         set     0x10001, %g1
F00E7C8C: a0028001                 add     %o2, %g1, %l0
F00E7C90: 940a8018                 and     %o2, %i0, %o2
F00E7C94: 9532a008                 srl     %o2, 8, %o2
F00E7C98: 7ffc7a1a                 call    _umul
F00E7C9C: a004000a                 add     %l0, %o2, %l0
F00E7CA0: 070000408610e001         set     0x10001, %g3
F00E7CA8: 92020003                 add     %o0, %g3, %o1
F00E7CAC: 900a0018                 and     %o0, %i0, %o0
F00E7CB0: 91322008                 srl     %o0, 8, %o0
F00E7CB4: 92024008                 add     %o1, %o0, %o1
F00E7CB8: a00c0018                 and     %l0, %i0, %l0
F00E7CBC: 93326008                 srl     %o1, 8, %o1
F00E7CC0: 920a401c                 and     %o1, %i4, %o1
F00E7CC4: 912ce002                 sll     %l3, 2, %o0
F00E7CC8: a0140009                 bset    %o1, %l0
F00E7CCC: 03003fff                 sethi   0xFFFC00, %g1
F00E7CD0: d0074008                 ld      [%i5+%o0], %o0
F00E7CD4: 82106300                 bset    0x300, %g1
F00E7CD8: 900a3f00                 and     %o0, -0x100, %o0
F00E7CDC: a2020010                 add     %o0, %l0, %l1
F00E7CE0: 97346008                 srl     %l1, 8, %o3
F00E7CE4: 901c400b                 xor     %l1, %o3, %o0
F00E7CE8: 808a0001                 btst    %g1, %o0
F00E7CEC: 0280000d                 be      loc_F00E7D20
F00E7CF0: 93346018                 srl     %l1, 24, %o1
F00E7CF4: 91346010                 srl     %l1, 16, %o0
F00E7CF8: 900a20ff                 and     %o0, 0xFF, %o0
F00E7CFC: d40d8009                 ldub    [%l6+%o1], %o2
F00E7D00: 90020016                 add     %o0, %l6, %o0
F00E7D04: 920ae0ff                 and     %o3, 0xFF, %o1
F00E7D08: d60a2100                 ldub    [%o0+0x100], %o3
F00E7D0C: 92024016                 add     %o1, %l6, %o1! SEL
F00E7D10: d00a6200                 ldub    [%o1+0x200], %o0
F00E7D14: 9402800b                 add     %o2, %o3, %o2
F00E7D18: 10800005                 ba      loc_F00E7D2C
F00E7D1C: a602000a                 add     %o0, %o2, %l3
F00E7D20: 91346018                 srl     %l1, 24, %o0
F00E7D24: 90020016                 add     %o0, %l6, %o0! id
F00E7D28: e60a2300                 ldub    [%o0+0x300], %l3
F00E7D2C: e62e8000                 stb     %l3, [%i2]
F00E7D30: ae05e001                 inc     %l7
F00E7D34: b606e001                 inc     %i3
F00E7D38: a8052001                 inc     %l4
F00E7D3C: a484bfff                 inccc   -1, %l2
F00E7D40: 1cbfffbb                 bpos    loc_F00E7C2C
F00E7D44: b406a001                 inc     %i2
F00E7D48: a8050019                 add     %l4, %i1, %l4
F00E7D4C: b606c019                 add     %i3, %i1, %i3
F00E7D50: c607bf8c                 ld      [%fp+var_74], %g3
F00E7D54: aa857fff                 inccc   -1, %l5
F00E7D58: 1cbfffb0                 bpos    loc_F00E7C18
F00E7D5C: b4068003                 add     %i2, %g3, %i2
F00E7D60: 108000e4                 ba      loc_F00E80F0
F00E7D64: c607bf94                 ld      [%fp+var_6C], %g3
F00E7D68: 400026c2                 call    _objc_msgSend
F00E7D6C: d007bfbc                 ld      [%fp+var_44], %o0
F00E7D70: c207bfbc                 ld      [%fp+var_44], %g1
F00E7D74: e00061fc                 ld      [%g1+0x1FC], %l0
F00E7D78: d8142020                 lduh    [%l0+0x20], %o4
F00E7D7C: d837bfc0                 sth     %o4, [%fp+var_40]
F00E7D80: da142022                 lduh    [%l0+0x22], %o5
F00E7D84: da37bfc2                 sth     %o5, [%fp+var_3E]
F00E7D88: d4142024                 lduh    [%l0+0x24], %o2
F00E7D8C: a2100008                 mov     %o0, %l1
F00E7D90: d437bfc4                 sth     %o2, [%fp+var_3C]
F00E7D94: d6142026                 lduh    [%l0+0x26], %o3
F00E7D98: 952aa010                 sll     %o2, 16, %o2
F00E7D9C: d637bfc6                 sth     %o3, [%fp+var_3A]
F00E7DA0: d2142034                 lduh    [%l0+0x34], %o1
F00E7DA4: 953aa010                 sra     %o2, 16, %o2
F00E7DA8: 932a6010                 sll     %o1, 16, %o1
F00E7DAC: 933a6010                 sra     %o1, 16, %o1
F00E7DB0: 80a28009                 cmp     %o2, %o1
F00E7DB4: 16800004                 bge     loc_F00E7DC4
F00E7DB8: 01000000                 nop
F00E7DBC: d0142034                 lduh    [%l0+0x34], %o0
F00E7DC0: d037bfc4                 sth     %o0, [%fp+var_3C]
F00E7DC4: d0142036                 lduh    [%l0+0x36], %o0
F00E7DC8: 932ae010                 sll     %o3, 16, %o1
F00E7DCC: 933a6010                 sra     %o1, 16, %o1
F00E7DD0: 912a2010                 sll     %o0, 16, %o0
F00E7DD4: 913a2010                 sra     %o0, 16, %o0
F00E7DD8: 80a24008                 cmp     %o1, %o0
F00E7DDC: 04800004                 ble     loc_F00E7DEC
F00E7DE0: 01000000                 nop
F00E7DE4: d0142036                 lduh    [%l0+0x36], %o0
F00E7DE8: d037bfc6                 sth     %o0, [%fp+var_3A]
F00E7DEC: d0142030                 lduh    [%l0+0x30], %o0
F00E7DF0: 932b2010                 sll     %o4, 16, %o1
F00E7DF4: 933a6010                 sra     %o1, 16, %o1
F00E7DF8: 912a2010                 sll     %o0, 16, %o0
F00E7DFC: 913a2010                 sra     %o0, 16, %o0
F00E7E00: 80a24008                 cmp     %o1, %o0
F00E7E04: 16800004                 bge     loc_F00E7E14
F00E7E08: 01000000                 nop
F00E7E0C: d0142030                 lduh    [%l0+0x30], %o0
F00E7E10: d037bfc0                 sth     %o0, [%fp+var_40]
F00E7E14: d0142032                 lduh    [%l0+0x32], %o0
F00E7E18: 932b6010                 sll     %o5, 16, %o1
F00E7E1C: 933a6010                 sra     %o1, 16, %o1
F00E7E20: 912a2010                 sll     %o0, 16, %o0
F00E7E24: 913a2010                 sra     %o0, 16, %o0
F00E7E28: 80a24008                 cmp     %o1, %o0
F00E7E2C: 04800005                 ble     loc_F00E7E40
F00E7E30: d017bfc0                 lduh    [%fp+var_40], %o0
F00E7E34: d0142032                 lduh    [%l0+0x32], %o0
F00E7E38: d037bfc2                 sth     %o0, [%fp+var_3E]
F00E7E3C: d017bfc0                 lduh    [%fp+var_40], %o0
F00E7E40: d034200c                 sth     %o0, [%l0+0xC]
F00E7E44: d017bfc2                 lduh    [%fp+var_3E], %o0
F00E7E48: d034200e                 sth     %o0, [%l0+0xE]
F00E7E4C: d017bfc4                 lduh    [%fp+var_3C], %o0
F00E7E50: d0342010                 sth     %o0, [%l0+0x10]
F00E7E54: d017bfc6                 lduh    [%fp+var_3A], %o0
F00E7E58: d0342012                 sth     %o0, [%l0+0x12]
F00E7E5C: f2046008                 ld      [%l1+8], %i1
F00E7E60: d2142034                 lduh    [%l0+0x34], %o1
F00E7E64: d457bfc4                 ldsh    [%fp+var_3C], %o2
F00E7E68: 90100019                 mov     %i1, %o0
F00E7E6C: 932a6010                 sll     %o1, 16, %o1
F00E7E70: 933a6010                 sra     %o1, 16, %o1
F00E7E74: 7ffc79a3                 call    _umul
F00E7E78: 92228009                 sub     %o2, %o1, %o1
F00E7E7C: 1300000492126048         set     0x1048, %o1
F00E7E84: d4046014                 ld      [%l1+0x14], %o2
F00E7E88: ac040009                 add     %l0, %o1, %l6
F00E7E8C: d2142030                 lduh    [%l0+0x30], %o1
F00E7E90: d657bfc0                 ldsh    [%fp+var_40], %o3
F00E7E94: 912a2002                 sll     %o0, 2, %o0
F00E7E98: d84c6020                 ldsb    [%l1+0x20], %o4
F00E7E9C: 94028008                 add     %o2, %o0, %o2
F00E7EA0: 932a6010                 sll     %o1, 16, %o1
F00E7EA4: 933a6010                 sra     %o1, 16, %o1
F00E7EA8: 9222c009                 sub     %o3, %o1, %o1
F00E7EAC: 932a6002                 sll     %o1, 2, %o1
F00E7EB0: d057bfc2                 ldsh    [%fp+var_3E], %o0
F00E7EB4: a4028009                 add     %o2, %o1, %l2
F00E7EB8: d2040000                 ld      [%l0], %o1
F00E7EBC: 80a32041                 cmp     %o4, 0x41 ! 'A'
F00E7EC0: d457bfc4                 ldsh    [%fp+var_3C], %o2
F00E7EC4: b022000b                 sub     %o0, %o3, %i0
F00E7EC8: b2264018                 sub     %i1, %i0, %i1
F00E7ECC: 932a600a                 sll     %o1, 10, %o1
F00E7ED0: 92026048                 inc     0x48, %o1 ! 'H'
F00E7ED4: d0142024                 lduh    [%l0+0x24], %o0
F00E7ED8: a8040009                 add     %l0, %o1, %l4
F00E7EDC: 912a2010                 sll     %o0, 16, %o0
F00E7EE0: 913a2010                 sra     %o0, 16, %o0
F00E7EE4: 90228008                 sub     %o2, %o0, %o0
F00E7EE8: d2142020                 lduh    [%l0+0x20], %o1
F00E7EEC: 912a2004                 sll     %o0, 4, %o0
F00E7EF0: 932a6010                 sll     %o1, 16, %o1
F00E7EF4: 933a6010                 sra     %o1, 16, %o1
F00E7EF8: 9622c009                 sub     %o3, %o1, %o3
F00E7EFC: 9002000b                 add     %o0, %o3, %o0
F00E7F00: 912a2002                 sll     %o0, 2, %o0
F00E7F04: a8050008                 add     %l4, %o0, %l4
F00E7F08: 90102010                 mov     0x10, %o0
F00E7F0C: 02800005                 be      loc_F00E7F20
F00E7F10: ba220018                 sub     %o0, %i0, %i5
F00E7F14: 80a3202d                 cmp     %o4, 0x2D ! '-'
F00E7F18: 12800040                 bne     loc_F00E8018
F00E7F1C: d057bfc6                 ldsh    [%fp+var_3A], %o0
F00E7F20: d057bfc6                 ldsh    [%fp+var_3A], %o0
F00E7F24: aa22000a                 sub     %o0, %o2, %l5
F00E7F28: aa057fff                 inc     -1, %l5
F00E7F2C: 80a57fff                 cmp     %l5, -1
F00E7F30: 02800070                 be      loc_F00E80F0
F00E7F34: c607bf94                 ld      [%fp+var_6C], %g3
F00E7F38: 113fc03fb8122300         set     -0xFF0100, %i4
F00E7F40: 11003fc0ae1220ff         set     0xFF00FF, %l7
F00E7F48: a6063fff                 add     %i0, -1, %l3
F00E7F4C: 80a4ffff                 cmp     %l3, -1
F00E7F50: 0280002a                 be      loc_F00E7FF8
F00E7F54: 912f6002                 sll     %i5, 2, %o0
F00E7F58: d0048000                 ld      [%l2], %o0
F00E7F5C: d0258000                 st      %o0, [%l6]
F00E7F60: b4100008                 mov     %o0, %i2
F00E7F64: f6050000                 ld      [%l4], %i3
F00E7F68: ac05a004                 inc     4, %l6
F00E7F6C: a336e018                 srl     %i3, 24, %l1
F00E7F70: 80a46000                 cmp     %l1, 0
F00E7F74: 0280001c                 be      loc_F00E7FE4
F00E7F78: a8052004                 inc     4, %l4
F00E7F7C: 80a460ff                 cmp     %l1, 0xFF
F00E7F80: 32800004                 bne,a   loc_F00E7F90
F00E7F84: b72ee008                 sll     %i3, 8, %i3
F00E7F88: 10800017                 ba      loc_F00E7FE4
F00E7F8C: f6248000                 st      %i3, [%l2]
F00E7F90: b52ea008                 sll     %i2, 8, %i2
F00E7F94: a21c60ff                 btog    0xFF, %l1
F00E7F98: 900e801c                 and     %i2, %i4, %o0
F00E7F9C: 91322008                 srl     %o0, 8, %o0
F00E7FA0: 7ffc7958                 call    _umul
F00E7FA4: 92100011                 mov     %l1, %o1
F00E7FA8: a0100008                 mov     %o0, %l0
F00E7FAC: 900e8017                 and     %i2, %l7, %o0
F00E7FB0: 92100011                 mov     %l1, %o1
F00E7FB4: a0040017                 add     %l0, %l7, %l0
F00E7FB8: 7ffc7952                 call    _umul
F00E7FBC: a00c001c                 and     %l0, %i4, %l0
F00E7FC0: 90020017                 add     %o0, %l7, %o0
F00E7FC4: 91322008                 srl     %o0, 8, %o0
F00E7FC8: 900a0017                 and     %o0, %l7, %o0
F00E7FCC: a0140008                 bset    %o0, %l0
F00E7FD0: b406c010                 add     %i3, %l0, %i2
F00E7FD4: 9136a008                 srl     %i2, 8, %o0
F00E7FD8: 133fc000                 sethi   -0x1000000, %o1
F00E7FDC: 90120009                 bset    %o1, %o0
F00E7FE0: d0248000                 st      %o0, [%l2]
F00E7FE4: a604ffff                 inc     -1, %l3
F00E7FE8: 80a4ffff                 cmp     %l3, -1
F00E7FEC: 12bfffdb                 bne     loc_F00E7F58
F00E7FF0: a404a004                 inc     4, %l2
F00E7FF4: 912f6002                 sll     %i5, 2, %o0
F00E7FF8: a8050008                 add     %l4, %o0, %l4
F00E7FFC: 912e6002                 sll     %i1, 2, %o0
F00E8000: aa057fff                 inc     -1, %l5
F00E8004: 80a57fff                 cmp     %l5, -1
F00E8008: 12bfffd0                 bne     loc_F00E7F48
F00E800C: a4048008                 add     %l2, %o0, %l2
F00E8010: 10800038                 ba      loc_F00E80F0
F00E8014: c607bf94                 ld      [%fp+var_6C], %g3
F00E8018: aa22000a                 sub     %o0, %o2, %l5
F00E801C: aa057fff                 inc     -1, %l5
F00E8020: 80a57fff                 cmp     %l5, -1
F00E8024: 02800033                 be      loc_F00E80F0
F00E8028: c607bf94                 ld      [%fp+var_6C], %g3
F00E802C: 113fc03fb8122300         set     -0xFF0100, %i4
F00E8034: 11003fc0ae1220ff         set     0xFF00FF, %l7
F00E803C: a6063fff                 add     %i0, -1, %l3
F00E8040: 80a4ffff                 cmp     %l3, -1
F00E8044: 02800024                 be      loc_F00E80D4
F00E8048: 912f6002                 sll     %i5, 2, %o0
F00E804C: d0048000                 ld      [%l2], %o0
F00E8050: d0258000                 st      %o0, [%l6]
F00E8054: b4100008                 mov     %o0, %i2
F00E8058: f6050000                 ld      [%l4], %i3
F00E805C: ac05a004                 inc     4, %l6
F00E8060: a28ee0ff                 andcc   %i3, 0xFF, %l1
F00E8064: 02800017                 be      loc_F00E80C0
F00E8068: a8052004                 inc     4, %l4
F00E806C: 80a460ff                 cmp     %l1, 0xFF
F00E8070: 12800004                 bne     loc_F00E8080
F00E8074: a21c60ff                 btog    0xFF, %l1
F00E8078: 10800012                 ba      loc_F00E80C0
F00E807C: f6248000                 st      %i3, [%l2]
F00E8080: 900e801c                 and     %i2, %i4, %o0
F00E8084: 91322008                 srl     %o0, 8, %o0
F00E8088: 7ffc791e                 call    _umul
F00E808C: 92100011                 mov     %l1, %o1
F00E8090: a0100008                 mov     %o0, %l0
F00E8094: 900e8017                 and     %i2, %l7, %o0
F00E8098: 92100011                 mov     %l1, %o1
F00E809C: a0040017                 add     %l0, %l7, %l0
F00E80A0: 7ffc7918                 call    _umul
F00E80A4: a00c001c                 and     %l0, %i4, %l0
F00E80A8: 90020017                 add     %o0, %l7, %o0
F00E80AC: 91322008                 srl     %o0, 8, %o0
F00E80B0: 900a0017                 and     %o0, %l7, %o0
F00E80B4: a0140008                 bset    %o0, %l0
F00E80B8: b406c010                 add     %i3, %l0, %i2
F00E80BC: f4248000                 st      %i2, [%l2]
F00E80C0: a604ffff                 inc     -1, %l3
F00E80C4: 80a4ffff                 cmp     %l3, -1
F00E80C8: 12bfffe1                 bne     loc_F00E804C
F00E80CC: a404a004                 inc     4, %l2
F00E80D0: 912f6002                 sll     %i5, 2, %o0
F00E80D4: a8050008                 add     %l4, %o0, %l4
F00E80D8: 912e6002                 sll     %i1, 2, %o0
F00E80DC: aa057fff                 inc     -1, %l5
F00E80E0: 80a57fff                 cmp     %l5, -1
F00E80E4: 12bfffd6                 bne     loc_F00E803C
F00E80E8: a4048008                 add     %l2, %o0, %l2
F00E80EC: c607bf94                 ld      [%fp+var_6C], %g3
F00E80F0: d010e020                 lduh    [%g3+0x20], %o0
F00E80F4: d030e028                 sth     %o0, [%g3+0x28]
F00E80F8: d010e022                 lduh    [%g3+0x22], %o0
F00E80FC: d030e02a                 sth     %o0, [%g3+0x2A]
F00E8100: d010e024                 lduh    [%g3+0x24], %o0
F00E8104: d030e02c                 sth     %o0, [%g3+0x2C]
F00E8108: d010e026                 lduh    [%g3+0x26], %o0
F00E810C: d030e02e                 sth     %o0, [%g3+0x2E]
F00E8110: c207bfb4                 ld      [%fp+var_4C], %g1
F00E8114: 7fff6b4d                 call    _ev_unlock
F00E8118: 90006004                 add     %g1, 4, %o0
F00E811C: f007bfbc                 ld      [%fp+var_44], %i0
F00E8120: 81c7e008                 ret
F00E8124: 81e80000                 restore
