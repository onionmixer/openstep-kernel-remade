040216C8: 4e56fffc                 link    a6,#-4
040216CC: 48e73f38                 movem.l d2-d7/a2-a4,-(sp)
040216D0: 246e0008                 movea.l arg_0(a6),a2
040216D4: 2c2e000c                 move.l  arg_4(a6),d6
040216D8: 4284                     clr.l   d4
040216DA: 42aefffc                 clr.l   var_4(a6)
040216DE: 4ab9040aeb24             tst.l   (_ipprintfs).l
040216E4: 6720                     beq.s   loc_4021706
040216E6: 4280                     clr.l   d0
040216E8: 102a0008                 move.b  8(a2),d0
040216EC: 2f00                     move.l  d0,-(sp)
040216EE: 2f2a0010                 move.l  $10(a2),-(sp)
040216F2: 2f2a000c                 move.l  $C(a2),-(sp)
040216F6: 4879040a68e0             pea     (aForwardSrcXDst).l; "forward: src %x dst %x ttl %x\n"
040216FC: 61fffffe9c5a             bsr.l   _printf
04021702: 504f                     addq.w  #8,sp
04021704: 504f                     addq.w  #8,sp
04021706: 4ab9040aeb28             tst.l   (_ipforwarding).l
0402170C: 670a                     beq.s   loc_4021718
0402170E: 7401                     moveq   #1,d2
04021710: b4b9040b7bcc             cmp.l   (_in_interfaces).l,d2
04021716: 6d08                     blt.s   loc_4021720
04021718: 52b9040b68c8             addq.l  #1,(dword_40B68C8).l
0402171E: 6010                     bra.s   loc_4021730
04021720: 2f2a0010                 move.l  $10(a2),-(sp)
04021724: 61ffffffd762             bsr.l   _in_canforward
0402172A: 584f                     addq.w  #4,sp
0402172C: 4a80                     tst.l   d0
0402172E: 6612                     bne.s   loc_4021742
04021730: 2e0a                     move.l  a2,d7
04021732: 7480                     moveq   #$FFFFFF80,d2
04021734: ce82                     and.l   d2,d7
04021736: 2f07                     move.l  d7,-(sp)
04021738: 61ffffff0a6c             bsr.l   _m_freem
0402173E: 60000330                 bra.w   loc_4021A70
04021742: 102a0008                 move.b  8(a2),d0
04021746: 0c000001                 cmpi.b  #1,d0
0402174A: 6208                     bhi.s   loc_4021754
0402174C: 780b                     moveq   #$B,d4
0402174E: 4283                     clr.l   d3
04021750: 6000030c                 bra.w   loc_4021A5E
04021754: 5300                     subq.b  #1,d0
04021756: 15400008                 move.b  d0,8(a2)
0402175A: 48780040                 pea     ($40).w
0402175E: 326a0002                 movea.w 2(a2),a1
04021762: 2f09                     move.l  a1,-(sp)
04021764: 61fffffea7b0             bsr.l   _imin
0402176A: 2f00                     move.l  d0,-(sp)
0402176C: 42a7                     clr.l   -(sp)
0402176E: 240a                     move.l  a2,d2
04021770: 7e80                     moveq   #$FFFFFF80,d7
04021772: c487                     and.l   d7,d2
04021774: 2f02                     move.l  d2,-(sp)
04021776: 61ffffff0ad8             bsr.l   _m_copy
0402177C: 2840                     movea.l d0,a4
0402177E: 47f9040b7d90             lea     (unk_40B7D90).l,a3
04021784: defc0014                 adda.w  #$14,sp
04021788: 222bfffc                 move.l  -4(a3),d1
0402178C: 6738                     beq.s   loc_40217C6
0402178E: 226a0010                 movea.l $10(a2),a1
04021792: b3f9040b7d94             cmpa.l  (dword_40B7D94).l,a1
04021798: 6744                     beq.s   loc_40217DE
0402179A: 4a81                     tst.l   d1
0402179C: 6728                     beq.s   loc_40217C6
0402179E: 2079040b7d8c             movea.l (_ipforward_rt).l,a0
040217A4: 30280026                 move.w  $26(a0),d0
040217A8: 0c400001                 cmpi.w  #1,d0
040217AC: 660c                     bne.s   loc_40217BA
040217AE: 2f01                     move.l  d1,-(sp)
040217B0: 61ffffffc158             bsr.l   _rtfree
040217B6: 584f                     addq.w  #4,sp
040217B8: 6006                     bra.s   loc_40217C0
040217BA: 5340                     subq.w  #1,d0
040217BC: 31400026                 move.w  d0,$26(a0)
040217C0: 42b9040b7d8c             clr.l   (_ipforward_rt).l
040217C6: 36bc0002                 move.w  #2,(a3)
040217CA: 276a00100004             move.l  $10(a2),4(a3)
040217D0: 4879040b7d8c             pea     (_ipforward_rt).l
040217D6: 61ffffffc010             bsr.l   _rtalloc
040217DC: 584f                     addq.w  #4,sp
040217DE: 4ab9040b7d8c             tst.l   (_ipforward_rt).l
040217E4: 670000dc                 beq.w   loc_40218C2
040217E8: 2079040b7d8c             movea.l (_ipforward_rt).l,a0
040217EE: bca8002c                 cmp.l   $2C(a0),d6
040217F2: 660000ce                 bne.w   loc_40218C2
040217F6: 30280024                 move.w  $24(a0),d0
040217FA: 02400030                 andi.w  #$30,d0 ; '0'
040217FE: 660000c2                 bne.w   loc_40218C2
04021802: 4aa80008                 tst.l   8(a0)
04021806: 670000ba                 beq.w   loc_40218C2
0402180A: 4ab9040aeb2c             tst.l   (_ipsendredirects).l
04021810: 670000b0                 beq.w   loc_40218C2
04021814: 1012                     move.b  (a2),d0
04021816: 740f                     moveq   #$F,d2
04021818: c082                     and.l   d2,d0
0402181A: 7e05                     moveq   #5,d7
0402181C: be80                     cmp.l   d0,d7
0402181E: 660000a2                 bne.w   loc_40218C2
04021822: 266a000c                 movea.l $C(a2),a3
04021826: 2a2a0010                 move.l  $10(a2),d5
0402182A: 2f06                     move.l  d6,-(sp)
0402182C: 61ffffffee16             bsr.l   _ifptoia
04021832: 2040                     movea.l d0,a0
04021834: 584f                     addq.w  #4,sp
04021836: 4a88                     tst.l   a0
04021838: 67000088                 beq.w   loc_40218C2
0402183C: 200b                     move.l  a3,d0
0402183E: c0a80034                 and.l   $34(a0),d0
04021842: b0a80030                 cmp.l   $30(a0),d0
04021846: 667a                     bne.s   loc_40218C2
04021848: 2079040b7d8c             movea.l (_ipforward_rt).l,a0
0402184E: 082800010025             btst    #1,$25(a0)
04021854: 6708                     beq.s   loc_402185E
04021856: 2d680018fffc             move.l  $18(a0),var_4(a6)
0402185C: 6006                     bra.s   loc_4021864
0402185E: 2d6a0010fffc             move.l  $10(a2),var_4(a6)
04021864: 7805                     moveq   #5,d4
04021866: 4283                     clr.l   d3
04021868: 2079040b7d8c             movea.l (_ipforward_rt).l,a0
0402186E: 30280024                 move.w  $24(a0),d0
04021872: 02400006                 andi.w  #6,d0
04021876: 0c400002                 cmpi.w  #2,d0
0402187A: 661c                     bne.s   loc_4021898
0402187C: 2079040b7bb4             movea.l (_in_ifaddr).l,a0
04021882: 6018                     bra.s   loc_402189C
04021884: 2228002c                 move.l  $2C(a0),d1
04021888: 2005                     move.l  d5,d0
0402188A: c081                     and.l   d1,d0
0402188C: b0a80028                 cmp.l   $28(a0),d0
04021890: 660a                     bne.s   loc_402189C
04021892: b2a80034                 cmp.l   $34(a0),d1
04021896: 670c                     beq.s   loc_40218A4
04021898: 7601                     moveq   #1,d3
0402189A: 6008                     bra.s   loc_40218A4
0402189C: 20680040                 movea.l $40(a0),a0
040218A0: 4a88                     tst.l   a0
040218A2: 66e0                     bne.s   loc_4021884
040218A4: 4ab9040aeb24             tst.l   (_ipprintfs).l
040218AA: 6716                     beq.s   loc_40218C2
040218AC: 2f2efffc                 move.l  var_4(a6),-(sp)
040218B0: 2f03                     move.l  d3,-(sp)
040218B2: 4879040a68ff             pea     (aRedirectDToX).l; "redirect (%d) to %x\n"
040218B8: 61fffffe9a9e             bsr.l   _printf
040218BE: 504f                     addq.w  #8,sp
040218C0: 584f                     addq.w  #4,sp
040218C2: 48780001                 pea     (1).w
040218C6: 4879040b7d8c             pea     (_ipforward_rt).l
040218CC: 42a7                     clr.l   -(sp)
040218CE: 240a                     move.l  a2,d2
040218D0: 7e80                     moveq   #$FFFFFF80,d7
040218D2: c487                     and.l   d7,d2
040218D4: 2f02                     move.l  d2,-(sp)
040218D6: 61ff000001a2             bsr.l   _ip_output
040218DC: 504f                     addq.w  #8,sp
040218DE: 504f                     addq.w  #8,sp
040218E0: 4a80                     tst.l   d0
040218E2: 6708                     beq.s   loc_40218EC
040218E4: 52b9040b68c8             addq.l  #1,(dword_40B68C8).l
040218EA: 6022                     bra.s   loc_402190E
040218EC: 4a84                     tst.l   d4
040218EE: 6708                     beq.s   loc_40218F8
040218F0: 52b9040b68cc             addq.l  #1,(dword_40B68CC).l
040218F6: 6016                     bra.s   loc_402190E
040218F8: 4a8c                     tst.l   a4
040218FA: 6708                     beq.s   loc_4021904
040218FC: 2f0c                     move.l  a4,-(sp)
040218FE: 61ffffff08a6             bsr.l   _m_freem
04021904: 52b9040b68c4             addq.l  #1,(dword_40B68C4).l
0402190A: 60000164                 bra.w   loc_4021A70
0402190E: 4a8c                     tst.l   a4
04021910: 6700015e                 beq.w   loc_4021A70
04021914: 244c                     movea.l a4,a2
04021916: d5ec0004                 adda.l  4(a4),a2
0402191A: 7803                     moveq   #3,d4
0402191C: 7441                     moveq   #$41,d2 ; 'A'
0402191E: b480                     cmp.l   d0,d2
04021920: 6500013c                 bcs.w   loc_4021A5E
04021924: 207c04021930             movea.l #$4021930,a0
0402192A: 20700c00                 movea.l (a0,d0.l*4),a0
0402192E: 4ed0                     jmp     (a0)
04021930: 04021a38                 subi.b  #$38,d2 ; '8'
04021934: 04021a54                 subi.b  #$54,d2 ; 'T'
04021938: 04021a5e                 subi.b  #$5E,d2 ; '^'
0402193C: 04021a5e                 subi.b  #$5E,d2 ; '^'
04021940: 04021a5e                 subi.b  #$5E,d2 ; '^'
04021944: 04021a5e                 subi.b  #$5E,d2 ; '^'
04021948: 04021a5e                 subi.b  #$5E,d2 ; '^'
0402194C: 04021a5e                 subi.b  #$5E,d2 ; '^'
04021950: 04021a5e                 subi.b  #$5E,d2 ; '^'
04021954: 04021a5e                 subi.b  #$5E,d2 ; '^'
04021958: 04021a5e                 subi.b  #$5E,d2 ; '^'
0402195C: 04021a5e                 subi.b  #$5E,d2 ; '^'
04021960: 04021a5e                 subi.b  #$5E,d2 ; '^'
04021964: 04021a5e                 subi.b  #$5E,d2 ; '^'
04021968: 04021a5e                 subi.b  #$5E,d2 ; '^'
0402196C: 04021a5e                 subi.b  #$5E,d2 ; '^'
04021970: 04021a5e                 subi.b  #$5E,d2 ; '^'
04021974: 04021a5e                 subi.b  #$5E,d2 ; '^'
04021978: 04021a5e                 subi.b  #$5E,d2 ; '^'
0402197C: 04021a5e                 subi.b  #$5E,d2 ; '^'
04021980: 04021a5e                 subi.b  #$5E,d2 ; '^'
04021984: 04021a5e                 subi.b  #$5E,d2 ; '^'
04021988: 04021a5e                 subi.b  #$5E,d2 ; '^'
0402198C: 04021a5e                 subi.b  #$5E,d2 ; '^'
04021990: 04021a5e                 subi.b  #$5E,d2 ; '^'
04021994: 04021a5e                 subi.b  #$5E,d2 ; '^'
04021998: 04021a5e                 subi.b  #$5E,d2 ; '^'
0402199C: 04021a5e                 subi.b  #$5E,d2 ; '^'
040219A0: 04021a5e                 subi.b  #$5E,d2 ; '^'
040219A4: 04021a5e                 subi.b  #$5E,d2 ; '^'
040219A8: 04021a5e                 subi.b  #$5E,d2 ; '^'
040219AC: 04021a5e                 subi.b  #$5E,d2 ; '^'
040219B0: 04021a5e                 subi.b  #$5E,d2 ; '^'
040219B4: 04021a5e                 subi.b  #$5E,d2 ; '^'
040219B8: 04021a5e                 subi.b  #$5E,d2 ; '^'
040219BC: 04021a5e                 subi.b  #$5E,d2 ; '^'
040219C0: 04021a5e                 subi.b  #$5E,d2 ; '^'
040219C4: 04021a5e                 subi.b  #$5E,d2 ; '^'
040219C8: 04021a5e                 subi.b  #$5E,d2 ; '^'
040219CC: 04021a5e                 subi.b  #$5E,d2 ; '^'
040219D0: 04021a50                 subi.b  #$50,d2 ; 'P'
040219D4: 04021a5e                 subi.b  #$5E,d2 ; '^'
040219D8: 04021a5e                 subi.b  #$5E,d2 ; '^'
040219DC: 04021a5e                 subi.b  #$5E,d2 ; '^'
040219E0: 04021a5e                 subi.b  #$5E,d2 ; '^'
040219E4: 04021a5e                 subi.b  #$5E,d2 ; '^'
040219E8: 04021a5e                 subi.b  #$5E,d2 ; '^'
040219EC: 04021a5e                 subi.b  #$5E,d2 ; '^'
040219F0: 04021a5e                 subi.b  #$5E,d2 ; '^'
040219F4: 04021a5e                 subi.b  #$5E,d2 ; '^'
040219F8: 04021a3c                 subi.b  #$3C,d2 ; '<'
040219FC: 04021a3c                 subi.b  #$3C,d2 ; '<'
04021A00: 04021a5e                 subi.b  #$5E,d2 ; '^'
04021A04: 04021a5e                 subi.b  #$5E,d2 ; '^'
04021A08: 04021a5e                 subi.b  #$5E,d2 ; '^'
04021A0C: 04021a58                 subi.b  #$58,d2 ; 'X'
04021A10: 04021a5e                 subi.b  #$5E,d2 ; '^'
04021A14: 04021a5e                 subi.b  #$5E,d2 ; '^'
04021A18: 04021a5e                 subi.b  #$5E,d2 ; '^'
04021A1C: 04021a5e                 subi.b  #$5E,d2 ; '^'
04021A20: 04021a5e                 subi.b  #$5E,d2 ; '^'
04021A24: 04021a5e                 subi.b  #$5E,d2 ; '^'
04021A28: 04021a5e                 subi.b  #$5E,d2 ; '^'
04021A2C: 04021a5e                 subi.b  #$5E,d2 ; '^'
04021A30: 04021a5c                 subi.b  #$5C,d2 ; '\'
04021A34: 04021a5c                 subi.b  #$5C,d2 ; '\'
04021A38: 7805                     moveq   #5,d4
04021A3A: 6022                     bra.s   loc_4021A5E
04021A3C: 2f2a0010                 move.l  $10(a2),-(sp)
04021A40: 61ffffffd3ee             bsr.l   _in_localaddr
04021A46: 584f                     addq.w  #4,sp
04021A48: 4283                     clr.l   d3
04021A4A: 4a80                     tst.l   d0
04021A4C: 6710                     beq.s   loc_4021A5E
04021A4E: 600c                     bra.s   loc_4021A5C
04021A50: 7604                     moveq   #4,d3
04021A52: 600a                     bra.s   loc_4021A5E
04021A54: 7603                     moveq   #3,d3
04021A56: 6006                     bra.s   loc_4021A5E
04021A58: 7804                     moveq   #4,d4
04021A5A: 6002                     bra.s   loc_4021A5E
04021A5C: 7601                     moveq   #1,d3
04021A5E: 486efffc                 pea     var_4(a6)
04021A62: 2f06                     move.l  d6,-(sp)
04021A64: 2f03                     move.l  d3,-(sp)
04021A66: 2f04                     move.l  d4,-(sp)
04021A68: 2f0a                     move.l  a2,-(sp)
04021A6A: 61ffffffe4dc             bsr.l   _icmp_error
04021A70: 4cee1cfcffd8             movem.l var_28(a6),d2-d7/a2-a4
04021A76: 4e5e                     unlk    a6
04021A78: 4e75                     rts
