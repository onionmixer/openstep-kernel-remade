0404E174: 4856                     pea     (a6)
0404E176: 2c4f                     movea.l sp,a6
0404E178: 61ffffffc9b8             bsr.l   _simple_lock_alloc
0404E17E: 23c0040c2414             move.l  d0,(__kernDebuggerLock).l
0404E184: 2f00                     move.l  d0,-(sp)
0404E186: 61fffffb373a             bsr.l   _simple_unlock
0404E18C: 4e5e                     unlk    a6
0404E18E: 4e75                     rts
