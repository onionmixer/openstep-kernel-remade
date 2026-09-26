F007BAA8: 9de3bf98                 save    %sp, -0x68, %sp
F007BAAC: d2062004                 ld      [%i0+4], %o1
F007BAB0: 80a26020                 cmp     %o1, 0x20 ! ' '
F007BAB4: 12800005                 bne     loc_F007BAC8
F007BAB8: d00e2003                 ldub    [%i0+3], %o0
F007BABC: 80a22001                 cmp     %o0, 1
F007BAC0: 22800005                 be,a    loc_F007BAD4
F007BAC4: d0062018                 ld      [%i0+0x18], %o0
F007BAC8: 90103ed0                 mov     -0x130, %o0
F007BACC: 10800018                 ba      locret_F007BB2C
F007BAD0: d026601c                 st      %o0, [%i1+0x1C]
F007BAD4: 133c03d3                 sethi   %hi(dword_F00F4DE0), %o1
F007BAD8: d20261e0                 ld      [%o1+%lo(dword_F00F4DE0)], %o1
F007BADC: 80a20009                 cmp     %o0, %o1
F007BAE0: 1280000b                 bne     loc_F007BB0C
F007BAE4: 90103ed0                 mov     -0x130, %o0
F007BAE8: d406a038                 ld      [%i2+0x38], %o2
F007BAEC: 80a2a000                 cmp     %o2, 0
F007BAF0: 32800005                 bne,a   loc_F007BB04
F007BAF4: d0068000                 ld      [%i2], %o0
F007BAF8: 90103ed1                 mov     -0x12F, %o0
F007BAFC: 1080000c                 ba      locret_F007BB2C
F007BB00: d026601c                 st      %o0, [%i1+0x1C]
F007BB04: 9fc28000                 call    %o2
F007BB08: d206201c                 ld      [%i0+0x1C], %o1
F007BB0C: d026601c                 st      %o0, [%i1+0x1C]
F007BB10: d006601c                 ld      [%i1+0x1C], %o0
F007BB14: 80a22000                 cmp     %o0, 0
F007BB18: 12800005                 bne     locret_F007BB2C
F007BB1C: 92102020                 mov     0x20, %o1 ! ' '
F007BB20: 90102001                 mov     1, %o0
F007BB24: d02e6003                 stb     %o0, [%i1+3]
F007BB28: d2266004                 st      %o1, [%i1+4]
F007BB2C: 81c7e008                 ret
F007BB30: 81e80000                 restore
