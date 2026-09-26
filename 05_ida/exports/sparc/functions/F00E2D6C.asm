F00E2D6C: 9de3bf98                 save    %sp, -0x68, %sp
F00E2D70: 90102001                 mov     1, %o0
F00E2D74: d02e6003                 stb     %o0, [%i1+3]
F00E2D78: 90102020                 mov     0x20, %o0 ! ' '
F00E2D7C: d0266004                 st      %o0, [%i1+4]
F00E2D80: d0062008                 ld      [%i0+8], %o0
F00E2D84: d0266008                 st      %o0, [%i1+8]
F00E2D88: c026600c                 clr     [%i1+0xC]
F00E2D8C: d0062010                 ld      [%i0+0x10], %o0
F00E2D90: d0266010                 st      %o0, [%i1+0x10]
F00E2D94: d0062014                 ld      [%i0+0x14], %o0
F00E2D98: 133c03e6                 sethi   %hi(dword_F00F9A2C), %o1
F00E2D9C: d202622c                 ld      [%o1+%lo(dword_F00F9A2C)], %o1
F00E2DA0: 90022064                 inc     0x64, %o0 ! 'd'
F00E2DA4: d0266014                 st      %o0, [%i1+0x14]
F00E2DA8: d2266018                 st      %o1, [%i1+0x18]
F00E2DAC: 90103ed1                 mov     -0x12F, %o0
F00E2DB0: d026601c                 st      %o0, [%i1+0x1C]
F00E2DB4: 113fffe1                 sethi   -0x7C00, %o0
F00E2DB8: d2062014                 ld      [%i0+0x14], %o1
F00E2DBC: 901222e8                 bset    0x2E8, %o0
F00E2DC0: 90024008                 add     %o1, %o0, %o0
F00E2DC4: 80a22008                 cmp     %o0, 8
F00E2DC8: 18800008                 bgu     loc_F00E2DE8
F00E2DCC: 113c036d                 sethi   %hi(loc_F00DB5D0), %o0
F00E2DD0: 901221d0                 bset    %lo(loc_F00DB5D0), %o0
F00E2DD4: 932a6002                 sll     %o1, 2, %o1
F00E2DD8: d4024008                 ld      [%o1+%o0], %o2
F00E2DDC: 80a2a000                 cmp     %o2, 0
F00E2DE0: 12800004                 bne     loc_F00E2DF0
F00E2DE4: 90100018                 mov     %i0, %o0
F00E2DE8: 10800005                 ba      locret_F00E2DFC
F00E2DEC: b0102000                 mov     0, %i0
F00E2DF0: 9fc28000                 call    %o2
F00E2DF4: 92100019                 mov     %i1, %o1
F00E2DF8: b0102001                 mov     1, %i0
F00E2DFC: 81c7e008                 ret
F00E2E00: 81e80000                 restore
