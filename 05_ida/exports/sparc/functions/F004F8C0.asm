F004F8C0: 9de3bf98                 save    %sp, -0x68, %sp
F004F8C4: 4000001a                 call    sub_F004F92C
F004F8C8: 90100018                 mov     %i0, %o0
F004F8CC: 92920000                 orcc    %o0, %g0, %o1
F004F8D0: 02800014                 be      loc_F004F920
F004F8D4: 90102003                 mov     3, %o0
F004F8D8: d0126002                 lduh    [%o1+2], %o0
F004F8DC: d0364000                 sth     %o0, [%i1]
F004F8E0: c0366002                 clrh    [%i1+2]
F004F8E4: d0026004                 ld      [%o1+4], %o0
F004F8E8: d0266004                 st      %o0, [%i1+4]
F004F8EC: d4026008                 ld      [%o1+8], %o2
F004F8F0: 80a2bfff                 cmp     %o2, -1
F004F8F4: 32800004                 bne,a   loc_F004F904
F004F8F8: d0026004                 ld      [%o1+4], %o0
F004F8FC: 10800005                 ba      loc_F004F910
F004F900: c0266008                 clr     [%i1+8]
F004F904: 90228008                 sub     %o2, %o0, %o0
F004F908: 90022001                 inc     %o0
F004F90C: d0266008                 st      %o0, [%i1+8]
F004F910: d002600c                 ld      [%o1+0xC], %o0
F004F914: d0020000                 ld      [%o0], %o0
F004F918: 10800003                 ba      locret_F004F924
F004F91C: d026600c                 st      %o0, [%i1+0xC]
F004F920: d0364000                 sth     %o0, [%i1]
F004F924: 81c7e008                 ret
F004F928: 91e82000                 restore %g0, 0, %o0
