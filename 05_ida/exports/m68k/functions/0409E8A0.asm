0409E8A0: 30280000                 move.w  0(a0),d0
0409E8A4: 0c400040                 cmpi.w  #$40,d0 ; '@'
0409E8A8: 6bff0000000c             bmi.l   loc_409E8B6
0409E8AE: 61ff00000080             bsr.l   nrm_set
0409E8B4: 4e75                     rts
0409E8B6: 48e73600                 movem.l d2-d3/d5-d6,-(sp)
0409E8BA: 22280004                 move.l  4(a0),d1
0409E8BE: 24280008                 move.l  8(a0),d2
0409E8C2: edc13000                 bfffo   d1{0:32},d3
0409E8C6: 67ff0000003a             beq.l   loc_409E902
0409E8CC: b043                     cmp.w   d3,d0
0409E8CE: 6bff00000010             bmi.l   loc_409E8E0
0409E8D4: 61ff0000005a             bsr.l   nrm_set
0409E8DA: 4cdf006c                 movem.l (sp)+,d2-d3/d5-d6
0409E8DE: 4e75                     rts
0409E8E0: 2c02                     move.l  d2,d6
0409E8E2: e1aa                     lsl.l   d0,d2
0409E8E4: e1a9                     lsl.l   d0,d1
0409E8E6: 7a20                     moveq   #$20,d5 ; ' '
0409E8E8: 9a80                     sub.l   d0,d5
0409E8EA: eaae                     lsr.l   d5,d6
0409E8EC: 8286                     or.l    d6,d1
0409E8EE: 7000                     moveq   #0,d0
0409E8F0: 31400000                 move.w  d0,0(a0)
0409E8F4: 21410004                 move.l  d1,4(a0)
0409E8F8: 21420008                 move.l  d2,8(a0)
0409E8FC: 4cdf006c                 movem.l (sp)+,d2-d3/d5-d6
0409E900: 4e75                     rts
0409E902: edc23000                 bfffo   d2{0:32},d3
0409E906: 67ff0000001c             beq.l   loc_409E924
0409E90C: 06430020                 addi.w  #$20,d3 ; ' '
0409E910: b043                     cmp.w   d3,d0
0409E912: 6bffffffffcc             bmi.l   loc_409E8E0
0409E918: 61ff00000016             bsr.l   nrm_set
0409E91E: 4cdf006c                 movem.l (sp)+,d2-d3/d5-d6
0409E922: 4e75                     rts
0409E924: 317c00000000             move.w  #0,0(a0)
0409E92A: 4cdf006c                 movem.l (sp)+,d2-d3/d5-d6
0409E92E: 4e75                     rts
