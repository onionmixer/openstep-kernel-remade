F0096D24: 93480000                 rdhpr   %hpstate, %o1
F0096D28: 942a6f00                 andn    %o1, 0xF00, %o2
F0096D2C: 900a2f00                 and     %o0, 0xF00, %o0
F0096D30: 94128008                 bset    %o0, %o2
F0096D34: 818a8000                 saved
F0096D38: 900a6f00                 and     %o1, 0xF00, %o0
F0096D3C: 81c3e008                 retl
F0096D40: 01000000                 nop
