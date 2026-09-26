04036AAC: 4856                     pea     (a6)
04036AAE: 2c4f                     movea.l sp,a6
04036AB0: 206e0008                 movea.l 8(a6),a0
04036AB4: 2f2e000c                 move.l  $C(a6),-(sp)
04036AB8: 2f2e0010                 move.l  $10(a6),-(sp)
04036ABC: 2f280046                 move.l  $46(a0),-(sp)
04036AC0: 2068004e                 movea.l $4E(a0),a0
04036AC4: d0fc00d4                 adda.w  #$D4,a0
04036AC8: 2f08                     move.l  a0,-(sp)
04036ACA: 4879040a8045             pea     (aSBadDirInoDAtO).l; "%s: bad dir ino %d at offset %d: %s\n"
04036AD0: 61fffffd4886             bsr.l   _printf
04036AD6: 4e5e                     unlk    a6
04036AD8: 4e75                     rts
