F00BED74: 9de3bf90                 save    %sp, -0x70, %sp
F00BED78: d4164000                 lduh    [%i1], %o2
F00BED7C: d206201c                 ld      [%i0+0x1C], %o1
F00BED80: d437bff0                 sth     %o2, [%fp+var_10]
F00BED84: d8166002                 lduh    [%i1+2], %o4
F00BED88: d837bff2                 sth     %o4, [%fp+var_E]
F00BED8C: d6166004                 lduh    [%i1+4], %o3
F00BED90: d637bff4                 sth     %o3, [%fp+var_C]
F00BED94: d0166006                 lduh    [%i1+6], %o0
F00BED98: 9602e003                 inc     3, %o3
F00BED9C: d037bff6                 sth     %o0, [%fp+var_A]
F00BEDA0: d0024000                 ld      [%o1], %o0
F00BEDA4: 960afffc                 and     %o3, -4, %o3
F00BEDA8: 90023b94                 inc     -0x46C, %o0
F00BEDAC: 91322001                 srl     %o0, 1, %o0
F00BEDB0: 94028008                 add     %o2, %o0, %o2
F00BEDB4: d437bff0                 sth     %o2, [%fp+var_10]
F00BEDB8: d2026004                 ld      [%o1+4], %o1
F00BEDBC: 90102000                 mov     0, %o0
F00BEDC0: 92027cc0                 inc     -0x340, %o1
F00BEDC4: 93326001                 srl     %o1, 1, %o1
F00BEDC8: 98030009                 add     %o4, %o1, %o4
F00BEDCC: d837bff2                 sth     %o4, [%fp+var_E]
F00BEDD0: 1300003f921263fc         set     0xFFFC, %o1
F00BEDD8: 940a8009                 and     %o2, %o1, %o2
F00BEDDC: d437bff0                 sth     %o2, [%fp+var_10]
F00BEDE0: d637bff4                 sth     %o3, [%fp+var_C]
F00BEDE4: 9207bff0                 add     %fp, var_10, %o1
F00BEDE8: d6066008                 ld      [%i1+8], %o3
F00BEDEC: 40009b03                 call    _sparcfbDrawRect
F00BEDF0: 94102002                 mov     2, %o2
F00BEDF4: 81c7e008                 ret
F00BEDF8: 91e80008                 restore %g0, %o0, %o0
