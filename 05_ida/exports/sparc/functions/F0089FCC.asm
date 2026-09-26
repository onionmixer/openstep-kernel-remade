F0089FCC: 9de3bf98                 save    %sp, -0x68, %sp! int
F0089FD0: f227a048                 st      %i1, [%fp+arg_48]
F0089FD4: 9007a048                 add     %fp, arg_48, %o0! int
F0089FD8: 92100018                 mov     %i0, %o1! int
F0089FDC: 4000383c                 call    _copyout
F0089FE0: 94102004                 mov     4, %o2
F0089FE4: 80a00008                 cmp     %g0, %o0
F0089FE8: b0602000                 subc    %g0, 0, %i0
F0089FEC: 81c7e008                 ret
F0089FF0: 81e80000                 restore
