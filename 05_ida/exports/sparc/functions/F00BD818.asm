F00BD818: 9de3bf90                 save    %sp, -0x70, %sp
F00BD81C: 9010001b                 mov     %i3, %o0! __s1
F00BD820: 133c0481                 sethi   %hi(aPrettyshutdown), %o1! "prettyShutdown"
F00BD824: 7ffd2a62                 call    _strcmp
F00BD828: 92126128                 bset    %lo(aPrettyshutdown), %o1! "prettyShutdown"
F00BD82C: 80a22000                 cmp     %o0, 0
F00BD830: 0280000e                 be      loc_F00BD868
F00BD834: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00BD838: f027bff0                 st      %i0, [%fp+var_10]
F00BD83C: 133c0507                 sethi   %hi(stru_F0141D2C.super_class), %o1
F00BD840: 9610001b                 mov     %i3, %o3
F00BD844: d4026130                 ld      [%o1+%lo(stru_F0141D2C.super_class)], %o2
F00BD848: 9810001c                 mov     %i4, %o4
F00BD84C: 133c0504                 sethi   %hi(paSetintvaluesFo_0), %o1
F00BD850: d427bff4                 st      %o2, [%fp+var_C]
F00BD854: d2026280                 ld      [%o1+%lo(paSetintvaluesFo_0)], %o1! SEL
F00BD858: 4000d049                 call    _objc_msgSendSuper
F00BD85C: 9410001a                 mov     %i2, %o2
F00BD860: 10800006                 ba      locret_F00BD878
F00BD864: b0100008                 mov     %o0, %i0
F00BD868: b0102000                 mov     0, %i0
F00BD86C: d2068000                 ld      [%i2], %o1
F00BD870: 113c04f7                 sethi   %hi(_prettyShutdown), %o0
F00BD874: d23221e8                 sth     %o1, [%o0+%lo(_prettyShutdown)]
F00BD878: 81c7e008                 ret
F00BD87C: 81e80000                 restore
