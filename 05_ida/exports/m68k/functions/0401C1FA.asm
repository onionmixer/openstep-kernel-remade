0401C1FA: 4856                     pea     (a6)
0401C1FC: 2c4f                     movea.l sp,a6
0401C1FE: 48e73830                 movem.l d2-d4/a2-a3,-(sp)
0401C202: 282e0008                 move.l  8(a6),d4
0401C206: 262e000c                 move.l  $C(a6),d3
0401C20A: 266e0010                 movea.l $10(a6),a3
0401C20E: 4282                     clr.l   d2
0401C210: 4879040acf77             pea     (_IFCONTROL_SETADDR).l; "setaddr"
0401C216: 2f03                     move.l  d3,-(sp)
0401C218: 45f904093078             lea     (_strcmp).l,a2
0401C21E: 4e92                     jsr     (a2)
0401C220: 504f                     addq.w  #8,sp
0401C222: 4a80                     tst.l   d0
0401C224: 6618                     bne.s   loc_401C23E
0401C226: 2f04                     move.l  d4,-(sp)
0401C228: 61ff00000a34             bsr.l   _if_flags
0401C22E: 7241                     moveq   #$41,d1 ; 'A'
0401C230: 8280                     or.l    d0,d1
0401C232: 2f01                     move.l  d1,-(sp)
0401C234: 2f04                     move.l  d4,-(sp)
0401C236: 61ff00000a88             bsr.l   _if_flags_set
0401C23C: 602c                     bra.s   loc_401C26A
0401C23E: 4879040acfba             pea     (_IFCONTROL_ADDMULTICAST).l; "add-multicast"
0401C244: 2f03                     move.l  d3,-(sp)
0401C246: 4e92                     jsr     (a2)
0401C248: 504f                     addq.w  #8,sp
0401C24A: 4a80                     tst.l   d0
0401C24C: 670e                     beq.s   loc_401C25C
0401C24E: 4879040acfba             pea     (_IFCONTROL_ADDMULTICAST).l; "add-multicast"
0401C254: 2f03                     move.l  d3,-(sp)
0401C256: 4e92                     jsr     (a2)
0401C258: 4a80                     tst.l   d0
0401C25A: 660c                     bne.s   loc_401C268
0401C25C: 0c6b00020010             cmpi.w  #2,$10(a3)
0401C262: 6706                     beq.s   loc_401C26A
0401C264: 742f                     moveq   #$2F,d2 ; '/'
0401C266: 6002                     bra.s   loc_401C26A
0401C268: 7416                     moveq   #$16,d2
0401C26A: 2002                     move.l  d2,d0
0401C26C: 4cee0c1cffec             movem.l -$14(a6),d2-d4/a2-a3
0401C272: 4e5e                     unlk    a6
0401C274: 4e75                     rts
