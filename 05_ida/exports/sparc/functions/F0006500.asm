F0006500: 98120009                 or      %o0, %o1, %o4
F0006504: 81820000                 mov     %o0, %y
F0006508: 9aab2fff                 andncc  %o4, 0xFFF, %o5
F000650C: 0280002a                 be      loc_F00065B4
F0006510: 98880000                 andcc   %g0, %g0, %o4
F0006514: 99230009                 mulscc  %o4, %o1, %o4
F0006518: 99230009                 mulscc  %o4, %o1, %o4
F000651C: 99230009                 mulscc  %o4, %o1, %o4
F0006520: 99230009                 mulscc  %o4, %o1, %o4
F0006524: 99230009                 mulscc  %o4, %o1, %o4
F0006528: 99230009                 mulscc  %o4, %o1, %o4
F000652C: 99230009                 mulscc  %o4, %o1, %o4
F0006530: 99230009                 mulscc  %o4, %o1, %o4
F0006534: 99230009                 mulscc  %o4, %o1, %o4
F0006538: 99230009                 mulscc  %o4, %o1, %o4
F000653C: 99230009                 mulscc  %o4, %o1, %o4
F0006540: 99230009                 mulscc  %o4, %o1, %o4
F0006544: 99230009                 mulscc  %o4, %o1, %o4
F0006548: 99230009                 mulscc  %o4, %o1, %o4
F000654C: 99230009                 mulscc  %o4, %o1, %o4
F0006550: 99230009                 mulscc  %o4, %o1, %o4
F0006554: 99230009                 mulscc  %o4, %o1, %o4
F0006558: 99230009                 mulscc  %o4, %o1, %o4
F000655C: 99230009                 mulscc  %o4, %o1, %o4
F0006560: 99230009                 mulscc  %o4, %o1, %o4
F0006564: 99230009                 mulscc  %o4, %o1, %o4
F0006568: 99230009                 mulscc  %o4, %o1, %o4
F000656C: 99230009                 mulscc  %o4, %o1, %o4
F0006570: 99230009                 mulscc  %o4, %o1, %o4
F0006574: 99230009                 mulscc  %o4, %o1, %o4
F0006578: 99230009                 mulscc  %o4, %o1, %o4
F000657C: 99230009                 mulscc  %o4, %o1, %o4
F0006580: 99230009                 mulscc  %o4, %o1, %o4
F0006584: 99230009                 mulscc  %o4, %o1, %o4
F0006588: 99230009                 mulscc  %o4, %o1, %o4
F000658C: 99230009                 mulscc  %o4, %o1, %o4
F0006590: 99230009                 mulscc  %o4, %o1, %o4
F0006594: 99230000                 mulscc  %o4, %g0, %o4
F0006598: 80924000                 tst     %o1
F000659C: 16800003                 bge     loc_F00065A8
F00065A0: 01000000                 nop
F00065A4: 98030008                 add     %o4, %o0, %o4
F00065A8: 91400000                 mov     %y, %o0
F00065AC: 81c3e008                 retl
F00065B0: 92830000                 addcc   %o4, %g0, %o1
F00065B4: 99230009                 mulscc  %o4, %o1, %o4
F00065B8: 99230009                 mulscc  %o4, %o1, %o4
F00065BC: 99230009                 mulscc  %o4, %o1, %o4
F00065C0: 99230009                 mulscc  %o4, %o1, %o4
F00065C4: 99230009                 mulscc  %o4, %o1, %o4
F00065C8: 99230009                 mulscc  %o4, %o1, %o4
F00065CC: 99230009                 mulscc  %o4, %o1, %o4
F00065D0: 99230009                 mulscc  %o4, %o1, %o4
F00065D4: 99230009                 mulscc  %o4, %o1, %o4
F00065D8: 99230009                 mulscc  %o4, %o1, %o4
F00065DC: 99230009                 mulscc  %o4, %o1, %o4
F00065E0: 99230009                 mulscc  %o4, %o1, %o4
F00065E4: 99230000                 mulscc  %o4, %g0, %o4
F00065E8: 9b400000                 mov     %y, %o5
F00065EC: 992b200c                 sll     %o4, 12, %o4
F00065F0: 9b336014                 srl     %o5, 20, %o5
F00065F4: 9013400c                 or      %o5, %o4, %o0
F00065F8: 81c3e008                 retl
F00065FC: 92800000                 addcc   %g0, %g0, %o1
