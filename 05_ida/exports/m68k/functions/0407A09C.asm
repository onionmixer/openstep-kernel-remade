0407A09C: 4e56fff0                 link    a6,#-$10
0407A0A0: 48e73838                 movem.l d2-d4/a2-a4,-(sp)
0407A0A4: 286e0010                 movea.l arg_8(a6),a4
0407A0A8: 240c                     move.l  a4,d2
0407A0AA: 0482040c3ec8             subi.l  #$40C3EC8,d2
0407A0B0: 4c3c2800da6c0965         muls.l  #$DA6C0965,d2
0407A0B8: e282                     asr.l   #1,d2
0407A0BA: e782                     asl.l   #3,d2
0407A0BC: 2639040b1f90             move.l  (_od_errmsg_filter).l,d3
0407A0C2: 7809                     moveq   #9,d4
0407A0C4: 23c4040b1f90             move.l  d4,(_od_errmsg_filter).l
0407A0CA: 48780400                 pea     ($400).w
0407A0CE: 486efff2                 pea     var_E(a6)
0407A0D2: 2f39040b5dbc             move.l  (_kernel_map).l,-(sp)
0407A0D8: 61fffffe35f2             bsr.l   _kmem_alloc_wired
0407A0DE: 206c00ba                 movea.l $BA(a4),a0
0407A0E2: 203c00004d6a             move.l  #$4D6A,d0
0407A0E8: 9090                     sub.l   (a0),d0
0407A0EA: 30680004                 movea.w 4(a0),a0
0407A0EE: 42a7                     clr.l   -(sp)
0407A0F0: 42a7                     clr.l   -(sp)
0407A0F2: 42a7                     clr.l   -(sp)
0407A0F4: 42a7                     clr.l   -(sp)
0407A0F6: 42a7                     clr.l   -(sp)
0407A0F8: 48780400                 pea     ($400).w
0407A0FC: 2f2efff2                 move.l  var_E(a6),-(sp)
0407A100: 2808                     move.l  a0,d4
0407A102: 4c004800                 muls.l  d0,d4
0407A106: 2f04                     move.l  d4,-(sp)
0407A108: 48780002                 pea     (2).w
0407A10C: 2f02                     move.l  d2,-(sp)
0407A10E: 61ffffffe5aa             bsr.l   _od_cmd
0407A114: defc0034                 adda.w  #$34,sp ; '4'
0407A118: 4a80                     tst.l   d0
0407A11A: 6600009c                 bne.w   loc_407A1B8
0407A11E: 206efff2                 movea.l var_E(a6),a0
0407A122: 0c50ff01                 cmpi.w  #$FF01,(a0)
0407A126: 66000090                 bne.w   loc_407A1B8
0407A12A: 48780002                 pea     (2).w
0407A12E: 47eefff6                 lea     var_A(a6),a3
0407A132: 2f0b                     move.l  a3,-(sp)
0407A134: 48680036                 pea     $36(a0)
0407A138: 45f904092d2c             lea     (_bcopy).l,a2
0407A13E: 4e92                     jsr     (a2)
0407A140: 1d7c002ffff8             move.b  #$2F,var_8(a6) ; '/'
0407A146: 48780002                 pea     (2).w
0407A14A: 486efff9                 pea     var_7(a6)
0407A14E: 7838                     moveq   #$38,d4 ; '8'
0407A150: d8aefff2                 add.l   var_E(a6),d4
0407A154: 2f04                     move.l  d4,-(sp)
0407A156: 4e92                     jsr     (a2)
0407A158: 1d7c002ffffb             move.b  #$2F,var_5(a6) ; '/'
0407A15E: 48780002                 pea     (2).w
0407A162: 486efffc                 pea     var_4(a6)
0407A166: 7834                     moveq   #$34,d4 ; '4'
0407A168: d8aefff2                 add.l   var_E(a6),d4
0407A16C: 2f04                     move.l  d4,-(sp)
0407A16E: 4e92                     jsr     (a2)
0407A170: 422efffe                 clr.b   var_2(a6)
0407A174: defc0020                 adda.w  #$20,sp ; ' '
0407A178: 2ebc00000001             move.l  #1,(sp)
0407A17E: 2f0c                     move.l  a4,-(sp)
0407A180: 2f2e000c                 move.l  arg_4(a6),-(sp)
0407A184: 2f2e0008                 move.l  arg_0(a6),-(sp)
0407A188: 61fffffffdc2             bsr.l   _od_canon_remap
0407A18E: 2200                     move.l  d0,d1
0407A190: 4841                     swap    d1
0407A192: 48c1                     ext.l   d1
0407A194: 2f01                     move.l  d1,-(sp)
0407A196: 3f00                     move.w  d0,-(sp)
0407A198: 4267                     clr.w   -(sp)
0407A19A: 2f0b                     move.l  a3,-(sp)
0407A19C: 206efff2                 movea.l var_E(a6),a0
0407A1A0: 48680022                 pea     $22(a0)
0407A1A4: 48680012                 pea     $12(a0)
0407A1A8: 4879040ab222             pea     (aLotSSerialSDat).l; "\tLot: %s  Serial: %s  Date: %s  Canon:"...
0407A1AE: 61fffff911a8             bsr.l   _printf
0407A1B4: defc0028                 adda.w  #$28,sp ; '('
0407A1B8: 48780400                 pea     ($400).w
0407A1BC: 2f2efff2                 move.l  var_E(a6),-(sp)
0407A1C0: 2f39040b5dbc             move.l  (_kernel_map).l,-(sp)
0407A1C6: 61fffffe3578             bsr.l   _kmem_free
0407A1CC: 23c3040b1f90             move.l  d3,(_od_errmsg_filter).l
0407A1D2: 4cee1c1cffd8             movem.l var_28(a6),d2-d4/a2-a4
0407A1D8: 4e5e                     unlk    a6
0407A1DA: 4e75                     rts
