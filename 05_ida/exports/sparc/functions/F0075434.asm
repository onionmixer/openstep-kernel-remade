F0075434: 9de3bf98                 save    %sp, -0x68, %sp
F0075438: 400085d4                 call    _splusclock
F007543C: a0062020                 add     %i0, 0x20, %l0 ! ' '
F0075440: a2100008                 mov     %o0, %l1
F0075444: d0040000                 ld      [%l0], %o0
F0075448: 80a22000                 cmp     %o0, 0
F007544C: 12bffffe                 bne     loc_F0075444
F0075450: 01000000                 nop
F0075454: 40008695                 call    _simple_lock_try
F0075458: 90100010                 mov     %l0, %o0
F007545C: 80a22000                 cmp     %o0, 0
F0075460: 02bffff9                 be      loc_F0075444
F0075464: 01000000                 nop
F0075468: d0062040                 ld      [%i0+0x40], %o0
F007546C: 90023fff                 inc     -1, %o0
F0075470: 80a22000                 cmp     %o0, 0
F0075474: 1280000c                 bne     loc_F00754A4
F0075478: d0262040                 st      %o0, [%i0+0x40]
F007547C: d006204c                 ld      [%i0+0x4C], %o0
F0075480: 920a3fed                 and     %o0, -0x13, %o1
F0075484: 808a2005                 btst    5, %o0
F0075488: 12800007                 bne     loc_F00754A4
F007548C: d226204c                 st      %o1, [%i0+0x4C]
F0075490: 90126004                 or      %o1, 4, %o0
F0075494: d026204c                 st      %o0, [%i0+0x4C]
F0075498: 90100018                 mov     %i0, %o0
F007549C: 7ffff201                 call    _thread_setrun
F00754A0: 92102001                 mov     1, %o1
F00754A4: c0262020                 clr     [%i0+0x20]
F00754A8: 4000861f                 call    _splx
F00754AC: 90100011                 mov     %l1, %o0
F00754B0: 81c7e008                 ret
F00754B4: 81e80000                 restore
