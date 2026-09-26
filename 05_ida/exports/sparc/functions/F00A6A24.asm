F00A6A24: 9de3bf90                 save    %sp, -0x70, %sp
F00A6A28: 80a6e000                 cmp     %i3, 0
F00A6A2C: 12800028                 bne     loc_F00A6ACC
F00A6A30: 113c046b                 sethi   -0xFEE5400, %o0
F00A6A34: 808e2001                 btst    1, %i0
F00A6A38: 02800008                 be      loc_F00A6A58
F00A6A3C: 113c0466                 sethi   %hi(_log_ce_error), %o0
F00A6A40: d0022154                 ld      [%o0+%lo(_log_ce_error)], %o0
F00A6A44: 80a22000                 cmp     %o0, 0
F00A6A48: 02800004                 be      loc_F00A6A58
F00A6A4C: 113c046b                 sethi   %hi(aSofterrorEccMe), %o0! "Softerror: ECC Memory Error Corrected."...
F00A6A50: 7ffdb702                 call    _printf
F00A6A54: 90122148                 bset    %lo(aSofterrorEccMe), %o0! "Softerror: ECC Memory Error Corrected."...
F00A6A58: 11000040                 sethi   0x10000, %o0
F00A6A5C: 808e0008                 btst    %o0, %i0
F00A6A60: 02800004                 be      loc_F00A6A70
F00A6A64: 113c046b                 sethi   %hi(aMultipleErrors_1), %o0! "\tMultiple errors.\n"
F00A6A68: 7ffdb6fc                 call    _printf
F00A6A6C: 90122170                 bset    %lo(aMultipleErrors_1), %o0! "\tMultiple errors.\n"
F00A6A70: 113c04f8                 sethi   %hi(_cpu), %o0
F00A6A74: d0022120                 ld      [%o0+%lo(_cpu)], %o0
F00A6A78: 80a22072                 cmp     %o0, 0x72 ! 'r'
F00A6A7C: 12800010                 bne     loc_F00A6ABC
F00A6A80: 808e2008                 btst    8, %i0
F00A6A84: 11000080                 sethi   0x20000, %o0
F00A6A88: 808e0008                 btst    %o0, %i0
F00A6A8C: 02800006                 be      loc_F00A6AA4
F00A6A90: 808e2002                 btst    2, %i0
F00A6A94: 113c046b                 sethi   %hi(aGraphicsError), %o0! "Graphics Error.\n"
F00A6A98: 7ffdb6f0                 call    _printf
F00A6A9C: 90122188                 bset    %lo(aGraphicsError), %o0! "Graphics Error.\n"
F00A6AA0: 808e2002                 btst    2, %i0
F00A6AA4: 02800006                 be      loc_F00A6ABC
F00A6AA8: 808e2008                 btst    8, %i0
F00A6AAC: 113c046b                 sethi   %hi(aMisreferencedS), %o0! "Misreferenced Slot Error.\n"
F00A6AB0: 7ffdb6ea                 call    _printf
F00A6AB4: 901221a0                 bset    %lo(aMisreferencedS), %o0! "Misreferenced Slot Error.\n"
F00A6AB8: 808e2008                 btst    8, %i0
F00A6ABC: 02800007                 be      loc_F00A6AD8
F00A6AC0: 113c046b                 sethi   %hi(aUncorrectableE), %o0! "Uncorrectable ECC Memory Error.\n"
F00A6AC4: 10800003                 ba      loc_F00A6AD0
F00A6AC8: 901221c0                 bset    %lo(aUncorrectableE), %o0! "Uncorrectable ECC Memory Error.\n"
F00A6ACC: 901221e8                 bset    0x1E8, %o0! char *
F00A6AD0: 7ffdb6e2                 call    _printf
F00A6AD4: 01000000                 nop
F00A6AD8: 40002268                 call    _prom_nextnode
F00A6ADC: 90102000                 mov     0, %o0
F00A6AE0: 133c046b92126210         set     aGetUnum, %o1! "get-unum"
F00A6AE8: 40002147                 call    _prom_getprop
F00A6AEC: 9407bff4                 add     %fp, var_C, %o2
F00A6AF0: d607bff4                 ld      [%fp+var_C], %o3
F00A6AF4: 80a2e000                 cmp     %o3, 0
F00A6AF8: 12800007                 bne     loc_F00A6B14
F00A6AFC: 80a6e000                 cmp     %i3, 0
F00A6B00: 113c046b                 sethi   %hi(aNoSimmDecodeFu), %o0! "no simm decode function available\n"
F00A6B04: 7ffdb6d5                 call    _printf
F00A6B08: 90122220                 bset    %lo(aNoSimmDecodeFu), %o0! "no simm decode function available\n"
F00A6B0C: 10800016                 ba      loc_F00A6B64
F00A6B10: 80a6e000                 cmp     %i3, 0
F00A6B14: 1280000b                 bne     loc_F00A6B40
F00A6B18: 80a6e000                 cmp     %i3, 0
F00A6B1C: 808e2001                 btst    1, %i0
F00A6B20: 02800007                 be      loc_F00A6B3C
F00A6B24: 90100018                 mov     %i0, %o0
F00A6B28: 92100019                 mov     %i1, %o1
F00A6B2C: 7fffff09                 call    _log_ce_mem_err
F00A6B30: 9410001a                 mov     %i2, %o2
F00A6B34: 1080000c                 ba      loc_F00A6B64
F00A6B38: 80a6e000                 cmp     %i3, 0
F00A6B3C: 80a6e000                 cmp     %i3, 0
F00A6B40: 12800005                 bne     loc_F00A6B54
F00A6B44: 90100019                 mov     %i1, %o0
F00A6B48: 808e2008                 btst    8, %i0
F00A6B4C: 02800006                 be      loc_F00A6B64
F00A6B50: 80a6e000                 cmp     %i3, 0
F00A6B54: d407bff4                 ld      [%fp+var_C], %o2
F00A6B58: 7fffffa4                 call    _log_ue_mem_err
F00A6B5C: 9210001a                 mov     %i2, %o1
F00A6B60: 80a6e000                 cmp     %i3, 0
F00A6B64: 1280000a                 bne     loc_F00A6B8C
F00A6B68: 113c046b                 sethi   -0xFEE5400, %o0
F00A6B6C: 808e2001                 btst    1, %i0
F00A6B70: 02800006                 be      loc_F00A6B88
F00A6B74: 113c0466                 sethi   %hi(_log_ce_error), %o0
F00A6B78: d0022154                 ld      [%o0+%lo(_log_ce_error)], %o0
F00A6B7C: 80a22000                 cmp     %o0, 0
F00A6B80: 02800007                 be      locret_F00A6B9C
F00A6B84: 01000000                 nop
F00A6B88: 113c046b                 sethi   -0xFEE5400, %o0
F00A6B8C: 90122248                 bset    0x248, %o0! char *
F00A6B90: 920e600f                 and     %i1, 0xF, %o1
F00A6B94: 7ffdb6b1                 call    _printf
F00A6B98: 9410001a                 mov     %i2, %o2
F00A6B9C: 81c7e008                 ret
F00A6BA0: 81e80000                 restore
