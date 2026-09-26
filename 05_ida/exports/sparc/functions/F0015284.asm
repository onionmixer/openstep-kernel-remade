F0015284: 9de3bf98                 save    %sp, -0x68, %sp
F0015288: 113c042d90122138         set     aSDCHardErrorSn, %o0! "%s%d%c: hard error sn%d "
F0015290: d616201e                 lduh    [%i0+0x1E], %o3
F0015294: 92100019                 mov     %i1, %o1
F0015298: d8062024                 ld      [%i0+0x24], %o4
F001529C: 940ae0ff                 and     %o3, 0xFF, %o2
F00152A0: 960ae007                 and     %o3, 7, %o3
F00152A4: 9532a003                 srl     %o2, 3, %o2
F00152A8: 7ffffcec                 call    _printf
F00152AC: 9602e061                 inc     0x61, %o3 ! 'a'
F00152B0: 81c7e008                 ret
F00152B4: 81e80000                 restore
