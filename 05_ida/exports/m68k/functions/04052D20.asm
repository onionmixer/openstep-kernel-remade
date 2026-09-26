04052D20: 4856                     pea     (a6)
04052D22: 2c4f                     movea.l sp,a6
04052D24: 206e0008                 movea.l 8(a6),a0
04052D28: 4a88                     tst.l   a0
04052D2A: 6710                     beq.s   loc_4052D3C
04052D2C: 40c0                     move    sr,d0
04052D2E: 46fc2300                 move    #$2300,sr
04052D32: 48c0                     ext.l   d0
04052D34: 52a80020                 addq.l  #1,$20(a0)
04052D38: 40c1                     move    sr,d1
04052D3A: 46c0                     move    d0,sr
04052D3C: 4e5e                     unlk    a6
04052D3E: 4e75                     rts
