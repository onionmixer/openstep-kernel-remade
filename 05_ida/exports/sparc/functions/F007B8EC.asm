F007B8EC: 9de3bf98                 save    %sp, -0x68, %sp
F007B8F0: d0062004                 ld      [%i0+4], %o0
F007B8F4: 80a22020                 cmp     %o0, 0x20 ! ' '
F007B8F8: 12800005                 bne     loc_F007B90C
F007B8FC: d20e2003                 ldub    [%i0+3], %o1
F007B900: 80a26000                 cmp     %o1, 0
F007B904: 22800004                 be,a    loc_F007B914
F007B908: d0062018                 ld      [%i0+0x18], %o0
F007B90C: 10800010                 ba      loc_F007B94C
F007B910: 90103ed0                 mov     -0x130, %o0
F007B914: 133c03d3                 sethi   %hi(dword_F00F4DCC), %o1
F007B918: d20261cc                 ld      [%o1+%lo(dword_F00F4DCC)], %o1
F007B91C: 80a20009                 cmp     %o0, %o1
F007B920: 1280000b                 bne     loc_F007B94C
F007B924: 90103ed0                 mov     -0x130, %o0
F007B928: d406a02c                 ld      [%i2+0x2C], %o2
F007B92C: 80a2a000                 cmp     %o2, 0
F007B930: 32800004                 bne,a   loc_F007B940
F007B934: d0068000                 ld      [%i2], %o0
F007B938: 10800005                 ba      loc_F007B94C
F007B93C: 90103ed1                 mov     -0x12F, %o0
F007B940: 9fc28000                 call    %o2
F007B944: d206201c                 ld      [%i0+0x1C], %o1
F007B948: 90103ecf                 mov     -0x131, %o0
F007B94C: d026601c                 st      %o0, [%i1+0x1C]
F007B950: 81c7e008                 ret
F007B954: 81e80000                 restore
