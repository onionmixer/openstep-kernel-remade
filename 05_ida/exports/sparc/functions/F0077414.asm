F0077414: 9de3bf98                 save    %sp, -0x68, %sp
F0077418: 113c04d0                 sethi   %hi(_active_threads), %o0
F007741C: 40007ddb                 call    _splusclock
F0077420: f6022260                 ld      [%o0+%lo(_active_threads)], %i3
F0077424: 113c04c3a0122320         set     dword_F0130F20, %l0
F007742C: d0040000                 ld      [%l0], %o0
F0077430: 80a22000                 cmp     %o0, 0
F0077434: 12bffffe                 bne     loc_F007742C
F0077438: 01000000                 nop
F007743C: 40007e9b                 call    _simple_lock_try
F0077440: 90100010                 mov     %l0, %o0
F0077444: 80a22000                 cmp     %o0, 0
F0077448: 02bffff9                 be      loc_F007742C
F007744C: 133c04c3                 sethi   %hi(dword_F0130F3C), %o1
F0077450: d002633c                 ld      [%o1+%lo(dword_F0130F3C)], %o0
F0077454: 80a22000                 cmp     %o0, 0
F0077458: 04800041                 ble     loc_F007755C
F007745C: 113c04c1                 sethi   %hi(unk_F0130520), %o0
F0077460: 2f3c04c3b015e32c         set     dword_F0130F2C, %i0
F0077468: ac100009                 mov     %o1, %l6
F007746C: b2122120                 or      %o0, %lo(unk_F0130520), %i1
F0077470: b4066a00                 add     %i1, 0xA00, %i2
F0077474: 113c04c3aa122324         set     dword_F0130F24, %l5
F007747C: 293c04c3                 sethi   -0xFECF400, %l4
F0077480: d205e32c                 ld      [%l7+0x32C], %o1
F0077484: 80a24018                 cmp     %o1, %i0
F0077488: 32800004                 bne,a   loc_F0077498
F007748C: d0024000                 ld      [%o1], %o0
F0077490: 10800006                 ba      loc_F00774A8
F0077494: a0102000                 mov     0, %l0
F0077498: f0222004                 st      %i0, [%o0+4]
F007749C: d0024000                 ld      [%o1], %o0
F00774A0: a0100009                 mov     %o1, %l0
F00774A4: d025e32c                 st      %o0, [%l7+0x32C]
F00774A8: c0242020                 clr     [%l0+0x20]
F00774AC: d005a33c                 ld      [%l6+0x33C], %o0
F00774B0: 92100010                 mov     %l0, %o1
F00774B4: e6042008                 ld      [%l0+8], %l3
F00774B8: 80a40019                 cmp     %l0, %i1
F00774BC: e404200c                 ld      [%l0+0xC], %l2
F00774C0: 90023fff                 inc     -1, %o0
F00774C4: 0a80000b                 bcs     loc_F00774F0
F00774C8: d025a33c                 st      %o0, [%l6+0x33C]
F00774CC: 80a4001a                 cmp     %l0, %i2
F00774D0: 3a800009                 bcc,a   loc_F00774F4
F00774D4: a0100009                 mov     %o1, %l0
F00774D8: ea240000                 st      %l5, [%l0]
F00774DC: d0056004                 ld      [%l5+4], %o0
F00774E0: 92102000                 mov     0, %o1
F00774E4: d0242004                 st      %o0, [%l0+4]
F00774E8: e0220000                 st      %l0, [%o0]
F00774EC: e0256004                 st      %l0, [%l5+4]
F00774F0: a0100009                 mov     %o1, %l0
F00774F4: 133c04c3                 sethi   %hi(dword_F0130F20), %o1
F00774F8: c0226320                 clr     [%o1+%lo(dword_F0130F20)]
F00774FC: d0052340                 ld      [%l4+0x340], %o0
F0077500: a2126320                 or      %o1, %lo(dword_F0130F20), %l1
F0077504: 90022001                 inc     %o0
F0077508: 40007df6                 call    _spl0
F007750C: d0252340                 st      %o0, [%l4+0x340]
F0077510: 90100012                 mov     %l2, %o0
F0077514: 9fc4c000                 call    %l3
F0077518: 92100010                 mov     %l0, %o1
F007751C: 40007d9b                 call    _splusclock
F0077520: 01000000                 nop
F0077524: d0044000                 ld      [%l1], %o0
F0077528: 80a22000                 cmp     %o0, 0
F007752C: 12bffffe                 bne     loc_F0077524
F0077530: 01000000                 nop
F0077534: 40007e5d                 call    _simple_lock_try
F0077538: 90100011                 mov     %l1, %o0
F007753C: 80a22000                 cmp     %o0, 0
F0077540: 02bffff9                 be      loc_F0077524
F0077544: d0052340                 ld      [%l4+0x340], %o0
F0077548: d205a33c                 ld      [%l6+0x33C], %o1
F007754C: 90023fff                 inc     -1, %o0
F0077550: 80a26000                 cmp     %o1, 0
F0077554: 14bfffcb                 bg      loc_F0077480
F0077558: d0252340                 st      %o0, [%l4+0x340]
F007755C: 213c04c3                 sethi   %hi(dword_F0130F44), %l0
F0077560: d0042344                 ld      [%l0+%lo(dword_F0130F44)], %o0
F0077564: 133c04c3                 sethi   %hi(dword_F0130F40), %o1
F0077568: d2026340                 ld      [%o1+%lo(dword_F0130F40)], %o1
F007756C: 90220009                 sub     %o0, %o1, %o0
F0077570: 80a22004                 cmp     %o0, 4
F0077574: 3480000c                 bg,a    loc_F00775A4
F0077578: d0042344                 ld      [%l0+%lo(dword_F0130F44)], %o0
F007757C: 113c04c39012233c         set     dword_F0130F3C, %o0
F0077584: 7fffe5d4                 call    _assert_wait
F0077588: 92102000                 mov     0, %o1
F007758C: 113c04c3                 sethi   %hi(dword_F0130F20), %o0
F0077590: c0222320                 clr     [%o0+%lo(dword_F0130F20)]
F0077594: 113c01dd                 sethi   %hi(sub_F0077414), %o0
F0077598: 7fffe86a                 call    _thread_block_with_continuation
F007759C: 90122014                 bset    %lo(sub_F0077414), %o0
F00775A0: d0042344                 ld      [%l0+%lo(dword_F0130F44)], %o0
F00775A4: 133c04c3                 sethi   %hi(dword_F0130F20), %o1
F00775A8: c0226320                 clr     [%o1+%lo(dword_F0130F20)]
F00775AC: 90023fff                 inc     -1, %o0! target_act
F00775B0: 40007dcc                 call    _spl0
F00775B4: d0242344                 st      %o0, [%l0+0x344]
F00775B8: 7ffff4b7                 call    _thread_terminate
F00775BC: 9010001b                 mov     %i3, %o0
F00775C0: 7ffff6d3                 call    _thread_halt_self
F00775C4: 01000000                 nop
F00775C8: 81c7e008                 ret
F00775CC: 81e80000                 restore
