F003A358: 9de3bf98                 save    %sp, -0x68, %sp
F003A35C: a0100018                 mov     %i0, %l0
F003A360: 113c04ea                 sethi   %hi(_exported), %o0
F003A364: f00220c8                 ld      [%o0+%lo(_exported)], %i0
F003A368: 80a62000                 cmp     %i0, 0
F003A36C: 2280001a                 be,a    locret_F003A3D4
F003A370: b0102000                 mov     0, %i0
F003A374: 90062020                 add     %i0, 0x20, %o0 ! ' '! void *
F003A378: 92100010                 mov     %l0, %o1! void *
F003A37C: 7fff2ef8                 call    _bcmp
F003A380: 94102008                 mov     8, %o2
F003A384: 80a22000                 cmp     %o0, 0
F003A388: 3280000f                 bne,a   loc_F003A3C4
F003A38C: f006202c                 ld      [%i0+0x2C], %i0
F003A390: d2062028                 ld      [%i0+0x28], %o1! void *
F003A394: d0164000                 lduh    [%i1], %o0
F003A398: d4124000                 lduh    [%o1], %o2! size_t
F003A39C: 80a28008                 cmp     %o2, %o0
F003A3A0: 32800009                 bne,a   loc_F003A3C4
F003A3A4: f006202c                 ld      [%i0+0x2C], %i0
F003A3A8: 90026002                 add     %o1, 2, %o0! void *
F003A3AC: 7fff2eec                 call    _bcmp
F003A3B0: 92066002                 add     %i1, 2, %o1
F003A3B4: 80a22000                 cmp     %o0, 0
F003A3B8: 02800007                 be      locret_F003A3D4
F003A3BC: 01000000                 nop
F003A3C0: f006202c                 ld      [%i0+0x2C], %i0
F003A3C4: 80a62000                 cmp     %i0, 0
F003A3C8: 12bfffec                 bne     loc_F003A378
F003A3CC: 90062020                 add     %i0, 0x20, %o0 ! ' '
F003A3D0: b0102000                 mov     0, %i0
F003A3D4: 81c7e008                 ret
F003A3D8: 81e80000                 restore
