F00F1C94: 9de3bf98                 save    %sp, -0x68, %sp
F00F1C98: d4066008                 ld      [%i1+8], %o2
F00F1C9C: d606a008                 ld      [%i2+8], %o3
F00F1CA0: d24a8000                 ldsb    [%o2], %o1! __s2
F00F1CA4: d04ac000                 ldsb    [%o3], %o0
F00F1CA8: 80a24008                 cmp     %o1, %o0
F00F1CAC: 12800007                 bne     locret_F00F1CC8
F00F1CB0: b0102000                 mov     0, %i0
F00F1CB4: 9010000a                 mov     %o2, %o0! __s1
F00F1CB8: 7ffc593d                 call    _strcmp
F00F1CBC: 9210000b                 mov     %o3, %o1
F00F1CC0: 80a00008                 cmp     %g0, %o0
F00F1CC4: b0603fff                 subc    %g0, -1, %i0
F00F1CC8: 81c7e008                 ret
F00F1CCC: 81e80000                 restore
