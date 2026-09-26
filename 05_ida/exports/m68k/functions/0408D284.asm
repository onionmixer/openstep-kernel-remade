0408D284: 4856                     pea     (a6)
0408D286: 2c4f                     movea.l sp,a6
0408D288: 2f02                     move.l  d2,-(sp)
0408D28A: 222e0008                 move.l  8(a6),d1
0408D28E: 4280                     clr.l   d0
0408D290: 08010004                 btst    #4,d1
0408D294: 6702                     beq.s   loc_408D298
0408D296: 7040                     moveq   #$40,d0 ; '@'
0408D298: 08010002                 btst    #2,d1
0408D29C: 6704                     beq.s   loc_408D2A2
0408D29E: 7402                     moveq   #2,d2
0408D2A0: 8082                     or.l    d2,d0
0408D2A2: 08010000                 btst    #0,d1
0408D2A6: 6704                     beq.s   loc_408D2AC
0408D2A8: 7404                     moveq   #4,d2
0408D2AA: 8082                     or.l    d2,d0
0408D2AC: 08010003                 btst    #3,d1
0408D2B0: 6704                     beq.s   loc_408D2B6
0408D2B2: 7420                     moveq   #$20,d2 ; ' '
0408D2B4: 8082                     or.l    d2,d0
0408D2B6: 242efffc                 move.l  -4(a6),d2
0408D2BA: 4e5e                     unlk    a6
0408D2BC: 4e75                     rts
