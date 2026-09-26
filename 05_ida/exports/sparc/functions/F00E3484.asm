F00E3484: 9de3bf98                 save    %sp, -0x68, %sp
F00E3488: 90102001                 mov     1, %o0
F00E348C: d02e6003                 stb     %o0, [%i1+3]
F00E3490: 90102020                 mov     0x20, %o0 ! ' '
F00E3494: d0266004                 st      %o0, [%i1+4]
F00E3498: d0062008                 ld      [%i0+8], %o0
F00E349C: d0266008                 st      %o0, [%i1+8]
F00E34A0: c026600c                 clr     [%i1+0xC]
F00E34A4: d0062010                 ld      [%i0+0x10], %o0
F00E34A8: d0266010                 st      %o0, [%i1+0x10]
F00E34AC: d0062014                 ld      [%i0+0x14], %o0
F00E34B0: 133c03e6                 sethi   %hi(dword_F00F9B94), %o1
F00E34B4: d2026394                 ld      [%o1+%lo(dword_F00F9B94)], %o1
F00E34B8: 90022064                 inc     0x64, %o0 ! 'd'
F00E34BC: d0266014                 st      %o0, [%i1+0x14]
F00E34C0: d2266018                 st      %o1, [%i1+0x18]
F00E34C4: 90103ed1                 mov     -0x12F, %o0
F00E34C8: d026601c                 st      %o0, [%i1+0x1C]
F00E34CC: d2062014                 ld      [%i0+0x14], %o1
F00E34D0: 90027d44                 add     %o1, -0x2BC, %o0
F00E34D4: 80a22024                 cmp     %o0, 0x24 ! '$'
F00E34D8: 18800008                 bgu     loc_F00E34F8
F00E34DC: 113c03e4                 sethi   %hi(unk_F00F90A8), %o0
F00E34E0: 901220a8                 bset    %lo(unk_F00F90A8), %o0
F00E34E4: 932a6002                 sll     %o1, 2, %o1
F00E34E8: d4024008                 ld      [%o1+%o0], %o2
F00E34EC: 80a2a000                 cmp     %o2, 0
F00E34F0: 12800004                 bne     loc_F00E3500
F00E34F4: 90100018                 mov     %i0, %o0
F00E34F8: 10800005                 ba      locret_F00E350C
F00E34FC: b0102000                 mov     0, %i0
F00E3500: 9fc28000                 call    %o2
F00E3504: 92100019                 mov     %i1, %o1
F00E3508: b0102001                 mov     1, %i0
F00E350C: 81c7e008                 ret
F00E3510: 81e80000                 restore
