F00A97A4: 9de3bf98                 save    %sp, -0x68, %sp
F00A97A8: 80a6a000                 cmp     %i2, 0
F00A97AC: 12800005                 bne     loc_F00A97C0
F00A97B0: 84100018                 mov     %i0, %g2
F00A97B4: 313c046f                 sethi   %hi(_dev_null), %i0
F00A97B8: 10800009                 ba      locret_F00A97DC
F00A97BC: b01622bc                 bset    %lo(_dev_null), %i0
F00A97C0: 80a6a00f                 cmp     %i2, 0xF
F00A97C4: 08800005                 bleu    loc_F00A97D8
F00A97C8: b12ea002                 sll     %i2, 2, %i0
F00A97CC: b0063fc0                 inc     -0x40, %i0
F00A97D0: 10800003                 ba      locret_F00A97DC
F00A97D4: b0064018                 add     %i1, %i0, %i0
F00A97D8: b0008018                 add     %g2, %i0, %i0
F00A97DC: 81c7e008                 ret
F00A97E0: 81e80000                 restore
