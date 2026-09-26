0407259E: 207c0200f000             movea.l #$200F000,a0
040725A4: 60000002                 bra.w   *+4
040725A8: 2f02                     move.l  d2,-(sp)
040725AA: 242f0008                 move.l  4+arg_0(sp),d2
040725AE: 40c1                     move    sr,d1
040725B0: 007c0700                 ori     #$700,sr
040725B4: 0c790139040c32d0         cmpi.w  #$139,(_dma_chip).l
040725BC: 661c                     bne.s   loc_40725DA
040725BE: 08100007                 btst    #7,(a0)
040725C2: 6716                     beq.s   loc_40725DA
040725C4: 43e80002                 lea     2(a0),a1
040725C8: 303c0064                 move.w  #$64,d0 ; 'd'
040725CC: 08110006                 btst    #6,(a1)
040725D0: 56c8fffa                 dbne    d0,loc_40725CC
040725D4: 08110006                 btst    #6,(a1)
040725D8: 66fa                     bne.s   loc_40725D4
040725DA: 8510                     or.b    d2,(a0)
040725DC: 46c1                     move    d1,sr
040725DE: 241f                     move.l  (sp)+,d2
040725E0: 4e75                     rts
