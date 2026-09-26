F00EB99C: 9de3bf90                 save    %sp, -0x70, %sp
F00EB9A0: d2060000                 ld      [%i0], %o1! __s2
F00EB9A4: 9010001a                 mov     %i2, %o0! __s1
F00EB9A8: 7ffc7201                 call    _strcmp
F00EB9AC: d2026008                 ld      [%o1+8], %o1
F00EB9B0: 80a00008                 cmp     %g0, %o0
F00EB9B4: b0603fff                 subc    %g0, -1, %i0
F00EB9B8: 81c7e008                 ret
F00EB9BC: 81e80000                 restore
