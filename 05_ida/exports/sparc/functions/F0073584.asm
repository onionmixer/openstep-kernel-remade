F0073584: 9de3bf98                 save    %sp, -0x68, %sp
F0073588: 113c04d0                 sethi   %hi(_active_threads), %o0
F007358C: e4022260                 ld      [%o0+%lo(_active_threads)], %l2
F0073590: d0060000                 ld      [%i0], %o0
F0073594: 80a22000                 cmp     %o0, 0
F0073598: 12bffffe                 bne     loc_F0073590
F007359C: 01000000                 nop
F00735A0: 40008e42                 call    _simple_lock_try
F00735A4: 90100018                 mov     %i0, %o0
F00735A8: 80a22000                 cmp     %o0, 0
F00735AC: 02bffff9                 be      loc_F0073590
F00735B0: 01000000                 nop
F00735B4: d0062008                 ld      [%i0+8], %o0
F00735B8: 80a22000                 cmp     %o0, 0
F00735BC: 32800005                 bne,a   loc_F00735D0
F00735C0: d0062018                 ld      [%i0+0x18], %o0
F00735C4: c0260000                 clr     [%i0]
F00735C8: 10800013                 ba      locret_F0073614
F00735CC: b0102005                 mov     5, %i0
F00735D0: a206201c                 add     %i0, 0x1C, %l1
F00735D4: e006201c                 ld      [%i0+0x1C], %l0
F00735D8: 90022001                 inc     %o0
F00735DC: 80a44010                 cmp     %l1, %l0
F00735E0: 0280000b                 be      loc_F007360C
F00735E4: d0262018                 st      %o0, [%i0+0x18]
F00735E8: 80a40012                 cmp     %l0, %l2
F00735EC: 22800005                 be,a    loc_F0073600
F00735F0: e0042010                 ld      [%l0+0x10], %l0
F00735F4: 4000071a                 call    _thread_hold
F00735F8: 90100010                 mov     %l0, %o0
F00735FC: e0042010                 ld      [%l0+0x10], %l0
F0073600: 80a44010                 cmp     %l1, %l0
F0073604: 12bffffa                 bne     loc_F00735EC
F0073608: 80a40012                 cmp     %l0, %l2
F007360C: c0260000                 clr     [%i0]
F0073610: b0102000                 mov     0, %i0
F0073614: 81c7e008                 ret
F0073618: 81e80000                 restore
