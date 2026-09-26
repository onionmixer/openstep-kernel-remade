0405813C: 4856                     pea     (a6)
0405813E: 2c4f                     movea.l sp,a6
04058140: 2f0a                     move.l  a2,-(sp)
04058142: 246e0008                 movea.l 8(a6),a2
04058146: 206e000c                 movea.l $C(a6),a0
0405814A: 117c00010003             move.b  #1,3(a0)
04058150: 7220                     moveq   #$20,d1 ; ' '
04058152: 21410004                 move.l  d1,4(a0)
04058156: 216a00080008             move.l  8(a2),8(a0)
0405815C: 42a8000c                 clr.l   $C(a0)
04058160: 216a00100010             move.l  $10(a2),$10(a0)
04058166: 7264                     moveq   #$64,d1 ; 'd'
04058168: d2aa0014                 add.l   $14(a2),d1
0405816C: 21410014                 move.l  d1,$14(a0)
04058170: 2179040ad0ea0018         move.l  (dword_40AD0EA).l,$18(a0)
04058178: 217cfffffed1001c         move.l  #$FFFFFED1,$1C(a0)
04058180: 0caa000009600014         cmpi.l  #$960,$14(a2)
04058188: 660a                     bne.s   loc_4058194
0405818A: 2279040ad0ee             movea.l (off_40AD0EE).l,a1
04058190: 4a89                     tst.l   a1
04058192: 6604                     bne.s   loc_4058198
04058194: 4280                     clr.l   d0
04058196: 6008                     bra.s   loc_40581A0
04058198: 2f08                     move.l  a0,-(sp)
0405819A: 2f0a                     move.l  a2,-(sp)
0405819C: 4e91                     jsr     (a1)
0405819E: 7001                     moveq   #1,d0
040581A0: 246efffc                 movea.l -4(a6),a2
040581A4: 4e5e                     unlk    a6
040581A6: 4e75                     rts
