04003C0A: 4856                     pea     (a6)
04003C0C: 2c4f                     movea.l sp,a6
04003C0E: 2079040b57d4             movea.l (dword_40B57D4).l,a0
04003C14: 217c00000100005c         move.l  #$100,$5C(a0)
04003C1C: 4e5e                     unlk    a6
04003C1E: 4e75                     rts
