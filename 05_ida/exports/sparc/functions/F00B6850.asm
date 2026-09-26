F00B6850: 9de3bf98                 save    %sp, -0x68, %sp
F00B6854: a0100018                 mov     %i0, %l0
F00B6858: d05420b2                 ldsh    [%l0+0xB2], %o0
F00B685C: da04209c                 ld      [%l0+0x9C], %o5
F00B6860: d80420a0                 ld      [%l0+0xA0], %o4
F00B6864: c40c2044                 ldub    [%l0+0x44], %g2
F00B6868: f00c2045                 ldub    [%l0+0x45], %i0
F00B686C: e60c2041                 ldub    [%l0+0x41], %l3
F00B6870: 912a2002                 sll     %o0, 2, %o0
F00B6874: 90020010                 add     %o0, %l0, %o0
F00B6878: e20220b8                 ld      [%o0+0xB8], %l1
F00B687C: d6030000                 ld      [%o4], %o3
F00B6880: 808ae002                 btst    2, %o3
F00B6884: 0280000b                 be      loc_F00B68B0
F00B6888: e4146008                 lduh    [%l1+8], %l2
F00B688C: 90100010                 mov     %l0, %o0
F00B6890: 92102003                 mov     3, %o1
F00B6894: 153c047a                 sethi   %hi(aUnrecoverableD_1), %o2! "Unrecoverable DMA error during selectio"...
F00B6898: 400004d5                 call    _esplog
F00B689C: 9412a1a0                 bset    %lo(aUnrecoverableD_1), %o2! "Unrecoverable DMA error during selectio"...
F00B68A0: 90102003                 mov     3, %o0
F00B68A4: d02c6028                 stb     %o0, [%l1+0x28]
F00B68A8: 108000c1                 ba      locret_F00B6BAC
F00B68AC: b0102008                 mov     8, %i0
F00B68B0: d4032004                 ld      [%o4+4], %o2
F00B68B4: 9132e01c                 srl     %o3, 28, %o0
F00B68B8: d20420a4                 ld      [%l0+0xA4], %o1
F00B68BC: 80a22008                 cmp     %o0, 8
F00B68C0: d00b601c                 ldub    [%o5+0x1C], %o0
F00B68C4: 94228009                 sub     %o2, %o1, %o2
F00B68C8: 12800007                 bne     loc_F00B68E4
F00B68CC: 860a201f                 and     %o0, 0x1F, %g3
F00B68D0: 9132e00b                 srl     %o3, 11, %o0
F00B68D4: 928a2003                 andcc   %o0, 3, %o1
F00B68D8: 02800003                 be      loc_F00B68E4
F00B68DC: 9002bffc                 add     %o2, -4, %o0
F00B68E0: 94020009                 add     %o0, %o1, %o2
F00B68E4: 94228003                 sub     %o2, %g3, %o2
F00B68E8: d2030000                 ld      [%o4], %o1
F00B68EC: 80a2a010                 cmp     %o2, 0x10
F00B68F0: 113ffff7901220ff         set     -0x2301, %o0
F00B68F8: 92126020                 bset    0x20, %o1 ! ' '
F00B68FC: 920a4008                 and     %o1, %o0, %o1
F00B6900: 08800003                 bleu    loc_F00B690C
F00B6904: d2230000                 st      %o1, [%o4]
F00B6908: 94102000                 mov     0, %o2
F00B690C: 9008a0ff                 and     %g2, 0xFF, %o0
F00B6910: 80a22020                 cmp     %o0, 0x20 ! ' '
F00B6914: 1280002c                 bne     loc_F00B69C4
F00B6918: 80a2200c                 cmp     %o0, 0xC
F00B691C: 400002cf                 call    _esp_chip_disconnect
F00B6920: 90100010                 mov     %l0, %o0
F00B6924: 80a62000                 cmp     %i0, 0
F00B6928: 02800021                 be      loc_F00B69AC
F00B692C: 90102001                 mov     1, %o0
F00B6930: d00c207b                 ldub    [%l0+0x7B], %o0
F00B6934: 913a0012                 sra     %o0, %l2, %o0
F00B6938: 808a2001                 btst    1, %o0
F00B693C: 0280001b                 be      loc_F00B69A8
F00B6940: 900ce0ff                 and     %l3, 0xFF, %o0
F00B6944: 80a22060                 cmp     %o0, 0x60 ! '`'
F00B6948: 02800004                 be      loc_F00B6958
F00B694C: 80a22040                 cmp     %o0, 0x40 ! '@'
F00B6950: 32800017                 bne,a   loc_F00B69AC
F00B6954: 90102001                 mov     1, %o0
F00B6958: 80a22060                 cmp     %o0, 0x60 ! '`'
F00B695C: 3280000b                 bne,a   loc_F00B6988
F00B6960: d014605c                 lduh    [%l1+0x5C], %o0
F00B6964: d20c204c                 ldub    [%l0+0x4C], %o1
F00B6968: 80a26001                 cmp     %o1, 1
F00B696C: 32800007                 bne,a   loc_F00B6988
F00B6970: d014605c                 lduh    [%l1+0x5C], %o0
F00B6974: d00c2078                 ldub    [%l0+0x78], %o0
F00B6978: 932a4012                 sll     %o1, %l2, %o1
F00B697C: 90120009                 bset    %o1, %o0
F00B6980: d02c2078                 stb     %o0, [%l0+0x78]
F00B6984: d014605c                 lduh    [%l1+0x5C], %o0
F00B6988: 808a2100                 btst    0x100, %o0
F00B698C: 12800008                 bne     loc_F00B69AC
F00B6990: 90102001                 mov     1, %o0
F00B6994: d00c2041                 ldub    [%l0+0x41], %o0
F00B6998: b0102005                 mov     5, %i0
F00B699C: d02c2042                 stb     %o0, [%l0+0x42]
F00B69A0: 10800083                 ba      locret_F00B6BAC
F00B69A4: c02c2041                 clrb    [%l0+0x41]
F00B69A8: 90102001                 mov     1, %o0
F00B69AC: d02c6028                 stb     %o0, [%l1+0x28]
F00B69B0: d00c6029                 ldub    [%l1+0x29], %o0
F00B69B4: b0102003                 mov     3, %i0
F00B69B8: 90122001                 bset    1, %o0
F00B69BC: 1080007c                 ba      locret_F00B6BAC
F00B69C0: d02c6029                 stb     %o0, [%l1+0x29]
F00B69C4: 12800018                 bne     loc_F00B6A24
F00B69C8: 80a22018                 cmp     %o0, 0x18
F00B69CC: 113c047c                 sethi   %hi(_scsi_options), %o0
F00B69D0: d0022158                 ld      [%o0+%lo(_scsi_options)], %o0
F00B69D4: 808a2040                 btst    0x40, %o0 ! '@'
F00B69D8: 02800008                 be      loc_F00B69F8
F00B69DC: b0102001                 mov     1, %i0
F00B69E0: d0046014                 ld      [%l1+0x14], %o0
F00B69E4: 808a2008                 btst    8, %o0
F00B69E8: 22800005                 be,a    loc_F00B69FC
F00B69EC: d00c2041                 ldub    [%l0+0x41], %o0
F00B69F0: d00c2032                 ldub    [%l0+0x32], %o0
F00B69F4: d02b6020                 stb     %o0, [%o5+0x20]
F00B69F8: d00c2041                 ldub    [%l0+0x41], %o0
F00B69FC: 92103fff                 mov     -1, %o1
F00B6A00: d02c2042                 stb     %o0, [%l0+0x42]
F00B6A04: d01420b2                 lduh    [%l0+0xB2], %o0
F00B6A08: c02c2041                 clrb    [%l0+0x41]
F00B6A0C: d03420b0                 sth     %o0, [%l0+0xB0]
F00B6A10: d004208c                 ld      [%l0+0x8C], %o0
F00B6A14: d23420b2                 sth     %o1, [%l0+0xB2]
F00B6A18: 90022001                 inc     %o0
F00B6A1C: 10800064                 ba      locret_F00B6BAC
F00B6A20: d024208c                 st      %o0, [%l0+0x8C]
F00B6A24: 0280000a                 be      loc_F00B6A4C
F00B6A28: 90100010                 mov     %l0, %o0
F00B6A2C: 92102003                 mov     3, %o1
F00B6A30: 153c047a                 sethi   %hi(aUndeterminedSe), %o2! "undetermined selection failure"
F00B6A34: 4000046e                 call    _esplog
F00B6A38: 9412a1d0                 bset    %lo(aUndeterminedSe), %o2! "undetermined selection failure"
F00B6A3C: 400004aa                 call    _esp_stat_int_print
F00B6A40: 90100010                 mov     %l0, %o0
F00B6A44: 1080005a                 ba      locret_F00B6BAC
F00B6A48: b0102008                 mov     8, %i0
F00B6A4C: 960e20ff                 and     %i0, 0xFF, %o3
F00B6A50: 80a2e007                 cmp     %o3, 7! switch 8 cases
F00B6A54: 90102001                 mov     1, %o0
F00B6A58: d20c207b                 ldub    [%l0+0x7B], %o1
F00B6A5C: 912a0012                 sll     %o0, %l2, %o0
F00B6A60: 92124008                 bset    %o0, %o1
F00B6A64: 18800022                 bgu     def_F00B6A7C! jumptable F00B6A7C default case
F00B6A68: d22c207b                 stb     %o1, [%l0+0x7B]
F00B6A6C: 113c02da90122284         set     jpt_F00B6A7C, %o0
F00B6A74: 932ae002                 sll     %o3, 2, %o1
F00B6A78: d0024008                 ld      [%o1+%o0], %o0
F00B6A7C: 81c20000                 jmp     %o0! switch jump
F00B6A80: 01000000                 nop
F00B6AA4: 1080001a                 ba      loc_F00B6B0C! jumptable F00B6A7C cases 0-2
F00B6AA8: 94102000                 mov     0, %o2
F00B6AAC: 80a4e020                 cmp     %l3, 0x20 ! ' '! jumptable F00B6A7C cases 3,4
F00B6AB0: 22800017                 be,a    loc_F00B6B0C
F00B6AB4: 9402bfff                 inc     -1, %o2
F00B6AB8: 10800016                 ba      loc_F00B6B10
F00B6ABC: 80a0e000                 cmp     %g3, 0
F00B6AC0: d00c2031                 ldub    [%l0+0x31], %o0! jumptable F00B6A7C cases 5-7
F00B6AC4: 80a22004                 cmp     %o0, 4
F00B6AC8: 02800004                 be      loc_F00B6AD8
F00B6ACC: 80a22001                 cmp     %o0, 1
F00B6AD0: 12800008                 bne     loc_F00B6AF0
F00B6AD4: 90100010                 mov     %l0, %o0
F00B6AD8: 133c0478                 sethi   %hi(_esp_step567), %o1
F00B6ADC: d0026198                 ld      [%o1+%lo(_esp_step567)], %o0
F00B6AE0: 90022001                 inc     %o0
F00B6AE4: 10bffff2                 ba      loc_F00B6AAC! jumptable F00B6A7C cases 3,4
F00B6AE8: d0226198                 st      %o0, [%o1+%lo(_esp_step567)]
F00B6AEC: 90100010                 mov     %l0, %o0! jumptable F00B6A7C default case
F00B6AF0: 92102003                 mov     3, %o1
F00B6AF4: 153c047a9412a1f0         set     aBadSequenceSte, %o2! "bad sequence step (0x%x) in selection"
F00B6AFC: 4000043c                 call    _esplog
F00B6B00: 96100018                 mov     %i0, %o3
F00B6B04: 1080002a                 ba      locret_F00B6BAC
F00B6B08: b0102008                 mov     8, %i0
F00B6B0C: 80a0e000                 cmp     %g3, 0
F00B6B10: 0280000e                 be      loc_F00B6B48
F00B6B14: c02b600c                 clrb    [%o5+0xC]
F00B6B18: d00c2043                 ldub    [%l0+0x43], %o0
F00B6B1C: 900a2007                 and     %o0, 7, %o0
F00B6B20: 80a22001                 cmp     %o0, 1
F00B6B24: 12800008                 bne     loc_F00B6B44
F00B6B28: 90102001                 mov     1, %o0
F00B6B2C: 90040012                 add     %l0, %l2, %o0
F00B6B30: d00a205e                 ldub    [%o0+0x5E], %o0
F00B6B34: 80a22000                 cmp     %o0, 0
F00B6B38: 32800005                 bne,a   loc_F00B6B4C
F00B6B3C: d00c6029                 ldub    [%l1+0x29], %o0
F00B6B40: 90102001                 mov     1, %o0
F00B6B44: d02b600c                 stb     %o0, [%o5+0xC]
F00B6B48: d00c6029                 ldub    [%l1+0x29], %o0
F00B6B4C: 80a2a000                 cmp     %o2, 0
F00B6B50: 90122003                 bset    3, %o0
F00B6B54: 04800007                 ble     loc_F00B6B70
F00B6B58: d02c6029                 stb     %o0, [%l1+0x29]
F00B6B5C: 92122004                 or      %o0, 4, %o1
F00B6B60: d004602c                 ld      [%l1+0x2C], %o0
F00B6B64: d22c6029                 stb     %o1, [%l1+0x29]
F00B6B68: 9002000a                 add     %o0, %o2, %o0
F00B6B6C: d024602c                 st      %o0, [%l1+0x2C]
F00B6B70: d0046034                 ld      [%l1+0x34], %o0
F00B6B74: d2046038                 ld      [%l1+0x38], %o1
F00B6B78: 80a20009                 cmp     %o0, %o1
F00B6B7C: 22800008                 be,a    loc_F00B6B9C
F00B6B80: d00c2041                 ldub    [%l0+0x41], %o0
F00B6B84: d2246034                 st      %o1, [%l1+0x34]
F00B6B88: d014605c                 lduh    [%l1+0x5C], %o0
F00B6B8C: 13000004                 sethi   0x1000, %o1
F00B6B90: 90120009                 bset    %o1, %o0
F00B6B94: d034605c                 sth     %o0, [%l1+0x5C]
F00B6B98: d00c2041                 ldub    [%l0+0x41], %o0
F00B6B9C: b0102002                 mov     2, %i0
F00B6BA0: d02c2042                 stb     %o0, [%l0+0x42]
F00B6BA4: 9010201a                 mov     0x1A, %o0
F00B6BA8: d02c2041                 stb     %o0, [%l0+0x41]
F00B6BAC: 81c7e008                 ret
F00B6BB0: 81e80000                 restore
