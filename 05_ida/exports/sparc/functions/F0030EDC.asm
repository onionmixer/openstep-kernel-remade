F0030EDC: 9de3bf98                 save    %sp, -0x68, %sp
F0030EE0: e0062024                 ld      [%i0+0x24], %l0
F0030EE4: 80a42000                 cmp     %l0, 0
F0030EE8: 0280000c                 be      locret_F0030F18
F0030EEC: 01000000                 nop
F0030EF0: d0142024                 lduh    [%l0+0x24], %o0
F0030EF4: 808a2010                 btst    0x10, %o0
F0030EF8: 02800005                 be      loc_F0030F0C
F0030EFC: 11200c1c                 sethi   -0x7FCF9000, %o0
F0030F00: 9012220b                 bset    0x20B, %o0
F0030F04: 7ffff07d                 call    _rtrequest
F0030F08: 92100010                 mov     %l0, %o1
F0030F0C: 7fffefc6                 call    _rtfree
F0030F10: 90100010                 mov     %l0, %o0
F0030F14: c0262024                 clr     [%i0+0x24]
F0030F18: 81c7e008                 ret
F0030F1C: 81e80000                 restore
