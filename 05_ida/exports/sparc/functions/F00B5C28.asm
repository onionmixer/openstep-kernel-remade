F00B5C28: 9de3bf98                 save    %sp, -0x68, %sp
F00B5C2C: a0100018                 mov     %i0, %l0
F00B5C30: d05420b2                 ldsh    [%l0+0xB2], %o0
F00B5C34: ec0c2044                 ldub    [%l0+0x44], %l6
F00B5C38: ea04209c                 ld      [%l0+0x9C], %l5
F00B5C3C: 912a2002                 sll     %o0, 2, %o0
F00B5C40: 90020010                 add     %o0, %l0, %o0
F00B5C44: 920da0ff                 and     %l6, 0xFF, %o1
F00B5C48: 80a26020                 cmp     %o1, 0x20 ! ' '
F00B5C4C: 12800008                 bne     loc_F00B5C6C
F00B5C50: e60220b8                 ld      [%o0+0xB8], %l3
F00B5C54: d00c2041                 ldub    [%l0+0x41], %o0
F00B5C58: b0102002                 mov     2, %i0
F00B5C5C: d02c2042                 stb     %o0, [%l0+0x42]
F00B5C60: 9010201a                 mov     0x1A, %o0
F00B5C64: 1080005a                 ba      locret_F00B5DCC
F00B5C68: d02c2041                 stb     %o0, [%l0+0x41]
F00B5C6C: d00c2043                 ldub    [%l0+0x43], %o0
F00B5C70: 900a2020                 and     %o0, 0x20, %o0
F00B5C74: 80a22000                 cmp     %o0, 0
F00B5C78: 02800005                 be      loc_F00B5C8C
F00B5C7C: a8100008                 mov     %o0, %l4
F00B5C80: d00ce02a                 ldub    [%l3+0x2A], %o0
F00B5C84: 90122004                 bset    4, %o0
F00B5C88: d02ce02a                 stb     %o0, [%l3+0x2A]
F00B5C8C: a4102000                 mov     0, %l2
F00B5C90: 80a26010                 cmp     %o1, 0x10
F00B5C94: 1280000d                 bne     loc_F00B5CC8
F00B5C98: b01020ff                 mov     0xFF, %i0
F00B5C9C: 80a52000                 cmp     %l4, 0
F00B5CA0: 0280001c                 be      loc_F00B5D10
F00B5CA4: e20d6008                 ldub    [%l5+8], %l1
F00B5CA8: a2102002                 mov     2, %l1
F00B5CAC: 90100010                 mov     %l0, %o0
F00B5CB0: 92102003                 mov     3, %o1
F00B5CB4: 153c0479                 sethi   %hi(aScsiBusStatusP), %o2! "SCSI bus STATUS phase parity error"
F00B5CB8: 400007cd                 call    _esplog
F00B5CBC: 9412a340                 bset    %lo(aScsiBusStatusP), %o2! "SCSI bus STATUS phase parity error"
F00B5CC0: 10800014                 ba      loc_F00B5D10
F00B5CC4: a4102005                 mov     5, %l2
F00B5CC8: f00d6008                 ldub    [%l5+8], %i0
F00B5CCC: 113c0479                 sethi   %hi(unk_F011E768), %o0
F00B5CD0: a2100018                 mov     %i0, %l1
F00B5CD4: e22c2054                 stb     %l1, [%l0+0x54]
F00B5CD8: f00d6008                 ldub    [%l5+8], %i0
F00B5CDC: 90122368                 bset    %lo(unk_F011E768), %o0! char *
F00B5CE0: 7ffd7a5e                 call    _printf
F00B5CE4: f02c2054                 stb     %i0, [%l0+0x54]
F00B5CE8: b0102000                 mov     0, %i0
F00B5CEC: 80a52000                 cmp     %l4, 0
F00B5CF0: 02800008                 be      loc_F00B5D10
F00B5CF4: c02c2054                 clrb    [%l0+0x54]
F00B5CF8: 90100010                 mov     %l0, %o0
F00B5CFC: 92102003                 mov     3, %o1
F00B5D00: 153c0478                 sethi   %hi(_msginperr), %o2
F00B5D04: d402a278                 ld      [%o2+%lo(_msginperr)], %o2
F00B5D08: 400007b9                 call    _esplog
F00B5D0C: a4102009                 mov     9, %l2
F00B5D10: 80a460ff                 cmp     %l1, 0xFF
F00B5D14: 02800009                 be      loc_F00B5D38
F00B5D18: 80a4a000                 cmp     %l2, 0
F00B5D1C: d00ce029                 ldub    [%l3+0x29], %o0
F00B5D20: d204e030                 ld      [%l3+0x30], %o1
F00B5D24: 90122010                 bset    0x10, %o0
F00B5D28: d02ce029                 stb     %o0, [%l3+0x29]
F00B5D2C: 90026001                 add     %o1, 1, %o0
F00B5D30: d024e030                 st      %o0, [%l3+0x30]
F00B5D34: e22a4000                 stb     %l1, [%o1]
F00B5D38: 32800018                 bne,a   loc_F00B5D98
F00B5D3C: e42c204c                 stb     %l2, [%l0+0x4C]
F00B5D40: 80a62000                 cmp     %i0, 0
F00B5D44: 22800008                 be,a    loc_F00B5D64
F00B5D48: d00c2041                 ldub    [%l0+0x41], %o0
F00B5D4C: 90063ff6                 add     %i0, -0xA, %o0
F00B5D50: 900a20ff                 and     %o0, 0xFF, %o0
F00B5D54: 80a22001                 cmp     %o0, 1
F00B5D58: 38800006                 bgu,a   loc_F00B5D70
F00B5D5C: 90102001                 mov     1, %o0
F00B5D60: d00c2041                 ldub    [%l0+0x41], %o0
F00B5D64: d02c2042                 stb     %o0, [%l0+0x42]
F00B5D68: 10800011                 ba      loc_F00B5DAC
F00B5D6C: 90102008                 mov     8, %o0
F00B5D70: d02c205c                 stb     %o0, [%l0+0x5C]
F00B5D74: d02c205d                 stb     %o0, [%l0+0x5D]
F00B5D78: d20c2041                 ldub    [%l0+0x41], %o1
F00B5D7C: 90100010                 mov     %l0, %o0
F00B5D80: d22a2042                 stb     %o1, [%o0+0x42]
F00B5D84: 92102007                 mov     7, %o1
F00B5D88: 40000046                 call    _esp_handle_msg_in_done
F00B5D8C: d22a2041                 stb     %o1, [%o0+0x41]
F00B5D90: 1080000f                 ba      locret_F00B5DCC
F00B5D94: b0100008                 mov     %o0, %i0
F00B5D98: 90102001                 mov     1, %o0
F00B5D9C: d20c2041                 ldub    [%l0+0x41], %o1
F00B5DA0: d02c2053                 stb     %o0, [%l0+0x53]
F00B5DA4: 9010201a                 mov     0x1A, %o0
F00B5DA8: d22c2042                 stb     %o1, [%l0+0x42]
F00B5DAC: 80a5a010                 cmp     %l6, 0x10
F00B5DB0: 12800004                 bne     loc_F00B5DC0
F00B5DB4: d02c2041                 stb     %o0, [%l0+0x41]
F00B5DB8: 10800005                 ba      locret_F00B5DCC
F00B5DBC: b0102002                 mov     2, %i0
F00B5DC0: 90102012                 mov     0x12, %o0
F00B5DC4: d02d600c                 stb     %o0, [%l5+0xC]
F00B5DC8: b0103fff                 mov     -1, %i0
F00B5DCC: 81c7e008                 ret
F00B5DD0: 81e80000                 restore
