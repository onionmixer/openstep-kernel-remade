F006FE64: 9de3bf98                 save    %sp, -0x68, %sp
F006FE68: d0064000                 ld      [%i1], %o0
F006FE6C: 80a2200f                 cmp     %o0, 0xF
F006FE70: 18800004                 bgu     loc_F006FE80
F006FE74: a0100018                 mov     %i0, %l0
F006FE78: 1080001f                 ba      locret_F006FEF4
F006FE7C: b0102000                 mov     0, %i0
F006FE80: d0040000                 ld      [%l0], %o0
F006FE84: 13004000                 sethi   0x1000000, %o1
F006FE88: f004200c                 ld      [%l0+0xC], %i0
F006FE8C: 90120009                 bset    %o1, %o0
F006FE90: d0240000                 st      %o0, [%l0]
F006FE94: 9010200c                 mov     0xC, %o0
F006FE98: 80a62400                 cmp     %i0, 0x400
F006FE9C: 08800005                 bleu    loc_F006FEB0
F006FEA0: d0342002                 sth     %o0, [%l0+2]
F006FEA4: 90102002                 mov     2, %o0
F006FEA8: 1080000a                 ba      loc_F006FED0
F006FEAC: d0242008                 st      %o0, [%l0+8]
F006FEB0: 9204200c                 add     %l0, 0xC, %o1
F006FEB4: d0042008                 ld      [%l0+8], %o0
F006FEB8: 40009fe9                 call    _copywithin
F006FEBC: 94100018                 mov     %i0, %o2
F006FEC0: d0142002                 lduh    [%l0+2], %o0
F006FEC4: c0242008                 clr     [%l0+8]
F006FEC8: 90020018                 add     %o0, %i0, %o0
F006FECC: d0342002                 sth     %o0, [%l0+2]
F006FED0: 113c04f1                 sethi   %hi(_kdp), %o0
F006FED4: d0122000                 lduh    [%o0+%lo(_kdp)], %o0
F006FED8: b0102001                 mov     1, %i0
F006FEDC: d0368000                 sth     %o0, [%i2]
F006FEE0: 1100003f                 sethi   0xFC00, %o0
F006FEE4: d2040000                 ld      [%l0], %o1
F006FEE8: 901223ff                 bset    0x3FF, %o0
F006FEEC: 920a4008                 and     %o1, %o0, %o1
F006FEF0: d2264000                 st      %o1, [%i1]
F006FEF4: 81c7e008                 ret
F006FEF8: 81e80000                 restore
