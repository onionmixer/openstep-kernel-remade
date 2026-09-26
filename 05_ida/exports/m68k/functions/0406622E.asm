0406622E: 4856                     pea     (a6)
04066230: 2c4f                     movea.l sp,a6
04066232: 48e73830                 movem.l d2-d4/a2-a3,-(sp)
04066236: 282e000c                 move.l  $C(a6),d4
0406623A: 262e0010                 move.l  $10(a6),d3
0406623E: 266e0014                 movea.l $14(a6),a3
04066242: 2f04                     move.l  d4,-(sp)
04066244: 2f2e0008                 move.l  8(a6),-(sp)
04066248: 2053                     movea.l (a3),a0
0406624A: 4e90                     jsr     (a0)
0406624C: 2400                     move.l  d0,d2
0406624E: 504f                     addq.w  #8,sp
04066250: 6604                     bne.s   loc_4066256
04066252: 4280                     clr.l   d0
04066254: 604a                     bra.s   loc_40662A0
04066256: 2f02                     move.l  d2,-(sp)
04066258: 2f04                     move.l  d4,-(sp)
0406625A: 2f2e0018                 move.l  $18(a6),-(sp)
0406625E: 4879040a9ed6             pea     (aSDAt0xX).l; "%s%d at 0x%x "
04066264: 45f90400b358             lea     (_printf).l,a2
0406626A: 4e92                     jsr     (a2)
0406626C: 504f                     addq.w  #8,sp
0406626E: 504f                     addq.w  #8,sp
04066270: 4a83                     tst.l   d3
04066272: 671e                     beq.s   loc_4066292
04066274: 2f2b0014                 move.l  $14(a3),-(sp)
04066278: 2f03                     move.l  d3,-(sp)
0406627A: 61fffffffcd4             bsr.l   _install_polled_intr
04066280: 504f                     addq.w  #8,sp
04066282: 4a80                     tst.l   d0
04066284: 6d0c                     blt.s   loc_4066292
04066286: 2f03                     move.l  d3,-(sp)
04066288: 4879040a9ee4             pea     (aIplD).l; "ipl %d"
0406628E: 4e92                     jsr     (a2)
04066290: 504f                     addq.w  #8,sp
04066292: 4879040a6049             pea     (asc_40A6049).l; "\n"
04066298: 61fffffa50be             bsr.l   _printf
0406629E: 2002                     move.l  d2,d0
040662A0: 4cee0c1cffec             movem.l -$14(a6),d2-d4/a2-a3
040662A6: 4e5e                     unlk    a6
040662A8: 4e75                     rts
