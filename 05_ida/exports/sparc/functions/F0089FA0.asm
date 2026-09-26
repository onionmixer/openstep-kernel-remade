F0089FA0: 9de3bf90                 save    %sp, -0x70, %sp! int
F0089FA4: 90100018                 mov     %i0, %o0! int
F0089FA8: 9207bff7                 add     %fp, var_9, %o1! int
F0089FAC: 4000382b                 call    _copyin
F0089FB0: 94102001                 mov     1, %o2
F0089FB4: 80a22000                 cmp     %o0, 0
F0089FB8: 12800003                 bne     locret_F0089FC4
F0089FBC: b0103fff                 mov     -1, %i0
F0089FC0: f04fbff7                 ldsb    [%fp+var_9], %i0
F0089FC4: 81c7e008                 ret
F0089FC8: 81e80000                 restore
