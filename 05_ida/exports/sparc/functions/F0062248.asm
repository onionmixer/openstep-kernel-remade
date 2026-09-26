F0062248: 9de3bf90                 save    %sp, -0x70, %sp
F006224C: 80a62000                 cmp     %i0, 0
F0062250: 12800004                 bne     loc_F0062260
F0062254: 90100018                 mov     %i0, %o0
F0062258: 10800012                 ba      locret_F00622A0
F006225C: b0102010                 mov     0x10, %i0
F0062260: 92100019                 mov     %i1, %o1
F0062264: 7fffe606                 call    _ipc_right_lookup_write
F0062268: 9407bff4                 add     %fp, var_C, %o2
F006226C: 80a22000                 cmp     %o0, 0
F0062270: 3280000c                 bne,a   locret_F00622A0
F0062274: b0100008                 mov     %o0, %i0
F0062278: 90100018                 mov     %i0, %o0
F006227C: 92100019                 mov     %i1, %o1
F0062280: d407bff4                 ld      [%fp+var_C], %o2
F0062284: 9610001a                 mov     %i2, %o3
F0062288: 7fffea8e                 call    _ipc_right_info
F006228C: 9807bff0                 add     %fp, var_10, %o4
F0062290: 80a22000                 cmp     %o0, 0
F0062294: 22800002                 be,a    loc_F006229C
F0062298: c0262008                 clr     [%i0+8]
F006229C: b0100008                 mov     %o0, %i0
F00622A0: 81c7e008                 ret
F00622A4: 81e80000                 restore
