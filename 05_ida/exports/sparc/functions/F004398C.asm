F004398C: 9de3bf90                 save    %sp, -0x70, %sp
F0043990: 90100018                 mov     %i0, %o0! XDR *
F0043994: d4064000                 ld      [%i1], %o2! unsigned int
F0043998: 9207bff4                 add     %fp, var_C, %o1! char **
F004399C: 173c01159612e0ec         set     _xdr_u_long, %o3! xdrproc_t
F00439A4: d427bff4                 st      %o2, [%fp+var_C]
F00439A8: 40000a5f                 call    _xdr_reference
F00439AC: 94102004                 mov     4, %o2
F00439B0: 80a22000                 cmp     %o0, 0
F00439B4: 0280000e                 be      loc_F00439EC
F00439B8: 90100018                 mov     %i0, %o0! XDR *
F00439BC: 400006cc                 call    _xdr_u_long
F00439C0: 92066004                 add     %i1, 4, %o1
F00439C4: 80a22000                 cmp     %o0, 0
F00439C8: 02800009                 be      loc_F00439EC
F00439CC: d607bff4                 ld      [%fp+var_C], %o3
F00439D0: d2066008                 ld      [%i1+8], %o1
F00439D4: 90100018                 mov     %i0, %o0
F00439D8: d406600c                 ld      [%i1+0xC], %o2
F00439DC: 9fc28000                 call    %o2
F00439E0: d6264000                 st      %o3, [%i1]
F00439E4: 10800003                 ba      locret_F00439F0
F00439E8: b0100008                 mov     %o0, %i0
F00439EC: b0102000                 mov     0, %i0
F00439F0: 81c7e008                 ret
F00439F4: 81e80000                 restore
