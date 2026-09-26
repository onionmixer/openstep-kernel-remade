F007B880: 9de3bf98                 save    %sp, -0x68, %sp
F007B884: d0062004                 ld      [%i0+4], %o0
F007B888: 80a22020                 cmp     %o0, 0x20 ! ' '
F007B88C: 12800005                 bne     loc_F007B8A0
F007B890: d20e2003                 ldub    [%i0+3], %o1
F007B894: 80a26001                 cmp     %o1, 1
F007B898: 22800004                 be,a    loc_F007B8A8
F007B89C: d0062018                 ld      [%i0+0x18], %o0
F007B8A0: 10800010                 ba      loc_F007B8E0
F007B8A4: 90103ed0                 mov     -0x130, %o0
F007B8A8: 133c03d3                 sethi   %hi(dword_F00F4DC8), %o1
F007B8AC: d20261c8                 ld      [%o1+%lo(dword_F00F4DC8)], %o1
F007B8B0: 80a20009                 cmp     %o0, %o1
F007B8B4: 1280000b                 bne     loc_F007B8E0
F007B8B8: 90103ed0                 mov     -0x130, %o0
F007B8BC: d406a028                 ld      [%i2+0x28], %o2
F007B8C0: 80a2a000                 cmp     %o2, 0
F007B8C4: 32800004                 bne,a   loc_F007B8D4
F007B8C8: d0068000                 ld      [%i2], %o0
F007B8CC: 10800005                 ba      loc_F007B8E0
F007B8D0: 90103ed1                 mov     -0x12F, %o0
F007B8D4: 9fc28000                 call    %o2
F007B8D8: d206201c                 ld      [%i0+0x1C], %o1
F007B8DC: 90103ecf                 mov     -0x131, %o0
F007B8E0: d026601c                 st      %o0, [%i1+0x1C]
F007B8E4: 81c7e008                 ret
F007B8E8: 81e80000                 restore
