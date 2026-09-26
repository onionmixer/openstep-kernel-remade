F00C2EAC: 9de3bf98                 save    %sp, -0x68, %sp
F00C2EB0: 90100018                 mov     %i0, %o0! __s1
F00C2EB4: 133c0485                 sethi   %hi(aLedma), %o1! "ledma"
F00C2EB8: 7ffd14bd                 call    _strcmp
F00C2EBC: 92126040                 bset    %lo(aLedma), %o1! "ledma"
F00C2EC0: 80a00008                 cmp     %g0, %o0
F00C2EC4: b0603fff                 subc    %g0, -1, %i0
F00C2EC8: 81c7e008                 ret
F00C2ECC: 81e80000                 restore
