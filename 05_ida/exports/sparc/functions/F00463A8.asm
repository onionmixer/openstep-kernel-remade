F00463A8: 9de3bf98                 save    %sp, -0x68, %sp
F00463AC: 90100018                 mov     %i0, %o0! XDR *
F00463B0: 92100019                 mov     %i1, %o1! char **
F00463B4: 7ffffd92                 call    _xdr_string
F00463B8: 941020ff                 mov     0xFF, %o2
F00463BC: 80a00008                 cmp     %g0, %o0
F00463C0: b0402000                 addc    %g0, 0, %i0
F00463C4: 81c7e008                 ret
F00463C8: 81e80000                 restore
