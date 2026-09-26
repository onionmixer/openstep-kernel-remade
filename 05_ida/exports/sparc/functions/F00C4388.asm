F00C4388: 9de3bf98                 save    %sp, -0x68, %sp
F00C438C: 90100018                 mov     %i0, %o0! __s1
F00C4390: 133c04ba                 sethi   %hi(aIrqLevels_5), %o1! "IRQ Levels"
F00C4394: 7ffd0f86                 call    _strcmp
F00C4398: 92126240                 bset    %lo(aIrqLevels_5), %o1! "IRQ Levels"
F00C439C: 80a00008                 cmp     %g0, %o0
F00C43A0: b0603fff                 subc    %g0, -1, %i0
F00C43A4: 81c7e008                 ret
F00C43A8: 81e80000                 restore
