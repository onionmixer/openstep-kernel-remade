04021550: 4856                     pea     (a6)
04021552: 2c4f                     movea.l sp,a6
04021554: 2f02                     move.l  d2,-(sp)
04021556: 206e0008                 movea.l 8(a6),a0
0402155A: 4282                     clr.l   d2
0402155C: 14280001                 move.b  1(a0),d2
04021560: 0c82000000a3             cmpi.l  #$A3,d2
04021566: 6318                     bls.s   loc_4021580
04021568: 4ab9040aeb24             tst.l   (_ipprintfs).l
0402156E: 673e                     beq.s   loc_40215AE
04021570: 2f02                     move.l  d2,-(sp)
04021572: 4879040a68cd             pea     (aSaveRteOlenD).l; "save_rte: olen %d\n"
04021578: 61fffffe9dde             bsr.l   _printf
0402157E: 602e                     bra.s   loc_40215AE
04021580: 2f02                     move.l  d2,-(sp)
04021582: 4879040b3485             pea     (unk_40B3485).l
04021588: 2f08                     move.l  a0,-(sp)
0402158A: 61ff000717a0             bsr.l   _bcopy
04021590: 2002                     move.l  d2,d0
04021592: 5780                     subq.l  #3,d0
04021594: e488                     lsr.l   #2,d0
04021596: 23c0040aeaf8             move.l  d0,(_ip_nhops).l
0402159C: 41f9040b3488             lea     (unk_40B3488).l,a0
040215A2: 21ae000c0c00             move.l  $C(a6),(a0,d0.l*4)
040215A8: 52b9040aeaf8             addq.l  #1,(_ip_nhops).l
040215AE: 242efffc                 move.l  -4(a6),d2
040215B2: 4e5e                     unlk    a6
040215B4: 4e75                     rts
