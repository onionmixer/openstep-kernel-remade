F007B480: 9de3bf98                 save    %sp, -0x68, %sp
F007B484: d2062004                 ld      [%i0+4], %o1
F007B488: 80a26020                 cmp     %o1, 0x20 ! ' '
F007B48C: 12800005                 bne     loc_F007B4A0
F007B490: d00e2003                 ldub    [%i0+3], %o0
F007B494: 80a22000                 cmp     %o0, 0
F007B498: 22800005                 be,a    loc_F007B4AC
F007B49C: d0062018                 ld      [%i0+0x18], %o0
F007B4A0: 90103ed0                 mov     -0x130, %o0
F007B4A4: 10800018                 ba      locret_F007B504
F007B4A8: d026601c                 st      %o0, [%i1+0x1C]
F007B4AC: 133c03d3                 sethi   %hi(dword_F00F4D9C), %o1
F007B4B0: d202619c                 ld      [%o1+%lo(dword_F00F4D9C)], %o1
F007B4B4: 80a20009                 cmp     %o0, %o1
F007B4B8: 1280000b                 bne     loc_F007B4E4
F007B4BC: 90103ed0                 mov     -0x130, %o0
F007B4C0: d406a00c                 ld      [%i2+0xC], %o2
F007B4C4: 80a2a000                 cmp     %o2, 0
F007B4C8: 32800005                 bne,a   loc_F007B4DC
F007B4CC: d0068000                 ld      [%i2], %o0
F007B4D0: 90103ed1                 mov     -0x12F, %o0
F007B4D4: 1080000c                 ba      locret_F007B504
F007B4D8: d026601c                 st      %o0, [%i1+0x1C]
F007B4DC: 9fc28000                 call    %o2
F007B4E0: d206201c                 ld      [%i0+0x1C], %o1
F007B4E4: d026601c                 st      %o0, [%i1+0x1C]
F007B4E8: d006601c                 ld      [%i1+0x1C], %o0
F007B4EC: 80a22000                 cmp     %o0, 0
F007B4F0: 12800005                 bne     locret_F007B504
F007B4F4: 92102020                 mov     0x20, %o1 ! ' '
F007B4F8: 90102001                 mov     1, %o0
F007B4FC: d02e6003                 stb     %o0, [%i1+3]
F007B500: d2266004                 st      %o1, [%i1+4]
F007B504: 81c7e008                 ret
F007B508: 81e80000                 restore
