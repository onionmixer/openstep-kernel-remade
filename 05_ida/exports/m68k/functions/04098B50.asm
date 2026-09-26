04098B50: 4856                     pea     (a6)
04098B52: 2c4f                     movea.l sp,a6
04098B54: 61fffff68880             bsr.l   _pflush_super
04098B5A: 4ab9040b5648             tst.l   (_active_threads).l
04098B60: 6706                     beq.s   loc_4098B68
04098B62: 61fffff68890             bsr.l   _pflush_user
04098B68: 4e5e                     unlk    a6
04098B6A: 4e75                     rts
