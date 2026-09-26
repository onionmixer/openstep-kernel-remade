F009B2B4: 9de3bf98                 save    %sp, -0x68, %sp
F009B2B8: 7fffeed2                 call    _getpsr
F009B2BC: a0100018                 mov     %i0, %l0
F009B2C0: 91322018                 srl     %o0, 24, %o0
F009B2C4: 80a22040                 cmp     %o0, 0x40 ! '@'
F009B2C8: 12800004                 bne     loc_F009B2D8
F009B2CC: 80a22041                 cmp     %o0, 0x41 ! 'A'
F009B2D0: 10800007                 ba      locret_F009B2EC
F009B2D4: b0102001                 mov     1, %i0
F009B2D8: 12800005                 bne     locret_F009B2EC
F009B2DC: b0102000                 mov     0, %i0
F009B2E0: 91342018                 srl     %l0, 24, %o0
F009B2E4: 80a00008                 cmp     %g0, %o0
F009B2E8: b0603fff                 subc    %g0, -1, %i0
F009B2EC: 81c7e008                 ret
F009B2F0: 81e80000                 restore
