F004F240: 9de3bf98                 save    %sp, -0x68, %sp
F004F244: 4000003c                 call    sub_F004F334
F004F248: 90100018                 mov     %i0, %o0
F004F24C: a0100008                 mov     %o0, %l0
F004F250: 40006388                 call    _kalloc
F004F254: 9010201c                 mov     0x1C, %o0
F004F258: d2164000                 lduh    [%i1], %o1
F004F25C: b0100008                 mov     %o0, %i0
F004F260: d2362002                 sth     %o1, [%i0+2]
F004F264: d0066004                 ld      [%i1+4], %o0
F004F268: d0262004                 st      %o0, [%i0+4]
F004F26C: d2066008                 ld      [%i1+8], %o1
F004F270: 80a26000                 cmp     %o1, 0
F004F274: 22800005                 be,a    loc_F004F288
F004F278: 90103fff                 mov     -1, %o0
F004F27C: d0066004                 ld      [%i1+4], %o0
F004F280: 90020009                 add     %o0, %o1, %o0
F004F284: 90023fff                 inc     -1, %o0
F004F288: d0262008                 st      %o0, [%i0+8]
F004F28C: 113c04cf                 sethi   %hi(_active_u), %o0
F004F290: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F004F294: d0020000                 ld      [%o0], %o0
F004F298: 7ffefe22                 call    _get_posix_proc
F004F29C: d0522030                 ldsh    [%o0+0x30], %o0
F004F2A0: d026200c                 st      %o0, [%i0+0xC]
F004F2A4: e0262010                 st      %l0, [%i0+0x10]
F004F2A8: d0042008                 ld      [%l0+8], %o0
F004F2AC: 80a6a007                 cmp     %i2, 7
F004F2B0: 90022001                 inc     %o0
F004F2B4: d0242008                 st      %o0, [%l0+8]
F004F2B8: c0262014                 clr     [%i0+0x14]
F004F2BC: 12800007                 bne     loc_F004F2D8
F004F2C0: c0262018                 clr     [%i0+0x18]
F004F2C4: 90100018                 mov     %i0, %o0
F004F2C8: 4000017e                 call    sub_F004F8C0
F004F2CC: 92100019                 mov     %i1, %o1
F004F2D0: 10800009                 ba      loc_F004F2F4
F004F2D4: b2100008                 mov     %o0, %i1
F004F2D8: d0564000                 ldsh    [%i1], %o0
F004F2DC: 80a22003                 cmp     %o0, 3
F004F2E0: 12800008                 bne     loc_F004F300
F004F2E4: 80a6a008                 cmp     %i2, 8
F004F2E8: 40000129                 call    sub_F004F78C
F004F2EC: 90100018                 mov     %i0, %o0
F004F2F0: b2100008                 mov     %o0, %i1
F004F2F4: 4000027b                 call    sub_F004FCE0
F004F2F8: 90100018                 mov     %i0, %o0
F004F2FC: 30800009                 ba,a    loc_F004F320
F004F300: 32800003                 bne,a   loc_F004F30C
F004F304: 90102002                 mov     2, %o0
F004F308: 90102001                 mov     1, %o0
F004F30C: d0360000                 sth     %o0, [%i0]
F004F310: 40000054                 call    sub_F004F460
F004F314: 90100018                 mov     %i0, %o0
F004F318: 10800005                 ba      locret_F004F32C
F004F31C: b0100008                 mov     %o0, %i0
F004F320: 4000002f                 call    sub_F004F3DC
F004F324: 90100010                 mov     %l0, %o0
F004F328: b0100019                 mov     %i1, %i0
F004F32C: 81c7e008                 ret
F004F330: 81e80000                 restore
