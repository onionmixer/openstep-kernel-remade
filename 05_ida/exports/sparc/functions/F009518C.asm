F009518C: 2b3c044d                 sethi   %hi(_fp_ctxp), %l5
F0095190: ea056078                 ld      [%l5+%lo(_fp_ctxp)], %l5
F0095194: 88100015                 mov     %l5, %g4
F0095198: c12d6080                 st      %fsr, [%l5+0x80]
F009519C: c2056080                 ld      [%l5+0x80], %g1
F00951A0: 29000070                 sethi   0x1C000, %l4
F00951A4: 82084014                 and     %g1, %l4, %g1
F00951A8: a930600e                 srl     %g1, 14, %l4
F00951AC: 84100000                 clr     %g2
F00951B0: 07000008                 sethi   0x2000, %g3
F00951B4: a6056090                 add     %l5, 0x90, %l3
F00951B8: c2056080                 ld      [%l5+0x80], %g1
F00951BC: 8088c001                 btst    %g1, %g3
F00951C0: 02800008                 be      loc_F00951E0
F00951C4: c004c002                 ld      [%l3+%g2], %g0
F00951C8: c134c002                 stq     %f0, [%l3+%g2]
F00951CC: 01000000                 nop
F00951D0: 01000000                 nop
F00951D4: 8400a008                 inc     8, %g2
F00951D8: 10bffff8                 ba      loc_F00951B8
F00951DC: c12d6080                 st      %fsr, [%l5+0x80]
F00951E0: 818c2020                 saved
F00951E4: 80a52004                 cmp     %l4, 4
F00951E8: 26800006                 bl,a    loc_F0095200
F00951EC: a8102090                 mov     0x90, %l4
F00951F0: 113c025590122108         set     aUnexpectedFloa, %o0! "unexpected floating point exception %x"...
F00951F8: 7ffdffde                 call    _panic
F00951FC: 92100014                 mov     %l4, %o1
F0095200: ad30a003                 srl     %g2, 3, %l6
F0095204: ec25608c                 st      %l6, [%l5+0x8C]
F0095208: 40000eea                 call    _fp_runq
F009520C: 9003a05c                 add     %sp, arg_5C, %o0
F0095210: d0056080                 ld      [%l5+0x80], %o0
F0095214: 13000078                 sethi   0x1E000, %o1
F0095218: 902a0009                 bclr    %o1, %o0
F009521C: d0256080                 st      %o0, [%l5+0x80]
F0095220: 10bdb8a0                 ba      sys_rtt
F0095224: c10d6080                 ld      [%l5+0x80], %fsr
