F0015254: 9de3bf98                 save    %sp, -0x68, %sp
F0015258: 113c042d90122108         set     aSTableIsFull, %o0! "%s: table is full\n"
F0015260: 7ffffcfe                 call    _printf
F0015264: 92100018                 mov     %i0, %o1
F0015268: 90102003                 mov     3, %o0! __x
F001526C: 133c042d92126120         set     aSTableIsFull_0, %o1! "%s: table is full\n"
F0015274: 7ffffd50                 call    _log
F0015278: 94100018                 mov     %i0, %o2
F001527C: 81c7e008                 ret
F0015280: 81e80000                 restore
