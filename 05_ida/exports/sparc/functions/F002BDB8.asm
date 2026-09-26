F002BDB8: 9de3bf98                 save    %sp, -0x68, %sp
F002BDBC: 90100018                 mov     %i0, %o0
F002BDC0: d2022040                 ld      [%o0+0x40], %o1
F002BDC4: 80a26000                 cmp     %o1, 0
F002BDC8: 02800005                 be      locret_F002BDDC
F002BDCC: b0102000                 mov     0, %i0
F002BDD0: 9fc24000                 call    %o1
F002BDD4: 01000000                 nop
F002BDD8: b0100008                 mov     %o0, %i0
F002BDDC: 81c7e008                 ret
F002BDE0: 81e80000                 restore
