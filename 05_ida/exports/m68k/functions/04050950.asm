04050950: 4856                     pea     (a6)
04050952: 2c4f                     movea.l sp,a6
04050954: 48e73e38                 movem.l d2-d6/a2-a4,-(sp)
04050958: 262e0008                 move.l  8(a6),d3
0405095C: 2a2e000c                 move.l  $C(a6),d5
04050960: 282e0010                 move.l  $10(a6),d4
04050964: 4a83                     tst.l   d3
04050966: 6d22                     blt.s   loc_405098A
04050968: 2203                     move.l  d3,d1
0405096A: 4c3c1c0022b63cbf         muls.l  #$22B63CBF,d0:d1
04050972: e680                     asr.l   #3,d0
04050974: 2203                     move.l  d3,d1
04050976: 7c1f                     moveq   #$1F,d6
04050978: eca1                     asr.l   d6,d1
0405097A: 9081                     sub.l   d1,d0
0405097C: 2200                     move.l  d0,d1
0405097E: e980                     asl.l   #4,d0
04050980: 9081                     sub.l   d1,d0
04050982: e580                     asl.l   #2,d0
04050984: 9081                     sub.l   d1,d0
04050986: 2203                     move.l  d3,d1
04050988: 6024                     bra.s   loc_40509AE
0405098A: 2403                     move.l  d3,d2
0405098C: 4682                     not.l   d2
0405098E: 2202                     move.l  d2,d1
04050990: 4c3c1c0022b63cbf         muls.l  #$22B63CBF,d0:d1
04050998: e680                     asr.l   #3,d0
0405099A: 2202                     move.l  d2,d1
0405099C: 7c1f                     moveq   #$1F,d6
0405099E: eca1                     asr.l   d6,d1
040509A0: 9081                     sub.l   d1,d0
040509A2: 2200                     move.l  d0,d1
040509A4: e980                     asl.l   #4,d0
040509A6: 9081                     sub.l   d1,d0
040509A8: e580                     asl.l   #2,d0
040509AA: 9081                     sub.l   d1,d0
040509AC: 2202                     move.l  d2,d1
040509AE: 9280                     sub.l   d0,d1
040509B0: 41f9040c2800             lea     (_wait_queue).l,a0
040509B6: 49f01e00                 lea     (a0,d1.l*8),a4
040509BA: 40c0                     move    sr,d0
040509BC: 46fc2300                 move    #$2300,sr
040509C0: 3400                     move.w  d0,d2
040509C2: 48c2                     ext.l   d2
040509C4: 2454                     movea.l (a4),a2
040509C6: b5cc                     cmpa.l  a4,a2
040509C8: 670000ce                 beq.w   loc_4050A98
040509CC: 2652                     movea.l (a2),a3
040509CE: b6aa0038                 cmp.l   $38(a2),d3
040509D2: 660000bc                 bne.w   loc_4050A90
040509D6: 276a00040004             move.l  4(a2),4(a3)
040509DC: 206a0004                 movea.l 4(a2),a0
040509E0: 2092                     move.l  (a2),(a0)
040509E2: 42aa0038                 clr.l   $38(a2)
040509E6: 4aaa013c                 tst.l   $13C(a2)
040509EA: 670c                     beq.s   loc_40509F8
040509EC: 486a0110                 pea     $110(a2)
040509F0: 61ffffffa792             bsr.l   _reset_timeout
040509F6: 584f                     addq.w  #4,sp
040509F8: 222a0048                 move.l  $48(a2),d1
040509FC: 700f                     moveq   #$F,d0
040509FE: c081                     and.l   d1,d0
04050A00: 5380                     subq.l  #1,d0
04050A02: 7c0e                     moveq   #$E,d6
04050A04: bc80                     cmp.l   d0,d6
04050A06: 6576                     bcs.s   loc_4050A7E
04050A08: 207c04050a14             movea.l #$4050A14,a0
04050A0E: 20700c00                 movea.l (a0,d0.l*4),a0
04050A12: 4ed0                     jmp     (a0)
04050A14: 04050a50                 subi.b  #$50,d5 ; 'P'
04050A18: 04050a7e                 subi.b  #$7E,d5 ; '~'
04050A1C: 04050a70                 subi.b  #$70,d5 ; 'p'
04050A20: 04050a7e                 subi.b  #$7E,d5 ; '~'
04050A24: 04050a70                 subi.b  #$70,d5 ; 'p'
04050A28: 04050a7e                 subi.b  #$7E,d5 ; '~'
04050A2C: 04050a70                 subi.b  #$70,d5 ; 'p'
04050A30: 04050a7e                 subi.b  #$7E,d5 ; '~'
04050A34: 04050a50                 subi.b  #$50,d5 ; 'P'
04050A38: 04050a7e                 subi.b  #$7E,d5 ; '~'
04050A3C: 04050a50                 subi.b  #$50,d5 ; 'P'
04050A40: 04050a7e                 subi.b  #$7E,d5 ; '~'
04050A44: 04050a70                 subi.b  #$70,d5 ; 'p'
04050A48: 04050a7e                 subi.b  #$7E,d5 ; '~'
04050A4C: 04050a70                 subi.b  #$70,d5 ; 'p'
04050A50: 70fe                     moveq   #$FFFFFFFE,d0
04050A52: c081                     and.l   d1,d0
04050A54: 7c04                     moveq   #4,d6
04050A56: 8c80                     or.l    d0,d6
04050A58: 25460048                 move.l  d6,$48(a2)
04050A5C: 25440040                 move.l  d4,$40(a2)
04050A60: 48780001                 pea     (1).w
04050A64: 2f0a                     move.l  a2,-(sp)
04050A66: 61ff000007c6             bsr.l   _thread_setrun
04050A6C: 504f                     addq.w  #8,sp
04050A6E: 601c                     bra.s   loc_4050A8C
04050A70: 7cfe                     moveq   #$FFFFFFFE,d6
04050A72: cc81                     and.l   d1,d6
04050A74: 25460048                 move.l  d6,$48(a2)
04050A78: 25440040                 move.l  d4,$40(a2)
04050A7C: 600e                     bra.s   loc_4050A8C
04050A7E: 4879040a8ee0             pea     (aThreadWakeup).l; "thread_wakeup"
04050A84: 61fffffbb1e0             bsr.l   _panic
04050A8A: 584f                     addq.w  #4,sp
04050A8C: 4a85                     tst.l   d5
04050A8E: 6608                     bne.s   loc_4050A98
04050A90: 244b                     movea.l a3,a2
04050A92: b5cc                     cmpa.l  a4,a2
04050A94: 6600ff36                 bne.w   loc_40509CC
04050A98: 40c0                     move    sr,d0
04050A9A: 46c2                     move    d2,sr
04050A9C: 4cee1c7cffe0             movem.l -$20(a6),d2-d6/a2-a4
04050AA2: 4e5e                     unlk    a6
04050AA4: 4e75                     rts
