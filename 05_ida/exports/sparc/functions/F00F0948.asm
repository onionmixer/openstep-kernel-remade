F00F0948: 9de3bf98                 save    %sp, -0x68, %sp
F00F094C: f227a048                 st      %i1, [%fp+arg_48]
F00F0950: f427a04c                 st      %i2, [%fp+arg_4C]
F00F0954: f627a050                 st      %i3, [%fp+arg_50]
F00F0958: f827a054                 st      %i4, [%fp+arg_54]
F00F095C: fa27a058                 st      %i5, [%fp+arg_58]
F00F0960: 90102003                 mov     3, %o0! __s
F00F0964: 92100018                 mov     %i0, %o1
F00F0968: 7ffc8fb3                 call    _vlog
F00F096C: 9407a048                 add     %fp, arg_48, %o2
F00F0970: 7ffc5ab2                 call    _strlen
F00F0974: 90100018                 mov     %i0, %o0
F00F0978: 90020018                 add     %o0, %i0, %o0
F00F097C: d04a3fff                 ldsb    [%o0-1], %o0
F00F0980: 80a2200a                 cmp     %o0, 0xA
F00F0984: 02800005                 be      locret_F00F0998
F00F0988: 90102003                 mov     3, %o0! __x
F00F098C: 133c03eb                 sethi   %hi(asc_F00FAC48), %o1! "\n"
F00F0990: 7ffc8f89                 call    _log
F00F0994: 92126048                 bset    %lo(asc_F00FAC48), %o1! "\n"
F00F0998: 81c7e008                 ret
F00F099C: 81e80000                 restore
