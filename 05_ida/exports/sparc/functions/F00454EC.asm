F00454EC: 9de3bf98                 save    %sp, -0x68, %sp
F00454F0: 90100018                 mov     %i0, %o0
F00454F4: d2020000                 ld      [%o0], %o1
F00454F8: 80a26001                 cmp     %o1, 1
F00454FC: 12800005                 bne     loc_F0045510
F0045500: 80a26000                 cmp     %o1, 0
F0045504: d2022004                 ld      [%o0+4], %o1
F0045508: 10800006                 ba      loc_F0045520
F004550C: d4024000                 ld      [%o1], %o2
F0045510: 12800008                 bne     loc_F0045530
F0045514: 80a26002                 cmp     %o1, 2
F0045518: d2022004                 ld      [%o0+4], %o1
F004551C: d4026004                 ld      [%o1+4], %o2
F0045520: 9fc28000                 call    %o2
F0045524: 92100019                 mov     %i1, %o1
F0045528: 10800009                 ba      locret_F004554C
F004552C: b0100008                 mov     %o0, %i0
F0045530: 02800006                 be      loc_F0045548
F0045534: 113c0437                 sethi   %hi(aXdrULongFailed), %o0! "xdr_u_long: FAILED\n"
F0045538: 7fff3c48                 call    _printf
F004553C: 901222b0                 bset    %lo(aXdrULongFailed), %o0! "xdr_u_long: FAILED\n"
F0045540: 10800003                 ba      locret_F004554C
F0045544: b0102000                 mov     0, %i0
F0045548: b0102001                 mov     1, %i0
F004554C: 81c7e008                 ret
F0045550: 81e80000                 restore
