04007426: 4856                     pea     (a6)
04007428: 2c4f                     movea.l sp,a6
0400742A: 2279040b57d4             movea.l (dword_40B57D4).l,a1
04007430: 2079040b57d0             movea.l (_active_u).l,a0
04007436: 2068001a                 movea.l $1A(a0),a0
0400743A: 30680008                 movea.w 8(a0),a0
0400743E: 2348005c                 move.l  a0,$5C(a1)
04007442: 2279040b57d4             movea.l (dword_40B57D4).l,a1
04007448: 2079040b57d0             movea.l (_active_u).l,a0
0400744E: 2068001a                 movea.l $1A(a0),a0
04007452: 30680004                 movea.w 4(a0),a0
04007456: 23480060                 move.l  a0,$60(a1)
0400745A: 4e5e                     unlk    a6
0400745C: 4e75                     rts
