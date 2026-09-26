F00BEDFC: 9de3bf90                 save    %sp, -0x70, %sp
F00BEE00: d2164000                 lduh    [%i1], %o1
F00BEE04: d806201c                 ld      [%i0+0x1C], %o4
F00BEE08: d237bff0                 sth     %o1, [%fp+var_10]
F00BEE0C: d6166002                 lduh    [%i1+2], %o3
F00BEE10: d637bff2                 sth     %o3, [%fp+var_E]
F00BEE14: d4166004                 lduh    [%i1+4], %o2
F00BEE18: d437bff4                 sth     %o2, [%fp+var_C]
F00BEE1C: d0166006                 lduh    [%i1+6], %o0
F00BEE20: d037bff6                 sth     %o0, [%fp+var_A]
F00BEE24: d0030000                 ld      [%o4], %o0
F00BEE28: 9402a003                 inc     3, %o2
F00BEE2C: 90023b94                 inc     -0x46C, %o0
F00BEE30: 91322001                 srl     %o0, 1, %o0
F00BEE34: 92024008                 add     %o1, %o0, %o1
F00BEE38: d237bff0                 sth     %o1, [%fp+var_10]
F00BEE3C: d0032004                 ld      [%o4+4], %o0
F00BEE40: 940abffc                 and     %o2, -4, %o2
F00BEE44: 90023cc0                 inc     -0x340, %o0
F00BEE48: 91322001                 srl     %o0, 1, %o0
F00BEE4C: 9602c008                 add     %o3, %o0, %o3
F00BEE50: d637bff2                 sth     %o3, [%fp+var_E]
F00BEE54: 1100003f901223fc         set     0xFFFC, %o0
F00BEE5C: 920a4008                 and     %o1, %o0, %o1
F00BEE60: d237bff0                 sth     %o1, [%fp+var_10]
F00BEE64: d437bff4                 sth     %o2, [%fp+var_C]
F00BEE68: d0066008                 ld      [%i1+8], %o0
F00BEE6C: 80a22001                 cmp     %o0, 1
F00BEE70: 2280000f                 be,a    loc_F00BEEAC
F00BEE74: 11002666                 sethi   0x999800, %o0
F00BEE78: 14800007                 bg      loc_F00BEE94
F00BEE7C: 80a22002                 cmp     %o0, 2
F00BEE80: 80a22000                 cmp     %o0, 0
F00BEE84: 02800008                 be      loc_F00BEEA4
F00BEE88: 11003fff                 sethi   0xFFFC00, %o0
F00BEE8C: 1080000b                 ba      loc_F00BEEB8
F00BEE90: 94102000                 mov     0, %o2
F00BEE94: 02800008                 be      loc_F00BEEB4
F00BEE98: 11001999                 sethi   0x666400, %o0
F00BEE9C: 10800007                 ba      loc_F00BEEB8
F00BEEA0: 94102000                 mov     0, %o2
F00BEEA4: 10800005                 ba      loc_F00BEEB8
F00BEEA8: 941223ff                 or      %o0, 0x3FF, %o2
F00BEEAC: 10800003                 ba      loc_F00BEEB8
F00BEEB0: 94122199                 or      %o0, 0x199, %o2
F00BEEB4: 94122266                 or      %o0, 0x266, %o2
F00BEEB8: 90102000                 mov     0, %o0
F00BEEBC: 40009a0a                 call    _sparcfbFillRect
F00BEEC0: 9207bff0                 add     %fp, var_10, %o1
F00BEEC4: 81c7e008                 ret
F00BEEC8: 91e82000                 restore %g0, 0, %o0
