0406E794: 4856                     pea     (a6)
0406E796: 2c4f                     movea.l sp,a6
0406E798: 48e73038                 movem.l d2-d3/a2-a4,-(sp)
0406E79C: 266e0008                 movea.l 8(a6),a3
0406E7A0: 286b0014                 movea.l $14(a3),a4
0406E7A4: 202c005c                 move.l  $5C(a4),d0
0406E7A8: 222b0186                 move.l  $186(a3),d1
0406E7AC: b280                     cmp.l   d0,d1
0406E7AE: 620c                     bhi.s   loc_406E7BC
0406E7B0: 2600                     move.l  d0,d3
0406E7B2: 4c413000                 divul.l d1,d0:d3
0406E7B6: 2203                     move.l  d3,d1
0406E7B8: 4a80                     tst.l   d0
0406E7BA: 6726                     beq.s   loc_406E7E2
0406E7BC: 76fd                     moveq   #$FFFFFFFD,d3
0406E7BE: c7ab0176                 and.l   d3,$176(a3)
0406E7C2: 4879040aa548             pea     (aFsBlockNotMult).l; "FS BLOCK NOT MULTIPLE OF DEVICE BLOCK\n"
0406E7C8: 45f90400b358             lea     (_printf).l,a2
0406E7CE: 4e92                     jsr     (a2)
0406E7D0: 2f2b0186                 move.l  $186(a3),-(sp)
0406E7D4: 2f2c005c                 move.l  $5C(a4),-(sp)
0406E7D8: 4879040aa56f             pea     (aFsBlockDDevBlo).l; "FS block: %d, DEV block: %d\n"
0406E7DE: 4e92                     jsr     (a2)
0406E7E0: 6050                     bra.s   loc_406E832
0406E7E2: 27410196                 move.l  d1,$196(a3)
0406E7E6: 206b000c                 movea.l $C(a3),a0
0406E7EA: 4a88                     tst.l   a0
0406E7EC: 6744                     beq.s   loc_406E832
0406E7EE: 3268000c                 movea.w $C(a0),a1
0406E7F2: 4a89                     tst.l   a1
0406E7F4: 6d3c                     blt.s   loc_406E832
0406E7F6: 242c006c                 move.l  $6C(a4),d2
0406E7FA: 763b                     moveq   #$3B,d3 ; ';'
0406E7FC: b682                     cmp.l   d2,d3
0406E7FE: 6c18                     bge.s   loc_406E818
0406E800: 2002                     move.l  d2,d0
0406E802: 4c3c0c0188888889         muls.l  #$88888889,d1:d0
0406E80A: d282                     add.l   d2,d1
0406E80C: ea81                     asr.l   #5,d1
0406E80E: 2002                     move.l  d2,d0
0406E810: 761f                     moveq   #$1F,d3
0406E812: e6a0                     asr.l   d3,d0
0406E814: 9280                     sub.l   d0,d1
0406E816: 6002                     bra.s   loc_406E81A
0406E818: 723c                     moveq   #$3C,d1 ; '<'
0406E81A: 41f9040b5b3c             lea     (_dk_bps).l,a0
0406E820: 202c005c                 move.l  $5C(a4),d0
0406E824: 4c2c08000064             muls.l  $64(a4),d0
0406E82A: 4c010800                 muls.l  d1,d0
0406E82E: 21809c00                 move.l  d0,(a0,a1.l*4)
0406E832: 4cee1c0cffec             movem.l -$14(a6),d2-d3/a2-a4
0406E838: 4e5e                     unlk    a6
0406E83A: 4e75                     rts
