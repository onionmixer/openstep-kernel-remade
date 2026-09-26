F007510C: 9de3bf98                 save    %sp, -0x68, %sp
F0075110: 113c04d0                 sethi   %hi(_active_threads), %o0
F0075114: e2022260                 ld      [%o0+%lo(_active_threads)], %l1
F0075118: d004618c                 ld      [%l1+0x18C], %o0
F007511C: 808a2002                 btst    2, %o0
F0075120: 113c026f                 sethi   %hi(_thread_exception_return), %o0
F0075124: 02800034                 be      loc_F00751F4
F0075128: a61223e4                 or      %o0, %lo(_thread_exception_return), %l3
F007512C: 7fffc75e                 call    _ipc_thread_terminate
F0075130: 90100011                 mov     %l1, %o0
F0075134: 4000004a                 call    _thread_hold
F0075138: 90100011                 mov     %l1, %o0
F007513C: 40008693                 call    _splusclock
F0075140: 01000000                 nop
F0075144: a4100008                 mov     %o0, %l2
F0075148: 113c04f2a0122168         set     _reaper_lock, %l0
F0075150: d0040000                 ld      [%l0], %o0
F0075154: 80a22000                 cmp     %o0, 0
F0075158: 12bffffe                 bne     loc_F0075150
F007515C: 01000000                 nop
F0075160: 40008752                 call    _simple_lock_try
F0075164: 90100010                 mov     %l0, %o0
F0075168: 80a22000                 cmp     %o0, 0
F007516C: 02bffff9                 be      loc_F0075150
F0075170: 113c04d4                 sethi   %hi(_reaper_queue), %o0
F0075174: 90122150                 bset    %lo(_reaper_queue), %o0
F0075178: d0244000                 st      %o0, [%l1]
F007517C: d2022004                 ld      [%o0+4], %o1
F0075180: a0046020                 add     %l1, 0x20, %l0 ! ' '
F0075184: d2246004                 st      %o1, [%l1+4]
F0075188: e2224000                 st      %l1, [%o1]
F007518C: e2222004                 st      %l1, [%o0+4]
F0075190: 113c04f2                 sethi   %hi(_reaper_lock), %o0
F0075194: c0222168                 clr     [%o0+%lo(_reaper_lock)]
F0075198: d0040000                 ld      [%l0], %o0
F007519C: 80a22000                 cmp     %o0, 0
F00751A0: 12bffffe                 bne     loc_F0075198
F00751A4: 01000000                 nop
F00751A8: 40008740                 call    _simple_lock_try
F00751AC: 90100010                 mov     %l0, %o0
F00751B0: 80a22000                 cmp     %o0, 0
F00751B4: 02bffff9                 be      loc_F0075198
F00751B8: 01000000                 nop
F00751BC: c0246020                 clr     [%l1+0x20]
F00751C0: d204604c                 ld      [%l1+0x4C], %o1
F00751C4: 90100012                 mov     %l2, %o0
F00751C8: 92126010                 bset    0x10, %o1
F00751CC: 400086d6                 call    _splx
F00751D0: d224604c                 st      %o1, [%l1+0x4C]
F00751D4: 113c04d490122150         set     _reaper_queue, %o0
F00751DC: 92102000                 mov     0, %o1
F00751E0: 7fffef87                 call    _thread_wakeup_prim
F00751E4: 94102000                 mov     0, %o2
F00751E8: 113c01d3                 sethi   %hi(_walking_zombie), %o0
F00751EC: 10800018                 ba      loc_F007524C
F00751F0: 901223a8                 bset    %lo(_walking_zombie), %o0
F00751F4: 40008665                 call    _splusclock
F00751F8: a0046020                 add     %l1, 0x20, %l0 ! ' '
F00751FC: a4100008                 mov     %o0, %l2
F0075200: d0040000                 ld      [%l0], %o0
F0075204: 80a22000                 cmp     %o0, 0
F0075208: 12bffffe                 bne     loc_F0075200
F007520C: 01000000                 nop
F0075210: 40008726                 call    _simple_lock_try
F0075214: 90100010                 mov     %l0, %o0
F0075218: 80a22000                 cmp     %o0, 0
F007521C: 02bffff9                 be      loc_F0075200
F0075220: 01000000                 nop
F0075224: c0246020                 clr     [%l1+0x20]
F0075228: d404604c                 ld      [%l1+0x4C], %o2
F007522C: 90100012                 mov     %l2, %o0
F0075230: d204618c                 ld      [%l1+0x18C], %o1
F0075234: 9412a010                 bset    0x10, %o2
F0075238: d424604c                 st      %o2, [%l1+0x4C]
F007523C: 920a7ffe                 and     %o1, -2, %o1
F0075240: 400086b9                 call    _splx
F0075244: d224618c                 st      %o1, [%l1+0x18C]
F0075248: 90100013                 mov     %l3, %o0
F007524C: 7ffff13d                 call    _thread_block_with_continuation
F0075250: 01000000                 nop
F0075254: 81c7e008                 ret
F0075258: 81e80000                 restore
