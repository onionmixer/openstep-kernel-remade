F0041D94: 9de3bf98                 save    %sp, -0x68, %sp
F0041D98: 92100019                 mov     %i1, %o1! int *
F0041D9C: 90100018                 mov     %i0, %o0! XDR *
F0041DA0: 173c0436                 sethi   %hi(_rdres_discrim), %o3
F0041DA4: 193c0115                 sethi   %hi(_xdr_void), %o4! xdrproc_t
F0041DA8: 94026004                 add     %o1, 4, %o2! char *
F0041DAC: 9612e134                 bset    %lo(_rdres_discrim), %o3! xdr_discrim *
F0041DB0: 40000eea                 call    _xdr_union
F0041DB4: 98132048                 bset    %lo(_xdr_void), %o4
F0041DB8: 80a00008                 cmp     %g0, %o0
F0041DBC: b0402000                 addc    %g0, 0, %i0
F0041DC0: 81c7e008                 ret
F0041DC4: 81e80000                 restore
