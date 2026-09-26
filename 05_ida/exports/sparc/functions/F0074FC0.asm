F0074FC0: 9de3bf98                 save    %sp, -0x68, %sp
F0074FC4: 113c04d0                 sethi   %hi(_active_threads), %o0
F0074FC8: e2022260                 ld      [%o0+%lo(_active_threads)], %l1
F0074FCC: d004618c                 ld      [%l1+0x18C], %o0
F0074FD0: 808a2002                 btst    2, %o0
F0074FD4: 02800034                 be      loc_F00750A4
F0074FD8: 01000000                 nop
F0074FDC: 7fffc7b2                 call    _ipc_thread_terminate
F0074FE0: 90100011                 mov     %l1, %o0
F0074FE4: 4000009e                 call    _thread_hold
F0074FE8: 90100011                 mov     %l1, %o0
F0074FEC: 400086e7                 call    _splusclock
F0074FF0: 01000000                 nop
F0074FF4: a4100008                 mov     %o0, %l2
F0074FF8: 113c04f2a0122168         set     _reaper_lock, %l0
F0075000: d0040000                 ld      [%l0], %o0
F0075004: 80a22000                 cmp     %o0, 0
F0075008: 12bffffe                 bne     loc_F0075000
F007500C: 01000000                 nop
F0075010: 400087a6                 call    _simple_lock_try
F0075014: 90100010                 mov     %l0, %o0
F0075018: 80a22000                 cmp     %o0, 0
F007501C: 02bffff9                 be      loc_F0075000
F0075020: 113c04d4                 sethi   %hi(_reaper_queue), %o0
F0075024: 90122150                 bset    %lo(_reaper_queue), %o0
F0075028: d0244000                 st      %o0, [%l1]
F007502C: d2022004                 ld      [%o0+4], %o1
F0075030: a0046020                 add     %l1, 0x20, %l0 ! ' '
F0075034: d2246004                 st      %o1, [%l1+4]
F0075038: e2224000                 st      %l1, [%o1]
F007503C: e2222004                 st      %l1, [%o0+4]
F0075040: 113c04f2                 sethi   %hi(_reaper_lock), %o0
F0075044: c0222168                 clr     [%o0+%lo(_reaper_lock)]
F0075048: d0040000                 ld      [%l0], %o0
F007504C: 80a22000                 cmp     %o0, 0
F0075050: 12bffffe                 bne     loc_F0075048
F0075054: 01000000                 nop
F0075058: 40008794                 call    _simple_lock_try
F007505C: 90100010                 mov     %l0, %o0
F0075060: 80a22000                 cmp     %o0, 0
F0075064: 02bffff9                 be      loc_F0075048
F0075068: 01000000                 nop
F007506C: c0246020                 clr     [%l1+0x20]
F0075070: d204604c                 ld      [%l1+0x4C], %o1
F0075074: 90100012                 mov     %l2, %o0
F0075078: 92126010                 bset    0x10, %o1
F007507C: 4000872a                 call    _splx
F0075080: d224604c                 st      %o1, [%l1+0x4C]
F0075084: 113c04d490122150         set     _reaper_queue, %o0
F007508C: 92102000                 mov     0, %o1
F0075090: 7fffefdb                 call    _thread_wakeup_prim
F0075094: 94102000                 mov     0, %o2
F0075098: 113c01d3                 sethi   %hi(_walking_zombie), %o0
F007509C: 10800018                 ba      loc_F00750FC
F00750A0: 901223a8                 bset    %lo(_walking_zombie), %o0
F00750A4: 400086b9                 call    _splusclock
F00750A8: a0046020                 add     %l1, 0x20, %l0 ! ' '
F00750AC: a4100008                 mov     %o0, %l2
F00750B0: d0040000                 ld      [%l0], %o0
F00750B4: 80a22000                 cmp     %o0, 0
F00750B8: 12bffffe                 bne     loc_F00750B0
F00750BC: 01000000                 nop
F00750C0: 4000877a                 call    _simple_lock_try
F00750C4: 90100010                 mov     %l0, %o0
F00750C8: 80a22000                 cmp     %o0, 0
F00750CC: 02bffff9                 be      loc_F00750B0
F00750D0: 01000000                 nop
F00750D4: c0246020                 clr     [%l1+0x20]
F00750D8: d404604c                 ld      [%l1+0x4C], %o2
F00750DC: 90100012                 mov     %l2, %o0
F00750E0: d204618c                 ld      [%l1+0x18C], %o1
F00750E4: 9412a010                 bset    0x10, %o2
F00750E8: d424604c                 st      %o2, [%l1+0x4C]
F00750EC: 920a7ffe                 and     %o1, -2, %o1
F00750F0: 4000870d                 call    _splx
F00750F4: d224618c                 st      %o1, [%l1+0x18C]
F00750F8: 90100018                 mov     %i0, %o0
F00750FC: 7ffff191                 call    _thread_block_with_continuation
F0075100: 01000000                 nop
F0075104: 81c7e008                 ret
F0075108: 81e80000                 restore
