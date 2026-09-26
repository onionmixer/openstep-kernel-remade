04072672: 4856                     pea     (a6)
04072674: 2c4f                     movea.l sp,a6
04072676: 61ffffffff6a             bsr.l   _nbic_bus_enable
0407267C: 4a80                     tst.l   d0
0407267E: 674c                     beq.s   loc_40726CC
04072680: 2f3cf0fffff0             move.l  #$F0FFFFF0,-(sp)
04072686: 61fffff8f210             bsr.l   _probe_rl
0407268C: 584f                     addq.w  #4,sp
0407268E: 4a80                     tst.l   d0
04072690: 673a                     beq.s   loc_40726CC
04072692: 7201                     moveq   #1,d1
04072694: 23c1040c3a1c             move.l  d1,(_nbic_present).l
0407269A: 4879040aa6d3             pea     (aNbicPresent).l; "NBIC present\n"
040726A0: 61fffff98cb6             bsr.l   _printf
040726A6: 1039040b61ac             move.b  (_machine_type).l,d0
040726AC: 6706                     beq.s   loc_40726B4
040726AE: 0c000002                 cmpi.b  #2,d0
040726B2: 6618                     bne.s   loc_40726CC
040726B4: 207c02020004             movea.l #$2020004,a0
040726BA: 20bc80000000             move.l  #$80000000,(a0)
040726C0: 207c02020000             movea.l #$2020000,a0
040726C6: 20bc08000000             move.l  #$8000000,(a0)
040726CC: 4e5e                     unlk    a6
040726CE: 4e75                     rts
