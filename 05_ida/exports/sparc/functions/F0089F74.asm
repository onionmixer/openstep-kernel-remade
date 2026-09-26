F0089F74: 9de3bf90                 save    %sp, -0x70, %sp! int
F0089F78: 90100018                 mov     %i0, %o0! int
F0089F7C: 9207bff7                 add     %fp, var_9, %o1! int
F0089F80: 40003836                 call    _copyin
F0089F84: 94102001                 mov     1, %o2
F0089F88: 80a22000                 cmp     %o0, 0
F0089F8C: 12800003                 bne     locret_F0089F98
F0089F90: b0103fff                 mov     -1, %i0
F0089F94: f04fbff7                 ldsb    [%fp+var_9], %i0
F0089F98: 81c7e008                 ret
F0089F9C: 81e80000                 restore
