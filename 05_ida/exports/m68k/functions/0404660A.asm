0404660A: 4e56fffc                 link    a6,#-4
0404660E: 202e0008                 move.l  arg_0(a6),d0
04046612: 6604                     bne.s   loc_4046618
04046614: 7010                     moveq   #$10,d0
04046616: 6024                     bra.s   loc_404663C
04046618: 486efffc                 pea     var_4(a6)
0404661C: 48780001                 pea     (1).w
04046620: 2f2e000c                 move.l  arg_4(a6),-(sp)
04046624: 2f00                     move.l  d0,-(sp)
04046626: 61ffffff9b7a             bsr.l   _ipc_object_translate
0404662C: 4a80                     tst.l   d0
0404662E: 660c                     bne.s   loc_404663C
04046630: 206efffc                 movea.l var_4(a6),a0
04046634: 216e00100014             move.l  arg_8(a6),$14(a0)
0404663A: 4280                     clr.l   d0
0404663C: 4e5e                     unlk    a6
0404663E: 4e75                     rts
