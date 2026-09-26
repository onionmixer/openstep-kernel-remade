F00668A8: 9de3bf98                 save    %sp, -0x68, %sp
F00668AC: 90100019                 mov     %i1, %o0
F00668B0: 133c043e                 sethi   %hi(_hz), %o1
F00668B4: d20263e0                 ld      [%o1+%lo(_hz)], %o1
F00668B8: 7ffe7f12                 call    _umul
F00668BC: a0062020                 add     %i0, 0x20, %l0 ! ' '
F00668C0: 900223e7                 inc     0x3E7, %o0
F00668C4: 7ffe7f4f                 call    _udiv
F00668C8: 921023e8                 mov     0x3E8, %o1
F00668CC: 4000c0af                 call    _splusclock
F00668D0: a2100008                 mov     %o0, %l1
F00668D4: a4100008                 mov     %o0, %l2
F00668D8: d0040000                 ld      [%l0], %o0
F00668DC: 80a22000                 cmp     %o0, 0
F00668E0: 12bffffe                 bne     loc_F00668D8
F00668E4: 01000000                 nop
F00668E8: 4000c170                 call    _simple_lock_try
F00668EC: 90100010                 mov     %l0, %o0
F00668F0: 80a22000                 cmp     %o0, 0
F00668F4: 02bffff9                 be      loc_F00668D8
F00668F8: 80a46000                 cmp     %l1, 0
F00668FC: d006204c                 ld      [%i0+0x4C], %o0
F0066900: 90122001                 bset    1, %o0
F0066904: 12800005                 bne     loc_F0066918
F0066908: d026204c                 st      %o0, [%i0+0x4C]
F006690C: 80a66000                 cmp     %i1, 0
F0066910: 12800005                 bne     loc_F0066924
F0066914: 01000000                 nop
F0066918: 90062118                 add     %i0, 0x118, %o0
F006691C: 40000c2d                 call    _set_timeout
F0066920: 92100011                 mov     %l1, %o1
F0066924: c0262020                 clr     [%i0+0x20]
F0066928: 4000c0ff                 call    _splx
F006692C: 90100012                 mov     %l2, %o0
F0066930: 81c7e008                 ret
F0066934: 81e80000                 restore
