F007B50C: 9de3bf98                 save    %sp, -0x68, %sp
F007B510: d2062004                 ld      [%i0+4], %o1
F007B514: 80a26028                 cmp     %o1, 0x28 ! '('
F007B518: 12800005                 bne     loc_F007B52C
F007B51C: d00e2003                 ldub    [%i0+3], %o0
F007B520: 80a22001                 cmp     %o0, 1
F007B524: 22800005                 be,a    loc_F007B538
F007B528: d0062018                 ld      [%i0+0x18], %o0
F007B52C: 90103ed0                 mov     -0x130, %o0
F007B530: 1080001f                 ba      locret_F007B5AC
F007B534: d026601c                 st      %o0, [%i1+0x1C]
F007B538: 133c03d3                 sethi   %hi(dword_F00F4DA0), %o1
F007B53C: d20261a0                 ld      [%o1+%lo(dword_F00F4DA0)], %o1
F007B540: 80a20009                 cmp     %o0, %o1
F007B544: 12800012                 bne     loc_F007B58C
F007B548: 90103ed0                 mov     -0x130, %o0
F007B54C: d0062020                 ld      [%i0+0x20], %o0
F007B550: 133c03d3                 sethi   %hi(dword_F00F4DA4), %o1
F007B554: d20261a4                 ld      [%o1+%lo(dword_F00F4DA4)], %o1
F007B558: 80a20009                 cmp     %o0, %o1
F007B55C: 1280000c                 bne     loc_F007B58C
F007B560: 90103ed0                 mov     -0x130, %o0
F007B564: d606a010                 ld      [%i2+0x10], %o3
F007B568: 80a2e000                 cmp     %o3, 0
F007B56C: 32800005                 bne,a   loc_F007B580
F007B570: d0068000                 ld      [%i2], %o0
F007B574: 90103ed1                 mov     -0x12F, %o0
F007B578: 1080000d                 ba      locret_F007B5AC
F007B57C: d026601c                 st      %o0, [%i1+0x1C]
F007B580: d206201c                 ld      [%i0+0x1C], %o1
F007B584: 9fc2c000                 call    %o3
F007B588: d4062024                 ld      [%i0+0x24], %o2
F007B58C: d026601c                 st      %o0, [%i1+0x1C]
F007B590: d006601c                 ld      [%i1+0x1C], %o0
F007B594: 80a22000                 cmp     %o0, 0
F007B598: 12800005                 bne     locret_F007B5AC
F007B59C: 92102020                 mov     0x20, %o1 ! ' '
F007B5A0: 90102001                 mov     1, %o0
F007B5A4: d02e6003                 stb     %o0, [%i1+3]
F007B5A8: d2266004                 st      %o1, [%i1+4]
F007B5AC: 81c7e008                 ret
F007B5B0: 81e80000                 restore
