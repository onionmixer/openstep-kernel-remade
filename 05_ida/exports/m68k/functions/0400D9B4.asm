0400D9B4: 4856                     pea     (a6)
0400D9B6: 2c4f                     movea.l sp,a6
0400D9B8: 2f0b                     move.l  a3,-(sp)
0400D9BA: 2f0a                     move.l  a2,-(sp)
0400D9BC: 266e0008                 movea.l 8(a6),a3
0400D9C0: 2453                     movea.l (a3),a2
0400D9C2: 082a0005003a             btst    #5,$3A(a2)
0400D9C8: 6708                     beq.s   loc_400D9D2
0400D9CA: 2f0a                     move.l  a2,-(sp)
0400D9CC: 61ff0000048e             bsr.l   _ttypend
0400D9D2: 222a000c                 move.l  $C(a2),d1
0400D9D6: 7022                     moveq   #$22,d0 ; '"'
0400D9D8: c0aa003a                 and.l   $3A(a2),d0
0400D9DC: 670e                     beq.s   loc_400D9EC
0400D9DE: d292                     add.l   (a2),d1
0400D9E0: 4280                     clr.l   d0
0400D9E2: 102b0015                 move.b  $15(a3),d0
0400D9E6: b081                     cmp.l   d1,d0
0400D9E8: 6f02                     ble.s   loc_400D9EC
0400D9EA: 4281                     clr.l   d1
0400D9EC: 2001                     move.l  d1,d0
0400D9EE: 246efff8                 movea.l -8(a6),a2
0400D9F2: 266efffc                 movea.l -4(a6),a3
0400D9F6: 4e5e                     unlk    a6
0400D9F8: 4e75                     rts
