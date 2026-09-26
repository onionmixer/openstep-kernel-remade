040048D6: 4856                     pea     (a6)
040048D8: 2c4f                     movea.l sp,a6
040048DA: 2079040b57d4             movea.l (dword_40B57D4).l,a0
040048E0: 20680024                 movea.l $24(a0),a0
040048E4: 42a80008                 clr.l   8(a0)
040048E8: 61ff00000012             bsr.l   _execve
040048EE: 2079040b57d4             movea.l (dword_40B57D4).l,a0
040048F4: 11400064                 move.b  d0,$64(a0)
040048F8: 4e5e                     unlk    a6
040048FA: 4e75                     rts
