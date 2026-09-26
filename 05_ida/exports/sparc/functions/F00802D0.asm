F00802D0: 9de3bf98                 save    %sp, -0x68, %sp
F00802D4: c4062014                 ld      [%i0+0x14], %g2
F00802D8: 8600b830                 add     %g2, -0x7D0, %g3
F00802DC: 80a0e067                 cmp     %g3, 0x67 ! 'g'
F00802E0: 18800006                 bgu     loc_F00802F8
F00802E4: 053c0445                 sethi   %hi(unk_F01114CC), %g2
F00802E8: 8410a0cc                 bset    %lo(unk_F01114CC), %g2
F00802EC: 8728e002                 sll     %g3, 2, %g3
F00802F0: 10800003                 ba      locret_F00802FC
F00802F4: f000c002                 ld      [%g3+%g2], %i0
F00802F8: b0102000                 mov     0, %i0
F00802FC: 81c7e008                 ret
F0080300: 81e80000                 restore
