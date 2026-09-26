0407F6A6: 4856                     pea     (a6)
0407F6A8: 2c4f                     movea.l sp,a6
0407F6AA: 2f0b                     move.l  a3,-(sp)
0407F6AC: 2f0a                     move.l  a2,-(sp)
0407F6AE: 266e0008                 movea.l 8(a6),a3
0407F6B2: 206b0010                 movea.l $10(a3),a0
0407F6B6: 30280004                 move.w  4(a0),d0
0407F6BA: c1fc0042                 muls.w  #$42,d0 ; 'B'
0407F6BE: 2440                     movea.l d0,a2
0407F6C0: d5fc040c65c8             adda.l  #$40C65C8,a2
0407F6C6: 48780042                 pea     ($42).w
0407F6CA: 2f0a                     move.l  a2,-(sp)
0407F6CC: 61ff00013744             bsr.l   _bzero
0407F6D2: 248b                     move.l  a3,(a2)
0407F6D4: 7027                     moveq   #$27,d0 ; '''
0407F6D6: d08a                     add.l   a2,d0
0407F6D8: 72f0                     moveq   #$FFFFFFF0,d1
0407F6DA: c280                     and.l   d0,d1
0407F6DC: 25410004                 move.l  d1,4(a2)
0407F6E0: 41ea0008                 lea     8(a2),a0
0407F6E4: 2548000c                 move.l  a0,$C(a2)
0407F6E8: 2088                     move.l  a0,(a0)
0407F6EA: 422a0015                 clr.b   $15(a2)
0407F6EE: 422a0017                 clr.b   $17(a2)
0407F6F2: 2052                     movea.l (a2),a0
0407F6F4: 117c00ff001c             move.b  #$FF,$1C(a0)
0407F6FA: 2052                     movea.l (a2),a0
0407F6FC: 117c00ff001d             move.b  #$FF,$1D(a0)
0407F702: 246efff8                 movea.l -8(a6),a2
0407F706: 266efffc                 movea.l -4(a6),a3
0407F70A: 4e5e                     unlk    a6
0407F70C: 4e75                     rts
