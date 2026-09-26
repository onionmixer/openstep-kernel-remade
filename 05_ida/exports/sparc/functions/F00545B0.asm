F00545B0: 9de3bf98                 save    %sp, -0x68, %sp
F00545B4: d0062018                 ld      [%i0+0x18], %o0
F00545B8: 9536a008                 srl     %i2, 8, %o2
F00545BC: 80a28008                 cmp     %o2, %o0
F00545C0: 1a80000b                 bcc     loc_F00545EC
F00545C4: 9610001b                 mov     %i3, %o3
F00545C8: d0062014                 ld      [%i0+0x14], %o0
F00545CC: 932aa004                 sll     %o2, 4, %o1
F00545D0: 90020009                 add     %o0, %o1, %o0
F00545D4: 80a2c008                 cmp     %o3, %o0
F00545D8: 12800006                 bne     loc_F00545F0
F00545DC: 90100018                 mov     %i0, %o0
F00545E0: 400000c8                 call    _ipc_hash_local_delete
F00545E4: 92100019                 mov     %i1, %o1
F00545E8: 30800005                 ba,a    locret_F00545FC
F00545EC: 90100018                 mov     %i0, %o0
F00545F0: 92100019                 mov     %i1, %o1
F00545F4: 4000005c                 call    _ipc_hash_global_delete
F00545F8: 9410001a                 mov     %i2, %o2
F00545FC: 81c7e008                 ret
F0054600: 81e80000                 restore
