F0092F2C: 9de3bf98                 save    %sp, -0x68, %sp
F0092F30: 912e2010                 sll     %i0, 16, %o0
F0092F34: 400000c0                 call    sub_F0093234
F0092F38: 913a2010                 sra     %o0, 16, %o0! id
F0092F3C: 80a22000                 cmp     %o0, 0
F0092F40: 12800004                 bne     loc_F0092F50
F0092F44: 133c0504                 sethi   -0xFEBF000, %o1
F0092F48: 10800005                 ba      locret_F0092F5C
F0092F4C: b0102006                 mov     6, %i0
F0092F50: d20261cc                 ld      [%o1+0x1CC], %o1! SEL
F0092F54: 40017a47                 call    _objc_msgSend
F0092F58: 94100008                 mov     %o0, %o2
F0092F5C: 81c7e008                 ret
F0092F60: 81e80000                 restore
