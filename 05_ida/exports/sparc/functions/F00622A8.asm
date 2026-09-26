F00622A8: 9de3bf98                 save    %sp, -0x68, %sp
F00622AC: 90100018                 mov     %i0, %o0
F00622B0: 92100019                 mov     %i1, %o1
F00622B4: 80a22000                 cmp     %o0, 0
F00622B8: 12800004                 bne     loc_F00622C8
F00622BC: 9410001a                 mov     %i2, %o2
F00622C0: 1080000c                 ba      locret_F00622F0
F00622C4: b0102010                 mov     0x10, %i0
F00622C8: 80a2a000                 cmp     %o2, 0
F00622CC: 02800004                 be      loc_F00622DC
F00622D0: 80a2bfff                 cmp     %o2, -1
F00622D4: 12800004                 bne     loc_F00622E4
F00622D8: 01000000                 nop
F00622DC: 10800005                 ba      locret_F00622F0
F00622E0: b0102012                 mov     0x12, %i0
F00622E4: 7fffdf57                 call    _ipc_object_rename
F00622E8: 01000000                 nop
F00622EC: b0100008                 mov     %o0, %i0
F00622F0: 81c7e008                 ret
F00622F4: 81e80000                 restore
