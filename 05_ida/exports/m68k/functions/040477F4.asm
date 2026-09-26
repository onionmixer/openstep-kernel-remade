040477F4: 4856                     pea     (a6)
040477F6: 2c4f                     movea.l sp,a6
040477F8: 2f0a                     move.l  a2,-(sp)
040477FA: 2479040b5648             movea.l (_active_threads).l,a2
04047800: e8ea01820177             bftst   $177(a2){6:2}
04047806: 670e                     beq.s   loc_4047816
04047808: 61ff0000b91a             bsr.l   _thread_halt_self
0404780E: e8ea01820177             bftst   $177(a2){6:2}
04047814: 66f2                     bne.s   loc_4047808
04047816: 2f2a000c                 move.l  $C(a2),-(sp)
0404781A: 61ff0000a842             bsr.l   _task_terminate
04047820: 61ff0000b902             bsr.l   _thread_halt_self
04047826: 246efffc                 movea.l -4(a6),a2
0404782A: 4e5e                     unlk    a6
0404782C: 4e75                     rts
