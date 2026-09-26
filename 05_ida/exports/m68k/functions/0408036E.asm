0408036E: 4856                     pea     (a6)
04080370: 2c4f                     movea.l sp,a6
04080372: 42a7                     clr.l   -(sp)
04080374: 4879040800cc             pea     (sub_40800CC).l
0408037A: 48780004                 pea     (4).w
0408037E: 61ff00013b00             bsr.l   _callout_dispatch
04080384: 4e5e                     unlk    a6
04080386: 4e75                     rts
