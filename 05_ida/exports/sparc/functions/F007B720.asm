F007B720: 9de3bf98                 save    %sp, -0x68, %sp
F007B724: d0062004                 ld      [%i0+4], %o0
F007B728: 80a22020                 cmp     %o0, 0x20 ! ' '
F007B72C: 12800005                 bne     loc_F007B740
F007B730: d20e2003                 ldub    [%i0+3], %o1
F007B734: 80a26001                 cmp     %o1, 1
F007B738: 22800004                 be,a    loc_F007B748
F007B73C: d0062018                 ld      [%i0+0x18], %o0
F007B740: 10800010                 ba      loc_F007B780
F007B744: 90103ed0                 mov     -0x130, %o0
F007B748: 133c03d3                 sethi   %hi(dword_F00F4DBC), %o1
F007B74C: d20261bc                 ld      [%o1+%lo(dword_F00F4DBC)], %o1
F007B750: 80a20009                 cmp     %o0, %o1
F007B754: 1280000b                 bne     loc_F007B780
F007B758: 90103ed0                 mov     -0x130, %o0
F007B75C: d406a01c                 ld      [%i2+0x1C], %o2
F007B760: 80a2a000                 cmp     %o2, 0
F007B764: 32800004                 bne,a   loc_F007B774
F007B768: d0068000                 ld      [%i2], %o0
F007B76C: 10800005                 ba      loc_F007B780
F007B770: 90103ed1                 mov     -0x12F, %o0
F007B774: 9fc28000                 call    %o2
F007B778: d206201c                 ld      [%i0+0x1C], %o1
F007B77C: 90103ecf                 mov     -0x131, %o0
F007B780: d026601c                 st      %o0, [%i1+0x1C]
F007B784: 81c7e008                 ret
F007B788: 81e80000                 restore
