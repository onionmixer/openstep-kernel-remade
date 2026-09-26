F00D2CA0: 9de3bf88                 save    %sp, -0x78, %sp
F00D2CA4: 90102064                 mov     0x64, %o0 ! 'd'
F00D2CA8: d03621a8                 sth     %o0, [%i0+0x1A8]
F00D2CAC: d03621aa                 sth     %o0, [%i0+0x1AA]
F00D2CB0: d206215c                 ld      [%i0+0x15C], %o1
F00D2CB4: 90102008                 mov     8, %o0
F00D2CB8: d0224000                 st      %o0, [%o1]
F00D2CBC: d0024000                 ld      [%o1], %o0
F00D2CC0: 90022e10                 inc     0xE10, %o0
F00D2CC4: d0226004                 st      %o0, [%o1+4]
F00D2CC8: d006215c                 ld      [%i0+0x15C], %o0
F00D2CCC: 9610204f                 mov     0x4F, %o3 ! 'O'
F00D2CD0: d4024000                 ld      [%o1], %o2
F00D2CD4: 84102000                 mov     0, %g2
F00D2CD8: 86102000                 mov     0, %g3
F00D2CDC: a002000a                 add     %o0, %o2, %l0
F00D2CE0: d2026004                 ld      [%o1+4], %o1
F00D2CE4: 94042d94                 add     %l0, 0xD94, %o2
F00D2CE8: 90020009                 add     %o0, %o1, %o0
F00D2CEC: d0262164                 st      %o0, [%i0+0x164]
F00D2CF0: 90102001                 mov     1, %o0
F00D2CF4: d02c2049                 stb     %o0, [%l0+0x49]
F00D2CF8: d02c204a                 stb     %o0, [%l0+0x4A]
F00D2CFC: 90102047                 mov     0x47, %o0 ! 'G'
F00D2D00: d034204c                 sth     %o0, [%l0+0x4C]
F00D2D04: 90102000                 mov     0, %o0
F00D2D08: 13011e1a921260c0         set     0x47868C0, %o1
F00D2D10: d03e21e8                 std     %o0, [%i0+0x1E8]
F00D2D14: 90102000                 mov     0, %o0
F00D2D18: 1304786892126300         set     0x11E1A300, %o1
F00D2D20: d03e21d8                 std     %o0, [%i0+0x1D8]
F00D2D24: c43e21e0                 std     %g2, [%i0+0x1E0]
F00D2D28: c43e21f0                 std     %g2, [%i0+0x1F0]
F00D2D2C: 90102050                 mov     0x50, %o0 ! 'P'
F00D2D30: d026216c                 st      %o0, [%i0+0x16C]
F00D2D34: c022a058                 clr     [%o2+0x58]
F00D2D38: c022a064                 clr     [%o2+0x64]
F00D2D3C: c022a068                 clr     [%o2+0x68]
F00D2D40: c022a054                 clr     [%o2+0x54]
F00D2D44: 9002e001                 add     %o3, 1, %o0
F00D2D48: d022a050                 st      %o0, [%o2+0x50]
F00D2D4C: 9602ffff                 inc     -1, %o3
F00D2D50: 80a2ffff                 cmp     %o3, -1
F00D2D54: 12bffff8                 bne     loc_F00D2D34
F00D2D58: 9402bfd4                 inc     -0x2C, %o2
F00D2D5C: c0342004                 clrh    [%l0+4]
F00D2D60: d206216c                 ld      [%i0+0x16C], %o1
F00D2D64: 92027fff                 inc     -1, %o1
F00D2D68: 912a6001                 sll     %o1, 1, %o0
F00D2D6C: 90020009                 add     %o0, %o1, %o0
F00D2D70: 912a2002                 sll     %o0, 2, %o0
F00D2D74: 90220009                 sub     %o0, %o1, %o0
F00D2D78: 912a2002                 sll     %o0, 2, %o0
F00D2D7C: 90040008                 add     %l0, %o0, %o0
F00D2D80: c0222050                 clr     [%o0+0x50]
F00D2D84: d2142004                 lduh    [%l0+4], %o1
F00D2D88: 932a6010                 sll     %o1, 16, %o1
F00D2D8C: 933a6010                 sra     %o1, 16, %o1
F00D2D90: 912a6001                 sll     %o1, 1, %o0
F00D2D94: 90020009                 add     %o0, %o1, %o0
F00D2D98: 912a2002                 sll     %o0, 2, %o0
F00D2D9C: 90220009                 sub     %o0, %o1, %o0
F00D2DA0: 912a2002                 sll     %o0, 2, %o0
F00D2DA4: 90040008                 add     %l0, %o0, %o0
F00D2DA8: d0022050                 ld      [%o0+0x50], %o0
F00D2DAC: d0340000                 sth     %o0, [%l0]
F00D2DB0: d2142004                 lduh    [%l0+4], %o1
F00D2DB4: 932a6010                 sll     %o1, 16, %o1
F00D2DB8: 933a6010                 sra     %o1, 16, %o1
F00D2DBC: 912a6001                 sll     %o1, 1, %o0
F00D2DC0: 90020009                 add     %o0, %o1, %o0
F00D2DC4: 912a2002                 sll     %o0, 2, %o0
F00D2DC8: 90220009                 sub     %o0, %o1, %o0
F00D2DCC: 912a2002                 sll     %o0, 2, %o0
F00D2DD0: 90040008                 add     %l0, %o0, %o0
F00D2DD4: d0022050                 ld      [%o0+0x50], %o0
F00D2DD8: d0342002                 sth     %o0, [%l0+2]
F00D2DDC: c0242008                 clr     [%l0+8]
F00D2DE0: 9010200d                 mov     0xD, %o0
F00D2DE4: d0342006                 sth     %o0, [%l0+6]
F00D2DE8: c024200c                 clr     [%l0+0xC]
F00D2DEC: 7fffccbc                 call    _IOGetTimestamp
F00D2DF0: 9007bfe8                 add     %fp, var_18, %o0
F00D2DF4: d41fbfe8                 ldd     [%fp+var_18], %o2
F00D2DF8: 9b2aa008                 sll     %o2, 8, %o5
F00D2DFC: 9932e018                 srl     %o3, 24, %o4
F00D2E00: 9213400c                 or      %o5, %o4, %o1
F00D2E04: 9132a018                 srl     %o2, 24, %o0
F00D2E08: 90924000                 orcc    %o1, %g0, %o0
F00D2E0C: 22800002                 be,a    loc_F00D2E14
F00D2E10: 90102001                 mov     1, %o0
F00D2E14: d0242010                 st      %o0, [%l0+0x10]
F00D2E18: d01621a8                 lduh    [%i0+0x1A8], %o0
F00D2E1C: d0342018                 sth     %o0, [%l0+0x18]
F00D2E20: d01621aa                 lduh    [%i0+0x1AA], %o0
F00D2E24: d034201a                 sth     %o0, [%l0+0x1A]
F00D2E28: d00c2033                 ldub    [%l0+0x33], %o0
F00D2E2C: 900a20fd                 and     %o0, 0xFD, %o0
F00D2E30: d02c2033                 stb     %o0, [%l0+0x33]
F00D2E34: d00c2033                 ldub    [%l0+0x33], %o0
F00D2E38: 900a20fb                 and     %o0, 0xFB, %o0
F00D2E3C: d02c2033                 stb     %o0, [%l0+0x33]
F00D2E40: d00c2033                 ldub    [%l0+0x33], %o0
F00D2E44: 900a20ef                 and     %o0, 0xEF, %o0
F00D2E48: d02c2033                 stb     %o0, [%l0+0x33]
F00D2E4C: d00c2033                 ldub    [%l0+0x33], %o0
F00D2E50: 900a20f7                 and     %o0, 0xF7, %o0
F00D2E54: d02c2033                 stb     %o0, [%l0+0x33]
F00D2E58: d00c2033                 ldub    [%l0+0x33], %o0
F00D2E5C: 900a20fe                 and     %o0, 0xFE, %o0
F00D2E60: d02c2033                 stb     %o0, [%l0+0x33]
F00D2E64: c0242034                 clr     [%l0+0x34]
F00D2E68: c0242014                 clr     [%l0+0x14]
F00D2E6C: c0242040                 clr     [%l0+0x40]
F00D2E70: e0262168                 st      %l0, [%i0+0x168]
F00D2E74: 90102001                 mov     1, %o0
F00D2E78: d02e21d2                 stb     %o0, [%i0+0x1D2]
F00D2E7C: 81c7e008                 ret
F00D2E80: 81e80000                 restore
