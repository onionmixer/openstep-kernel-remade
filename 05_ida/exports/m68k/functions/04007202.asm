04007202: 4856                     pea     (a6)
04007204: 2c4f                     movea.l sp,a6
04007206: 2f02                     move.l  d2,-(sp)
04007208: 242e0008                 move.l  8(a6),d2
0400720C: 703f                     moveq   #$3F,d0 ; '?'
0400720E: c082                     and.l   d2,d0
04007210: 41f9040b5f04             lea     (_posix_proc_hash).l,a0
04007216: 22700c00                 movea.l (a0,d0.l*4),a1
0400721A: 4a89                     tst.l   a1
0400721C: 6710                     beq.s   loc_400722E
0400721E: b491                     cmp.l   (a1),d2
04007220: 6604                     bne.s   loc_4007226
04007222: 4280                     clr.l   d0
04007224: 602c                     bra.s   loc_4007252
04007226: 2269001a                 movea.l $1A(a1),a1
0400722A: 4a89                     tst.l   a1
0400722C: 66f0                     bne.s   loc_400721E
0400722E: 4878001e                 pea     ($1E).w
04007232: 61ff00042fcc             bsr.l   _kalloc
04007238: 2240                     movea.l d0,a1
0400723A: 2282                     move.l  d2,(a1)
0400723C: 703f                     moveq   #$3F,d0 ; '?'
0400723E: c082                     and.l   d2,d0
04007240: 41f9040b5f04             lea     (_posix_proc_hash).l,a0
04007246: 23700c00001a             move.l  (a0,d0.l*4),$1A(a1)
0400724C: 21890c00                 move.l  a1,(a0,d0.l*4)
04007250: 2009                     move.l  a1,d0
04007252: 242efffc                 move.l  -4(a6),d2
04007256: 4e5e                     unlk    a6
04007258: 4e75                     rts
