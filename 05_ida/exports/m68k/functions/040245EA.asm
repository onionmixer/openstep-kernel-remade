040245EA: 4856                     pea     (a6)
040245EC: 2c4f                     movea.l sp,a6
040245EE: 2f0a                     move.l  a2,-(sp)
040245F0: 2f02                     move.l  d2,-(sp)
040245F2: 246e0008                 movea.l 8(a6),a2
040245F6: 302a0060                 move.w  $60(a2),d0
040245FA: 4840                     swap    d0
040245FC: 4240                     clr.w   d0
040245FE: 7212                     moveq   #$12,d1
04024600: e2a0                     asr.l   d1,d0
04024602: 306a0062                 movea.w $62(a2),a0
04024606: d088                     add.l   a0,d0
04024608: 2400                     move.l  d0,d2
0402460A: e282                     asr.l   #1,d2
0402460C: 4a6a000a                 tst.w   $A(a2)
04024610: 670c                     beq.s   loc_402461E
04024612: 4879040a6931             pea     (aTcpOutputRexmt).l; "tcp_output REXMT"
04024618: 61fffffe764c             bsr.l   _panic
0402461E: 306a0012                 movea.w $12(a2),a0
04024622: 43f9040aeb84             lea     (_tcp_backoff).l,a1
04024628: 2002                     move.l  d2,d0
0402462A: 4c3108008c00             muls.l  (a1,a0.l*4),d0
04024630: 3540000c                 move.w  d0,$C(a2)
04024634: 0c400009                 cmpi.w  #9,d0
04024638: 6e08                     bgt.s   loc_4024642
0402463A: 357c000a000c             move.w  #$A,$C(a2)
04024640: 600c                     bra.s   loc_402464E
04024642: 0c400078                 cmpi.w  #$78,d0 ; 'x'
04024646: 6f06                     ble.s   loc_402464E
04024648: 357c0078000c             move.w  #$78,$C(a2) ; 'x'
0402464E: 302a0012                 move.w  $12(a2),d0
04024652: 0c40000b                 cmpi.w  #$B,d0
04024656: 6e06                     bgt.s   loc_402465E
04024658: 5240                     addq.w  #1,d0
0402465A: 35400012                 move.w  d0,$12(a2)
0402465E: 242efff8                 move.l  -8(a6),d2
04024662: 246efffc                 movea.l -4(a6),a2
04024666: 4e5e                     unlk    a6
04024668: 4e75                     rts
