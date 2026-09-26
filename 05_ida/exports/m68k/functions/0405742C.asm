0405742C: 4856                     pea     (a6)
0405742E: 2c4f                     movea.l sp,a6
04057430: 2f0b                     move.l  a3,-(sp)
04057432: 2f0a                     move.l  a2,-(sp)
04057434: 266e0008                 movea.l 8(a6),a3
04057438: 202b0014                 move.l  $14(a3),d0
0405743C: 0c8000076543             cmpi.l  #$76543,d0
04057442: 663a                     bne.s   loc_405747E
04057444: 48780014                 pea     ($14).w
04057448: 61ffffff2db6             bsr.l   _kalloc
0405744E: 2440                     movea.l d0,a2
04057450: 256b001c0008             move.l  $1C(a3),8(a2)
04057456: 256b0020000c             move.l  $20(a3),$C(a2)
0405745C: 256b00280010             move.l  $28(a3),$10(a2)
04057462: 41f9040b4dec             lea     (dword_40B4DEC).l,a0
04057468: 2250                     movea.l (a0),a1
0405746A: 228a                     move.l  a2,(a1)
0405746C: 25490004                 move.l  a1,4(a2)
04057470: 24bc040b4de8             move.l  #$40B4DE8,(a2)
04057476: 23ca040b4dec             move.l  a2,(dword_40B4DEC).l
0405747C: 600e                     bra.s   loc_405748C
0405747E: 2f00                     move.l  d0,-(sp)
04057480: 4879040a9386             pea     (aNotifyServerBo).l; "notify server: bogus msg_id on pn_regis"...
04057486: 61fffffb3ed0             bsr.l   _printf
0405748C: 246efff8                 movea.l -8(a6),a2
04057490: 266efffc                 movea.l -4(a6),a3
04057494: 4e5e                     unlk    a6
04057496: 4e75                     rts
