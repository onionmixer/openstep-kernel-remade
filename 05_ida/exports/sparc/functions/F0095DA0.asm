F0095DA0: 173c0464                 sethi   %hi(_use_ic), %o3
F0095DA4: d602e2e0                 ld      [%o3+%lo(_use_ic)], %o3
F0095DA8: 8092c000                 tst     %o3
F0095DAC: 02800003                 be      loc_F0095DB8
F0095DB0: 94100000                 clr     %o2
F0095DB4: 9412a200                 bset    0x200, %o2
F0095DB8: 173c0464                 sethi   %hi(_use_dc), %o3
F0095DBC: d602e2e4                 ld      [%o3+%lo(_use_dc)], %o3
F0095DC0: 8092c000                 tst     %o3
F0095DC4: 02800003                 be      loc_F0095DD0
F0095DC8: 01000000                 nop
F0095DCC: 9412a100                 bset    0x100, %o2
F0095DD0: 90102000                 mov     0, %o0
F0095DD4: d2820080                 lda     [%o0]#ASI_NUCLEUS, %o1
F0095DD8: 922a6300                 bclr    0x300, %o1
F0095DDC: 9212400a                 bset    %o2, %o1
F0095DE0: 81c3e008                 retl
F0095DE4: d2a20080                 sta     %o1, [%o0]#ASI_NUCLEUS
