F007D418: 9de3bf98                 save    %sp, -0x68, %sp
F007D41C: c4062014                 ld      [%i0+0x14], %g2
F007D420: 8600b5d8                 add     %g2, -0xA28, %g3
F007D424: 80a0e029                 cmp     %g3, 0x29 ! ')'
F007D428: 18800006                 bgu     loc_F007D440
F007D42C: 053c0444                 sethi   %hi(unk_F0111138), %g2
F007D430: 8410a138                 bset    %lo(unk_F0111138), %g2
F007D434: 8728e002                 sll     %g3, 2, %g3
F007D438: 10800003                 ba      locret_F007D444
F007D43C: f000c002                 ld      [%g3+%g2], %i0
F007D440: b0102000                 mov     0, %i0
F007D444: 81c7e008                 ret
F007D448: 81e80000                 restore
