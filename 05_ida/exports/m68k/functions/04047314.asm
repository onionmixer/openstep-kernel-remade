04047314: 4856                     pea     (a6)
04047316: 2c4f                     movea.l sp,a6
04047318: 202e0008                 move.l  8(a6),d0
0404731C: 671c                     beq.s   loc_404733A
0404731E: 2f2e0010                 move.l  $10(a6),-(sp)
04047322: 48780001                 pea     (1).w
04047326: 48780006                 pea     (6).w
0404732A: 2f2e000c                 move.l  $C(a6),-(sp)
0404732E: 2f00                     move.l  d0,-(sp)
04047330: 61ffffff9558             bsr.l   _ipc_object_copyin_compat
04047336: 4a80                     tst.l   d0
04047338: 6702                     beq.s   loc_404733C
0404733A: 7004                     moveq   #4,d0
0404733C: 4e5e                     unlk    a6
0404733E: 4e75                     rts
