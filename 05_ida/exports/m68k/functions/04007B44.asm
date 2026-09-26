04007B44: 4856                     pea     (a6)
04007B46: 2c4f                     movea.l sp,a6
04007B48: 322e000a                 move.w  $A(a6),d1
04007B4C: 2079040b57d0             movea.l (_active_u).l,a0
04007B52: 2068001a                 movea.l $1A(a0),a0
04007B56: 43e8000a                 lea     $A(a0),a1
04007B5A: d0fc002a                 adda.w  #$2A,a0 ; '*'
04007B5E: b1c9                     cmpa.l  a1,a0
04007B60: 6328                     bls.s   loc_4007B8A
04007B62: 3011                     move.w  (a1),d0
04007B64: b240                     cmp.w   d0,d1
04007B66: 6604                     bne.s   loc_4007B6C
04007B68: 4280                     clr.l   d0
04007B6A: 6020                     bra.s   loc_4007B8C
04007B6C: 0c40ffff                 cmpi.w  #$FFFF,d0
04007B70: 6606                     bne.s   loc_4007B78
04007B72: 3281                     move.w  d1,(a1)
04007B74: 4280                     clr.l   d0
04007B76: 6014                     bra.s   loc_4007B8C
04007B78: 5449                     addq.w  #2,a1
04007B7A: 2079040b57d0             movea.l (_active_u).l,a0
04007B80: 702a                     moveq   #$2A,d0 ; '*'
04007B82: d0a8001a                 add.l   $1A(a0),d0
04007B86: b089                     cmp.l   a1,d0
04007B88: 62d8                     bhi.s   loc_4007B62
04007B8A: 70ff                     moveq   #$FFFFFFFF,d0
04007B8C: 4e5e                     unlk    a6
04007B8E: 4e75                     rts
