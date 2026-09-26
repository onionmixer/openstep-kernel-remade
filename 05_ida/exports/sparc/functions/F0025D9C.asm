F0025D9C: 9de3bf98                 save    %sp, -0x68, %sp
F0025DA0: 113c04d5                 sethi   %hi(dword_F01355D8), %o0
F0025DA4: d20221d8                 ld      [%o0+%lo(dword_F01355D8)], %o1
F0025DA8: 901221d8                 bset    %lo(dword_F01355D8), %o0
F0025DAC: 90023ff8                 inc     -8, %o0
F0025DB0: 80a24008                 cmp     %o1, %o0
F0025DB4: 0280000f                 be      locret_F0025DF0
F0025DB8: b0102000                 mov     0, %i0
F0025DBC: 94100008                 mov     %o0, %o2
F0025DC0: d0026014                 ld      [%o1+0x14], %o0
F0025DC4: 80a22000                 cmp     %o0, 0
F0025DC8: 22800006                 be,a    loc_F0025DE0
F0025DCC: d2026008                 ld      [%o1+8], %o1
F0025DD0: 4000000a                 call    sub_F0025DF8
F0025DD4: 90100009                 mov     %o1, %o0
F0025DD8: 10800006                 ba      locret_F0025DF0
F0025DDC: b0102001                 mov     1, %i0
F0025DE0: 80a2400a                 cmp     %o1, %o2
F0025DE4: 32bffff8                 bne,a   loc_F0025DC4
F0025DE8: d0026014                 ld      [%o1+0x14], %o0
F0025DEC: b0102000                 mov     0, %i0
F0025DF0: 81c7e008                 ret
F0025DF4: 81e80000                 restore
