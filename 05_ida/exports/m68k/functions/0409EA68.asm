0409EA68: 2f02                     move.l  d2,-(sp)
0409EA6A: 082e0001ff24             btst    #1,-$DC(a6)
0409EA70: 67ff00000010             beq.l   loc_409EA82
0409EA76: e9ee2183ff18             bfextu  -$E8(a6){6:3},d2
0409EA7C: 701d                     moveq   #$1D,d0
0409EA7E: e1aa                     lsl.l   d0,d2
0409EA80: 2002                     move.l  d2,d0
0409EA82: 241f                     move.l  (sp)+,d2
0409EA84: 2d680008ffa4             move.l  8(a0),-$5C(a6)
0409EA8A: 2d40ffa8                 move.l  d0,-$58(a6)
0409EA8E: 2001                     move.l  d1,d0
0409EA90: 92680000                 sub.w   0(a0),d1
0409EA94: 6fff0000001e             ble.l   loc_409EAB4
0409EA9A: 0c410020                 cmpi.w  #$20,d1 ; ' '
0409EA9E: 6dff0000001c             blt.l   loc_409EABC
0409EAA4: 0c410040                 cmpi.w  #$40,d1 ; '@'
0409EAA8: 6dff0000006e             blt.l   loc_409EB18
0409EAAE: 60ff000000d8             bra.l   loc_409EB88
0409EAB4: 4201                     clr.b   d1
0409EAB6: 202effa8                 move.l  -$58(a6),d0
0409EABA: 4e75                     rts
0409EABC: 2f02                     move.l  d2,-(sp)
0409EABE: 31400000                 move.w  d0,0(a0)
0409EAC2: 7020                     moveq   #$20,d0 ; ' '
0409EAC4: 9041                     sub.w   d1,d0
0409EAC6: e9e828000000             bfextu  0(a0){d0:32},d2
0409EACC: e9c22860                 bfextu  d2{d1:d0},d2
0409EAD0: e9e818000004             bfextu  4(a0){d0:32},d1
0409EAD6: e9ee0800ffa4             bfextu  -$5C(a6){d0:32},d0
0409EADC: 21420004                 move.l  d2,4(a0)
0409EAE0: 21410008                 move.l  d1,8(a0)
0409EAE4: 4201                     clr.b   d1
0409EAE6: e8c0009e                 bftst   d0{2:30}
0409EAEA: 67ff0000000a             beq.l   loc_409EAF6
0409EAF0: 08c0001d                 bset    #$1D,d0
0409EAF4: 50c1                     st      d1
0409EAF6: 242effa8                 move.l  -$58(a6),d2
0409EAFA: 0282e0000000             andi.l  #$E0000000,d2
0409EB00: 4a82                     tst.l   d2
0409EB02: 67ff0000000a             beq.l   loc_409EB0E
0409EB08: 008020000000             ori.l   #$20000000,d0
0409EB0E: 0280e0000000             andi.l  #$E0000000,d0
0409EB14: 241f                     move.l  (sp)+,d2
0409EB16: 4e75                     rts
0409EB18: 2f02                     move.l  d2,-(sp)
0409EB1A: 31400000                 move.w  d0,0(a0)
0409EB1E: 04410020                 subi.w  #$20,d1 ; ' '
0409EB22: 7020                     moveq   #$20,d0 ; ' '
0409EB24: 9041                     sub.w   d1,d0
0409EB26: e9e828000000             bfextu  0(a0){d0:32},d2
0409EB2C: e9c22860                 bfextu  d2{d1:d0},d2
0409EB30: e9e818000004             bfextu  4(a0){d0:32},d1
0409EB36: e8c1009e                 bftst   d1{2:30}
0409EB3A: 66ff0000001a             bne.l   loc_409EB56
0409EB40: e8ee0800ffa4             bftst   -$5C(a6){d0:32}
0409EB46: 66ff0000000e             bne.l   loc_409EB56
0409EB4C: 2001                     move.l  d1,d0
0409EB4E: 4201                     clr.b   d1
0409EB50: 60ff0000000c             bra.l   loc_409EB5E
0409EB56: 2001                     move.l  d1,d0
0409EB58: 08c0001d                 bset    #$1D,d0
0409EB5C: 50c1                     st      d1
0409EB5E: 42a80004                 clr.l   4(a0)
0409EB62: 21420008                 move.l  d2,8(a0)
0409EB66: 242effa8                 move.l  -$58(a6),d2
0409EB6A: 0282e0000000             andi.l  #$E0000000,d2
0409EB70: 4a82                     tst.l   d2
0409EB72: 67ff0000000a             beq.l   loc_409EB7E
0409EB78: 008020000000             ori.l   #$20000000,d0
0409EB7E: 0280e0000000             andi.l  #$E0000000,d0
0409EB84: 241f                     move.l  (sp)+,d2
0409EB86: 4e75                     rts
0409EB88: 31400000                 move.w  d0,0(a0)
0409EB8C: 4a680002                 tst.w   2(a0)
0409EB90: 6cff0000000c             bge.l   loc_409EB9E
0409EB96: 00a8800000000000         ori.l   #$80000000,0(a0)
0409EB9E: 0c410040                 cmpi.w  #$40,d1 ; '@'
0409EBA2: 67ff00000020             beq.l   loc_409EBC4
0409EBA8: 0c410041                 cmpi.w  #$41,d1 ; 'A'
0409EBAC: 67ff0000002a             beq.l   loc_409EBD8
0409EBB2: 42a80004                 clr.l   4(a0)
0409EBB6: 42a80008                 clr.l   8(a0)
0409EBBA: 203c20000000             move.l  #$20000000,d0
0409EBC0: 50c1                     st      d1
0409EBC2: 4e75                     rts
0409EBC4: 20280004                 move.l  4(a0),d0
0409EBC8: e9c0109e                 bfextu  d0{2:30},d1
0409EBCC: 0280c0000000             andi.l  #$C0000000,d0
0409EBD2: 60ff00000014             bra.l   loc_409EBE8
0409EBD8: 20280004                 move.l  4(a0),d0
0409EBDC: e9c0105f                 bfextu  d0{1:31},d1
0409EBE0: 028080000000             andi.l  #$80000000,d0
0409EBE6: e288                     lsr.l   #1,d0
0409EBE8: 4a81                     tst.l   d1
0409EBEA: 66ff00000020             bne.l   loc_409EC0C
0409EBF0: 4aa80008                 tst.l   8(a0)
0409EBF4: 66ff00000016             bne.l   loc_409EC0C
0409EBFA: 4a2effa8                 tst.b   -$58(a6)
0409EBFE: 66ff0000000c             bne.l   loc_409EC0C
0409EC04: 4201                     clr.b   d1
0409EC06: 60ff0000000a             bra.l   loc_409EC12
0409EC0C: 08c0001d                 bset    #$1D,d0
0409EC10: 50c1                     st      d1
0409EC12: 42a80004                 clr.l   4(a0)
0409EC16: 42a80008                 clr.l   8(a0)
0409EC1A: 4e75                     rts
