0405DD16: 4856                     pea     (a6)
0405DD18: 2c4f                     movea.l sp,a6
0405DD1A: 2f0a                     move.l  a2,-(sp)
0405DD1C: 4879040a9689             pea     (aMaps).l; "maps"
0405DD22: 42a7                     clr.l   -(sp)
0405DD24: 42a7                     clr.l   -(sp)
0405DD26: 2f3c00019000             move.l  #$19000,-(sp)
0405DD2C: 48780044                 pea     ($44).w
0405DD30: 45f904054fe2             lea     (_zinit).l,a2
0405DD36: 4e92                     jsr     (a2)
0405DD38: 23c0040c2d38             move.l  d0,(_vm_map_zone).l
0405DD3E: 4879040a968e             pea     (aNonKernelMapEn).l; "non-kernel map entries"
0405DD44: 42a7                     clr.l   -(sp)
0405DD46: 42a7                     clr.l   -(sp)
0405DD48: 2f3c00100000             move.l  #$100000,-(sp)
0405DD4E: 4878002a                 pea     ($2A).w
0405DD52: 4e92                     jsr     (a2)
0405DD54: 23c0040c2d30             move.l  d0,(_vm_map_entry_zone).l
0405DD5A: defc0024                 adda.w  #$24,sp ; '$'
0405DD5E: 2ebc040a96a5             move.l  #$40A96A5,(sp)
0405DD64: 42a7                     clr.l   -(sp)
0405DD66: 42a7                     clr.l   -(sp)
0405DD68: 2f39040c2d24             move.l  (_kentry_data_size).l,-(sp)
0405DD6E: 4878002a                 pea     ($2A).w
0405DD72: 4e92                     jsr     (a2)
0405DD74: 23c0040c2d34             move.l  d0,(_vm_map_kentry_zone).l
0405DD7A: 42a7                     clr.l   -(sp)
0405DD7C: 42a7                     clr.l   -(sp)
0405DD7E: 42a7                     clr.l   -(sp)
0405DD80: 42a7                     clr.l   -(sp)
0405DD82: 2f00                     move.l  d0,-(sp)
0405DD84: 61ffffff7f1c             bsr.l   _zchange
0405DD8A: defc0024                 adda.w  #$24,sp ; '$'
0405DD8E: 2eb9040c2d2c             move.l  (_map_data_size).l,(sp)
0405DD94: 2f39040c2d28             move.l  (_map_data).l,-(sp)
0405DD9A: 2f39040c2d38             move.l  (_vm_map_zone).l,-(sp)
0405DDA0: 45f9040550f2             lea     (_zcram).l,a2
0405DDA6: 4e92                     jsr     (a2)
0405DDA8: 2f39040c2d24             move.l  (_kentry_data_size).l,-(sp)
0405DDAE: 2f39040c2d20             move.l  (_kentry_data).l,-(sp)
0405DDB4: 2f39040c2d34             move.l  (_vm_map_kentry_zone).l,-(sp)
0405DDBA: 4e92                     jsr     (a2)
0405DDBC: 246efffc                 movea.l -4(a6),a2
0405DDC0: 4e5e                     unlk    a6
0405DDC2: 4e75                     rts
