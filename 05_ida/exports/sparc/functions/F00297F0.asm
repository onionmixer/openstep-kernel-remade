F00297F0: 9de3bf98                 save    %sp, -0x68, %sp
F00297F4: 9fc64000                 call    %i1
F00297F8: 90100018                 mov     %i0, %o0
F00297FC: d2060000                 ld      [%i0], %o1
F0029800: 11000008                 sethi   0x2000, %o0
F0029804: 808a4008                 btst    %o0, %o1
F0029808: 12800011                 bne     locret_F002984C
F002980C: 01000000                 nop
F0029810: 4001b4ea                 call    _spltty
F0029814: 01000000                 nop
F0029818: d2060000                 ld      [%i0], %o1
F002981C: 808a6002                 btst    2, %o1
F0029820: 12800009                 bne     loc_F0029844
F0029824: b2100008                 mov     %o0, %i1
F0029828: 90100018                 mov     %i0, %o0! unsigned int
F002982C: 7fffa393                 call    _sleep
F0029830: 9210001a                 mov     %i2, %o1
F0029834: d0060000                 ld      [%i0], %o0
F0029838: 808a2002                 btst    2, %o0
F002983C: 02bffffc                 be      loc_F002982C
F0029840: 90100018                 mov     %i0, %o0
F0029844: 4001b538                 call    _splx
F0029848: 90100019                 mov     %i1, %o0
F002984C: 81c7e008                 ret
F0029850: 81e80000                 restore
