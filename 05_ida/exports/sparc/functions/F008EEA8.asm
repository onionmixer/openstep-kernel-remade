F008EEA8: 9de3bf98                 save    %sp, -0x68, %sp
F008EEAC: 90100018                 mov     %i0, %o0! __s1
F008EEB0: 133c0448                 sethi   %hi(aIrqLevels_0), %o1! "IRQ Levels"
F008EEB4: 7ffde4be                 call    _strcmp
F008EEB8: 92126070                 bset    %lo(aIrqLevels_0), %o1! "IRQ Levels"
F008EEBC: 80a00008                 cmp     %g0, %o0
F008EEC0: b0603fff                 subc    %g0, -1, %i0
F008EEC4: 81c7e008                 ret
F008EEC8: 81e80000                 restore
