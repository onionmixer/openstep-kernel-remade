F00B302C: 9de3bf98                 save    %sp, -0x68, %sp
F00B3030: 7fffffb0                 call    _path_to_devi
F00B3034: 90100018                 mov     %i0, %o0
F00B3038: 80a22000                 cmp     %o0, 0
F00B303C: 02800003                 be      locret_F00B3048
F00B3040: b0103fff                 mov     -1, %i0
F00B3044: f0022028                 ld      [%o0+0x28], %i0
F00B3048: 81c7e008                 ret
F00B304C: 81e80000                 restore
