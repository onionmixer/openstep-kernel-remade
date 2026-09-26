F0089F4C: 9de3bf90                 save    %sp, -0x70, %sp! int
F0089F50: f22fbff7                 stb     %i1, [%fp+var_9]
F0089F54: 9007bff7                 add     %fp, var_9, %o0! int
F0089F58: 92100018                 mov     %i0, %o1! int
F0089F5C: 4000385c                 call    _copyout
F0089F60: 94102001                 mov     1, %o2
F0089F64: 80a00008                 cmp     %g0, %o0
F0089F68: b0602000                 subc    %g0, 0, %i0
F0089F6C: 81c7e008                 ret
F0089F70: 81e80000                 restore
