0406B512: 4856                     pea     (a6)
0406B514: 2c4f                     movea.l sp,a6
0406B516: 2f02                     move.l  d2,-(sp)
0406B518: 242e0008                 move.l  8(a6),d2
0406B51C: 4ab9040b1298             tst.l   (_fd_polling_mode).l
0406B522: 661a                     bne.s   loc_406B53E
0406B524: 2f02                     move.l  d2,-(sp)
0406B526: 48790406b4da             pea     (_fc_timeout).l
0406B52C: 61fffffe356a             bsr.l   _us_untimeout
0406B532: 48780018                 pea     ($18).w
0406B536: 2f02                     move.l  d2,-(sp)
0406B538: 61ff0000214e             bsr.l   _fc_flags_bclr
0406B53E: 242efffc                 move.l  -4(a6),d2
0406B542: 4e5e                     unlk    a6
0406B544: 4e75                     rts
