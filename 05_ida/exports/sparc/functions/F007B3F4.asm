F007B3F4: 9de3bf98                 save    %sp, -0x68, %sp
F007B3F8: d2062004                 ld      [%i0+4], %o1
F007B3FC: 80a26020                 cmp     %o1, 0x20 ! ' '
F007B400: 12800005                 bne     loc_F007B414
F007B404: d00e2003                 ldub    [%i0+3], %o0
F007B408: 80a22001                 cmp     %o0, 1
F007B40C: 22800005                 be,a    loc_F007B420
F007B410: d0062018                 ld      [%i0+0x18], %o0
F007B414: 90103ed0                 mov     -0x130, %o0
F007B418: 10800018                 ba      locret_F007B478
F007B41C: d026601c                 st      %o0, [%i1+0x1C]
F007B420: 133c03d3                 sethi   %hi(dword_F00F4D98), %o1
F007B424: d2026198                 ld      [%o1+%lo(dword_F00F4D98)], %o1
F007B428: 80a20009                 cmp     %o0, %o1
F007B42C: 1280000b                 bne     loc_F007B458
F007B430: 90103ed0                 mov     -0x130, %o0
F007B434: d406a008                 ld      [%i2+8], %o2
F007B438: 80a2a000                 cmp     %o2, 0
F007B43C: 32800005                 bne,a   loc_F007B450
F007B440: d0068000                 ld      [%i2], %o0
F007B444: 90103ed1                 mov     -0x12F, %o0
F007B448: 1080000c                 ba      locret_F007B478
F007B44C: d026601c                 st      %o0, [%i1+0x1C]
F007B450: 9fc28000                 call    %o2
F007B454: d206201c                 ld      [%i0+0x1C], %o1
F007B458: d026601c                 st      %o0, [%i1+0x1C]
F007B45C: d006601c                 ld      [%i1+0x1C], %o0
F007B460: 80a22000                 cmp     %o0, 0
F007B464: 12800005                 bne     locret_F007B478
F007B468: 92102020                 mov     0x20, %o1 ! ' '
F007B46C: 90102001                 mov     1, %o0
F007B470: d02e6003                 stb     %o0, [%i1+3]
F007B474: d2266004                 st      %o1, [%i1+4]
F007B478: 81c7e008                 ret
F007B47C: 81e80000                 restore
