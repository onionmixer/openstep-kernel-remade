F0092EE8: 9de3bf98                 save    %sp, -0x68, %sp
F0092EEC: 912e2010                 sll     %i0, 16, %o0
F0092EF0: 400000d1                 call    sub_F0093234
F0092EF4: 913a2010                 sra     %o0, 16, %o0! id
F0092EF8: 80a22000                 cmp     %o0, 0
F0092EFC: 12800004                 bne     loc_F0092F0C
F0092F00: 133c0504                 sethi   -0xFEBF000, %o1
F0092F04: 10800008                 ba      locret_F0092F24
F0092F08: b0102006                 mov     6, %i0
F0092F0C: d20261c8                 ld      [%o1+0x1C8], %o1! SEL
F0092F10: 40017a58                 call    _objc_msgSend
F0092F14: 94100008                 mov     %o0, %o2
F0092F18: 80a00008                 cmp     %g0, %o0
F0092F1C: b0602000                 subc    %g0, 0, %i0
F0092F20: b00e2010                 and     %i0, 0x10, %i0
F0092F24: 81c7e008                 ret
F0092F28: 81e80000                 restore
