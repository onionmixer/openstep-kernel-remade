F00F0900: 9de3bf98                 save    %sp, -0x68, %sp
F00F0904: f427a04c                 st      %i2, [%fp+arg_4C]
F00F0908: f627a050                 st      %i3, [%fp+arg_50]
F00F090C: f827a054                 st      %i4, [%fp+arg_54]
F00F0910: fa27a058                 st      %i5, [%fp+arg_58]
F00F0914: a007a04c                 add     %fp, arg_4C, %l0
F00F0918: 113c04bc                 sethi   %hi(__error), %o0
F00F091C: d6022100                 ld      [%o0+%lo(__error)], %o3
F00F0920: 90100018                 mov     %i0, %o0
F00F0924: 92100019                 mov     %i1, %o1
F00F0928: 9fc2c000                 call    %o3
F00F092C: 94100010                 mov     %l0, %o2
F00F0930: 90100018                 mov     %i0, %o0
F00F0934: 92100019                 mov     %i1, %o1
F00F0938: 4000001a                 call    __objc_error
F00F093C: 94100010                 mov     %l0, %o2
F00F0940: 81c7e008                 ret
F00F0944: 81e80000                 restore
