040189B8: 4856                     pea     (a6)
040189BA: 2c4f                     movea.l sp,a6
040189BC: 48e73c20                 movem.l d2-d5/a2,-(sp)
040189C0: 282e0008                 move.l  8(a6),d4
040189C4: 246e000c                 movea.l $C(a6),a2
040189C8: 2f0a                     move.l  a2,-(sp)
040189CA: 61ff0007a71a             bsr.l   _strlen
040189D0: 2400                     move.l  d0,d2
040189D2: 584f                     addq.w  #4,sp
040189D4: 7a20                     moveq   #$20,d5 ; ' '
040189D6: ba82                     cmp.l   d2,d5
040189D8: 6d3a                     blt.s   loc_4018A14
040189DA: 1012                     move.b  (a2),d0
040189DC: 49c0                     extb.l  d0
040189DE: 123228ff                 move.b  -1(a2,d2.l),d1
040189E2: 49c1                     extb.l  d1
040189E4: d081                     add.l   d1,d0
040189E6: d082                     add.l   d2,d0
040189E8: d084                     add.l   d4,d0
040189EA: 763f                     moveq   #$3F,d3 ; '?'
040189EC: c680                     and.l   d0,d3
040189EE: 4878ffff                 pea     ($FFFFFFFF).w
040189F2: 2f03                     move.l  d3,-(sp)
040189F4: 2f02                     move.l  d2,-(sp)
040189F6: 2f0a                     move.l  a2,-(sp)
040189F8: 2f04                     move.l  d4,-(sp)
040189FA: 61ff000001b2             bsr.l   sub_4018BAE
04018A00: defc0014                 adda.w  #$14,sp
04018A04: 4a80                     tst.l   d0
04018A06: 670c                     beq.s   loc_4018A14
04018A08: 2f00                     move.l  d0,-(sp)
04018A0A: 61ff000000f2             bsr.l   sub_4018AFE
04018A10: 584f                     addq.w  #4,sp
04018A12: 60da                     bra.s   loc_40189EE
04018A14: 4cee043cffec             movem.l -$14(a6),d2-d5/a2
04018A1A: 4e5e                     unlk    a6
04018A1C: 4e75                     rts
