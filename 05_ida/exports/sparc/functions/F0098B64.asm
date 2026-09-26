F0098B64: 9de3bf98                 save    %sp, -0x68, %sp
F0098B68: d2062284                 ld      [%i0+0x284], %o1
F0098B6C: 80a26000                 cmp     %o1, 0
F0098B70: 0280000a                 be      locret_F0098B98
F0098B74: 153c044d                 sethi   %hi(_fp_ctxp), %o2
F0098B78: d002a078                 ld      [%o2+%lo(_fp_ctxp)], %o0
F0098B7C: 80a20009                 cmp     %o0, %o1
F0098B80: 22800002                 be,a    loc_F0098B88
F0098B84: c022a078                 clr     [%o2+%lo(_fp_ctxp)]
F0098B88: d0062284                 ld      [%i0+0x284], %o0
F0098B8C: 7fff3d85                 call    _kfree
F0098B90: 92102110                 mov     0x110, %o1
F0098B94: c0262284                 clr     [%i0+0x284]
F0098B98: 81c7e008                 ret
F0098B9C: 81e80000                 restore
