040A47F4: 0c6f202c0006             cmpi.w  #$202C,arg_2(sp)
040A47FA: 67ff00000c24             beq.l   fpsp_unimp
040A4800: 598f                     subq.l  #4,sp
040A4802: 4e56ff40                 link    a6,#-$C0
040A4806: f327                     fsave   -(sp)
040A4808: 48ee0303ff40             movem.l d0-d1/a0-a1,-$C0(a6)
040A480E: 206e000a                 movea.l $A(a6),a0
040A4812: 43eeffac                 lea     -$54(a6),a1
040A4816: 7004                     moveq   #4,d0
040A4818: 588e                     addq.l  #4,a6
040A481A: 61ffffffc4ea             bsr.l   mem_read
040A4820: 598e                     subq.l  #4,a6
040A4822: 202effac                 move.l  -$54(a6),d0
040A4826: e9c01103                 bfextu  d0{4:3},d1
040A482A: 0c010001                 cmpi.b  #1,d1
040A482E: 66ff00000090             bne.l   loc_40A48C0
040A4834: e9c01406                 bfextu  d0{16:6},d1
040A4838: 0c010017                 cmpi.b  #$17,d1
040A483C: 66ff00000082             bne.l   loc_40A48C0
040A4842: 0c170040                 cmpi.b  #$40,(sp) ; '@'
040A4846: 66ff0000001e             bne.l   loc_40A4866
040A484C: 9ffc00000028             suba.l  #$28,sp ; '('
040A4852: 1ebc0040                 move.b  #$40,(sp) ; '@'
040A4856: 1f7c00280001             move.b  #$28,$F0+var_EF(sp) ; '('
040A485C: 426f0002                 clr.w   $F0+var_EE(sp)
040A4860: 60ff00000022             bra.l   loc_40A4884
040A4866: 0c170041                 cmpi.b  #$41,(sp) ; 'A'
040A486A: 66ffffffc466             bne.l   fpsp_fmt_error
040A4870: 9ffc00000030             suba.l  #$30,sp ; '0'
040A4876: 1ebc0041                 move.b  #$41,(sp) ; 'A'
040A487A: 1f7c00300001             move.b  #$30,$F8+var_F7(sp) ; '0'
040A4880: 426f0002                 clr.w   $F8+var_F6(sp)
040A4884: 3d6e00080004             move.w  8(a6),4(a6)
040A488A: 2d6e000a0006             move.l  $A(a6),6(a6)
040A4890: f22e84000006             fmovem.l 6(a6),fpiar
040A4896: 7204                     moveq   #4,d1
040A4898: d3ae0006                 add.l   d1,6(a6)
040A489C: 3d7c202c000a             move.w  #$202C,$A(a6)
040A48A2: 42ae000c                 clr.l   $C(a6)
040A48A6: 3d40ff1c                 move.w  d0,-$E4(a6)
040A48AA: 42aeff24                 clr.l   -$DC(a6)
040A48AE: 08ee0005ff25             bset    #5,-$DB(a6)
040A48B4: 4cee0303ff40             movem.l -$C0(a6),d0-d1/a0-a1
040A48BA: 60ff00000b6a             bra.l   uni_2
040A48C0: 4cee0303ff40             movem.l -$C0(a6),d0-d1/a0-a1
040A48C6: f35f                     frestore (sp)+
040A48C8: 4e5e                     unlk    a6
040A48CA: 588f                     addq.l  #4,sp
040A48CC: 60ffffffc3d0             bra.l   real_fline
