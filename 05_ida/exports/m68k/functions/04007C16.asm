04007C16: 4856                     pea     (a6)
04007C18: 2c4f                     movea.l sp,a6
04007C1A: 2f0a                     move.l  a2,-(sp)
04007C1C: 4878002a                 pea     ($2A).w
04007C20: 61ff000425de             bsr.l   _kalloc
04007C26: 2440                     movea.l d0,a2
04007C28: 4878002a                 pea     ($2A).w
04007C2C: 2f0a                     move.l  a2,-(sp)
04007C2E: 61ff0008b1e2             bsr.l   _bzero
04007C34: 5252                     addq.w  #1,(a2)
04007C36: 52b9040ae236             addq.l  #1,(_cractive).l
04007C3C: 200a                     move.l  a2,d0
04007C3E: 246efffc                 movea.l -4(a6),a2
04007C42: 4e5e                     unlk    a6
04007C44: 4e75                     rts
