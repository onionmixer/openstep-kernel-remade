040162A6: 4e56fffc                 link    a6,#-4
040162AA: 48e72030                 movem.l d2/a2-a3,-(sp)
040162AE: 266e0008                 movea.l arg_0(a6),a3
040162B2: 206e000c                 movea.l arg_4(a6),a0
040162B6: 22680004                 movea.l 4(a0),a1
040162BA: 45f09800                 lea     (a0,a1.l),a2
040162BE: 30680008                 movea.w 8(a0),a0
040162C2: 43f188f4                 lea     -$C(a1,a0.l),a1
040162C6: 2009                     move.l  a1,d0
040162C8: 7270                     moveq   #$70,d1 ; 'p'
040162CA: b280                     cmp.l   d0,d1
040162CC: 6606                     bne.s   loc_40162D4
040162CE: 7028                     moveq   #$28,d0 ; '('
040162D0: 6000008a                 bra.w   loc_401635C
040162D4: 4230a800                 clr.b   (a0,a2.l)
040162D8: 486efffc                 pea     var_4(a6)
040162DC: 42a7                     clr.l   -(sp)
040162DE: 48780001                 pea     (1).w
040162E2: 48780001                 pea     (1).w
040162E6: 486a0002                 pea     2(a2)
040162EA: 61ff000030f2             bsr.l   _lookupname
040162F0: 2400                     move.l  d0,d2
040162F2: defc0014                 adda.w  #$14,sp
040162F6: 6664                     bne.s   loc_401635C
040162F8: 206efffc                 movea.l var_4(a6),a0
040162FC: 7206                     moveq   #6,d1
040162FE: b2a80028                 cmp.l   $28(a0),d1
04016302: 6704                     beq.s   loc_4016308
04016304: 7426                     moveq   #$26,d2 ; '&'
04016306: 6048                     bra.s   loc_4016350
04016308: 22680020                 movea.l $20(a0),a1
0401630C: 4a89                     tst.l   a1
0401630E: 672e                     beq.s   loc_401633E
04016310: 3211                     move.w  (a1),d1
04016312: b253                     cmp.w   (a3),d1
04016314: 6704                     beq.s   loc_401631A
04016316: 7429                     moveq   #$29,d2 ; ')'
04016318: 6036                     bra.s   loc_4016350
0401631A: 206b000c                 movea.l $C(a3),a0
0401631E: 082800020009             btst    #2,9(a0)
04016324: 671c                     beq.s   loc_4016342
04016326: 082900010003             btst    #1,3(a1)
0401632C: 6710                     beq.s   loc_401633E
0401632E: 2f09                     move.l  a1,-(sp)
04016330: 61ffffffdb14             bsr.l   _sonewconn
04016336: 2240                     movea.l d0,a1
04016338: 584f                     addq.w  #4,sp
0401633A: 4a89                     tst.l   a1
0401633C: 6604                     bne.s   loc_4016342
0401633E: 743d                     moveq   #$3D,d2 ; '='
04016340: 600e                     bra.s   loc_4016350
04016342: 2f09                     move.l  a1,-(sp)
04016344: 2f0b                     move.l  a3,-(sp)
04016346: 61ff0000001e             bsr.l   _unp_connect2
0401634C: 2400                     move.l  d0,d2
0401634E: 504f                     addq.w  #8,sp
04016350: 2f2efffc                 move.l  var_4(a6),-(sp)
04016354: 61ff00004d70             bsr.l   _vn_rele
0401635A: 2002                     move.l  d2,d0
0401635C: 4cee0c04fff0             movem.l var_10(a6),d2/a2-a3
04016362: 4e5e                     unlk    a6
04016364: 4e75                     rts
