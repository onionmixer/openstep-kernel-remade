040073EE: 4856                     pea     (a6)
040073F0: 2c4f                     movea.l sp,a6
040073F2: 2279040b57d4             movea.l (dword_40B57D4).l,a1
040073F8: 2079040b57d0             movea.l (_active_u).l,a0
040073FE: 2068001a                 movea.l $1A(a0),a0
04007402: 30680006                 movea.w 6(a0),a0
04007406: 2348005c                 move.l  a0,$5C(a1)
0400740A: 2279040b57d4             movea.l (dword_40B57D4).l,a1
04007410: 2079040b57d0             movea.l (_active_u).l,a0
04007416: 2068001a                 movea.l $1A(a0),a0
0400741A: 30680002                 movea.w 2(a0),a0
0400741E: 23480060                 move.l  a0,$60(a1)
04007422: 4e5e                     unlk    a6
04007424: 4e75                     rts
