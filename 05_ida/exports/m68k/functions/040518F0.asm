040518F0: 4856                     pea     (a6)
040518F2: 2c4f                     movea.l sp,a6
040518F4: 4879040518c6             pea     (_swtch_continue).l
040518FA: 61fffffff53c             bsr.l   _thread_block_with_continuation
04051900: 2079040b6004             movea.l (_processor_ptr).l,a0
04051906: 4280                     clr.l   d0
04051908: 4aa80104                 tst.l   $104(a0)
0405190C: 6e0a                     bgt.s   loc_4051918
0405190E: 20680128                 movea.l $128(a0),a0
04051912: 4aa80104                 tst.l   $104(a0)
04051916: 6f02                     ble.s   loc_405191A
04051918: 7001                     moveq   #1,d0
0405191A: 4e5e                     unlk    a6
0405191C: 4e75                     rts
