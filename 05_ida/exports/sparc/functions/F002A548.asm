F002A548: 9de3bd98                 save    %sp, -0x268, %sp
F002A54C: 40000552                 call    _nb_map
F002A550: 90100018                 mov     %i0, %o0
F002A554: b32e6010                 sll     %i1, 16, %i1
F002A558: b33e6010                 sra     %i1, 16, %i1
F002A55C: 80a66200                 cmp     %i1, 0x200
F002A560: 04800014                 ble     loc_F002A5B0
F002A564: a6100008                 mov     %o0, %l3
F002A568: 90100018                 mov     %i0, %o0
F002A56C: 92066012                 add     %i1, 0x12, %o1
F002A570: a12ea010                 sll     %i2, 16, %l0
F002A574: a13c2010                 sra     %l0, 16, %l0
F002A578: 94100010                 mov     %l0, %o2! size_t
F002A57C: a407bdf8                 add     %fp, var_208, %l2
F002A580: 4000055a                 call    _nb_read
F002A584: 96100012                 mov     %l2, %o3
F002A588: a204e00e                 add     %l3, 0xE, %l1
F002A58C: 90100011                 mov     %l1, %o0! void *
F002A590: 9204200e                 add     %l0, 0xE, %o1
F002A594: 9204c009                 add     %l3, %o1, %o1! void *
F002A598: 4001a95e                 call    _bcopy
F002A59C: 94100019                 mov     %i1, %o2
F002A5A0: 90100012                 mov     %l2, %o0
F002A5A4: 92100011                 mov     %l1, %o1
F002A5A8: 10800013                 ba      loc_F002A5F4
F002A5AC: 94100010                 mov     %l0, %o2
F002A5B0: 90100018                 mov     %i0, %o0
F002A5B4: 9210200e                 mov     0xE, %o1
F002A5B8: 94100019                 mov     %i1, %o2! size_t
F002A5BC: a207bdf8                 add     %fp, var_208, %l1
F002A5C0: 4000054a                 call    _nb_read
F002A5C4: 96100011                 mov     %l1, %o3
F002A5C8: 90066012                 add     %i1, 0x12, %o0
F002A5CC: 9004c008                 add     %l3, %o0, %o0! void *
F002A5D0: 9204e00e                 add     %l3, 0xE, %o1! void *
F002A5D4: a12ea010                 sll     %i2, 16, %l0
F002A5D8: a13c2010                 sra     %l0, 16, %l0
F002A5DC: 4001a94d                 call    _bcopy
F002A5E0: 94100010                 mov     %l0, %o2
F002A5E4: 90100011                 mov     %l1, %o0! void *
F002A5E8: a004200e                 inc     0xE, %l0
F002A5EC: 9204c010                 add     %l3, %l0, %o1! void *
F002A5F0: 94100019                 mov     %i1, %o2! size_t
F002A5F4: 4001a947                 call    _bcopy
F002A5F8: 01000000                 nop
F002A5FC: 90100018                 mov     %i0, %o0
F002A600: 4000056c                 call    _nb_shrink_bot
F002A604: 92102004                 mov     4, %o1
F002A608: 81c7e008                 ret
F002A60C: 81e80000                 restore
