0402969E: 4856                     pea     (a6)
040296A0: 2c4f                     movea.l sp,a6
040296A2: 2f0a                     move.l  a2,-(sp)
040296A4: 246e0008                 movea.l 8(a6),a2
040296A8: 302a006a                 move.w  $6A(a2),d0
040296AC: 3200                     move.w  d0,d1
040296AE: 5341                     subq.w  #1,d1
040296B0: 3541006a                 move.w  d1,$6A(a2)
040296B4: 5340                     subq.w  #1,d0
040296B6: 6a0e                     bpl.s   loc_40296C6
040296B8: 4879040a6c71             pea     (aRunlock).l; "RUNLOCK"
040296BE: 61fffffe25a6             bsr.l   _panic
040296C4: 584f                     addq.w  #4,sp
040296C6: 4a6a006a                 tst.w   $6A(a2)
040296CA: 6624                     bne.s   loc_40296F0
040296CC: 302a005e                 move.w  $5E(a2),d0
040296D0: 3200                     move.w  d0,d1
040296D2: 0241ffde                 andi.w  #$FFDE,d1
040296D6: 3541005e                 move.w  d1,$5E(a2)
040296DA: 08000001                 btst    #1,d0
040296DE: 6710                     beq.s   loc_40296F0
040296E0: 0240ffdc                 andi.w  #$FFDC,d0
040296E4: 3540005e                 move.w  d0,$5E(a2)
040296E8: 2f0a                     move.l  a2,-(sp)
040296EA: 61fffffe0b16             bsr.l   _wakeup
040296F0: 246efffc                 movea.l -4(a6),a2
040296F4: 4e5e                     unlk    a6
040296F6: 4e75                     rts
