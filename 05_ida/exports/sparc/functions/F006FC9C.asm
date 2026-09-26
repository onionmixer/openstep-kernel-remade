F006FC9C: 9de3bf98                 save    %sp, -0x68, %sp
F006FCA0: d0064000                 ld      [%i1], %o0
F006FCA4: 80a22007                 cmp     %o0, 7
F006FCA8: 08800014                 bleu    loc_F006FCF8
F006FCAC: a0100018                 mov     %i0, %l0
F006FCB0: d0040000                 ld      [%l0], %o0
F006FCB4: 13004000                 sethi   0x1000000, %o1
F006FCB8: 90120009                 bset    %o1, %o0
F006FCBC: d0240000                 st      %o0, [%l0]
F006FCC0: 90102014                 mov     0x14, %o0
F006FCC4: d0342002                 sth     %o0, [%l0+2]
F006FCC8: 40009263                 call    _kdp_machine_hostinfo
F006FCCC: 90042008                 add     %l0, 8, %o0
F006FCD0: 113c04f1                 sethi   %hi(_kdp), %o0
F006FCD4: d0122000                 lduh    [%o0+%lo(_kdp)], %o0
F006FCD8: b0102001                 mov     1, %i0
F006FCDC: d0368000                 sth     %o0, [%i2]
F006FCE0: 1100003f                 sethi   0xFC00, %o0
F006FCE4: d2040000                 ld      [%l0], %o1
F006FCE8: 901223ff                 bset    0x3FF, %o0
F006FCEC: 920a4008                 and     %o1, %o0, %o1
F006FCF0: 10800003                 ba      locret_F006FCFC
F006FCF4: d2264000                 st      %o1, [%i1]
F006FCF8: b0102000                 mov     0, %i0
F006FCFC: 81c7e008                 ret
F006FD00: 81e80000                 restore
