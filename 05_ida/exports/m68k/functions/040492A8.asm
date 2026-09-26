040492A8: 4856                     pea     (a6)
040492AA: 2c4f                     movea.l sp,a6
040492AC: 48e73820                 movem.l d2-d4/a2,-(sp)
040492B0: 242e0008                 move.l  8(a6),d2
040492B4: 246e000c                 movea.l $C(a6),a2
040492B8: 40c0                     move    sr,d0
040492BA: 46fc2300                 move    #$2300,sr
040492BE: 3600                     move.w  d0,d3
040492C0: 48c3                     ext.l   d3
040492C2: 4aaa013c                 tst.l   $13C(a2)
040492C6: 670c                     beq.s   loc_40492D4
040492C8: 486a0110                 pea     $110(a2)
040492CC: 61ff00001eb6             bsr.l   _reset_timeout
040492D2: 584f                     addq.w  #4,sp
040492D4: 222a0048                 move.l  $48(a2),d1
040492D8: 700f                     moveq   #$F,d0
040492DA: c081                     and.l   d1,d0
040492DC: 5380                     subq.l  #1,d0
040492DE: 780e                     moveq   #$E,d4
040492E0: b880                     cmp.l   d0,d4
040492E2: 6500009c                 bcs.w   loc_4049380
040492E6: 207c040492f2             movea.l #$40492F2,a0
040492EC: 20700c00                 movea.l (a0,d0.l*4),a0
040492F0: 4ed0                     jmp     (a0)
040492F2: 0404932e                 subi.b  #$2E,d4 ; '.'
040492F6: 04049380                 subi.b  #$80,d4
040492FA: 04049374                 subi.b  #$74,d4 ; 't'
040492FE: 04049380                 subi.b  #$80,d4
04049302: 04049374                 subi.b  #$74,d4 ; 't'
04049306: 04049380                 subi.b  #$80,d4
0404930A: 04049374                 subi.b  #$74,d4 ; 't'
0404930E: 04049380                 subi.b  #$80,d4
04049312: 0404932e                 subi.b  #$2E,d4 ; '.'
04049316: 04049380                 subi.b  #$80,d4
0404931A: 0404932e                 subi.b  #$2E,d4 ; '.'
0404931E: 04049380                 subi.b  #$80,d4
04049322: 04049374                 subi.b  #$74,d4 ; 't'
04049326: 04049380                 subi.b  #$80,d4
0404932A: 04049374                 subi.b  #$74,d4 ; 't'
0404932E: 70fe                     moveq   #$FFFFFFFE,d0
04049330: c081                     and.l   d1,d0
04049332: 7804                     moveq   #4,d4
04049334: 8880                     or.l    d0,d4
04049336: 25440048                 move.l  d4,$48(a2)
0404933A: 42aa0040                 clr.l   $40(a2)
0404933E: 226a0178                 movea.l $178(a2),a1
04049342: 4aa90110                 tst.l   $110(a1)
04049346: 6e0c                     bgt.s   loc_4049354
04049348: 2079040b5648             movea.l (_active_threads).l,a0
0404934E: b3e80178                 cmpa.l  $178(a0),a1
04049352: 6710                     beq.s   loc_4049364
04049354: 48780001                 pea     (1).w
04049358: 2f0a                     move.l  a2,-(sp)
0404935A: 61ff00007ed2             bsr.l   _thread_setrun
04049360: 504f                     addq.w  #8,sp
04049362: 601c                     bra.s   loc_4049380
04049364: 2f0a                     move.l  a2,-(sp)
04049366: 2f02                     move.l  d2,-(sp)
04049368: 61ff00007b3c             bsr.l   _thread_run
0404936E: 40c0                     move    sr,d0
04049370: 46c3                     move    d3,sr
04049372: 6022                     bra.s   loc_4049396
04049374: 78fe                     moveq   #$FFFFFFFE,d4
04049376: c881                     and.l   d1,d4
04049378: 25440048                 move.l  d4,$48(a2)
0404937C: 42aa0040                 clr.l   $40(a2)
04049380: 4a82                     tst.l   d2
04049382: 670e                     beq.s   loc_4049392
04049384: 40c0                     move    sr,d0
04049386: 46fc2000                 move    #$2000,sr
0404938A: 2f02                     move.l  d2,-(sp)
0404938C: 61fffffb87a2             bsr.l   _call_continuation
04049392: 40c0                     move    sr,d0
04049394: 46c3                     move    d3,sr
04049396: 4cee041cfff0             movem.l -$10(a6),d2-d4/a2
0404939C: 4e5e                     unlk    a6
0404939E: 4e75                     rts
