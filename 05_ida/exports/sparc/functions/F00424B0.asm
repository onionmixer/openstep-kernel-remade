F00424B0: 9de3bf98                 save    %sp, -0x68, %sp
F00424B4: 92100019                 mov     %i1, %o1! int *
F00424B8: 90100018                 mov     %i0, %o0! XDR *
F00424BC: 173c0436                 sethi   %hi(_statfs_discrim), %o3
F00424C0: 193c0115                 sethi   %hi(_xdr_void), %o4! xdrproc_t
F00424C4: 94026004                 add     %o1, 4, %o2! char *
F00424C8: 9612e174                 bset    %lo(_statfs_discrim), %o3! xdr_discrim *
F00424CC: 40000d23                 call    _xdr_union
F00424D0: 98132048                 bset    %lo(_xdr_void), %o4
F00424D4: 80a00008                 cmp     %g0, %o0
F00424D8: b0402000                 addc    %g0, 0, %i0
F00424DC: 81c7e008                 ret
F00424E0: 81e80000                 restore
