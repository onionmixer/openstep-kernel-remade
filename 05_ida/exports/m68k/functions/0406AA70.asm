0406AA70: 4856                     pea     (a6)
0406AA72: 2c4f                     movea.l sp,a6
0406AA74: 48e7383c                 movem.l d2-d4/a2-a5,-(sp)
0406AA78: 266e0008                 movea.l 8(a6),a3
0406AA7C: 2a6e000c                 movea.l $C(a6),a5
0406AA80: 2853                     movea.l (a3),a4
0406AA82: 246b001c                 movea.l $1C(a3),a2
0406AA86: 162a000a                 move.b  $A(a2),d3
0406AA8A: 0203001f                 andi.b  #$1F,d3
0406AA8E: 43ed0018                 lea     $18(a5),a1
0406AA92: 40c0                     move    sr,d0
0406AA94: 46fc2600                 move    #$2600,sr
0406AA98: 3400                     move.w  d0,d2
0406AA9A: 48c2                     ext.l   d2
0406AA9C: 2079040c2b78             movea.l (_eventc_latch).l,a0
0406AAA2: 1010                     move.b  (a0),d0
0406AAA4: 2079040c2b70             movea.l (_eventc_h).l,a0
0406AAAA: 1210                     move.b  (a0),d1
0406AAAC: 0281000000ff             andi.l  #$FF,d1
0406AAB2: 4841                     swap    d1
0406AAB4: 4241                     clr.w   d1
0406AAB6: 2079040c2b7c             movea.l (_eventc_m).l,a0
0406AABC: 1010                     move.b  (a0),d0
0406AABE: 0280000000ff             andi.l  #$FF,d0
0406AAC4: e180                     asl.l   #8,d0
0406AAC6: 8280                     or.l    d0,d1
0406AAC8: 2079040c2b74             movea.l (_eventc_l).l,a0
0406AACE: 1010                     move.b  (a0),d0
0406AAD0: 8200                     or.b    d0,d1
0406AAD2: 0281000fffff             andi.l  #$FFFFF,d1
0406AAD8: 2079040b2ba2             movea.l (_event_middle).l,a0
0406AADE: 2010                     move.l  (a0),d0
0406AAE0: b380                     eor.l   d1,d0
0406AAE2: 08000013                 btst    #$13,d0
0406AAE6: 6728                     beq.s   loc_406AB10
0406AAE8: 2010                     move.l  (a0),d0
0406AAEA: 068000080000             addi.l  #$80000,d0
0406AAF0: 2080                     move.l  d0,(a0)
0406AAF2: 2079040b2ba2             movea.l (_event_middle).l,a0
0406AAF8: 2010                     move.l  (a0),d0
0406AAFA: 0280fff80000             andi.l  #$FFF80000,d0
0406AB00: 660e                     bne.s   loc_406AB10
0406AB02: 2079040b2b9e             movea.l (_event_high).l,a0
0406AB08: 2010                     move.l  (a0),d0
0406AB0A: 5280                     addq.l  #1,d0
0406AB0C: 2080                     move.l  d0,(a0)
0406AB0E: 2010                     move.l  (a0),d0
0406AB10: 2079040b2b9e             movea.l (_event_high).l,a0
0406AB16: 23500004                 move.l  (a0),4(a1)
0406AB1A: 2079040b2ba2             movea.l (_event_middle).l,a0
0406AB20: 2010                     move.l  (a0),d0
0406AB22: 8280                     or.l    d0,d1
0406AB24: 2281                     move.l  d1,(a1)
0406AB26: 40c0                     move    sr,d0
0406AB28: 46c2                     move    d2,sr
0406AB2A: 701f                     moveq   #$1F,d0
0406AB2C: c083                     and.l   d3,d0
0406AB2E: 5780                     subq.l  #3,d0
0406AB30: 7810                     moveq   #$10,d4
0406AB32: b880                     cmp.l   d0,d4
0406AB34: 6550                     bcs.s   loc_406AB86
0406AB36: 207c0406ab42             movea.l #$406AB42,a0
0406AB3C: 20700c00                 movea.l (a0,d0.l*4),a0
0406AB40: 4ed0                     jmp     (a0)
0406AB42: 0406ab92                 subi.b  #$92,d6
0406AB46: 0406ab86                 subi.b  #$86,d6
0406AB4A: 0406ab86                 subi.b  #$86,d6
0406AB4E: 0406ab86                 subi.b  #$86,d6
0406AB52: 0406ab86                 subi.b  #$86,d6
0406AB56: 0406ab92                 subi.b  #$92,d6
0406AB5A: 0406ab86                 subi.b  #$86,d6
0406AB5E: 0406ab86                 subi.b  #$86,d6
0406AB62: 0406ab86                 subi.b  #$86,d6
0406AB66: 0406ab86                 subi.b  #$86,d6
0406AB6A: 0406ab86                 subi.b  #$86,d6
0406AB6E: 0406ab92                 subi.b  #$92,d6
0406AB72: 0406ab86                 subi.b  #$86,d6
0406AB76: 0406ab92                 subi.b  #$92,d6
0406AB7A: 0406ab86                 subi.b  #$86,d6
0406AB7E: 0406ab92                 subi.b  #$92,d6
0406AB82: 0406ab92                 subi.b  #$92,d6
0406AB86: 206b001c                 movea.l $1C(a3),a0
0406AB8A: 18280058                 move.b  $58(a0),d4
0406AB8E: 892a000b                 or.b    d4,$B(a2)
0406AB92: 4280                     clr.l   d0
0406AB94: 1012                     move.b  (a2),d0
0406AB96: b0ab025e                 cmp.l   $25E(a3),d0
0406AB9A: 673e                     beq.s   loc_406ABDA
0406AB9C: 2f00                     move.l  d0,-(sp)
0406AB9E: 2f0b                     move.l  a3,-(sp)
0406ABA0: 61ff000025b0             bsr.l   _fc_configure
0406ABA6: 504f                     addq.w  #8,sp
0406ABA8: 4a80                     tst.l   d0
0406ABAA: 660000c0                 bne.w   loc_406AC6C
0406ABAE: 202d0024                 move.l  $24(a5),d0
0406ABB2: 2200                     move.l  d0,d1
0406ABB4: e981                     asl.l   #4,d1
0406ABB6: d280                     add.l   d0,d1
0406ABB8: 41f9040b12ce             lea     (_fd_drive_info).l,a0; "Sony MPX-111N"
0406ABBE: 48701c00                 pea     (a0,d1.l*4)
0406ABC2: 4280                     clr.l   d0
0406ABC4: 1012                     move.b  (a2),d0
0406ABC6: 2f00                     move.l  d0,-(sp)
0406ABC8: 2f0b                     move.l  a3,-(sp)
0406ABCA: 61ff000025ee             bsr.l   _fc_specify
0406ABD0: 504f                     addq.w  #8,sp
0406ABD2: 584f                     addq.w  #4,sp
0406ABD4: 4a80                     tst.l   d0
0406ABD6: 66000094                 bne.w   loc_406AC6C
0406ABDA: 4280                     clr.l   d0
0406ABDC: 102a0058                 move.b  $58(a2),d0
0406ABE0: 7210                     moveq   #$10,d1
0406ABE2: e1a1                     asl.l   d0,d1
0406ABE4: 102c0002                 move.b  2(a4),d0
0406ABE8: c001                     and.b   d1,d0
0406ABEA: 6676                     bne.s   loc_406AC62
0406ABEC: 701f                     moveq   #$1F,d0
0406ABEE: c083                     and.l   d3,d0
0406ABF0: 5580                     subq.l  #2,d0
0406ABF2: 7814                     moveq   #$14,d4
0406ABF4: b880                     cmp.l   d0,d4
0406ABF6: 656a                     bcs.s   loc_406AC62
0406ABF8: 207c0406ac04             movea.l #$406AC04,a0
0406ABFE: 20700c00                 movea.l (a0,d0.l*4),a0
0406AC02: 4ed0                     jmp     (a0)
0406AC04: 0406ac58                 subi.b  #$58,d6 ; 'X'
0406AC08: 0406ac62                 subi.b  #$62,d6 ; 'b'
0406AC0C: 0406ac62                 subi.b  #$62,d6 ; 'b'
0406AC10: 0406ac58                 subi.b  #$58,d6 ; 'X'
0406AC14: 0406ac58                 subi.b  #$58,d6 ; 'X'
0406AC18: 0406ac58                 subi.b  #$58,d6 ; 'X'
0406AC1C: 0406ac62                 subi.b  #$62,d6 ; 'b'
0406AC20: 0406ac58                 subi.b  #$58,d6 ; 'X'
0406AC24: 0406ac58                 subi.b  #$58,d6 ; 'X'
0406AC28: 0406ac62                 subi.b  #$62,d6 ; 'b'
0406AC2C: 0406ac58                 subi.b  #$58,d6 ; 'X'
0406AC30: 0406ac58                 subi.b  #$58,d6 ; 'X'
0406AC34: 0406ac62                 subi.b  #$62,d6 ; 'b'
0406AC38: 0406ac58                 subi.b  #$58,d6 ; 'X'
0406AC3C: 0406ac62                 subi.b  #$62,d6 ; 'b'
0406AC40: 0406ac62                 subi.b  #$62,d6 ; 'b'
0406AC44: 0406ac62                 subi.b  #$62,d6 ; 'b'
0406AC48: 0406ac62                 subi.b  #$62,d6 ; 'b'
0406AC4C: 0406ac62                 subi.b  #$62,d6 ; 'b'
0406AC50: 0406ac62                 subi.b  #$62,d6 ; 'b'
0406AC54: 0406ac58                 subi.b  #$58,d6 ; 'X'
0406AC58: 2f0b                     move.l  a3,-(sp)
0406AC5A: 61ff000000e4             bsr.l   _fc_motor_on
0406AC60: 584f                     addq.w  #4,sp
0406AC62: 2f0a                     move.l  a2,-(sp)
0406AC64: 2f0b                     move.l  a3,-(sp)
0406AC66: 61ff00000154             bsr.l   _fc_send_cmd
0406AC6C: 2540003e                 move.l  d0,$3E(a2)
0406AC70: 4cee3c1cffe4             movem.l -$1C(a6),d2-d4/a2-a5
0406AC76: 4e5e                     unlk    a6
0406AC78: 4e75                     rts
