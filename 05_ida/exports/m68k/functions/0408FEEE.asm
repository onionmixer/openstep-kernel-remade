0408FEEE: 4856                     pea     (a6)
0408FEF0: 2c4f                     movea.l sp,a6
0408FEF2: 48e72038                 movem.l d2/a2-a4,-(sp)
0408FEF6: 266e000c                 movea.l $C(a6),a3
0408FEFA: 242e0010                 move.l  $10(a6),d2
0408FEFE: 48780148                 pea     ($148).w
0408FF02: 61fffffba2fc             bsr.l   _kalloc
0408FF08: 2440                     movea.l d0,a2
0408FF0A: 49ea0108                 lea     $108(a2),a4
0408FF0E: 48780148                 pea     ($148).w
0408FF12: 2f0a                     move.l  a2,-(sp)
0408FF14: 61ff00002efc             bsr.l   _bzero
0408FF1A: 14bc0045                 move.b  #$45,(a2) ; 'E'
0408FF1E: 3579040b68820004         move.w  (_ip_id).l,4(a2)
0408FF26: 5279040b6882             addq.w  #1,(_ip_id).l
0408FF2C: 157c00ff0008             move.b  #$FF,8(a2)
0408FF32: 157c00110009             move.b  #$11,9(a2)
0408FF38: 256b0004000c             move.l  4(a3),$C(a2)
0408FF3E: 72ff                     moveq   #$FFFFFFFF,d1
0408FF40: 25410010                 move.l  d1,$10(a2)
0408FF44: 357c00440014             move.w  #$44,$14(a2) ; 'D'
0408FF4A: 357c00430016             move.w  #$43,$16(a2) ; 'C'
0408FF50: 426a001a                 clr.w   $1A(a2)
0408FF54: 157c0001001c             move.b  #1,$1C(a2)
0408FF5A: 157c0001001d             move.b  #1,$1D(a2)
0408FF60: 157c0006001e             move.b  #6,$1E(a2)
0408FF66: 42aa0028                 clr.l   $28(a2)
0408FF6A: 48780006                 pea     (6).w
0408FF6E: 486a0038                 pea     $38(a2)
0408FF72: 2f02                     move.l  d2,-(sp)
0408FF74: 47f904092d2c             lea     (_bcopy).l,a3
0408FF7A: 4e93                     jsr     (a3)
0408FF7C: 48780004                 pea     (4).w
0408FF80: 2f0c                     move.l  a4,-(sp)
0408FF82: 4879040ac0e4             pea     (aNext).l; "NeXT"
0408FF88: 4e93                     jsr     (a3)
0408FF8A: 157c0001010c             move.b  #1,$10C(a2)
0408FF90: 422a010e                 clr.b   $10E(a2)
0408FF94: 357c01340018             move.w  #$134,$18(a2)
0408FF9A: 357c01480002             move.w  #$148,2(a2)
0408FFA0: 426a000a                 clr.w   $A(a2)
0408FFA4: 200a                     move.l  a2,d0
0408FFA6: 4cee1c04fff0             movem.l -$10(a6),d2/a2-a4
0408FFAC: 4e5e                     unlk    a6
0408FFAE: 4e75                     rts
