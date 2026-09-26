F0045938: 9de3bf98                 save    %sp, -0x68, %sp
F004593C: 94100019                 mov     %i1, %o2! unsigned int *
F0045940: 90100018                 mov     %i0, %o0! XDR *
F0045944: 9202a004                 add     %o2, 4, %o1! char **
F0045948: 7fffffc4                 call    _xdr_bytes
F004594C: 96102400                 mov     0x400, %o3
F0045950: 81c7e008                 ret
F0045954: 91e80008                 restore %g0, %o0, %o0
