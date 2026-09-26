04019C94: 4856                     pea     (a6)
04019C96: 2c4f                     movea.l sp,a6
04019C98: 2f0a                     move.l  a2,-(sp)
04019C9A: 226e0008                 movea.l 8(a6),a1
04019C9E: 4aa90008                 tst.l   8(a1)
04019CA2: 6722                     beq.s   loc_4019CC6
04019CA4: 20690004                 movea.l 4(a1),a0
04019CA8: 0c10002f                 cmpi.b  #$2F,(a0) ; '/'
04019CAC: 6618                     bne.s   loc_4019CC6
04019CAE: 5248                     addq.w  #1,a0
04019CB0: 23480004                 move.l  a0,4(a1)
04019CB4: 20690008                 movea.l 8(a1),a0
04019CB8: 45e8ffff                 lea     -1(a0),a2
04019CBC: 234a0008                 move.l  a2,8(a1)
04019CC0: 7001                     moveq   #1,d0
04019CC2: b088                     cmp.l   a0,d0
04019CC4: 66de                     bne.s   loc_4019CA4
04019CC6: 246efffc                 movea.l -4(a6),a2
04019CCA: 4e5e                     unlk    a6
04019CCC: 4e75                     rts
