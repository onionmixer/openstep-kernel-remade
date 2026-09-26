0400A968: 4e56ffdc                 link    a6,#-$24
0400A96C: 48e7203c                 movem.l d2/a2-a5,-(sp)
0400A970: 2079040b57d4             movea.l (dword_40B57D4).l,a0
0400A976: 24680024                 movea.l $24(a0),a2
0400A97A: 49eeffdc                 lea     var_24(a6),a4
0400A97E: 2f0c                     move.l  a4,-(sp)
0400A980: 48780020                 pea     ($20).w
0400A984: 2f12                     move.l  (a2),-(sp)
0400A986: 4879040a61d4             pea     (aNextstep).l; "NEXTSTEP"
0400A98C: 4bf90400159a             lea     (_copyoutstr).l,a5
0400A992: 4e95                     jsr     (a5)
0400A994: 2079040b57d4             movea.l (dword_40B57D4).l,a0
0400A99A: 11400064                 move.b  d0,$64(a0)
0400A99E: 2079040b57d4             movea.l (dword_40B57D4).l,a0
0400A9A4: 504f                     addq.w  #8,sp
0400A9A6: 504f                     addq.w  #8,sp
0400A9A8: 4a280064                 tst.b   $64(a0)
0400A9AC: 660001e2                 bne.w   loc_400AB90
0400A9B0: 2f0c                     move.l  a4,-(sp)
0400A9B2: 48780020                 pea     ($20).w
0400A9B6: 7220                     moveq   #$20,d1 ; ' '
0400A9B8: d292                     add.l   (a2),d1
0400A9BA: 2f01                     move.l  d1,-(sp)
0400A9BC: 4879040b5cb4             pea     (_hostname).l
0400A9C2: 4e95                     jsr     (a5)
0400A9C4: 2079040b57d4             movea.l (dword_40B57D4).l,a0
0400A9CA: 11400064                 move.b  d0,$64(a0)
0400A9CE: 2079040b57d4             movea.l (dword_40B57D4).l,a0
0400A9D4: 504f                     addq.w  #8,sp
0400A9D6: 504f                     addq.w  #8,sp
0400A9D8: 4a280064                 tst.b   $64(a0)
0400A9DC: 660001b2                 bne.w   loc_400AB90
0400A9E0: 42a7                     clr.l   -(sp)
0400A9E2: 4879040a61dd             pea     (aD_0).l; "%d"
0400A9E8: 47eeffe0                 lea     var_20(a6),a3
0400A9EC: 2f0b                     move.l  a3,-(sp)
0400A9EE: 243c0400b41c             move.l  #$400B41C,d2
0400A9F4: 2242                     movea.l d2,a1
0400A9F6: 4e91                     jsr     (a1)
0400A9F8: 2f0c                     move.l  a4,-(sp)
0400A9FA: 48780020                 pea     ($20).w
0400A9FE: 7240                     moveq   #$40,d1 ; '@'
0400AA00: d292                     add.l   (a2),d1
0400AA02: 2f01                     move.l  d1,-(sp)
0400AA04: 2f0b                     move.l  a3,-(sp)
0400AA06: 4e95                     jsr     (a5)
0400AA08: 2079040b57d4             movea.l (dword_40B57D4).l,a0
0400AA0E: 11400064                 move.b  d0,$64(a0)
0400AA12: 2079040b57d4             movea.l (dword_40B57D4).l,a0
0400AA18: defc001c                 adda.w  #$1C,sp
0400AA1C: 4a280064                 tst.b   $64(a0)
0400AA20: 6600016e                 bne.w   loc_400AB90
0400AA24: 48780004                 pea     (4).w
0400AA28: 4879040a61dd             pea     (aD_0).l; "%d"
0400AA2E: 2f0b                     move.l  a3,-(sp)
0400AA30: 2242                     movea.l d2,a1
0400AA32: 4e91                     jsr     (a1)
0400AA34: 2f0c                     move.l  a4,-(sp)
0400AA36: 48780020                 pea     ($20).w
0400AA3A: 7260                     moveq   #$60,d1 ; '`'
0400AA3C: d292                     add.l   (a2),d1
0400AA3E: 2f01                     move.l  d1,-(sp)
0400AA40: 2f0b                     move.l  a3,-(sp)
0400AA42: 4e95                     jsr     (a5)
0400AA44: 2079040b57d4             movea.l (dword_40B57D4).l,a0
0400AA4A: 11400064                 move.b  d0,$64(a0)
0400AA4E: 2079040b57d4             movea.l (dword_40B57D4).l,a0
0400AA54: defc001c                 adda.w  #$1C,sp
0400AA58: 4a280064                 tst.b   $64(a0)
0400AA5C: 66000132                 bne.w   loc_400AB90
0400AA60: 4280                     clr.l   d0
0400AA62: 1039040b61ac             move.b  (_machine_type).l,d0
0400AA68: 7209                     moveq   #9,d1
0400AA6A: b280                     cmp.l   d0,d1
0400AA6C: 650000fc                 bcs.w   loc_400AB6A
0400AA70: 207c0400aa7c             movea.l #$400AA7C,a0
0400AA76: 20700c00                 movea.l (a0,d0.l*4),a0
0400AA7A: 4ed0                     jmp     (a0)
0400AA7C: 0400aaa4                 subi.b  #$A4,d0
0400AA80: 0400aabe                 subi.b  #$BE,d0
0400AA84: 0400aad8                 subi.b  #$D8,d0
0400AA88: 0400aaf2                 subi.b  #$F2,d0
0400AA8C: 0400ab0a                 subi.b  #$A,d0
0400AA90: 0400ab22                 subi.b  #$22,d0 ; '"'
0400AA94: 0400ab6a                 subi.b  #$6A,d0 ; 'j'
0400AA98: 0400ab6a                 subi.b  #$6A,d0 ; 'j'
0400AA9C: 0400ab3a                 subi.b  #$3A,d0 ; ':'
0400AAA0: 0400ab52                 subi.b  #$52,d0 ; 'R'
0400AAA4: 486effdc                 pea     var_24(a6)
0400AAA8: 48780020                 pea     ($20).w
0400AAAC: 2452                     movea.l (a2),a2
0400AAAE: d4fc0080                 adda.w  #$80,a2
0400AAB2: 2f0a                     move.l  a2,-(sp)
0400AAB4: 4879040a61e0             pea     (aNextCube).l; "NeXT_CUBE"
0400AABA: 600000c4                 bra.w   loc_400AB80
0400AABE: 486effdc                 pea     var_24(a6)
0400AAC2: 48780020                 pea     ($20).w
0400AAC6: 2452                     movea.l (a2),a2
0400AAC8: d4fc0080                 adda.w  #$80,a2
0400AACC: 2f0a                     move.l  a2,-(sp)
0400AACE: 4879040a61ea             pea     (aNextWarp9).l; "NeXT_WARP9"
0400AAD4: 600000aa                 bra.w   loc_400AB80
0400AAD8: 486effdc                 pea     var_24(a6)
0400AADC: 48780020                 pea     ($20).w
0400AAE0: 2452                     movea.l (a2),a2
0400AAE2: d4fc0080                 adda.w  #$80,a2
0400AAE6: 2f0a                     move.l  a2,-(sp)
0400AAE8: 4879040a61f5             pea     (aNextX15).l; "NeXT_X15"
0400AAEE: 60000090                 bra.w   loc_400AB80
0400AAF2: 486effdc                 pea     var_24(a6)
0400AAF6: 48780020                 pea     ($20).w
0400AAFA: 2452                     movea.l (a2),a2
0400AAFC: d4fc0080                 adda.w  #$80,a2
0400AB00: 2f0a                     move.l  a2,-(sp)
0400AB02: 4879040a61fe             pea     (aNextWarp9c).l; "NeXT_WARP9C"
0400AB08: 6076                     bra.s   loc_400AB80
0400AB0A: 486effdc                 pea     var_24(a6)
0400AB0E: 48780020                 pea     ($20).w
0400AB12: 2452                     movea.l (a2),a2
0400AB14: d4fc0080                 adda.w  #$80,a2
0400AB18: 2f0a                     move.l  a2,-(sp)
0400AB1A: 4879040a620a             pea     (aNextTurbo).l; "NeXT_Turbo"
0400AB20: 605e                     bra.s   loc_400AB80
0400AB22: 486effdc                 pea     var_24(a6)
0400AB26: 48780020                 pea     ($20).w
0400AB2A: 2452                     movea.l (a2),a2
0400AB2C: d4fc0080                 adda.w  #$80,a2
0400AB30: 2f0a                     move.l  a2,-(sp)
0400AB32: 4879040a6215             pea     (aNextTurboc).l; "NeXT_TurboC"
0400AB38: 6046                     bra.s   loc_400AB80
0400AB3A: 486effdc                 pea     var_24(a6)
0400AB3E: 48780020                 pea     ($20).w
0400AB42: 2452                     movea.l (a2),a2
0400AB44: d4fc0080                 adda.w  #$80,a2
0400AB48: 2f0a                     move.l  a2,-(sp)
0400AB4A: 4879040a6221             pea     (aNextTurbocube).l; "NeXT_TurboCube"
0400AB50: 602e                     bra.s   loc_400AB80
0400AB52: 486effdc                 pea     var_24(a6)
0400AB56: 48780020                 pea     ($20).w
0400AB5A: 2452                     movea.l (a2),a2
0400AB5C: d4fc0080                 adda.w  #$80,a2
0400AB60: 2f0a                     move.l  a2,-(sp)
0400AB62: 4879040a6230             pea     (aNextTurbocubec).l; "NeXT_TurboCubeC"
0400AB68: 6016                     bra.s   loc_400AB80
0400AB6A: 486effdc                 pea     var_24(a6)
0400AB6E: 48780020                 pea     ($20).w
0400AB72: 2452                     movea.l (a2),a2
0400AB74: d4fc0080                 adda.w  #$80,a2
0400AB78: 2f0a                     move.l  a2,-(sp)
0400AB7A: 4879040a6240             pea     (aUnknown).l; "Unknown"
0400AB80: 61ffffff6a18             bsr.l   _copyoutstr
0400AB86: 2079040b57d4             movea.l (dword_40B57D4).l,a0
0400AB8C: 11400064                 move.b  d0,$64(a0)
0400AB90: 4cee3c04ffc8             movem.l var_38(a6),d2/a2-a5
0400AB96: 4e5e                     unlk    a6
0400AB98: 4e75                     rts
