F00737A0: 9de3bf98                 save    %sp, -0x68, %sp
F00737A4: 113c04d0                 sethi   %hi(_active_threads), %o0
F00737A8: e6022260                 ld      [%o0+%lo(_active_threads)], %l3
F00737AC: a406201c                 add     %i0, 0x1C, %l2
F00737B0: a2102000                 mov     0, %l1
F00737B4: d0060000                 ld      [%i0], %o0
F00737B8: 80a22000                 cmp     %o0, 0
F00737BC: 12bffffe                 bne     loc_F00737B4
F00737C0: 01000000                 nop
F00737C4: 40008db9                 call    _simple_lock_try
F00737C8: 90100018                 mov     %i0, %o0
F00737CC: 80a22000                 cmp     %o0, 0
F00737D0: 02bffff9                 be      loc_F00737B4
F00737D4: 01000000                 nop
F00737D8: e0048000                 ld      [%l2], %l0
F00737DC: 80a48010                 cmp     %l2, %l0
F00737E0: 0280001d                 be      loc_F0073854
F00737E4: 80a40013                 cmp     %l0, %l3
F00737E8: 22800018                 be,a    loc_F0073848
F00737EC: e0042010                 ld      [%l0+0x10], %l0
F00737F0: 40000411                 call    _thread_reference
F00737F4: 90100010                 mov     %l0, %o0
F00737F8: c0260000                 clr     [%i0]
F00737FC: 80a46000                 cmp     %l1, 0
F0073800: 02800005                 be      loc_F0073814
F0073804: 90100010                 mov     %l0, %o0
F0073808: 400002e9                 call    _thread_deallocate
F007380C: 90100011                 mov     %l1, %o0
F0073810: 90100010                 mov     %l0, %o0
F0073814: 400004cd                 call    _thread_halt
F0073818: 92102001                 mov     1, %o1
F007381C: a2100010                 mov     %l0, %l1
F0073820: d0060000                 ld      [%i0], %o0
F0073824: 80a22000                 cmp     %o0, 0
F0073828: 12bffffe                 bne     loc_F0073820
F007382C: 01000000                 nop
F0073830: 40008d9e                 call    _simple_lock_try
F0073834: 90100018                 mov     %i0, %o0
F0073838: 80a22000                 cmp     %o0, 0
F007383C: 02bffff9                 be      loc_F0073820
F0073840: 01000000                 nop
F0073844: e0042010                 ld      [%l0+0x10], %l0
F0073848: 80a48010                 cmp     %l2, %l0
F007384C: 12bfffe7                 bne     loc_F00737E8
F0073850: 80a40013                 cmp     %l0, %l3
F0073854: c0260000                 clr     [%i0]
F0073858: 80a46000                 cmp     %l1, 0
F007385C: 02800004                 be      locret_F007386C
F0073860: 01000000                 nop
F0073864: 400002d2                 call    _thread_deallocate
F0073868: 90100011                 mov     %l1, %o0
F007386C: 81c7e008                 ret
F0073870: 91e82000                 restore %g0, 0, %o0
