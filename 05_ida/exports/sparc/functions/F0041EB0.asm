F0041EB0: 9de3bf98                 save    %sp, -0x68, %sp
F0041EB4: 92100019                 mov     %i1, %o1! int *
F0041EB8: 90100018                 mov     %i0, %o0! XDR *
F0041EBC: 173c0436                 sethi   %hi(_rdlnres_discrim), %o3
F0041EC0: 193c0115                 sethi   %hi(_xdr_void), %o4! xdrproc_t
F0041EC4: 94026004                 add     %o1, 4, %o2! char *
F0041EC8: 9612e154                 bset    %lo(_rdlnres_discrim), %o3! xdr_discrim *
F0041ECC: 40000ea3                 call    _xdr_union
F0041ED0: 98132048                 bset    %lo(_xdr_void), %o4
F0041ED4: 80a00008                 cmp     %g0, %o0
F0041ED8: b0402000                 addc    %g0, 0, %i0
F0041EDC: 81c7e008                 ret
F0041EE0: 81e80000                 restore
