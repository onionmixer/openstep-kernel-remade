F0014658: 9de3bf98                 save    %sp, -0x68, %sp
F001465C: f227a048                 st      %i1, [%fp+arg_48]
F0014660: f427a04c                 st      %i2, [%fp+arg_4C]
F0014664: f627a050                 st      %i3, [%fp+arg_50]
F0014668: f827a054                 st      %i4, [%fp+arg_54]
F001466C: fa27a058                 st      %i5, [%fp+arg_58]
F0014670: 90100018                 mov     %i0, %o0
F0014674: 9207a048                 add     %fp, arg_48, %o1
F0014678: 94102005                 mov     5, %o2
F001467C: 40000094                 call    _prf
F0014680: 96102000                 mov     0, %o3
F0014684: 80a22000                 cmp     %o0, 0
F0014688: 02800004                 be      locret_F0014698
F001468C: 01000000                 nop
F0014690: 7fffff79                 call    _logwakeup
F0014694: 01000000                 nop
F0014698: 81c7e008                 ret
F001469C: 91e82000                 restore %g0, 0, %o0
