F007E11C: 9de3bf98                 save    %sp, -0x68, %sp
F007E120: c4062014                 ld      [%i0+0x14], %g2
F007E124: 8600b380                 add     %g2, -0xC80, %g3
F007E128: 80a0e012                 cmp     %g3, 0x12
F007E12C: 18800006                 bgu     loc_F007E144
F007E130: 053c0444                 sethi   %hi(unk_F011129C), %g2
F007E134: 8410a29c                 bset    %lo(unk_F011129C), %g2
F007E138: 8728e002                 sll     %g3, 2, %g3
F007E13C: 10800003                 ba      locret_F007E148
F007E140: f000c002                 ld      [%g3+%g2], %i0
F007E144: b0102000                 mov     0, %i0
F007E148: 81c7e008                 ret
F007E14C: 81e80000                 restore
