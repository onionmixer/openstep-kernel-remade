F00F0A30: 9de3bf98                 save    %sp, -0x68, %sp
F00F0A34: f227a048                 st      %i1, [%fp+arg_48]
F00F0A38: f427a04c                 st      %i2, [%fp+arg_4C]
F00F0A3C: f627a050                 st      %i3, [%fp+arg_50]
F00F0A40: f827a054                 st      %i4, [%fp+arg_54]
F00F0A44: fa27a058                 st      %i5, [%fp+arg_58]
F00F0A48: 90102003                 mov     3, %o0! __s
F00F0A4C: 92100018                 mov     %i0, %o1
F00F0A50: 7ffc8f79                 call    _vlog
F00F0A54: 9407a048                 add     %fp, arg_48, %o2
F00F0A58: 7ffc5a78                 call    _strlen
F00F0A5C: 90100018                 mov     %i0, %o0
F00F0A60: 90020018                 add     %o0, %i0, %o0
F00F0A64: d04a3fff                 ldsb    [%o0-1], %o0
F00F0A68: 80a2200a                 cmp     %o0, 0xA
F00F0A6C: 02800005                 be      locret_F00F0A80
F00F0A70: 90102003                 mov     3, %o0! __x
F00F0A74: 133c03eb                 sethi   %hi(asc_F00FAC48), %o1! "\n"
F00F0A78: 7ffc8f4f                 call    _log
F00F0A7C: 92126048                 bset    %lo(asc_F00FAC48), %o1! "\n"
F00F0A80: 81c7e008                 ret
F00F0A84: 81e80000                 restore
