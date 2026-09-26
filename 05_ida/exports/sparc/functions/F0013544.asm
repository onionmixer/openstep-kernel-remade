F0013544: 9de3bf98                 save    %sp, -0x68, %sp
F0013548: f2060000                 ld      [%i0], %i1
F001354C: 05017d788410a100         set     0x5F5E100, %g2
F0013554: 80a64002                 cmp     %i1, %g2
F0013558: 18800007                 bgu     loc_F0013574
F001355C: 050003d0                 sethi   0xF4000, %g2
F0013560: c6062004                 ld      [%i0+4], %g3
F0013564: 8410a23f                 bset    0x23F, %g2
F0013568: 80a0c002                 cmp     %g3, %g2
F001356C: 08800004                 bleu    loc_F001357C
F0013570: 80a66000                 cmp     %i1, 0
F0013574: 1080000d                 ba      locret_F00135A8
F0013578: b0102016                 mov     0x16, %i0
F001357C: 3280000b                 bne,a   locret_F00135A8
F0013580: b0102000                 mov     0, %i0
F0013584: 80a0e000                 cmp     %g3, 0
F0013588: 22800008                 be,a    locret_F00135A8
F001358C: b0102000                 mov     0, %i0
F0013590: 053c043e                 sethi   %hi(_tick), %g2
F0013594: c400a3e4                 ld      [%g2+%lo(_tick)], %g2
F0013598: 80a0c002                 cmp     %g3, %g2
F001359C: 26800002                 bl,a    loc_F00135A4
F00135A0: c4262004                 st      %g2, [%i0+4]
F00135A4: b0102000                 mov     0, %i0
F00135A8: 81c7e008                 ret
F00135AC: 81e80000                 restore
