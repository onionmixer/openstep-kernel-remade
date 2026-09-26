0400AB9A: 4856                     pea     (a6)
0400AB9C: 2c4f                     movea.l sp,a6
0400AB9E: 2079040b57d4             movea.l (dword_40B57D4).l,a0
0400ABA4: 2179040b5cb0005c         move.l  (_hostid).l,$5C(a0)
0400ABAC: 4e5e                     unlk    a6
0400ABAE: 4e75                     rts
