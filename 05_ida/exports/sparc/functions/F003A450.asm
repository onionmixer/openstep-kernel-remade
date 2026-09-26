F003A450: 9de3bf98                 save    %sp, -0x68, %sp
F003A454: d0062008                 ld      [%i0+8], %o0
F003A458: 80a22001                 cmp     %o0, 1
F003A45C: 12800009                 bne     loc_F003A480
F003A460: a0100018                 mov     %i0, %l0
F003A464: d206200c                 ld      [%i0+0xC], %o1
F003A468: 80a26000                 cmp     %o1, 0
F003A46C: 22800006                 be,a    loc_F003A484
F003A470: d0040000                 ld      [%l0], %o0
F003A474: d0062010                 ld      [%i0+0x10], %o0
F003A478: 4000b74a                 call    _kfree
F003A47C: 932a6004                 sll     %o1, 4, %o1
F003A480: d0040000                 ld      [%l0], %o0
F003A484: 808a2002                 btst    2, %o0
F003A488: 2280000a                 be,a    loc_F003A4B0
F003A48C: d0062028                 ld      [%i0+0x28], %o0
F003A490: d2042018                 ld      [%l0+0x18], %o1
F003A494: 80a26000                 cmp     %o1, 0
F003A498: 22800006                 be,a    loc_F003A4B0
F003A49C: d0062028                 ld      [%i0+0x28], %o0
F003A4A0: d004201c                 ld      [%l0+0x1C], %o0
F003A4A4: 4000b73f                 call    _kfree
F003A4A8: 932a6004                 sll     %o1, 4, %o1
F003A4AC: d0062028                 ld      [%i0+0x28], %o0
F003A4B0: d2120000                 lduh    [%o0], %o1
F003A4B4: 4000b73b                 call    _kfree
F003A4B8: 92026002                 inc     2, %o1
F003A4BC: 90100018                 mov     %i0, %o0
F003A4C0: 4000b738                 call    _kfree
F003A4C4: 92102030                 mov     0x30, %o1 ! '0'
F003A4C8: 81c7e008                 ret
F003A4CC: 81e80000                 restore
