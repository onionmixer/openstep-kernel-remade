F00463CC: 9de3bf98                 save    %sp, -0x68, %sp
F00463D0: 90100018                 mov     %i0, %o0! XDR *
F00463D4: 92100019                 mov     %i1, %o1! char **
F00463D8: 7ffffd89                 call    _xdr_string
F00463DC: 94102400                 mov     0x400, %o2
F00463E0: 80a00008                 cmp     %g0, %o0
F00463E4: b0402000                 addc    %g0, 0, %i0
F00463E8: 81c7e008                 ret
F00463EC: 81e80000                 restore
