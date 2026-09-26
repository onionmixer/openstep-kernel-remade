F0093234: 9de3bf98                 save    %sp, -0x68, %sp
F0093238: 860e20ff                 and     %i0, 0xFF, %g3
F009323C: 80a0e003                 cmp     %g3, 3
F0093240: 18800006                 bgu     loc_F0093258
F0093244: 053c04f6                 sethi   %hi(_sgIdMap), %g2
F0093248: 8410a1c0                 bset    %lo(_sgIdMap), %g2
F009324C: 8728e002                 sll     %g3, 2, %g3
F0093250: 10800003                 ba      locret_F009325C
F0093254: f000c002                 ld      [%g3+%g2], %i0
F0093258: b0102000                 mov     0, %i0
F009325C: 81c7e008                 ret
F0093260: 81e80000                 restore
