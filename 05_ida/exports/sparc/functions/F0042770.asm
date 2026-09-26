F0042770: 9de3bf98                 save    %sp, -0x68, %sp
F0042774: 90100018                 mov     %i0, %o0! XDR *
F0042778: 40000b5d                 call    _xdr_u_long
F004277C: 92100019                 mov     %i1, %o1
F0042780: 80a22000                 cmp     %o0, 0
F0042784: 0280001c                 be      loc_F00427F4
F0042788: 90100018                 mov     %i0, %o0! XDR *
F004278C: 92066004                 add     %i1, 4, %o1! char **
F0042790: 40000c9b                 call    _xdr_string
F0042794: 941020ff                 mov     0xFF, %o2
F0042798: 80a22000                 cmp     %o0, 0
F004279C: 02800016                 be      loc_F00427F4
F00427A0: 90100018                 mov     %i0, %o0! XDR *
F00427A4: 40000b2c                 call    _xdr_int
F00427A8: 92066008                 add     %i1, 8, %o1! int *
F00427AC: 80a22000                 cmp     %o0, 0
F00427B0: 02800011                 be      loc_F00427F4
F00427B4: 90100018                 mov     %i0, %o0! XDR *
F00427B8: 40000b27                 call    _xdr_int
F00427BC: 9206600c                 add     %i1, 0xC, %o1
F00427C0: 80a22000                 cmp     %o0, 0
F00427C4: 0280000c                 be      loc_F00427F4
F00427C8: 90100018                 mov     %i0, %o0! XDR *
F00427CC: 92066014                 add     %i1, 0x14, %o1! char **
F00427D0: 94066010                 add     %i1, 0x10, %o2! unsigned int *
F00427D4: 1b3c0115                 sethi   %hi(_xdr_int), %o5! xdrproc_t
F00427D8: 96102010                 mov     0x10, %o3! unsigned int
F00427DC: 98102004                 mov     4, %o4! unsigned int
F00427E0: 40000cc8                 call    _xdr_array
F00427E4: 9a136054                 bset    %lo(_xdr_int), %o5
F00427E8: 80a22000                 cmp     %o0, 0
F00427EC: 12800003                 bne     locret_F00427F8
F00427F0: b0102001                 mov     1, %i0
F00427F4: b0102000                 mov     0, %i0
F00427F8: 81c7e008                 ret
F00427FC: 81e80000                 restore
