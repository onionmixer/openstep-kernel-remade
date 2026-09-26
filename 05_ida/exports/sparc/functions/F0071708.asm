F0071708: 9de3bf98                 save    %sp, -0x68, %sp
F007170C: 113c04d0                 sethi   %hi(_active_threads), %o0
F0071710: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F0071714: 80a62000                 cmp     %i0, 0
F0071718: 02800004                 be      loc_F0071728
F007171C: e0022034                 ld      [%o0+0x34], %l0
F0071720: 40000037                 call    _thread_dispatch
F0071724: 90100018                 mov     %i0, %o0
F0071728: 4000956e                 call    _spl0
F007172C: 01000000                 nop
F0071730: 9fc40000                 call    %l0
F0071734: 01000000                 nop
F0071738: 81c7e008                 ret
F007173C: 81e80000                 restore
