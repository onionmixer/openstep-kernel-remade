F0095C6C: 82102300                 mov     0x300, %g1
F0095C70: c0804080                 lda     [%g1]#ASI_NUCLEUS, %g0
F0095C74: 84102000                 mov     0, %g2
F0095C78: c2808080                 lda     [%g2]#ASI_NUCLEUS, %g1
F0095C7C: 82106002                 bset    2, %g1
F0095C80: c2a08080                 sta     %g1, [%g2]#ASI_NUCLEUS
F0095C84: 81e80000                 restore
F0095C88: e01ba000                 ldd     [%sp+arg_0], %l0
F0095C8C: e41ba008                 ldd     [%sp+arg_8], %l2
F0095C90: e81ba010                 ldd     [%sp+arg_10], %l4
F0095C94: ec1ba018                 ldd     [%sp+arg_18], %l6
F0095C98: f01ba020                 ldd     [%sp+arg_20], %i0
F0095C9C: f41ba028                 ldd     [%sp+arg_28], %i2
F0095CA0: f81ba030                 ldd     [%sp+arg_30], %i4
F0095CA4: fc1ba038                 ldd     [%sp+arg_38], %fp
F0095CA8: 81e00000                 save
F0095CAC: 82286002                 bclr    2, %g1
F0095CB0: c2a08080                 sta     %g1, [%g2]#ASI_NUCLEUS
F0095CB4: 84102400                 mov     0x400, %g2
F0095CB8: c4808080                 lda     [%g2]#ASI_NUCLEUS, %g2
F0095CBC: 82102300                 mov     0x300, %g1
F0095CC0: c2804080                 lda     [%g1]#ASI_NUCLEUS, %g1
F0095CC4: 30bdb647                 ba,a    sr_chk_flt
