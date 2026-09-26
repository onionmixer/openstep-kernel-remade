0408046E: 4856                     pea     (a6)
04080470: 2c4f                     movea.l sp,a6
04080472: 202e0008                 move.l  8(a6),d0
04080476: 4aae000c                 tst.l   $C(a6)
0408047A: 6608                     bne.s   loc_4080484
0408047C: d0b9040c32d4             add.l   (_slot_id).l,d0
04080482: 6002                     bra.s   loc_4080486
04080484: 4280                     clr.l   d0
04080486: 4e5e                     unlk    a6
04080488: 4e75                     rts
