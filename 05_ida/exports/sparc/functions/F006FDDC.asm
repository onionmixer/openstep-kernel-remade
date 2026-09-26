F006FDDC: 9de3bf98                 save    %sp, -0x68, %sp
F006FDE0: d0064000                 ld      [%i1], %o0
F006FDE4: 80a2200f                 cmp     %o0, 0xF
F006FDE8: 18800004                 bgu     loc_F006FDF8
F006FDEC: a0100018                 mov     %i0, %l0
F006FDF0: 1080001b                 ba      locret_F006FE5C
F006FDF4: b0102000                 mov     0, %i0
F006FDF8: d404200c                 ld      [%l0+0xC], %o2
F006FDFC: 80a2a400                 cmp     %o2, 0x400
F006FE00: 08800004                 bleu    loc_F006FE10
F006FE04: 90102002                 mov     2, %o0
F006FE08: 10800006                 ba      loc_F006FE20
F006FE0C: d0242008                 st      %o0, [%l0+8]
F006FE10: d2042008                 ld      [%l0+8], %o1
F006FE14: 4000a012                 call    _copywithin
F006FE18: 90042010                 add     %l0, 0x10, %o0
F006FE1C: c0242008                 clr     [%l0+8]
F006FE20: d0040000                 ld      [%l0], %o0
F006FE24: 13004000                 sethi   0x1000000, %o1
F006FE28: 90120009                 bset    %o1, %o0
F006FE2C: d0240000                 st      %o0, [%l0]
F006FE30: 9010200c                 mov     0xC, %o0
F006FE34: d0342002                 sth     %o0, [%l0+2]
F006FE38: 113c04f1                 sethi   %hi(_kdp), %o0
F006FE3C: d0122000                 lduh    [%o0+%lo(_kdp)], %o0
F006FE40: b0102001                 mov     1, %i0
F006FE44: d0368000                 sth     %o0, [%i2]
F006FE48: 1100003f                 sethi   0xFC00, %o0
F006FE4C: d2040000                 ld      [%l0], %o1
F006FE50: 901223ff                 bset    0x3FF, %o0
F006FE54: 920a4008                 and     %o1, %o0, %o1
F006FE58: d2264000                 st      %o1, [%i1]
F006FE5C: 81c7e008                 ret
F006FE60: 81e80000                 restore
