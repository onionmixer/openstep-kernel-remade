F00B7908: 9de3bf98                 save    %sp, -0x68, %sp
F00B790C: e206209c                 ld      [%i0+0x9C], %l1
F00B7910: 808e6002                 btst    2, %i1
F00B7914: 0280003f                 be      loc_F00B7A10
F00B7918: e00620a0                 ld      [%i0+0xA0], %l0
F00B791C: 808e6020                 btst    0x20, %i1 ! ' '
F00B7920: 02800005                 be      loc_F00B7934
F00B7924: 90100018                 mov     %i0, %o0
F00B7928: 133c047b                 sethi   %hi(aResettingDmaEn), %o1! "resetting DMA engine\n"
F00B792C: 400000d8                 call    _eprintf
F00B7930: 92126048                 bset    %lo(aResettingDmaEn), %o1! "resetting DMA engine\n"
F00B7934: d0040000                 ld      [%l0], %o0
F00B7938: 920a3f7f                 and     %o0, -0x81, %o1
F00B793C: 9132601c                 srl     %o1, 28, %o0
F00B7940: 80a22009                 cmp     %o0, 9
F00B7944: 0280002a                 be      loc_F00B79EC
F00B7948: d2240000                 st      %o1, [%l0]
F00B794C: 80a22009                 cmp     %o0, 9
F00B7950: 18800006                 bgu     loc_F00B7968
F00B7954: 80a22004                 cmp     %o0, 4
F00B7958: 22800009                 be,a    loc_F00B797C
F00B795C: d00e207c                 ldub    [%i0+0x7C], %o0
F00B7960: 1080002a                 ba      loc_F00B7A08
F00B7964: d0040000                 ld      [%l0], %o0
F00B7968: 80a2200a                 cmp     %o0, 0xA
F00B796C: 2280000c                 be,a    loc_F00B799C
F00B7970: d00e2031                 ldub    [%i0+0x31], %o0
F00B7974: 10800025                 ba      loc_F00B7A08
F00B7978: d0040000                 ld      [%l0], %o0
F00B797C: 808a2020                 btst    0x20, %o0 ! ' '
F00B7980: 32800005                 bne,a   loc_F00B7994
F00B7984: d0040000                 ld      [%l0], %o0
F00B7988: 90126800                 or      %o1, 0x800, %o0
F00B798C: d0240000                 st      %o0, [%l0]
F00B7990: d0040000                 ld      [%l0], %o0
F00B7994: 1080001a                 ba      loc_F00B79FC
F00B7998: 13000100                 sethi   0x40000, %o1
F00B799C: 90023ffc                 inc     -4, %o0
F00B79A0: 900a20ff                 and     %o0, 0xFF, %o0
F00B79A4: 80a22001                 cmp     %o0, 1
F00B79A8: 18800007                 bgu     loc_F00B79C4
F00B79AC: 113fefff                 sethi   -0x400400, %o0
F00B79B0: 901223ff                 bset    0x3FF, %o0
F00B79B4: 900a4008                 and     %o1, %o0, %o0
F00B79B8: 13000800                 sethi   0x200000, %o1
F00B79BC: 90120009                 bset    %o1, %o0
F00B79C0: d0240000                 st      %o0, [%l0]
F00B79C4: d00e207c                 ldub    [%i0+0x7C], %o0
F00B79C8: 808a2020                 btst    0x20, %o0 ! ' '
F00B79CC: 0280000e                 be      loc_F00B7A04
F00B79D0: 13000300                 sethi   0xC0000, %o1
F00B79D4: d0040000                 ld      [%l0], %o0
F00B79D8: 922a0009                 andn    %o0, %o1, %o1
F00B79DC: 11000100                 sethi   0x40000, %o0
F00B79E0: 92124008                 bset    %o0, %o1
F00B79E4: 10800008                 ba      loc_F00B7A04
F00B79E8: d2240000                 st      %o1, [%l0]
F00B79EC: d00e2031                 ldub    [%i0+0x31], %o0
F00B79F0: 80a22000                 cmp     %o0, 0
F00B79F4: 02800004                 be      loc_F00B7A04
F00B79F8: 11001000                 sethi   0x400000, %o0
F00B79FC: 90124008                 bset    %o1, %o0
F00B7A00: d0240000                 st      %o0, [%l0]
F00B7A04: d0040000                 ld      [%l0], %o0
F00B7A08: 90122010                 bset    0x10, %o0
F00B7A0C: d0240000                 st      %o0, [%l0]
F00B7A10: 808e6001                 btst    1, %i1
F00B7A14: 02800056                 be      def_F00B7AA8! jumptable F00B7AA8 default case, case 4
F00B7A18: 808e6020                 btst    0x20, %i1 ! ' '
F00B7A1C: 02800005                 be      loc_F00B7A30
F00B7A20: 90100018                 mov     %i0, %o0
F00B7A24: 133c047b                 sethi   %hi(aResettingEspCh), %o1! "resetting ESP chip\n"
F00B7A28: 40000099                 call    _eprintf
F00B7A2C: 92126060                 bset    %lo(aResettingEspCh), %o1! "resetting ESP chip\n"
F00B7A30: 90102080                 mov     0x80, %o0
F00B7A34: d02c600c                 stb     %o0, [%l1+0xC]
F00B7A38: d00e203d                 ldub    [%i0+0x3D], %o0
F00B7A3C: 900a2007                 and     %o0, 7, %o0
F00B7A40: d02c6024                 stb     %o0, [%l1+0x24]
F00B7A44: d00e2040                 ldub    [%i0+0x40], %o0
F00B7A48: d02c6014                 stb     %o0, [%l1+0x14]
F00B7A4C: c02c6018                 clrb    [%l1+0x18]
F00B7A50: c02c601c                 clrb    [%l1+0x1C]
F00B7A54: d00e2032                 ldub    [%i0+0x32], %o0
F00B7A58: d02c6020                 stb     %o0, [%l1+0x20]
F00B7A5C: d00e2031                 ldub    [%i0+0x31], %o0
F00B7A60: 80a22005                 cmp     %o0, 5
F00B7A64: 3280000b                 bne,a   loc_F00B7A90
F00B7A68: 92023fff                 add     %o0, -1, %o1
F00B7A6C: d00c6038                 ldub    [%l1+0x38], %o0
F00B7A70: 91322003                 srl     %o0, 3, %o0
F00B7A74: 80a22002                 cmp     %o0, 2
F00B7A78: 12800003                 bne     loc_F00B7A84
F00B7A7C: 90102004                 mov     4, %o0
F00B7A80: 90102003                 mov     3, %o0
F00B7A84: d02e2031                 stb     %o0, [%i0+0x31]
F00B7A88: d00e2031                 ldub    [%i0+0x31], %o0
F00B7A8C: 92023fff                 add     %o0, -1, %o1
F00B7A90: 80a26004                 cmp     %o1, 4! switch 5 cases
F00B7A94: 18800036                 bgu     def_F00B7AA8! jumptable F00B7AA8 default case, case 4
F00B7A98: 113c02de                 sethi   %hi(jpt_F00B7AA8), %o0
F00B7A9C: 901222b0                 bset    %lo(jpt_F00B7AA8), %o0
F00B7AA0: 932a6002                 sll     %o1, 2, %o1
F00B7AA4: d0024008                 ld      [%o1+%o0], %o0
F00B7AA8: 81c20000                 jmp     %o0! switch jump
F00B7AAC: 01000000                 nop
F00B7AC4: d00e2033                 ldub    [%i0+0x33], %o0! jumptable F00B7AA8 case 1
F00B7AC8: d02c602c                 stb     %o0, [%l1+0x2C]
F00B7ACC: d00e2034                 ldub    [%i0+0x34], %o0
F00B7AD0: 10800027                 ba      def_F00B7AA8! jumptable F00B7AA8 default case, case 4
F00B7AD4: d02c6030                 stb     %o0, [%l1+0x30]
F00B7AD8: 96102000                 mov     0, %o3! jumptable F00B7AA8 case 2
F00B7ADC: 940ae0ff                 and     %o3, 0xFF, %o2
F00B7AE0: 9602e001                 inc     %o3
F00B7AE4: 9406000a                 add     %i0, %o2, %o2
F00B7AE8: d20aa034                 ldub    [%o2+0x34], %o1
F00B7AEC: 900ae0ff                 and     %o3, 0xFF, %o0
F00B7AF0: 80a22007                 cmp     %o0, 7
F00B7AF4: 92126008                 bset    8, %o1
F00B7AF8: 08bffff9                 bleu    loc_F00B7ADC
F00B7AFC: d22aa034                 stb     %o1, [%o2+0x34]
F00B7B00: d00e2033                 ldub    [%i0+0x33], %o0
F00B7B04: d02c602c                 stb     %o0, [%l1+0x2C]
F00B7B08: d00e203c                 ldub    [%i0+0x3C], %o0
F00B7B0C: 80a22000                 cmp     %o0, 0
F00B7B10: 02800004                 be      loc_F00B7B20
F00B7B14: 90102060                 mov     0x60, %o0 ! '`'
F00B7B18: 10800015                 ba      def_F00B7AA8! jumptable F00B7AA8 default case, case 4
F00B7B1C: c02e2077                 clrb    [%i0+0x77]
F00B7B20: 10800013                 ba      def_F00B7AA8! jumptable F00B7AA8 default case, case 4
F00B7B24: d02e2077                 stb     %o0, [%i0+0x77]
F00B7B28: 96102000                 mov     0, %o3! jumptable F00B7AA8 case 3
F00B7B2C: 940ae0ff                 and     %o3, 0xFF, %o2
F00B7B30: 9602e001                 inc     %o3
F00B7B34: 9406000a                 add     %i0, %o2, %o2
F00B7B38: d20aa034                 ldub    [%o2+0x34], %o1
F00B7B3C: 900ae0ff                 and     %o3, 0xFF, %o0
F00B7B40: 80a22007                 cmp     %o0, 7
F00B7B44: 92126001                 bset    1, %o1
F00B7B48: 08bffff9                 bleu    loc_F00B7B2C
F00B7B4C: d22aa034                 stb     %o1, [%o2+0x34]
F00B7B50: d00e2033                 ldub    [%i0+0x33], %o0
F00B7B54: d02c602c                 stb     %o0, [%l1+0x2C]
F00B7B58: 90102020                 mov     0x20, %o0 ! ' '
F00B7B5C: 10800004                 ba      def_F00B7AA8! jumptable F00B7AA8 default case, case 4
F00B7B60: d02e2077                 stb     %o0, [%i0+0x77]
F00B7B64: d00e2033                 ldub    [%i0+0x33], %o0! jumptable F00B7AA8 case 0
F00B7B68: d02c602c                 stb     %o0, [%l1+0x2C]
F00B7B6C: 808e600c                 btst    0xC, %i1! jumptable F00B7AA8 default case, case 4
F00B7B70: 0280001d                 be      locret_F00B7BE4
F00B7B74: 808e6020                 btst    0x20, %i1 ! ' '
F00B7B78: 0280000c                 be      loc_F00B7BA8
F00B7B7C: 808e6008                 btst    8, %i1
F00B7B80: 113c047b                 sethi   %hi(aResettingScsiB), %o0! "resetting SCSI bus (%s)\n"
F00B7B84: 02800005                 be      loc_F00B7B98
F00B7B88: 92122078                 or      %o0, %lo(aResettingScsiB), %o1! "resetting SCSI bus (%s)\n"
F00B7B8C: 113c047b                 sethi   %hi(aIgnored), %o0! "ignored"
F00B7B90: 10800004                 ba      loc_F00B7BA0
F00B7B94: 94122098                 or      %o0, %lo(aIgnored), %o2! "ignored"
F00B7B98: 113c047b941220a0         set     aNotIgnored, %o2! "not ignored"
F00B7BA0: 4000003b                 call    _eprintf
F00B7BA4: 90100018                 mov     %i0, %o0
F00B7BA8: 808e6008                 btst    8, %i1
F00B7BAC: 2280000a                 be,a    loc_F00B7BD4
F00B7BB0: 90102003                 mov     3, %o0
F00B7BB4: d00e2032                 ldub    [%i0+0x32], %o0
F00B7BB8: 90122040                 bset    0x40, %o0 ! '@'
F00B7BBC: d02c6020                 stb     %o0, [%l1+0x20]
F00B7BC0: 90102003                 mov     3, %o0
F00B7BC4: d02c600c                 stb     %o0, [%l1+0xC]
F00B7BC8: d00e2032                 ldub    [%i0+0x32], %o0
F00B7BCC: 10800003                 ba      loc_F00B7BD8
F00B7BD0: d02c6020                 stb     %o0, [%l1+0x20]
F00B7BD4: d02c600c                 stb     %o0, [%l1+0xC]
F00B7BD8: 113c047c                 sethi   %hi(_scsi_reset_delay), %o0
F00B7BDC: 7fff7f21                 call    _us_spin
F00B7BE0: d0022154                 ld      [%o0+%lo(_scsi_reset_delay)], %o0
F00B7BE4: 81c7e008                 ret
F00B7BE8: 81e80000                 restore
