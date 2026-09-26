0400853E: 4856                     pea     (a6)
04008540: 2c4f                     movea.l sp,a6
04008542: 48e72030                 movem.l d2/a2-a3,-(sp)
04008546: 61ff0000015e             bsr.l   _proc_shutdown
0400854C: 61ff0000009e             bsr.l   _kill_tasks
04008552: 61ff000451ca             bsr.l   _mfs_cache_clear
04008558: 61ff00057bf2             bsr.l   _vm_object_cache_clear
0400855E: 61ff0000038e             bsr.l   _fd_shutdown
04008564: 61ff00057874             bsr.l   _vm_object_shutdown
0400856A: 61ff0005acfa             bsr.l   _vnode_pager_shutdown
04008570: 2079040b67cc             movea.l (_rootvfs).l,a0
04008576: 2450                     movea.l (a0),a2
04008578: 4a8a                     tst.l   a2
0400857A: 673c                     beq.s   loc_40085B8
0400857C: 47f90400b358             lea     (_printf).l,a3
04008582: 486a0020                 pea     $20(a2)
04008586: 4879040a5ffa             pea     (aUnmountingS).l; "unmounting %s ... "
0400858C: 4e93                     jsr     (a3)
0400858E: 2412                     move.l  (a2),d2
04008590: 2f0a                     move.l  a2,-(sp)
04008592: 61ff0000e9b4             bsr.l   _dounmount
04008598: 504f                     addq.w  #8,sp
0400859A: 584f                     addq.w  #4,sp
0400859C: 4a80                     tst.l   d0
0400859E: 6708                     beq.s   loc_40085A8
040085A0: 4879040a600d             pea     (aFailed).l; "FAILED\n"
040085A6: 6006                     bra.s   loc_40085AE
040085A8: 4879040a6015             pea     (aDone).l; "done\n"
040085AE: 4e93                     jsr     (a3)
040085B0: 584f                     addq.w  #4,sp
040085B2: 2442                     movea.l d2,a2
040085B4: 4a8a                     tst.l   a2
040085B6: 66ca                     bne.s   loc_4008582
040085B8: 2f39040b67c8             move.l  (_rootdir).l,-(sp)
040085BE: 61ff00012b06             bsr.l   _vn_rele
040085C4: 2f39040b67cc             move.l  (_rootvfs).l,-(sp)
040085CA: 61ff0000e97c             bsr.l   _dounmount
040085D0: 504f                     addq.w  #8,sp
040085D2: 4a80                     tst.l   d0
040085D4: 670c                     beq.s   loc_40085E2
040085D6: 4879040a601b             pea     (aRootUnmountFai).l; "Root unmount FAILED\n"
040085DC: 61ff00002d7a             bsr.l   _printf
040085E2: 4cee0c04fff4             movem.l -$C(a6),d2/a2-a3
040085E8: 4e5e                     unlk    a6
040085EA: 4e75                     rts
