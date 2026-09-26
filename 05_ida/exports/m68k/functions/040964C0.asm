040964C0: 4e56fffc                 link    a6,#-4
040964C4: 2f0a                     move.l  a2,-(sp)
040964C6: 2d7c040c946cfffc         move.l  #$40C946C,var_4(a6)
040964CE: 206efffc                 movea.l var_4(a6),a0
040964D2: 2f10                     move.l  (a0),-(sp)
040964D4: 48780473                 pea     ($473).w
040964D8: 61fffffffeac             bsr.l   _kdebug_send
040964DE: 226efffc                 movea.l var_4(a6),a1
040964E2: 2051                     movea.l (a1),a0
040964E4: 45e80001                 lea     1(a0),a2
040964E8: 228a                     move.l  a2,(a1)
040964EA: 246efff8                 movea.l var_8(a6),a2
040964EE: 4e5e                     unlk    a6
040964F0: 4e75                     rts
