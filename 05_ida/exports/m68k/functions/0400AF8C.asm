0400AF8C: 4856                     pea     (a6)
0400AF8E: 2c4f                     movea.l sp,a6
0400AF90: 48e73020                 movem.l d2-d3/a2,-(sp)
0400AF94: 246e0008                 movea.l 8(a6),a2
0400AF98: 202e000c                 move.l  $C(a6),d0
0400AF9C: 7620                     moveq   #$20,d3 ; ' '
0400AF9E: b680                     cmp.l   d0,d3
0400AFA0: 654a                     bcs.s   loc_400AFEC
0400AFA2: 5380                     subq.l  #1,d0
0400AFA4: 7201                     moveq   #1,d1
0400AFA6: 2401                     move.l  d1,d2
0400AFA8: e1a2                     asl.l   d0,d2
0400AFAA: 2002                     move.l  d2,d0
0400AFAC: 028000001ef8             andi.l  #$1EF8,d0
0400AFB2: 6618                     bne.s   loc_400AFCC
0400AFB4: 4879040a6248             pea     (aSignalD).l; "signal = %d\n"
0400AFBA: 61ff0000039c             bsr.l   _printf
0400AFC0: 4879040a6255             pea     (aThreadPsignalS).l; "thread_psignal: signal is not an except"...
0400AFC6: 61ff00000c9e             bsr.l   _panic
0400AFCC: 206a000c                 movea.l $C(a2),a0
0400AFD0: 20680034                 movea.l $34(a0),a0
0400AFD4: 20280020                 move.l  $20(a0),d0
0400AFD8: c082                     and.l   d2,d0
0400AFDA: 6708                     beq.s   loc_400AFE4
0400AFDC: 08280004002b             btst    #4,$2B(a0)
0400AFE2: 6708                     beq.s   loc_400AFEC
0400AFE4: 206a0080                 movea.l $80(a2),a0
0400AFE8: 85a80072                 or.l    d2,$72(a0)
0400AFEC: 4cee040cfff4             movem.l -$C(a6),d2-d3/a2
0400AFF2: 4e5e                     unlk    a6
0400AFF4: 4e75                     rts
