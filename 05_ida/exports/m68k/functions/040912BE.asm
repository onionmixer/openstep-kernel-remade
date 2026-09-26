040912BE: 4856                     pea     (a6)
040912C0: 2c4f                     movea.l sp,a6
040912C2: 48e73020                 movem.l d2-d3/a2,-(sp)
040912C6: 48780030                 pea     ($30).w
040912CA: 45f904091b46             lea     (_rtc_read).l,a2
040912D0: 4e92                     jsr     (a2)
040912D2: 584f                     addq.w  #4,sp
040912D4: 7420                     moveq   #$20,d2 ; ' '
040912D6: 4a00                     tst.b   d0
040912D8: 6c02                     bge.s   loc_40912DC
040912DA: 7423                     moveq   #$23,d2 ; '#'
040912DC: 2f02                     move.l  d2,-(sp)
040912DE: 4e92                     jsr     (a2)
040912E0: 2600                     move.l  d0,d3
040912E2: 2e82                     move.l  d2,(sp)
040912E4: 61ff00000860             bsr.l   _rtc_read
040912EA: 584f                     addq.w  #4,sp
040912EC: b083                     cmp.l   d3,d0
040912EE: 660c                     bne.s   loc_40912FC
040912F0: 487803e8                 pea     ($3E8).w
040912F4: 61ff00001084             bsr.l   _delay
040912FA: 60e6                     bra.s   loc_40912E2
040912FC: 4280                     clr.l   d0
040912FE: 4cee040cfff4             movem.l -$C(a6),d2-d3/a2
04091304: 4e5e                     unlk    a6
04091306: 4e75                     rts
