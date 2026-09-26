04050856: 4856                     pea     (a6)
04050858: 2c4f                     movea.l sp,a6
0405085A: 48e73c20                 movem.l d2-d5/a2,-(sp)
0405085E: 246e0008                 movea.l 8(a6),a2
04050862: 282e000c                 move.l  $C(a6),d4
04050866: 222e0010                 move.l  $10(a6),d1
0405086A: 40c0                     move    sr,d0
0405086C: 46fc2300                 move    #$2300,sr
04050870: 3600                     move.w  d0,d3
04050872: 48c3                     ext.l   d3
04050874: 4a81                     tst.l   d1
04050876: 6710                     beq.s   loc_4050888
04050878: 082a0003004b             btst    #3,$4B(a2)
0405087E: 6708                     beq.s   loc_4050888
04050880: 40c0                     move    sr,d0
04050882: 46c3                     move    d3,sr
04050884: 600000c0                 bra.w   loc_4050946
04050888: 202a0038                 move.l  $38(a2),d0
0405088C: 6720                     beq.s   loc_40508AE
0405088E: b0aa0038                 cmp.l   $38(a2),d0
04050892: 6614                     bne.s   loc_40508A8
04050894: 2052                     movea.l (a2),a0
04050896: 216a00040004             move.l  4(a2),4(a0)
0405089C: 206a0004                 movea.l 4(a2),a0
040508A0: 2092                     move.l  (a2),(a0)
040508A2: 42aa0038                 clr.l   $38(a2)
040508A6: 4280                     clr.l   d0
040508A8: 4a80                     tst.l   d0
040508AA: 66000096                 bne.w   loc_4050942
040508AE: 242a0048                 move.l  $48(a2),d2
040508B2: 4aaa013c                 tst.l   $13C(a2)
040508B6: 670c                     beq.s   loc_40508C4
040508B8: 486a0110                 pea     $110(a2)
040508BC: 61ffffffa8c6             bsr.l   _reset_timeout
040508C2: 584f                     addq.w  #4,sp
040508C4: 700f                     moveq   #$F,d0
040508C6: c082                     and.l   d2,d0
040508C8: 5380                     subq.l  #1,d0
040508CA: 7a0e                     moveq   #$E,d5
040508CC: ba80                     cmp.l   d0,d5
040508CE: 6572                     bcs.s   loc_4050942
040508D0: 207c040508dc             movea.l #$40508DC,a0
040508D6: 20700c00                 movea.l (a0,d0.l*4),a0
040508DA: 4ed0                     jmp     (a0)
040508DC: 04050918                 subi.b  #$18,d5
040508E0: 04050942                 subi.b  #$42,d5 ; 'B'
040508E4: 04050936                 subi.b  #$36,d5 ; '6'
040508E8: 04050942                 subi.b  #$42,d5 ; 'B'
040508EC: 04050936                 subi.b  #$36,d5 ; '6'
040508F0: 04050942                 subi.b  #$42,d5 ; 'B'
040508F4: 04050936                 subi.b  #$36,d5 ; '6'
040508F8: 04050942                 subi.b  #$42,d5 ; 'B'
040508FC: 04050918                 subi.b  #$18,d5
04050900: 04050942                 subi.b  #$42,d5 ; 'B'
04050904: 04050918                 subi.b  #$18,d5
04050908: 04050942                 subi.b  #$42,d5 ; 'B'
0405090C: 04050936                 subi.b  #$36,d5 ; '6'
04050910: 04050942                 subi.b  #$42,d5 ; 'B'
04050914: 04050936                 subi.b  #$36,d5 ; '6'
04050918: 70fe                     moveq   #$FFFFFFFE,d0
0405091A: c082                     and.l   d2,d0
0405091C: 7a04                     moveq   #4,d5
0405091E: 8a80                     or.l    d0,d5
04050920: 25450048                 move.l  d5,$48(a2)
04050924: 25440040                 move.l  d4,$40(a2)
04050928: 48780001                 pea     (1).w
0405092C: 2f0a                     move.l  a2,-(sp)
0405092E: 61ff000008fe             bsr.l   _thread_setrun
04050934: 600c                     bra.s   loc_4050942
04050936: 7afe                     moveq   #$FFFFFFFE,d5
04050938: ca82                     and.l   d2,d5
0405093A: 25450048                 move.l  d5,$48(a2)
0405093E: 25440040                 move.l  d4,$40(a2)
04050942: 40c0                     move    sr,d0
04050944: 46c3                     move    d3,sr
04050946: 4cee043cffec             movem.l -$14(a6),d2-d5/a2
0405094C: 4e5e                     unlk    a6
0405094E: 4e75                     rts
