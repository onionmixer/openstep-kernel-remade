F00BCAAC: 9de3bf90                 save    %sp, -0x70, %sp
F00BCAB0: c4062114                 ld      [%i0+0x114], %g2
F00BCAB4: 80a0a001                 cmp     %g2, 1
F00BCAB8: 12800003                 bne     locret_F00BCAC4
F00BCABC: 84102004                 mov     4, %g2
F00BCAC0: c4262114                 st      %g2, [%i0+0x114]
F00BCAC4: 81c7e008                 ret
F00BCAC8: 91e82000                 restore %g0, 0, %o0
