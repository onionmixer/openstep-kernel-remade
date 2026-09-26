F002BFD4: 9de3bf98                 save    %sp, -0x68, %sp
F002BFD8: a4100018                 mov     %i0, %l2
F002BFDC: 113c04d0                 sethi   %hi(_ifnet), %o0
F002BFE0: f00220b8                 ld      [%o0+%lo(_ifnet)], %i0
F002BFE4: ec07a05c                 ld      [%fp+arg_5C], %l6
F002BFE8: e607a060                 ld      [%fp+arg_60], %l3
F002BFEC: e807a064                 ld      [%fp+arg_64], %l4
F002BFF0: ea07a068                 ld      [%fp+arg_68], %l5
F002BFF4: e207a06c                 ld      [%fp+arg_6C], %l1
F002BFF8: a0102000                 mov     0, %l0
F002BFFC: 80a62000                 cmp     %i0, 0
F002C000: 02800011                 be      loc_F002C044
F002C004: ee07a070                 ld      [%fp+arg_70], %l7
F002C008: 113c03d392122150         set     aNull, %o1! "null"
F002C010: d0060000                 ld      [%i0], %o0
F002C014: 80a20009                 cmp     %o0, %o1
F002C018: 32800008                 bne,a   loc_F002C038
F002C01C: f006205c                 ld      [%i0+0x5C], %i0
F002C020: d0062014                 ld      [%i0+0x14], %o0
F002C024: 80a20011                 cmp     %o0, %l1
F002C028: 32800004                 bne,a   loc_F002C038
F002C02C: f006205c                 ld      [%i0+0x5C], %i0
F002C030: 10800005                 ba      loc_F002C044
F002C034: a0042001                 inc     %l0
F002C038: 80a62000                 cmp     %i0, 0
F002C03C: 32bffff6                 bne,a   loc_F002C014
F002C040: d0060000                 ld      [%i0], %o0
F002C044: 80a42000                 cmp     %l0, 0
F002C048: 32800008                 bne,a   loc_F002C068
F002C04C: fa260000                 st      %i5, [%i0]
F002C050: 4000f008                 call    _kalloc
F002C054: 90102060                 mov     0x60, %o0! void *
F002C058: b0100008                 mov     %o0, %i0
F002C05C: 4001a37f                 call    _bzero
F002C060: 92102060                 mov     0x60, %o1 ! '`'
F002C064: fa260000                 st      %i5, [%i0]
F002C068: e6262004                 st      %l3, [%i0+4]
F002C06C: ec362008                 sth     %l6, [%i0+8]
F002C070: e836200a                 sth     %l4, [%i0+0xA]
F002C074: ea36200c                 sth     %l5, [%i0+0xC]
F002C078: c0262010                 clr     [%i0+0x10]
F002C07C: c0262018                 clr     [%i0+0x18]
F002C080: e4262030                 st      %l2, [%i0+0x30]
F002C084: f4262034                 st      %i2, [%i0+0x34]
F002C088: f8262038                 st      %i4, [%i0+0x38]
F002C08C: f226203c                 st      %i1, [%i0+0x3C]
F002C090: f6262040                 st      %i3, [%i0+0x40]
F002C094: ee262058                 st      %l7, [%i0+0x58]
F002C098: e2262014                 st      %l1, [%i0+0x14]
F002C09C: c0262044                 clr     [%i0+0x44]
F002C0A0: c0262048                 clr     [%i0+0x48]
F002C0A4: c026204c                 clr     [%i0+0x4C]
F002C0A8: c0262050                 clr     [%i0+0x50]
F002C0AC: c0262054                 clr     [%i0+0x54]
F002C0B0: 113c0430                 sethi   %hi(_ifqmaxlen), %o0
F002C0B4: d00221d8                 ld      [%o0+%lo(_ifqmaxlen)], %o0
F002C0B8: 80a42000                 cmp     %l0, 0
F002C0BC: 12800013                 bne     loc_F002C108
F002C0C0: d0262028                 st      %o0, [%i0+0x28]
F002C0C4: 113c04d0                 sethi   %hi(_ifnet), %o0
F002C0C8: d20220b8                 ld      [%o0+%lo(_ifnet)], %o1
F002C0CC: 80a26000                 cmp     %o1, 0
F002C0D0: 0280000b                 be      loc_F002C0FC
F002C0D4: 941220b8                 or      %o0, %lo(_ifnet), %o2
F002C0D8: d2028000                 ld      [%o2], %o1
F002C0DC: d0026014                 ld      [%o1+0x14], %o0
F002C0E0: 80a20011                 cmp     %o0, %l1
F002C0E4: 2a800007                 bcs,a   loc_F002C100
F002C0E8: d0028000                 ld      [%o2], %o0
F002C0EC: d002605c                 ld      [%o1+0x5C], %o0
F002C0F0: 80a22000                 cmp     %o0, 0
F002C0F4: 12bffff9                 bne     loc_F002C0D8
F002C0F8: 9402605c                 add     %o1, 0x5C, %o2 ! '\'
F002C0FC: d0028000                 ld      [%o2], %o0
F002C100: d026205c                 st      %o0, [%i0+0x5C]
F002C104: f0228000                 st      %i0, [%o2]
F002C108: d0062014                 ld      [%i0+0x14], %o0
F002C10C: 80a22000                 cmp     %o0, 0
F002C110: 12800004                 bne     locret_F002C120
F002C114: 01000000                 nop
F002C118: 7fffff7b                 call    sub_F002BF04
F002C11C: 90100018                 mov     %i0, %o0
F002C120: 81c7e008                 ret
F002C124: 81e80000                 restore
