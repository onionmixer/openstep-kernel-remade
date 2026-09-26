F004F92C: 9de3bf90                 save    %sp, -0x70, %sp
F004F930: d2062010                 ld      [%i0+0x10], %o1
F004F934: 90026004                 add     %o1, 4, %o0
F004F938: d027bff4                 st      %o0, [%fp+var_C]
F004F93C: d0026004                 ld      [%o1+4], %o0
F004F940: 92100018                 mov     %i0, %o1
F004F944: 94102002                 mov     2, %o2
F004F948: 9607bff4                 add     %fp, var_C, %o3
F004F94C: 40000010                 call    sub_F004F98C
F004F950: 9807bff0                 add     %fp, var_10, %o4
F004F954: 80a22000                 cmp     %o0, 0
F004F958: 2280000b                 be,a    locret_F004F984
F004F95C: b0102000                 mov     0, %i0
F004F960: d0562002                 ldsh    [%i0+2], %o0
F004F964: 80a22002                 cmp     %o0, 2
F004F968: 02800006                 be      loc_F004F980
F004F96C: d207bff0                 ld      [%fp+var_10], %o1
F004F970: d0526002                 ldsh    [%o1+2], %o0
F004F974: 80a22002                 cmp     %o0, 2
F004F978: 32bffff2                 bne,a   loc_F004F940
F004F97C: d0026014                 ld      [%o1+0x14], %o0
F004F980: f007bff0                 ld      [%fp+var_10], %i0
F004F984: 81c7e008                 ret
F004F988: 81e80000                 restore
