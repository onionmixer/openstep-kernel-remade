F00422B8: 9de3bf98                 save    %sp, -0x68, %sp
F00422BC: 90100018                 mov     %i0, %o0! XDR *
F00422C0: 40000c71                 call    _xdr_long
F00422C4: 92100019                 mov     %i1, %o1! __int32 *
F00422C8: 80a22000                 cmp     %o0, 0
F00422CC: 02800007                 be      loc_F00422E8
F00422D0: 90100018                 mov     %i0, %o0! XDR *
F00422D4: 40000c6c                 call    _xdr_long
F00422D8: 92066004                 add     %i1, 4, %o1
F00422DC: 80a22000                 cmp     %o0, 0
F00422E0: 12800003                 bne     locret_F00422EC
F00422E4: b0102001                 mov     1, %i0
F00422E8: b0102000                 mov     0, %i0
F00422EC: 81c7e008                 ret
F00422F0: 81e80000                 restore
