040A51EE: 4a290002                 tst.b   2(a1)
040A51F2: 67ff0000000a             beq.l   loc_40A51FE
040A51F8: 08e900070000             bset    #7,0(a1)
040A51FE: 42290002                 clr.b   2(a1)
040A5202: 700c                     moveq   #$C,d0
040A5204: c149                     exg     a0,a1
040A5206: 61ffffffbad0             bsr.l   mem_write
040A520C: 4e75                     rts
