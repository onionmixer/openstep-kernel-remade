0409350C: 4856                     pea     (a6)
0409350E: 2c4f                     movea.l sp,a6
04093510: 48e73e30                 movem.l d2-d6/a2-a3,-(sp)
04093514: 246e0008                 movea.l 8(a6),a2
04093518: 266e000c                 movea.l $C(a6),a3
0409351C: 7a01                     moveq   #1,d5
0409351E: 0c12003d                 cmpi.b  #$3D,(a2) ; '='
04093522: 660000c4                 bne.w   loc_40935E8
04093526: 524a                     addq.w  #1,a2
04093528: 0c12002d                 cmpi.b  #$2D,(a2) ; '-'
0409352C: 6604                     bne.s   loc_4093532
0409352E: 7aff                     moveq   #$FFFFFFFF,d5
04093530: 524a                     addq.w  #1,a2
04093532: 101a                     move.b  (a2)+,d0
04093534: 49c0                     extb.l  d0
04093536: 74d0                     moveq   #$FFFFFFD0,d2
04093538: d480                     add.l   d0,d2
0409353A: 780a                     moveq   #$A,d4
0409353C: 4a82                     tst.l   d2
0409353E: 6644                     bne.s   loc_4093584
04093540: 1012                     move.b  (a2),d0
04093542: 0c000030                 cmpi.b  #$30,d0 ; '0'
04093546: 6d2a                     blt.s   loc_4093572
04093548: 0c000037                 cmpi.b  #$37,d0 ; '7'
0409354C: 6f18                     ble.s   loc_4093566
0409354E: 0c000062                 cmpi.b  #$62,d0 ; 'b'
04093552: 670c                     beq.s   loc_4093560
04093554: 0c000078                 cmpi.b  #$78,d0 ; 'x'
04093558: 6618                     bne.s   loc_4093572
0409355A: 7810                     moveq   #$10,d4
0409355C: 524a                     addq.w  #1,a2
0409355E: 6024                     bra.s   loc_4093584
04093560: 7802                     moveq   #2,d4
04093562: 524a                     addq.w  #1,a2
04093564: 601e                     bra.s   loc_4093584
04093566: 49c0                     extb.l  d0
04093568: 74d0                     moveq   #$FFFFFFD0,d2
0409356A: d480                     add.l   d0,d2
0409356C: 524a                     addq.w  #1,a2
0409356E: 7808                     moveq   #8,d4
04093570: 6012                     bra.s   loc_4093584
04093572: 1c12                     move.b  (a2),d6
04093574: 49c6                     extb.l  d6
04093576: 2f06                     move.l  d6,-(sp)
04093578: 61ffffffff34             bsr.l   _isargsep
0409357E: 584f                     addq.w  #4,sp
04093580: 4a80                     tst.l   d0
04093582: 6760                     beq.s   loc_40935E4
04093584: 4283                     clr.l   d3
04093586: 121a                     move.b  (a2)+,d1
04093588: 0c01002f                 cmpi.b  #$2F,d1 ; '/'
0409358C: 630c                     bls.s   loc_409359A
0409358E: 0c010039                 cmpi.b  #$39,d1 ; '9'
04093592: 6206                     bhi.s   loc_409359A
04093594: 0601ffd0                 addi.b  #-$30,d1
04093598: 6032                     bra.s   loc_40935CC
0409359A: 1001                     move.b  d1,d0
0409359C: 0600ff9f                 addi.b  #-$61,d0
040935A0: 0c000005                 cmpi.b  #5,d0
040935A4: 6206                     bhi.s   loc_40935AC
040935A6: 0601ffa9                 addi.b  #-$57,d1
040935AA: 6020                     bra.s   loc_40935CC
040935AC: 1001                     move.b  d1,d0
040935AE: 0600ffbf                 addi.b  #-$41,d0
040935B2: 0c000005                 cmpi.b  #5,d0
040935B6: 6310                     bls.s   loc_40935C8
040935B8: 1601                     move.b  d1,d3
040935BA: 2f03                     move.l  d3,-(sp)
040935BC: 61fffffffef0             bsr.l   _isargsep
040935C2: 4a80                     tst.l   d0
040935C4: 6616                     bne.s   loc_40935DC
040935C6: 601c                     bra.s   loc_40935E4
040935C8: 0601ffc9                 addi.b  #-$37,d1
040935CC: 4280                     clr.l   d0
040935CE: 1001                     move.b  d1,d0
040935D0: b880                     cmp.l   d0,d4
040935D2: 6310                     bls.s   loc_40935E4
040935D4: 4c042800                 muls.l  d4,d2
040935D8: d480                     add.l   d0,d2
040935DA: 60aa                     bra.s   loc_4093586
040935DC: 4c052800                 muls.l  d5,d2
040935E0: 2682                     move.l  d2,(a3)
040935E2: 6008                     bra.s   loc_40935EC
040935E4: 7001                     moveq   #1,d0
040935E6: 6006                     bra.s   loc_40935EE
040935E8: 7c01                     moveq   #1,d6
040935EA: 2686                     move.l  d6,(a3)
040935EC: 4280                     clr.l   d0
040935EE: 4cee0c7cffe4             movem.l -$1C(a6),d2-d6/a2-a3
040935F4: 4e5e                     unlk    a6
040935F6: 4e75                     rts
