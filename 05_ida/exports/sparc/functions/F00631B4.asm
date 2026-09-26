F00631B4: 9de3bf88                 save    %sp, -0x78, %sp
F00631B8: 80a62000                 cmp     %i0, 0
F00631BC: 0280001c                 be      loc_F006322C
F00631C0: 90100018                 mov     %i0, %o0
F00631C4: 92100019                 mov     %i1, %o1
F00631C8: 7fffe22d                 call    _ipc_right_lookup_write
F00631CC: 9407bff4                 add     %fp, var_C, %o2
F00631D0: 80a22000                 cmp     %o0, 0
F00631D4: 32800017                 bne,a   locret_F0063230
F00631D8: b0102004                 mov     4, %i0
F00631DC: 90100018                 mov     %i0, %o0
F00631E0: 92100019                 mov     %i1, %o1
F00631E4: d407bff4                 ld      [%fp+var_C], %o2
F00631E8: 9607bff0                 add     %fp, var_10, %o3
F00631EC: 7fffe6b5                 call    _ipc_right_info
F00631F0: 9807bfec                 add     %fp, var_14, %o4
F00631F4: 80a22000                 cmp     %o0, 0
F00631F8: 3280000e                 bne,a   locret_F0063230
F00631FC: b0102004                 mov     4, %i0
F0063200: d207bff0                 ld      [%fp+var_10], %o1
F0063204: 110005c0                 sethi   0x170000, %o0
F0063208: 808a4008                 btst    %o0, %o1
F006320C: 02800007                 be      loc_F0063228
F0063210: 90100018                 mov     %i0, %o0
F0063214: d407bff4                 ld      [%fp+var_C], %o2
F0063218: 7fffe3e8                 call    _ipc_right_destroy
F006321C: 92100019                 mov     %i1, %o1
F0063220: 10800004                 ba      locret_F0063230
F0063224: b0102000                 mov     0, %i0
F0063228: c0262008                 clr     [%i0+8]
F006322C: b0102004                 mov     4, %i0
F0063230: 81c7e008                 ret
F0063234: 81e80000                 restore
