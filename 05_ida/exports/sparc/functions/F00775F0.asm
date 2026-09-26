F00775F0: 9de3bf98                 save    %sp, -0x68, %sp
F00775F4: 113c04d0                 sethi   %hi(_active_threads), %o0
F00775F8: 40007d64                 call    _splusclock
F00775FC: e2022260                 ld      [%o0+%lo(_active_threads)], %l1
F0077600: 113c04c3a0122320         set     dword_F0130F20, %l0
F0077608: d0040000                 ld      [%l0], %o0
F007760C: 80a22000                 cmp     %o0, 0
F0077610: 12bffffe                 bne     loc_F0077608
F0077614: 01000000                 nop
F0077618: 40007e24                 call    _simple_lock_try
F007761C: 90100010                 mov     %l0, %o0
F0077620: 80a22000                 cmp     %o0, 0
F0077624: 02bffff9                 be      loc_F0077608
F0077628: 113c04c3                 sethi   %hi(dword_F0130F40), %o0
F007762C: d2022340                 ld      [%o0+%lo(dword_F0130F40)], %o1
F0077630: 153c04c3                 sethi   %hi(dword_F0130F44), %o2
F0077634: 113c04c3                 sethi   %hi(dword_F0130F3C), %o0
F0077638: d002233c                 ld      [%o0+%lo(dword_F0130F3C)], %o0
F007763C: d602a344                 ld      [%o2+%lo(dword_F0130F44)], %o3
F0077640: 92024008                 add     %o1, %o0, %o1
F0077644: 80a2c009                 cmp     %o3, %o1
F0077648: 1680000e                 bge     loc_F0077680
F007764C: a012a344                 or      %o2, %lo(dword_F0130F44), %l0
F0077650: 9002e001                 add     %o3, 1, %o0
F0077654: d022a344                 st      %o0, [%o2+%lo(dword_F0130F44)]
F0077658: 113c04c3                 sethi   %hi(dword_F0130F20), %o0
F007765C: c0222320                 clr     [%o0+%lo(dword_F0130F20)]
F0077660: d004600c                 ld      [%l1+0xC], %o0
F0077664: 133c01dd921261d0         set     sub_F00775D0, %o1
F007766C: 7ffff8f2                 call    _kernel_thread
F0077670: 94102000                 mov     0, %o2
F0077674: 113c01dd                 sethi   %hi(sub_F00775F0), %o0
F0077678: 7fffe832                 call    _thread_block_with_continuation
F007767C: 901221f0                 bset    %lo(sub_F00775F0), %o0
F0077680: 90100010                 mov     %l0, %o0
F0077684: 7fffe594                 call    _assert_wait
F0077688: 92102000                 mov     0, %o1
F007768C: 113c04c3                 sethi   %hi(dword_F0130F20), %o0
F0077690: c0222320                 clr     [%o0+%lo(dword_F0130F20)]
F0077694: 113c01dd                 sethi   %hi(sub_F00775F0), %o0
F0077698: 7fffe82a                 call    _thread_block_with_continuation
F007769C: 901221f0                 bset    %lo(sub_F00775F0), %o0
F00776A0: 81c7e008                 ret
F00776A4: 81e80000                 restore
