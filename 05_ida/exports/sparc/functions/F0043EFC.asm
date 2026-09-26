F0043EFC: 9de3bf98                 save    %sp, -0x68, %sp
F0043F00: 90100018                 mov     %i0, %o0! XDR *
F0043F04: 40000611                 call    _xdr_enum
F0043F08: 92100019                 mov     %i1, %o1! unsigned __int32 *
F0043F0C: 80a22000                 cmp     %o0, 0
F0043F10: 22800019                 be,a    locret_F0043F74
F0043F14: b0102000                 mov     0, %i0
F0043F18: d0064000                 ld      [%i1], %o0
F0043F1C: 80a22000                 cmp     %o0, 0
F0043F20: 02800006                 be      loc_F0043F38
F0043F24: 80a22001                 cmp     %o0, 1
F0043F28: 0280000e                 be      loc_F0043F60
F0043F2C: 90100018                 mov     %i0, %o0
F0043F30: 10800011                 ba      locret_F0043F74
F0043F34: b0102000                 mov     0, %i0
F0043F38: 90100018                 mov     %i0, %o0! XDR *
F0043F3C: 4000056c                 call    _xdr_u_long
F0043F40: 92066004                 add     %i1, 4, %o1! unsigned __int32 *
F0043F44: 80a22000                 cmp     %o0, 0
F0043F48: 0280000a                 be      loc_F0043F70
F0043F4C: 90100018                 mov     %i0, %o0! XDR *
F0043F50: 40000567                 call    _xdr_u_long
F0043F54: 92066008                 add     %i1, 8, %o1! int *
F0043F58: 10800007                 ba      locret_F0043F74
F0043F5C: b0100008                 mov     %o0, %i0
F0043F60: 400005fa                 call    _xdr_enum
F0043F64: 92066004                 add     %i1, 4, %o1
F0043F68: 10800003                 ba      locret_F0043F74
F0043F6C: b0100008                 mov     %o0, %i0
F0043F70: b0102000                 mov     0, %i0
F0043F74: 81c7e008                 ret
F0043F78: 81e80000                 restore
