F0059A68: 9de3bf88                 save    %sp, -0x78, %sp
F0059A6C: a0100018                 mov     %i0, %l0
F0059A70: 90100010                 mov     %l0, %o0
F0059A74: 92100019                 mov     %i1, %o1
F0059A78: 40000801                 call    _ipc_right_lookup_write
F0059A7C: 9407bff4                 add     %fp, var_C, %o2
F0059A80: b0920000                 orcc    %o0, %g0, %i0
F0059A84: 1280001c                 bne     locret_F0059AF4
F0059A88: 90100010                 mov     %l0, %o0
F0059A8C: 92100019                 mov     %i1, %o1
F0059A90: 9607bff0                 add     %fp, var_10, %o3
F0059A94: 98102001                 mov     1, %o4
F0059A98: d407bff4                 ld      [%fp+var_C], %o2
F0059A9C: 9a10001b                 mov     %i3, %o5
F0059AA0: d623a05c                 st      %o3, [%sp+0x78+var_1C]
F0059AA4: 40000cf3                 call    _ipc_right_copyin
F0059AA8: 9610001a                 mov     %i2, %o3
F0059AAC: d407bff4                 ld      [%fp+var_C], %o2
F0059AB0: b0100008                 mov     %o0, %i0
F0059AB4: d2028000                 ld      [%o2], %o1
F0059AB8: 110007c0                 sethi   0x1F0000, %o0
F0059ABC: 808a4008                 btst    %o0, %o1
F0059AC0: 12800004                 bne     loc_F0059AD0
F0059AC4: 90100010                 mov     %l0, %o0
F0059AC8: 7fffe8ec                 call    _ipc_entry_dealloc
F0059ACC: 92100019                 mov     %i1, %o1
F0059AD0: c0242008                 clr     [%l0+8]
F0059AD4: 80a62000                 cmp     %i0, 0
F0059AD8: 12800007                 bne     locret_F0059AF4
F0059ADC: d007bff0                 ld      [%fp+var_10], %o0
F0059AE0: 80a22000                 cmp     %o0, 0
F0059AE4: 02800004                 be      locret_F0059AF4
F0059AE8: 01000000                 nop
F0059AEC: 7ffffd40                 call    _ipc_notify_port_deleted
F0059AF0: 92100019                 mov     %i1, %o1
F0059AF4: 81c7e008                 ret
F0059AF8: 81e80000                 restore
