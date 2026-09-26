F003D214: 9de3bf98                 save    %sp, -0x68, %sp
F003D218: c6060000                 ld      [%i0], %g3
F003D21C: 80a0e000                 cmp     %g3, 0
F003D220: 02800017                 be      locret_F003D27C
F003D224: 80a0c018                 cmp     %g3, %i0
F003D228: 12800005                 bne     loc_F003D23C
F003D22C: 333c0434                 sethi   -0xFEF3000, %i1
F003D230: 053c0434                 sethi   %hi(_rpfreelist), %g2
F003D234: 1080000c                 ba      loc_F003D264
F003D238: c020a048                 clr     [%g2+%lo(_rpfreelist)]
F003D23C: c4066048                 ld      [%i1+0x48], %g2
F003D240: 80a60002                 cmp     %i0, %g2
F003D244: 22800002                 be,a    loc_F003D24C
F003D248: c6266048                 st      %g3, [%i1+0x48]
F003D24C: c6062004                 ld      [%i0+4], %g3
F003D250: c4060000                 ld      [%i0], %g2
F003D254: c420c000                 st      %g2, [%g3]
F003D258: c6060000                 ld      [%i0], %g3
F003D25C: c4062004                 ld      [%i0+4], %g2
F003D260: c420e004                 st      %g2, [%g3+4]
F003D264: c0262004                 clr     [%i0+4]
F003D268: 073c04ea                 sethi   %hi(_rnfree), %g3
F003D26C: c400e270                 ld      [%g3+%lo(_rnfree)], %g2
F003D270: c0260000                 clr     [%i0]
F003D274: 8400bfff                 inc     -1, %g2
F003D278: c420e270                 st      %g2, [%g3+%lo(_rnfree)]
F003D27C: 81c7e008                 ret
F003D280: 81e80000                 restore
