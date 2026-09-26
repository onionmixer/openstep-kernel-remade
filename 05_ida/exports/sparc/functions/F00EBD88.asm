F00EBD88: 9de3bf90                 save    %sp, -0x70, %sp
F00EBD8C: 80a62000                 cmp     %i0, 0
F00EBD90: 2280002b                 be,a    locret_F00EBE3C
F00EBD94: b0102000                 mov     0, %i0
F00EBD98: 253c0504                 sethi   -0xFEBF000, %l2
F00EBD9C: d0060000                 ld      [%i0], %o0
F00EBDA0: d002200c                 ld      [%o0+0xC], %o0
F00EBDA4: 80a22002                 cmp     %o0, 2
F00EBDA8: 24800021                 ble,a   loc_F00EBE2C
F00EBDAC: f0062004                 ld      [%i0+4], %i0
F00EBDB0: e2062024                 ld      [%i0+0x24], %l1
F00EBDB4: 80a46000                 cmp     %l1, 0
F00EBDB8: 2280001d                 be,a    loc_F00EBE2C
F00EBDBC: f0062004                 ld      [%i0+4], %i0
F00EBDC0: 1080000d                 ba      loc_F00EBDF4
F00EBDC4: a0102000                 mov     0, %l0
F00EBDC8: 90020011                 add     %o0, %l1, %o0
F00EBDCC: d0022008                 ld      [%o0+8], %o0! id
F00EBDD0: d204a018                 ld      [%l2+0x18], %o1! SEL
F00EBDD4: 400016a7                 call    _objc_msgSend
F00EBDD8: 9410001a                 mov     %i2, %o2
F00EBDDC: 912a2018                 sll     %o0, 24, %o0
F00EBDE0: 80a22000                 cmp     %o0, 0
F00EBDE4: 02800004                 be      loc_F00EBDF4
F00EBDE8: a0042001                 inc     %l0
F00EBDEC: 10800014                 ba      locret_F00EBE3C
F00EBDF0: b0102001                 mov     1, %i0
F00EBDF4: d0046004                 ld      [%l1+4], %o0
F00EBDF8: 80a40008                 cmp     %l0, %o0
F00EBDFC: 06bffff3                 bl      loc_F00EBDC8
F00EBE00: 912c2002                 sll     %l0, 2, %o0
F00EBE04: d0060000                 ld      [%i0], %o0
F00EBE08: d002200c                 ld      [%o0+0xC], %o0
F00EBE0C: 80a22004                 cmp     %o0, 4
F00EBE10: 24800007                 ble,a   loc_F00EBE2C
F00EBE14: f0062004                 ld      [%i0+4], %i0
F00EBE18: e2044000                 ld      [%l1], %l1
F00EBE1C: 80a46000                 cmp     %l1, 0
F00EBE20: 32bffff5                 bne,a   loc_F00EBDF4
F00EBE24: a0102000                 mov     0, %l0
F00EBE28: f0062004                 ld      [%i0+4], %i0
F00EBE2C: 80a62000                 cmp     %i0, 0
F00EBE30: 32bfffdc                 bne,a   loc_F00EBDA0
F00EBE34: d0060000                 ld      [%i0], %o0
F00EBE38: b0102000                 mov     0, %i0
F00EBE3C: 81c7e008                 ret
F00EBE40: 81e80000                 restore
