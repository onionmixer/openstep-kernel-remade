F002BF04: 9de3bf98                 save    %sp, -0x68, %sp
F002BF08: 113c04bd                 sethi   %hi(dword_F012F414), %o0
F002BF0C: e0022014                 ld      [%o0+%lo(dword_F012F414)], %l0
F002BF10: 80a42000                 cmp     %l0, 0
F002BF14: 0280000a                 be      locret_F002BF3C
F002BF18: 01000000                 nop
F002BF1C: d4040000                 ld      [%l0], %o2
F002BF20: d0042004                 ld      [%l0+4], %o0
F002BF24: 9fc28000                 call    %o2
F002BF28: 92100018                 mov     %i0, %o1
F002BF2C: e0042008                 ld      [%l0+8], %l0
F002BF30: 80a42000                 cmp     %l0, 0
F002BF34: 32bffffb                 bne,a   loc_F002BF20
F002BF38: d4040000                 ld      [%l0], %o2
F002BF3C: 81c7e008                 ret
F002BF40: 81e80000                 restore
