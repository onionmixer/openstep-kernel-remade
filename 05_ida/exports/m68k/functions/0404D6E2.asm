0404D6E2: 4856                     pea     (a6)
0404D6E4: 2c4f                     movea.l sp,a6
0404D6E6: 2f02                     move.l  d2,-(sp)
0404D6E8: 2239040af8d0             move.l  (_mfs_files_mapped).l,d1
0404D6EE: b2b9040af8cc             cmp.l   (_mfs_files_max).l,d1
0404D6F4: 6f20                     ble.s   loc_404D716
0404D6F6: 2439040c23cc             move.l  (_vm_info_queue).l,d2
0404D6FC: 2f02                     move.l  d2,-(sp)
0404D6FE: 61fffffff9c2             bsr.l   _vm_info_dequeue
0404D704: 48780001                 pea     (1).w
0404D708: 2f02                     move.l  d2,-(sp)
0404D70A: 61ffffffff34             bsr.l   _mfs_memfree
0404D710: 504f                     addq.w  #8,sp
0404D712: 584f                     addq.w  #4,sp
0404D714: 60d2                     bra.s   loc_404D6E8
0404D716: 242efffc                 move.l  -4(a6),d2
0404D71A: 4e5e                     unlk    a6
0404D71C: 4e75                     rts
