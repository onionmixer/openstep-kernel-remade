040013F4: 4e560000                 link    a6,#0
040013F8: 0c390000040b56cc         cmpi.b  #0,(_cpu_type).l
04001400: 6708                     beq.s   loc_400140A
04001402: 4e71                     nop
04001404: f4f8                     cpusha  bc
04001406: f510                     pflushan
04001408: 6004                     bra.s   loc_400140E
0400140A: f0003090                 pflush  #0,#4
0400140E: 4e5e                     unlk    a6
04001410: 4e75                     rts
