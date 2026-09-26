F0042284: 9de3bf98                 save    %sp, -0x68, %sp
F0042288: 92100019                 mov     %i1, %o1! int *
F004228C: 90100018                 mov     %i0, %o0! XDR *
F0042290: 173c0436                 sethi   %hi(_diropres_discrim), %o3
F0042294: 193c0115                 sethi   %hi(_xdr_void), %o4! xdrproc_t
F0042298: 94026004                 add     %o1, 4, %o2! char *
F004229C: 9612e164                 bset    %lo(_diropres_discrim), %o3! xdr_discrim *
F00422A0: 40000dae                 call    _xdr_union
F00422A4: 98132048                 bset    %lo(_xdr_void), %o4
F00422A8: 80a00008                 cmp     %g0, %o0
F00422AC: b0402000                 addc    %g0, 0, %i0
F00422B0: 81c7e008                 ret
F00422B4: 81e80000                 restore
