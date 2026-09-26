F00C4750: 9de3bf98                 save    %sp, -0x68, %sp
F00C4754: 86100018                 mov     %i0, %g3
F00C4758: 053c04cc                 sethi   %hi(dword_F0133034), %g2
F00C475C: f000a034                 ld      [%g2+%lo(dword_F0133034)], %i0
F00C4760: 8410a034                 bset    %lo(dword_F0133034), %g2
F00C4764: 80a60002                 cmp     %i0, %g2
F00C4768: 2280000c                 be,a    locret_F00C4798
F00C476C: b0102000                 mov     0, %i0
F00C4770: b2100002                 mov     %g2, %i1
F00C4774: c4060000                 ld      [%i0], %g2
F00C4778: 80a08003                 cmp     %g2, %g3
F00C477C: 02800007                 be      locret_F00C4798
F00C4780: 01000000                 nop
F00C4784: f0062008                 ld      [%i0+8], %i0
F00C4788: 80a60019                 cmp     %i0, %i1
F00C478C: 32bffffb                 bne,a   loc_F00C4778
F00C4790: c4060000                 ld      [%i0], %g2
F00C4794: b0102000                 mov     0, %i0
F00C4798: 81c7e008                 ret
F00C479C: 81e80000                 restore
