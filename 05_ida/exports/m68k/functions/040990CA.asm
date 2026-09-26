040990CA: 4856                     pea     (a6)
040990CC: 2c4f                     movea.l sp,a6
040990CE: 1039040b61ac             move.b  (_machine_type).l,d0
040990D4: 6706                     beq.s   loc_40990DC
040990D6: 0c000002                 cmpi.b  #2,d0
040990DA: 661c                     bne.s   loc_40990F8
040990DC: 61fffffe051c             bsr.l   _od_update
040990E2: 082e0003000d             btst    #3,$D(a6)
040990E8: 670e                     beq.s   loc_40990F8
040990EA: 4ab9040aff10             tst.l   (_kernel_task).l
040990F0: 6706                     beq.s   loc_40990F8
040990F2: 61fffffe18bc             bsr.l   _od_eject
040990F8: 4e5e                     unlk    a6
040990FA: 4e75                     rts
