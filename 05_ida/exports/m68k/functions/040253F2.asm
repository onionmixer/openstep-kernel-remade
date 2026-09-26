040253F2: 4856                     pea     (a6)
040253F4: 2c4f                     movea.l sp,a6
040253F6: 2f0a                     move.l  a2,-(sp)
040253F8: 246e0008                 movea.l 8(a6),a2
040253FC: 326a0008                 movea.w 8(a2),a1
04025400: 7205                     moveq   #5,d1
04025402: b289                     cmp.l   a1,d1
04025404: 6544                     bcs.s   loc_402544A
04025406: 207c04025412             movea.l #$4025412,a0
0402540C: 20709c00                 movea.l (a0,a1.l*4),a0
04025410: 4ed0                     jmp     (a0)
04025412: 0402542a                 subi.b  #$2A,d2 ; '*'
04025416: 0402542a                 subi.b  #$2A,d2 ; '*'
0402541A: 0402542a                 subi.b  #$2A,d2 ; '*'
0402541E: 0402543c                 subi.b  #$3C,d2 ; '<'
04025422: 0402543c                 subi.b  #$3C,d2 ; '<'
04025426: 04025444                 subi.b  #$44,d2 ; 'D'
0402542A: 426a0008                 clr.w   8(a2)
0402542E: 2f0a                     move.l  a2,-(sp)
04025430: 61fffffff504             bsr.l   _tcp_close
04025436: 2440                     movea.l d0,a2
04025438: 584f                     addq.w  #4,sp
0402543A: 600e                     bra.s   loc_402544A
0402543C: 357c00060008             move.w  #6,8(a2)
04025442: 6006                     bra.s   loc_402544A
04025444: 357c00080008             move.w  #8,8(a2)
0402544A: 4a8a                     tst.l   a2
0402544C: 6716                     beq.s   loc_4025464
0402544E: 0c6a00080008             cmpi.w  #8,8(a2)
04025454: 6f0e                     ble.s   loc_4025464
04025456: 206a0020                 movea.l $20(a2),a0
0402545A: 2f280018                 move.l  $18(a0),-(sp)
0402545E: 61fffffee99e             bsr.l   _soisdisconnected
04025464: 200a                     move.l  a2,d0
04025466: 246efffc                 movea.l -4(a6),a2
0402546A: 4e5e                     unlk    a6
0402546C: 4e75                     rts
