F0042438: 9de3bf98                 save    %sp, -0x68, %sp
F004243C: 90100018                 mov     %i0, %o0! XDR *
F0042440: 40000c11                 call    _xdr_long
F0042444: 92100019                 mov     %i1, %o1! __int32 *
F0042448: 80a22000                 cmp     %o0, 0
F004244C: 02800016                 be      loc_F00424A4
F0042450: 90100018                 mov     %i0, %o0! XDR *
F0042454: 40000c0c                 call    _xdr_long
F0042458: 92066004                 add     %i1, 4, %o1! __int32 *
F004245C: 80a22000                 cmp     %o0, 0
F0042460: 02800011                 be      loc_F00424A4
F0042464: 90100018                 mov     %i0, %o0! XDR *
F0042468: 40000c07                 call    _xdr_long
F004246C: 92066008                 add     %i1, 8, %o1! __int32 *
F0042470: 80a22000                 cmp     %o0, 0
F0042474: 0280000c                 be      loc_F00424A4
F0042478: 90100018                 mov     %i0, %o0! XDR *
F004247C: 40000c02                 call    _xdr_long
F0042480: 9206600c                 add     %i1, 0xC, %o1! __int32 *
F0042484: 80a22000                 cmp     %o0, 0
F0042488: 02800007                 be      loc_F00424A4
F004248C: 90100018                 mov     %i0, %o0! XDR *
F0042490: 40000bfd                 call    _xdr_long
F0042494: 92066010                 add     %i1, 0x10, %o1
F0042498: 80a22000                 cmp     %o0, 0
F004249C: 12800003                 bne     locret_F00424A8
F00424A0: b0102001                 mov     1, %i0
F00424A4: b0102000                 mov     0, %i0
F00424A8: 81c7e008                 ret
F00424AC: 81e80000                 restore
