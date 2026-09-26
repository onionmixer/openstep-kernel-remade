04093078: 4e560000                 link    a6,#0
0409307C: 206e0008                 movea.l arg_0(a6),a0
04093080: 226e000c                 movea.l arg_4(a6),a1
04093084: 1010                     move.b  (a0),d0
04093086: b019                     cmp.b   (a1)+,d0
04093088: 670c                     beq.s   loc_4093096
0409308A: 49c0                     extb.l  d0
0409308C: 1221                     move.b  -(a1),d1
0409308E: 49c1                     extb.l  d1
04093090: 9081                     sub.l   d1,d0
04093092: 4e5e                     unlk    a6
04093094: 4e75                     rts
04093096: 4a18                     tst.b   (a0)+
04093098: 66ea                     bne.s   loc_4093084
0409309A: 7000                     moveq   #0,d0
0409309C: 4e5e                     unlk    a6
0409309E: 4e75                     rts
