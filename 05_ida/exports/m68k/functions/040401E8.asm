040401E8: 4e56fffc                 link    a6,#-4
040401EC: 486efffc                 pea     var_4(a6)
040401F0: 2f2e000c                 move.l  arg_4(a6),-(sp)
040401F4: 2f2e0008                 move.l  arg_0(a6),-(sp)
040401F8: 61ffffffbf12             bsr.l   _ipc_entry_alloc
040401FE: 4a80                     tst.l   d0
04040200: 660c                     bne.s   loc_404020E
04040202: 206efffc                 movea.l var_4(a6),a0
04040206: 009000100001             ori.l   #$100001,(a0)
0404020C: 4280                     clr.l   d0
0404020E: 4e5e                     unlk    a6
04040210: 4e75                     rts
