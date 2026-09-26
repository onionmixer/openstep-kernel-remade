F0091F08: 9de3bf98                 save    %sp, -0x68, %sp
F0091F0C: c4062014                 ld      [%i0+0x14], %g2
F0091F10: 8600b574                 add     %g2, -0xA8C, %g3
F0091F14: 80a0e026                 cmp     %g3, 0x26 ! '&'
F0091F18: 18800006                 bgu     loc_F0091F30
F0091F1C: 053c0448                 sethi   %hi(unk_F0112304), %g2
F0091F20: 8410a304                 bset    %lo(unk_F0112304), %g2
F0091F24: 8728e002                 sll     %g3, 2, %g3
F0091F28: 10800003                 ba      locret_F0091F34
F0091F2C: f000c002                 ld      [%g3+%g2], %i0
F0091F30: b0102000                 mov     0, %i0
F0091F34: 81c7e008                 ret
F0091F38: 81e80000                 restore
