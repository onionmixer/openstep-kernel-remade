F00DB420: 9de3bf90                 save    %sp, -0x70, %sp
F00DB424: 86100018                 mov     %i0, %g3
F00DB428: c400e064                 ld      [%g3+0x64], %g2
F00DB42C: 80a6c002                 cmp     %i3, %g2
F00DB430: 1280000a                 bne     locret_F00DB458
F00DB434: b0102000                 mov     0, %i0
F00DB438: c400e068                 ld      [%g3+0x68], %g2
F00DB43C: 80a70002                 cmp     %i4, %g2
F00DB440: 12800006                 bne     locret_F00DB458
F00DB444: 01000000                 nop
F00DB448: c400e06c                 ld      [%g3+0x6C], %g2
F00DB44C: 841f4002                 btog    %i5, %g2
F00DB450: 80a00002                 cmp     %g0, %g2
F00DB454: b0603fff                 subc    %g0, -1, %i0
F00DB458: 81c7e008                 ret
F00DB45C: 81e80000                 restore
