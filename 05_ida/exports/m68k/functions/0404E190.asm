0404E190: 4856                     pea     (a6)
0404E192: 2c4f                     movea.l sp,a6
0404E194: 2f0a                     move.l  a2,-(sp)
0404E196: 2f02                     move.l  d2,-(sp)
0404E198: 242e0008                 move.l  8(a6),d2
0404E19C: 23ee0010040c2418         move.l  $10(a6),(_miniMonState).l
0404E1A4: 4aae000c                 tst.l   $C(a6)
0404E1A8: 6764                     beq.s   loc_404E20E
0404E1AA: 4879040a8b17             pea     (aSystemPanic_0).l; "System Panic:\n"
0404E1B0: 45f90404e2e4             lea     (_safe_prf).l,a2
0404E1B6: 4e92                     jsr     (a2)
0404E1B8: 2f39040b69c8             move.l  (_panicstr).l,-(sp)
0404E1BE: 4879040a8b26             pea     (aS).l; "%s\n"
0404E1C4: 4e92                     jsr     (a2)
0404E1C6: 504f                     addq.w  #8,sp
0404E1C8: 2ebc040a8b2a             move.l  #$40A8B2A,(sp)
0404E1CE: 4e92                     jsr     (a2)
0404E1D0: 584f                     addq.w  #4,sp
0404E1D2: 61ff000468c6             bsr.l   _miniMonTryGetchar
0404E1D8: 7272                     moveq   #$72,d1 ; 'r'
0404E1DA: b280                     cmp.l   d0,d1
0404E1DC: 661c                     bne.s   loc_404E1FA
0404E1DE: 4879040a8b52             pea     (aRebooting).l; "\nRebooting..."
0404E1E4: 61ff000000fe             bsr.l   _safe_prf
0404E1EA: 4879040a62e7             pea     (unk_40A62E7).l
0404E1F0: 61ff0004688a             bsr.l   _miniMonReboot
0404E1F6: 504f                     addq.w  #8,sp
0404E1F8: 60d8                     bra.s   loc_404E1D2
0404E1FA: 726d                     moveq   #$6D,d1 ; 'm'
0404E1FC: b280                     cmp.l   d0,d1
0404E1FE: 66d2                     bne.s   loc_404E1D2
0404E200: 4879040a6049             pea     (asc_40A6049).l; "\n"
0404E206: 61ff000000dc             bsr.l   _safe_prf
0404E20C: 584f                     addq.w  #4,sp
0404E20E: 4879040a8b60             pea     (aNextstepMiniMo).l; "NEXTSTEP Mini-monitor\n"
0404E214: 61ff000000ce             bsr.l   _safe_prf
0404E21A: 584f                     addq.w  #4,sp
0404E21C: 2f02                     move.l  d2,-(sp)
0404E21E: 4879040a8b77             pea     (aS_0).l; "%s> "
0404E224: 61ff000000be             bsr.l   _safe_prf
0404E22A: 48780080                 pea     ($80).w
0404E22E: 4879040b393a             pea     (unk_40B393A).l
0404E234: 61fffffffe9c             bsr.l   sub_404E0D2
0404E23A: 4879040b393a             pea     (unk_40B393A).l
0404E240: 61fffffffe04             bsr.l   sub_404E046
0404E246: defc0014                 adda.w  #$14,sp
0404E24A: 4a80                     tst.l   d0
0404E24C: 66ce                     bne.s   loc_404E21C
0404E24E: 242efff8                 move.l  -8(a6),d2
0404E252: 246efffc                 movea.l -4(a6),a2
0404E256: 4e5e                     unlk    a6
0404E258: 4e75                     rts
