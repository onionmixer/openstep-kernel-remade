F00B6BB4: 9de3bf20                 save    %sp, -0xE0, %sp
F00B6BB8: a0100018                 mov     %i0, %l0
F00B6BBC: d00c2041                 ldub    [%l0+0x41], %o0
F00B6BC0: e604209c                 ld      [%l0+0x9C], %l3
F00B6BC4: d20c2032                 ldub    [%l0+0x32], %o1
F00B6BC8: d02c2042                 stb     %o0, [%l0+0x42]
F00B6BCC: 9010201b                 mov     0x1B, %o0
F00B6BD0: d02c2041                 stb     %o0, [%l0+0x41]
F00B6BD4: d00ce01c                 ldub    [%l3+0x1C], %o0
F00B6BD8: 920a6007                 and     %o1, 7, %o1
F00B6BDC: 900a201f                 and     %o0, 0x1F, %o0
F00B6BE0: 80a22002                 cmp     %o0, 2
F00B6BE4: 90102001                 mov     1, %o0
F00B6BE8: 1280011f                 bne     loc_F00B7064
F00B6BEC: 912a0009                 sll     %o0, %o1, %o0
F00B6BF0: d40ce008                 ldub    [%l3+8], %o2
F00B6BF4: 808a8008                 btst    %o0, %o2
F00B6BF8: 0280011b                 be      loc_F00B7064
F00B6BFC: 941a8008                 btog    %o0, %o2
F00B6C00: 900aa0ff                 and     %o2, 0xFF, %o0
F00B6C04: 80a22000                 cmp     %o0, 0
F00B6C08: 02800117                 be      loc_F00B7064
F00B6C0C: a8102000                 mov     0, %l4
F00B6C10: 92100008                 mov     %o0, %o1
F00B6C14: 913a4014                 sra     %o1, %l4, %o0
F00B6C18: 808a2001                 btst    1, %o0
F00B6C1C: 3280005b                 bne,a   loc_F00B6D88
F00B6C20: 90102001                 mov     1, %o0
F00B6C24: a8052001                 inc     %l4
F00B6C28: 80a52007                 cmp     %l4, 7
F00B6C2C: 04bffffb                 ble     loc_F00B6C18
F00B6C30: 913a4014                 sra     %o1, %l4, %o0
F00B6C34: 900aa0ff                 and     %o2, 0xFF, %o0
F00B6C38: 80a22000                 cmp     %o0, 0
F00B6C3C: 1280010b                 bne     loc_F00B7068
F00B6C40: 90100010                 mov     %l0, %o0
F00B6C44: d00c2043                 ldub    [%l0+0x43], %o0
F00B6C48: 900a2007                 and     %o0, 7, %o0
F00B6C4C: 80a22007                 cmp     %o0, 7
F00B6C50: 12800106                 bne     loc_F00B7068
F00B6C54: 90100010                 mov     %l0, %o0
F00B6C58: d00ce008                 ldub    [%l3+8], %o0
F00B6C5C: d20c2043                 ldub    [%l0+0x43], %o1
F00B6C60: d02c2054                 stb     %o0, [%l0+0x54]
F00B6C64: 808a6020                 btst    0x20, %o1 ! ' '
F00B6C68: 02800003                 be      loc_F00B6C74
F00B6C6C: 94100008                 mov     %o0, %o2
F00B6C70: 94102080                 mov     0x80, %o2
F00B6C74: 900aa0d8                 and     %o2, 0xD8, %o0
F00B6C78: 80a22080                 cmp     %o0, 0x80
F00B6C7C: 128000fb                 bne     loc_F00B7068
F00B6C80: 90100010                 mov     %l0, %o0
F00B6C84: d00ce01c                 ldub    [%l3+0x1C], %o0
F00B6C88: 908a201f                 andcc   %o0, 0x1F, %o0
F00B6C8C: 02800005                 be      loc_F00B6CA0
F00B6C90: a40aa007                 and     %o2, 7, %l2
F00B6C94: 80a22000                 cmp     %o0, 0
F00B6C98: 12800000                 bne     loc_F00B6C98
F00B6C9C: 01000000                 nop
F00B6CA0: c02ce00c                 clrb    [%l3+0xC]
F00B6CA4: 94040014                 add     %l0, %l4, %o2
F00B6CA8: d00aa066                 ldub    [%o2+0x66], %o0
F00B6CAC: 900a201f                 and     %o0, 0x1F, %o0
F00B6CB0: d02ce018                 stb     %o0, [%l3+0x18]
F00B6CB4: d00aa05e                 ldub    [%o2+0x5E], %o0
F00B6CB8: d20c2077                 ldub    [%l0+0x77], %o1
F00B6CBC: 90120009                 bset    %o1, %o0
F00B6CC0: d02ce01c                 stb     %o0, [%l3+0x1C]
F00B6CC4: d00c2031                 ldub    [%l0+0x31], %o0
F00B6CC8: 90023ffd                 inc     -3, %o0
F00B6CCC: 900a20ff                 and     %o0, 0xFF, %o0
F00B6CD0: 80a22001                 cmp     %o0, 1
F00B6CD4: 18800005                 bgu     loc_F00B6CE8
F00B6CD8: 912d2003                 sll     %l4, 3, %o0
F00B6CDC: d00aa034                 ldub    [%o2+0x34], %o0
F00B6CE0: d02ce030                 stb     %o0, [%l3+0x30]
F00B6CE4: 912d2003                 sll     %l4, 3, %o0
F00B6CE8: 90120012                 bset    %l2, %o0
F00B6CEC: aa100008                 mov     %o0, %l5
F00B6CF0: 912a2010                 sll     %o0, 16, %o0
F00B6CF4: 973a2010                 sra     %o0, 16, %o3
F00B6CF8: 912ae002                 sll     %o3, 2, %o0
F00B6CFC: d20c2043                 ldub    [%l0+0x43], %o1
F00B6D00: 90020010                 add     %o0, %l0, %o0
F00B6D04: 808a6020                 btst    0x20, %o1 ! ' '
F00B6D08: 02800024                 be      loc_F00B6D98
F00B6D0C: e20220b8                 ld      [%o0+0xB8], %l1
F00B6D10: 94102000                 mov     0, %o2
F00B6D14: a4102000                 mov     0, %l2
F00B6D18: 9210000b                 mov     %o3, %o1
F00B6D1C: 90024012                 add     %o1, %l2, %o0
F00B6D20: 912a2002                 sll     %o0, 2, %o0
F00B6D24: 90020010                 add     %o0, %l0, %o0
F00B6D28: d00220b8                 ld      [%o0+0xB8], %o0
F00B6D2C: 80a22000                 cmp     %o0, 0
F00B6D30: 22800007                 be,a    loc_F00B6D4C
F00B6D34: a404a001                 inc     %l2
F00B6D38: 80a46000                 cmp     %l1, 0
F00B6D3C: 12800003                 bne     loc_F00B6D48
F00B6D40: 9402a001                 inc     %o2
F00B6D44: a2100008                 mov     %o0, %l1
F00B6D48: a404a001                 inc     %l2
F00B6D4C: 80a4a007                 cmp     %l2, 7
F00B6D50: 04bffff4                 ble     loc_F00B6D20
F00B6D54: 90024012                 add     %o1, %l2, %o0
F00B6D58: 900aa0ff                 and     %o2, 0xFF, %o0
F00B6D5C: 80a22001                 cmp     %o0, 1
F00B6D60: 2280000d                 be,a    loc_F00B6D94
F00B6D64: e40c600a                 ldub    [%l1+0xA], %l2
F00B6D68: 0880000c                 bleu    loc_F00B6D98
F00B6D6C: 133c047a                 sethi   %hi(off_F011EA4C), %o1! "unrecoverable SCSI bus parity error (ID"...
F00B6D70: d402624c                 ld      [%o1+%lo(off_F011EA4C)], %o2! "unrecoverable SCSI bus parity error (ID"...
F00B6D74: 90100010                 mov     %l0, %o0
F00B6D78: 4000039d                 call    _esplog
F00B6D7C: 92102003                 mov     3, %o1
F00B6D80: 108000ba                 ba      loc_F00B7068
F00B6D84: 90100010                 mov     %l0, %o0
F00B6D88: 912a0014                 sll     %o0, %l4, %o0
F00B6D8C: 10bfffaa                 ba      loc_F00B6C34
F00B6D90: 941a8008                 btog    %o0, %o2
F00B6D94: aa054012                 add     %l5, %l2, %l5
F00B6D98: 80a46000                 cmp     %l1, 0
F00B6D9C: 02800007                 be      loc_F00B6DB8
F00B6DA0: 80a00011                 cmp     %g0, %l1
F00B6DA4: d014605c                 lduh    [%l1+0x5C], %o0
F00B6DA8: 808a2110                 btst    0x110, %o0
F00B6DAC: 12800069                 bne     loc_F00B6F50
F00B6DB0: 808a2100                 btst    0x100, %o0
F00B6DB4: 80a00011                 cmp     %g0, %l1
F00B6DB8: 90602000                 subc    %g0, 0, %o0
F00B6DBC: ae0c4008                 and     %l1, %o0, %l7
F00B6DC0: a207bf80                 add     %fp, var_80, %l1
F00B6DC4: 4000095a                 call    _scsi_cookie
F00B6DC8: 90100010                 mov     %l0, %o0
F00B6DCC: d027bff0                 st      %o0, [%fp+var_10]
F00B6DD0: e837bff4                 sth     %l4, [%fp+var_C]
F00B6DD4: e42fbff6                 stb     %l2, [%fp+var_A]
F00B6DD8: c02fbff7                 clrb    [%fp+var_9]
F00B6DDC: 90100011                 mov     %l1, %o0
F00B6DE0: 9207bff0                 add     %fp, var_10, %o1
F00B6DE4: 40000181                 call    _esp_makeproxy_cmd
F00B6DE8: 94102006                 mov     6, %o2
F00B6DEC: 4000015b                 call    _esp_init_cmd
F00B6DF0: 90100011                 mov     %l1, %o0
F00B6DF4: 90100010                 mov     %l0, %o0
F00B6DF8: 92102004                 mov     4, %o1
F00B6DFC: 153c047a9412a250         set     aNoCommandForRe, %o2! "No command for reconnect of Target %d L"...
F00B6E04: 96100014                 mov     %l4, %o3
F00B6E08: c4042080                 ld      [%l0+0x80], %g2
F00B6E0C: 98100012                 mov     %l2, %o4
F00B6E10: da042084                 ld      [%l0+0x84], %o5
F00B6E14: 8400a001                 inc     %g2
F00B6E18: c4242080                 st      %g2, [%l0+0x80]
F00B6E1C: 9a036001                 inc     %o5
F00B6E20: 40000373                 call    _esplog
F00B6E24: da242084                 st      %o5, [%l0+0x84]
F00B6E28: 90102006                 mov     6, %o0
F00B6E2C: d02c204c                 stb     %o0, [%l0+0x4C]
F00B6E30: 90102001                 mov     1, %o0
F00B6E34: d02c2053                 stb     %o0, [%l0+0x53]
F00B6E38: 90102012                 mov     0x12, %o0
F00B6E3C: d02ce00c                 stb     %o0, [%l3+0xC]
F00B6E40: ea3420b2                 sth     %l5, [%l0+0xB2]
F00B6E44: 912d6010                 sll     %l5, 16, %o0
F00B6E48: 913a200e                 sra     %o0, 14, %o0
F00B6E4C: 94020010                 add     %o0, %l0, %o2
F00B6E50: e222a0b8                 st      %l1, [%o2+0xB8]
F00B6E54: d00c2041                 ldub    [%l0+0x41], %o0
F00B6E58: d2042080                 ld      [%l0+0x80], %o1
F00B6E5C: d02c2042                 stb     %o0, [%l0+0x42]
F00B6E60: 9010201a                 mov     0x1A, %o0
F00B6E64: 80a26000                 cmp     %o1, 0
F00B6E68: 02800014                 be      loc_F00B6EB8
F00B6E6C: d02c2041                 stb     %o0, [%l0+0x41]
F00B6E70: 2d02aea5                 sethi   0xABA9400, %l6
F00B6E74: b010000a                 mov     %o2, %i0
F00B6E78: a6100011                 mov     %l1, %l3
F00B6E7C: 90100010                 mov     %l0, %o0
F00B6E80: 7ffff757                 call    _esp_dopoll
F00B6E84: 9215a100                 or      %l6, 0x100, %o1
F00B6E88: 80a22000                 cmp     %o0, 0
F00B6E8C: 22800008                 be,a    loc_F00B6EAC
F00B6E90: d0042080                 ld      [%l0+0x80], %o0
F00B6E94: d00620b8                 ld      [%i0+0xB8], %o0
F00B6E98: 80a20013                 cmp     %o0, %l3
F00B6E9C: 22800076                 be,a    loc_F00B7074
F00B6EA0: c02620b8                 clr     [%i0+0xB8]
F00B6EA4: 10800075                 ba      locret_F00B7078
F00B6EA8: b0102008                 mov     8, %i0
F00B6EAC: 80a22000                 cmp     %o0, 0
F00B6EB0: 12bffff4                 bne     loc_F00B6E80
F00B6EB4: 90100010                 mov     %l0, %o0
F00B6EB8: d00c6028                 ldub    [%l1+0x28], %o0
F00B6EBC: 80a22000                 cmp     %o0, 0
F00B6EC0: 113c047a                 sethi   %hi(aProxyAbortSFor), %o0! "Proxy abort %s for Target %d Lun %d"
F00B6EC4: 12800005                 bne     loc_F00B6ED8
F00B6EC8: 94122280                 or      %o0, %lo(aProxyAbortSFor), %o2! "Proxy abort %s for Target %d Lun %d"
F00B6ECC: 113c047a                 sethi   %hi(aSucceeded), %o0! "succeeded"
F00B6ED0: 10800004                 ba      loc_F00B6EE0
F00B6ED4: 961222a8                 or      %o0, %lo(aSucceeded), %o3! "succeeded"
F00B6ED8: 113c047a961222b8         set     aFailed, %o3! "failed"
F00B6EE0: 90100010                 mov     %l0, %o0
F00B6EE4: 92102006                 mov     6, %o1
F00B6EE8: 98100014                 mov     %l4, %o4
F00B6EEC: 40000340                 call    _esplog
F00B6EF0: 9a100012                 mov     %l2, %o5
F00B6EF4: 80a5e000                 cmp     %l7, 0
F00B6EF8: 02800006                 be      loc_F00B6F10
F00B6EFC: 912d6010                 sll     %l5, 16, %o0
F00B6F00: 913a200e                 sra     %o0, 14, %o0
F00B6F04: 90020010                 add     %o0, %l0, %o0
F00B6F08: 10800009                 ba      loc_F00B6F2C
F00B6F0C: ee2220b8                 st      %l7, [%o0+0xB8]
F00B6F10: 913a200e                 sra     %o0, 14, %o0
F00B6F14: b0020010                 add     %o0, %l0, %i0
F00B6F18: d20620b8                 ld      [%i0+0xB8], %o1
F00B6F1C: 9007bf80                 add     %fp, var_80, %o0
F00B6F20: 80a24008                 cmp     %o1, %o0
F00B6F24: 22800002                 be,a    loc_F00B6F2C
F00B6F28: c02620b8                 clr     [%i0+0xB8]
F00B6F2C: d00c6028                 ldub    [%l1+0x28], %o0
F00B6F30: 80a22000                 cmp     %o0, 0
F00B6F34: 12800051                 bne     locret_F00B7078
F00B6F38: b0102008                 mov     8, %i0
F00B6F3C: d00c606b                 ldub    [%l1+0x6B], %o0
F00B6F40: 80a22001                 cmp     %o0, 1
F00B6F44: 2280004d                 be,a    locret_F00B7078
F00B6F48: b0102005                 mov     5, %i0
F00B6F4C: 3080004b                 ba,a    locret_F00B7078
F00B6F50: 02800018                 be      loc_F00B6FB0
F00B6F54: 94102000                 mov     0, %o2
F00B6F58: d0042088                 ld      [%l0+0x88], %o0
F00B6F5C: 90022001                 inc     %o0
F00B6F60: d0242088                 st      %o0, [%l0+0x88]
F00B6F64: 9010201a                 mov     0x1A, %o0
F00B6F68: d02ce00c                 stb     %o0, [%l3+0xC]
F00B6F6C: d00c606c                 ldub    [%l1+0x6C], %o0
F00B6F70: 80a22000                 cmp     %o0, 0
F00B6F74: 0280000d                 be      loc_F00B6FA8
F00B6F78: d02c2053                 stb     %o0, [%l0+0x53]
F00B6F7C: 920aa0ff                 and     %o2, 0xFF, %o1
F00B6F80: 9402a001                 inc     %o2
F00B6F84: 90044009                 add     %l1, %o1, %o0
F00B6F88: d00a206d                 ldub    [%o0+0x6D], %o0
F00B6F8C: 92040009                 add     %l0, %o1, %o1
F00B6F90: d02a604c                 stb     %o0, [%o1+0x4C]
F00B6F94: d20c2053                 ldub    [%l0+0x53], %o1
F00B6F98: 900aa0ff                 and     %o2, 0xFF, %o0
F00B6F9C: 80a20009                 cmp     %o0, %o1
F00B6FA0: 0abffff8                 bcs     loc_F00B6F80
F00B6FA4: 920aa0ff                 and     %o2, 0xFF, %o1
F00B6FA8: 10800015                 ba      loc_F00B6FFC
F00B6FAC: c02c606b                 clrb    [%l1+0x6B]
F00B6FB0: 113c047c                 sethi   %hi(_scsi_options), %o0
F00B6FB4: d0022158                 ld      [%o0+%lo(_scsi_options)], %o0
F00B6FB8: 808a2040                 btst    0x40, %o0 ! '@'
F00B6FBC: 02800011                 be      loc_F00B7000
F00B6FC0: 90102012                 mov     0x12, %o0
F00B6FC4: d0046014                 ld      [%l1+0x14], %o0
F00B6FC8: 808a2008                 btst    8, %o0
F00B6FCC: 22800006                 be,a    loc_F00B6FE4
F00B6FD0: d00c2043                 ldub    [%l0+0x43], %o0
F00B6FD4: d00c2032                 ldub    [%l0+0x32], %o0
F00B6FD8: 900a20ef                 and     %o0, 0xEF, %o0
F00B6FDC: 10800008                 ba      loc_F00B6FFC
F00B6FE0: d02ce020                 stb     %o0, [%l3+0x20]
F00B6FE4: 808a2020                 btst    0x20, %o0 ! ' '
F00B6FE8: 02800005                 be      loc_F00B6FFC
F00B6FEC: 90102009                 mov     9, %o0
F00B6FF0: d02c204c                 stb     %o0, [%l0+0x4C]
F00B6FF4: 90102001                 mov     1, %o0
F00B6FF8: d02c2053                 stb     %o0, [%l0+0x53]
F00B6FFC: 90102012                 mov     0x12, %o0
F00B7000: d02ce00c                 stb     %o0, [%l3+0xC]
F00B7004: d0042088                 ld      [%l0+0x88], %o0
F00B7008: 80a22000                 cmp     %o0, 0
F00B700C: 02800004                 be      loc_F00B701C
F00B7010: ea3420b2                 sth     %l5, [%l0+0xB2]
F00B7014: 90023fff                 inc     -1, %o0
F00B7018: d0242088                 st      %o0, [%l0+0x88]
F00B701C: d00c2041                 ldub    [%l0+0x41], %o0
F00B7020: b0103fff                 mov     -1, %i0
F00B7024: d02c2042                 stb     %o0, [%l0+0x42]
F00B7028: 9010201a                 mov     0x1A, %o0
F00B702C: d02c2041                 stb     %o0, [%l0+0x41]
F00B7030: 1100003f                 sethi   0xFC00, %o0
F00B7034: d214605c                 lduh    [%l1+0x5C], %o1
F00B7038: 901223ef                 bset    0x3EF, %o0
F00B703C: 920a4008                 and     %o1, %o0, %o1
F00B7040: d0046020                 ld      [%l1+0x20], %o0
F00B7044: d234605c                 sth     %o1, [%l1+0x5C]
F00B7048: d204601c                 ld      [%l1+0x1C], %o1
F00B704C: d024602c                 st      %o0, [%l1+0x2C]
F00B7050: d0046038                 ld      [%l1+0x38], %o0
F00B7054: d2246030                 st      %o1, [%l1+0x30]
F00B7058: d0246034                 st      %o0, [%l1+0x34]
F00B705C: 10800007                 ba      locret_F00B7078
F00B7060: c02c2046                 clrb    [%l0+0x46]
F00B7064: 90100010                 mov     %l0, %o0
F00B7068: 133c047a                 sethi   %hi(aFailedReselect), %o1! "failed reselection"
F00B706C: 4000032a                 call    _esp_printstate
F00B7070: 921262c0                 bset    %lo(aFailedReselect), %o1! "failed reselection"
F00B7074: b0102008                 mov     8, %i0
F00B7078: 81c7e008                 ret
F00B707C: 81e80000                 restore
