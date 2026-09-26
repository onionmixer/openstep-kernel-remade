0406A3CA: 4856                     pea     (a6)
0406A3CC: 2c4f                     movea.l sp,a6
0406A3CE: 2079040c3640             movea.l (_evg).l,a0
0406A3D4: 42a80040                 clr.l   $40(a0)
0406A3D8: 42a7                     clr.l   -(sp)
0406A3DA: 61ff000005f8             bsr.l   sub_406A9D4
0406A3E0: 4e5e                     unlk    a6
0406A3E2: 4e75                     rts
