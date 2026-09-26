F00625AC: 9de3bf90                 save    %sp, -0x70, %sp
F00625B0: 80a62000                 cmp     %i0, 0
F00625B4: 12800004                 bne     loc_F00625C4
F00625B8: 80a6a004                 cmp     %i2, 4
F00625BC: 10800013                 ba      locret_F0062608
F00625C0: b0102010                 mov     0x10, %i0
F00625C4: 08800004                 bleu    loc_F00625D4
F00625C8: 90100018                 mov     %i0, %o0
F00625CC: 1080000f                 ba      locret_F0062608
F00625D0: b0102012                 mov     0x12, %i0
F00625D4: 92100019                 mov     %i1, %o1
F00625D8: 7fffe529                 call    _ipc_right_lookup_write
F00625DC: 9407bff4                 add     %fp, var_C, %o2
F00625E0: 80a22000                 cmp     %o0, 0
F00625E4: 32800009                 bne,a   locret_F0062608
F00625E8: b0100008                 mov     %o0, %i0
F00625EC: 90100018                 mov     %i0, %o0
F00625F0: 92100019                 mov     %i1, %o1
F00625F4: d407bff4                 ld      [%fp+var_C], %o2
F00625F8: 9610001a                 mov     %i2, %o3
F00625FC: 7fffe869                 call    _ipc_right_delta
F0062600: 9810001b                 mov     %i3, %o4
F0062604: b0100008                 mov     %o0, %i0
F0062608: 81c7e008                 ret
F006260C: 81e80000                 restore
