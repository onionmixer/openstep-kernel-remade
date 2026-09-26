F005455C: 9de3bf98                 save    %sp, -0x68, %sp
F0054560: d0062018                 ld      [%i0+0x18], %o0
F0054564: 9536a008                 srl     %i2, 8, %o2
F0054568: 80a28008                 cmp     %o2, %o0
F005456C: 1a80000b                 bcc     loc_F0054598
F0054570: 9610001b                 mov     %i3, %o3
F0054574: d0062014                 ld      [%i0+0x14], %o0
F0054578: 932aa004                 sll     %o2, 4, %o1
F005457C: 90020009                 add     %o0, %o1, %o0
F0054580: 80a2c008                 cmp     %o3, %o0
F0054584: 12800006                 bne     loc_F005459C
F0054588: 90100018                 mov     %i0, %o0
F005458C: 400000c7                 call    _ipc_hash_local_insert
F0054590: 92100019                 mov     %i1, %o1
F0054594: 30800005                 ba,a    locret_F00545A8
F0054598: 90100018                 mov     %i0, %o0
F005459C: 92100019                 mov     %i1, %o1
F00545A0: 40000054                 call    _ipc_hash_global_insert
F00545A4: 9410001a                 mov     %i2, %o2
F00545A8: 81c7e008                 ret
F00545AC: 81e80000                 restore
