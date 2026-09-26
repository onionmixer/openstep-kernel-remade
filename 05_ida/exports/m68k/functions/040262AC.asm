040262AC: 4856                     pea     (a6)
040262AE: 2c4f                     movea.l sp,a6
040262B0: 2f0b                     move.l  a3,-(sp)
040262B2: 2f0a                     move.l  a2,-(sp)
040262B4: 246e0008                 movea.l 8(a6),a2
040262B8: 266e000c                 movea.l $C(a6),a3
040262BC: 082a00060005             btst    #6,5(a2)
040262C2: 6634                     bne.s   loc_40262F8
040262C4: 206a0024                 movea.l $24(a2),a0
040262C8: 20680126                 movea.l $126(a0),a0
040262CC: 082800030014             btst    #3,$14(a0)
040262D2: 6624                     bne.s   loc_40262F8
040262D4: 4878003a                 pea     ($3A).w
040262D8: 707c                     moveq   #$7C,d0 ; '|'
040262DA: d0aa002e                 add.l   $2E(a2),d0
040262DE: 2f00                     move.l  d0,-(sp)
040262E0: 2f0b                     move.l  a3,-(sp)
040262E2: 61ff0006ca48             bsr.l   _bcopy
040262E8: 504f                     addq.w  #8,sp
040262EA: 584f                     addq.w  #4,sp
040262EC: 25530028                 move.l  (a3),$28(a2)
040262F0: 2f0a                     move.l  a2,-(sp)
040262F2: 61ff00000010             bsr.l   sub_4026304
040262F8: 246efff8                 movea.l -8(a6),a2
040262FC: 266efffc                 movea.l -4(a6),a3
04026300: 4e5e                     unlk    a6
04026302: 4e75                     rts
