040A432C: 206eff88                 movea.l -$78(a6),a0
040A4330: 2f3c00000000             move.l  #0,-(sp)
040A4336: 43ef0002                 lea     4+var_2(sp),a1
040A433A: 7002                     moveq   #2,d0
040A433C: 61ffffffc9c8             bsr.l   mem_read
040A4342: 201f                     move.l  (sp)+,d0
040A4344: 4e75                     rts
