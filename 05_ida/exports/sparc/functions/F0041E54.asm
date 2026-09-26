F0041E54: 9de3bf98                 save    %sp, -0x68, %sp
F0041E58: 92100019                 mov     %i1, %o1! int *
F0041E5C: 90100018                 mov     %i0, %o0! XDR *
F0041E60: 173c0436                 sethi   %hi(_attrstat_discrim), %o3
F0041E64: 193c0115                 sethi   %hi(_xdr_void), %o4! xdrproc_t
F0041E68: 94026004                 add     %o1, 4, %o2! char *
F0041E6C: 9612e144                 bset    %lo(_attrstat_discrim), %o3! xdr_discrim *
F0041E70: 40000eba                 call    _xdr_union
F0041E74: 98132048                 bset    %lo(_xdr_void), %o4
F0041E78: 80a00008                 cmp     %g0, %o0
F0041E7C: b0402000                 addc    %g0, 0, %i0
F0041E80: 81c7e008                 ret
F0041E84: 81e80000                 restore
