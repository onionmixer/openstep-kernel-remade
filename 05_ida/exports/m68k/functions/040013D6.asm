040013D6: 4e560000                 link    a6,#0
040013DA: 0c390000040b56cc         cmpi.b  #0,(_cpu_type).l
040013E2: 6708                     beq.s   loc_40013EC
040013E4: 4e71                     nop
040013E6: f4f8                     cpusha  bc
040013E8: f518                     pflusha
040013EA: 6004                     bra.s   loc_40013F0
040013EC: f0003094                 pflush  #4,#4
040013F0: 4e5e                     unlk    a6
040013F2: 4e75                     rts
