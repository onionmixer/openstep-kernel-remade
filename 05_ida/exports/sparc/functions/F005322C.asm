F005322C: 9de3bf98                 save    %sp, -0x68, %sp
F0053230: 90100019                 mov     %i1, %o0
F0053234: d2020000                 ld      [%o0], %o1
F0053238: c0222028                 clr     [%o0+0x28]
F005323C: 92126080                 bset    0x80, %o1
F0053240: 7fff458a                 call    _brelse
F0053244: d2220000                 st      %o1, [%o0]
F0053248: 81c7e008                 ret
F005324C: 81e80000                 restore
