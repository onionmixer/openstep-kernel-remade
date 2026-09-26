040373B8: 4856                     pea     (a6)
040373BA: 2c4f                     movea.l sp,a6
040373BC: 206e0008                 movea.l 8(a6),a0
040373C0: 1028000c                 move.b  $C(a0),d0
040373C4: 6c1a                     bge.s   loc_40373E0
040373C6: 0200007f                 andi.b  #$7F,d0
040373CA: 1140000c                 move.b  d0,$C(a0)
040373CE: 4ab9040c10a0             tst.l   (dword_40C10A0).l
040373D4: 670a                     beq.s   loc_40373E0
040373D6: 2f08                     move.l  a0,-(sp)
040373D8: 2079040c109c             movea.l (dword_40C109C).l,a0
040373DE: 4e90                     jsr     (a0)
040373E0: 4e5e                     unlk    a6
040373E2: 4e75                     rts
