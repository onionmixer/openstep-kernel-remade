040527A0: 4856                     pea     (a6)
040527A2: 2c4f                     movea.l sp,a6
040527A4: 2f0a                     move.l  a2,-(sp)
040527A6: 246e0008                 movea.l 8(a6),a2
040527AA: b5f9040b5648             cmpa.l  (_active_threads).l,a2
040527B0: 670c                     beq.s   loc_40527BE
040527B2: 4879040a8fd2             pea     (aStackPrivilege).l; "stack_privilege"
040527B8: 61fffffb94ac             bsr.l   _panic
040527BE: 4aaa002c                 tst.l   $2C(a2)
040527C2: 6608                     bne.s   loc_40527CC
040527C4: 2579040c22dc002c         move.l  (_active_stacks).l,$2C(a2)
040527CC: 246efffc                 movea.l -4(a6),a2
040527D0: 4e5e                     unlk    a6
040527D2: 4e75                     rts
