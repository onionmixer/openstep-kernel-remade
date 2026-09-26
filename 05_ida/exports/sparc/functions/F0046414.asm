F0046414: 9de3bf98                 save    %sp, -0x68, %sp
F0046418: 90100018                 mov     %i0, %o0! XDR *
F004641C: 7ffffc93                 call    _xdr_char
F0046420: 92100019                 mov     %i1, %o1! char *
F0046424: 80a22000                 cmp     %o0, 0
F0046428: 0280000c                 be      loc_F0046458
F004642C: 90100018                 mov     %i0, %o0! XDR *
F0046430: 7ffffc8e                 call    _xdr_char
F0046434: 92066001                 add     %i1, 1, %o1! char *
F0046438: 80a22000                 cmp     %o0, 0
F004643C: 02800007                 be      loc_F0046458
F0046440: 90100018                 mov     %i0, %o0! XDR *
F0046444: 7ffffc89                 call    _xdr_char
F0046448: 92066002                 add     %i1, 2, %o1! char *
F004644C: 80a22000                 cmp     %o0, 0
F0046450: 12800004                 bne     loc_F0046460
F0046454: 90100018                 mov     %i0, %o0! XDR *
F0046458: 10800006                 ba      locret_F0046470
F004645C: b0102000                 mov     0, %i0
F0046460: 7ffffc82                 call    _xdr_char
F0046464: 92066003                 add     %i1, 3, %o1
F0046468: 80a00008                 cmp     %g0, %o0
F004646C: b0402000                 addc    %g0, 0, %i0
F0046470: 81c7e008                 ret
F0046474: 81e80000                 restore
