0406CFB6: 4856                     pea     (a6)
0406CFB8: 2c4f                     movea.l sp,a6
0406CFBA: 2f0b                     move.l  a3,-(sp)
0406CFBC: 2f0a                     move.l  a2,-(sp)
0406CFBE: 246e0008                 movea.l 8(a6),a2
0406CFC2: 266e000c                 movea.l $C(a6),a3
0406CFC6: 48780040                 pea     ($40).w
0406CFCA: 2f0a                     move.l  a2,-(sp)
0406CFCC: 61ff0000001a             bsr.l   sub_406CFE8
0406CFD2: 4a80                     tst.l   d0
0406CFD4: 6606                     bne.s   loc_406CFDC
0406CFD6: 2052                     movea.l (a2),a0
0406CFD8: 16a80005                 move.b  5(a0),(a3)
0406CFDC: 246efff8                 movea.l -8(a6),a2
0406CFE0: 266efffc                 movea.l -4(a6),a3
0406CFE4: 4e5e                     unlk    a6
0406CFE6: 4e75                     rts
