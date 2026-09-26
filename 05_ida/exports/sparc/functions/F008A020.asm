F008A020: 9de3bf98                 save    %sp, -0x68, %sp! int
F008A024: f227a048                 st      %i1, [%fp+arg_48]
F008A028: 9007a048                 add     %fp, arg_48, %o0! int
F008A02C: 92100018                 mov     %i0, %o1! int
F008A030: 40003827                 call    _copyout
F008A034: 94102004                 mov     4, %o2
F008A038: 80a00008                 cmp     %g0, %o0
F008A03C: b0602000                 subc    %g0, 0, %i0
F008A040: 81c7e008                 ret
F008A044: 81e80000                 restore
