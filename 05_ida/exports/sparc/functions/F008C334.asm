F008C334: 9de3bf98                 save    %sp, -0x68, %sp
F008C338: f427a04c                 st      %i2, [%fp+arg_4C]
F008C33C: f627a050                 st      %i3, [%fp+arg_50]
F008C340: f827a054                 st      %i4, [%fp+arg_54]
F008C344: 40002a11                 call    _splusclock
F008C348: fa27a058                 st      %i5, [%fp+arg_58]
F008C34C: a0100008                 mov     %o0, %l0
F008C350: 90102003                 mov     3, %o0
F008C354: 92100019                 mov     %i1, %o1
F008C358: 7ffe2137                 call    _vlog
F008C35C: 9407a04c                 add     %fp, arg_4C, %o2
F008C360: 40002a71                 call    _splx
F008C364: 90100010                 mov     %l0, %o0
F008C368: 81c7e008                 ret
F008C36C: 81e80000                 restore
