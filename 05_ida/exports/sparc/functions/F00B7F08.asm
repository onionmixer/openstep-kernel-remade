F00B7F08: 9de3bf98                 save    %sp, -0x68, %sp
F00B7F0C: 113c047b                 sethi   %hi(aMappedDmaSpace), %o0! "\tMapped Dma Space:\n"
F00B7F10: 7ffd71d2                 call    _printf
F00B7F14: 90122230                 bset    %lo(aMappedDmaSpace), %o0! "\tMapped Dma Space:\n"
F00B7F18: a086203c                 addcc   %i0, 0x3C, %l0 ! '<'
F00B7F1C: 0280000c                 be      loc_F00B7F4C
F00B7F20: 113c047b                 sethi   -0xFEE1400, %o0! char *
F00B7F24: 233c047b                 sethi   -0xFEE1400, %l1
F00B7F28: d2040000                 ld      [%l0], %o1
F00B7F2C: d4042004                 ld      [%l0+4], %o2
F00B7F30: 7ffd71ca                 call    _printf
F00B7F34: 90146248                 or      %l1, 0x248, %o0
F00B7F38: e0042008                 ld      [%l0+8], %l0
F00B7F3C: 80a42000                 cmp     %l0, 0
F00B7F40: 32bffffb                 bne,a   loc_F00B7F2C
F00B7F44: d2040000                 ld      [%l0], %o1
F00B7F48: 113c047b                 sethi   -0xFEE1400, %o0! char *
F00B7F4C: 7ffd71c3                 call    _printf
F00B7F50: 90122268                 bset    0x268, %o0! char *
F00B7F54: a0862048                 addcc   %i0, 0x48, %l0 ! 'H'
F00B7F58: 0280000a                 be      locret_F00B7F80
F00B7F5C: 233c047b                 sethi   -0xFEE1400, %l1
F00B7F60: d2040000                 ld      [%l0], %o1
F00B7F64: d4042004                 ld      [%l0+4], %o2
F00B7F68: 7ffd71bc                 call    _printf
F00B7F6C: 90146280                 or      %l1, 0x280, %o0
F00B7F70: e0042008                 ld      [%l0+8], %l0
F00B7F74: 80a42000                 cmp     %l0, 0
F00B7F78: 32bffffb                 bne,a   loc_F00B7F64
F00B7F7C: d2040000                 ld      [%l0], %o1
F00B7F80: 81c7e008                 ret
F00B7F84: 81e80000                 restore
