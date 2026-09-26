0409E564: 2d680000fef4             move.l  0(a0),-$10C(a6)
0409E56A: 2d680004fef8             move.l  4(a0),-$108(a6)
0409E570: 2d680008fefc             move.l  8(a0),-$104(a6)
0409E576: ecee0008fef6             bfclr   -$10A(a6){0:8}
0409E57C: 67ff0000000a             beq.l   loc_409E588
0409E582: 08ee0007fef4             bset    #7,-$10C(a6)
0409E588: ecee0144ff18             bfclr   -$E8(a6){5:4}
0409E58E: 4e75                     rts
