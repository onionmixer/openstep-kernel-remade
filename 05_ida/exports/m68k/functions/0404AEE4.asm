0404AEE4: 4856                     pea     (a6)
0404AEE6: 2c4f                     movea.l sp,a6
0404AEE8: 206e0008                 movea.l 8(a6),a0
0404AEEC: 2210                     move.l  (a0),d1
0404AEEE: b2b9040b5648             cmp.l   (_active_threads).l,d1
0404AEF4: 670a                     beq.s   loc_404AF00
0404AEF6: 10280006                 move.b  6(a0),d0
0404AEFA: 020000c0                 andi.b  #$C0,d0
0404AEFE: 6608                     bne.s   loc_404AF08
0404AF00: 52680004                 addq.w  #1,4(a0)
0404AF04: 7001                     moveq   #1,d0
0404AF06: 6002                     bra.s   loc_404AF0A
0404AF08: 4280                     clr.l   d0
0404AF0A: 4e5e                     unlk    a6
0404AF0C: 4e75                     rts
