0409E98C: 082800060000             btst    #6,0(a0)
0409E992: 67ff0000000a             beq.l   loc_409E99E
0409E998: 08e800070000             bset    #7,0(a0)
0409E99E: 0c000000                 cmpi.b  #0,d0
0409E9A2: 66ff0000001c             bne.l   loc_409E9C0
0409E9A8: 4281                     clr.l   d1
0409E9AA: 4280                     clr.l   d0
0409E9AC: 61ff000000ba             bsr.l   dnrm_lp
0409E9B2: 4a01                     tst.b   d1
0409E9B4: 67ff000000b0             beq.l   locret_409EA66
0409E9BA: 60ff000000a2             bra.l   loc_409EA5E
0409E9C0: 0c8000000001             cmpi.l  #1,d0
0409E9C6: 67ff0000002e             beq.l   loc_409E9F6
0409E9CC: 323c3c01                 move.w  #$3C01,d1
0409E9D0: 2001                     move.l  d1,d0
0409E9D2: 90680000                 sub.w   0(a0),d0
0409E9D6: 0c400043                 cmpi.w  #$43,d0 ; 'C'
0409E9DA: 6aff00000044             bpl.l   loc_409EA20
0409E9E0: 4280                     clr.l   d0
0409E9E2: 61ff00000084             bsr.l   dnrm_lp
0409E9E8: 4a01                     tst.b   d1
0409E9EA: 67ff0000007a             beq.l   locret_409EA66
0409E9F0: 60ff0000006c             bra.l   loc_409EA5E
0409E9F6: 323c3f81                 move.w  #$3F81,d1
0409E9FA: 2001                     move.l  d1,d0
0409E9FC: 90680000                 sub.w   0(a0),d0
0409EA00: 0c400043                 cmpi.w  #$43,d0 ; 'C'
0409EA04: 6aff0000001a             bpl.l   loc_409EA20
0409EA0A: 4280                     clr.l   d0
0409EA0C: 61ff0000005a             bsr.l   dnrm_lp
0409EA12: 4a01                     tst.b   d1
0409EA14: 67ff00000050             beq.l   locret_409EA66
0409EA1A: 60ff00000042             bra.l   loc_409EA5E
0409EA20: 4aa80004                 tst.l   4(a0)
0409EA24: 66ff00000014             bne.l   loc_409EA3A
0409EA2A: 4aa80008                 tst.l   8(a0)
0409EA2E: 66ff0000000a             bne.l   loc_409EA3A
0409EA34: 60ff00000012             bra.l   loc_409EA48
0409EA3A: 00ae00000208ff84         ori.l   #$208,-$7C(a6)
0409EA42: 203c20000000             move.l  #$20000000,d0
0409EA48: 31410000                 move.w  d1,0(a0)
0409EA4C: 217c000000000004         move.l  #0,4(a0)
0409EA54: 217c000000000008         move.l  #0,8(a0)
0409EA5C: 4e75                     rts
0409EA5E: 00ae00000208ff84         ori.l   #$208,-$7C(a6)
0409EA66: 4e75                     rts
