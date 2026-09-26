F006363C: 9de3bf88                 save    %sp, -0x78, %sp
F0063640: 80a62000                 cmp     %i0, 0
F0063644: 02800011                 be      loc_F0063688
F0063648: 90100018                 mov     %i0, %o0
F006364C: 92100019                 mov     %i1, %o1
F0063650: 7fffe10b                 call    _ipc_right_lookup_write
F0063654: 9407bff4                 add     %fp, var_C, %o2
F0063658: 80a22000                 cmp     %o0, 0
F006365C: 3280001d                 bne,a   locret_F00636D0
F0063660: b0102004                 mov     4, %i0
F0063664: 90100018                 mov     %i0, %o0
F0063668: 92100019                 mov     %i1, %o1
F006366C: d407bff4                 ld      [%fp+var_C], %o2
F0063670: 9607bff0                 add     %fp, var_10, %o3
F0063674: 7fffe593                 call    _ipc_right_info
F0063678: 9807bfec                 add     %fp, var_14, %o4
F006367C: 80a22000                 cmp     %o0, 0
F0063680: 02800004                 be      loc_F0063690
F0063684: d207bff0                 ld      [%fp+var_10], %o1
F0063688: 10800012                 ba      locret_F00636D0
F006368C: b0102004                 mov     4, %i0
F0063690: 11000080                 sethi   0x20000, %o0
F0063694: 808a4008                 btst    %o0, %o1
F0063698: 32800009                 bne,a   loc_F00636BC
F006369C: d207bff4                 ld      [%fp+var_C], %o1
F00636A0: c0262008                 clr     [%i0+8]
F00636A4: 110005c0                 sethi   0x170000, %o0
F00636A8: 808a4008                 btst    %o0, %o1
F00636AC: 02800009                 be      locret_F00636D0
F00636B0: b0102004                 mov     4, %i0
F00636B4: 10800007                 ba      locret_F00636D0
F00636B8: b0102007                 mov     7, %i0
F00636BC: 90100018                 mov     %i0, %o0
F00636C0: d2026004                 ld      [%o1+4], %o1
F00636C4: 7fffe040                 call    _ipc_pset_move
F00636C8: 94102000                 mov     0, %o2
F00636CC: b0100008                 mov     %o0, %i0
F00636D0: 81c7e008                 ret
F00636D4: 81e80000                 restore
