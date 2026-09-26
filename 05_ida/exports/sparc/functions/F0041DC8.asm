F0041DC8: 9de3bf98                 save    %sp, -0x68, %sp
F0041DCC: 90100018                 mov     %i0, %o0! XDR *
F0041DD0: 40000dc7                 call    _xdr_u_long
F0041DD4: 92100019                 mov     %i1, %o1! unsigned __int32 *
F0041DD8: 80a22000                 cmp     %o0, 0
F0041DDC: 0280001b                 be      loc_F0041E48
F0041DE0: 90100018                 mov     %i0, %o0! XDR *
F0041DE4: 40000dc2                 call    _xdr_u_long
F0041DE8: 92066004                 add     %i1, 4, %o1! unsigned __int32 *
F0041DEC: 80a22000                 cmp     %o0, 0
F0041DF0: 02800016                 be      loc_F0041E48
F0041DF4: 90100018                 mov     %i0, %o0! XDR *
F0041DF8: 40000dbd                 call    _xdr_u_long
F0041DFC: 92066008                 add     %i1, 8, %o1! unsigned __int32 *
F0041E00: 80a22000                 cmp     %o0, 0
F0041E04: 02800011                 be      loc_F0041E48
F0041E08: 90100018                 mov     %i0, %o0! XDR *
F0041E0C: 40000db8                 call    _xdr_u_long
F0041E10: 9206600c                 add     %i1, 0xC, %o1
F0041E14: 80a22000                 cmp     %o0, 0
F0041E18: 0280000c                 be      loc_F0041E48
F0041E1C: 90100018                 mov     %i0, %o0
F0041E20: 40000126                 call    sub_F00422B8
F0041E24: 92066010                 add     %i1, 0x10, %o1
F0041E28: 80a22000                 cmp     %o0, 0
F0041E2C: 02800007                 be      loc_F0041E48
F0041E30: 90100018                 mov     %i0, %o0
F0041E34: 40000121                 call    sub_F00422B8
F0041E38: 92066018                 add     %i1, 0x18, %o1
F0041E3C: 80a22000                 cmp     %o0, 0
F0041E40: 12800003                 bne     locret_F0041E4C
F0041E44: b0102001                 mov     1, %i0
F0041E48: b0102000                 mov     0, %i0
F0041E4C: 81c7e008                 ret
F0041E50: 81e80000                 restore
