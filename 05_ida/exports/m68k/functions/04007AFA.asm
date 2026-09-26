04007AFA: 4856                     pea     (a6)
04007AFC: 2c4f                     movea.l sp,a6
04007AFE: 322e000a                 move.w  $A(a6),d1
04007B02: 2079040b57d0             movea.l (_active_u).l,a0
04007B08: 2068001a                 movea.l $1A(a0),a0
04007B0C: 43e8000a                 lea     $A(a0),a1
04007B10: d0fc002a                 adda.w  #$2A,a0 ; '*'
04007B14: b1c9                     cmpa.l  a1,a0
04007B16: 6328                     bls.s   loc_4007B40
04007B18: 2008                     move.l  a0,d0
04007B1A: b251                     cmp.w   (a1),d1
04007B1C: 670e                     beq.s   loc_4007B2C
04007B1E: 5449                     addq.w  #2,a1
04007B20: b089                     cmp.l   a1,d0
04007B22: 62f6                     bhi.s   loc_4007B1A
04007B24: 601a                     bra.s   loc_4007B40
04007B26: 32a90002                 move.w  2(a1),(a1)
04007B2A: 5449                     addq.w  #2,a1
04007B2C: 2079040b57d0             movea.l (_active_u).l,a0
04007B32: 7028                     moveq   #$28,d0 ; '('
04007B34: d0a8001a                 add.l   $1A(a0),d0
04007B38: b089                     cmp.l   a1,d0
04007B3A: 62ea                     bhi.s   loc_4007B26
04007B3C: 32bcffff                 move.w  #$FFFF,(a1)
04007B40: 4e5e                     unlk    a6
04007B42: 4e75                     rts
