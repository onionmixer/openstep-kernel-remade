F00DA9BC: 9de3bf90                 save    %sp, -0x70, %sp
F00DA9C0: c6062014                 ld      [%i0+0x14], %g3
F00DA9C4: 80a0e000                 cmp     %g3, 0
F00DA9C8: 02800005                 be      locret_F00DA9DC
F00DA9CC: b0102001                 mov     1, %i0
F00DA9D0: 841e8003                 xor     %i2, %g3, %g2
F00DA9D4: 80a00002                 cmp     %g0, %g2
F00DA9D8: b0603fff                 subc    %g0, -1, %i0
F00DA9DC: 81c7e008                 ret
F00DA9E0: 81e80000                 restore
