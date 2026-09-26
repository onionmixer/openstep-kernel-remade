04038E3A: 4856                     pea     (a6)
04038E3C: 2c4f                     movea.l sp,a6
04038E3E: 226e0008                 movea.l 8(a6),a1
04038E42: 20690010                 movea.l $10(a1),a0
04038E46: 53a80008                 subq.l  #1,8(a0)
04038E4A: 4878001c                 pea     ($1C).w
04038E4E: 2f09                     move.l  a1,-(sp)
04038E50: 61ff00011472             bsr.l   _kfree
04038E56: 4e5e                     unlk    a6
04038E58: 4e75                     rts
