F0041EE4: 9de3bf98                 save    %sp, -0x68, %sp
F0041EE8: 90100018                 mov     %i0, %o0! XDR *
F0041EEC: 7ffffdec                 call    _xdr_fhandle
F0041EF0: 92100019                 mov     %i1, %o1! unsigned __int32 *
F0041EF4: 80a22000                 cmp     %o0, 0
F0041EF8: 0280000c                 be      loc_F0041F28
F0041EFC: 90100018                 mov     %i0, %o0! XDR *
F0041F00: 40000d7b                 call    _xdr_u_long
F0041F04: 92066020                 add     %i1, 0x20, %o1 ! ' '! unsigned __int32 *
F0041F08: 80a22000                 cmp     %o0, 0
F0041F0C: 02800007                 be      loc_F0041F28
F0041F10: 90100018                 mov     %i0, %o0! XDR *
F0041F14: 40000d76                 call    _xdr_u_long
F0041F18: 92066024                 add     %i1, 0x24, %o1 ! '$'
F0041F1C: 80a22000                 cmp     %o0, 0
F0041F20: 12800003                 bne     locret_F0041F2C
F0041F24: b0102001                 mov     1, %i0
F0041F28: b0102000                 mov     0, %i0
F0041F2C: 81c7e008                 ret
F0041F30: 81e80000                 restore
