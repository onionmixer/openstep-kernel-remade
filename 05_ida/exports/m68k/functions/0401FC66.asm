0401FC66: 4856                     pea     (a6)
0401FC68: 2c4f                     movea.l sp,a6
0401FC6A: 226e0008                 movea.l 8(a6),a1
0401FC6E: 42a9000c                 clr.l   $C(a1)
0401FC72: 42690010                 clr.w   $10(a1)
0401FC76: 20690018                 movea.l $18(a1),a0
0401FC7A: 082800000007             btst    #0,7(a0)
0401FC80: 6708                     beq.s   loc_401FC8A
0401FC82: 2f09                     move.l  a1,-(sp)
0401FC84: 61ff00000008             bsr.l   _in_pcbdetach
0401FC8A: 4e5e                     unlk    a6
0401FC8C: 4e75                     rts
