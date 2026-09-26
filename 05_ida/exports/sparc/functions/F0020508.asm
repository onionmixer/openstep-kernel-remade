F0020508: 9de3bf98                 save    %sp, -0x68, %sp
F002050C: 40000166                 call    _sbflush
F0020510: 90100018                 mov     %i0, %o0
F0020514: c0362006                 clrh    [%i0+6]
F0020518: 4001d9a8                 call    _spltty
F002051C: c0362002                 clrh    [%i0+2]
F0020520: d2062010                 ld      [%i0+0x10], %o1
F0020524: 80a26000                 cmp     %o1, 0
F0020528: 02800004                 be      loc_F0020538
F002052C: a0100008                 mov     %o0, %l0
F0020530: 7fffd6e9                 call    _selthreadclear
F0020534: 90062010                 add     %i0, 0x10, %o0
F0020538: 4001d9fb                 call    _splx
F002053C: 90100010                 mov     %l0, %o0
F0020540: 81c7e008                 ret
F0020544: 81e80000                 restore
