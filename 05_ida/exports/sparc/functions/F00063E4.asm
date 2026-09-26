F00063E4: 81820000                 mov     %o0, %y
F00063E8: 80aa2fff                 andncc  %o0, 0xFFF, %g0
F00063EC: 0280002e                 be      loc_F00064A4
F00063F0: 98880000                 andcc   %g0, %g0, %o4
F00063F4: 99230009                 mulscc  %o4, %o1, %o4
F00063F8: 99230009                 mulscc  %o4, %o1, %o4
F00063FC: 99230009                 mulscc  %o4, %o1, %o4
F0006400: 99230009                 mulscc  %o4, %o1, %o4
F0006404: 99230009                 mulscc  %o4, %o1, %o4
F0006408: 99230009                 mulscc  %o4, %o1, %o4
F000640C: 99230009                 mulscc  %o4, %o1, %o4
F0006410: 99230009                 mulscc  %o4, %o1, %o4
F0006414: 99230009                 mulscc  %o4, %o1, %o4
F0006418: 99230009                 mulscc  %o4, %o1, %o4
F000641C: 99230009                 mulscc  %o4, %o1, %o4
F0006420: 99230009                 mulscc  %o4, %o1, %o4
F0006424: 99230009                 mulscc  %o4, %o1, %o4
F0006428: 99230009                 mulscc  %o4, %o1, %o4
F000642C: 99230009                 mulscc  %o4, %o1, %o4
F0006430: 99230009                 mulscc  %o4, %o1, %o4
F0006434: 99230009                 mulscc  %o4, %o1, %o4
F0006438: 99230009                 mulscc  %o4, %o1, %o4
F000643C: 99230009                 mulscc  %o4, %o1, %o4
F0006440: 99230009                 mulscc  %o4, %o1, %o4
F0006444: 99230009                 mulscc  %o4, %o1, %o4
F0006448: 99230009                 mulscc  %o4, %o1, %o4
F000644C: 99230009                 mulscc  %o4, %o1, %o4
F0006450: 99230009                 mulscc  %o4, %o1, %o4
F0006454: 99230009                 mulscc  %o4, %o1, %o4
F0006458: 99230009                 mulscc  %o4, %o1, %o4
F000645C: 99230009                 mulscc  %o4, %o1, %o4
F0006460: 99230009                 mulscc  %o4, %o1, %o4
F0006464: 99230009                 mulscc  %o4, %o1, %o4
F0006468: 99230009                 mulscc  %o4, %o1, %o4
F000646C: 99230009                 mulscc  %o4, %o1, %o4
F0006470: 99230009                 mulscc  %o4, %o1, %o4
F0006474: 99230000                 mulscc  %o4, %g0, %o4
F0006478: 80920000                 tst     %o0
F000647C: 91400000                 mov     %y, %o0
F0006480: 16800003                 bge     loc_F000648C
F0006484: 80920000                 tst     %o0
F0006488: 98230009                 sub     %o4, %o1, %o4
F000648C: 16800004                 bge     locret_F000649C
F0006490: 92830000                 addcc   %o4, %g0, %o1
F0006494: 81c3e008                 retl
F0006498: 80a33fff                 cmp     %o4, -1
F000649C: 81c3e008                 retl
F00064A0: 01000000                 nop
F00064A4: 99230009                 mulscc  %o4, %o1, %o4
F00064A8: 99230009                 mulscc  %o4, %o1, %o4
F00064AC: 99230009                 mulscc  %o4, %o1, %o4
F00064B0: 99230009                 mulscc  %o4, %o1, %o4
F00064B4: 99230009                 mulscc  %o4, %o1, %o4
F00064B8: 99230009                 mulscc  %o4, %o1, %o4
F00064BC: 99230009                 mulscc  %o4, %o1, %o4
F00064C0: 99230009                 mulscc  %o4, %o1, %o4
F00064C4: 99230009                 mulscc  %o4, %o1, %o4
F00064C8: 99230009                 mulscc  %o4, %o1, %o4
F00064CC: 99230009                 mulscc  %o4, %o1, %o4
F00064D0: 99230009                 mulscc  %o4, %o1, %o4
F00064D4: 99230000                 mulscc  %o4, %g0, %o4
F00064D8: 9b400000                 mov     %y, %o5
F00064DC: 912b200c                 sll     %o4, 12, %o0
F00064E0: 9b336014                 srl     %o5, 20, %o5
F00064E4: 90934008                 orcc    %o5, %o0, %o0
F00064E8: 16800004                 bge     locret_F00064F8
F00064EC: 933b2014                 sra     %o4, 20, %o1
F00064F0: 81c3e008                 retl
F00064F4: 80a27fff                 cmp     %o1, -1
F00064F8: 81c3e008                 retl
F00064FC: 80824000                 addcc   %o1, %g0, %g0
