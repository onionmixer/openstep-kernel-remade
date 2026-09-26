F00659C0: 9de3bf98                 save    %sp, -0x68, %sp
F00659C4: a2102000                 mov     0, %l1
F00659C8: a00620a8                 add     %i0, 0xA8, %l0
F00659CC: d0040000                 ld      [%l0], %o0
F00659D0: 80a22000                 cmp     %o0, 0
F00659D4: 12bffffe                 bne     loc_F00659CC
F00659D8: 01000000                 nop
F00659DC: 4000c533                 call    _simple_lock_try
F00659E0: 90100010                 mov     %l0, %o0
F00659E4: 80a22000                 cmp     %o0, 0
F00659E8: 02bffff9                 be      loc_F00659CC
F00659EC: 01000000                 nop
F00659F0: d00620ac                 ld      [%i0+0xAC], %o0
F00659F4: 80a22000                 cmp     %o0, 0
F00659F8: 02800004                 be      loc_F0065A08
F00659FC: 01000000                 nop
F0065A00: e20620c0                 ld      [%i0+0xC0], %l1
F0065A04: c02620c0                 clr     [%i0+0xC0]
F0065A08: c02620a8                 clr     [%i0+0xA8]
F0065A0C: 80a46000                 cmp     %l1, 0
F0065A10: 02800005                 be      locret_F0065A24
F0065A14: 113c04ef                 sethi   %hi(_ipc_space_reply), %o0
F0065A18: d2022338                 ld      [%o0+%lo(_ipc_space_reply)], %o1
F0065A1C: 7fffd650                 call    _ipc_port_dealloc_special
F0065A20: 90100011                 mov     %l1, %o0
F0065A24: 81c7e008                 ret
F0065A28: 81e80000                 restore
