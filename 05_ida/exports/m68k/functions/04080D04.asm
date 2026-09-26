04080D04: 4856                     pea     (a6)
04080D06: 2c4f                     movea.l sp,a6
04080D08: 202e0008                 move.l  8(a6),d0
04080D0C: 41f9040c6df4             lea     (unk_40C6DF4).l,a0
04080D12: 20700c00                 movea.l (a0,d0.l*4),a0
04080D16: 4281                     clr.l   d1
04080D18: 3228004e                 move.w  $4E(a0),d1
04080D1C: 10280053                 move.b  $53(a0),d0
04080D20: 0c000005                 cmpi.b  #5,d0
04080D24: 670c                     beq.s   loc_4080D32
04080D26: 0280000000ff             andi.l  #$FF,d0
04080D2C: 4c010800                 muls.l  d1,d0
04080D30: 6004                     bra.s   loc_4080D36
04080D32: 2001                     move.l  d1,d0
04080D34: d080                     add.l   d0,d0
04080D36: 4e5e                     unlk    a6
04080D38: 4e75                     rts
