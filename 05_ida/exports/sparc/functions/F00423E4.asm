F00423E4: 9de3bf98                 save    %sp, -0x68, %sp
F00423E8: 90100018                 mov     %i0, %o0
F00423EC: 7fffff87                 call    _xdr_diropargs
F00423F0: 92100019                 mov     %i1, %o1
F00423F4: 80a22000                 cmp     %o0, 0
F00423F8: 0280000d                 be      loc_F004242C
F00423FC: 90100018                 mov     %i0, %o0! XDR *
F0042400: 92066024                 add     %i1, 0x24, %o1 ! '$'! char **
F0042404: 40000d7e                 call    _xdr_string
F0042408: 94102400                 mov     0x400, %o2
F004240C: 80a22000                 cmp     %o0, 0
F0042410: 02800007                 be      loc_F004242C
F0042414: 90100018                 mov     %i0, %o0
F0042418: 7ffffe6c                 call    sub_F0041DC8
F004241C: 92066028                 add     %i1, 0x28, %o1 ! '('
F0042420: 80a22000                 cmp     %o0, 0
F0042424: 12800003                 bne     locret_F0042430
F0042428: b0102001                 mov     1, %i0
F004242C: b0102000                 mov     0, %i0
F0042430: 81c7e008                 ret
F0042434: 81e80000                 restore
