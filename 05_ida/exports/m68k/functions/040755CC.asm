040755CC: 4856                     pea     (a6)
040755CE: 2c4f                     movea.l sp,a6
040755D0: 48e70038                 movem.l a2-a4,-(sp)
040755D4: 266e0008                 movea.l 8(a6),a3
040755D8: 2f0b                     move.l  a3,-(sp)
040755DA: 61fffffc1c4a             bsr.l   _disksort_first
040755E0: 4a80                     tst.l   d0
040755E2: 6772                     beq.s   loc_4075656
040755E4: 302b00d8                 move.w  $D8(a3),d0
040755E8: 0800000d                 btst    #$D,d0
040755EC: 6608                     bne.s   loc_40755F6
040755EE: 00400040                 ori.w   #$40,d0 ; '@'
040755F2: 374000d8                 move.w  d0,$D8(a3)
040755F6: 122b000c                 move.b  $C(a3),d1
040755FA: 1001                     move.b  d1,d0
040755FC: 02000060                 andi.b  #$60,d0 ; '`'
04075600: 660e                     bne.s   loc_4075610
04075602: 1001                     move.b  d1,d0
04075604: 020000bf                 andi.b  #$BF,d0
04075608: 00000020                 ori.b   #$20,d0 ; ' '
0407560C: 1740000c                 move.b  d0,$C(a3)
04075610: 102b000c                 move.b  $C(a3),d0
04075614: 02000060                 andi.b  #$60,d0 ; '`'
04075618: 0c000040                 cmpi.b  #$40,d0 ; '@'
0407561C: 6738                     beq.s   loc_4075656
0407561E: 4280                     clr.l   d0
04075620: 302b00d2                 move.w  $D2(a3),d0
04075624: eb80                     asl.l   #5,d0
04075626: 2040                     movea.l d0,a0
04075628: d1fc040c3e18             adda.l  #$40C3E18,a0
0407562E: 24680010                 movea.l $10(a0),a2
04075632: 226a001c                 movea.l $1C(a2),a1
04075636: 228b                     move.l  a3,(a1)
04075638: 27490004                 move.l  a1,4(a3)
0407563C: 49ea0018                 lea     $18(a2),a4
04075640: 268c                     move.l  a4,(a3)
04075642: 254b001c                 move.l  a3,$1C(a2)
04075646: 102b000c                 move.b  $C(a3),d0
0407564A: 020000df                 andi.b  #$DF,d0
0407564E: 00000040                 ori.b   #$40,d0 ; '@'
04075652: 1740000c                 move.b  d0,$C(a3)
04075656: 4cee1c00fff4             movem.l -$C(a6),a2-a4
0407565C: 4e5e                     unlk    a6
0407565E: 4e75                     rts
