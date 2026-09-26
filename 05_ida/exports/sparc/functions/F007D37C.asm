F007D37C: 9de3bf98                 save    %sp, -0x68, %sp
F007D380: 1300003f                 sethi   0xFC00, %o1
F007D384: d0060000                 ld      [%i0], %o0
F007D388: 92126300                 bset    0x300, %o1
F007D38C: 900a0009                 and     %o0, %o1, %o0
F007D390: 91322008                 srl     %o0, 8, %o0
F007D394: d0264000                 st      %o0, [%i1]
F007D398: 90102020                 mov     0x20, %o0 ! ' '
F007D39C: d0266004                 st      %o0, [%i1+4]
F007D3A0: d006200c                 ld      [%i0+0xC], %o0
F007D3A4: d0266008                 st      %o0, [%i1+8]
F007D3A8: c026600c                 clr     [%i1+0xC]
F007D3AC: c0266010                 clr     [%i1+0x10]
F007D3B0: d0062014                 ld      [%i0+0x14], %o0
F007D3B4: 90022064                 inc     0x64, %o0 ! 'd'
F007D3B8: d0266014                 st      %o0, [%i1+0x14]
F007D3BC: 113c0444                 sethi   %hi(dword_F01111E0), %o0
F007D3C0: d00221e0                 ld      [%o0+%lo(dword_F01111E0)], %o0
F007D3C4: d0266018                 st      %o0, [%i1+0x18]
F007D3C8: d2062014                 ld      [%i0+0x14], %o1
F007D3CC: 900275d8                 add     %o1, -0xA28, %o0
F007D3D0: 80a22029                 cmp     %o0, 0x29 ! ')'
F007D3D4: 18800008                 bgu     loc_F007D3F4
F007D3D8: 113c043a                 sethi   %hi(aDev0xXBlockDFs+0x20), %o0! ""
F007D3DC: 90122098                 bset    %lo(aDev0xXBlockDFs+0x20), %o0! ""
F007D3E0: 932a6002                 sll     %o1, 2, %o1
F007D3E4: d4024008                 ld      [%o1+%o0], %o2
F007D3E8: 80a2a000                 cmp     %o2, 0
F007D3EC: 12800006                 bne     loc_F007D404
F007D3F0: 90100018                 mov     %i0, %o0
F007D3F4: 90103ed1                 mov     -0x12F, %o0
F007D3F8: d026601c                 st      %o0, [%i1+0x1C]
F007D3FC: 10800005                 ba      locret_F007D410
F007D400: b0102000                 mov     0, %i0
F007D404: 9fc28000                 call    %o2
F007D408: 92100019                 mov     %i1, %o1
F007D40C: b0102001                 mov     1, %i0
F007D410: 81c7e008                 ret
F007D414: 81e80000                 restore
