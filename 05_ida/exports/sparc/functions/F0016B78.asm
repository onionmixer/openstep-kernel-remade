F0016B78: 9de3bf98                 save    %sp, -0x68, %sp
F0016B7C: 4002000f                 call    _spltty
F0016B80: 01000000                 nop
F0016B84: d4062040                 ld      [%i0+0x40], %o2
F0016B88: 1301000092126121         set     0x4000121, %o1
F0016B90: 808a8009                 btst    %o1, %o2
F0016B94: 12800008                 bne     loc_F0016BB4
F0016B98: a0100008                 mov     %o0, %l0
F0016B9C: d2062024                 ld      [%i0+0x24], %o1
F0016BA0: 80a26000                 cmp     %o1, 0
F0016BA4: 02800004                 be      loc_F0016BB4
F0016BA8: 01000000                 nop
F0016BAC: 9fc24000                 call    %o1
F0016BB0: 90100018                 mov     %i0, %o0
F0016BB4: 4002005c                 call    _splx
F0016BB8: 90100010                 mov     %l0, %o0
F0016BBC: 81c7e008                 ret
F0016BC0: 81e80000                 restore
