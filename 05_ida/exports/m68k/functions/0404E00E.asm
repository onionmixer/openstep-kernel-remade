0404E00E: 4856                     pea     (a6)
0404E010: 2c4f                     movea.l sp,a6
0404E012: 206e0008                 movea.l 8(a6),a0
0404E016: 226e000c                 movea.l $C(a6),a1
0404E01A: 4a10                     tst.b   (a0)
0404E01C: 6722                     beq.s   loc_404E040
0404E01E: 1211                     move.b  (a1),d1
0404E020: 0c010020                 cmpi.b  #$20,d1 ; ' '
0404E024: 671a                     beq.s   loc_404E040
0404E026: 1001                     move.b  d1,d0
0404E028: 0600fff7                 addi.b  #-9,d0
0404E02C: 0c000001                 cmpi.b  #1,d0
0404E030: 630e                     bls.s   loc_404E040
0404E032: 4a01                     tst.b   d1
0404E034: 670a                     beq.s   loc_404E040
0404E036: 5249                     addq.w  #1,a1
0404E038: b218                     cmp.b   (a0)+,d1
0404E03A: 67de                     beq.s   loc_404E01A
0404E03C: 7001                     moveq   #1,d0
0404E03E: 6002                     bra.s   loc_404E042
0404E040: 4280                     clr.l   d0
0404E042: 4e5e                     unlk    a6
0404E044: 4e75                     rts
