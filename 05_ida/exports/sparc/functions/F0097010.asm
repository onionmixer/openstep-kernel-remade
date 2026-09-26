F0097010: 033c0464                 sethi   %hi(_cache), %g1
F0097014: c2006330                 ld      [%g1+%lo(_cache)], %g1
F0097018: 80a06003                 cmp     %g1, 3
F009701C: 32800012                 bne,a   locret_F0097064
F0097020: f0fe4400                 swapa   [%i1]0x20, %i0
F0097024: 9b480000                 rdhpr   %hpstate, %o5
F0097028: 822b6020                 andn    %o5, 0x20, %g1
F009702C: 81884000                 saved
F0097030: 01000000                 nop
F0097034: 01000000                 nop
F0097038: 01000000                 nop
F009703C: d8800080                 lda     [%g0]#ASI_NUCLEUS, %o4
F0097040: 0300002082130001         set     0x8000, %g1
F0097048: c2a00080                 sta     %g1, [%g0]#ASI_NUCLEUS
F009704C: d0fa4400                 swapa   [%o1]0x20, %o0
F0097050: d8a00080                 sta     %o4, [%g0]#ASI_NUCLEUS
F0097054: 818b4000                 saved
F0097058: 01000000                 nop
F009705C: 01000000                 nop
F0097060: 01000000                 nop
F0097064: 81c3e008                 retl
F0097068: 01000000                 nop
