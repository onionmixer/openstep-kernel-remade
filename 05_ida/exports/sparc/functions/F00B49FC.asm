F00B49FC: 9de3bf98                 save    %sp, -0x68, %sp
F00B4A00: d05620b2                 ldsh    [%i0+0xB2], %o0
F00B4A04: 912a2002                 sll     %o0, 2, %o0
F00B4A08: 90020018                 add     %o0, %i0, %o0
F00B4A0C: e00220b8                 ld      [%o0+0xB8], %l0
F00B4A10: d64c202b                 ldsb    [%l0+0x2B], %o3
F00B4A14: 80a2e000                 cmp     %o3, 0
F00B4A18: 06800008                 bl      loc_F00B4A38
F00B4A1C: a6102000                 mov     0, %l3
F00B4A20: 113c04d0                 sethi   %hi(_dk_busy), %o0
F00B4A24: 92102001                 mov     1, %o1
F00B4A28: d4022050                 ld      [%o0+%lo(_dk_busy)], %o2
F00B4A2C: 932a400b                 sll     %o1, %o3, %o1
F00B4A30: 922a8009                 andn    %o2, %o1, %o1
F00B4A34: d2222050                 st      %o1, [%o0+%lo(_dk_busy)]
F00B4A38: d41620b2                 lduh    [%i0+0xB2], %o2
F00B4A3C: 90103fff                 mov     -1, %o0
F00B4A40: d2062084                 ld      [%i0+0x84], %o1
F00B4A44: d43620b0                 sth     %o2, [%i0+0xB0]
F00B4A48: d03620b2                 sth     %o0, [%i0+0xB2]
F00B4A4C: 92027fff                 inc     -1, %o1
F00B4A50: d2262084                 st      %o1, [%i0+0x84]
F00B4A54: d00e2054                 ldub    [%i0+0x54], %o0
F00B4A58: 90023ff6                 inc     -0xA, %o0
F00B4A5C: 900a20ff                 and     %o0, 0xFF, %o0
F00B4A60: 80a22001                 cmp     %o0, 1
F00B4A64: 18800003                 bgu     loc_F00B4A70
F00B4A68: a410000a                 mov     %o2, %l2
F00B4A6C: a6102001                 mov     1, %l3
F00B4A70: d00c2029                 ldub    [%l0+0x29], %o0
F00B4A74: 808a2010                 btst    0x10, %o0
F00B4A78: 02800013                 be      loc_F00B4AC4
F00B4A7C: 808a2008                 btst    8, %o0
F00B4A80: d004201c                 ld      [%l0+0x1C], %o0
F00B4A84: d00a0000                 ldub    [%o0], %o0
F00B4A88: 808a2002                 btst    2, %o0
F00B4A8C: 2280000d                 be,a    loc_F00B4AC0
F00B4A90: d00c2029                 ldub    [%l0+0x29], %o0
F00B4A94: d4142008                 lduh    [%l0+8], %o2
F00B4A98: 9006000a                 add     %i0, %o2, %o0
F00B4A9C: d00a205e                 ldub    [%o0+0x5E], %o0
F00B4AA0: 80a22000                 cmp     %o0, 0
F00B4AA4: 02800006                 be      loc_F00B4ABC
F00B4AA8: 90102001                 mov     1, %o0
F00B4AAC: d20e2078                 ldub    [%i0+0x78], %o1
F00B4AB0: 912a000a                 sll     %o0, %o2, %o0
F00B4AB4: 902a4008                 andn    %o1, %o0, %o0
F00B4AB8: d02e2078                 stb     %o0, [%i0+0x78]
F00B4ABC: d00c2029                 ldub    [%l0+0x29], %o0
F00B4AC0: 808a2008                 btst    8, %o0
F00B4AC4: 22800019                 be,a    loc_F00B4B28
F00B4AC8: d00e2041                 ldub    [%i0+0x41], %o0
F00B4ACC: d2042050                 ld      [%l0+0x50], %o1
F00B4AD0: 80a26000                 cmp     %o1, 0
F00B4AD4: 2280000a                 be,a    loc_F00B4AFC
F00B4AD8: 92842048                 addcc   %l0, 0x48, %o1 ! 'H'
F00B4ADC: d0026004                 ld      [%o1+4], %o0
F00B4AE0: 80a22000                 cmp     %o0, 0
F00B4AE4: 02800006                 be      loc_F00B4AFC
F00B4AE8: 92842048                 addcc   %l0, 0x48, %o1 ! 'H'
F00B4AEC: 113c0479                 sethi   %hi(aEspFinishMoreT), %o0! "esp_finish: more than one segment with "...
F00B4AF0: 7ffd81a0                 call    _panic
F00B4AF4: 90122050                 bset    %lo(aEspFinishMoreT), %o0! "esp_finish: more than one segment with "...
F00B4AF8: 92842048                 addcc   %l0, 0x48, %o1 ! 'H'
F00B4AFC: 02800007                 be      loc_F00B4B18
F00B4B00: 94102000                 mov     0, %o2
F00B4B04: d0026004                 ld      [%o1+4], %o0
F00B4B08: d2026008                 ld      [%o1+8], %o1
F00B4B0C: 80a26000                 cmp     %o1, 0
F00B4B10: 12bffffd                 bne     loc_F00B4B04
F00B4B14: 94028008                 add     %o2, %o0, %o2
F00B4B18: d0042040                 ld      [%l0+0x40], %o0
F00B4B1C: 9022000a                 sub     %o0, %o2, %o0
F00B4B20: d0242024                 st      %o0, [%l0+0x24]
F00B4B24: d00e2041                 ldub    [%i0+0x41], %o0
F00B4B28: d02e2042                 stb     %o0, [%i0+0x42]
F00B4B2C: c02e2041                 clrb    [%i0+0x41]
F00B4B30: 912ca010                 sll     %l2, 16, %o0
F00B4B34: 913a200e                 sra     %o0, 14, %o0
F00B4B38: a2020018                 add     %o0, %i0, %l1
F00B4B3C: c02460b8                 clr     [%l1+0xB8]
F00B4B40: d0042014                 ld      [%l0+0x14], %o0
F00B4B44: 808a2001                 btst    1, %o0
F00B4B48: 0280000a                 be      loc_F00B4B70
F00B4B4C: 80a4e000                 cmp     %l3, 0
F00B4B50: d0062080                 ld      [%i0+0x80], %o0
F00B4B54: 90023fff                 inc     -1, %o0
F00B4B58: d0262080                 st      %o0, [%i0+0x80]
F00B4B5C: d2042010                 ld      [%l0+0x10], %o1
F00B4B60: 9fc24000                 call    %o1
F00B4B64: 90100010                 mov     %l0, %o0
F00B4B68: 1080001b                 ba      locret_F00B4BD4
F00B4B6C: 90103fff                 mov     -1, %o0
F00B4B70: 04800015                 ble     loc_F00B4BC4
F00B4B74: 9010201e                 mov     0x1E, %o0
F00B4B78: d02e2041                 stb     %o0, [%i0+0x41]
F00B4B7C: d2042010                 ld      [%l0+0x10], %o1
F00B4B80: 9fc24000                 call    %o1
F00B4B84: 90100010                 mov     %l0, %o0
F00B4B88: c02e2041                 clrb    [%i0+0x41]
F00B4B8C: d00460b8                 ld      [%l1+0xB8], %o0
F00B4B90: 80a22000                 cmp     %o0, 0
F00B4B94: 32800009                 bne,a   loc_F00B4BB8
F00B4B98: e43620b2                 sth     %l2, [%i0+0xB2]
F00B4B9C: 90100018                 mov     %i0, %o0
F00B4BA0: 153c0479                 sethi   %hi(aLinkedCommandN), %o2! "linked command not started by driver"
F00B4BA4: 92102003                 mov     3, %o1
F00B4BA8: 40000c11                 call    _esplog
F00B4BAC: 9412a080                 bset    %lo(aLinkedCommandN), %o2! "linked command not started by driver"
F00B4BB0: 10800009                 ba      locret_F00B4BD4
F00B4BB4: 90102008                 mov     8, %o0
F00B4BB8: 7fffff73                 call    _esp_link_start
F00B4BBC: 90100018                 mov     %i0, %o0
F00B4BC0: 30800005                 ba,a    locret_F00B4BD4
F00B4BC4: d2042010                 ld      [%l0+0x10], %o1
F00B4BC8: 9fc24000                 call    %o1
F00B4BCC: 90100010                 mov     %l0, %o0
F00B4BD0: 90102005                 mov     5, %o0
F00B4BD4: 81c7e008                 ret
F00B4BD8: 91e80008                 restore %g0, %o0, %o0
