0404CB80: 4e56fffc                 link    a6,#-4
0404CB84: 2f02                     move.l  d2,-(sp)
0404CB86: 4879040a89c6             pea     (aNetListenerZon).l; "net listener zone"
0404CB8C: 42a7                     clr.l   -(sp)
0404CB8E: 48780014                 pea     ($14).w
0404CB92: 487807d0                 pea     ($7D0).w
0404CB96: 48780014                 pea     ($14).w
0404CB9A: 61ff00008446             bsr.l   _zinit
0404CBA0: 23c0040c2354             move.l  d0,(_listener_zone).l
0404CBA6: 7411                     moveq   #$11,d2
0404CBA8: 23c2040b3722             move.l  d2,(dword_40B3722).l
0404CBAE: 23fc000007ec040b3726     move.l  #$7EC,(dword_40B3726).l
0404CBB8: 42b9040b372a             clr.l   (dword_40B372A).l
0404CBBE: 42b9040b372e             clr.l   (dword_40B372E).l
0404CBC4: 23fc000007a7040b3736     move.l  #$7A7,(dword_40B3736).l
0404CBCE: 203c040c2358             move.l  #$40C2358,d0
0404CBD4: defc0014                 adda.w  #$14,sp
0404CBD8: 223c040c2398             move.l  #$40C2398,d1
0404CBDE: b280                     cmp.l   d0,d1
0404CBE0: 6306                     bls.s   loc_404CBE8
0404CBE2: 5880                     addq.l  #4,d0
0404CBE4: b280                     cmp.l   d0,d1
0404CBE6: 62fa                     bhi.s   loc_404CBE2
0404CBE8: 4879040a89d8             pea     (aMachNetMessage).l; "mach_net messages"
0404CBEE: 42a7                     clr.l   -(sp)
0404CBF0: 48780800                 pea     ($800).w
0404CBF4: 48782000                 pea     ($2000).w
0404CBF8: 48780800                 pea     ($800).w
0404CBFC: 61ff000083e4             bsr.l   _zinit
0404CC02: 23c0040c2398             move.l  d0,(_mach_net_kmsg_zone).l
0404CC08: 42a7                     clr.l   -(sp)
0404CC0A: 42a7                     clr.l   -(sp)
0404CC0C: 42a7                     clr.l   -(sp)
0404CC0E: 42a7                     clr.l   -(sp)
0404CC10: 2f00                     move.l  d0,-(sp)
0404CC12: 61ff0000908e             bsr.l   _zchange
0404CC18: defc0024                 adda.w  #$24,sp ; '$'
0404CC1C: 2ebc00002000             move.l  #$2000,(sp)
0404CC22: 486efffc                 pea     var_4(a6)
0404CC26: 2f39040b5dbc             move.l  (_kernel_map).l,-(sp)
0404CC2C: 61ff00010a9e             bsr.l   _kmem_alloc_wired
0404CC32: 48782000                 pea     ($2000).w
0404CC36: 2f2efffc                 move.l  var_4(a6),-(sp)
0404CC3A: 2f39040c2398             move.l  (_mach_net_kmsg_zone).l,-(sp)
0404CC40: 61ff000084b0             bsr.l   _zcram
0404CC46: 242efff8                 move.l  var_8(a6),d2
0404CC4A: 4e5e                     unlk    a6
0404CC4C: 4e75                     rts
