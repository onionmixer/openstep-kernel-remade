0406FE0E: 4856                     pea     (a6)
0406FE10: 2c4f                     movea.l sp,a6
0406FE12: 2f0a                     move.l  a2,-(sp)
0406FE14: 45f9040b6904             lea     (unk_40B6904).l,a2
0406FE1A: 3012                     move.w  (a2),d0
0406FE1C: 08000004                 btst    #4,d0
0406FE20: 6648                     bne.s   loc_406FE6A
0406FE22: 33fc0050040b68e2         move.w  #$50,(word_40B68E2).l ; 'P'
0406FE2A: 33fc0028040b68e6         move.w  #$28,(word_40B68E6).l ; '('
0406FE32: 203c00000a60             move.l  #$A60,d0
0406FE38: 4c790000040b693c         divu.l  (_km_coni).l,d0
0406FE40: 4c3c0800000001fe         muls.l  #$1FE,d0
0406FE48: 2f00                     move.l  d0,-(sp)
0406FE4A: 4879040b68ec             pea     (dword_40B68EC).l
0406FE50: 2f39040b5dbc             move.l  (_kernel_map).l,-(sp)
0406FE56: 61fffffed874             bsr.l   _kmem_alloc_wired
0406FE5C: 3012                     move.w  (a2),d0
0406FE5E: 00400010                 ori.w   #$10,d0
0406FE62: 3480                     move.w  d0,(a2)
0406FE64: 42b9040b68e8             clr.l   (dword_40B68E8).l
0406FE6A: 246efffc                 movea.l -4(a6),a2
0406FE6E: 4e5e                     unlk    a6
0406FE70: 4e75                     rts
