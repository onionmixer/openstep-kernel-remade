04026266: 4856                     pea     (a6)
04026268: 2c4f                     movea.l sp,a6
0402626A: 2f0a                     move.l  a2,-(sp)
0402626C: 246e0008                 movea.l 8(a6),a2
04026270: 082a00060005             btst    #6,5(a2)
04026276: 662c                     bne.s   loc_40262A4
04026278: 206a0024                 movea.l $24(a2),a0
0402627C: 20680126                 movea.l $126(a0),a0
04026280: 082800030014             btst    #3,$14(a0)
04026286: 661c                     bne.s   loc_40262A4
04026288: 727c                     moveq   #$7C,d1 ; '|'
0402628A: d2aa002e                 add.l   $2E(a2),d1
0402628E: 2f01                     move.l  d1,-(sp)
04026290: 2f2e000c                 move.l  $C(a6),-(sp)
04026294: 2f0a                     move.l  a2,-(sp)
04026296: 61ff00000292             bsr.l   _nattr_to_vattr
0402629C: 2f0a                     move.l  a2,-(sp)
0402629E: 61ff00000064             bsr.l   sub_4026304
040262A4: 246efffc                 movea.l -4(a6),a2
040262A8: 4e5e                     unlk    a6
040262AA: 4e75                     rts
