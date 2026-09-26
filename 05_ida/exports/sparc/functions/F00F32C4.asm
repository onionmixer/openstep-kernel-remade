F00F32C4: 912a2018                 sll     %o0, 24, %o0
F00F32C8: 913a2018                 sra     %o0, 24, %o0
F00F32CC: 80a22001                 cmp     %o0, 1
F00F32D0: 12800005                 bne     loc_F00F32E4
F00F32D4: 073c04bc                 sethi   -0xFED1000, %g3
F00F32D8: 053c04bc                 sethi   %hi(__objc_multithread_mask), %g2
F00F32DC: 10800004                 ba      locret_F00F32EC
F00F32E0: c020a130                 clr     [%g2+%lo(__objc_multithread_mask)]
F00F32E4: 84103fff                 mov     -1, %g2
F00F32E8: c420e130                 st      %g2, [%g3+0x130]
F00F32EC: 81c3e008                 retl
F00F32F0: 01000000                 nop
