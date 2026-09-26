040248D6: 4856                     pea     (a6)
040248D8: 2c4f                     movea.l sp,a6
040248DA: 48e70038                 movem.l a2-a4,-(sp)
040248DE: 266e0008                 movea.l 8(a6),a3
040248E2: 246e000c                 movea.l $C(a6),a2
040248E6: 206b0020                 movea.l $20(a3),a0
040248EA: 28680018                 movea.l $18(a0),a4
040248EE: 0c6b00020008             cmpi.w  #2,8(a3)
040248F4: 6f16                     ble.s   loc_402490C
040248F6: 426b0008                 clr.w   8(a3)
040248FA: 2f0b                     move.l  a3,-(sp)
040248FC: 61fffffff746             bsr.l   _tcp_output
04024902: 52b9040bbd38             addq.l  #1,(dword_40BBD38).l
04024908: 584f                     addq.w  #4,sp
0402490A: 6006                     bra.s   loc_4024912
0402490C: 52b9040bbd3c             addq.l  #1,(dword_40BBD3C).l
04024912: 723c                     moveq   #$3C,d1 ; '<'
04024914: b28a                     cmp.l   a2,d1
04024916: 6608                     bne.s   loc_4024920
04024918: 302b006a                 move.w  $6A(a3),d0
0402491C: 6702                     beq.s   loc_4024920
0402491E: 3440                     movea.w d0,a2
04024920: 394a0050                 move.w  a2,$50(a4)
04024924: 2f0b                     move.l  a3,-(sp)
04024926: 61ff0000000e             bsr.l   _tcp_close
0402492C: 4cee1c00fff4             movem.l -$C(a6),a2-a4
04024932: 4e5e                     unlk    a6
04024934: 4e75                     rts
