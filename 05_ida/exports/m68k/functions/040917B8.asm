040917B8: 4856                     pea     (a6)
040917BA: 2c4f                     movea.l sp,a6
040917BC: 122e000b                 move.b  $B(a6),d1
040917C0: 4200                     clr.b   d0
040917C2: 0c010009                 cmpi.b  #9,d1
040917C6: 630e                     bls.s   loc_40917D6
040917C8: 06000010                 addi.b  #$10,d0
040917CC: 0601fff6                 addi.b  #-$A,d1
040917D0: 0c010009                 cmpi.b  #9,d1
040917D4: 62f2                     bhi.s   loc_40917C8
040917D6: 8001                     or.b    d1,d0
040917D8: 0280000000ff             andi.l  #$FF,d0
040917DE: 4e5e                     unlk    a6
040917E0: 4e75                     rts
