F00546F0: 9de3bf98                 save    %sp, -0x68, %sp
F00546F4: 133c04ef                 sethi   %hi(_ipc_hash_global_table), %o1
F00546F8: d0062040                 ld      [%i0+0x40], %o0
F00546FC: b3366006                 srl     %i1, 6, %i1
F0054700: 90022001                 inc     %o0
F0054704: d0262040                 st      %o0, [%i0+0x40]
F0054708: b1362004                 srl     %i0, 4, %i0
F005470C: 113c04ef                 sethi   %hi(_ipc_hash_global_mask), %o0
F0054710: d00222e0                 ld      [%o0+%lo(_ipc_hash_global_mask)], %o0
F0054714: b0060019                 add     %i0, %i1, %i0
F0054718: b00e0008                 and     %i0, %o0, %i0
F005471C: d00262f0                 ld      [%o1+%lo(_ipc_hash_global_table)], %o0
F0054720: b12e2003                 sll     %i0, 3, %i0
F0054724: b0020018                 add     %o0, %i0, %i0
F0054728: d0060000                 ld      [%i0], %o0
F005472C: 80a22000                 cmp     %o0, 0
F0054730: 12bffffe                 bne     loc_F0054728
F0054734: 01000000                 nop
F0054738: 400109dc                 call    _simple_lock_try
F005473C: 90100018                 mov     %i0, %o0
F0054740: 80a22000                 cmp     %o0, 0
F0054744: 02bffff9                 be      loc_F0054728
F0054748: 01000000                 nop
F005474C: d0062004                 ld      [%i0+4], %o0
F0054750: d026e00c                 st      %o0, [%i3+0xC]
F0054754: f6262004                 st      %i3, [%i0+4]
F0054758: c0260000                 clr     [%i0]
F005475C: 81c7e008                 ret
F0054760: 81e80000                 restore
