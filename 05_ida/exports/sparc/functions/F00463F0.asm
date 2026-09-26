F00463F0: 9de3bf98                 save    %sp, -0x68, %sp
F00463F4: 90100018                 mov     %i0, %o0! XDR *
F00463F8: 92100019                 mov     %i1, %o1! char **
F00463FC: 7ffffd80                 call    _xdr_string
F0046400: 94102020                 mov     0x20, %o2 ! ' '
F0046404: 80a00008                 cmp     %g0, %o0
F0046408: b0402000                 addc    %g0, 0, %i0
F004640C: 81c7e008                 ret
F0046410: 81e80000                 restore
