F0062C80: 9de3bf98                 save    %sp, -0x68, %sp
F0062C84: 92100019                 mov     %i1, %o1
F0062C88: 80a62000                 cmp     %i0, 0
F0062C8C: 12800004                 bne     loc_F0062C9C
F0062C90: 9610001b                 mov     %i3, %o3
F0062C94: 10800010                 ba      locret_F0062CD4
F0062C98: b0102010                 mov     0x10, %i0
F0062C9C: 9006bff0                 add     %i2, -0x10, %o0
F0062CA0: 80a22005                 cmp     %o0, 5
F0062CA4: 08800004                 bleu    loc_F0062CB4
F0062CA8: 90100018                 mov     %i0, %o0
F0062CAC: 1080000a                 ba      locret_F0062CD4
F0062CB0: b0102012                 mov     0x12, %i0
F0062CB4: 7fffdb6d                 call    _ipc_object_copyin
F0062CB8: 9410001a                 mov     %i2, %o2
F0062CBC: b0920000                 orcc    %o0, %g0, %i0
F0062CC0: 12800005                 bne     locret_F0062CD4
F0062CC4: 01000000                 nop
F0062CC8: 7fffdb3d                 call    _ipc_object_copyin_type
F0062CCC: 9010001a                 mov     %i2, %o0
F0062CD0: d0270000                 st      %o0, [%i4]
F0062CD4: 81c7e008                 ret
F0062CD8: 81e80000                 restore
