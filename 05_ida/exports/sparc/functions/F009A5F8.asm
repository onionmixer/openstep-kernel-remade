F009A5F8: 9de3bf98                 save    %sp, -0x68, %sp
F009A5FC: b406a001                 inc     %i2
F009A600: b53ea001                 sra     %i2, 1, %i2
F009A604: b486bfff                 inccc   -1, %i2
F009A608: 0c80000c                 bneg    locret_F009A638
F009A60C: 01000000                 nop
F009A610: c60e0000                 ldub    [%i0], %g3
F009A614: b0062001                 inc     %i0
F009A618: c40e0000                 ldub    [%i0], %g2
F009A61C: b486bfff                 inccc   -1, %i2
F009A620: c42e4000                 stb     %g2, [%i1]
F009A624: b0062001                 inc     %i0
F009A628: b2066001                 inc     %i1
F009A62C: c62e4000                 stb     %g3, [%i1]
F009A630: 1cbffff8                 bpos    loc_F009A610
F009A634: b2066001                 inc     %i1
F009A638: 81c7e008                 ret
F009A63C: 81e80000                 restore
