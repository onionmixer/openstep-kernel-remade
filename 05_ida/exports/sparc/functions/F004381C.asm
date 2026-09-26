F004381C: 9de3bf98                 save    %sp, -0x68, %sp
F0043820: 90100018                 mov     %i0, %o0! XDR *
F0043824: 40000732                 call    _xdr_u_long
F0043828: 92100019                 mov     %i1, %o1! unsigned __int32 *
F004382C: 80a22000                 cmp     %o0, 0
F0043830: 02800010                 be      loc_F0043870
F0043834: 90100018                 mov     %i0, %o0! XDR *
F0043838: 4000072d                 call    _xdr_u_long
F004383C: 92066004                 add     %i1, 4, %o1! unsigned __int32 *
F0043840: 80a22000                 cmp     %o0, 0
F0043844: 0280000b                 be      loc_F0043870
F0043848: 90100018                 mov     %i0, %o0! XDR *
F004384C: 40000728                 call    _xdr_u_long
F0043850: 92066008                 add     %i1, 8, %o1! unsigned __int32 *
F0043854: 80a22000                 cmp     %o0, 0
F0043858: 02800006                 be      loc_F0043870
F004385C: 90100018                 mov     %i0, %o0! XDR *
F0043860: 40000723                 call    _xdr_u_long
F0043864: 9206600c                 add     %i1, 0xC, %o1
F0043868: 10800003                 ba      locret_F0043874
F004386C: b0100008                 mov     %o0, %i0
F0043870: b0102000                 mov     0, %i0
F0043874: 81c7e008                 ret
F0043878: 81e80000                 restore
