F0045668: 9de3bf90                 save    %sp, -0x70, %sp
F004566C: d24e4000                 ldsb    [%i1], %o1! int *
F0045670: 90100018                 mov     %i0, %o0! XDR *
F0045674: d227bff4                 st      %o1, [%fp+var_C]
F0045678: 7fffff77                 call    _xdr_int
F004567C: 9207bff4                 add     %fp, var_C, %o1
F0045680: 80a22000                 cmp     %o0, 0
F0045684: 02800005                 be      loc_F0045698
F0045688: d007bff4                 ld      [%fp+var_C], %o0
F004568C: b0102001                 mov     1, %i0
F0045690: 10800003                 ba      locret_F004569C
F0045694: d02e4000                 stb     %o0, [%i1]
F0045698: b0102000                 mov     0, %i0
F004569C: 81c7e008                 ret
F00456A0: 81e80000                 restore
