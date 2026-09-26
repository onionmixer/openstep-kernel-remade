F0004ECC: 83480000                 rdhpr   %hpstate, %g1
F0004ED0: 8208601f                 and     %g1, 0x1F, %g1
F0004ED4: 073c000c                 sethi   %hi(_nwindows), %g3
F0004ED8: c600e03c                 ld      [%g3+%lo(_nwindows)], %g3
F0004EDC: 84006001                 add     %g1, 1, %g2
F0004EE0: 80a08003                 cmp     %g2, %g3
F0004EE4: 22800002                 be,a    loc_F0004EEC
F0004EE8: 84100000                 clr     %g2
F0004EEC: 86102001                 mov     1, %g3
F0004EF0: 8728c002                 sll     %g3, %g2, %g3
F0004EF4: 81c3e008                 retl
F0004EF8: 8190c000                 wrpr    %g3, %g0, %tpc
