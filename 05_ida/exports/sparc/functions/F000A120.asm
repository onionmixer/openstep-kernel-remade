F000A120: 9de3bf98                 save    %sp, -0x68, %sp
F000A124: 113c043e                 sethi   %hi(_hz), %o0
F000A128: e00223e0                 ld      [%o0+%lo(_hz)], %l0
F000A12C: 90100018                 mov     %i0, %o0! int
F000A130: 7ffff136                 call    _div
F000A134: 92100010                 mov     %l0, %o1
F000A138: d0264000                 st      %o0, [%i1]
F000A13C: 90100018                 mov     %i0, %o0
F000A140: 7ffff1da                 call    _rem
F000A144: 92100010                 mov     %l0, %o1
F000A148: 133c043e                 sethi   %hi(_tick), %o1
F000A14C: 7ffff0ed                 call    _umul
F000A150: d20263e4                 ld      [%o1+%lo(_tick)], %o1
F000A154: d0266004                 st      %o0, [%i1+4]
F000A158: 81c7e008                 ret
F000A15C: 81e80000                 restore
