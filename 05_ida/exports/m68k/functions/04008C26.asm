04008C26: 4856                     pea     (a6)
04008C28: 2c4f                     movea.l sp,a6
04008C2A: 48780004                 pea     (4).w
04008C2E: 61ff000915e6             bsr.l   _unix_syscall_return
04008C34: 4e5e                     unlk    a6
04008C36: 4e75                     rts
