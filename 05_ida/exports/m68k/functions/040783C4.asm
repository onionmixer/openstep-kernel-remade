040783C4: 4856                     pea     (a6)
040783C6: 2c4f                     movea.l sp,a6
040783C8: 48e73038                 movem.l d2-d3/a2-a4,-(sp)
040783CC: 266e0008                 movea.l 8(a6),a3
040783D0: 242e000c                 move.l  $C(a6),d2
040783D4: 286e0010                 movea.l $10(a6),a4
040783D8: 0802001e                 btst    #$1E,d2
040783DC: 675e                     beq.s   loc_407843C
040783DE: 4879040ab0fa             pea     (aDriveCmd).l; "drive cmd: "
040783E4: 4e94                     jsr     (a4)
040783E6: 43f9040b1df8             lea     (_od_dcmd).l,a1
040783EC: 584f                     addq.w  #4,sp
040783EE: 4ab9040b1dfc             tst.l   (off_40B1DFC).l; "seek"
040783F4: 6734                     beq.s   loc_407842A
040783F6: 4281                     clr.l   d1
040783F8: 41f9040b1dfc             lea     (off_40B1DFC).l,a0; "seek"
040783FE: 302b025a                 move.w  $25A(a3),d0
04078402: c0690002                 and.w   2(a1),d0
04078406: b051                     cmp.w   (a1),d0
04078408: 6618                     bne.s   loc_4078422
0407840A: 302b025a                 move.w  $25A(a3),d0
0407840E: 3200                     move.w  d0,d1
04078410: 2f01                     move.l  d1,-(sp)
04078412: 2f10                     move.l  (a0),-(sp)
04078414: 4879040ab106             pea     (aS0xX).l; "%s (0x%x)\n"
0407841A: 4e94                     jsr     (a4)
0407841C: 504f                     addq.w  #8,sp
0407841E: 584f                     addq.w  #4,sp
04078420: 601a                     bra.s   loc_407843C
04078422: 5048                     addq.w  #8,a0
04078424: 5049                     addq.w  #8,a1
04078426: 4a90                     tst.l   (a0)
04078428: 66d4                     bne.s   loc_40783FE
0407842A: 302b025a                 move.w  $25A(a3),d0
0407842E: 3f00                     move.w  d0,-(sp)
04078430: 4267                     clr.w   -(sp)
04078432: 4879040ab111             pea     (aUnknown0xX).l; "unknown (0x%x)\n"
04078438: 4e94                     jsr     (a4)
0407843A: 504f                     addq.w  #8,sp
0407843C: 0802001d                 btst    #$1D,d2
04078440: 6752                     beq.s   loc_4078494
04078442: 4879040ab121             pea     (aFormatterCmd).l; "formatter cmd: "
04078448: 4e94                     jsr     (a4)
0407844A: 45f9040b1ec8             lea     (_od_fcmd).l,a2
04078450: 584f                     addq.w  #4,sp
04078452: 4ab9040b1eca             tst.l   (off_40B1ECA).l; "ECC read"
04078458: 6726                     beq.s   loc_4078480
0407845A: 4281                     clr.l   d1
0407845C: 43f9040b1eca             lea     (off_40B1ECA).l,a1; "ECC read"
04078462: 102b025c                 move.b  $25C(a3),d0
04078466: 1200                     move.b  d0,d1
04078468: 3052                     movea.w (a2),a0
0407846A: b1c1                     cmpa.l  d1,a0
0407846C: 660a                     bne.s   loc_4078478
0407846E: 2f11                     move.l  (a1),-(sp)
04078470: 4879040a8b26             pea     (aS).l; "%s\n"
04078476: 6018                     bra.s   loc_4078490
04078478: 5c49                     addq.w  #6,a1
0407847A: 5c4a                     addq.w  #6,a2
0407847C: 4a91                     tst.l   (a1)
0407847E: 66e2                     bne.s   loc_4078462
04078480: 102b025c                 move.b  $25C(a3),d0
04078484: 42a7                     clr.l   -(sp)
04078486: 1f400003                 move.b  d0,$1C+var_19(sp)
0407848A: 4879040ab111             pea     (aUnknown0xX).l; "unknown (0x%x)\n"
04078490: 4e94                     jsr     (a4)
04078492: 504f                     addq.w  #8,sp
04078494: 0802000e                 btst    #$E,d2
04078498: 67000098                 beq.w   loc_4078532
0407849C: 302b024a                 move.w  $24A(a3),d0
040784A0: 0240fffe                 andi.w  #$FFFE,d0
040784A4: 6728                     beq.s   loc_40784CE
040784A6: 740f                     moveq   #$F,d2
040784A8: 4283                     clr.l   d3
040784AA: 45f9040b1cbc             lea     (unk_40B1CBC).l,a2
040784B0: 302b024a                 move.w  $24A(a3),d0
040784B4: 3600                     move.w  d0,d3
040784B6: 0503                     btst    d2,d3
040784B8: 670c                     beq.s   loc_40784C6
040784BA: 2f12                     move.l  (a2),-(sp)
040784BC: 4879040ab131             pea     (aS_2).l; "\t%s\n"
040784C2: 4e94                     jsr     (a4)
040784C4: 504f                     addq.w  #8,sp
040784C6: 514a                     subq.w  #8,a2
040784C8: 5382                     subq.l  #1,d2
040784CA: 4a82                     tst.l   d2
040784CC: 6ee2                     bgt.s   loc_40784B0
040784CE: 302b024c                 move.w  $24C(a3),d0
040784D2: 0240fffe                 andi.w  #$FFFE,d0
040784D6: 6728                     beq.s   loc_4078500
040784D8: 740f                     moveq   #$F,d2
040784DA: 4283                     clr.l   d3
040784DC: 45f9040b1d34             lea     (unk_40B1D34).l,a2
040784E2: 302b024c                 move.w  $24C(a3),d0
040784E6: 3600                     move.w  d0,d3
040784E8: 0503                     btst    d2,d3
040784EA: 670c                     beq.s   loc_40784F8
040784EC: 2f12                     move.l  (a2),-(sp)
040784EE: 4879040ab131             pea     (aS_2).l; "\t%s\n"
040784F4: 4e94                     jsr     (a4)
040784F6: 504f                     addq.w  #8,sp
040784F8: 514a                     subq.w  #8,a2
040784FA: 5382                     subq.l  #1,d2
040784FC: 4a82                     tst.l   d2
040784FE: 6ee2                     bgt.s   loc_40784E2
04078500: 302b024e                 move.w  $24E(a3),d0
04078504: 672c                     beq.s   loc_4078532
04078506: 740f                     moveq   #$F,d2
04078508: 4283                     clr.l   d3
0407850A: 45f9040b1db4             lea     (unk_40B1DB4).l,a2
04078510: 302b024e                 move.w  $24E(a3),d0
04078514: 3600                     move.w  d0,d3
04078516: 0503                     btst    d2,d3
04078518: 670c                     beq.s   loc_4078526
0407851A: 2f12                     move.l  (a2),-(sp)
0407851C: 4879040ab131             pea     (aS_2).l; "\t%s\n"
04078522: 4e94                     jsr     (a4)
04078524: 504f                     addq.w  #8,sp
04078526: 514a                     subq.w  #8,a2
04078528: 51caffe6                 dbf     d2,loc_4078510
0407852C: 4242                     clr.w   d2
0407852E: 5382                     subq.l  #1,d2
04078530: 64de                     bcc.s   loc_4078510
04078532: 4cee1c0cffec             movem.l -$14(a6),d2-d3/a2-a4
04078538: 4e5e                     unlk    a6
0407853A: 4e75                     rts
