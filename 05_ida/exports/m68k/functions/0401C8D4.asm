0401C8D4: 4856                     pea     (a6)
0401C8D6: 2c4f                     movea.l sp,a6
0401C8D8: 42a7                     clr.l   -(sp)
0401C8DA: 48790401c804             pea     (sub_401C804).l
0401C8E0: 61ff00000602             bsr.l   _if_registervirtual
0401C8E6: 4e5e                     unlk    a6
0401C8E8: 4e75                     rts
