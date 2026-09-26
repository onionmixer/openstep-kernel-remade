04016366: 4856                     pea     (a6)
04016368: 2c4f                     movea.l sp,a6
0401636A: 2f0b                     move.l  a3,-(sp)
0401636C: 2f0a                     move.l  a2,-(sp)
0401636E: 266e0008                 movea.l 8(a6),a3
04016372: 246e000c                 movea.l $C(a6),a2
04016376: 226b0008                 movea.l 8(a3),a1
0401637A: 3213                     move.w  (a3),d1
0401637C: b252                     cmp.w   (a2),d1
0401637E: 6704                     beq.s   loc_4016384
04016380: 7029                     moveq   #$29,d0 ; ')'
04016382: 604c                     bra.s   loc_40163D0
04016384: 206a0008                 movea.l 8(a2),a0
04016388: 2348000c                 move.l  a0,$C(a1)
0401638C: 3013                     move.w  (a3),d0
0401638E: 0c400001                 cmpi.w  #1,d0
04016392: 671a                     beq.s   loc_40163AE
04016394: 0c400002                 cmpi.w  #2,d0
04016398: 6628                     bne.s   loc_40163C2
0401639A: 236800100014             move.l  $10(a0),$14(a1)
040163A0: 21490010                 move.l  a1,$10(a0)
040163A4: 2f0b                     move.l  a3,-(sp)
040163A6: 61ffffffd978             bsr.l   _soisconnected
040163AC: 6020                     bra.s   loc_40163CE
040163AE: 2149000c                 move.l  a1,$C(a0)
040163B2: 2f0a                     move.l  a2,-(sp)
040163B4: 45f904013d20             lea     (_soisconnected).l,a2
040163BA: 4e92                     jsr     (a2)
040163BC: 2f0b                     move.l  a3,-(sp)
040163BE: 4e92                     jsr     (a2)
040163C0: 600c                     bra.s   loc_40163CE
040163C2: 4879040a64cf             pea     (aUnpConnect2).l; "unp_connect2"
040163C8: 61ffffff589c             bsr.l   _panic
040163CE: 4280                     clr.l   d0
040163D0: 246efff8                 movea.l -8(a6),a2
040163D4: 266efffc                 movea.l -4(a6),a3
040163D8: 4e5e                     unlk    a6
040163DA: 4e75                     rts
