F00BCE7C: 9de3bf90                 save    %sp, -0x70, %sp
F00BCE80: c4062114                 ld      [%i0+0x114], %g2
F00BCE84: 8418a001                 btog    1, %g2
F00BCE88: 80a00002                 cmp     %g0, %g2
F00BCE8C: 84603fff                 subc    %g0, -1, %g2
F00BCE90: c4268000                 st      %g2, [%i2]
F00BCE94: 81c7e008                 ret
F00BCE98: 91e82000                 restore %g0, 0, %o0
