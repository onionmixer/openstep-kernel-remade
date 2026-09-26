040A40C6: 082e0001ff24             btst    #1,-$DC(a6)
040A40CC: 67ff0000004c             beq.l   loc_40A411A
040A40D2: 302eff10                 move.w  -$F0(a6),d0
040A40D6: 02400060                 andi.w  #$60,d0 ; '`'
040A40DA: 0c8000000040             cmpi.l  #$40,d0 ; '@'
040A40E0: 67ff0000008a             beq.l   loc_40A416C
040A40E6: 0c8000000060             cmpi.l  #$60,d0 ; '`'
040A40EC: 67ff00000086             beq.l   loc_40A4174
040A40F2: 302eff10                 move.w  -$F0(a6),d0
040A40F6: 02800000007f             andi.l  #$7F,d0
040A40FC: 0c8000000033             cmpi.l  #$33,d0 ; '3'
040A4102: 67ff00000060             beq.l   loc_40A4164
040A4108: 0c8000000030             cmpi.l  #$30,d0 ; '0'
040A410E: 67ff00000054             beq.l   loc_40A4164
040A4114: 60ff00000066             bra.l   loc_40A417C
040A411A: 302eff1c                 move.w  -$E4(a6),d0
040A411E: 028000000044             andi.l  #$44,d0 ; 'D'
040A4124: 0c8000000040             cmpi.l  #$40,d0 ; '@'
040A412A: 67ff00000040             beq.l   loc_40A416C
040A4130: 0c8000000044             cmpi.l  #$44,d0 ; 'D'
040A4136: 67ff0000003c             beq.l   loc_40A4174
040A413C: 302eff1c                 move.w  -$E4(a6),d0
040A4140: 02800000007f             andi.l  #$7F,d0
040A4146: 0c8000000027             cmpi.l  #$27,d0 ; '''
040A414C: 67ff00000016             beq.l   loc_40A4164
040A4152: 0c8000000024             cmpi.l  #$24,d0 ; '$'
040A4158: 67ff0000000a             beq.l   loc_40A4164
040A415E: 60ff0000001c             bra.l   loc_40A417C
040A4164: 4280                     clr.l   d0
040A4166: 60ff00000026             bra.l   ovf_res
040A416C: 7001                     moveq   #1,d0
040A416E: 60ff0000001e             bra.l   ovf_res
040A4174: 7002                     moveq   #2,d0
040A4176: 60ff00000016             bra.l   ovf_res
040A417C: e9ee0002ff83             bfextu  -$7D(a6){0:2},d0
040A4182: 60ff0000000a             bra.l   ovf_res
