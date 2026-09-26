F0089F24: 9de3bf90                 save    %sp, -0x70, %sp! int
F0089F28: f22fbff7                 stb     %i1, [%fp+var_9]
F0089F2C: 9007bff7                 add     %fp, var_9, %o0! int
F0089F30: 92100018                 mov     %i0, %o1! int
F0089F34: 40003866                 call    _copyout
F0089F38: 94102001                 mov     1, %o2
F0089F3C: 80a00008                 cmp     %g0, %o0
F0089F40: b0602000                 subc    %g0, 0, %i0
F0089F44: 81c7e008                 ret
F0089F48: 81e80000                 restore
