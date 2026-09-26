04006C64: 4856                     pea     (a6)
04006C66: 2c4f                     movea.l sp,a6
04006C68: 2079040b317c             movea.l (dword_40B317C).l,a0
04006C6E: b1f9040af710             cmpa.l  (_max_proc).l,a0
04006C74: 6c16                     bge.s   loc_4006C8C
04006C76: 5248                     addq.w  #1,a0
04006C78: 23c8040b317c             move.l  a0,(dword_40B317C).l
04006C7E: 2f39040b653c             move.l  (_proc_zone).l,-(sp)
04006C84: 61ff0004eed0             bsr.l   _zalloc
04006C8A: 6002                     bra.s   loc_4006C8E
04006C8C: 4280                     clr.l   d0
04006C8E: 4e5e                     unlk    a6
04006C90: 4e75                     rts
