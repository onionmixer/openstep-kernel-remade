F0030F20: 9de3bf98                 save    %sp, -0x68, %sp
F0030F24: d0062024                 ld      [%i0+0x24], %o0
F0030F28: 80a22000                 cmp     %o0, 0
F0030F2C: 02800005                 be      locret_F0030F40
F0030F30: 01000000                 nop
F0030F34: 7fffefbc                 call    _rtfree
F0030F38: 01000000                 nop
F0030F3C: c0262024                 clr     [%i0+0x24]
F0030F40: 81c7e008                 ret
F0030F44: 81e80000                 restore
