F0095D1C: aa102300                 mov     0x300, %l5
F0095D20: c0854080                 lda     [%l5]#ASI_NUCLEUS, %g0
F0095D24: aa102000                 mov     0, %l5
F0095D28: e8854080                 lda     [%l5]#ASI_NUCLEUS, %l4
F0095D2C: a8152002                 bset    2, %l4
F0095D30: e8a54080                 sta     %l4, [%l5]#ASI_NUCLEUS
F0095D34: e01ba000                 ldd     [%sp+arg_0], %l0
F0095D38: e41ba008                 ldd     [%sp+arg_8], %l2
F0095D3C: e81ba010                 ldd     [%sp+arg_10], %l4
F0095D40: ec1ba018                 ldd     [%sp+arg_18], %l6
F0095D44: f01ba020                 ldd     [%sp+arg_20], %i0
F0095D48: f41ba028                 ldd     [%sp+arg_28], %i2
F0095D4C: f81ba030                 ldd     [%sp+arg_30], %i4
F0095D50: fc1ba038                 ldd     [%sp+arg_38], %fp
F0095D54: 81e00000                 save
F0095D58: 81e00000                 save
F0095D5C: aa102000                 mov     0, %l5
F0095D60: e8854080                 lda     [%l5]#ASI_NUCLEUS, %l4
F0095D64: a82d2002                 bclr    2, %l4
F0095D68: e8a54080                 sta     %l4, [%l5]#ASI_NUCLEUS
F0095D6C: aa102400                 mov     0x400, %l5
F0095D70: ea854080                 lda     [%l5]#ASI_NUCLEUS, %l5
F0095D74: a8102300                 mov     0x300, %l4
F0095D78: e8850080                 lda     [%l4]#ASI_NUCLEUS, %l4
F0095D7C: 1080061a                 ba      wu_chk_flt
F0095D80: 01000000                 nop
