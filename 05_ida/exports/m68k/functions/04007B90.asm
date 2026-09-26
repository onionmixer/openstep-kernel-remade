04007B90: 4856                     pea     (a6)
04007B92: 2c4f                     movea.l sp,a6
04007B94: 322e000a                 move.w  $A(a6),d1
04007B98: 2079040b57d0             movea.l (_active_u).l,a0
04007B9E: 2268001a                 movea.l $1A(a0),a1
04007BA2: b2690004                 cmp.w   4(a1),d1
04007BA6: 6604                     bne.s   loc_4007BAC
04007BA8: 7001                     moveq   #1,d0
04007BAA: 6020                     bra.s   loc_4007BCC
04007BAC: 41e9000a                 lea     $A(a1),a0
04007BB0: d2fc002a                 adda.w  #$2A,a1 ; '*'
04007BB4: b3c8                     cmpa.l  a0,a1
04007BB6: 6312                     bls.s   loc_4007BCA
04007BB8: 3010                     move.w  (a0),d0
04007BBA: 0c40ffff                 cmpi.w  #$FFFF,d0
04007BBE: 670a                     beq.s   loc_4007BCA
04007BC0: b240                     cmp.w   d0,d1
04007BC2: 67e4                     beq.s   loc_4007BA8
04007BC4: 5448                     addq.w  #2,a0
04007BC6: b3c8                     cmpa.l  a0,a1
04007BC8: 62ee                     bhi.s   loc_4007BB8
04007BCA: 4280                     clr.l   d0
04007BCC: 4e5e                     unlk    a6
04007BCE: 4e75                     rts
