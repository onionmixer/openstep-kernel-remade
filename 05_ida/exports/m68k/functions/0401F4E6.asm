0401F4E6: 4e56fffc                 link    a6,#-4
0401F4EA: 48e73c00                 movem.l d2-d5,-(sp)
0401F4EE: 206e0008                 movea.l arg_0(a6),a0
0401F4F2: 2d50fffc                 move.l  (a0),var_4(a6)
0401F4F6: 43eefffc                 lea     var_4(a6),a1
0401F4FA: 41f9040b3470             lea     (unk_40B3470).l,a0
0401F500: 4282                     clr.l   d2
0401F502: 4244                     clr.w   d4
0401F504: 4283                     clr.l   d3
0401F506: 4a82                     tst.l   d2
0401F508: 6704                     beq.s   loc_401F50E
0401F50A: 10fc002e                 move.b  #$2E,(a0)+ ; '.'
0401F50E: 1011                     move.b  (a1),d0
0401F510: 0c000063                 cmpi.b  #$63,d0 ; 'c'
0401F514: 6376                     bls.s   loc_401F58C
0401F516: 1800                     move.b  d0,d4
0401F518: 3004                     move.w  d4,d0
0401F51A: e448                     lsr.w   #2,d0
0401F51C: 3600                     move.w  d0,d3
0401F51E: 2003                     move.l  d3,d0
0401F520: 4c3c08000000147b         muls.l  #$147B,d0
0401F528: 4240                     clr.w   d0
0401F52A: 4840                     swap    d0
0401F52C: e248                     lsr.w   #1,d0
0401F52E: 06000030                 addi.b  #$30,d0 ; '0'
0401F532: 10c0                     move.b  d0,(a0)+
0401F534: 4241                     clr.w   d1
0401F536: 1211                     move.b  (a1),d1
0401F538: e9c10606                 bfextu  d1{24:6},d0
0401F53C: 4c3c08000000147b         muls.l  #$147B,d0
0401F544: 4240                     clr.w   d0
0401F546: 4840                     swap    d0
0401F548: e248                     lsr.w   #1,d0
0401F54A: c1fc0064                 muls.w  #$64,d0 ; 'd'
0401F54E: 9240                     sub.w   d0,d1
0401F550: 3001                     move.w  d1,d0
0401F552: 0280000000ff             andi.l  #$FF,d0
0401F558: 4c3c08000000cccd         muls.l  #$CCCD,d0
0401F560: 4240                     clr.w   d0
0401F562: 4840                     swap    d0
0401F564: e648                     lsr.w   #3,d0
0401F566: 4a00                     tst.b   d0
0401F568: 6604                     bne.s   loc_401F56E
0401F56A: 10fc0030                 move.b  #$30,(a0)+ ; '0'
0401F56E: 4241                     clr.w   d1
0401F570: 1211                     move.b  (a1),d1
0401F572: e9c10606                 bfextu  d1{24:6},d0
0401F576: 4c3c08000000147b         muls.l  #$147B,d0
0401F57E: 4240                     clr.w   d0
0401F580: 4840                     swap    d0
0401F582: e248                     lsr.w   #1,d0
0401F584: c1fc0064                 muls.w  #$64,d0 ; 'd'
0401F588: 9200                     sub.b   d0,d1
0401F58A: 1281                     move.b  d1,(a1)
0401F58C: 1011                     move.b  (a1),d0
0401F58E: 0c000009                 cmpi.b  #9,d0
0401F592: 6338                     bls.s   loc_401F5CC
0401F594: 0280000000ff             andi.l  #$FF,d0
0401F59A: 4c3c08000000cccd         muls.l  #$CCCD,d0
0401F5A2: 4240                     clr.w   d0
0401F5A4: 4840                     swap    d0
0401F5A6: e648                     lsr.w   #3,d0
0401F5A8: 06000030                 addi.b  #$30,d0 ; '0'
0401F5AC: 10c0                     move.b  d0,(a0)+
0401F5AE: 4241                     clr.w   d1
0401F5B0: 1211                     move.b  (a1),d1
0401F5B2: 4280                     clr.l   d0
0401F5B4: 1001                     move.b  d1,d0
0401F5B6: 4c3c08000000cccd         muls.l  #$CCCD,d0
0401F5BE: 4240                     clr.w   d0
0401F5C0: 4840                     swap    d0
0401F5C2: e648                     lsr.w   #3,d0
0401F5C4: c1fc000a                 muls.w  #$A,d0
0401F5C8: 9200                     sub.b   d0,d1
0401F5CA: 1281                     move.b  d1,(a1)
0401F5CC: 1a19                     move.b  (a1)+,d5
0401F5CE: 06050030                 addi.b  #$30,d5 ; '0'
0401F5D2: 10c5                     move.b  d5,(a0)+
0401F5D4: 5282                     addq.l  #1,d2
0401F5D6: 7a03                     moveq   #3,d5
0401F5D8: ba82                     cmp.l   d2,d5
0401F5DA: 6c00ff2a                 bge.w   loc_401F506
0401F5DE: 4210                     clr.b   (a0)
0401F5E0: 203c040b3470             move.l  #$40B3470,d0
0401F5E6: 4cee003cffec             movem.l var_14(a6),d2-d5
0401F5EC: 4e5e                     unlk    a6
0401F5EE: 4e75                     rts
