0402AEEC: 4e56ff80                 link    a6,#-$80
0402AEF0: 48e73e30                 movem.l d2-d6/a2-a3,-(sp)
0402AEF4: 266e0008                 movea.l arg_0(a6),a3
0402AEF8: 2a2e000c                 move.l  arg_4(a6),d5
0402AEFC: 282e0010                 move.l  arg_8(a6),d4
0402AF00: 262e0014                 move.l  arg_C(a6),d3
0402AF04: 2c2e0018                 move.l  arg_10(a6),d6
0402AF08: 206b0024                 movea.l $24(a3),a0
0402AF0C: 20680126                 movea.l $126(a0),a0
0402AF10: 2468001e                 movea.l $1E(a0),a2
0402AF14: b68a                     cmp.l   a2,d3
0402AF16: 6c02                     bge.s   loc_402AF1A
0402AF18: 2443                     movea.l d3,a2
0402AF1A: 2d45fff8                 move.l  d5,var_8(a6)
0402AF1E: 206b002e                 movea.l $2E(a3),a0
0402AF22: 2d68003effc8             move.l  $3E(a0),var_38(a6)
0402AF28: 2d680042ffcc             move.l  $42(a0),var_34(a6)
0402AF2E: 2d680046ffd0             move.l  $46(a0),var_30(a6)
0402AF34: 2d68004affd4             move.l  $4A(a0),var_2C(a6)
0402AF3A: 2d68004effd8             move.l  $4E(a0),var_28(a6)
0402AF40: 2d680052ffdc             move.l  $52(a0),var_24(a6)
0402AF46: 2d680056ffe0             move.l  $56(a0),var_20(a6)
0402AF4C: 2d68005affe4             move.l  $5A(a0),var_1C(a6)
0402AF52: 2d44ffe8                 move.l  d4,var_18(a6)
0402AF56: 2d4afff0                 move.l  a2,var_10(a6)
0402AF5A: 2d4afff4                 move.l  a2,var_C(a6)
0402AF5E: 2d44ffec                 move.l  d4,var_14(a6)
0402AF62: 2f06                     move.l  d6,-(sp)
0402AF64: 486eff80                 pea     var_80(a6)
0402AF68: 48790402d230             pea     (_xdr_attrstat).l
0402AF6E: 486effc8                 pea     var_38(a6)
0402AF72: 48790402ccb0             pea     (_xdr_writeargs).l
0402AF78: 48780008                 pea     (8).w
0402AF7C: 206b0024                 movea.l $24(a3),a0
0402AF80: 2f280126                 move.l  $126(a0),-(sp)
0402AF84: 61ffffffdb66             bsr.l   _rfscall
0402AF8A: 2400                     move.l  d0,d2
0402AF8C: defc001c                 adda.w  #$1C,sp
0402AF90: 661c                     bne.s   loc_402AFAE
0402AF92: 242eff80                 move.l  var_80(a6),d2
0402AF96: 7246                     moveq   #$46,d1 ; 'F'
0402AF98: b282                     cmp.l   d2,d1
0402AF9A: 6612                     bne.s   loc_402AFAE
0402AF9C: 2f0b                     move.l  a3,-(sp)
0402AF9E: 61fffffed4bc             bsr.l   _btrash
0402AFA4: 2f0b                     move.l  a3,-(sp)
0402AFA6: 61ffffffb200             bsr.l   _nfs_invalidate_caches
0402AFAC: 504f                     addq.w  #8,sp
0402AFAE: 968a                     sub.l   a2,d3
0402AFB0: da8a                     add.l   a2,d5
0402AFB2: d88a                     add.l   a2,d4
0402AFB4: 4a82                     tst.l   d2
0402AFB6: 6614                     bne.s   loc_402AFCC
0402AFB8: 4a83                     tst.l   d3
0402AFBA: 6600ff4c                 bne.w   loc_402AF08
0402AFBE: 486eff84                 pea     var_7C(a6)
0402AFC2: 2f0b                     move.l  a3,-(sp)
0402AFC4: 61ffffffb2a0             bsr.l   _nfs_attrcache
0402AFCA: 504f                     addq.w  #8,sp
0402AFCC: 721c                     moveq   #$1C,d1
0402AFCE: b282                     cmp.l   d2,d1
0402AFD0: 6710                     beq.s   loc_402AFE2
0402AFD2: 6d06                     blt.s   loc_402AFDA
0402AFD4: 4a82                     tst.l   d2
0402AFD6: 6756                     beq.s   loc_402B02E
0402AFD8: 6022                     bra.s   loc_402AFFC
0402AFDA: 7245                     moveq   #$45,d1 ; 'E'
0402AFDC: b282                     cmp.l   d2,d1
0402AFDE: 661c                     bne.s   loc_402AFFC
0402AFE0: 604c                     bra.s   loc_402B02E
0402AFE2: 206b0024                 movea.l $24(a3),a0
0402AFE6: 7232                     moveq   #$32,d1 ; '2'
0402AFE8: d2a80126                 add.l   $126(a0),d1
0402AFEC: 2f01                     move.l  d1,-(sp)
0402AFEE: 4879040a70a0             pea     (aNfsWriteErrorO).l; "NFS write error: on host %s remote file"...
0402AFF4: 61fffffe0362             bsr.l   _printf
0402AFFA: 6032                     bra.s   loc_402B02E
0402AFFC: 206b0024                 movea.l $24(a3),a0
0402B000: 7232                     moveq   #$32,d1 ; '2'
0402B002: d2a80126                 add.l   $126(a0),d1
0402B006: 2f01                     move.l  d1,-(sp)
0402B008: 2f02                     move.l  d2,-(sp)
0402B00A: 4879040a70d5             pea     (aNfsWriteErrorD).l; "NFS write error %d on host %s fh "
0402B010: 45f90400b358             lea     (_printf).l,a2
0402B016: 4e92                     jsr     (a2)
0402B018: 723e                     moveq   #$3E,d1 ; '>'
0402B01A: d2ab002e                 add.l   $2E(a3),d1
0402B01E: 2f01                     move.l  d1,-(sp)
0402B020: 61ff00000018             bsr.l   sub_402B03A
0402B026: 4879040a6049             pea     (asc_40A6049).l; "\n"
0402B02C: 4e92                     jsr     (a2)
0402B02E: 2002                     move.l  d2,d0
0402B030: 4cee0c7cff64             movem.l var_9C(a6),d2-d6/a2-a3
0402B036: 4e5e                     unlk    a6
0402B038: 4e75                     rts
