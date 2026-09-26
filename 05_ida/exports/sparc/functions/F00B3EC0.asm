F00B3EC0: 9de3bf28                 save    %sp, -0xD8, %sp
F00B3EC4: e0060000                 ld      [%i0], %l0
F00B3EC8: d2162004                 lduh    [%i0+4], %o1
F00B3ECC: d40e2006                 ldub    [%i0+6], %o2
F00B3ED0: 932a6003                 sll     %o1, 3, %o1
F00B3ED4: d0040000                 ld      [%l0], %o0
F00B3ED8: 7fff8b8b                 call    _splr
F00B3EDC: a2128009                 or      %o2, %o1, %l1
F00B3EE0: a4100011                 mov     %l1, %l2
F00B3EE4: d20c2041                 ldub    [%l0+0x41], %o1
F00B3EE8: 80a26000                 cmp     %o1, 0
F00B3EEC: 0280000c                 be      loc_F00B3F1C
F00B3EF0: a8100008                 mov     %o0, %l4
F00B3EF4: d25420b2                 ldsh    [%l0+0xB2], %o1
F00B3EF8: 912c6010                 sll     %l1, 16, %o0
F00B3EFC: 913a2010                 sra     %o0, 16, %o0
F00B3F00: 80a24008                 cmp     %o1, %o0
F00B3F04: 12800007                 bne     loc_F00B3F20
F00B3F08: 80a66000                 cmp     %i1, 0
F00B3F0C: 7fff8b86                 call    _splx
F00B3F10: 90100014                 mov     %l4, %o0
F00B3F14: 1080006d                 ba      locret_F00B40C8
F00B3F18: b0102000                 mov     0, %i0
F00B3F1C: 80a66000                 cmp     %i1, 0
F00B3F20: 12800006                 bne     loc_F00B3F38
F00B3F24: 912ca010                 sll     %l2, 16, %o0
F00B3F28: 913a200e                 sra     %o0, 14, %o0
F00B3F2C: 90020010                 add     %o0, %l0, %o0
F00B3F30: f20220b8                 ld      [%o0+0xB8], %i1
F00B3F34: 912ca010                 sll     %l2, 16, %o0
F00B3F38: 913a200e                 sra     %o0, 14, %o0
F00B3F3C: 92020010                 add     %o0, %l0, %o1
F00B3F40: d00260b8                 ld      [%o1+0xB8], %o0
F00B3F44: 80a22000                 cmp     %o0, 0
F00B3F48: 22800002                 be,a    loc_F00B3F50
F00B3F4C: b2102000                 mov     0, %i1
F00B3F50: 80a66000                 cmp     %i1, 0
F00B3F54: 02800012                 be      loc_F00B3F9C
F00B3F58: 80a64008                 cmp     %i1, %o0
F00B3F5C: 12800011                 bne     loc_F00B3FA0
F00B3F60: 80a66000                 cmp     %i1, 0
F00B3F64: d00e6029                 ldub    [%i1+0x29], %o0
F00B3F68: 80a22000                 cmp     %o0, 0
F00B3F6C: 1280000d                 bne     loc_F00B3FA0
F00B3F70: 80a66000                 cmp     %i1, 0
F00B3F74: c02260b8                 clr     [%o1+0xB8]
F00B3F78: 90102005                 mov     5, %o0
F00B3F7C: d02e6028                 stb     %o0, [%i1+0x28]
F00B3F80: d0042084                 ld      [%l0+0x84], %o0
F00B3F84: 90023fff                 inc     -1, %o0
F00B3F88: d0242084                 st      %o0, [%l0+0x84]
F00B3F8C: d2066010                 ld      [%i1+0x10], %o1
F00B3F90: 9fc24000                 call    %o1
F00B3F94: 90100019                 mov     %i1, %o0
F00B3F98: b2102000                 mov     0, %i1
F00B3F9C: 80a66000                 cmp     %i1, 0
F00B3FA0: 12800006                 bne     loc_F00B3FB8
F00B3FA4: 912ca010                 sll     %l2, 16, %o0
F00B3FA8: 7fff8b5f                 call    _splx
F00B3FAC: 90100014                 mov     %l4, %o0
F00B3FB0: 10800046                 ba      locret_F00B40C8
F00B3FB4: b0102001                 mov     1, %i0
F00B3FB8: 913a200e                 sra     %o0, 14, %o0
F00B3FBC: 90020010                 add     %o0, %l0, %o0
F00B3FC0: c02220b8                 clr     [%o0+0xB8]
F00B3FC4: a2100019                 mov     %i1, %l1
F00B3FC8: d014605c                 lduh    [%l1+0x5C], %o0
F00B3FCC: 808a2010                 btst    0x10, %o0
F00B3FD0: 02800006                 be      loc_F00B3FE8
F00B3FD4: a6102001                 mov     1, %l3
F00B3FD8: d0042088                 ld      [%l0+0x88], %o0
F00B3FDC: 90023fff                 inc     -1, %o0
F00B3FE0: 10800003                 ba      loc_F00B3FEC
F00B3FE4: d0242088                 st      %o0, [%l0+0x88]
F00B3FE8: a6102000                 mov     0, %l3
F00B3FEC: b207bf88                 add     %fp, var_78, %i1
F00B3FF0: 90100019                 mov     %i1, %o0
F00B3FF4: d4042084                 ld      [%l0+0x84], %o2
F00B3FF8: 92100018                 mov     %i0, %o1
F00B3FFC: 9402bfff                 inc     -1, %o2
F00B4000: d4242084                 st      %o2, [%l0+0x84]
F00B4004: 40000cf9                 call    _esp_makeproxy_cmd
F00B4008: 94102006                 mov     6, %o2
F00B400C: 7fffff6c                 call    _esp_start
F00B4010: 90100019                 mov     %i1, %o0
F00B4014: 80a22001                 cmp     %o0, 1
F00B4018: 32800012                 bne,a   loc_F00B4060
F00B401C: d0042084                 ld      [%l0+0x84], %o0
F00B4020: d00fbfb0                 ldub    [%fp+var_50], %o0
F00B4024: 80a22000                 cmp     %o0, 0
F00B4028: 3280000e                 bne,a   loc_F00B4060
F00B402C: d0042084                 ld      [%l0+0x84], %o0
F00B4030: d00fbff3                 ldub    [%fp+var_D], %o0
F00B4034: 80a22001                 cmp     %o0, 1
F00B4038: 3280000a                 bne,a   loc_F00B4060
F00B403C: d0042084                 ld      [%l0+0x84], %o0
F00B4040: b0102001                 mov     1, %i0
F00B4044: 90102005                 mov     5, %o0
F00B4048: d02c6028                 stb     %o0, [%l1+0x28]
F00B404C: d2046010                 ld      [%l1+0x10], %o1
F00B4050: 9fc24000                 call    %o1
F00B4054: 90100011                 mov     %l1, %o0
F00B4058: 10800012                 ba      loc_F00B40A0
F00B405C: d00c2041                 ldub    [%l0+0x41], %o0
F00B4060: 80a4e000                 cmp     %l3, 0
F00B4064: 90022001                 inc     %o0
F00B4068: 02800008                 be      loc_F00B4088
F00B406C: d0242084                 st      %o0, [%l0+0x84]
F00B4070: d0042088                 ld      [%l0+0x88], %o0
F00B4074: 90022001                 inc     %o0
F00B4078: d0242088                 st      %o0, [%l0+0x88]
F00B407C: d014605c                 lduh    [%l1+0x5C], %o0
F00B4080: 90122010                 bset    0x10, %o0
F00B4084: d034605c                 sth     %o0, [%l1+0x5C]
F00B4088: 912ca010                 sll     %l2, 16, %o0
F00B408C: 913a200e                 sra     %o0, 14, %o0
F00B4090: 90020010                 add     %o0, %l0, %o0
F00B4094: e22220b8                 st      %l1, [%o0+0xB8]
F00B4098: b0102000                 mov     0, %i0
F00B409C: d00c2041                 ldub    [%l0+0x41], %o0
F00B40A0: 80a22000                 cmp     %o0, 0
F00B40A4: 12800007                 bne     loc_F00B40C0
F00B40A8: 90100010                 mov     %l0, %o0
F00B40AC: 932ca010                 sll     %l2, 16, %o1
F00B40B0: 933a6010                 sra     %o1, 16, %o1
F00B40B4: 92026001                 inc     %o1
F00B40B8: 4000010f                 call    _esp_ustart
F00B40BC: 920a603f                 and     %o1, 0x3F, %o1
F00B40C0: 7fff8b19                 call    _splx
F00B40C4: 90100014                 mov     %l4, %o0
F00B40C8: 81c7e008                 ret
F00B40CC: 81e80000                 restore
