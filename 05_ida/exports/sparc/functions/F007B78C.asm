F007B78C: 9de3bf98                 save    %sp, -0x68, %sp
F007B790: d2062004                 ld      [%i0+4], %o1
F007B794: 80a26028                 cmp     %o1, 0x28 ! '('
F007B798: 12800005                 bne     loc_F007B7AC
F007B79C: d00e2003                 ldub    [%i0+3], %o0
F007B7A0: 80a22001                 cmp     %o0, 1
F007B7A4: 22800005                 be,a    loc_F007B7B8
F007B7A8: d0062018                 ld      [%i0+0x18], %o0
F007B7AC: 90103ed0                 mov     -0x130, %o0
F007B7B0: 1080001f                 ba      locret_F007B82C
F007B7B4: d026601c                 st      %o0, [%i1+0x1C]
F007B7B8: 133c03d3                 sethi   %hi(dword_F00F4DC0), %o1
F007B7BC: d20261c0                 ld      [%o1+%lo(dword_F00F4DC0)], %o1
F007B7C0: 80a20009                 cmp     %o0, %o1
F007B7C4: 12800012                 bne     loc_F007B80C
F007B7C8: 90103ed0                 mov     -0x130, %o0
F007B7CC: d0062020                 ld      [%i0+0x20], %o0
F007B7D0: 133c03d3                 sethi   %hi(dword_F00F4DC4), %o1
F007B7D4: d20261c4                 ld      [%o1+%lo(dword_F00F4DC4)], %o1
F007B7D8: 80a20009                 cmp     %o0, %o1
F007B7DC: 1280000c                 bne     loc_F007B80C
F007B7E0: 90103ed0                 mov     -0x130, %o0
F007B7E4: d606a020                 ld      [%i2+0x20], %o3
F007B7E8: 80a2e000                 cmp     %o3, 0
F007B7EC: 32800005                 bne,a   loc_F007B800
F007B7F0: d0068000                 ld      [%i2], %o0
F007B7F4: 90103ed1                 mov     -0x12F, %o0
F007B7F8: 1080000d                 ba      locret_F007B82C
F007B7FC: d026601c                 st      %o0, [%i1+0x1C]
F007B800: d206201c                 ld      [%i0+0x1C], %o1
F007B804: 9fc2c000                 call    %o3
F007B808: d4062024                 ld      [%i0+0x24], %o2
F007B80C: d026601c                 st      %o0, [%i1+0x1C]
F007B810: d006601c                 ld      [%i1+0x1C], %o0
F007B814: 80a22000                 cmp     %o0, 0
F007B818: 12800005                 bne     locret_F007B82C
F007B81C: 92102020                 mov     0x20, %o1 ! ' '
F007B820: 90102001                 mov     1, %o0
F007B824: d02e6003                 stb     %o0, [%i1+3]
F007B828: d2266004                 st      %o1, [%i1+4]
F007B82C: 81c7e008                 ret
F007B830: 81e80000                 restore
