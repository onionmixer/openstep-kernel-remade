F0047E2C: 9de3bf98                 save    %sp, -0x68, %sp
F0047E30: e8062030                 ld      [%i0+0x30], %l4
F0047E34: 80a6a001                 cmp     %i2, 1
F0047E38: 08800005                 bleu    loc_F0047E4C
F0047E3C: e0152042                 lduh    [%l4+0x42], %l0
F0047E40: 113c0439                 sethi   %hi(aSpecRdwr), %o0! "spec_rdwr"
F0047E44: 7fff34cb                 call    _panic
F0047E48: 90122098                 bset    %lo(aSpecRdwr), %o0! "spec_rdwr"
F0047E4C: 80a6a000                 cmp     %i2, 0
F0047E50: 3280000c                 bne,a   loc_F0047E80
F0047E54: f0062028                 ld      [%i0+0x28], %i0
F0047E58: d0066014                 ld      [%i1+0x14], %o0
F0047E5C: 80a22000                 cmp     %o0, 0
F0047E60: 02800033                 be      loc_F0047F2C
F0047E64: 80a6a000                 cmp     %i2, 0
F0047E68: 32800006                 bne,a   loc_F0047E80
F0047E6C: f0062028                 ld      [%i0+0x28], %i0
F0047E70: 90100014                 mov     %l4, %o0
F0047E74: 7ffffed1                 call    _smark
F0047E78: 92102004                 mov     4, %o1
F0047E7C: f0062028                 ld      [%i0+0x28], %i0
F0047E80: 80a62004                 cmp     %i0, 4
F0047E84: 12800024                 bne     loc_F0047F14
F0047E88: 80a62003                 cmp     %i0, 3
F0047E8C: 80a6a000                 cmp     %i2, 0
F0047E90: 1280000f                 bne     loc_F0047ECC
F0047E94: 90100014                 mov     %l4, %o0
F0047E98: 952c2010                 sll     %l0, 16, %o2
F0047E9C: 913aa010                 sra     %o2, 16, %o0
F0047EA0: 9532a018                 srl     %o2, 24, %o2
F0047EA4: 932aa001                 sll     %o2, 1, %o1
F0047EA8: 9202400a                 add     %o1, %o2, %o1
F0047EAC: 932a6002                 sll     %o1, 2, %o1
F0047EB0: 9222400a                 sub     %o1, %o2, %o1
F0047EB4: 932a6002                 sll     %o1, 2, %o1
F0047EB8: 153c04729412a1f0         set     _cdevsw, %o2
F0047EC0: 9202400a                 add     %o1, %o2, %o1
F0047EC4: 10800010                 ba      loc_F0047F04
F0047EC8: d4026008                 ld      [%o1+8], %o2
F0047ECC: 7ffffebb                 call    _smark
F0047ED0: 92102042                 mov     0x42, %o1 ! 'B'
F0047ED4: 952c2010                 sll     %l0, 16, %o2
F0047ED8: 913aa010                 sra     %o2, 16, %o0
F0047EDC: 9532a018                 srl     %o2, 24, %o2
F0047EE0: 932aa001                 sll     %o2, 1, %o1
F0047EE4: 9202400a                 add     %o1, %o2, %o1
F0047EE8: 932a6002                 sll     %o1, 2, %o1
F0047EEC: 9222400a                 sub     %o1, %o2, %o1
F0047EF0: 932a6002                 sll     %o1, 2, %o1
F0047EF4: 153c04729412a1f0         set     _cdevsw, %o2
F0047EFC: 9202400a                 add     %o1, %o2, %o1
F0047F00: d402600c                 ld      [%o1+0xC], %o2
F0047F04: 9fc28000                 call    %o2
F0047F08: 92100019                 mov     %i1, %o1
F0047F0C: 1080008b                 ba      locret_F0048138
F0047F10: b0100008                 mov     %o0, %i0
F0047F14: 12800089                 bne     locret_F0048138
F0047F18: b010202d                 mov     0x2D, %i0 ! '-'
F0047F1C: d0066014                 ld      [%i1+0x14], %o0
F0047F20: 80a22000                 cmp     %o0, 0
F0047F24: 32800008                 bne,a   loc_F0047F44
F0047F28: ea05203c                 ld      [%l4+0x3C], %l5
F0047F2C: 10800083                 ba      locret_F0048138
F0047F30: b0102000                 mov     0, %i0
F0047F34: b0102005                 mov     5, %i0
F0047F38: 7fff724c                 call    _brelse
F0047F3C: 90100010                 mov     %l0, %o0
F0047F40: 3080007e                 ba,a    locret_F0048138
F0047F44: 25000008                 sethi   0x2000, %l2
F0047F48: e0066008                 ld      [%i1+8], %l0
F0047F4C: 92100012                 mov     %l2, %o1
F0047F50: 7ffef9ac                 call    _udiv
F0047F54: 90100010                 mov     %l0, %o0
F0047F58: b0100008                 mov     %o0, %i0
F0047F5C: 90100010                 mov     %l0, %o0
F0047F60: 7ffefa50                 call    _urem
F0047F64: 92100012                 mov     %l2, %o1
F0047F68: a6100008                 mov     %o0, %l3
F0047F6C: 11000008                 sethi   0x2000, %o0
F0047F70: d2066014                 ld      [%i1+0x14], %o1
F0047F74: a2220013                 sub     %o0, %l3, %l1
F0047F78: 80a44009                 cmp     %l1, %o1
F0047F7C: 34800002                 bg,a    loc_F0047F84
F0047F80: a2100009                 mov     %o1, %l1
F0047F84: d2052048                 ld      [%l4+0x48], %o1
F0047F88: 7ffef99e                 call    _udiv
F0047F8C: 90100012                 mov     %l2, %o0
F0047F90: a0100008                 mov     %o0, %l0
F0047F94: 90100018                 mov     %i0, %o0
F0047F98: 7ffef95a                 call    _umul
F0047F9C: 92100010                 mov     %l0, %o1
F0047FA0: 92100008                 mov     %o0, %o1! size_t
F0047FA4: 96024010                 add     %o1, %l0, %o3
F0047FA8: 113c04eb                 sethi   %hi(_rablock), %o0
F0047FAC: d6222170                 st      %o3, [%o0+%lo(_rablock)]
F0047FB0: 113c04eb                 sethi   %hi(_rasize), %o0
F0047FB4: 80a6a000                 cmp     %i2, 0
F0047FB8: 1280001b                 bne     loc_F0048024
F0047FBC: e4222178                 st      %l2, [%o0+%lo(_rasize)]
F0047FC0: 80a26000                 cmp     %o1, 0
F0047FC4: 3680000a                 bge,a   loc_F0047FEC
F0047FC8: d0052044                 ld      [%l4+0x44], %o0
F0047FCC: 7fff731f                 call    _geteblk
F0047FD0: 90100012                 mov     %l2, %o0
F0047FD4: a0100008                 mov     %o0, %l0
F0047FD8: d0042020                 ld      [%l0+0x20], %o0! void *
F0047FDC: 4001339f                 call    _bzero
F0047FE0: d2042014                 ld      [%l0+0x14], %o1
F0047FE4: 1080000e                 ba      loc_F004801C
F0047FE8: c0242028                 clr     [%l0+0x28]
F0047FEC: 90022001                 inc     %o0
F0047FF0: 80a20018                 cmp     %o0, %i0
F0047FF4: 12800007                 bne     loc_F0048010
F0047FF8: 90100015                 mov     %l5, %o0
F0047FFC: 94100012                 mov     %l2, %o2
F0048000: 7fff7176                 call    _breada
F0048004: 98100012                 mov     %l2, %o4
F0048008: 10800005                 ba      loc_F004801C
F004800C: a0100008                 mov     %o0, %l0
F0048010: 7fff7144                 call    _bread
F0048014: 94100012                 mov     %l2, %o2
F0048018: a0100008                 mov     %o0, %l0
F004801C: 1080000c                 ba      loc_F004804C
F0048020: f0252044                 st      %i0, [%l4+0x44]
F0048024: 80a44012                 cmp     %l1, %l2
F0048028: 12800006                 bne     loc_F0048040
F004802C: 90100015                 mov     %l5, %o0
F0048030: 7fff728e                 call    _getblk
F0048034: 94100011                 mov     %l1, %o2
F0048038: 10800005                 ba      loc_F004804C
F004803C: a0100008                 mov     %o0, %l0
F0048040: 7fff7138                 call    _bread
F0048044: 94100012                 mov     %l2, %o2
F0048048: a0100008                 mov     %o0, %l0
F004804C: d2042014                 ld      [%l0+0x14], %o1
F0048050: d0042028                 ld      [%l0+0x28], %o0
F0048054: 92224008                 sub     %o1, %o0, %o1
F0048058: 80a44009                 cmp     %l1, %o1
F004805C: 34800002                 bg,a    loc_F0048064
F0048060: a2100009                 mov     %o1, %l1
F0048064: d0040000                 ld      [%l0], %o0
F0048068: 808a2004                 btst    4, %o0
F004806C: 12bfffb2                 bne     loc_F0047F34
F0048070: 92100011                 mov     %l1, %o1
F0048074: 9410001a                 mov     %i2, %o2
F0048078: d0042020                 ld      [%l0+0x20], %o0
F004807C: 96100019                 mov     %i1, %o3
F0048080: 7fff28a6                 call    _uiomove
F0048084: 90020013                 add     %o0, %l3, %o0
F0048088: 80a6a000                 cmp     %i2, 0
F004808C: 1280000d                 bne     loc_F00480C0
F0048090: b0100008                 mov     %o0, %i0
F0048094: 90044013                 add     %l1, %l3, %o0
F0048098: 80a20012                 cmp     %o0, %l2
F004809C: 12800005                 bne     loc_F00480B0
F00480A0: 01000000                 nop
F00480A4: d0040000                 ld      [%l0], %o0
F00480A8: 90122080                 bset    0x80, %o0
F00480AC: d0240000                 st      %o0, [%l0]
F00480B0: 7fff71ee                 call    _brelse
F00480B4: 90100010                 mov     %l0, %o0
F00480B8: 10800018                 ba      loc_F0048118
F00480BC: 80a62000                 cmp     %i0, 0
F00480C0: 808ee004                 btst    4, %i3
F00480C4: 02800006                 be      loc_F00480DC
F00480C8: 90044013                 add     %l1, %l3, %o0
F00480CC: 7fff71a7                 call    _bwrite
F00480D0: 90100010                 mov     %l0, %o0
F00480D4: 1080000e                 ba      loc_F004810C
F00480D8: 90100014                 mov     %l4, %o0
F00480DC: 80a20012                 cmp     %o0, %l2
F00480E0: 12800008                 bne     loc_F0048100
F00480E4: 90100010                 mov     %l0, %o0
F00480E8: d2040000                 ld      [%l0], %o1
F00480EC: 92126080                 bset    0x80, %o1
F00480F0: 7fff71d6                 call    _bawrite
F00480F4: d2220000                 st      %o1, [%o0]
F00480F8: 10800005                 ba      loc_F004810C
F00480FC: 90100014                 mov     %l4, %o0
F0048100: 7fff71c1                 call    _bdwrite
F0048104: 90100010                 mov     %l0, %o0
F0048108: 90100014                 mov     %l4, %o0
F004810C: 7ffffe2b                 call    _smark
F0048110: 92102042                 mov     0x42, %o1 ! 'B'
F0048114: 80a62000                 cmp     %i0, 0
F0048118: 12800008                 bne     locret_F0048138
F004811C: 01000000                 nop
F0048120: d0066014                 ld      [%i1+0x14], %o0
F0048124: 80a22000                 cmp     %o0, 0
F0048128: 04800004                 ble     locret_F0048138
F004812C: 80a46000                 cmp     %l1, 0
F0048130: 32bfff87                 bne,a   loc_F0047F4C
F0048134: e0066008                 ld      [%i1+8], %l0
F0048138: 81c7e008                 ret
F004813C: 81e80000                 restore
