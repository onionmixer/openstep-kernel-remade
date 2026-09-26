F0041A8C: 9de3bf98                 save    %sp, -0x68, %sp
F0041A90: 90100018                 mov     %i0, %o0! XDR *
F0041A94: 7fffff02                 call    _xdr_fhandle
F0041A98: 92100019                 mov     %i1, %o1! __int32 *
F0041A9C: 80a22000                 cmp     %o0, 0
F0041AA0: 02800011                 be      loc_F0041AE4
F0041AA4: 90100018                 mov     %i0, %o0! XDR *
F0041AA8: 40000e77                 call    _xdr_long
F0041AAC: 92066020                 add     %i1, 0x20, %o1 ! ' '! __int32 *
F0041AB0: 80a22000                 cmp     %o0, 0
F0041AB4: 0280000c                 be      loc_F0041AE4
F0041AB8: 90100018                 mov     %i0, %o0! XDR *
F0041ABC: 40000e72                 call    _xdr_long
F0041AC0: 92066024                 add     %i1, 0x24, %o1 ! '$'! __int32 *
F0041AC4: 80a22000                 cmp     %o0, 0
F0041AC8: 02800007                 be      loc_F0041AE4
F0041ACC: 90100018                 mov     %i0, %o0! XDR *
F0041AD0: 40000e6d                 call    _xdr_long
F0041AD4: 92066028                 add     %i1, 0x28, %o1 ! '('
F0041AD8: 80a22000                 cmp     %o0, 0
F0041ADC: 12800003                 bne     locret_F0041AE8
F0041AE0: b0102001                 mov     1, %i0
F0041AE4: b0102000                 mov     0, %i0
F0041AE8: 81c7e008                 ret
F0041AEC: 81e80000                 restore
