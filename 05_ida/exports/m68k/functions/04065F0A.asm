04065F0A: 4856                     pea     (a6)
04065F0C: 2c4f                     movea.l sp,a6
04065F0E: 2f02                     move.l  d2,-(sp)
04065F10: 2239040b4f4e             move.l  (dword_40B4F4E).l,d1
04065F16: 2001                     move.l  d1,d0
04065F18: 52b9040b4f4e             addq.l  #1,(dword_40B4F4E).l
04065F1E: 4a81                     tst.l   d1
04065F20: 6c06                     bge.s   loc_4065F28
04065F22: 0680000000ff             addi.l  #$FF,d0
04065F28: 0240ff00                 andi.w  #$FF00,d0
04065F2C: 9280                     sub.l   d0,d1
04065F2E: 2001                     move.l  d1,d0
04065F30: 7401                     moveq   #1,d2
04065F32: b480                     cmp.l   d0,d2
04065F34: 6610                     bne.s   loc_4065F46
04065F36: 48780005                 pea     (5).w
04065F3A: 4879040a9e49             pea     (aIplDSpuriousIn).l; "ipl%d: spurious interrupt\n"
04065F40: 61fffffa5416             bsr.l   _printf
04065F46: 7001                     moveq   #1,d0
04065F48: 242efffc                 move.l  -4(a6),d2
04065F4C: 4e5e                     unlk    a6
04065F4E: 4e75                     rts
