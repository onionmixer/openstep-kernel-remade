F0054764: 9de3bf98                 save    %sp, -0x68, %sp
F0054768: 133c04ef                 sethi   %hi(_ipc_hash_global_table), %o1
F005476C: d0062040                 ld      [%i0+0x40], %o0
F0054770: b3366006                 srl     %i1, 6, %i1
F0054774: 90023fff                 inc     -1, %o0
F0054778: d0262040                 st      %o0, [%i0+0x40]
F005477C: b1362004                 srl     %i0, 4, %i0
F0054780: 113c04ef                 sethi   %hi(_ipc_hash_global_mask), %o0
F0054784: d00222e0                 ld      [%o0+%lo(_ipc_hash_global_mask)], %o0
F0054788: b0060019                 add     %i0, %i1, %i0
F005478C: b00e0008                 and     %i0, %o0, %i0
F0054790: d00262f0                 ld      [%o1+%lo(_ipc_hash_global_table)], %o0
F0054794: b12e2003                 sll     %i0, 3, %i0
F0054798: b0020018                 add     %o0, %i0, %i0
F005479C: d0060000                 ld      [%i0], %o0
F00547A0: 80a22000                 cmp     %o0, 0
F00547A4: 12bffffe                 bne     loc_F005479C
F00547A8: 01000000                 nop
F00547AC: 400109bf                 call    _simple_lock_try
F00547B0: 90100018                 mov     %i0, %o0
F00547B4: 80a22000                 cmp     %o0, 0
F00547B8: 02bffff9                 be      loc_F005479C
F00547BC: 01000000                 nop
F00547C0: d0062004                 ld      [%i0+4], %o0
F00547C4: 80a22000                 cmp     %o0, 0
F00547C8: 0280000c                 be      loc_F00547F8
F00547CC: 92062004                 add     %i0, 4, %o1
F00547D0: 80a2001b                 cmp     %o0, %i3
F00547D4: 32800005                 bne,a   loc_F00547E8
F00547D8: 9202200c                 add     %o0, 0xC, %o1
F00547DC: d002200c                 ld      [%o0+0xC], %o0
F00547E0: 10800006                 ba      loc_F00547F8
F00547E4: d0224000                 st      %o0, [%o1]
F00547E8: d002200c                 ld      [%o0+0xC], %o0
F00547EC: 80a22000                 cmp     %o0, 0
F00547F0: 12bffff9                 bne     loc_F00547D4
F00547F4: 80a2001b                 cmp     %o0, %i3
F00547F8: c0260000                 clr     [%i0]
F00547FC: 81c7e008                 ret
F0054800: 81e80000                 restore
