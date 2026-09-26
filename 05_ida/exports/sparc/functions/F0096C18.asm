F0096C18: 91480000                 rdhpr   %hpstate, %o0
F0096C1C: 820a2f00                 and     %o0, 0xF00, %g1
F0096C20: 80a06600                 cmp     %g1, 0x600
F0096C24: 26800004                 bl,a    loc_F0096C34
F0096C28: 822a2f00                 andn    %o0, 0xF00, %g1
F0096C2C: 81c3e008                 retl
F0096C30: 01000000                 nop
F0096C34: 82106600                 bset    0x600, %g1
F0096C38: 81884000                 saved
F0096C3C: 01000000                 nop
F0096C40: 81c3e008                 retl
F0096C44: 01000000                 nop
