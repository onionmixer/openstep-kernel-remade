0404EAAE: 4e56fffc                 link    a6,#-4
0404EAB2: 48e72030                 movem.l d2/a2-a3,-(sp)
0404EAB6: 266e0008                 movea.l arg_0(a6),a3
0404EABA: 486efffc                 pea     var_4(a6)
0404EABE: 61ff000421f6             bsr.l   _PMGetPowerEvent
0404EAC4: 2400                     move.l  d0,d2
0404EAC6: 584f                     addq.w  #4,sp
0404EAC8: 660000ba                 bne.w   loc_404EB84
0404EACC: 202efffc                 move.l  var_4(a6),d0
0404EAD0: 5380                     subq.l  #1,d0
0404EAD2: 720a                     moveq   #$A,d1
0404EAD4: b280                     cmp.l   d0,d1
0404EAD6: 650000a4                 bcs.w   loc_404EB7C
0404EADA: 207c0404eae6             movea.l #$404EAE6,a0
0404EAE0: 20700c00                 movea.l (a0,d0.l*4),a0
0404EAE4: 4ed0                     jmp     (a0)
0404EAE6: 0404eb12                 subi.b  #$12,d4
0404EAEA: 0404eb2c                 subi.b  #$2C,d4 ; ','
0404EAEE: 0404eb58                 subi.b  #$58,d4 ; 'X'
0404EAF2: 0404eb58                 subi.b  #$58,d4 ; 'X'
0404EAF6: 0404eb7c                 subi.b  #$7C,d4 ; '|'
0404EAFA: 0404eb7c                 subi.b  #$7C,d4 ; '|'
0404EAFE: 0404eb76                 subi.b  #$76,d4 ; 'v'
0404EB02: 0404eb2c                 subi.b  #$2C,d4 ; ','
0404EB06: 0404eb12                 subi.b  #$12,d4
0404EB0A: 0404eb2c                 subi.b  #$2C,d4 ; ','
0404EB0E: 0404eb58                 subi.b  #$58,d4 ; 'X'
0404EB12: 7201                     moveq   #1,d1
0404EB14: 23c1040b39c2             move.l  d1,(dword_40B39C2).l
0404EB1A: 48780001                 pea     (1).w
0404EB1E: 2f3c00010000             move.l  #$10000,-(sp)
0404EB24: 61ff00042182             bsr.l   _PMSetPowerState
0404EB2A: 6050                     bra.s   loc_404EB7C
0404EB2C: 7202                     moveq   #2,d1
0404EB2E: 23c1040b39c2             move.l  d1,(dword_40B39C2).l
0404EB34: 48780002                 pea     (2).w
0404EB38: 2f3c00010000             move.l  #$10000,-(sp)
0404EB3E: 45f904090ca8             lea     (_PMSetPowerState).l,a2
0404EB44: 4e92                     jsr     (a2)
0404EB46: 42b9040b39c2             clr.l   (dword_40B39C2).l
0404EB4C: 42a7                     clr.l   -(sp)
0404EB4E: 2f3c00010000             move.l  #$10000,-(sp)
0404EB54: 4e92                     jsr     (a2)
0404EB56: 6024                     bra.s   loc_404EB7C
0404EB58: 4ab9040b39c2             tst.l   (dword_40B39C2).l
0404EB5E: 6716                     beq.s   loc_404EB76
0404EB60: 42b9040b39c2             clr.l   (dword_40B39C2).l
0404EB66: 42a7                     clr.l   -(sp)
0404EB68: 2f3c00010000             move.l  #$10000,-(sp)
0404EB6E: 61ff00042138             bsr.l   _PMSetPowerState
0404EB74: 504f                     addq.w  #8,sp
0404EB76: 61ff00042180             bsr.l   _PMUpdateClock
0404EB7C: 4a8b                     tst.l   a3
0404EB7E: 6704                     beq.s   loc_404EB84
0404EB80: 26aefffc                 move.l  var_4(a6),(a3)
0404EB84: 2002                     move.l  d2,d0
0404EB86: 4cee0c04fff0             movem.l var_10(a6),d2/a2-a3
0404EB8C: 4e5e                     unlk    a6
0404EB8E: 4e75                     rts
