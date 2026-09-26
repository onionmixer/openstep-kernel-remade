04048874: 4856                     pea     (a6)
04048876: 2c4f                     movea.l sp,a6
04048878: 2f0a                     move.l  a2,-(sp)
0404887A: 226e0008                 movea.l 8(a6),a1
0404887E: 206e000c                 movea.l $C(a6),a0
04048882: 24690008                 movea.l 8(a1),a2
04048886: 217cfffffecf001c         move.l  #$FFFFFECF,$1C(a0)
0404888E: 20290014                 move.l  $14(a1),d0
04048892: 7241                     moveq   #$41,d1 ; 'A'
04048894: b280                     cmp.l   d0,d1
04048896: 6e1a                     bgt.s   loc_40488B2
04048898: 7242                     moveq   #$42,d1 ; 'B'
0404889A: b280                     cmp.l   d0,d1
0404889C: 6c0c                     bge.s   loc_40488AA
0404889E: 7248                     moveq   #$48,d1 ; 'H'
040488A0: b280                     cmp.l   d0,d1
040488A2: 6d0e                     blt.s   loc_40488B2
040488A4: 7245                     moveq   #$45,d1 ; 'E'
040488A6: b280                     cmp.l   d0,d1
040488A8: 6e08                     bgt.s   loc_40488B2
040488AA: 0c6a000c0006             cmpi.w  #$C,6(a2)
040488B0: 6704                     beq.s   loc_40488B6
040488B2: 4280                     clr.l   d0
040488B4: 6008                     bra.s   loc_40488BE
040488B6: 2f09                     move.l  a1,-(sp)
040488B8: 61ff0000180c             bsr.l   _ds_notify
040488BE: 246efffc                 movea.l -4(a6),a2
040488C2: 4e5e                     unlk    a6
040488C4: 4e75                     rts
