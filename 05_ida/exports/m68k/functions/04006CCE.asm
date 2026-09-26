04006CCE: 4856                     pea     (a6)
04006CD0: 2c4f                     movea.l sp,a6
04006CD2: 2f0a                     move.l  a2,-(sp)
04006CD4: 2f02                     move.l  d2,-(sp)
04006CD6: 7479                     moveq   #$79,d2 ; 'y'
04006CD8: 4602                     not.b   d2
04006CDA: 4879040a5f11             pea     (aProcStructures).l; "proc structures"
04006CE0: 42a7                     clr.l   -(sp)
04006CE2: 42a7                     clr.l   -(sp)
04006CE4: 2239040af710             move.l  (_max_proc).l,d1
04006CEA: 4c3c180000003458         muls.l  #$3458,d1
04006CF2: 2f01                     move.l  d1,-(sp)
04006CF4: 2f02                     move.l  d2,-(sp)
04006CF6: 61ff0004e2ea             bsr.l   _zinit
04006CFC: 23c0040b653c             move.l  d0,(_proc_zone).l
04006D02: 42b9040b317c             clr.l   (dword_40B317C).l
04006D08: 42b9040b61a4             clr.l   (_freeproc).l
04006D0E: 61ffffffff54             bsr.l   _getproc
04006D14: 2440                     movea.l d0,a2
04006D16: 2f02                     move.l  d2,-(sp)
04006D18: 2f0a                     move.l  a2,-(sp)
04006D1A: 61ff0008c0f6             bsr.l   _bzero
04006D20: 23ca040b6524             move.l  a2,(_allproc).l
04006D26: 42aa0008                 clr.l   8(a2)
04006D2A: 257c040b6524000c         move.l  #$40B6524,$C(a2)
04006D32: 23ca040b5dc0             move.l  a2,(_kernel_proc).l
04006D38: 42b9040b6520             clr.l   (_zombproc).l
04006D3E: 242efff8                 move.l  -8(a6),d2
04006D42: 246efffc                 movea.l -4(a6),a2
04006D46: 4e5e                     unlk    a6
04006D48: 4e75                     rts
