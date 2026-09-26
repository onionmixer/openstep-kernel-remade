04039382: 4856                     pea     (a6)
04039384: 2c4f                     movea.l sp,a6
04039386: 2f0a                     move.l  a2,-(sp)
04039388: 302e000a                 move.w  $A(a6),d0
0403938C: 2479040af5be             movea.l (_mounttab).l,a2
04039392: 4a8a                     tst.l   a2
04039394: 6748                     beq.s   loc_40393DE
04039396: 206a000a                 movea.l $A(a2),a0
0403939A: 4a88                     tst.l   a0
0403939C: 6738                     beq.s   loc_40393D6
0403939E: b06a0004                 cmp.w   4(a2),d0
040393A2: 6632                     bne.s   loc_40393D6
040393A4: 20680020                 movea.l $20(a0),a0
040393A8: 0ca800011954055c         cmpi.l  #$11954,$55C(a0)
040393B0: 6720                     beq.s   loc_40393D2
040393B2: 486800d4                 pea     $D4(a0)
040393B6: 3240                     movea.w d0,a1
040393B8: 2f09                     move.l  a1,-(sp)
040393BA: 4879040a81ae             pea     (aDev0xXFsS).l; "dev = 0x%x, fs = %s\n"
040393C0: 61fffffd1f96             bsr.l   _printf
040393C6: 4879040a81c3             pea     (aGetmpBadMagic).l; "getmp: bad magic"
040393CC: 61fffffd2898             bsr.l   _panic
040393D2: 200a                     move.l  a2,d0
040393D4: 600a                     bra.s   loc_40393E0
040393D6: 246a001c                 movea.l $1C(a2),a2
040393DA: 4a8a                     tst.l   a2
040393DC: 66b8                     bne.s   loc_4039396
040393DE: 4280                     clr.l   d0
040393E0: 246efffc                 movea.l -4(a6),a2
040393E4: 4e5e                     unlk    a6
040393E6: 4e75                     rts
