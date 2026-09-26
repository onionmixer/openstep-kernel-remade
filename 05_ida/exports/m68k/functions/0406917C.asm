0406917C: 4856                     pea     (a6)
0406917E: 2c4f                     movea.l sp,a6
04069180: 2f39040c3324             move.l  (_curBright).l,-(sp)
04069186: 61ffffffff70             bsr.l   _SetCurBrightness
0406918C: 2079040c3640             movea.l (_evg).l,a0
04069192: 20280010                 move.l  $10(a0),d0
04069196: d0b9040c3300             add.l   (_autoDimPeriod).l,d0
0406919C: 23c0040c3304             move.l  d0,(_autoDimTime).l
040691A2: 42b9040c3308             clr.l   (_autoDimmed).l
040691A8: 4e5e                     unlk    a6
040691AA: 4e75                     rts
