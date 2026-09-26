F00B0BC4: 9de3bf98                 save    %sp, -0x68, %sp
F00B0BC8: 90100018                 mov     %i0, %o0! __s1
F00B0BCC: 133c0471                 sethi   %hi(aSbus_0), %o1! "sbus"
F00B0BD0: 7ffd5d77                 call    _strcmp
F00B0BD4: 92126160                 bset    %lo(aSbus_0), %o1! "sbus"
F00B0BD8: 80a00008                 cmp     %g0, %o0
F00B0BDC: b0603fff                 subc    %g0, -1, %i0
F00B0BE0: 81c7e008                 ret
F00B0BE4: 81e80000                 restore
