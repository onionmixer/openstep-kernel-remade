F00A4F14: 9de3bf98                 save    %sp, -0x68, %sp
F00A4F18: 80a6a000                 cmp     %i2, 0
F00A4F1C: 02800080                 be      loc_F00A511C
F00A4F20: 80a66000                 cmp     %i1, 0
F00A4F24: 0480007f                 ble     loc_F00A5120
F00A4F28: 113c0466                 sethi   -0xFEE6800, %o0
F00A4F2C: a0062008                 add     %i0, 8, %l0
F00A4F30: d006200c                 ld      [%i0+0xC], %o0
F00A4F34: 80a2001a                 cmp     %o0, %i2
F00A4F38: 1880000b                 bgu     loc_F00A4F64
F00A4F3C: 98100010                 mov     %l0, %o4
F00A4F40: d0040000                 ld      [%l0], %o0
F00A4F44: 80a22000                 cmp     %o0, 0
F00A4F48: 02800008                 be      loc_F00A4F68
F00A4F4C: 80a4000c                 cmp     %l0, %o4
F00A4F50: a0042008                 inc     8, %l0
F00A4F54: d0042004                 ld      [%l0+4], %o0
F00A4F58: 80a2001a                 cmp     %o0, %i2
F00A4F5C: 28bffffa                 bleu,a  loc_F00A4F44
F00A4F60: d0040000                 ld      [%l0], %o0
F00A4F64: 80a4000c                 cmp     %l0, %o4
F00A4F68: 22800028                 be,a    loc_F00A5008
F00A4F6C: d0040000                 ld      [%l0], %o0
F00A4F70: d0043ffc                 ld      [%l0-4], %o0
F00A4F74: d2043ff8                 ld      [%l0-8], %o1
F00A4F78: 90020009                 add     %o0, %o1, %o0
F00A4F7C: 80a2001a                 cmp     %o0, %i2
F00A4F80: 2a800022                 bcs,a   loc_F00A5008
F00A4F84: d0040000                 ld      [%l0], %o0
F00A4F88: 18800066                 bgu     loc_F00A5120
F00A4F8C: 113c0466                 sethi   -0xFEE6800, %o0
F00A4F90: 90024019                 add     %o1, %i1, %o0
F00A4F94: d4040000                 ld      [%l0], %o2
F00A4F98: 80a2a000                 cmp     %o2, 0
F00A4F9C: 02800058                 be      loc_F00A50FC
F00A4FA0: d0243ff8                 st      %o0, [%l0-8]
F00A4FA4: d2042004                 ld      [%l0+4], %o1
F00A4FA8: b2068019                 add     %i2, %i1, %i1
F00A4FAC: 80a64009                 cmp     %i1, %o1
F00A4FB0: 2a800054                 bcs,a   loc_F00A5100
F00A4FB4: d0062004                 ld      [%i0+4], %o0
F00A4FB8: 3880005a                 bgu,a   loc_F00A5120
F00A4FBC: 113c04669002000a         set     (aSrmmuTlbflushB+8), %o0! "bflush: bad level %x"
F00A4FC4: d2040000                 ld      [%l0], %o1
F00A4FC8: 80a26000                 cmp     %o1, 0
F00A4FCC: 0280000c                 be      loc_F00A4FFC
F00A4FD0: d0243ff8                 st      %o0, [%l0-8]
F00A4FD4: 92042004                 add     %l0, 4, %o1
F00A4FD8: d0026004                 ld      [%o1+4], %o0
F00A4FDC: d0240000                 st      %o0, [%l0]
F00A4FE0: d0026008                 ld      [%o1+8], %o0
F00A4FE4: a0042008                 inc     8, %l0
F00A4FE8: d0224000                 st      %o0, [%o1]
F00A4FEC: d0040000                 ld      [%l0], %o0
F00A4FF0: 80a22000                 cmp     %o0, 0
F00A4FF4: 12bffff9                 bne     loc_F00A4FD8
F00A4FF8: 92026008                 inc     8, %o1
F00A4FFC: d0060000                 ld      [%i0], %o0
F00A5000: 1080003e                 ba      loc_F00A50F8
F00A5004: 90022001                 inc     %o0
F00A5008: 80a22000                 cmp     %o0, 0
F00A500C: 0280000d                 be      loc_F00A5040
F00A5010: 90068019                 add     %i2, %i1, %o0
F00A5014: d2042004                 ld      [%l0+4], %o1
F00A5018: 80a20009                 cmp     %o0, %o1
F00A501C: 2a80000a                 bcs,a   loc_F00A5044
F00A5020: d0060000                 ld      [%i0], %o0
F00A5024: 1880003e                 bgu     loc_F00A511C
F00A5028: 92224019                 sub     %o1, %i1, %o1
F00A502C: d0040000                 ld      [%l0], %o0
F00A5030: d2242004                 st      %o1, [%l0+4]
F00A5034: 90020019                 add     %o0, %i1, %o0
F00A5038: 10800031                 ba      loc_F00A50FC
F00A503C: d0240000                 st      %o0, [%l0]
F00A5040: d0060000                 ld      [%i0], %o0
F00A5044: 80a22000                 cmp     %o0, 0
F00A5048: 12800021                 bne     loc_F00A50CC
F00A504C: 92042004                 add     %l0, 4, %o1
F00A5050: d0040000                 ld      [%l0], %o0
F00A5054: 80a22000                 cmp     %o0, 0
F00A5058: 02800007                 be      loc_F00A5074
F00A505C: 98100010                 mov     %l0, %o4
F00A5060: 98032008                 inc     8, %o4
F00A5064: d0030000                 ld      [%o4], %o0
F00A5068: 80a22000                 cmp     %o0, 0
F00A506C: 32bffffe                 bne,a   loc_F00A5064
F00A5070: 98032008                 inc     8, %o4
F00A5074: d2033ff8                 ld      [%o4-8], %o1
F00A5078: d0033ff0                 ld      [%o4-0x10], %o0
F00A507C: 80a24008                 cmp     %o1, %o0
F00A5080: 04800003                 ble     loc_F00A508C
F00A5084: a0033ff8                 add     %o4, -8, %l0
F00A5088: a0033ff0                 add     %o4, -0x10, %l0
F00A508C: d4042004                 ld      [%l0+4], %o2
F00A5090: 113c0466                 sethi   %hi(aSRmapOverflowL), %o0! "%s: rmap overflow, lost [%d, %d)\n"
F00A5094: d6040000                 ld      [%l0], %o3
F00A5098: 90122090                 bset    %lo(aSRmapOverflowL), %o0! "%s: rmap overflow, lost [%d, %d)\n"
F00A509C: d2032004                 ld      [%o4+4], %o1
F00A50A0: 7ffdbd6e                 call    _printf
F00A50A4: 9602800b                 add     %o2, %o3, %o3
F00A50A8: d0042008                 ld      [%l0+8], %o0
F00A50AC: d204200c                 ld      [%l0+0xC], %o1
F00A50B0: d0240000                 st      %o0, [%l0]
F00A50B4: d2242004                 st      %o1, [%l0+4]
F00A50B8: c0242008                 clr     [%l0+8]
F00A50BC: d0060000                 ld      [%i0], %o0
F00A50C0: 90022001                 inc     %o0
F00A50C4: 10bfff9a                 ba      loc_F00A4F2C
F00A50C8: d0260000                 st      %o0, [%i0]
F00A50CC: d0024000                 ld      [%o1], %o0
F00A50D0: f4224000                 st      %i2, [%o1]
F00A50D4: b4100008                 mov     %o0, %i2
F00A50D8: d0040000                 ld      [%l0], %o0
F00A50DC: 92026008                 inc     8, %o1
F00A50E0: f2240000                 st      %i1, [%l0]
F00A50E4: b2920000                 orcc    %o0, %g0, %i1
F00A50E8: 12bffff9                 bne     loc_F00A50CC
F00A50EC: a0042008                 inc     8, %l0
F00A50F0: d0060000                 ld      [%i0], %o0
F00A50F4: 90023fff                 inc     -1, %o0
F00A50F8: d0260000                 st      %o0, [%i0]
F00A50FC: d0062004                 ld      [%i0+4], %o0
F00A5100: 80a22000                 cmp     %o0, 0
F00A5104: 02800009                 be      locret_F00A5128
F00A5108: 01000000                 nop
F00A510C: c0262004                 clr     [%i0+4]
F00A5110: 7ffdb736                 call    _wakeup
F00A5114: 90100018                 mov     %i0, %o0
F00A5118: 30800004                 ba,a    locret_F00A5128
F00A511C: 113c0466                 sethi   -0xFEE6800, %o0! char *
F00A5120: 7ffdc014                 call    _panic
F00A5124: 901220b8                 bset    0xB8, %o0
F00A5128: 81c7e008                 ret
F00A512C: 81e80000                 restore
