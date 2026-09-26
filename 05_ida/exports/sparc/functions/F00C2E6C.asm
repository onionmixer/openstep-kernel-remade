F00C2E6C: 9de3bf98                 save    %sp, -0x68, %sp
F00C2E70: 90100018                 mov     %i0, %o0! __s1
F00C2E74: 133c0484                 sethi   %hi(aLebuffer), %o1! "lebuffer"
F00C2E78: 7ffd14cd                 call    _strcmp
F00C2E7C: 921263f8                 bset    %lo(aLebuffer), %o1! "lebuffer"
F00C2E80: 80a00008                 cmp     %g0, %o0
F00C2E84: b0603fff                 subc    %g0, -1, %i0
F00C2E88: 81c7e008                 ret
F00C2E8C: 81e80000                 restore
