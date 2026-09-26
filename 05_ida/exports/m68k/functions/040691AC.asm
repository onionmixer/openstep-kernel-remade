040691AC: 4e56ffe0                 link    a6,#-$20
040691B0: 2f0a                     move.l  a2,-(sp)
040691B2: 45eeffe0                 lea     var_20(a6),a2
040691B6: 2f0a                     move.l  a2,-(sp)
040691B8: 61ff00028628             bsr.l   _nvram_check
040691BE: 703f                     moveq   #$3F,d0 ; '?'
040691C0: c0b9040c3324             and.l   (_curBright).l,d0
040691C6: efee0106ffe1             bfins   d0,var_1F(a6){4:6}
040691CC: 2f0a                     move.l  a2,-(sp)
040691CE: 61ff0002867a             bsr.l   _nvram_set
040691D4: 246effdc                 movea.l var_24(a6),a2
040691D8: 4e5e                     unlk    a6
040691DA: 4e75                     rts
