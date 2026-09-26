F000F7F0: 9de3bf98                 save    %sp, -0x68, %sp
F000F7F4: 053c04cf                 sethi   %hi(_active_u), %g2
F000F7F8: c400a1d8                 ld      [%g2+%lo(_active_u)], %g2
F000F7FC: c400a01c                 ld      [%g2+0x1C], %g2
F000F800: 8600a00a                 add     %g2, 0xA, %g3
F000F804: b200a02a                 add     %g2, 0x2A, %i1 ! '*'
F000F808: 80a0c019                 cmp     %g3, %i1
F000F80C: 1a80001a                 bcc     locret_F000F874
F000F810: 852e2010                 sll     %i0, 16, %g2
F000F814: b538a010                 sra     %g2, 16, %i2
F000F818: b0100019                 mov     %i1, %i0
F000F81C: c450c000                 ldsh    [%g3], %g2
F000F820: 80a0801a                 cmp     %g2, %i2
F000F824: 22800007                 be,a    loc_F000F840
F000F828: 313c04cf                 sethi   -0xFECC400, %i0
F000F82C: 8600e002                 inc     2, %g3
F000F830: 80a0c018                 cmp     %g3, %i0
F000F834: 2abffffb                 bcs,a   loc_F000F820
F000F838: c450c000                 ldsh    [%g3], %g2
F000F83C: 3080000e                 ba,a    locret_F000F874
F000F840: c40621d8                 ld      [%i0+0x1D8], %g2
F000F844: 10800006                 ba      loc_F000F85C
F000F848: c400a01c                 ld      [%g2+0x1C], %g2
F000F84C: c430c000                 sth     %g2, [%g3]
F000F850: c40621d8                 ld      [%i0+0x1D8], %g2
F000F854: c400a01c                 ld      [%g2+0x1C], %g2
F000F858: 8600e002                 inc     2, %g3
F000F85C: 8400a028                 inc     0x28, %g2 ! '('
F000F860: 80a0c002                 cmp     %g3, %g2
F000F864: 2abffffa                 bcs,a   loc_F000F84C
F000F868: c410e002                 lduh    [%g3+2], %g2
F000F86C: 84103fff                 mov     -1, %g2
F000F870: c430c000                 sth     %g2, [%g3]
F000F874: 81c7e008                 ret
F000F878: 81e80000                 restore
