0409C714: 302eff1c                 move.w  -$E4(a6),d0
0409C718: 0240003b                 andi.w  #$3B,d0 ; ';'
0409C71C: 67ff000000d0             beq.l   loc_409C7EE
0409C722: 302eff34                 move.w  -$CC(a6),d0
0409C726: e9c0150c                 bfextu  d0{20:12},d1
0409C72A: 0c410fff                 cmpi.w  #$FFF,d1
0409C72E: 66ff00000046             bne.l   loc_409C776
0409C734: e9c01443                 bfextu  d0{17:3},d1
0409C738: 0c410007                 cmpi.w  #7,d1
0409C73C: 66ff00000038             bne.l   loc_409C776
0409C742: 4aaeff38                 tst.l   -$C8(a6)
0409C746: 66ff00000014             bne.l   loc_409C75C
0409C74C: 4aaeff3c                 tst.l   -$C4(a6)
0409C750: 66ff0000000a             bne.l   loc_409C75C
0409C756: 60ff000001b0             bra.l   loc_409C908
0409C75C: 082e0006ff38             btst    #6,-$C8(a6)
0409C762: 66ff000001a4             bne.l   loc_409C908
0409C768: 00ae01004080ff84         ori.l   #$1004080,-$7C(a6)
0409C770: 60ff00000196             bra.l   loc_409C908
0409C776: 302eff36                 move.w  -$CA(a6),d0
0409C77A: 0240000f                 andi.w  #$F,d0
0409C77E: 4a40                     tst.w   d0
0409C780: 66ff0000004a             bne.l   loc_409C7CC
0409C786: 4aaeff38                 tst.l   -$C8(a6)
0409C78A: 66ff00000040             bne.l   loc_409C7CC
0409C790: 4aaeff3c                 tst.l   -$C4(a6)
0409C794: 66ff00000036             bne.l   loc_409C7CC
0409C79A: 4aaeff34                 tst.l   -$CC(a6)
0409C79E: 6cff0000001a             bge.l   loc_409C7BA
0409C7A4: 2d7c80000000ff34         move.l  #$80000000,-$CC(a6)
0409C7AC: 42aeff38                 clr.l   -$C8(a6)
0409C7B0: 42aeff3c                 clr.l   -$C4(a6)
0409C7B4: 60ff00000152             bra.l   loc_409C908
0409C7BA: 42aeff34                 clr.l   -$CC(a6)
0409C7BE: 42aeff38                 clr.l   -$C8(a6)
0409C7C2: 42aeff3c                 clr.l   -$C4(a6)
0409C7C6: 60ff00000140             bra.l   loc_409C908
0409C7CC: f227e001                 fmovem.x fp0,-(sp)
0409C7D0: 61ffffffed38             bsr.l   decbin
0409C7D6: f22e6800ff34             fmove.x fp0,-$CC(a6)
0409C7DC: f21fd080                 fmovem.x (sp)+,fp0
0409C7E0: f23c880000000000         fmovem.l #0,fpsr
0409C7E8: 60ff0000011e             bra.l   loc_409C908
0409C7EE: 302eff34                 move.w  -$CC(a6),d0
0409C7F2: e9c0150c                 bfextu  d0{20:12},d1
0409C7F6: 0c410fff                 cmpi.w  #$FFF,d1
0409C7FA: 66ff00000092             bne.l   loc_409C88E
0409C800: e9c01443                 bfextu  d0{17:3},d1
0409C804: 0c410007                 cmpi.w  #7,d1
0409C808: 66ff00000084             bne.l   loc_409C88E
0409C80E: 4aaeff38                 tst.l   -$C8(a6)
0409C812: 66ff0000002e             bne.l   loc_409C842
0409C818: 4aaeff3c                 tst.l   -$C4(a6)
0409C81C: 66ff00000024             bne.l   loc_409C842
0409C822: 00ae02000000ff84         ori.l   #$2000000,-$7C(a6)
0409C82A: 4aaeff34                 tst.l   -$CC(a6)
0409C82E: 6cff000000d8             bge.l   loc_409C908
0409C834: 00ae08000000ff84         ori.l   #$8000000,-$7C(a6)
0409C83C: 60ff000000ca             bra.l   loc_409C908
0409C842: 00ae01000000ff84         ori.l   #$1000000,-$7C(a6)
0409C84A: 1d7c0060ff18             move.b  #$60,-$E8(a6) ; '`'
0409C850: 082e0006ff38             btst    #6,-$C8(a6)
0409C856: 66ff0000001e             bne.l   loc_409C876
0409C85C: 00ae01004080ff84         ori.l   #$1004080,-$7C(a6)
0409C864: 082e0006ff82             btst    #6,-$7E(a6)
0409C86A: 66ff0000000a             bne.l   loc_409C876
0409C870: 08ee0006ff38             bset    #6,-$C8(a6)
0409C876: 4aaeff34                 tst.l   -$CC(a6)
0409C87A: 6cff0000008c             bge.l   loc_409C908
0409C880: 00ae08000000ff84         ori.l   #$8000000,-$7C(a6)
0409C888: 60ff0000007e             bra.l   loc_409C908
0409C88E: 302eff36                 move.w  -$CA(a6),d0
0409C892: 0240000f                 andi.w  #$F,d0
0409C896: 4a40                     tst.w   d0
0409C898: 66ff0000005a             bne.l   loc_409C8F4
0409C89E: 4aaeff38                 tst.l   -$C8(a6)
0409C8A2: 66ff00000050             bne.l   loc_409C8F4
0409C8A8: 4aaeff3c                 tst.l   -$C4(a6)
0409C8AC: 66ff00000046             bne.l   loc_409C8F4
0409C8B2: 4aaeff34                 tst.l   -$CC(a6)
0409C8B6: 6cff00000022             bge.l   loc_409C8DA
0409C8BC: 00ae0c000000ff84         ori.l   #$C000000,-$7C(a6)
0409C8C4: 2d7c80000000ff34         move.l  #$80000000,-$CC(a6)
0409C8CC: 42aeff38                 clr.l   -$C8(a6)
0409C8D0: 42aeff3c                 clr.l   -$C4(a6)
0409C8D4: 60ff00000032             bra.l   loc_409C908
0409C8DA: 00ae04000000ff84         ori.l   #$4000000,-$7C(a6)
0409C8E2: 42aeff34                 clr.l   -$CC(a6)
0409C8E6: 42aeff38                 clr.l   -$C8(a6)
0409C8EA: 42aeff3c                 clr.l   -$C4(a6)
0409C8EE: 60ff00000018             bra.l   loc_409C908
0409C8F4: f227e001                 fmovem.x fp0,-(sp)
0409C8F8: 61ffffffec10             bsr.l   decbin
0409C8FE: f22e6800ff34             fmove.x fp0,-$CC(a6)
0409C904: f21fd080                 fmovem.x (sp)+,fp0
0409C908: 302eff1c                 move.w  -$E4(a6),d0
0409C90C: 0240fbff                 andi.w  #$FBFF,d0
0409C910: 3d40ff1c                 move.w  d0,-$E4(a6)
0409C914: 322eff34                 move.w  -$CC(a6),d1
0409C918: 02417fff                 andi.w  #$7FFF,d1
0409C91C: 0c417fff                 cmpi.w  #$7FFF,d1
0409C920: 66ff0000002c             bne.l   loc_409C94E
0409C926: 222eff38                 move.l  -$C8(a6),d1
0409C92A: 66ff00000018             bne.l   loc_409C944
0409C930: 222eff3c                 move.l  -$C4(a6),d1
0409C934: 66ff0000000e             bne.l   loc_409C944
0409C93A: 1d7c0040ff18             move.b  #$40,-$E8(a6) ; '@'
0409C940: 7040                     moveq   #$40,d0 ; '@'
0409C942: 4e75                     rts
0409C944: 1d7c0060ff18             move.b  #$60,-$E8(a6) ; '`'
0409C94A: 7060                     moveq   #$60,d0 ; '`'
0409C94C: 4e75                     rts
0409C94E: 4a41                     tst.w   d1
0409C950: 66ff0000000e             bne.l   loc_409C960
0409C956: 1d7c0030ff18             move.b  #$30,-$E8(a6) ; '0'
0409C95C: 7020                     moveq   #$20,d0 ; ' '
0409C95E: 4e75                     rts
0409C960: 0c413fff                 cmpi.w  #$3FFF,d1
0409C964: 6fff00000010             ble.l   loc_409C976
0409C96A: 1d7c0000ff18             move.b  #0,-$E8(a6)
0409C970: 60ff0000000a             bra.l   loc_409C97C
0409C976: 1d7c0010ff18             move.b  #$10,-$E8(a6)
0409C97C: 7000                     moveq   #0,d0
0409C97E: 4e75                     rts
