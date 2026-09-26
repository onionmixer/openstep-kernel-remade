04053D38: 4856                     pea     (a6)
04053D3A: 2c4f                     movea.l sp,a6
04053D3C: 2f0a                     move.l  a2,-(sp)
04053D3E: 2f02                     move.l  d2,-(sp)
04053D40: 4280                     clr.l   d0
04053D42: 4282                     clr.l   d2
04053D44: 43f9040b6778             lea     (unk_40B6778).l,a1
04053D4A: 2051                     movea.l (a1),a0
04053D4C: b3c8                     cmpa.l  a0,a1
04053D4E: 6714                     beq.s   loc_4053D64
04053D50: 2209                     move.l  a1,d1
04053D52: 5280                     addq.l  #1,d0
04053D54: 4aa800b8                 tst.l   $B8(a0)
04053D58: 6702                     beq.s   loc_4053D5C
04053D5A: 5282                     addq.l  #1,d2
04053D5C: 20680018                 movea.l $18(a0),a0
04053D60: b288                     cmp.l   a0,d1
04053D62: 66ee                     bne.s   loc_4053D52
04053D64: 2f00                     move.l  d0,-(sp)
04053D66: 4879040a9079             pea     (aDTotalThreads).l; "%d total threads.\n"
04053D6C: 45f90400b358             lea     (_printf).l,a2
04053D72: 4e92                     jsr     (a2)
04053D74: 2f02                     move.l  d2,-(sp)
04053D76: 4879040a908c             pea     (aDUsingRpcReply).l; "%d using rpc_reply.\n"
04053D7C: 4e92                     jsr     (a2)
04053D7E: 242efff8                 move.l  -8(a6),d2
04053D82: 246efffc                 movea.l -4(a6),a2
04053D86: 4e5e                     unlk    a6
04053D88: 4e75                     rts
